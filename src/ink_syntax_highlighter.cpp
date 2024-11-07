#include "ink_syntax_highlighter.h"

#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/editor_settings.hpp>
#include <godot_cpp/classes/text_edit.hpp>

void godot::InkSyntaxHighlighter::_bind_methods() {
	/*ClassDB::bind_method(D_METHOD("_get_line_syntax_highlighting"), &godot::InkSyntaxHighlighter::_get_name);
	ClassDB::bind_method(D_METHOD("_get_name"), &godot::InkSyntaxHighlighter::_get_name);
	ClassDB::bind_method(D_METHOD("_get_supported_languages"), &godot::InkSyntaxHighlighter::_get_name);*/
}

godot::Dictionary godot::InkSyntaxHighlighter::_get_line_syntax_highlighting(std::int32_t line) const {
	Ref<EditorSettings> editor_settings = EditorInterface::get_singleton()->get_editor_settings();

	TextEdit* text_edit = get_text_edit();
	if (!text_edit) {
		return Dictionary();
	}

	String line_text = text_edit->get_line(line);

	Dictionary result;
	Dictionary subresult;
	subresult["color"] = Color(1, 1, 0);
	result[0] = subresult;

	return result;
}
