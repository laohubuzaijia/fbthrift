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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <sys/types.h>
#include <sstream>

#include <boost/filesystem.hpp>

#include <thrift/compiler/ast/base_types.h>
#include <thrift/compiler/generate/t_oop_generator.h>

using namespace std;

namespace apache {
namespace thrift {
namespace compiler {

/**
 * Ruby code generator.
 *
 */
class t_rb_generator : public t_oop_generator {
 public:
  t_rb_generator(
      t_program* program,
      t_generation_context context,
      const std::map<std::string, std::string>& /*parsed_options*/,
      const std::string& /*option_string*/)
      : t_oop_generator(program, std::move(context)) {
    out_dir_base_ = "gen-rb";
  }

  /**
   * Init and close methods
   */

  void init_generator() override;
  void close_generator() override;

  /**
   * Program-level generation functions
   */

  void generate_typedef(const t_typedef* ttypedef) override;
  void generate_enum(const t_enum* tenum) override;
  void generate_const(const t_const* tconst) override;
  void generate_struct(const t_struct* tstruct) override;
  void generate_xception(const t_struct* txception) override;
  void generate_service(const t_service* tservice) override;

  std::string render_const_value(
      const t_type* type, const t_const_value* value);

  /**
   * Struct generation code
   */

  void generate_rb_struct(
      std::ofstream& out, const t_struct* tstruct, bool is_exception);
  void generate_rb_struct_required_validator(
      std::ofstream& out, const t_struct* tstruct);
  void generate_rb_function_helpers(const t_function* tfunction);
  void generate_rb_simple_constructor(
      std::ofstream& out, const t_struct* tstruct);
  void generate_rb_simple_exception_constructor(
      std::ofstream& out, const t_struct* tstruct);
  void generate_field_constants(std::ofstream& out, const t_struct* tstruct);
  void generate_accessors(std::ofstream& out, const t_struct* tstruct);
  void generate_field_defns(std::ofstream& out, const t_struct* tstruct);
  void generate_field_data(
      std::ofstream& out,
      const t_type* field_type,
      const std::string& field_name = "",
      const t_const_value* field_value = nullptr,
      bool optional = false);

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
      std::ofstream& out,
      const t_field* tfield,
      std::string prefix = "",
      bool inclass = false);

  void generate_deserialize_struct(
      std::ofstream& out, const t_struct* tstruct, std::string prefix = "");

  void generate_deserialize_container(
      std::ofstream& out, const t_type* ttype, std::string prefix = "");

  void generate_deserialize_set_element(
      std::ofstream& out, const t_set* tset, std::string prefix = "");

  void generate_deserialize_map_element(
      std::ofstream& out, const t_map* tmap, std::string prefix = "");

  void generate_deserialize_list_element(
      std::ofstream& out, const t_list* tlist, std::string prefix = "");

  void generate_serialize_field(
      std::ofstream& out, const t_field* tfield, std::string prefix = "");

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

  void generate_rdoc(std::ofstream& out, const t_node* tdoc);

  /**
   * Helper rendering functions
   */

  std::string rb_autogen_comment();
  std::string render_includes();
  std::string declare_field(const t_field* tfield);
  std::string type_name(const t_type* ttype);
  std::string full_type_name(const t_type* ttype);
  std::string function_signature(
      const t_function* tfunction, std::string prefix = "");
  std::string argument_list(const t_struct* tstruct);
  std::string type_to_enum(const t_type* ttype);

  std::vector<std::string> ruby_modules(const t_program* p) {
    std::string ns = p->get_namespace("rb");
    std::vector<std::string> modules;
    if (ns.empty()) {
      return modules;
    }

    std::string::iterator pos = ns.begin();
    while (true) {
      std::string::iterator delim = std::find(pos, ns.end(), '.');
      modules.push_back(camelcase(std::string(pos, delim), true));
      pos = delim;
      if (pos == ns.end()) {
        break;
      }
      ++pos;
    }

    return modules;
  }

  void begin_namespace(std::ofstream&, std::vector<std::string>);
  void end_namespace(std::ofstream&, std::vector<std::string>);

 private:
  /**
   * File streams
   */

