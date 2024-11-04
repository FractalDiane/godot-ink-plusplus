#pragma once

#include "ink_story.h"
#include "ink_story_compiled.h"

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/button.hpp>

namespace godot {

class InkPlayerEditor : public Control {
	GDCLASS(InkPlayerEditor, Control);

private:
	Ref<InkStory> story;
	Ref<InkStoryCompiled> story_file;
	bool story_running = false;

	bool auto_continue = false;
	bool bbcode_enabled = false;

	VBoxContainer* story_items;
	VBoxContainer* story_choices;

	HBoxContainer* choices_header;
	Label* choices_header_text;

	HBoxContainer* state_header;

	Button* button_start;
	Button* button_restart;
	Button* button_stop;

protected:
	static void _bind_methods();

public:
	virtual void _ready() override;

private:
	void start_story();
	void continue_story(bool maximally);

	void add_text(const String& text, const TypedArray<String>& tags);
	void add_continue();
	void add_choices(const TypedArray<String>& choices);

	void update_button_visibility();
	void clear_story_content();

	///////////////////////////////////////////////////////////////////////////

	void _on_selected_story_changed(Ref<Resource> resource);

	void _on_check_box_continue_toggled(bool button_pressed);
	void _on_check_box_bbcode_toggled(bool button_pressed);

	void _on_button_start_pressed();
	void _on_button_restart_pressed();
	void _on_button_stop_pressed();

	void _on_continue_selected(int index);
	void _on_choice_selected(int index);
};

}
