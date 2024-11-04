#include "ink_compiler_gd.h"

#include "ink_story_compiled.h"
#include "ink_gd_utils.h"

#include <godot_cpp/classes/resource_saver.hpp>
#include <godot_cpp/classes/project_settings.hpp>

void godot::InkCompiler::_bind_methods() {
	ClassDB::bind_method(D_METHOD("compile_file_to_file", "in_ink_file", "out_res_file"), &godot::InkCompiler::compile_file_to_file);
	ClassDB::bind_method(D_METHOD("compile_script_to_file", "script", "out_res_file"), &godot::InkCompiler::compile_script_to_file);
}

void godot::InkCompiler::compile_file_to_file(const String& in_ink_file, const String& out_res_file) {
	std::string infile = godot_string_to_ink(ProjectSettings::get_singleton()->globalize_path(in_ink_file));
	::InkStory result = compiler_internal.compile_file(infile);
	
	save_story_to_file(result, out_res_file);
}

void godot::InkCompiler::compile_script_to_file(const String& script, const String& out_res_file) {
	::InkStory result = compiler_internal.compile_script(godot_string_to_ink(script));

	save_story_to_file(result, out_res_file);
}

void godot::InkCompiler::save_story_to_file(const ::InkStory& story, const String& file) {
	ByteVec story_bytes = story.get_serialized_bytes();

	PackedByteArray godot_bytes;
	godot_bytes.resize(story_bytes.size());
	for (std::size_t i = 0; i < story_bytes.size(); ++i) {
		godot_bytes[i] = story_bytes[i];
	}

	Ref<InkStoryCompiled> compiled_story = memnew(InkStoryCompiled);
	compiled_story->set_data(godot_bytes);
	ResourceSaver::get_singleton()->save(compiled_story, file);
}
