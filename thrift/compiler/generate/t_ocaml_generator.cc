/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>

#include <sys/types.h>
#include <sstream>
#include <thrift/compiler/ast/base_types.h>
#include <thrift/compiler/generate/t_oop_generator.h>

using namespace std;

namespace apache {
namespace thrift {
namespace compiler {

/**
 * OCaml code generator.
 *
 */
class t_ocaml_generator : public t_oop_generator {
 public:
  t_ocaml_generator(
      t_program* program,
      t_generation_context context,
      const std::map<std::string, std::string>& /* parsed_options */,
      const std::string& /* option_string */)
      : t_oop_generator(program, std::move(context)) {
    out_dir_base_ = "gen-ocaml";
  }

  /**
   * Init and close methods
   */

  void init_generator() override;
  void close_generator() override;

  /**
   * Program-level generation functions
   */
  void generate_program() override;
  void generate_typedef(const t_typedef* ttypedef) override;
  void generate_enum(const t_enum* tenum) override;
  void generate_const(const t_const* tconst) override;
  void generate_struct(const t_struct* tstruct) override;
  void generate_xception(const t_struct* txception) override;
  void generate_service(const t_service* tservice) override;

  std::string render_const_value(const t_type* type, t_const_value* value);

  /**
   * Struct generation code
   */

  void generate_ocaml_struct(const t_struct* tstruct, bool is_exception);
  void generate_ocaml_struct_definition(
      std::ofstream& out, const t_struct* tstruct, bool is_xception = false);
  void generate_ocaml_struct_sig(
      std::ofstream& out, const t_struct* tstruct, bool is_exception);
  void generate_ocaml_struct_reader(
      std::ofstream& out, const t_struct* tstruct);
  void generate_ocaml_struct_writer(
      std::ofstream& out, const t_struct* tstruct);
  void generate_ocaml_function_helpers(const t_function* tfunction);

  /**
   * Service-level generation functions
   */

  void generate_service_helpers(const t_service* tservice);
  void generate_service_interface(const t_service* tservice);
  void generate_service_client(const t_service* tservice);
  void generate_service_server(const t_service* tservice);
  void generate_process_function(
      const t_service* tservice, const t_function* tfunction);

  /**
   * Serialization constructs
   */

  void generate_deserialize_field(
      std::ofstream& out, const t_field* tfield, std::string prefix);

  void generate_deserialize_struct(std::ofstream& out, const t_struct* tstruct);

  void generate_deserialize_container(std::ofstream& out, const t_type* ttype);

  void generate_deserialize_set_element(std::ofstream& out, const t_set* tset);

  void generate_deserialize_list_element(
      std::ofstream& out, const t_list* tlist, std::string prefix = "");
  void generate_deserialize_type(std::ofstream& out, const t_type* type);

  void generate_serialize_field(
      std::ofstream& out, const t_field* tfield, std::string name = "");

  void generate_serialize_struct(
      std::ofstream& out, const t_struct* tstruct, std::string prefix = "");

  void generate_serialize_container(
      std::ofstream& out, const t_type* ttype, std::string prefix = "");

  void generate_serialize_map_element(
      std::ofstream& out,
      const t_map* tmap,
      std::string kiter,
      std::string viter);

  void generate_serialize_set_element(
      std::ofstream& out, const t_set* tmap, std::string iter);

  void generate_serialize_list_element(
      std::ofstream& out, const t_list* tlist, std::string iter);

  /**
   * Helper rendering functions
   */

  std::string ocaml_autogen_comment();
  std::string ocaml_imports();
  std::string type_name(const t_type* ttype);
  std::string function_signature(
      const t_function* tfunction, std::string prefix = "");
  std::string function_type(
      const t_function* tfunc, bool method = false, bool options = false);
  std::string argument_list(const t_struct* tstruct);
  std::string type_to_enum(const t_type* ttype);
  std::string render_ocaml_type(const t_type* type);

 private:
  /**
   * File streams
   */

  std::ofstream f_types_;
  std::ofstream f_consts_;
  std::ofstream f_service_;

  std::ofstream f_types_i_;
  std::ofstream f_service_i_;
};

/*
 * This is necessary because we want typedefs to appear later,
 * after all the types have been declared.
 */
void t_ocaml_generator::generate_program() {
  // Initialize the generator
  init_generator();

  // Generate enums
  for (auto* en : program_->enums()) {
    generate_enum(en);
  }

  // Generate structs
  for (auto* st : program_->structs()) {
    generate_struct(st);
  }

  // Generate xceptions
  for (auto* x : program_->xceptions()) {
    generate_xception(x);
  }

  // Generate typedefs
  for (auto td : program_->typedefs()) {
    generate_typedef(td);
  }

  // Generate services
  for (auto* sv : program_->services()) {
    service_name_ = get_service_name(sv);
    generate_service(sv);
  }

  // Generate constants
  generate_consts(program_->consts());

  // Close the generator
  close_generator();
}

/**
 * Prepares for file generation by opening up the necessary file output
 * streams.
 *
 * @param tprogram The program to generate
 */
void t_ocaml_generator::init_generator() {
  // Make output directory
  boost::filesystem::create_directory(get_out_dir());

  // Make output file
  string f_types_name = get_out_dir() + program_name_ + "_types.ml";
  f_types_.open(f_types_name.c_str());
  record_genfile(f_types_name);
  string f_types_i_name = get_out_dir() + program_name_ + "_types.mli";
  f_types_i_.open(f_types_i_name.c_str());
  record_genfile(f_types_i_name);

  string f_consts_name = get_out_dir() + program_name_ + "_consts.ml";
  f_consts_.open(f_consts_name.c_str());
  record_genfile(f_consts_name);

  // Print header
  f_types_ << ocaml_autogen_comment() << endl << ocaml_imports() << endl;
  f_types_i_ << ocaml_autogen_comment() << endl << ocaml_imports() << endl;
  f_consts_ << ocaml_autogen_comment() << endl
            << ocaml_imports() << endl
            << "open " << capitalize(program_name_) << "_types" << endl;
}

/**
 * Autogen'd comment
 */
string t_ocaml_generator::ocaml_autogen_comment() {
  return std::string("(*\n") + " Autogenerated by Thrift\n" + "\n" +
      " DO NOT EDIT UNLESS YOU ARE SURE YOU KNOW WHAT YOU ARE DOING\n" + "*)\n";
}

/**
 * Prints standard thrift imports
 */
string t_ocaml_generator::ocaml_imports() {
  return "open Thrift";
}

/**
 * Closes the type files
 */
void t_ocaml_generator::close_generator() {
  // Close types file
  f_types_.close();
}

/**
 * Generates a typedef. Ez.
 *
 * @param ttypedef The type definition
 */
void t_ocaml_generator::generate_typedef(const t_typedef* ttypedef) {
  f_types_ << indent() << "type " << decapitalize(ttypedef->get_symbolic())
           << " = " << render_ocaml_type(ttypedef->get_type()) << endl
           << endl;
  f_types_i_ << indent() << "type " << decapitalize(ttypedef->get_symbolic())
             << " = " << render_ocaml_type(ttypedef->get_type()) << endl
             << endl;
}

/**
 * Generates code for an enumerated type.
 * the values.
 *
 * @param tenum The enumeration
 */
void t_ocaml_generator::generate_enum(const t_enum* tenum) {
  indent(f_types_) << "module " << capitalize(tenum->get_name()) << " = "
                   << endl
                   << "struct" << endl;
  indent(f_types_i_) << "module " << capitalize(tenum->get_name()) << " : "
                     << endl
                     << "sig" << endl;
  indent_up();
  indent(f_types_) << "type t = " << endl;
  indent(f_types_i_) << "type t = " << endl;
  indent_up();
  vector<t_enum_value*> constants = tenum->get_enum_values();
  vector<t_enum_value*>::iterator c_iter;
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    string name = capitalize((*c_iter)->get_name());
    indent(f_types_) << "| " << name << endl;
    indent(f_types_i_) << "| " << name << endl;
  }
  indent_down();

