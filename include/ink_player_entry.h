#pragma once

#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/rich_text_label.hpp>

namespace godot {

class InkPlayerEntry : public HBoxContainer {
	GDCLASS(InkPlayerEntry, HBoxContainer);

private:
	RichTextLabel* text_label;
	VBoxContainer* tag_container;

protected:
	static void _bind_methods();

public:
	virtual void _ready() override;

	void set_text(const String& text);
	void set_tags(const TypedArray<String>& tags);
};

}
