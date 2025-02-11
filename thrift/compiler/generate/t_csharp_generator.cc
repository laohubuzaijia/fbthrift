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

#include <stdlib.h>
#include <sstream>

#include <boost/filesystem.hpp>

#include <thrift/compiler/ast/base_types.h>
#include <thrift/compiler/generate/t_oop_generator.h>

using namespace std;

namespace apache {
namespace thrift {
namespace compiler {

class t_csharp_generator : public t_oop_generator {
 public:
  t_csharp_generator(
      t_program* program,
      t_generation_context context,
      const std::map<std::string, std::string>& /* parsed_options */,
      const std::string& /* option_string */)
      : t_oop_generator(program, std::move(context)) {
    out_dir_base_ = "gen-csharp";
  }
  void init_generator() override;
  void close_generator() override;

  void generate_consts(std::vector<t_const*> consts) override;

  void generate_typedef(const t_typedef* ttypedef) override;
  void generate_enum(const t_enum* tenum) override;
  void generate_struct(const t_struct* tstruct) override;
  void generate_xception(const t_struct* txception) override;
  void generate_service(const t_service* tservice) override;
  void generate_property(ofstream& out, const t_field* tfield, bool isPublic);
  bool print_const_value(
      std::ofstream& out,
      std::string name,
      const t_type* type,
      const t_const_value* value,
      bool in_static,
      bool defval = false,
      bool needtype = false);
  std::string render_const_value(
      std::ofstream& out,
      std::string name,
      const t_type* type,
      const t_const_value* value);
  void print_const_constructor(
      std::ofstream& out, std::vector<t_const*> consts);
  void print_const_def_value(
      std::ofstream& out,
      std::string name,
      const t_type* type,
      const t_const_value* value);

  void generate_csharp_struct(const t_struct* tstruct, bool is_exception);
  void generate_csharp_struct_definition(
      std::ofstream& out,
      const t_struct* tstruct,
      bool is_xception = false,
      bool in_class = false,
      bool is_result = false);
  void generate_csharp_struct_reader(
      std::ofstream& out, const t_struct* tstruct);
  void generate_csharp_struct_result_writer(
      std::ofstream& out, const t_struct* tstruct);
  void generate_csharp_struct_writer(
      std::ofstream& out, const t_struct* tstruct);
  void generate_csharp_struct_tostring(
      std::ofstream& out, const t_struct* tstruct);

  void generate_function_helpers(const t_function* tfunction);
  void generate_service_interface(const t_service* tservice);
  void generate_service_helpers(const t_service* tservice);
  void generate_service_client(const t_service* tservice);
  void generate_service_server(const t_service* tservice);
  void generate_process_function(
      const t_service* tservice, const t_function* function);

  void generate_deserialize_field(
      std::ofstream& out, const t_field* tfield, std::string prefix = "");
  void generate_deserialize_struct(
      std::ofstream& out, const t_struct* tstruct, std::string prefix = "");
  void generate_deserialize_container(
      std::ofstream& out, const t_type* ttype, std::string prefix = "");
  void generate_deserialize_set_element(
      std::ofstream& out, const t_set* tset, std::string prefix = "");
  void generate_deserialize_map_element(
      std::ofstream& out, const t_map* tmap, std::string prefix = "");
  void generate_deserialize_list_element(
      std::ofstream& out, const t_list* list, std::string prefix = "");
  void generate_serialize_field(
      std::ofstream& out, const t_field* tfield, std::string prefix = "");
  void generate_serialize_struct(
      std::ofstream& out, const t_struct* tstruct, std::string prefix = "");
  void generate_serialize_container(
      std::ofstream& out, const t_type* ttype, std::string prefix = "");
  void generate_serialize_map_element(
      std::ofstream& out, const t_map* tmap, std::string iter, std::string map);
  void generate_serialize_set_element(
      std::ofstream& out, const t_set* tmap, std::string iter);
  void generate_serialize_list_element(
      std::ofstream& out, const t_list* tlist, std::string iter);

  void start_csharp_namespace(std::ofstream& out);
  void end_csharp_namespace(std::ofstream& out);

  std::string csharp_type_usings();
  std::string csharp_thrift_usings();

  std::string type_name(
      const t_type* ttype, bool in_countainer = false, bool in_init = false);
  std::string base_type_name(t_base_type* tbase, bool in_container = false);
  std::string declare_field(const t_field* tfield, bool init = false);
  std::string function_signature(
      const t_function* tfunction, std::string prefix = "");
  std::string argument_list(const t_struct* tstruct);
  std::string type_to_enum(const t_type* ttype);
  std::string prop_name(const t_field* tfield);

  bool type_can_be_null(const t_type* ttype) {
    while (ttype->is_typedef()) {
      ttype = ((t_typedef*)ttype)->get_type();
    }

    return ttype->is_container() || ttype->is_struct() ||
        ttype->is_xception() || ttype->is_string_or_binary();
  }

