#include "ink_story.h"

#include "ink_story_compiled.h"
#include "ink_gd_utils.h"

#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/project_settings.hpp>

void godot::InkStory::_bind_methods() {
	ClassDB::bind_method(D_METHOD("load_compiled_file", "file"), &godot::InkStory::load_compiled_file);

	ClassDB::bind_method(D_METHOD("can_continue"), &godot::InkStory::can_continue);
	ClassDB::bind_method(D_METHOD("continue_story"), &godot::InkStory::continue_story);
	ClassDB::bind_method(D_METHOD("continue_story_maximally"), &godot::InkStory::continue_story_maximally);

	ClassDB::bind_method(D_METHOD("get_current_choices"), &godot::InkStory::get_current_choices);
	ClassDB::bind_method(D_METHOD("get_current_tags"), &godot::InkStory::get_current_tags);

	ClassDB::bind_method(D_METHOD("choose_choice_index", "index"), &godot::InkStory::choose_choice_index);

	ClassDB::bind_method(D_METHOD("get_variable", "variable_name"), &godot::InkStory::get_variable);
	ClassDB::bind_method(D_METHOD("set_variable", "variable_name", "value"), &godot::InkStory::set_variable);

	ClassDB::bind_method(D_METHOD("observe_variable", "variable_name", "callback"), &godot::InkStory::observe_variable);

	ClassDB::bind_method(D_METHOD("bind_external_function", "function_name", "function", "lookahead_safe"), &godot::InkStory::bind_external_function, DEFVAL(false));
}

void godot::InkStory::load_and_compile_file(const String& file) {
	//std::string path = godot_string_to_ink(ProjectSettings::get_singleton()->globalize_path(file));
	//story_internal = ::InkStory(path);
}

void godot::InkStory::load_compiled_file(Ref<InkStoryCompiled> file) {
	story_internal = ::InkStory(godot_byte_array_to_ink(file->get_data()));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool godot::InkStory::can_continue() const {
	return story_internal.can_continue();
}

godot::String godot::InkStory::continue_story() {
	return ink_string_to_godot(story_internal.continue_story());
}

godot::String godot::InkStory::continue_story_maximally() {
	return ink_string_to_godot(story_internal.continue_story_maximally());
}

godot::TypedArray<godot::String> godot::InkStory::get_current_choices() const {
	return ink_string_array_to_godot(story_internal.get_current_choices());
}

godot::TypedArray<godot::String> godot::InkStory::get_current_tags() const {
	return ink_string_array_to_godot(story_internal.get_current_tags_v());
}

void godot::InkStory::choose_choice_index(int index) {
	story_internal.choose_choice_index(static_cast<std::size_t>(index));
}

godot::Variant godot::InkStory::get_variable(const StringName& variable_name) const {
	std::string var_name_ink = godot_string_to_ink(variable_name);
	std::optional<ExpressionParserV2::Variant> result = story_internal.get_variable(var_name_ink);
	if (result.has_value()) {
		return ink_variant_to_godot(std::move(*result));
	} else {
		godot::UtilityFunctions::push_error("Ink story variable \"", variable_name, "\" not found");
		return godot::Variant();
	}
}

void godot::InkStory::set_variable(const StringName& variable_name, const Variant& value) {
	std::string var_name_ink = godot_string_to_ink(variable_name);
	story_internal.set_variable(var_name_ink, godot_variant_to_ink(value));
}

void godot::InkStory::observe_variable(const StringName& variable_name, Callable callback) {
	std::string var_name_ink = godot_string_to_ink(variable_name);
	story_internal.observe_variable(
		var_name_ink,
		[callback](const std::string& var_name, const ExpressionParserV2::Variant& new_value) {
			callback.call(ink_string_to_godot(var_name), ink_variant_to_godot(new_value));
		}
	);
}

void godot::InkStory::bind_external_function(const StringName& function_name, Callable function, bool lookahead_safe) {
	std::string func_name_ink = godot_string_to_ink(function_name);
	story_internal.bind_external_function_generic(func_name_ink, [function](const std::vector<ExpressionParserV2::Variant>& args) {
		switch (function.get_argument_count() + function.get_bound_arguments_count()) {
			case 0:
				return godot_variant_to_ink(function.call());
			case 1:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0])
				));
			case 2:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1])
				));
			case 3:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2])
				));
			case 4:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2]),
					ink_variant_to_godot(args[3])
				));
			case 5:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2]),
					ink_variant_to_godot(args[3]),
					ink_variant_to_godot(args[4])
				));
			case 6:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2]),
					ink_variant_to_godot(args[3]),
					ink_variant_to_godot(args[4]),
					ink_variant_to_godot(args[5])
				));
			case 7:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2]),
					ink_variant_to_godot(args[3]),
					ink_variant_to_godot(args[4]),
					ink_variant_to_godot(args[5]),
					ink_variant_to_godot(args[6])
				));
			case 8:
				return godot_variant_to_ink(function.call(
					ink_variant_to_godot(args[0]),
					ink_variant_to_godot(args[1]),
					ink_variant_to_godot(args[2]),
					ink_variant_to_godot(args[3]),
					ink_variant_to_godot(args[4]),
					ink_variant_to_godot(args[5]),
					ink_variant_to_godot(args[6]),
					ink_variant_to_godot(args[7])
				));
			default:
				UtilityFunctions::push_error("bind_external_function only accepts up to 8 bound arguments");
				return ExpressionParserV2::Variant();
		}
	}, lookahead_safe);
}