  indent(f_types_) << "let to_i = function" << endl;
  indent(f_types_i_) << "val to_i : t -> Int32.t" << endl;
  indent_up();
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    int32_t value = (*c_iter)->get_value();
    string name = capitalize((*c_iter)->get_name());

    f_types_ << indent() << "| " << name << " -> " << value << "l" << endl;
  }
  indent_down();

  indent(f_types_) << "let of_i = function" << endl;
  indent(f_types_i_) << "val of_i : Int32.t -> t" << endl;
  indent_up();
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    int32_t value = (*c_iter)->get_value();
    string name = capitalize((*c_iter)->get_name());

    f_types_ << indent() << "| " << value << "l -> " << name << endl;
  }
  indent(f_types_) << "| _ -> raise Thrift_error" << endl;
  indent_down();
  indent_down();
  indent(f_types_) << "end" << endl;
  indent(f_types_i_) << "end" << endl;
}

/**
 * Generate a constant value
 */
void t_ocaml_generator::generate_const(const t_const* tconst) {
  const t_type* type = tconst->get_type();
  string name = decapitalize(tconst->get_name());
  t_const_value* value = tconst->get_value();

  indent(f_consts_) << "let " << name << " = "
                    << render_const_value(type, value) << endl
                    << endl;
}

/**
 * Prints the value of a constant with the given type. Note that type checking
 * is NOT performed in this function as it is always run beforehand using the
 * validate_types method in main.cc
 */
string t_ocaml_generator::render_const_value(
    const t_type* type, t_const_value* value) {
  type = type->get_true_type();
  std::ostringstream out;
  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        out << "\"" << value->get_string() << "\"";
        break;
      case t_base_type::TYPE_BOOL:
        out << (value->get_integer() > 0 ? "true" : "false");
        break;
      case t_base_type::TYPE_BYTE:
      case t_base_type::TYPE_I16:
      case t_base_type::TYPE_I32:
        out << value->get_integer();
        break;
      case t_base_type::TYPE_I64:
        out << value->get_integer() << "L";
        break;
      case t_base_type::TYPE_DOUBLE:
        if (value->get_type() == t_const_value::CV_INTEGER) {
          out << value->get_integer();
        } else {
          out << value->get_double();
        }
        break;
      default:
        throw std::runtime_error(
            "compiler error: no const of base type " +
            t_base_type::t_base_name(tbase));
    }
  } else if (type->is_enum()) {
    const t_enum* tenum = (t_enum*)type;
    vector<t_enum_value*> constants = tenum->get_enum_values();
    vector<t_enum_value*>::iterator c_iter;
    for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
      int32_t val = (*c_iter)->get_value();
      if (val == value->get_integer()) {
        indent(out) << capitalize(tenum->get_name()) << "."
                    << capitalize((*c_iter)->get_name());
        break;
      }
    }
  } else if (type->is_struct() || type->is_xception()) {
    string cname = type_name(type);
    string ct = tmp("_c");
    out << endl;
    indent_up();
    indent(out) << "(let " << ct << " = new " << cname << " in" << endl;
    indent_up();
    const vector<t_field*>& fields = ((t_struct*)type)->get_members();
    vector<t_field*>::const_iterator f_iter;
    const vector<pair<t_const_value*, t_const_value*>>& val = value->get_map();
    vector<pair<t_const_value*, t_const_value*>>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      const t_type* field_type = nullptr;
      for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
        if ((*f_iter)->get_name() == v_iter->first->get_string()) {
          field_type = (*f_iter)->get_type();
        }
      }
      if (field_type == nullptr) {
        throw std::runtime_error(
            "type error: " + type->get_name() + " has no field " +
            v_iter->first->get_string());
      }
      string fname = v_iter->first->get_string();
      out << indent();
      out << ct << "#set_" << fname << " ";
      out << render_const_value(field_type, v_iter->second);
      out << ";" << endl;
    }
    indent(out) << ct << ")";
    indent_down();
    indent_down();
  } else if (type->is_map()) {
    const t_type* ktype = ((t_map*)type)->get_key_type();
    const t_type* vtype = ((t_map*)type)->get_val_type();
    const vector<pair<t_const_value*, t_const_value*>>& val = value->get_map();
    string hm = tmp("_hm");
    out << endl;
    indent_up();
    indent(out) << "(let " << hm << " = Hashtbl.create " << val.size() << " in"
                << endl;
    indent_up();
    for (auto v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      string key = render_const_value(ktype, v_iter->first);
      string val = render_const_value(vtype, v_iter->second);
      indent(out) << "Hashtbl.add " << hm << " " << key << " " << val << ";"
                  << endl;
    }
    indent(out) << hm << ")";
    indent_down();
    indent_down();
  } else if (type->is_list()) {
    const t_type* etype;
    etype = ((t_list*)type)->get_elem_type();
    out << "[" << endl;
    indent_up();
    const vector<t_const_value*>& val = value->get_list();
    vector<t_const_value*>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      out << indent();
      out << render_const_value(etype, *v_iter);
      out << ";" << endl;
    }
    indent_down();
    indent(out) << "]";
  } else if (type->is_set()) {
    const t_type* etype = ((t_set*)type)->get_elem_type();
    const vector<t_const_value*>& val = value->get_list();
    vector<t_const_value*>::const_iterator v_iter;
    string hm = tmp("_hm");
    indent(out) << "(let " << hm << " = Hashtbl.create " << val.size() << " in"
                << endl;
    indent_up();
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      string val = render_const_value(etype, *v_iter);
      indent(out) << "Hashtbl.add " << hm << " " << val << " true;" << endl;
    }
    indent(out) << hm << ")" << endl;
    indent_down();
    out << endl;
  } else {
    throw std::runtime_error(
        "CANNOT GENERATE CONSTANT FOR TYPE: " + type->get_name());
  }
  return out.str();
}