 private:
  std::string namespace_name_;
  std::ofstream f_service_;
  std::string namespace_dir_;
};

void t_csharp_generator::init_generator() {
  boost::filesystem::create_directory(get_out_dir());
  namespace_name_ = program_->get_namespace("csharp");

  string dir = namespace_name_;
  string subdir = get_out_dir().c_str();
  string::size_type loc;

  while ((loc = dir.find('.')) != string::npos) {
    subdir = subdir + "/" + dir.substr(0, loc);
    boost::filesystem::create_directory(subdir);
    dir = dir.substr(loc + 1);
  }
  if (dir.size() > 0) {
    subdir = subdir + "/" + dir;
    boost::filesystem::create_directory(subdir);
  }

  namespace_dir_ = subdir;
}

void t_csharp_generator::start_csharp_namespace(ofstream& out) {
  if (!namespace_name_.empty()) {
    out << "namespace " << namespace_name_ << "\n";
    scope_up(out);
  }
}

void t_csharp_generator::end_csharp_namespace(ofstream& out) {
  if (!namespace_name_.empty()) {
    scope_down(out);
  }
}

string t_csharp_generator::csharp_type_usings() {
  return string() + "using System;\n" + "using System.Collections;\n" +
      "using System.Collections.Generic;\n" + "using System.Text;\n" +
      "using System.IO;\n" + "using Thrift;\n" + "using Thrift.Collections;\n";
}

string t_csharp_generator::csharp_thrift_usings() {
  return string() + "using Thrift.Protocol;\n" + "using Thrift.Transport;\n";
}

void t_csharp_generator::close_generator() {}
void t_csharp_generator::generate_typedef(const t_typedef* /* ttypedef */) {}

void t_csharp_generator::generate_enum(const t_enum* tenum) {
  string f_enum_name = namespace_dir_ + "/" + (tenum->get_name()) + ".cs";
  ofstream f_enum;
  f_enum.open(f_enum_name.c_str());
  record_genfile(f_enum_name);

  f_enum << autogen_comment() << endl;

  start_csharp_namespace(f_enum);

  indent(f_enum) << "public enum " << tenum->get_name() << "\n";
  scope_up(f_enum);

  vector<t_enum_value*> constants = tenum->get_enum_values();
  vector<t_enum_value*>::iterator c_iter;
  for (c_iter = constants.begin(); c_iter != constants.end(); ++c_iter) {
    int32_t value = (*c_iter)->get_value();

    indent(f_enum) << (*c_iter)->get_name() << " = " << value << "," << endl;
  }

  scope_down(f_enum);

  end_csharp_namespace(f_enum);

  f_enum.close();
}

void t_csharp_generator::generate_consts(std::vector<t_const*> consts) {
  if (consts.empty()) {
    return;
  }
  string f_consts_name = namespace_dir_ + "/Constants.cs";
  ofstream f_consts;
  f_consts.open(f_consts_name.c_str());
  record_genfile(f_consts_name);

  f_consts << autogen_comment() << csharp_type_usings() << endl;

  start_csharp_namespace(f_consts);

  indent(f_consts) << "public class Constants" << endl;
  scope_up(f_consts);

  vector<t_const*>::iterator c_iter;
  bool need_static_constructor = false;
  for (c_iter = consts.begin(); c_iter != consts.end(); ++c_iter) {
    if (print_const_value(
            f_consts,
            (*c_iter)->get_name(),
            (*c_iter)->get_type(),
            (*c_iter)->get_value(),
            false)) {
      need_static_constructor = true;
    }
  }

  if (need_static_constructor) {
    print_const_constructor(f_consts, consts);
  }

  scope_down(f_consts);
  end_csharp_namespace(f_consts);
  f_consts.close();
}

void t_csharp_generator::print_const_def_value(
    std::ofstream& out,
    string name,
    const t_type* type,
    const t_const_value* value) {
  if (type->is_struct() || type->is_xception()) {
    const auto* as_struct = static_cast<const t_struct*>(type);
    for (const auto& entry : value->get_map()) {
      const auto* field =
          as_struct->get_field_by_name(entry.first->get_string());
      if (field == nullptr) {
        throw std::runtime_error(
            "type error: " + type->get_name() + " has no field " +
            entry.first->get_string());
      }
      string val =
          render_const_value(out, name, field->get_type(), entry.second);
      indent(out) << name << "." << field->get_name() << " = " << val << ";"
                  << endl;
    }
  } else if (type->is_map()) {
    const t_type* ktype = ((t_map*)type)->get_key_type();
    const t_type* vtype = ((t_map*)type)->get_val_type();
    const vector<pair<t_const_value*, t_const_value*>>& val = value->get_map();
    vector<pair<t_const_value*, t_const_value*>>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      string key = render_const_value(out, name, ktype, v_iter->first);
      string val = render_const_value(out, name, vtype, v_iter->second);
      indent(out) << name << "[" << key << "]"
                  << " = " << val << ";" << endl;
    }
  } else if (type->is_list() || type->is_set()) {
    const t_type* etype;
    if (type->is_list()) {
      etype = ((t_list*)type)->get_elem_type();
    } else {
      etype = ((t_set*)type)->get_elem_type();
    }

    const vector<t_const_value*>& val = value->get_list();
    vector<t_const_value*>::const_iterator v_iter;
    for (v_iter = val.begin(); v_iter != val.end(); ++v_iter) {
      string val = render_const_value(out, name, etype, *v_iter);
      indent(out) << name << ".Add(" << val << ");" << endl;
    }
  }
}

void t_csharp_generator::print_const_constructor(
    std::ofstream& out, std::vector<t_const*> consts) {
  indent(out) << "static Constants()" << endl;
  scope_up(out);
  vector<t_const*>::iterator c_iter;
  for (c_iter = consts.begin(); c_iter != consts.end(); ++c_iter) {
    string name = (*c_iter)->get_name();
    const t_type* type = (*c_iter)->get_type();
    t_const_value* value = (*c_iter)->get_value();

    print_const_def_value(out, name, type, value);
  }
  scope_down(out);
}

// it seems like all that methods that call this are using in_static to be the
// opposite of what it would imply
bool t_csharp_generator::print_const_value(
    std::ofstream& out,
    string name,
    const t_type* type,
    const t_const_value* value,
    bool in_static,
    bool defval,
    bool needtype) {
  indent(out);
  bool need_static_construction = !in_static;
  if (!defval || needtype) {
    out << (in_static ? "" : "public static ") << type_name(type) << " ";
  }
  if (type->is_base_type()) {
    string v2 = render_const_value(out, name, type, value);
    out << name << " = " << v2 << ";" << endl;
    need_static_construction = false;
  } else if (type->is_enum()) {
    out << name << " = (" << type_name(type, false, true) << ")"
        << value->get_integer() << ";" << endl;
    need_static_construction = false;
  } else if (type->is_struct() || type->is_xception()) {
    out << name << " = new " << type_name(type) << "();" << endl;
  } else if (type->is_map()) {
    out << name << " = new " << type_name(type, true, true) << "();" << endl;
  } else if (type->is_list() || type->is_set()) {
    out << name << " = new " << type_name(type) << "();" << endl;
  }

  if (defval && !type->is_base_type() && !type->is_enum()) {
    print_const_def_value(out, name, type, value);
  }

  return need_static_construction;
}

std::string t_csharp_generator::render_const_value(
    ofstream& out,
    string /* unused */,
    const t_type* type,
    const t_const_value* value) {
  std::ostringstream render;

  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        render << "\"" + value->get_string() + "\"";
        break;
      case t_base_type::TYPE_BOOL:
        render << ((value->get_integer() > 0) ? "true" : "false");
        break;
      case t_base_type::TYPE_BYTE:
      case t_base_type::TYPE_I16:
      case t_base_type::TYPE_I32:
      case t_base_type::TYPE_I64:
        render << value->get_integer();
        break;
      case t_base_type::TYPE_DOUBLE:
        if (value->get_type() == t_const_value::CV_INTEGER) {
          render << value->get_integer();
        } else {
          render << value->get_double();
        }
        break;
      default:
        throw std::string("compiler error: no const of base type ") +
            t_base_type::t_base_name(tbase);
    }
  } else if (type->is_enum()) {
    render << "(" << type->get_name() << ")" << value->get_integer();
  } else {
    string t = tmp("tmp");
    print_const_value(out, t, type, value, true, true, true);
    render << t;
  }

  return render.str();
}

void t_csharp_generator::generate_struct(const t_struct* tstruct) {
  generate_csharp_struct(tstruct, false);
}

void t_csharp_generator::generate_xception(const t_struct* txception) {
  generate_csharp_struct(txception, true);
}