  std::ofstream f_types_;
  std::ofstream f_consts_;
  std::ofstream f_service_;
};

/**
 * Prepares for file generation by opening up the necessary file output
 * streams.
 *
 * @param tprogram The program to generate
 */
void t_rb_generator::init_generator() {
  // Make output directory
  boost::filesystem::create_directory(get_out_dir());

  // Make output file
  string f_types_name = get_out_dir() + underscore(program_name_) + "_types.rb";
  f_types_.open(f_types_name.c_str());
  record_genfile(f_types_name);

  string f_consts_name =
      get_out_dir() + underscore(program_name_) + "_constants.rb";
  f_consts_.open(f_consts_name.c_str());
  record_genfile(f_consts_name);

  // Print header
  f_types_ << rb_autogen_comment() << endl << render_includes() << endl;
  begin_namespace(f_types_, ruby_modules(program_));

  f_consts_ << rb_autogen_comment() << endl
            << "require '" << underscore(program_name_) << "_types'" << endl
            << endl;
  begin_namespace(f_consts_, ruby_modules(program_));
}

/**
 * Renders all the imports necessary for including another Thrift program
 */
string t_rb_generator::render_includes() {
  const vector<t_program*>& includes = program_->get_included_programs();
  string result = "";
  for (size_t i = 0; i < includes.size(); ++i) {
    result += "require '" + underscore(includes[i]->name()) + "_types'\n";
  }
  if (includes.size() > 0) {
    result += "\n";
  }
  return result;
}

/**
 * Autogen'd comment
 */
string t_rb_generator::rb_autogen_comment() {
  return std::string("#\n") + "# Autogenerated by Thrift\n" + "#\n" +
      "# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING\n" +
      "# @"
      "generated\n" +
      "#\n";
}

/**
 * Closes the type files
 */
void t_rb_generator::close_generator() {
  // Close types file
  end_namespace(f_types_, ruby_modules(program_));
  end_namespace(f_consts_, ruby_modules(program_));
  f_types_.close();
  f_consts_.close();
}

/**
 * Generates a typedef. This is not done in Ruby, types are all implicit.
 *
 * @param ttypedef The type definition
 */
void t_rb_generator::generate_typedef(const t_typedef* /*ttypedef*/) {}

/**
 * Generates code for an enumerated type. Done using a class to scope
 * the values.
 *
 * @param tenum The enumeration
 */
void t_rb_generator::generate_enum(const t_enum* tenum) {
  indent(f_types_) << "module " << capitalize(tenum->get_name()) << endl;
  indent_up();

  vector<t_enum_value*> constants = tenum->get_enum_values();
  vector<t_enum_value*>::iterator c_iter;
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    int32_t value = (*c_iter)->get_value();

    // Ruby class constants have to be capitalized... omg i am so on the fence
    // about languages strictly enforcing capitalization why can't we just all
    // agree and play nice.
    string name = capitalize((*c_iter)->get_name());

    f_types_ << indent() << name << " = " << value << endl;
  }

  // Create a hash mapping values back to their names (as strings) since ruby
  // has no native enum type
  indent(f_types_) << "VALUE_MAP = {";
  bool first = true;
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    // Populate the hash
    int32_t value = (*c_iter)->get_value();

    if (first) {
      first = false;
    } else {
      f_types_ << ", ";
    }
    f_types_ << value << " => \"" << capitalize((*c_iter)->get_name()) << "\"";
  }
  f_types_ << "}" << endl;

  // Create a set with valid values for this enum
  indent(f_types_) << "VALID_VALUES = Set.new([";
  first = true;
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    // Populate the set
    if (first) {
      first = false;
    } else {
      f_types_ << ", ";
    }
    f_types_ << capitalize((*c_iter)->get_name());
  }
  f_types_ << "]).freeze" << endl;

  indent_down();
  indent(f_types_) << "end" << endl << endl;
}

/**
 * Generate a constant value
 */
void t_rb_generator::generate_const(const t_const* tconst) {
  const t_type* type = tconst->get_type();
  string name = tconst->get_name();
  t_const_value* value = tconst->get_value();

  name[0] = toupper(name[0]);

  indent(f_consts_) << name << " = " << render_const_value(type, value);
  f_consts_ << endl << endl;
}

/**
 * Prints the value of a constant with the given type. Note that type checking
 * is NOT performed in this function as it is always run beforehand using the
 * validate_types method in main.cc
 */
