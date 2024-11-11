#pragma once

#include <godot_cpp/classes/ref.hpp>

#include "runtime/ink_story.h"
#include "ink_story_compiled.h"

namespace godot {

class InkStory : public RefCounted {
	GDCLASS(InkStory, RefCounted);

private:
	::InkStory story_internal;

protected:
	static void _bind_methods();

public:
	void load_and_compile_file(const String& file, const String& root_include_path = String());
	void load_compiled_file(Ref<InkStoryCompiled> file);

	bool can_continue() const;
	bool is_story_finished() const;

	String continue_story();
	String continue_story_maximally();

	TypedArray<String> get_current_choices() const;
	TypedArray<String> get_current_tags() const;

	void choose_choice_index(int index);
	
	Variant get_variable(const StringName& variable_name) const;
	void set_variable(const StringName& variable_name, const Variant& value);

	void observe_variable(const StringName& variable_name, Callable callback);

	void bind_external_function(const StringName& function_name, Callable function, bool lookahead_safe = false);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	const ExpressionParserV2::StoryVariableInfo& get_internal_variable_info() const { return story_internal.get_variable_info(); }
};

}