void t_csharp_generator::generate_csharp_struct(
    const t_struct* tstruct, bool is_exception) {
  string f_struct_name = namespace_dir_ + "/" + (tstruct->get_name()) + ".cs";
  ofstream f_struct;

  f_struct.open(f_struct_name.c_str());
  record_genfile(f_struct_name);

  f_struct << autogen_comment() << csharp_type_usings()
           << csharp_thrift_usings();

  generate_csharp_struct_definition(f_struct, tstruct, is_exception);

  f_struct.close();
}

void t_csharp_generator::generate_csharp_struct_definition(
    ofstream& out,
    const t_struct* tstruct,
    bool is_exception,
    bool in_class,
    bool is_result) {
  if (!in_class) {
    start_csharp_namespace(out);
  }

  out << endl;
  indent(out) << "[Serializable]" << endl;
  bool is_final = tstruct->has_annotation("final");
  indent(out) << "public " << (is_final ? "sealed " : "") << "partial class "
              << tstruct->get_name() << " : ";

  if (is_exception) {
    out << "Exception, ";
  }
  out << "TBase";

  out << endl;

  scope_up(out);

  // make private members with public Properties
  for (const auto* field : tstruct->fields()) {
    indent(out) << "private " << declare_field(field, false) << endl;
  }
  out << endl;

  for (const auto* field : tstruct->fields()) {
    generate_property(out, field, true);
  }

  if (tstruct->has_fields()) {
    out << endl
        << indent() << "public Isset __isset;" << endl
        << indent() << "[Serializable]" << endl
        << indent() << "public struct Isset {" << endl;
    indent_up();
    for (const auto* field : tstruct->fields()) {
      indent(out) << "public bool " << field->get_name() << ";" << endl;
    }

    indent_down();
    indent(out) << "}" << endl << endl;
  }

  indent(out) << "public " << tstruct->get_name() << "() {" << endl;
  indent_up();
  for (const auto* field : tstruct->fields()) {
    const t_type* t = field->get_type();
    while (t->is_typedef()) {
      t = ((t_typedef*)t)->get_type();
    }
    if (field->get_value() != nullptr) {
      print_const_value(
          out, "this." + field->get_name(), t, field->get_value(), true, true);
    }
  }

  indent_down();
  indent(out) << "}" << endl << endl;

  generate_csharp_struct_reader(out, tstruct);
  if (is_result) {
    generate_csharp_struct_result_writer(out, tstruct);
  } else {
    generate_csharp_struct_writer(out, tstruct);
  }
  generate_csharp_struct_tostring(out, tstruct);
  scope_down(out);
  out << endl;

  if (!in_class) {
    end_csharp_namespace(out);
  }
}

void t_csharp_generator::generate_csharp_struct_reader(
    ofstream& out, const t_struct* tstruct) {
  indent(out) << "public void Read (TProtocol iprot)" << endl;
  scope_up(out);

  indent(out) << "TField field;" << endl
              << indent() << "iprot.ReadStructBegin();" << endl;

  indent(out) << "while (true)" << endl;
  scope_up(out);

  indent(out) << "field = iprot.ReadFieldBegin();" << endl;

  indent(out) << "if (field.Type == TType.Stop) { " << endl;
  indent_up();
  indent(out) << "break;" << endl;
  indent_down();
  indent(out) << "}" << endl;

  indent(out) << "switch (field.ID)" << endl;

  scope_up(out);

  for (const auto* field : tstruct->fields()) {
    indent(out) << "case " << field->get_key() << ":" << endl;
    indent_up();
    indent(out) << "if (field.Type == " << type_to_enum(field->get_type())
                << ") {" << endl;
    indent_up();

    generate_deserialize_field(out, field, "this.");
    indent(out) << "this.__isset." << field->get_name() << " = true;" << endl;
    indent_down();
    out << indent() << "} else { " << endl
        << indent() << "  TProtocolUtil.Skip(iprot, field.Type);" << endl
        << indent() << "}" << endl
        << indent() << "break;" << endl;
    indent_down();
  }

  indent(out) << "default: " << endl;
  indent_up();
  indent(out) << "TProtocolUtil.Skip(iprot, field.Type);" << endl;
  indent(out) << "break;" << endl;
  indent_down();

  scope_down(out);

  indent(out) << "iprot.ReadFieldEnd();" << endl;

  scope_down(out);

  indent(out) << "iprot.ReadStructEnd();" << endl;

  indent_down();

  indent(out) << "}" << endl << endl;
}

void t_csharp_generator::generate_csharp_struct_writer(
    ofstream& out, const t_struct* tstruct) {
  out << indent() << "public void Write(TProtocol oprot) {" << endl;
  indent_up();

  const string& name = tstruct->get_name();
  indent(out) << "TStruct struc = new TStruct(\"" << name << "\");" << endl;
  indent(out) << "oprot.WriteStructBegin(struc);" << endl;

  if (tstruct->has_fields()) {
    indent(out) << "TField field = new TField();" << endl;
    for (const auto* field : tstruct->fields()) {
      bool null_allowed = type_can_be_null(field->get_type());
      if (null_allowed) {
        indent(out) << "if (this." << field->get_name()
                    << " != null && __isset." << field->get_name() << ") {"
                    << endl;
        indent_up();
      } else {
        indent(out) << "if (__isset." << field->get_name() << ") {" << endl;
        indent_up();
      }

      indent(out) << "field.Name = \"" << field->get_name() << "\";" << endl;
      indent(out) << "field.Type = " << type_to_enum(field->get_type()) << ";"
                  << endl;
      indent(out) << "field.ID = " << field->get_key() << ";" << endl;
      indent(out) << "oprot.WriteFieldBegin(field);" << endl;

      generate_serialize_field(out, field, "this.");

      indent(out) << "oprot.WriteFieldEnd();" << endl;

      indent_down();
      indent(out) << "}" << endl;
    }
  }

  indent(out) << "oprot.WriteFieldStop();" << endl;
  indent(out) << "oprot.WriteStructEnd();" << endl;

  indent_down();

  indent(out) << "}" << endl << endl;
}