string t_rb_generator::render_const_value(
    const t_type* type, const t_const_value* value) {
  type = type->get_true_type();
  std::ostringstream out;
  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        out << "%q\"" << value->get_string() << '"';
        break;
      case t_base_type::TYPE_BOOL:
        out << (value->get_integer() > 0 ? "true" : "false");
        break;
      case t_base_type::TYPE_BYTE:
      case t_base_type::TYPE_I16:
      case t_base_type::TYPE_I32:
      case t_base_type::TYPE_I64:
        out << value->get_integer();
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
    indent(out) << value->get_integer();
  } else if (type->is_struct() || type->is_xception()) {
    out << full_type_name(type) << ".new({" << endl;
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
      out << indent();
      out << render_const_value(string_type(), v_iter->first);
      out << " => ";
      out << render_const_value(field_type, v_iter->second);
      out << "," << endl;
    }
    indent_down();
    indent(out) << "})";
  } else if (type->is_map()) {
    const t_type* ktype = ((t_map*)type)->get_key_type();
    const t_type* vtype = ((t_map*)type)->get_val_type();
    out << "{" << endl;
    indent_up();
    const vector<pair<t_const_value*, t_const_value*>>& val = value->get_map();
    vector<pair<t_const_value*, t_const_value*>>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      out << indent();
      out << render_const_value(ktype, v_iter->first);
      out << " => ";
      out << render_const_value(vtype, v_iter->second);
      out << "," << endl;
    }
    indent_down();
    indent(out) << "}";
  } else if (type->is_list() || type->is_set()) {
    const t_type* etype;
    if (type->is_list()) {
      etype = ((t_list*)type)->get_elem_type();
    } else {
      etype = ((t_set*)type)->get_elem_type();
    }
    if (type->is_set()) {
      out << "Set.new([" << endl;
    } else {
      out << "[" << endl;
    }
    indent_up();
    const vector<t_const_value*>& val = value->get_list();
    vector<t_const_value*>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      out << indent();
      out << render_const_value(etype, *v_iter);
      out << "," << endl;
    }
    indent_down();
    if (type->is_set()) {
      indent(out) << "])";
    } else {
      indent(out) << "]";
    }
  } else {
    throw std::runtime_error(
        "CANNOT GENERATE CONSTANT FOR TYPE: " + type->get_name());
  }
  return out.str();
}

/**
 * Generates a ruby struct
 */
void t_rb_generator::generate_struct(const t_struct* tstruct) {
  generate_rb_struct(f_types_, tstruct, false);
}

/**
 * Generates a struct definition for a thrift exception. Basically the same
 * as a struct but extends the Exception class.
 *
 * @param txception The struct definition
 */
void t_rb_generator::generate_xception(const t_struct* txception) {
  generate_rb_struct(f_types_, txception, true);
}

/**
 * Generates a ruby struct
 */
void t_rb_generator::generate_rb_struct(
    std::ofstream& out, const t_struct* tstruct, bool is_exception = false) {
  generate_rdoc(out, tstruct);
  indent(out) << "class " << type_name(tstruct);
  if (is_exception) {
    out << " < ::Thrift::Exception";
  }
  out << endl;

  indent_up();
  indent(out) << "include ::Thrift::Struct" << endl;

  if (is_exception) {
    generate_rb_simple_exception_constructor(out, tstruct);
  }

  generate_field_constants(out, tstruct);
  generate_field_defns(out, tstruct);
  generate_rb_struct_required_validator(out, tstruct);
  generate_accessors(out, tstruct);

  indent_down();
  indent(out) << "end" << endl << endl;
}

void t_rb_generator::generate_rb_simple_exception_constructor(
    std::ofstream& out, const t_struct* tstruct) {
  const vector<t_field*>& members = tstruct->get_members();

  if (members.size() == 1) {
    vector<t_field*>::const_iterator m_iter = members.begin();

    if ((*m_iter)->get_type()->is_string_or_binary()) {
      string name = (*m_iter)->get_name();

      indent(out) << "def initialize(message=nil)" << endl;
      indent_up();
      indent(out) << "super()" << endl;
      indent(out) << "self." << name << " = message" << endl;
      indent_down();
      indent(out) << "end" << endl << endl;

      if (name != "message") {
        indent(out) << "def message; " << name << " end" << endl << endl;
      }
    }
  }
}

void t_rb_generator::generate_field_constants(
    std::ofstream& out, const t_struct* tstruct) {
  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;

  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    std::string field_name = (*f_iter)->get_name();
    std::string cap_field_name = upcase_string(field_name);

    indent(out) << cap_field_name << " = " << (*f_iter)->get_key() << endl;
  }
  out << endl;
}

