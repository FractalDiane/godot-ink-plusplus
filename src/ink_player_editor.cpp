#include "ink_player_editor.h"

#include "ink_player_entry.h"

#include <godot_cpp/classes/editor_resource_picker.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

void godot::InkPlayerEditor::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_on_selected_story_changed"), &godot::InkPlayerEditor::_on_selected_story_changed);

	ClassDB::bind_method(D_METHOD("_on_check_box_continue_toggled"), &godot::InkPlayerEditor::_on_check_box_continue_toggled);
	ClassDB::bind_method(D_METHOD("_on_check_box_bbcode_toggled"), &godot::InkPlayerEditor::_on_check_box_bbcode_toggled);
	
	ClassDB::bind_method(D_METHOD("_on_button_start_pressed"), &godot::InkPlayerEditor::_on_button_start_pressed);
	ClassDB::bind_method(D_METHOD("_on_button_restart_pressed"), &godot::InkPlayerEditor::_on_button_restart_pressed);
	ClassDB::bind_method(D_METHOD("_on_button_stop_pressed"), &godot::InkPlayerEditor::_on_button_stop_pressed);

	ClassDB::bind_method(D_METHOD("_on_continue_selected"), &godot::InkPlayerEditor::_on_continue_selected);
	ClassDB::bind_method(D_METHOD("_on_choice_selected"), &godot::InkPlayerEditor::_on_choice_selected);
}

void godot::InkPlayerEditor::_ready() {
	story_items = get_node<VBoxContainer>("VBoxContainer/HSplitContainer/MarginContainer/ScrollContainer/StoryItems");
	story_choices = get_node<VBoxContainer>("VBoxContainer/HSplitContainer/HSplitContainer/MarginContainer2/ScrollContainer/MarginContainer/VBoxContainer/StoryChoices");

	choices_header = get_node<HBoxContainer>("VBoxContainer/HSplitContainer/HSplitContainer/MarginContainer2/ScrollContainer/MarginContainer/VBoxContainer/ChoicesHeader");
	choices_header_text = get_node<Label>("VBoxContainer/HSplitContainer/HSplitContainer/MarginContainer2/ScrollContainer/MarginContainer/VBoxContainer/ChoicesHeader/ChoicesHeaderText");

	state_header = get_node<HBoxContainer>("VBoxContainer/HSplitContainer/HSplitContainer/MarginContainer3/ScrollContainer/MarginContainer/VBoxContainer/StateHeader");

	button_start = get_node<Button>("VBoxContainer/HBoxContainer/HBoxContainer2/ButtonStart");
	button_restart = get_node<Button>("VBoxContainer/HBoxContainer/HBoxContainer2/ButtonRestart");
	button_stop = get_node<Button>("VBoxContainer/HBoxContainer/HBoxContainer2/ButtonStop");

	EditorResourcePicker* picker = memnew(EditorResourcePicker);
	picker->set_base_type("InkStoryCompiled");
	picker->set_custom_minimum_size(Vector2(200, 0));
	picker->connect("resource_changed", Callable(this, "_on_selected_story_changed"));
	Node* parent = get_node<Node>("VBoxContainer/HBoxContainer");
	parent->add_child(picker);
	parent->move_child(picker, 1);

	button_start->set_button_icon(get_theme_icon("Play", "EditorIcons"));
	button_restart->set_button_icon(get_theme_icon("Reload", "EditorIcons"));
	button_stop->set_button_icon(get_theme_icon("Stop", "EditorIcons"));

	button_start->set_disabled(true);
	button_restart->set_visible(false);
	button_stop->set_visible(false);
}

void godot::InkPlayerEditor::start_story() {
	Ref<InkStory> new_story = memnew(InkStory);
	story = new_story;
	story->load_compiled_file(story_file);

	continue_story(auto_continue);
}

