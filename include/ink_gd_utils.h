#pragma once

#include "expression_parser/token.h"
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/typed_array.hpp>

#include <string>
#include <vector>

godot::String ink_string_to_godot(const std::string& ink_string);
godot::String ink_string_to_godot(std::string&& ink_string);
std::string godot_string_to_ink(const godot::String& godot_string);
std::string godot_string_to_ink(godot::String&& godot_string);

godot::TypedArray<godot::String> ink_string_array_to_godot(std::vector<std::string>&& ink_array);

ByteVec godot_byte_array_to_ink(const godot::PackedByteArray& godot_array);

godot::Variant ink_variant_to_godot(const ExpressionParserV2::Variant& ink_variant);
godot::Variant ink_variant_to_godot(ExpressionParserV2::Variant&& ink_variant);
ExpressionParserV2::Variant godot_variant_to_ink(const godot::Variant& godot_variant);
ExpressionParserV2::Variant godot_variant_to_ink(godot::Variant&& godot_variant);