void t_rb_generator::generate_accessors(
    std::ofstream& out, const t_struct* tstruct) {
  const vector<t_field*>& members = tstruct->get_members();
  vector<t_field*>::const_iterator m_iter;

  if (members.size() > 0) {
    indent(out) << "::Thrift::Struct.field_accessor self";
    for (m_iter = members.begin(); m_iter != members.end(); ++m_iter) {
      out << ", :" << (*m_iter)->get_name();
    }
    out << endl;
  }
}

void t_rb_generator::generate_field_defns(
    std::ofstream& out, const t_struct* tstruct) {
  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;

  indent(out) << "FIELDS = {" << endl;
  indent_up();
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    if (f_iter != fields.begin()) {
      out << "," << endl;
    }

    // generate the field docstrings within the FIELDS constant. no real better
    // place...
    generate_rdoc(out, *f_iter);

    indent(out) << upcase_string((*f_iter)->get_name()) << " => ";

    generate_field_data(
        out,
        (*f_iter)->get_type(),
        (*f_iter)->get_name(),
        (*f_iter)->get_value(),
        (*f_iter)->get_req() == t_field::e_req::optional);
  }
  indent_down();
  out << endl;
  indent(out) << "}" << endl << endl;

  indent(out) << "def struct_fields; FIELDS; end" << endl << endl;
}

void t_rb_generator::generate_field_data(
    std::ofstream& out,
    const t_type* field_type,
    const std::string& field_name,
    const t_const_value* field_value,
    bool optional) {
  field_type = field_type->get_true_type();

  // Begin this field's defn
  out << "{:type => " << type_to_enum(field_type);

  if (!field_name.empty()) {
    out << ", :name => '" << field_name << "'";
  }

  if (field_value != nullptr) {
    out << ", :default => " << render_const_value(field_type, field_value);
  }

  if (!field_type->is_base_type()) {
    if (field_type->is_struct() || field_type->is_xception()) {
      out << ", :class => " << full_type_name((t_struct*)field_type);
    } else if (field_type->is_list()) {
      out << ", :element => ";
      generate_field_data(out, ((t_list*)field_type)->get_elem_type());
    } else if (field_type->is_map()) {
      out << ", :key => ";
      generate_field_data(out, ((t_map*)field_type)->get_key_type());
      out << ", :value => ";
      generate_field_data(out, ((t_map*)field_type)->get_val_type());
    } else if (field_type->is_set()) {
      out << ", :element => ";
      generate_field_data(out, ((t_set*)field_type)->get_elem_type());
    }
  }

  if (optional) {
    out << ", :optional => true";
  }

  if (field_type->is_enum()) {
    out << ", :enum_class => " << full_type_name(field_type);
  }

  // End of this field's defn
  out << "}";
}

void t_rb_generator::begin_namespace(
    std::ofstream& out, vector<std::string> modules) {
  for (vector<std::string>::iterator m_iter = modules.begin();
       m_iter != modules.end();
       ++m_iter) {
    indent(out) << "module " << *m_iter << endl;
    indent_up();
  }
}

void t_rb_generator::end_namespace(
    std::ofstream& out, vector<std::string> modules) {
  for (vector<std::string>::reverse_iterator m_iter = modules.rbegin();
       m_iter != modules.rend();
       ++m_iter) {
    indent_down();
    indent(out) << "end" << endl;
  }
}

/**
 * Generates a thrift service.
 *
 * @param tservice The service definition
 */
void t_rb_generator::generate_service(const t_service* tservice) {
  string f_service_name = get_out_dir() + underscore(service_name_) + ".rb";
  f_service_.open(f_service_name.c_str());
  record_genfile(f_service_name);

  f_service_ << rb_autogen_comment() << endl << "require 'thrift'" << endl;

  if (tservice->get_extends() != nullptr) {
    f_service_ << "require '" << underscore(tservice->get_extends()->get_name())
               << "'" << endl;
  }

  f_service_ << "require '" << underscore(program_name_) << "_types'" << endl
             << endl;

  begin_namespace(f_service_, ruby_modules(tservice->get_program()));

  indent(f_service_) << "module " << capitalize(tservice->get_name()) << endl;
  indent_up();

  // Generate the three main parts of the service (well, two for now in PHP)
  generate_service_client(tservice);
  generate_service_server(tservice);
  generate_service_helpers(tservice);

  indent_down();
  indent(f_service_) << "end" << endl << endl;

  end_namespace(f_service_, ruby_modules(tservice->get_program()));

  // Close service file
  f_service_.close();
}