void t_csharp_generator::generate_csharp_struct_result_writer(
    ofstream& out, const t_struct* tstruct) {
  indent(out) << "public void Write(TProtocol oprot) {" << endl;
  indent_up();

  const string& name = tstruct->get_name();
  indent(out) << "TStruct struc = new TStruct(\"" << name << "\");" << endl;
  indent(out) << "oprot.WriteStructBegin(struc);" << endl;

  if (tstruct->has_fields()) {
    indent(out) << "TField field = new TField();" << endl;
    bool first = true;
    for (const auto* field : tstruct->fields()) {
      if (first) {
        first = false;
        out << endl << indent() << "if ";
      } else {
        out << " else if ";
      }

      out << "(this.__isset." << field->get_name() << ") {" << endl;
      indent_up();

      bool null_allowed = type_can_be_null(field->get_type());
      if (null_allowed) {
        indent(out) << "if (this." << field->get_name() << " != null) {"
                    << endl;
        indent_up();
      }

      indent(out) << "field.Name = \"" << field->get_name() << "\";" << endl;
      indent(out) << "field.Type = " << type_to_enum(field->get_type()) << ";"
                  << endl;
      indent(out) << "field.ID = " << field->get_key() << ";" << endl;
      indent(out) << "oprot.WriteFieldBegin(field);" << endl;

      generate_serialize_field(out, field, "this.");

      indent(out) << "oprot.WriteFieldEnd();" << endl;

      if (null_allowed) {
        indent_down();
        indent(out) << "}" << endl;
      }

      indent_down();
      indent(out) << "}";
    }
  }

  out << endl
      << indent() << "oprot.WriteFieldStop();" << endl
      << indent() << "oprot.WriteStructEnd();" << endl;

  indent_down();

  indent(out) << "}" << endl << endl;
}

void t_csharp_generator::generate_csharp_struct_tostring(
    ofstream& out, const t_struct* tstruct) {
  indent(out) << "public override string ToString() {" << endl;
  indent_up();

  indent(out) << "StringBuilder sb = new StringBuilder(\""
              << tstruct->get_name() << "(\");" << endl;

  bool first = true;
  for (const auto* field : tstruct->fields()) {
    if (first) {
      first = false;
      indent(out) << "sb.Append(\"" << field->get_name() << ": \");" << endl;
    } else {
      indent(out) << "sb.Append(\"," << field->get_name() << ": \");" << endl;
    }
    const t_type* ttype = field->get_type();
    if (ttype->is_xception() || ttype->is_struct()) {
      indent(out) << "sb.Append(this." << field->get_name()
                  << "== null ? \"<null>\" : "
                  << "this." << field->get_name() << ".ToString());" << endl;
    } else {
      indent(out) << "sb.Append(this." << field->get_name() << ");" << endl;
    }
  }

  indent(out) << "sb.Append(\")\");" << endl;
  indent(out) << "return sb.ToString();" << endl;

  indent_down();
  indent(out) << "}" << endl << endl;
}

void t_csharp_generator::generate_service(const t_service* tservice) {
  string f_service_name = namespace_dir_ + "/" + service_name_ + ".cs";
  f_service_.open(f_service_name.c_str());
  record_genfile(f_service_name);

  f_service_ << autogen_comment() << csharp_type_usings()
             << csharp_thrift_usings();

  start_csharp_namespace(f_service_);

  indent(f_service_) << "public class " << service_name_ << " {" << endl;
  indent_up();

  generate_service_interface(tservice);
  generate_service_client(tservice);
  generate_service_server(tservice);
  generate_service_helpers(tservice);

  indent_down();

  indent(f_service_) << "}" << endl;
  end_csharp_namespace(f_service_);
  f_service_.close();
}

void t_csharp_generator::generate_service_interface(const t_service* tservice) {
  string extends = "";
  string extends_iface = "";
  if (tservice->get_extends() != nullptr) {
    extends = type_name(tservice->get_extends());
    extends_iface = " : " + extends + ".Iface";
  }

  indent(f_service_) << "public interface Iface" << extends_iface << " {"
                     << endl;
  indent_up();
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;
  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    indent(f_service_) << function_signature(*f_iter) << ";" << endl;
  }
  indent_down();
  f_service_ << indent() << "}" << endl << endl;
}

void t_csharp_generator::generate_service_helpers(const t_service* tservice) {
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    const t_struct* ts = (*f_iter)->get_paramlist();
    generate_csharp_struct_definition(f_service_, ts, false, true);
    generate_function_helpers(*f_iter);
  }
}

void t_csharp_generator::generate_service_client(const t_service* tservice) {
  string extends = "";
  string extends_client = "";
  if (tservice->get_extends() != nullptr) {
    extends = type_name(tservice->get_extends());
    extends_client = extends + ".Client, ";
  }

  indent(f_service_) << "public class Client : " << extends_client << "Iface {"
                     << endl;
  indent_up();
  indent(f_service_) << "public Client(TProtocol prot) : this(prot, prot)"
                     << endl;
  scope_up(f_service_);
  scope_down(f_service_);
  f_service_ << endl;

  indent(f_service_) << "public Client(TProtocol iprot, TProtocol oprot)";
  if (!extends.empty()) {
    f_service_ << " : base(iprot, oprot)";
  }
  f_service_ << endl;

  scope_up(f_service_);
  if (extends.empty()) {
    f_service_ << indent() << "iprot_ = iprot;" << endl
               << indent() << "oprot_ = oprot;" << endl;
  }
  scope_down(f_service_);

  f_service_ << endl;

  if (extends.empty()) {
    f_service_ << indent() << "protected TProtocol iprot_;" << endl
               << indent() << "protected TProtocol oprot_;" << endl
               << indent() << "protected int seqid_;" << endl
               << endl;

    f_service_ << indent() << "public TProtocol InputProtocol" << endl;
    scope_up(f_service_);
    indent(f_service_) << "get { return iprot_; }" << endl;
    scope_down(f_service_);

    f_service_ << indent() << "public TProtocol OutputProtocol" << endl;
    scope_up(f_service_);
    indent(f_service_) << "get { return oprot_; }" << endl;
    scope_down(f_service_);
    f_service_ << endl << endl;
  }

  for (const auto* function : tservice->get_functions()) {
    indent(f_service_) << "public " << function_signature(function) << endl;
    scope_up(f_service_);
    indent(f_service_) << "send_" << function->get_name() << "(";

    bool first = true;
    for (const auto* field : function->get_paramlist()->fields()) {
      if (first) {
        first = false;
      } else {
        f_service_ << ", ";
      }
      f_service_ << field->get_name();
    }
    f_service_ << ");" << endl;

    if (!function->is_oneway()) {
      f_service_ << indent();
      if (!function->get_returntype()->is_void()) {
        f_service_ << "return ";
      }
      f_service_ << "recv_" << function->get_name() << "();" << endl;
    }
    scope_down(f_service_);
    f_service_ << endl;

    t_function send_function(
        void_type(),
        string("send_") + function->get_name(),
        t_struct::clone_DO_NOT_USE(function->get_paramlist()));

    string argsname = function->get_name() + "_args";

    indent(f_service_) << "public " << function_signature(&send_function)
                       << endl;
    scope_up(f_service_);

    f_service_ << indent() << "oprot_.WriteMessageBegin(new TMessage(\""
               << function->get_name() << "\", TMessageType.Call, seqid_));"
               << endl
               << indent() << argsname << " args = new " << argsname << "();"
               << endl;

    for (const auto* field : function->get_paramlist()->fields()) {
      f_service_ << indent() << "args." << prop_name(field) << " = "
                 << field->get_name() << ";" << endl;
    }

    f_service_ << indent() << "args.Write(oprot_);" << endl
               << indent() << "oprot_.WriteMessageEnd();" << endl
               << indent() << "oprot_.Transport.Flush();" << endl;

    scope_down(f_service_);
    f_service_ << endl;

    if (!function->is_oneway()) {
      string resultname = function->get_name() + "_result";

      t_function recv_function(
          function->get_returntype(),
          string("recv_") + function->get_name(),
          std::make_unique<t_paramlist>(program_),
          t_struct::clone_DO_NOT_USE(function->get_xceptions()),
          nullptr);
      indent(f_service_) << "public " << function_signature(&recv_function)
                         << endl;
      scope_up(f_service_);

      f_service_ << indent() << "TMessage msg = iprot_.ReadMessageBegin();"
                 << endl
                 << indent() << "if (msg.Type == TMessageType.Exception) {"
                 << endl;
      indent_up();
      f_service_
          << indent()
          << "TApplicationException x = TApplicationException.Read(iprot_);"
          << endl
          << indent() << "iprot_.ReadMessageEnd();" << endl
          << indent() << "throw x;" << endl;
      indent_down();
      f_service_ << indent() << "}" << endl
                 << indent() << resultname << " result = new " << resultname
                 << "();" << endl
                 << indent() << "result.Read(iprot_);" << endl
                 << indent() << "iprot_.ReadMessageEnd();" << endl;

      if (!function->get_returntype()->is_void()) {
        f_service_ << indent() << "if (result.__isset.success) {" << endl
                   << indent() << "  return result.Success;" << endl
                   << indent() << "}" << endl;
      }

      for (const auto* x : function->get_xceptions()->fields()) {
        f_service_ << indent() << "if (result.__isset." << x->get_name()
                   << ") {" << endl
                   << indent() << "  throw result." << prop_name(x) << ";"
                   << endl
                   << indent() << "}" << endl;
      }

      if (function->get_returntype()->is_void()) {
        indent(f_service_) << "return;" << endl;
      } else {
        f_service_
            << indent()
            << "throw new TApplicationException(TApplicationException.ExceptionType.MissingResult, \""
            << function->get_name() << " failed: unknown result\");" << endl;
      }

      scope_down(f_service_);
      f_service_ << endl;
    }
  }

  indent_down();
  indent(f_service_) << "}" << endl;
}