/**
 * Generates a "struct"
 */
void t_ocaml_generator::generate_struct(const t_struct* tstruct) {
  generate_ocaml_struct(tstruct, false);
}

/**
 * Generates a struct definition for a thrift exception. Basically the same
 * as a struct, but also has an exception declaration.
 *
 * @param txception The struct definition
 */
void t_ocaml_generator::generate_xception(const t_struct* txception) {
  generate_ocaml_struct(txception, true);
}

/**
 * Generates an OCaml struct
 */
void t_ocaml_generator::generate_ocaml_struct(
    const t_struct* tstruct, bool is_exception) {
  generate_ocaml_struct_definition(f_types_, tstruct, is_exception);
  generate_ocaml_struct_sig(f_types_i_, tstruct, is_exception);
}

/**
 * Generates a struct definition for a thrift data type.
 *
 * @param tstruct The struct definition
 */
void t_ocaml_generator::generate_ocaml_struct_definition(
    ofstream& out, const t_struct* tstruct, bool is_exception) {
  const vector<t_field*>& members = tstruct->get_members();
  vector<t_field*>::const_iterator m_iter;
  string tname = type_name(tstruct);
  indent(out) << "class " << tname << " =" << endl;
  indent(out) << "object (self)" << endl;

  indent_up();

  string x = tmp("_x");
  if (members.size() > 0) {
    for (m_iter = members.begin(); m_iter != members.end(); ++m_iter) {
      string mname = decapitalize((*m_iter)->get_name());
      indent(out) << "val mutable _" << mname << " : "
                  << render_ocaml_type((*m_iter)->get_type())
                  << " option = None" << endl;
      indent(out) << "method get_" << mname << " = _" << mname << endl;
      indent(out) << "method grab_" << mname << " = match _" << mname
                  << " with None->raise (Field_empty \"" << tname << "."
                  << mname << "\") | Some " << x << " -> " << x << endl;
      indent(out) << "method set_" << mname << " " << x << " = _" << mname
                  << " <- Some " << x << endl;
    }
  }
  generate_ocaml_struct_writer(out, tstruct);
  indent_down();
  indent(out) << "end" << endl;

  if (is_exception) {
    indent(out) << "exception " << capitalize(tname) << " of " << tname << endl;
  }

  generate_ocaml_struct_reader(out, tstruct);
}

/**
 * Generates a struct definition for a thrift data type.
 *
 * @param tstruct The struct definition
 */
void t_ocaml_generator::generate_ocaml_struct_sig(
    ofstream& out, const t_struct* tstruct, bool is_exception) {
  const vector<t_field*>& members = tstruct->get_members();
  vector<t_field*>::const_iterator m_iter;
  string tname = type_name(tstruct);
  indent(out) << "class " << tname << " :" << endl;
  indent(out) << "object" << endl;

  indent_up();

  string x = tmp("_x");
  if (members.size() > 0) {
    for (m_iter = members.begin(); m_iter != members.end(); ++m_iter) {
      string mname = decapitalize((*m_iter)->get_name());
      string type = render_ocaml_type((*m_iter)->get_type());
      indent(out) << "method get_" << mname << " : " << type << " option"
                  << endl;
      indent(out) << "method grab_" << mname << " : " << type << endl;
      indent(out) << "method set_" << mname << " : " << type << " -> unit"
                  << endl;
    }
  }
  indent(out) << "method write : Protocol.t -> unit" << endl;
  indent_down();
  indent(out) << "end" << endl;

  if (is_exception) {
    indent(out) << "exception " << capitalize(tname) << " of " << tname << endl;
  }

  indent(out) << "val read_" << tname << " : Protocol.t -> " << tname << endl;
}

/**
 * Generates the read method for a struct
 */
void t_ocaml_generator::generate_ocaml_struct_reader(
    ofstream& out, const t_struct* tstruct) {
  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;
  string sname = type_name(tstruct);
  string str = tmp("_str");
  string t = tmp("_t");
  string id = tmp("_id");
  indent(out) << "let rec read_" << sname << " (iprot : Protocol.t) =" << endl;
  indent_up();
  indent(out) << "let " << str << " = new " << sname << " in" << endl;
  indent_up();
  indent(out) << "ignore(iprot#readStructBegin);" << endl;

  // Loop over reading in fields
  indent(out) << "(try while true do" << endl;
  indent_up();
  indent_up();

  // Read beginning field marker
  indent(out) << "let (_," << t << "," << id << ") = iprot#readFieldBegin in"
              << endl;

  // Check for field STOP marker and break
  indent(out) << "if " << t << " = Protocol.T_STOP then" << endl;
  indent_up();
  indent(out) << "raise Break" << endl;
  indent_down();
  indent(out) << "else ();" << endl;

  indent(out) << "(match " << id << " with " << endl;
  indent_up();
  // Generate deserialization code for known cases
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    indent(out) << "| " << (*f_iter)->get_key() << " -> (";
    out << "if " << t << " = " << type_to_enum((*f_iter)->get_type()) << " then"
        << endl;
    indent_up();
    indent_up();
    generate_deserialize_field(out, *f_iter, str);
    indent_down();
    out << indent() << "else" << endl
        << indent() << "  iprot#skip " << t << ")" << endl;
    indent_down();
  }

  // In the default case we skip the field
  out << indent() << "| _ -> "
      << "iprot#skip " << t << ");" << endl;
  indent_down();
  // Read field end marker
  indent(out) << "iprot#readFieldEnd;" << endl;
  indent_down();
  indent(out) << "done; ()" << endl;
  indent_down();
  indent(out) << "with Break -> ());" << endl;

  indent(out) << "iprot#readStructEnd;" << endl;

  indent(out) << str << endl << endl;
  indent_down();
  indent_down();
}