/**
 * Generates helper functions for a service.
 *
 * @param tservice The service to generate a header definition for
 */
void t_rb_generator::generate_service_helpers(const t_service* tservice) {
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  indent(f_service_) << "# HELPER FUNCTIONS AND STRUCTURES" << endl << endl;

  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    const t_struct* ts = (*f_iter)->get_paramlist();
    generate_rb_struct(f_service_, ts);
    generate_rb_function_helpers(*f_iter);
  }
}

/**
 * Generates a struct and helpers for a function.
 *
 * @param tfunction The function
 */
void t_rb_generator::generate_rb_function_helpers(const t_function* tfunction) {
  t_struct result(program_, tfunction->get_name() + "_result");
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
  generate_rb_struct(f_service_, &result);
}

/**
 * Generates a service client definition.
 *
 * @param tservice The service to generate a server for.
 */
void t_rb_generator::generate_service_client(const t_service* tservice) {
  string extends = "";
  string extends_client = "";
  if (tservice->get_extends() != nullptr) {
    extends = full_type_name(tservice->get_extends());
    extends_client = " < " + extends + "::Client ";
  }

  indent(f_service_) << "class Client" << extends_client << endl;
  indent_up();

  indent(f_service_) << "include ::Thrift::Client" << endl << endl;

  // Generate client method implementations
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::const_iterator f_iter;
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    const t_struct* arg_struct = (*f_iter)->get_paramlist();
    const vector<t_field*>& fields = arg_struct->get_members();
    vector<t_field*>::const_iterator fld_iter;
    string funname = (*f_iter)->get_name();

    // Open function
    indent(f_service_) << "def " << function_signature(*f_iter) << endl;
    indent_up();
    indent(f_service_) << "send_" << funname << "(";

    bool first = true;
    for (fld_iter = fields.begin(); fld_iter != fields.end(); ++fld_iter) {
      if (first) {
        first = false;
      } else {
        f_service_ << ", ";
      }
      f_service_ << (*fld_iter)->get_name();
    }
    f_service_ << ")" << endl;

    if (!(*f_iter)->is_oneway()) {
      f_service_ << indent();
      if (!(*f_iter)->get_returntype()->is_void()) {
        f_service_ << "return ";
      }
      f_service_ << "recv_" << funname << "()" << endl;
    }
    indent_down();
    indent(f_service_) << "end" << endl;
    f_service_ << endl;

    indent(f_service_) << "def send_" << function_signature(*f_iter) << endl;
    indent_up();

    std::string argsname = capitalize((*f_iter)->get_name() + "_args");

    indent(f_service_) << "send_message('" << funname << "', " << argsname;

    for (fld_iter = fields.begin(); fld_iter != fields.end(); ++fld_iter) {
      f_service_ << ", :" << (*fld_iter)->get_name() << " => "
                 << (*fld_iter)->get_name();
    }

    f_service_ << ")" << endl;

    indent_down();
    indent(f_service_) << "end" << endl;

    if (!(*f_iter)->is_oneway()) {
      std::string resultname = capitalize((*f_iter)->get_name() + "_result");

      t_function recv_function(
          (*f_iter)->get_returntype(),
          string("recv_") + (*f_iter)->get_name(),
          std::make_unique<t_paramlist>(program_));
      // Open function
      f_service_ << endl
                 << indent() << "def " << function_signature(&recv_function)
                 << endl;
      indent_up();

      // TODO(mcslee): Validate message reply here, seq ids etc.

      f_service_ << indent() << "result = receive_message(" << resultname << ")"
                 << endl;

      // Careful, only return _result if not a void function
      if (!(*f_iter)->get_returntype()->is_void()) {
        f_service_ << indent()
                   << "return result.success unless result.success.nil?"
                   << endl;
      }

      const t_struct* xs = (*f_iter)->get_xceptions();
      const std::vector<t_field*>& xceptions = xs->get_members();
      vector<t_field*>::const_iterator x_iter;
      for (x_iter = xceptions.begin(); x_iter != xceptions.end(); ++x_iter) {
        indent(f_service_) << "raise result." << (*x_iter)->get_name()
                           << " unless result." << (*x_iter)->get_name()
                           << ".nil?" << endl;
      }

      // Careful, only return _result if not a void function
      if ((*f_iter)->get_returntype()->is_void()) {
        indent(f_service_) << "return" << endl;
      } else {
        f_service_
            << indent()
            << "raise ::Thrift::ApplicationException.new(::Thrift::ApplicationException::MISSING_RESULT, '"
            << (*f_iter)->get_name() << " failed: unknown result')" << endl;
      }

      // Close function
      indent_down();
      indent(f_service_) << "end" << endl << endl;
    }
  }

  indent_down();
  indent(f_service_) << "end" << endl << endl;
}