void t_csharp_generator::generate_service_server(const t_service* tservice) {
  vector<t_function*> functions = tservice->get_functions();
  vector<t_function*>::iterator f_iter;

  string extends = "";
  string extends_processor = "";
  if (tservice->get_extends() != nullptr) {
    extends = type_name(tservice->get_extends());
    extends_processor = extends + ".Processor, ";
  }

  indent(f_service_) << "public class Processor : " << extends_processor
                     << "TProcessor {" << endl;
  indent_up();

  indent(f_service_) << "public Processor(Iface iface)";
  if (!extends.empty()) {
    f_service_ << " : base(iface)";
  }
  f_service_ << endl;
  scope_up(f_service_);
  f_service_ << indent() << "iface_ = iface;" << endl;

  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    f_service_ << indent() << "processMap_[\"" << (*f_iter)->get_name()
               << "\"] = " << (*f_iter)->get_name() << "_Process;" << endl;
  }

  scope_down(f_service_);
  f_service_ << endl;

  if (extends.empty()) {
    f_service_
        << indent()
        << "protected delegate void ProcessFunction(int seqid, TProtocol iprot, TProtocol oprot);"
        << endl;
  }

  f_service_ << indent() << "private Iface iface_;" << endl;

  if (extends.empty()) {
    f_service_
        << indent()
        << "protected Dictionary<string, ProcessFunction> processMap_ = new Dictionary<string, ProcessFunction>();"
        << endl;
  }

  f_service_ << endl;

  if (extends.empty()) {
    indent(f_service_)
        << "public bool Process(TProtocol iprot, TProtocol oprot)" << endl;
  } else {
    indent(f_service_)
        << "public new bool Process(TProtocol iprot, TProtocol oprot)" << endl;
  }
  scope_up(f_service_);

  f_service_ << indent() << "try" << endl;
  scope_up(f_service_);

  f_service_ << indent() << "TMessage msg = iprot.ReadMessageBegin();" << endl;

  f_service_
      << indent() << "ProcessFunction fn;" << endl
      << indent() << "processMap_.TryGetValue(msg.Name, out fn);" << endl
      << indent() << "if (fn == null) {" << endl
      << indent() << "  TProtocolUtil.Skip(iprot, TType.Struct);" << endl
      << indent() << "  iprot.ReadMessageEnd();" << endl
      << indent()
      << "  TApplicationException x = new TApplicationException (TApplicationException.ExceptionType.UnknownMethod, \"Invalid method name: '\" + msg.Name + \"'\");"
      << endl
      << indent()
      << "  oprot.WriteMessageBegin(new TMessage(msg.Name, TMessageType.Exception, msg.SeqID));"
      << endl
      << indent() << "  x.Write(oprot);" << endl
      << indent() << "  oprot.WriteMessageEnd();" << endl
      << indent() << "  oprot.Transport.Flush();" << endl
      << indent() << "  return true;" << endl
      << indent() << "}" << endl
      << indent() << "fn(msg.SeqID, iprot, oprot);" << endl;

  scope_down(f_service_);

  f_service_ << indent() << "catch (IOException)" << endl;
  scope_up(f_service_);
  f_service_ << indent() << "return false;" << endl;
  scope_down(f_service_);

  f_service_ << indent() << "return true;" << endl;

  scope_down(f_service_);
  f_service_ << endl;

  for (f_iter = functions.begin(); f_iter != functions.end(); ++f_iter) {
    generate_process_function(tservice, *f_iter);
  }

  indent_down();
  indent(f_service_) << "}" << endl << endl;
}

void t_csharp_generator::generate_function_helpers(
    const t_function* tfunction) {
  if (tfunction->is_oneway()) {
    return;
  }

  t_struct result(program_, tfunction->get_name() + "_result");
  auto success =
      std::make_unique<t_field>(tfunction->get_returntype(), "success", 0);
  if (!tfunction->get_returntype()->is_void()) {
    result.append(std::move(success));
  }

  for (const auto* x : tfunction->get_xceptions()->fields()) {
    result.append(x->clone_DO_NOT_USE());
  }

  generate_csharp_struct_definition(f_service_, &result, false, true, true);
}