void t_ocaml_generator::generate_ocaml_struct_writer(
    ofstream& out, const t_struct* tstruct) {
  const string& name = tstruct->get_name();
  const vector<t_field*>& fields = tstruct->get_sorted_members();
  vector<t_field*>::const_iterator f_iter;
  string str = tmp("_str");
  string f = tmp("_f");

  indent(out) << "method write (oprot : Protocol.t) =" << endl;
  indent_up();
  indent(out) << "oprot#writeStructBegin \"" << name << "\";" << endl;

  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    // Write field header
    string mname = "_" + decapitalize((*f_iter)->get_name());
    indent(out) << "(match " << mname << " with None -> () | Some _v -> "
                << endl;
    indent_up();
    indent(out) << "oprot#writeFieldBegin(\"" << (*f_iter)->get_name() << "\","
                << type_to_enum((*f_iter)->get_type()) << ","
                << (*f_iter)->get_key() << ");" << endl;

    // Write field contents
    generate_serialize_field(out, *f_iter, "_v");

    // Write field closer
    indent(out) << "oprot#writeFieldEnd" << endl;

    indent_down();
    indent(out) << ");" << endl;
  }

  // Write the struct map
  out << indent() << "oprot#writeFieldStop;" << endl
      << indent() << "oprot#writeStructEnd" << endl;

  indent_down();
}

/**
 * Generates a thrift service.
 *
 * @param tservice The service definition
 */
void t_ocaml_generator::generate_service(const t_service* tservice) {
  string f_service_name = get_out_dir() + capitalize(service_name_) + ".ml";
  f_service_.open(f_service_name.c_str());
  record_genfile(f_service_name);
  string f_service_i_name = get_out_dir() + capitalize(service_name_) + ".mli";
  f_service_i_.open(f_service_i_name.c_str());
  record_genfile(f_service_i_name);

  f_service_ << ocaml_autogen_comment() << endl << ocaml_imports() << endl;
  f_service_i_ << ocaml_autogen_comment() << endl << ocaml_imports() << endl;

  /* if (tservice->get_extends() != NULL) {
    f_service_ <<
      "open " << capitalize(tservice->get_extends()->get_name()) << endl;
    f_service_i_ <<
      "open " << capitalize(tservice->get_extends()->get_name()) << endl;
  }
  */
  f_service_ << "open " << capitalize(program_name_) << "_types" << endl
             << endl;

  f_service_i_ << "open " << capitalize(program_name_) << "_types" << endl
               << endl;

  // Generate the three main parts of the service
  generate_service_helpers(tservice);
  generate_service_interface(tservice);
  generate_service_client(tservice);
  generate_service_server(tservice);

  // Close service file
  f_service_.close();
  f_service_i_.close();
}

/**
 * Generates helper functions for a service.
 *
 * @param tservice The service to generate a header definition for
 */
void t_ocaml_generator::generate_service_helpers(const t_service* tservice) {
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  indent(f_service_) << "(* HELPER FUNCTIONS AND STRUCTURES *)" << endl << endl;

  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    const t_struct* ts = (*f_iter)->get_paramlist();
    generate_ocaml_struct_definition(f_service_, ts, false);
    generate_ocaml_function_helpers(*f_iter);
  }
}

/**
 * Generates a struct and helpers for a function.
 *
 * @param tfunction The function
 */
void t_ocaml_generator::generate_ocaml_function_helpers(
    const t_function* tfunction) {
  t_struct result(program_, decapitalize(tfunction->get_name()) + "_result");
  auto success =
      std::make_unique<t_field>(tfunction->get_returntype(), "success", 0);
  if (!tfunction->get_returntype()->is_void()) {
    result.append(std::move(success));
  }

  const t_struct* xs = tfunction->get_xceptions();
  const vector<t_field*>& fields = xs->get_members();
  vector<t_field*>::const_iterator f_iter;
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    result.append((*f_iter)->clone_DO_NOT_USE());
  }
  generate_ocaml_struct_definition(f_service_, &result, false);
}

/**
 * Generates a service interface definition.
 *
 * @param tservice The service to generate a header definition for
 */
void t_ocaml_generator::generate_service_interface(const t_service* tservice) {
  f_service_ << indent() << "class virtual iface =" << endl
             << "object (self)" << endl;
  f_service_i_ << indent() << "class virtual iface :" << endl
               << "object" << endl;

  indent_up();

  if (tservice->get_extends() != nullptr) {
    string extends = type_name(tservice->get_extends());
    indent(f_service_) << "inherit " << extends << ".iface" << endl;
    indent(f_service_i_) << "inherit " << extends << ".iface" << endl;
  }

  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    string ft = function_type(*f_iter, true, true);
    f_service_ << indent() << "method virtual "
               << decapitalize((*f_iter)->get_name()) << " : " << ft << endl;
    f_service_i_ << indent() << "method virtual "
                 << decapitalize((*f_iter)->get_name()) << " : " << ft << endl;
  }
  indent_down();
  indent(f_service_) << "end" << endl << endl;
  indent(f_service_i_) << "end" << endl << endl;
}

/**
 * Generates a service client definition. Note that in OCaml, the client doesn't
 * implement iface. This is because The client does not (and should not have to)
 * deal with arguments being None.
 *
 * @param tservice The service to generate a server for.
 */
