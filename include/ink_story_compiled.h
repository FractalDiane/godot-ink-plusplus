#pragma once

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>

namespace godot {
	
class InkStoryCompiled : public Resource {
	GDCLASS(InkStoryCompiled, Resource);

private:
	PackedByteArray data;

protected:
	static void _bind_methods();

public:
	inline const PackedByteArray& get_data() const { return data; }
	inline void set_data(const PackedByteArray& value) { data = value; }
};

}