void t_csharp_generator::generate_process_function(
    const t_service* /* tservice */, const t_function* tfunction) {
  indent(f_service_) << "public void " << tfunction->get_name()
                     << "_Process(int seqid, TProtocol iprot, TProtocol oprot)"
                     << endl;
  scope_up(f_service_);

  string argsname = tfunction->get_name() + "_args";
  string resultname = tfunction->get_name() + "_result";

  f_service_ << indent() << argsname << " args = new " << argsname << "();"
             << endl
             << indent() << "args.Read(iprot);" << endl
             << indent() << "iprot.ReadMessageEnd();" << endl;

  if (!tfunction->is_oneway()) {
    f_service_ << indent() << resultname << " result = new " << resultname
               << "();" << endl;
  }

  const t_struct* xs = tfunction->get_xceptions();
  if (!xs->fields().empty()) {
    f_service_ << indent() << "try {" << endl;
    indent_up();
  }

  t_struct* arg_struct = tfunction->get_paramlist();
  f_service_ << indent();
  if (!tfunction->is_oneway() && !tfunction->get_returntype()->is_void()) {
    f_service_ << "result.Success = ";
  }
  f_service_ << "iface_." << tfunction->get_name() << "(";
  const char* delim = "";
  for (const auto* field : arg_struct->fields()) {
    f_service_ << delim << "args." << prop_name(field);
    delim = ", ";
  }
  f_service_ << ");" << endl;

  if (!tfunction->is_oneway() && !xs->fields().empty()) {
    indent_down();
    f_service_ << indent() << "}";
    for (const auto* x : xs->fields()) {
      f_service_ << " catch (" << type_name(x->get_type(), false, false) << " "
                 << x->get_name() << ") {" << endl;
      if (!tfunction->is_oneway()) {
        indent_up();
        f_service_ << indent() << "result." << prop_name(x) << " = "
                   << x->get_name() << ";" << endl;
        indent_down();
        f_service_ << indent() << "}";
      } else {
        f_service_ << "}";
      }
    }
    f_service_ << endl;
  }

  if (tfunction->is_oneway()) {
    f_service_ << indent() << "return;" << endl;
    scope_down(f_service_);

    return;
  }

  f_service_ << indent() << "oprot.WriteMessageBegin(new TMessage(\""
             << tfunction->get_name() << "\", TMessageType.Reply, seqid)); "
             << endl
             << indent() << "result.Write(oprot);" << endl
             << indent() << "oprot.WriteMessageEnd();" << endl
             << indent() << "oprot.Transport.Flush();" << endl;

  scope_down(f_service_);

  f_service_ << endl;
}

void t_csharp_generator::generate_deserialize_field(
    ofstream& out, const t_field* tfield, string prefix) {
  const t_type* type = tfield->get_type();
  while (type->is_typedef()) {
    type = ((t_typedef*)type)->get_type();
  }

  if (type->is_void()) {
    throw std::runtime_error(
        "CANNOT GENERATE DESERIALIZE CODE FOR void TYPE: " + prefix +
        tfield->get_name());
  }

  string name = prefix + tfield->get_name();

  if (type->is_struct() || type->is_xception()) {
    generate_deserialize_struct(out, (t_struct*)type, name);
  } else if (type->is_container()) {
    generate_deserialize_container(out, type, name);
  } else if (type->is_base_type() || type->is_enum()) {
    indent(out) << name << " = ";

    if (type->is_enum()) {
      out << "(" << type_name(type, false, true) << ")";
    }

    out << "iprot.";

    if (type->is_base_type()) {
      t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
      switch (tbase) {
        case t_base_type::TYPE_VOID:
          throw std::runtime_error(
              "compiler error: cannot serialize void field in a struct: " +
              name);
        case t_base_type::TYPE_STRING:
          out << "ReadString();";
          break;
        case t_base_type::TYPE_BINARY:
          out << "ReadBinary();";
          break;
        case t_base_type::TYPE_BOOL:
          out << "ReadBool();";
          break;
        case t_base_type::TYPE_BYTE:
          out << "ReadByte();";
          break;
        case t_base_type::TYPE_I16:
          out << "ReadI16();";
          break;
        case t_base_type::TYPE_I32:
          out << "ReadI32();";
          break;
        case t_base_type::TYPE_I64:
          out << "ReadI64();";
          break;
        case t_base_type::TYPE_DOUBLE:
          out << "ReadDouble();";
          break;
        default:
          throw std::string("compiler error: no C# name for base type ") +
              t_base_type::t_base_name(tbase);
      }
    } else if (type->is_enum()) {
      out << "ReadI32();";
    }
    out << endl;
  } else {
    printf(
        "DO NOT KNOW HOW TO DESERIALIZE FIELD '%s' TYPE '%s'\n",
        tfield->get_name().c_str(),
        type_name(type).c_str());
  }
}

void t_csharp_generator::generate_deserialize_struct(
    ofstream& out, const t_struct* tstruct, string prefix) {
  out << indent() << prefix << " = new " << type_name(tstruct) << "();" << endl
      << indent() << prefix << ".Read(iprot);" << endl;
}

void t_csharp_generator::generate_deserialize_container(
    ofstream& out, const t_type* ttype, string prefix) {
  scope_up(out);

  string obj;

  if (ttype->is_map()) {
    obj = tmp("_map");
  } else if (ttype->is_set()) {
    obj = tmp("_set");
  } else if (ttype->is_list()) {
    obj = tmp("_list");
  }

  indent(out) << prefix << " = new " << type_name(ttype, false, true) << "();"
              << endl;
  if (ttype->is_map()) {
    out << indent() << "TMap " << obj << " = iprot.ReadMapBegin();" << endl;
  } else if (ttype->is_set()) {
    out << indent() << "TSet " << obj << " = iprot.ReadSetBegin();" << endl;
  } else if (ttype->is_list()) {
    out << indent() << "TList " << obj << " = iprot.ReadListBegin();" << endl;
  }

  string i = tmp("_i");
  indent(out) << "for( int " << i << " = 0; " << i << " < " << obj << ".Count"
              << "; "
              << "++" << i << ")" << endl;
  scope_up(out);

  if (ttype->is_map()) {
    generate_deserialize_map_element(out, (t_map*)ttype, prefix);
  } else if (ttype->is_set()) {
    generate_deserialize_set_element(out, (t_set*)ttype, prefix);
  } else if (ttype->is_list()) {
    generate_deserialize_list_element(out, (t_list*)ttype, prefix);
  }

  scope_down(out);

  if (ttype->is_map()) {
    indent(out) << "iprot.ReadMapEnd();" << endl;
  } else if (ttype->is_set()) {
    indent(out) << "iprot.ReadSetEnd();" << endl;
  } else if (ttype->is_list()) {
    indent(out) << "iprot.ReadListEnd();" << endl;
  }

  scope_down(out);
}