void t_ocaml_generator::generate_service_client(const t_service* tservice) {
  string extends = "";
  indent(f_service_)
      << "class client (iprot : Protocol.t) (oprot : Protocol.t) =" << endl
      << "object (self)" << endl;
  indent(f_service_i_) << "class client : Protocol.t -> Protocol.t -> " << endl
                       << "object" << endl;
  indent_up();

  if (tservice->get_extends() != nullptr) {
    extends = type_name(tservice->get_extends());
    indent(f_service_) << "inherit " << extends
                       << ".client iprot oprot as super" << endl;
    indent(f_service_i_) << "inherit " << extends << ".client" << endl;
  }
  indent(f_service_) << "val mutable seqid = 0" << endl;

  // Generate client method implementations
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::const_iterator f_iter;
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    const t_struct* arg_struct = (*f_iter)->get_paramlist();
    const vector<t_field*>& fields = arg_struct->get_members();
    vector<t_field*>::const_iterator fld_iter;
    string funname = (*f_iter)->get_name();

    // Open function
    indent(f_service_) << "method " << function_signature(*f_iter) << " = "
                       << endl;
    indent(f_service_i_) << "method " << decapitalize((*f_iter)->get_name())
                         << " : " << function_type(*f_iter, true, false)
                         << endl;
    indent_up();
    indent(f_service_) << "self#send_" << funname;

    for (fld_iter = fields.begin(); fld_iter != fields.end(); ++fld_iter) {
      f_service_ << " " << decapitalize((*fld_iter)->get_name());
    }
    f_service_ << ";" << endl;

    if (!(*f_iter)->is_oneway()) {
      f_service_ << indent();
      f_service_ << "self#recv_" << funname << endl;
    }
    indent_down();

    indent(f_service_) << "method private send_" << function_signature(*f_iter)
                       << " = " << endl;
    indent_up();

    std::string argsname = decapitalize((*f_iter)->get_name() + "_args");

    // Serialize the request header
    f_service_ << indent() << "oprot#writeMessageBegin (\""
               << (*f_iter)->get_name() << "\", Protocol.CALL, seqid);" << endl;

    f_service_ << indent() << "let args = new " << argsname << " in" << endl;
    indent_up();

    for (fld_iter = fields.begin(); fld_iter != fields.end(); ++fld_iter) {
      f_service_ << indent() << "args#set_" << (*fld_iter)->get_name() << " "
                 << (*fld_iter)->get_name() << ";" << endl;
    }

    // Write to the stream
    f_service_ << indent() << "args#write oprot;" << endl
               << indent() << "oprot#writeMessageEnd;" << endl
               << indent() << "oprot#getTransport#flush" << endl;

    indent_down();
    indent_down();

    if (!(*f_iter)->is_oneway()) {
      std::string resultname = decapitalize((*f_iter)->get_name() + "_result");

      t_function recv_function(
          (*f_iter)->get_returntype(),
          string("recv_") + (*f_iter)->get_name(),
          std::make_unique<t_paramlist>(program_));
      // Open function
      f_service_ << indent() << "method private "
                 << function_signature(&recv_function) << " =" << endl;
      indent_up();

      // TODO(mcslee): Validate message reply here, seq ids etc.

      f_service_ << indent()
                 << "let (fname, mtype, rseqid) = iprot#readMessageBegin in"
                 << endl;
      indent_up();
      f_service_ << indent() << "(if mtype = Protocol.EXCEPTION then" << endl
                 << indent() << "  let x = Application_Exn.read iprot in"
                 << endl;
      indent_up();
      f_service_ << indent() << "  (iprot#readMessageEnd;" << indent()
                 << "   raise (Application_Exn.E x))" << endl;
      indent_down();
      f_service_ << indent() << "else ());" << endl;
      string res = "_";

      const t_struct* xs = (*f_iter)->get_xceptions();
      const std::vector<t_field*>& xceptions = xs->get_members();

      if (!(*f_iter)->get_returntype()->is_void() || xceptions.size() > 0) {
        res = "result";
      }
      f_service_ << indent() << "let " << res << " = read_" << resultname
                 << " iprot in" << endl;
      indent_up();
      f_service_ << indent() << "iprot#readMessageEnd;" << endl;

      // Careful, only return _result if not a void function
      if (!(*f_iter)->get_returntype()->is_void()) {
        f_service_ << indent()
                   << "match result#get_success with Some v -> v | None -> ("
                   << endl;
        indent_up();
      }

      vector<t_field*>::const_iterator x_iter;
      for (x_iter = xceptions.begin(); x_iter != xceptions.end(); ++x_iter) {
        f_service_ << indent() << "(match result#get_" << (*x_iter)->get_name()
                   << " with None -> () | Some _v ->" << endl;
        indent(f_service_) << "  raise ("
                           << capitalize(type_name((*x_iter)->get_type()))
                           << " _v));" << endl;
      }

      // Careful, only return _result if not a void function
      if ((*f_iter)->get_returntype()->is_void()) {
        indent(f_service_) << "()" << endl;
      } else {
        f_service_
            << indent()
            << "raise (Application_Exn.E (Application_Exn.create Application_Exn.MISSING_RESULT \""
            << (*f_iter)->get_name() << " failed: unknown result\")))" << endl;
        indent_down();
      }

      // Close function
      indent_down();
      indent_down();
      indent_down();
    }
  }

  indent_down();
  indent(f_service_) << "end" << endl << endl;
  indent(f_service_i_) << "end" << endl << endl;
}

/**
 * Generates a service server definition.
 *
 * @param tservice The service to generate a server for.
 */
void t_ocaml_generator::generate_service_server(const t_service* tservice) {
  // Generate the dispatch methods
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  // Generate the header portion
  indent(f_service_) << "class processor (handler : iface) =" << endl
                     << indent() << "object (self)" << endl;
  indent(f_service_i_) << "class processor : iface ->" << endl
                       << indent() << "object" << endl;
  indent_up();

  f_service_ << indent() << "inherit Processor.t" << endl << endl;
  f_service_i_ << indent() << "inherit Processor.t" << endl << endl;
  string extends = "";

  if (tservice->get_extends() != nullptr) {
    extends = type_name(tservice->get_extends());
    indent(f_service_) << "inherit " + extends + ".processor (handler :> " +
            extends +
            ".iface)" << endl;
    indent(f_service_i_) << "inherit " + extends + ".processor" << endl;
  }

  if (extends.empty()) {
    indent(f_service_) << "val processMap = Hashtbl.create " << functions.size()
                       << endl;
  }
  indent(f_service_i_)
      << "val processMap : (string, int * Protocol.t * Protocol.t -> unit) Hashtbl.t"
      << endl;

  // Generate the server implementation
  indent(f_service_) << "method process iprot oprot =" << endl;
  indent(f_service_i_) << "method process : Protocol.t -> Protocol.t -> bool"
                       << endl;
  indent_up();

  f_service_ << indent()
             << "let (name, typ, seqid)  = iprot#readMessageBegin in" << endl;
  indent_up();
  // TODO(mcslee): validate message

  // HOT: dictionary function lookup
  f_service_
      << indent() << "if Hashtbl.mem processMap name then" << endl
      << indent() << "  (Hashtbl.find processMap name) (seqid, iprot, oprot)"
      << endl
      << indent() << "else (" << endl
      << indent() << "  iprot#skip(Protocol.T_STRUCT);" << endl
      << indent() << "  iprot#readMessageEnd;" << endl
      << indent()
      << "  let x = Application_Exn.create Application_Exn.UNKNOWN_METHOD (\"Unknown function \"^name) in"
      << endl
      << indent()
      << "    oprot#writeMessageBegin(name, Protocol.EXCEPTION, seqid);" << endl
      << indent() << "    x#write oprot;" << endl
      << indent() << "    oprot#writeMessageEnd;" << endl
      << indent() << "    oprot#getTransport#flush" << endl
      << indent() << ");" << endl;

  // Read end of args field, the T_STOP, and the struct close
  f_service_ << indent() << "true" << endl;
  indent_down();
  indent_down();
  // Generate the process subfunctions
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    generate_process_function(tservice, *f_iter);
  }

  indent(f_service_) << "initializer" << endl;
  indent_up();
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    f_service_ << indent() << "Hashtbl.add processMap \""
               << (*f_iter)->get_name() << "\" self#process_"
               << (*f_iter)->get_name() << ";" << endl;
  }
  indent_down();

  indent_down();
  indent(f_service_) << "end" << endl << endl;
  indent(f_service_i_) << "end" << endl << endl;
}