/**
 * Generates a service server definition.
 *
 * @param tservice The service to generate a server for.
 */
void t_rb_generator::generate_service_server(const t_service* tservice) {
  // Generate the dispatch methods
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  string extends = "";
  string extends_processor = "";
  if (tservice->get_extends() != nullptr) {
    extends = full_type_name(tservice->get_extends());
    extends_processor = " < " + extends + "::Processor ";
  }

  // Generate the header portion
  indent(f_service_) << "class Processor" << extends_processor << endl;
  indent_up();

  f_service_ << indent() << "include ::Thrift::Processor" << endl << endl;

  // Generate the process subfunctions
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    generate_process_function(tservice, *f_iter);
  }

  indent_down();
  indent(f_service_) << "end" << endl << endl;
}

/**
 * Generates a process function definition.
 *
 * @param tfunction The function to write a dispatcher for
 */
void t_rb_generator::generate_process_function(
    const t_service* /*tservice*/, const t_function* tfunction) {
  // Open function
  indent(f_service_) << "def process_" << tfunction->get_name()
                     << "(seqid, iprot, oprot)" << endl;
  indent_up();

  string argsname = capitalize(tfunction->get_name()) + "_args";
  string resultname = capitalize(tfunction->get_name()) + "_result";

  f_service_ << indent() << "args = read_args(iprot, " << argsname << ")"
             << endl;

  const t_struct* xs = tfunction->get_xceptions();
  const std::vector<t_field*>& xceptions = xs->get_members();
  vector<t_field*>::const_iterator x_iter;

  // Declare result for non oneway function
  if (!tfunction->is_oneway()) {
    f_service_ << indent() << "result = " << resultname << ".new()" << endl;
  }

  // Try block for a function with exceptions
  if (xceptions.size() > 0) {
    f_service_ << indent() << "begin" << endl;
    indent_up();
  }

  // Generate the function call
  const t_struct* arg_struct = tfunction->get_paramlist();
  const std::vector<t_field*>& fields = arg_struct->get_members();
  vector<t_field*>::const_iterator f_iter;

  f_service_ << indent();
  if (!tfunction->is_oneway() && !tfunction->get_returntype()->is_void()) {
    f_service_ << "result.success = ";
  }
  f_service_ << "@handler." << tfunction->get_name() << "(";
  bool first = true;
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    if (first) {
      first = false;
    } else {
      f_service_ << ", ";
    }
    f_service_ << "args." << (*f_iter)->get_name();
  }
  f_service_ << ")" << endl;

  if (!tfunction->is_oneway() && xceptions.size() > 0) {
    indent_down();
    for (x_iter = xceptions.begin(); x_iter != xceptions.end(); ++x_iter) {
      f_service_ << indent() << "rescue "
                 << full_type_name((*x_iter)->get_type()) << " => "
                 << (*x_iter)->get_name() << endl;
      if (!tfunction->is_oneway()) {
        indent_up();
        f_service_ << indent() << "result." << (*x_iter)->get_name() << " = "
                   << (*x_iter)->get_name() << endl;
        indent_down();
      }
    }
    indent(f_service_) << "end" << endl;
  }

  // Shortcut out here for oneway functions
  if (tfunction->is_oneway()) {
    f_service_ << indent() << "return" << endl;
    indent_down();
    indent(f_service_) << "end" << endl << endl;
    return;
  }

  f_service_ << indent() << "write_result(result, oprot, '"
             << tfunction->get_name() << "', seqid)" << endl;

  // Close function
  indent_down();
  indent(f_service_) << "end" << endl << endl;
}

/**
 * Renders a function signature of the form 'type name(args)'
 *
 * @param tfunction Function definition
 * @return String of rendered function definition
 */
string t_rb_generator::function_signature(
    const t_function* tfunction, string prefix) {
  // TODO(mcslee): Nitpicky, no ',' if argument_list is empty
  return prefix + tfunction->get_name() + "(" +
      argument_list(tfunction->get_paramlist()) + ")";
}

