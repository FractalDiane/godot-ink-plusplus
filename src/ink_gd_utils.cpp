#include "ink_gd_utils.h"

#include <cstdint>
#include <iterator>

godot::String ink_string_to_godot(const std::string& ink_string) {
	godot::PackedByteArray bytes;
	bytes.resize(ink_string.size());
	for (std::size_t i = 0; i < ink_string.size(); ++i) {
		bytes[i] = ink_string[i];
	}

	return bytes.get_string_from_utf8();
}

godot::String ink_string_to_godot(std::string&& ink_string) {
	godot::PackedByteArray bytes;
	bytes.resize(ink_string.size());
	for (std::size_t i = 0; i < ink_string.size(); ++i) {
		bytes[i] = ink_string[i];
	}

	return bytes.get_string_from_utf8();
}

std::string godot_string_to_ink(const godot::String& godot_string) {
	return std::string(godot_string.utf8().get_data());
}

std::string godot_string_to_ink(godot::String&& godot_string) {
	return std::string(godot_string.utf8().get_data());
}

godot::TypedArray<godot::String> ink_string_array_to_godot(std::vector<std::string>&& ink_array) {
	godot::TypedArray<godot::String> result;
	for (auto string = std::make_move_iterator(ink_array.begin()), end = std::make_move_iterator(ink_array.end()); string != end; ++string) {
		result.push_back(ink_string_to_godot(*string));
	}

	return result;
}

ByteVec godot_byte_array_to_ink(const godot::PackedByteArray& godot_array) {
	ByteVec result;
	result.reserve(godot_array.size());

	for (std::uint8_t byte : godot_array) {
		result.push_back(byte);
	}

	return result;
}

godot::Variant ink_variant_to_godot(const ExpressionParserV2::Variant& ink_variant) {
	switch (ink_variant.index()) {
		case ExpressionParserV2::Variant_Bool:
			return static_cast<bool>(ink_variant);
		case ExpressionParserV2::Variant_Int:
			return static_cast<std::int64_t>(ink_variant);
		case ExpressionParserV2::Variant_Float:
			return static_cast<real_t>(ink_variant);
		case ExpressionParserV2::Variant_String:
			return ink_string_to_godot(ink_variant.get<std::string>());
		default:
			return godot::Variant();
	}
}

godot::Variant ink_variant_to_godot(ExpressionParserV2::Variant&& ink_variant) {
	switch (ink_variant.index()) {
		case ExpressionParserV2::Variant_Bool:
			return static_cast<bool>(ink_variant);
		case ExpressionParserV2::Variant_Int:
			return static_cast<std::int64_t>(ink_variant);
		case ExpressionParserV2::Variant_Float:
			return static_cast<real_t>(ink_variant);
		case ExpressionParserV2::Variant_String:
			return ink_string_to_godot(ink_variant.get<std::string>());
		default:
			return godot::Variant();
	}
}

ExpressionParserV2::Variant godot_variant_to_ink(const godot::Variant& godot_variant) {
	switch (godot_variant.get_type()) {
		case godot::Variant::BOOL:
			return static_cast<bool>(godot_variant);
		case godot::Variant::INT:
			return static_cast<std::int64_t>(godot_variant);
		case godot::Variant::FLOAT:
			return static_cast<double>(godot_variant);
		case godot::Variant::STRING:
		case godot::Variant::STRING_NAME:
			return godot_string_to_ink(godot_variant);
		default:
			return ExpressionParserV2::Variant();
	}
}

ExpressionParserV2::Variant godot_variant_to_ink(godot::Variant&& godot_variant) {
	switch (godot_variant.get_type()) {
		case godot::Variant::BOOL:
			return static_cast<bool>(godot_variant);
		case godot::Variant::INT:
			return static_cast<std::int64_t>(godot_variant);
		case godot::Variant::FLOAT:
			return static_cast<double>(godot_variant);
		case godot::Variant::STRING:
		case godot::Variant::STRING_NAME:
			return godot_string_to_ink(godot_variant);
		default:
			return ExpressionParserV2::Variant();
	}
}