/**
 * Generates a process function definition.
 *
 * @param tfunction The function to write a dispatcher for
 */
void t_ocaml_generator::generate_process_function(
    const t_service* /* tservice */, const t_function* tfunction) {
  // Open function
  indent(f_service_) << "method private process_" << tfunction->get_name()
                     << " (seqid, iprot, oprot) =" << endl;
  indent_up();

  string argsname = decapitalize(tfunction->get_name()) + "_args";
  string resultname = decapitalize(tfunction->get_name()) + "_result";

  // Generate the function call
  const t_struct* arg_struct = tfunction->get_paramlist();
  const std::vector<t_field*>& fields = arg_struct->get_members();
  vector<t_field*>::const_iterator f_iter;

  string args = "args";
  if (fields.size() == 0) {
    args = "_";
  }

  f_service_ << indent() << "let " << args << " = read_" << argsname
             << " iprot in" << endl;
  indent_up();
  f_service_ << indent() << "iprot#readMessageEnd;" << endl;

  const t_struct* xs = tfunction->get_xceptions();
  const std::vector<t_field*>& xceptions = xs->get_members();
  vector<t_field*>::const_iterator x_iter;

  // Declare result for non oneway function
  if (!tfunction->is_oneway()) {
    f_service_ << indent() << "let result = new " << resultname << " in"
               << endl;
    indent_up();
  }

  // Try block for a function with exceptions
  if (xceptions.size() > 0) {
    f_service_ << indent() << "(try" << endl;
    indent_up();
  }

  f_service_ << indent();
  if (!tfunction->is_oneway() && !tfunction->get_returntype()->is_void()) {
    f_service_ << "result#set_success ";
  }
  f_service_ << "(handler#" << tfunction->get_name();
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    f_service_ << " args#get_" << (*f_iter)->get_name();
  }
  f_service_ << ");" << endl;

  if (xceptions.size() > 0) {
    indent_down();
    indent(f_service_) << "with" << endl;
    indent_up();
    for (x_iter = xceptions.begin(); x_iter != xceptions.end(); ++x_iter) {
      f_service_ << indent() << "| "
                 << capitalize(type_name((*x_iter)->get_type())) << " "
                 << (*x_iter)->get_name() << " -> " << endl;
      indent_up();
      indent_up();
      if (!tfunction->is_oneway()) {
        f_service_ << indent() << "result#set_" << (*x_iter)->get_name() << " "
                   << (*x_iter)->get_name() << endl;
      } else {
        indent(f_service_) << "()";
      }
      indent_down();
      indent_down();
    }
    indent_down();
    f_service_ << indent() << ");" << endl;
  }

  // Shortcut out here for oneway functions
  if (tfunction->is_oneway()) {
    f_service_ << indent() << "()" << endl;
    indent_down();
    indent_down();
    return;
  }

  f_service_ << indent() << "oprot#writeMessageBegin (\""
             << tfunction->get_name() << "\", Protocol.REPLY, seqid);" << endl
             << indent() << "result#write oprot;" << endl
             << indent() << "oprot#writeMessageEnd;" << endl
             << indent() << "oprot#getTransport#flush" << endl;

  // Close function
  indent_down();
  indent_down();
  indent_down();
}

/**
 * Deserializes a field of any type.
 */
void t_ocaml_generator::generate_deserialize_field(
    ofstream& out, const t_field* tfield, string prefix) {
  const t_type* type = tfield->get_type();

  string name = decapitalize(tfield->get_name());
  indent(out) << prefix << "#set_" << name << " ";
  generate_deserialize_type(out, type);
  out << endl;
}

/**
 * Deserializes a field of any type.
 */
void t_ocaml_generator::generate_deserialize_type(
    ofstream& out, const t_type* type) {
  type = type->get_true_type();

  if (type->is_void()) {
    throw std::runtime_error("CANNOT GENERATE DESERIALIZE CODE FOR void TYPE");
  }

  if (type->is_struct() || type->is_xception()) {
    generate_deserialize_struct(out, (t_struct*)type);
  } else if (type->is_container()) {
    generate_deserialize_container(out, type);
  } else if (type->is_base_type()) {
    out << "iprot#";
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_VOID:
        throw std::runtime_error(
            "compiler error: cannot serialize void field in a struct");
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        out << "readString";
        break;
      case t_base_type::TYPE_BOOL:
        out << "readBool";
        break;
      case t_base_type::TYPE_BYTE:
        out << "readByte";
        break;
      case t_base_type::TYPE_I16:
        out << "readI16";
        break;
      case t_base_type::TYPE_I32:
        out << "readI32";
        break;
      case t_base_type::TYPE_I64:
        out << "readI64";
        break;
      case t_base_type::TYPE_DOUBLE:
        out << "readDouble";
        break;
      default:
        throw std::runtime_error(
            "compiler error: no PHP name for base type " +
            t_base_type::t_base_name(tbase));
    }
  } else if (type->is_enum()) {
    string ename = capitalize(type->get_name());
    out << "(" << ename << ".of_i iprot#readI32)";
  } else {
    printf(
        "DO NOT KNOW HOW TO DESERIALIZE TYPE '%s'\n", type->get_name().c_str());
  }
}

/**
 * Generates an unserializer for a struct, calling read()
 */
void t_ocaml_generator::generate_deserialize_struct(
    ofstream& out, const t_struct* tstruct) {
  string name = decapitalize(tstruct->get_name());
  out << "(read_" << name << " iprot)";
}

/**
 * Serialize a container by writing out the header followed by
 * data and then a footer.
 */
