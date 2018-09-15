#ifndef VEC3_H
#define VEC3_H
#include <math.h>

template <class T>

class vec3 {
public:
	T x, y, z;

public:
	vec3() : x(0), y(0), z(0) {}
	vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	vec3(T* vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}

	//operators:
	vec3 operator +(const vec3 vec) const {
		vec3 ret;

		ret.x = x + vec.x;
		ret.y = y + vec.y;
		ret.z = z + vec.z;

		return ret;
	}

	vec3 operator -(const vec3 vec) const {
		vec3 ret;

		ret.x = x - vec.x;
		ret.y = y - vec.y;
		ret.z = z - vec.z;

		return ret;
	}

	void operator +=(const vec3 vec) const {
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	void operator -=(const vec3 vec) const {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}

	void operator =(const vec3 vec) const {
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	bool operator ==(const vec3 vec) const {
		bool ret = true;
		if (x != vec.x || y != vec.y || z != vec.z)
			ret = false;

		return ret;
	}
	//

	//methods:
	void normalize() {
		int _x = x, _y = y, _z = z;
		int root = sqrt(_x*_x + _y*_y + _z*_z);

		_x = _x / root;
		_y = _y / root;
		_z = _z / root;

		x = _x;
		y = _y;
		z = _z;
	}

	void zero() {
		x = 0;
		y = 0;
		z = 0;
	}

	bool is_zero() {
		bool ret = true;
		if (x != 0 || y != 0 || z != 0)
			ret = false;

		return ret;
	}

	T distance_to(vec3 vec) {
		int _x = x, _y = y, _z = z;
		int root = sqrt(_x*_x + _y*_y + _z*_z);

		int _x2 = vec.x, _y2 = vec.y, _z2 = vec.z;
		int root2 = sqrt(_x2*_x2 + _y2*_y2 + _z2*_z2);

		T dis = root - root2;
		if (dis < 0) dis = dis*(-1);

		return dis;
	}
};

typedef vec3<int> iVec;
typedef vec3<float> fVec;

#endif // !VEC3_H
