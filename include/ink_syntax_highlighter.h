#pragma once

#include <godot_cpp/classes/editor_syntax_highlighter.hpp>

#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {

class InkSyntaxHighlighter : public EditorSyntaxHighlighter {
	GDCLASS(InkSyntaxHighlighter, EditorSyntaxHighlighter);

protected:
	static void _bind_methods();

public:
	virtual Dictionary _get_line_syntax_highlighting(std::int32_t line) const override;

	virtual String _get_name() const override { return "Ink"; }
	virtual PackedStringArray _get_supported_languages() const override { return PackedStringArray({"TextFile"}); }
};

}