/**
 * Renders a field list
 */
string t_rb_generator::argument_list(const t_struct* tstruct) {
  string result = "";

  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;
  bool first = true;
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    if (first) {
      first = false;
    } else {
      result += ", ";
    }
    result += (*f_iter)->get_name();
  }
  return result;
}

string t_rb_generator::type_name(const t_type* ttype) {
  string prefix = "";

  string name = ttype->get_name();
  if (ttype->is_struct() || ttype->is_xception() || ttype->is_enum()) {
    name = capitalize(ttype->get_name());
  }

  return prefix + name;
}

string t_rb_generator::full_type_name(const t_type* ttype) {
  string prefix = "";
  vector<std::string> modules = ruby_modules(ttype->get_program());
  for (vector<std::string>::iterator m_iter = modules.begin();
       m_iter != modules.end();
       ++m_iter) {
    prefix += *m_iter + "::";
  }
  return prefix + type_name(ttype);
}

/**
 * Converts the parse type to a Ruby tyoe
 */
string t_rb_generator::type_to_enum(const t_type* type) {
  type = type->get_true_type();

  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_VOID:
        throw std::runtime_error("NO T_VOID CONSTRUCT");
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        return "::Thrift::Types::STRING";
      case t_base_type::TYPE_BOOL:
        return "::Thrift::Types::BOOL";
      case t_base_type::TYPE_BYTE:
        return "::Thrift::Types::BYTE";
      case t_base_type::TYPE_I16:
        return "::Thrift::Types::I16";
      case t_base_type::TYPE_I32:
        return "::Thrift::Types::I32";
      case t_base_type::TYPE_I64:
        return "::Thrift::Types::I64";
      case t_base_type::TYPE_DOUBLE:
        return "::Thrift::Types::DOUBLE";
      case t_base_type::TYPE_FLOAT:
        throw std::runtime_error("Float type is not supported");
    }
  } else if (type->is_enum()) {
    return "::Thrift::Types::I32";
  } else if (type->is_struct() || type->is_xception()) {
    return "::Thrift::Types::STRUCT";
  } else if (type->is_map()) {
    return "::Thrift::Types::MAP";
  } else if (type->is_set()) {
    return "::Thrift::Types::SET";
  } else if (type->is_list()) {
    return "::Thrift::Types::LIST";
  }

  throw std::runtime_error("INVALID TYPE IN type_to_enum: " + type->get_name());
}

void t_rb_generator::generate_rdoc(std::ofstream& out, const t_node* tdoc) {
  if (tdoc->has_doc()) {
    generate_docstring_comment(out, "", "# ", tdoc->get_doc(), "");
  }
}

void t_rb_generator::generate_rb_struct_required_validator(
    std::ofstream& out, const t_struct* tstruct) {
  indent(out) << "def validate" << endl;
  indent_up();

  const vector<t_field*>& fields = tstruct->get_members();
  vector<t_field*>::const_iterator f_iter;

  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    const t_field* field = (*f_iter);
    if (field->get_req() == t_field::e_req::required) {
      indent(out) << "raise ::Thrift::ProtocolException.new("
                  << "::Thrift::ProtocolException::MISSING_REQUIRED_FIELD, "
                  << "'Required field " << field->get_name() << " is unset!')";
      if (field->get_type()->is_bool()) {
        out << " if @" << field->get_name() << ".nil?";
      } else {
        out << " unless @" << field->get_name();
      }
      out << endl;
    }
  }

  // if field is an enum, check that its value is valid
  for (f_iter = fields.begin(); f_iter != fields.end(); ++f_iter) {
    const t_field* field = (*f_iter);

    if (field->get_type()->is_enum()) {
      indent(out) << "unless @" << field->get_name() << ".nil? || "
                  << full_type_name(field->get_type())
                  << "::VALID_VALUES.include?(@" << field->get_name() << ")"
                  << endl;
      indent_up();
      indent(out)
          << "raise ::Thrift::ProtocolException.new(::Thrift::ProtocolException::UNKNOWN, 'Invalid value of field "
          << field->get_name() << "!')" << endl;
      indent_down();
      indent(out) << "end" << endl;
    }
  }

  indent_down();
  indent(out) << "end" << endl << endl;
}

THRIFT_REGISTER_GENERATOR(rb, "Ruby", "");

} // namespace compiler
} // namespace thrift
} // namespace apache
