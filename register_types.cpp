#include "register_types.h"
#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "ink_plugin.h"
#include "ink_player_editor.h"
#include "ink_player_entry.h"

#include "ink_story.h"
#include "ink_compiler_gd.h"
#include "ink_story_compiled.h"

void initialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	if (p_level == godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		godot::ClassDB::register_class<godot::InkStory>();
		godot::ClassDB::register_class<godot::InkStoryCompiled>();
		godot::ClassDB::register_class<godot::InkCompiler>();
	} else if (p_level == godot::MODULE_INITIALIZATION_LEVEL_EDITOR) {
		godot::ClassDB::register_class<godot::InkPlugin>();
		godot::EditorPlugins::add_by_type<godot::InkPlugin>();

		godot::ClassDB::register_class<godot::InkPlayerEditor>();
		godot::ClassDB::register_class<godot::InkPlayerEntry>();
	}
}

void uninitialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE && p_level != godot::MODULE_INITIALIZATION_LEVEL_EDITOR) {
		return;
	}
}

extern "C" {
	GDExtensionBool GDE_EXPORT gdextension_lib_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj{p_get_proc_address, p_library, r_initialization};
		init_obj.register_initializer(initialize_gdextension_types);
		init_obj.register_terminator(uninitialize_gdextension_types);
		init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