void t_csharp_generator::generate_deserialize_map_element(
    ofstream& out, const t_map* tmap, string prefix) {
  string key = tmp("_key");
  string val = tmp("_val");

  t_field fkey(tmap->get_key_type(), key);
  t_field fval(tmap->get_val_type(), val);

  indent(out) << declare_field(&fkey) << endl;
  indent(out) << declare_field(&fval) << endl;

  generate_deserialize_field(out, &fkey);
  generate_deserialize_field(out, &fval);

  indent(out) << prefix << "[" << key << "] = " << val << ";" << endl;
}

void t_csharp_generator::generate_deserialize_set_element(
    ofstream& out, const t_set* tset, string prefix) {
  string elem = tmp("_elem");
  t_field felem(tset->get_elem_type(), elem);

  indent(out) << declare_field(&felem, true) << endl;

  generate_deserialize_field(out, &felem);

  indent(out) << prefix << ".Add(" << elem << ");" << endl;
}

void t_csharp_generator::generate_deserialize_list_element(
    ofstream& out, const t_list* tlist, string prefix) {
  string elem = tmp("_elem");
  t_field felem(tlist->get_elem_type(), elem);

  indent(out) << declare_field(&felem, true) << endl;

  generate_deserialize_field(out, &felem);

  indent(out) << prefix << ".Add(" << elem << ");" << endl;
}

void t_csharp_generator::generate_serialize_field(
    ofstream& out, const t_field* tfield, string prefix) {
  const t_type* type = tfield->get_type();
  while (type->is_typedef()) {
    type = ((t_typedef*)type)->get_type();
  }

  if (type->is_void()) {
    throw std::runtime_error(
        "CANNOT GENERATE SERIALIZE CODE FOR void TYPE: " + prefix +
        tfield->get_name());
  }

  if (type->is_struct() || type->is_xception()) {
    generate_serialize_struct(
        out, (t_struct*)type, prefix + tfield->get_name());
  } else if (type->is_container()) {
    generate_serialize_container(out, type, prefix + tfield->get_name());
  } else if (type->is_base_type() || type->is_enum()) {
    string name = prefix + tfield->get_name();
    indent(out) << "oprot.";

    if (type->is_base_type()) {
      t_base_type::t_base tbase = ((t_base_type*)type)->get_base();

      switch (tbase) {
        case t_base_type::TYPE_VOID:
          throw std::runtime_error(
              "compiler error: cannot serialize void field in a struct: " +
              name);
        case t_base_type::TYPE_STRING:
          out << "WriteString(";
          out << name << ");";
          break;
        case t_base_type::TYPE_BINARY:
          out << "WriteBinary(";
          out << name << ");";
          break;
        case t_base_type::TYPE_BOOL:
          out << "WriteBool(" << name << ");";
          break;
        case t_base_type::TYPE_BYTE:
          out << "WriteByte(" << name << ");";
          break;
        case t_base_type::TYPE_I16:
          out << "WriteI16(" << name << ");";
          break;
        case t_base_type::TYPE_I32:
          out << "WriteI32(" << name << ");";
          break;
        case t_base_type::TYPE_I64:
          out << "WriteI64(" << name << ");";
          break;
        case t_base_type::TYPE_DOUBLE:
          out << "WriteDouble(" << name << ");";
          break;
        default:
          throw std::string("compiler error: no C# name for base type ") +
              t_base_type::t_base_name(tbase);
      }
    } else if (type->is_enum()) {
      out << "WriteI32((int)" << name << ");";
    }
    out << endl;
  } else {
    printf(
        "DO NOT KNOW HOW TO SERIALIZE '%s%s' TYPE '%s'\n",
        prefix.c_str(),
        tfield->get_name().c_str(),
        type_name(type).c_str());
  }
}

void t_csharp_generator::generate_serialize_struct(
    ofstream& out, const t_struct* /* tstruct */, string prefix) {
  out << indent() << prefix << ".Write(oprot);" << endl;
}

void t_csharp_generator::generate_serialize_container(
    ofstream& out, const t_type* ttype, string prefix) {
  scope_up(out);

  if (ttype->is_map()) {
    indent(out) << "oprot.WriteMapBegin(new TMap("
                << type_to_enum(((t_map*)ttype)->get_key_type()) << ", "
                << type_to_enum(((t_map*)ttype)->get_val_type()) << ", "
                << prefix << ".Count));" << endl;
  } else if (ttype->is_set()) {
    indent(out) << "oprot.WriteSetBegin(new TSet("
                << type_to_enum(((t_set*)ttype)->get_elem_type()) << ", "
                << prefix << ".Count));" << endl;
  } else if (ttype->is_list()) {
    indent(out) << "oprot.WriteListBegin(new TList("
                << type_to_enum(((t_list*)ttype)->get_elem_type()) << ", "
                << prefix << ".Count));" << endl;
  }

  string iter = tmp("_iter");
  if (ttype->is_map()) {
    indent(out) << "foreach (" << type_name(((t_map*)ttype)->get_key_type())
                << " " << iter << " in " << prefix << ".Keys)";
  } else if (ttype->is_set()) {
    indent(out) << "foreach (" << type_name(((t_set*)ttype)->get_elem_type())
                << " " << iter << " in " << prefix << ")";
  } else if (ttype->is_list()) {
    indent(out) << "foreach (" << type_name(((t_list*)ttype)->get_elem_type())
                << " " << iter << " in " << prefix << ")";
  }

  out << endl;
  scope_up(out);

  if (ttype->is_map()) {
    generate_serialize_map_element(out, (t_map*)ttype, iter, prefix);
  } else if (ttype->is_set()) {
    generate_serialize_set_element(out, (t_set*)ttype, iter);
  } else if (ttype->is_list()) {
    generate_serialize_list_element(out, (t_list*)ttype, iter);
  }

  if (ttype->is_map()) {
    indent(out) << "oprot.WriteMapEnd();" << endl;
  } else if (ttype->is_set()) {
    indent(out) << "oprot.WriteSetEnd();" << endl;
  } else if (ttype->is_list()) {
    indent(out) << "oprot.WriteListEnd();" << endl;
  }

  scope_down(out);
  scope_down(out);
}

void t_csharp_generator::generate_serialize_map_element(
    ofstream& out, const t_map* tmap, string iter, string map) {
  t_field kfield(tmap->get_key_type(), iter);
  generate_serialize_field(out, &kfield, "");
  t_field vfield(tmap->get_val_type(), map + "[" + iter + "]");
  generate_serialize_field(out, &vfield, "");
}

void t_csharp_generator::generate_serialize_set_element(
    ofstream& out, const t_set* tset, string iter) {
  t_field efield(tset->get_elem_type(), iter);
  generate_serialize_field(out, &efield, "");
}

void t_csharp_generator::generate_serialize_list_element(
    ofstream& out, const t_list* tlist, string iter) {
  t_field efield(tlist->get_elem_type(), iter);
  generate_serialize_field(out, &efield, "");
}

