@tool
extends EditorSyntaxHighlighter

const KEYWORDS: Array[String] = [
	"VAR",
	"CONST",
	"LIST",
	"EXTERNAL",
	"INCLUDE",
]

var regex := RegEx.new()

var background_color: Color
var text_color: Color
var selection_color: Color
var comment_color: Color
var keyword_color: Color
var function_color: Color
var function_definition_color: Color
var base_type_color: Color

func _init() -> void:
	regex.compile(r"\b")
	

func _get_name() -> String:
	return "Ink"
	
func _get_supported_languages() -> PackedStringArray:
	return ["TextFile"]
	
# /////////////////////////////////////////////////////////////////////////////////////////////////
	
func _get_line_syntax_highlighting(line: int) -> Dictionary:
	var text_edit := get_text_edit()
	if text_edit == null:
		return {}
		
	var line_text := text_edit.get_line(line)
		
	setup_colors()
	var result := {}
	
	for kw in KEYWORDS:
		if line_text.begins_with(kw):
			result[0] = {"color": keyword_color}
			result[len(kw)] = {"color": text_color}
		elif line_text.begins_with("="):
			var found_knot_name := false
			for i in range(len(line_text)):
				if not found_knot_name:
					if line_text[i] != '=':
						result[i] = {"color": function_definition_color}
						found_knot_name = true
				else:
					pass#if line_text[i] == '=' or i == len(line_text) - 1:
						
	
	return result
	
# /////////////////////////////////////////////////////////////////////////////////////////////////

func setup_colors() -> void:
	var plugin := EditorPlugin.new()
	var settings := plugin.get_editor_interface().get_editor_settings()
	
	background_color = settings.get_setting("text_editor/theme/highlighting/background_color")
	text_color = settings.get_setting("text_editor/theme/highlighting/text_color")
	selection_color = settings.get_setting("text_editor/theme/highlighting/selection_color")
	comment_color = settings.get_setting("text_editor/theme/highlighting/comment_color")
	keyword_color = settings.get_setting("text_editor/theme/highlighting/keyword_color")
	function_color = settings.get_setting("text_editor/theme/highlighting/function_color")
	function_definition_color = settings.get_setting("text_editor/theme/highlighting/gdscript/function_definition_color")
	base_type_color = settings.get_setting("text_editor/theme/highlighting/base_type_color")
	
	plugin.free()


func at(string: String, index: int) -> String:
	return string[index] if index >= 0 and index < len(string) else ""