void godot::InkPlayerEditor::continue_story(bool maximally) {
	choices_header_text->set_text("Choices");
	if (maximally) {
		PackedStringArray next_text = story->continue_story_maximally().split("\n");
		TypedArray<String> current_tags = story->get_current_tags();
		for (int i = 0; i < next_text.size(); ++i) {
			add_text(next_text[i], current_tags);
		}

		if (!story->is_story_finished()) {
			add_choices(story->get_current_choices());
		}
	} else {
		if (story->can_continue()) {
			String next_text = story->continue_story();
			add_text(next_text, story->get_current_tags());
			if (story->can_continue()) {
				add_continue();
			} else if (!story->is_story_finished()) {
				add_choices(story->get_current_choices());
			}
		} else if (!story->is_story_finished()) {
			add_choices(story->get_current_choices());
		}
	}
}

void godot::InkPlayerEditor::add_text(const String& text, const TypedArray<String>& tags) {
	UtilityFunctions::print(text);
	UtilityFunctions::print(tags);
	if (!text.strip_edges().is_empty()) {
		Ref<PackedScene> entry_scene = ResourceLoader::get_singleton()->load("res://addons/ink_plusplus/ink_player_entry.tscn", "PackedScene");
		InkPlayerEntry* entry = cast_to<InkPlayerEntry>(entry_scene->instantiate());
		entry->call_deferred("set_text", text);
		entry->call_deferred("set_tags", tags);
		story_items->add_child(entry);
	}
}

void godot::InkPlayerEditor::add_continue() {
	const Array ContinueOptions = Array::make("Continue", "Continue Maximally");
	for (int i = 0; i < ContinueOptions.size(); ++i) {
		Button* button = memnew(Button);
		button->set_text(ContinueOptions[i]);
		button->set_button_icon(get_theme_icon(i == 1 ? "TransitionEnd" : "TransitionImmediate", "EditorIcons"));
		button->connect("pressed", Callable(this, "_on_continue_selected").bind(i));
		story_choices->add_child(button);
	}

	choices_header_text->set_text("Story");
}

void godot::InkPlayerEditor::add_choices(const TypedArray<String>& choices) {
	for (int i = 0; i < choices.size(); ++i) {
		Button* button = memnew(Button);
		button->set_text(choices[i]);
		button->connect("pressed", Callable(this, "_on_choice_selected").bind(i));
		story_choices->add_child(button);
	}

	choices_header_text->set_text("Choices");
}

void godot::InkPlayerEditor::update_variables() {

}

void godot::InkPlayerEditor::update_button_visibility() {
	button_start->set_visible(!story_running);
	button_restart->set_visible(story_running);
	button_stop->set_visible(story_running);
}

void godot::InkPlayerEditor::clear_story_content() {
	Array children = story_items->get_children();
	for (int i = 0; i < children.size(); ++i) {
		cast_to<Node>(children[i])->queue_free();
	}

	Array buttons = story_choices->get_children();
	for (int i = 0; i < buttons.size(); ++i) {
		cast_to<Node>(buttons[i])->queue_free();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void godot::InkPlayerEditor::_on_selected_story_changed(Ref<Resource> resource) {
	clear_story_content();
	story_running = false;
	update_button_visibility();

	button_start->set_disabled(resource.is_null() || resource->get_class() != "InkStoryCompiled");
	story_file = resource;
}

void godot::InkPlayerEditor::_on_check_box_continue_toggled(bool button_pressed) {
	auto_continue = button_pressed;
}

void godot::InkPlayerEditor::_on_check_box_bbcode_toggled(bool button_pressed) {
	bbcode_enabled = button_pressed;
}

void godot::InkPlayerEditor::_on_button_start_pressed() {
	start_story();
	story_running = true;
	update_button_visibility();
}

void godot::InkPlayerEditor::_on_button_restart_pressed() {
	clear_story_content();
	_on_button_start_pressed();
}

void godot::InkPlayerEditor::_on_button_stop_pressed() {
	clear_story_content();
	story_running = false;
	update_button_visibility();
}

void godot::InkPlayerEditor::_on_continue_selected(int index) {
	Array choices = story_choices->get_children();
	for (int i = 0; i < choices.size(); ++i) {
		cast_to<Node>(choices[i])->queue_free();
	}

	continue_story(index == 1);
}

void godot::InkPlayerEditor::_on_choice_selected(int index) {
	Array choices = story_choices->get_children();
	for (int i = 0; i < choices.size(); ++i) {
		cast_to<Node>(choices[i])->queue_free();
	}

	story->choose_choice_index(index);
	continue_story(auto_continue);
}