void t_csharp_generator::generate_property(
    ofstream& out, const t_field* tfield, bool isPublic) {
  indent(out) << (isPublic ? "public " : "private ")
              << type_name(tfield->get_type()) << " " << prop_name(tfield)
              << endl;
  scope_up(out);
  indent(out) << "get" << endl;
  scope_up(out);
  indent(out) << "return " << tfield->get_name() << ";" << endl;
  scope_down(out);
  indent(out) << "set" << endl;
  scope_up(out);
  indent(out) << "__isset." << tfield->get_name() << " = true;" << endl;
  indent(out) << "this." << tfield->get_name() << " = value;" << endl;
  scope_down(out);
  scope_down(out);
  out << endl;
}

std::string t_csharp_generator::prop_name(const t_field* tfield) {
  string name(tfield->get_name());
  name[0] = toupper(name[0]);
  return name;
}

string t_csharp_generator::type_name(
    const t_type* ttype, bool in_container, bool /* in_init */) {
  while (ttype->is_typedef()) {
    ttype = ((t_typedef*)ttype)->get_type();
  }

  if (ttype->is_base_type()) {
    return base_type_name((t_base_type*)ttype, in_container);
  } else if (ttype->is_map()) {
    const t_map* tmap = (t_map*)ttype;
    return "Dictionary<" + type_name(tmap->get_key_type(), true) + ", " +
        type_name(tmap->get_val_type(), true) + ">";
  } else if (ttype->is_set()) {
    const t_set* tset = (t_set*)ttype;
    return "THashSet<" + type_name(tset->get_elem_type(), true) + ">";
  } else if (ttype->is_list()) {
    const t_list* tlist = (t_list*)ttype;
    return "List<" + type_name(tlist->get_elem_type(), true) + ">";
  }

  const t_program* program = ttype->get_program();
  if (program != nullptr && program != program_) {
    string ns = program->get_namespace("csharp");
    if (!ns.empty()) {
      return ns + "." + ttype->get_name();
    }
  }

  return ttype->get_name();
}

string t_csharp_generator::base_type_name(
    t_base_type* tbase, bool /* in_container */) {
  switch (tbase->get_base()) {
    case t_base_type::TYPE_VOID:
      return "void";
    case t_base_type::TYPE_STRING:
      return "string";
    case t_base_type::TYPE_BINARY:
      return "byte[]";
    case t_base_type::TYPE_BOOL:
      return "bool";
    case t_base_type::TYPE_BYTE:
      return "byte";
    case t_base_type::TYPE_I16:
      return "short";
    case t_base_type::TYPE_I32:
      return "int";
    case t_base_type::TYPE_I64:
      return "long";
    case t_base_type::TYPE_FLOAT:
      return "float";
    case t_base_type::TYPE_DOUBLE:
      return "double";
    default:
      throw std::string("compiler error: no C# name for base type ") +
          t_base_type::t_base_name(tbase->get_base());
  }
}

string t_csharp_generator::declare_field(const t_field* tfield, bool init) {
  string result = type_name(tfield->get_type()) + " " + tfield->get_name();
  if (init) {
    const t_type* ttype = tfield->get_type();
    while (ttype->is_typedef()) {
      ttype = ((t_typedef*)ttype)->get_type();
    }
    if (ttype->is_base_type() && tfield->get_value() != nullptr) {
      ofstream dummy;
      result += " = " +
          render_const_value(
                    dummy, tfield->get_name(), ttype, tfield->get_value());
    } else if (ttype->is_base_type()) {
      t_base_type::t_base tbase = ((t_base_type*)ttype)->get_base();
      switch (tbase) {
        case t_base_type::TYPE_VOID:
          throw std::runtime_error("NO T_VOID CONSTRUCT");
        case t_base_type::TYPE_STRING:
        case t_base_type::TYPE_BINARY:
          result += " = null";
          break;
        case t_base_type::TYPE_BOOL:
          result += " = false";
          break;
        case t_base_type::TYPE_BYTE:
        case t_base_type::TYPE_I16:
        case t_base_type::TYPE_I32:
        case t_base_type::TYPE_I64:
          result += " = 0";
          break;
        case t_base_type::TYPE_FLOAT:
          result += " = (float)0";
          break;
        case t_base_type::TYPE_DOUBLE:
          result += " = (double)0";
          break;
      }
    } else if (ttype->is_enum()) {
      result += " = (" + type_name(ttype, false, true) + ")0";
    } else if (ttype->is_container()) {
      result += " = new " + type_name(ttype, false, true) + "()";
    } else {
      result += " = new " + type_name(ttype, false, true) + "()";
    }
  }
  return result + ";";
}

string t_csharp_generator::function_signature(
    const t_function* tfunction, string prefix) {
  const t_type* ttype = tfunction->get_returntype();
  return type_name(ttype) + " " + prefix + tfunction->get_name() + "(" +
      argument_list(tfunction->get_paramlist()) + ")";
}

string t_csharp_generator::argument_list(const t_struct* tstruct) {
  string result = "";
  auto delim = "";
  for (const auto* param : tstruct->fields()) {
    result += delim;
    result += type_name(param->get_type());
    result += " ";
    result += param->get_name();
    delim = ", ";
  }
  return result;
}

string t_csharp_generator::type_to_enum(const t_type* type) {
  while (type->is_typedef()) {
    type = ((t_typedef*)type)->get_type();
  }

  if (type->is_base_type()) {
    t_base_type::t_base tbase = ((t_base_type*)type)->get_base();
    switch (tbase) {
      case t_base_type::TYPE_VOID:
        throw std::runtime_error("NO T_VOID CONSTRUCT");
      case t_base_type::TYPE_STRING:
      case t_base_type::TYPE_BINARY:
        return "TType.String";
      case t_base_type::TYPE_BOOL:
        return "TType.Bool";
      case t_base_type::TYPE_BYTE:
        return "TType.Byte";
      case t_base_type::TYPE_I16:
        return "TType.I16";
      case t_base_type::TYPE_I32:
        return "TType.I32";
      case t_base_type::TYPE_I64:
        return "TType.I64";
      case t_base_type::TYPE_FLOAT:
        return "TType.Float";
      case t_base_type::TYPE_DOUBLE:
        return "TType.Double";
    }
  } else if (type->is_enum()) {
    return "TType.I32";
  } else if (type->is_struct() || type->is_xception()) {
    return "TType.Struct";
  } else if (type->is_map()) {
    return "TType.Map";
  } else if (type->is_set()) {
    return "TType.Set";
  } else if (type->is_list()) {
    return "TType.List";
  }

  throw std::runtime_error("INVALID TYPE IN type_to_enum: " + type->get_name());
}

THRIFT_REGISTER_GENERATOR(csharp, "C#", "");

} // namespace compiler
} // namespace thrift
} // namespace apache