void t_ocaml_generator::generate_deserialize_container(
    ofstream& out, const t_type* ttype) {
  string size = tmp("_size");
  string ktype = tmp("_ktype");
  string vtype = tmp("_vtype");
  string etype = tmp("_etype");
  string con = tmp("_con");

  t_field fsize(i32_type(), size);
  t_field fktype(byte_type(), ktype);
  t_field fvtype(byte_type(), vtype);
  t_field fetype(byte_type(), etype);

  out << endl;
  indent_up();
  // Declare variables, read header
  if (ttype->is_map()) {
    indent(out) << "(let (" << ktype << "," << vtype << "," << size
                << ") = iprot#readMapBegin in" << endl;
    indent(out) << "let " << con << " = Hashtbl.create " << size << " in"
                << endl;
    indent_up();
    indent(out) << "for i = 1 to " << size << " do" << endl;
    indent_up();
    indent(out) << "let _k = ";
    generate_deserialize_type(out, ((t_map*)ttype)->get_key_type());
    out << " in" << endl;
    indent(out) << "let _v = ";
    generate_deserialize_type(out, ((t_map*)ttype)->get_val_type());
    out << " in" << endl;
    indent_up();
    indent(out) << "Hashtbl.add " << con << " _k _v" << endl;
    indent_down();
    indent_down();
    indent(out) << "done; iprot#readMapEnd; " << con << ")";
    indent_down();
  } else if (ttype->is_set()) {
    indent(out) << "(let (" << etype << "," << size
                << ") = iprot#readSetBegin in" << endl;
    indent(out) << "let " << con << " = Hashtbl.create " << size << " in"
                << endl;
    indent_up();
    indent(out) << "for i = 1 to " << size << " do" << endl;
    indent_up();
    indent(out) << "Hashtbl.add " << con << " ";
    generate_deserialize_type(out, ((t_set*)ttype)->get_elem_type());
    out << " true" << endl;
    indent_down();
    indent(out) << "done; iprot#readSetEnd; " << con << ")";
    indent_down();
  } else if (ttype->is_list()) {
    indent(out) << "(let (" << etype << "," << size
                << ") = iprot#readListBegin in" << endl;
    indent_up();
    indent(out) << "let " << con << " = (Array.to_list (Array.init " << size
                << " (fun _ -> ";
    generate_deserialize_type(out, ((t_list*)ttype)->get_elem_type());
    out << "))) in" << endl;
    indent_up();
    indent(out) << "iprot#readListEnd; " << con << ")";
    indent_down();
    indent_down();
  }
  indent_down();
}

/**
 * Serializes a field of any type.
 *
 * @param tfield The field to serialize
 * @param prefix Name to prepend to field name
 */
void t_ocaml_generator::generate_serialize_field(
    ofstream& out, const t_field* tfield, string name) {
  const t_type* type = tfield->get_type()->get_true_type();

  // Do nothing for void types
  if (type->is_void()) {
    throw std::runtime_error(
        "CANNOT GENERATE SERIALIZE CODE FOR void TYPE: " + tfield->get_name());
  }

  if (name.length() == 0) {
    name = decapitalize(tfield->get_name());
  }

  if (type->is_struct() || type->is_xception()) {
    generate_serialize_struct(out, (t_struct*)type, name);
  } else if (type->is_container()) {
    generate_serialize_container(out, type, name);
  } else if (type->is_base_type() || type->is_enum()) {
    indent(out) << "oprot#";

    if (type->is_base_type()) {
      t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
      switch (tbase) {
        case t_base_type::TYPE_VOID:
          throw std::runtime_error(
              "compiler error: cannot serialize void field in a struct: " +
              name);
        case t_base_type::TYPE_STRING:
        case t_base_type::TYPE_BINARY:
          out << "writeString(" << name << ")";
          break;
        case t_base_type::TYPE_BOOL:
          out << "writeBool(" << name << ")";
          break;
        case t_base_type::TYPE_BYTE:
          out << "writeByte(" << name << ")";
          break;
        case t_base_type::TYPE_I16:
          out << "writeI16(" << name << ")";
          break;
        case t_base_type::TYPE_I32:
          out << "writeI32(" << name << ")";
          break;
        case t_base_type::TYPE_I64:
          out << "writeI64(" << name << ")";
          break;
        case t_base_type::TYPE_DOUBLE:
          out << "writeDouble(" << name << ")";
          break;
        default:
          throw std::runtime_error(
              "compiler error: no ocaml name for base type " +
              t_base_type::t_base_name(tbase));
      }
    } else if (type->is_enum()) {
      string ename = capitalize(type->get_name());
      out << "writeI32(" << ename << ".to_i " << name << ")";
    }

  } else {
    printf(
        "DO NOT KNOW HOW TO SERIALIZE FIELD '%s' TYPE '%s'\n",
        tfield->get_name().c_str(),
        type->get_name().c_str());
  }
  out << ";" << endl;
}

/**
 * Serializes all the members of a struct.
 *
 * @param tstruct The struct to serialize
 * @param prefix  String prefix to attach to all fields
 */
void t_ocaml_generator::generate_serialize_struct(
    ofstream& out, const t_struct* /* tstruct */, string prefix) {
  indent(out) << prefix << "#write(oprot)";
}

void t_ocaml_generator::generate_serialize_container(
    ofstream& out, const t_type* ttype, string prefix) {
  if (ttype->is_map()) {
    indent(out) << "oprot#writeMapBegin("
                << type_to_enum(((t_map*)ttype)->get_key_type()) << ",";
    out << type_to_enum(((t_map*)ttype)->get_val_type()) << ",";
    out << "Hashtbl.length " << prefix << ");" << endl;
  } else if (ttype->is_set()) {
    indent(out) << "oprot#writeSetBegin("
                << type_to_enum(((t_set*)ttype)->get_elem_type()) << ",";
    out << "Hashtbl.length " << prefix << ");" << endl;
  } else if (ttype->is_list()) {
    indent(out) << "oprot#writeListBegin("
                << type_to_enum(((t_list*)ttype)->get_elem_type()) << ",";
    out << "List.length " << prefix << ");" << endl;
  }

  if (ttype->is_map()) {
    string kiter = tmp("_kiter");
    string viter = tmp("_viter");
    indent(out) << "Hashtbl.iter (fun " << kiter << " -> fun " << viter
                << " -> " << endl;
    indent_up();
    generate_serialize_map_element(out, (t_map*)ttype, kiter, viter);
    indent_down();
    indent(out) << ") " << prefix << ";" << endl;
  } else if (ttype->is_set()) {
    string iter = tmp("_iter");
    indent(out) << "Hashtbl.iter (fun " << iter << " -> fun _ -> ";
    indent_up();
    generate_serialize_set_element(out, (t_set*)ttype, iter);
    indent_down();
    indent(out) << ") " << prefix << ";" << endl;
  } else if (ttype->is_list()) {
    string iter = tmp("_iter");
    indent(out) << "List.iter (fun " << iter << " -> ";
    indent_up();
    generate_serialize_list_element(out, (t_list*)ttype, iter);
    indent_down();
    indent(out) << ") " << prefix << ";" << endl;
  }

  if (ttype->is_map()) {
    indent(out) << "oprot#writeMapEnd";
  } else if (ttype->is_set()) {
    indent(out) << "oprot#writeSetEnd";
  } else if (ttype->is_list()) {
    indent(out) << "oprot#writeListEnd";
  }
}

