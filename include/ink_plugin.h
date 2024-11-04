#pragma once

#include <godot_cpp/classes/editor_plugin.hpp>

namespace godot {

class InkPlugin : public EditorPlugin {
	GDCLASS(InkPlugin, EditorPlugin);

private:
	std::int64_t compile_option_hash;

protected:
	static void _bind_methods();

public:
	InkPlugin() { compile_option_hash = String("Compile File").hash() % INT32_MAX; }
	~InkPlugin() = default;

	virtual void _enter_tree() override;
	virtual void _exit_tree() override;

private:
	void _on_context_menu_popup(PopupMenu* context_menu);
	void _on_context_menu_id_pressed(std::int64_t id);
};

}
