#include "ink_plugin.h"

#include "ink_compiler_gd.h"

#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/file_system_dock.hpp>
#include <godot_cpp/classes/popup_menu.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

void godot::InkPlugin::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_on_context_menu_popup"), &godot::InkPlugin::_on_context_menu_popup);
	ClassDB::bind_method(D_METHOD("_on_context_menu_id_pressed"), &godot::InkPlugin::_on_context_menu_id_pressed);
}

void godot::InkPlugin::_enter_tree() {
	FileSystemDock* file_system = get_editor_interface()->get_file_system_dock();
	PopupMenu* context_menu = nullptr;
	TypedArray<Node> children = file_system->get_children();
	for (std::int64_t i = 0; i < children.size(); ++i) {
		if (cast_to<Node>(children[i])->is_class("PopupMenu")) {
			context_menu = cast_to<PopupMenu>(children[i]);
			break;
		}
	}

	if (context_menu) {
		context_menu->connect("about_to_popup", Callable(this, "_on_context_menu_popup").bind(context_menu));
		context_menu->connect("id_pressed", Callable(this, "_on_context_menu_id_pressed"));
	}
}

void godot::InkPlugin::_exit_tree() {
	
}

void godot::InkPlugin::_on_context_menu_popup(PopupMenu* context_menu) {
	String current_path = get_editor_interface()->get_current_path();
	if (current_path.get_extension() == "ink") {
		context_menu->add_separator();
		context_menu->add_item("Compile File", compile_option_hash);
	}
}

void godot::InkPlugin::_on_context_menu_id_pressed(std::int64_t id) {
	if (id == compile_option_hash) {
		Ref<godot::InkCompiler> compiler = memnew(godot::InkCompiler);
		String file_path = get_editor_interface()->get_current_path();
		compiler->compile_file_to_file(file_path, file_path.get_basename() + ".res");
	}
}