/**
 * Serializes the members of a map.
 *
 */
void t_ocaml_generator::generate_serialize_map_element(
    ofstream& out, const t_map* tmap, string kiter, string viter) {
  t_field kfield(tmap->get_key_type(), kiter);
  generate_serialize_field(out, &kfield);

  t_field vfield(tmap->get_val_type(), viter);
  generate_serialize_field(out, &vfield);
}

/**
 * Serializes the members of a set.
 */
void t_ocaml_generator::generate_serialize_set_element(
    ofstream& out, const t_set* tset, string iter) {
  t_field efield(tset->get_elem_type(), iter);
  generate_serialize_field(out, &efield);
}

/**
 * Serializes the members of a list.
 */
void t_ocaml_generator::generate_serialize_list_element(
    ofstream& out, const t_list* tlist, string iter) {
  t_field efield(tlist->get_elem_type(), iter);
  generate_serialize_field(out, &efield);
}

/**
 * Renders a function signature of the form 'name args'
 *
 * @param tfunction Function definition
 * @return String of rendered function definition
 */
string t_ocaml_generator::function_signature(
    const t_function* tfunction, string prefix) {
  return prefix + decapitalize(tfunction->get_name()) + " " +
      argument_list(tfunction->get_paramlist());
}

string t_ocaml_generator::function_type(
    const t_function* tfunc, bool method, bool options) {
  string result = "";

  const vector<t_field*>& fields = tfunc->get_paramlist()->get_members();
  vector<t_field*>::const_iterator f_iter;
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    result += render_ocaml_type((*f_iter)->get_type());
    if (options)
      result += " option";
    result += " -> ";
  }
  if (fields.empty() && !method) {
    result += "unit -> ";
  }
  result += render_ocaml_type(tfunc->get_returntype());
  return result;
}

/**
 * Renders a field list
 */
string t_ocaml_generator::argument_list(const t_struct* tstruct) {
  string result = "";

  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;
  bool first = true;
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    if (first) {
      first = false;
    } else {
      result += " ";
    }
    result += (*f_iter)->get_name();
  }
  return result;
}

string t_ocaml_generator::type_name(const t_type* ttype) {
  string prefix = "";
  const t_program* program = ttype->get_program();
  if (program != nullptr && program != program_) {
    if (!ttype->is_service()) {
      prefix = capitalize(program->name()) + "_types.";
    }
  }

  string name = ttype->get_name();
  if (ttype->is_service()) {
    name = capitalize(name);
  } else {
    name = decapitalize(name);
  }
  return prefix + name;
}

/**
 * Converts the parse type to a Protocol.t_type enum
 */
string t_ocaml_generator::type_to_enum(const t_type* type) {
  type = type->get_true_type();

  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_VOID:
        return "Protocol.T_VOID";
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        return "Protocol.T_STRING";
      case t_base_type::TYPE_BOOL:
        return "Protocol.T_BOOL";
      case t_base_type::TYPE_BYTE:
        return "Protocol.T_BYTE";
      case t_base_type::TYPE_I16:
        return "Protocol.T_I16";
      case t_base_type::TYPE_I32:
        return "Protocol.T_I32";
      case t_base_type::TYPE_I64:
        return "Protocol.T_I64";
      case t_base_type::TYPE_FLOAT:
        return "Protocol.T_FLOAT";
      case t_base_type::TYPE_DOUBLE:
        return "Protocol.T_DOUBLE";
    }
  } else if (type->is_enum()) {
    return "Protocol.T_I32";
  } else if (type->is_struct() || type->is_xception()) {
    return "Protocol.T_STRUCT";
  } else if (type->is_map()) {
    return "Protocol.T_MAP";
  } else if (type->is_set()) {
    return "Protocol.T_SET";
  } else if (type->is_list()) {
    return "Protocol.T_LIST";
  }

  throw std::runtime_error("INVALID TYPE IN type_to_enum: " + type->get_name());
}

/**
 * Converts the parse type to an ocaml type
 */
string t_ocaml_generator::render_ocaml_type(const t_type* type) {
  type = type->get_true_type();

  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_VOID:
        return "unit";
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        return "string";
      case t_base_type::TYPE_BOOL:
        return "bool";
      case t_base_type::TYPE_BYTE:
        return "int";
      case t_base_type::TYPE_I16:
        return "int";
      case t_base_type::TYPE_I32:
        return "Int32.t";
      case t_base_type::TYPE_I64:
        return "Int64.t";
      case t_base_type::TYPE_FLOAT:
      case t_base_type::TYPE_DOUBLE:
        return "float";
    }
  } else if (type->is_enum()) {
    return capitalize(((t_enum*)type)->get_name()) + ".t";
  } else if (type->is_struct() || type->is_xception()) {
    return type_name((t_struct*)type);
  } else if (type->is_map()) {
    const t_type* ktype = ((t_map*)type)->get_key_type();
    const t_type* vtype = ((t_map*)type)->get_val_type();
    return "(" + render_ocaml_type(ktype) + "," + render_ocaml_type(vtype) +
        ") Hashtbl.t";
  } else if (type->is_set()) {
    const t_type* etype = ((t_set*)type)->get_elem_type();
    return "(" + render_ocaml_type(etype) + ",bool) Hashtbl.t";
  } else if (type->is_list()) {
    const t_type* etype = ((t_list*)type)->get_elem_type();
    return render_ocaml_type(etype) + " list";
  }

  throw std::runtime_error("INVALID TYPE IN type_to_enum: " + type->get_name());
}

THRIFT_REGISTER_GENERATOR(ocaml, "OCaml", "");

} // namespace compiler
} // namespace thrift
} // namespace apache
