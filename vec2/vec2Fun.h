

namespace vf{
	vec2 A2(float angle, float length) {
		return vec2(length * cos(angle), length * sin(angle));
	}
	mat22 A22(float angle, float length){
		vec2 i=A2(angle, length);
		return mat22(i, vec2(i.y,-i.x));
	}
};
