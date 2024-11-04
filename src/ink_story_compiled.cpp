#include "ink_story_compiled.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void InkStoryCompiled::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_data", "data"), &InkStoryCompiled::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &InkStoryCompiled::get_data);
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_BYTE_ARRAY, "data", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE), "set_data", "get_data");
}
