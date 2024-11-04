#pragma once

#include <godot_cpp/classes/ref.hpp>

#include "ink_compiler.h"
#include "runtime/ink_story.h"

namespace godot {

class InkCompiler : public RefCounted {
	GDCLASS(InkCompiler, RefCounted);

private:
	::InkCompiler compiler_internal;

protected:
	static void _bind_methods();

public:
	void compile_file_to_file(const String& in_ink_file, const String& out_res_file);
	void compile_script_to_file(const String& script, const String& out_res_file);

private:
	void save_story_to_file(const ::InkStory& story, const String& file);
};

}
