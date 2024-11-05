#include "ink_player_entry.h"

#include <godot_cpp/classes/property_tweener.hpp>
#include <godot_cpp/classes/tween.hpp>

void godot::InkPlayerEntry::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_text"), &godot::InkPlayerEntry::set_text);
	ClassDB::bind_method(D_METHOD("set_tags"), &godot::InkPlayerEntry::set_tags);
}

void godot::InkPlayerEntry::_ready() {
	text_label = get_node<RichTextLabel>("Text");
	tag_container = get_node<VBoxContainer>("Tags");

	Ref<Tween> tween = create_tween();
	set_modulate(Color(1.0f, 1.0f, 1.0f, 0.0f));
	tween->tween_property(this, "modulate:a", 1.0f, 0.5f);
}

void godot::InkPlayerEntry::set_text(const String& text) {
	text_label->set_text(text);
}

void godot::InkPlayerEntry::set_tags(const TypedArray<String>& tags) {
	RichTextLabel* text = memnew(RichTextLabel);
	text->set_fit_content(true);
	text->set_clip_contents(false);
	text->set_v_size_flags(Control::SIZE_SHRINK_CENTER | Control::SIZE_EXPAND);
	text->set_use_bbcode(true);

	String text_contents;
	for (int i = 0; i < tags.size(); ++i) {
		text_contents += String("[color=#ffffff80]#[/color] {0}{1}").format(Array::make(tags[i], i < tags.size() - 1 ? "  " : ""));
	}

	if (!text_contents.is_empty()) {
		text->set_text(text_contents);
		tag_container->add_child(text);
	} else {
		tag_container->set_visible(false);
	}
}
