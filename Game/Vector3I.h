#pragma once
#include "pch.h"
struct Vector3F
{
	float x, y, z;

	Vector3F(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	Vector3F(const Vector3F& v) : x(v.x), y(v.y), z(v.z) {}

	Vector3F& operator = (const Vector3F& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

};

class Vector3I
{
public:
	int64 x;
	int64 y;
	int64 z;

	Vector3I();
	~Vector3I();

	Vector3I(int64 _x, int64 _y, int64 _z) : x(_x), y(_y), z(_z) {}

	bool operator == (const Vector3I& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }

	bool operator != (const Vector3I& v) const { return !(*this == v); }

	Vector3I operator + (const Vector3I& v) const { return Vector3I(x + v.x, y + v.y, z + v.z); }

	Vector3I operator - (const Vector3I& v) const { return Vector3I(x - v.x, y - v.y, z - v.z); }

	Vector3I operator * (const Vector3I& v) const { return Vector3I(x * v.x, y * v.y, z* v.z); }

	Vector3I operator / (const Vector3I& v) const { return Vector3I(x / v.x, y / v.y, z / v.z); }

	Vector3I operator + (const int64 scalar) const { return Vector3I(x + scalar, y + scalar, z + scalar); }

	Vector3I operator - (const int64 scalar) const { return Vector3I(x - scalar, y - scalar, z - scalar); }

	Vector3I operator * (const int64 scalar) const { return Vector3I(x * scalar, y * scalar, z*scalar); }

	Vector3I operator / (const int64 scalar) const { return Vector3I(x / scalar, y / scalar, z / scalar); }

	Vector3I& operator += (const Vector3I& v) { x += v.x, y += v.y, z += v.z; return *this; }

	Vector3I& operator -= (const Vector3I& v) { x -= v.x, y -= v.y, z -= v.z;  return *this; }

	Vector3I& operator *= (const Vector3I& v) { x *= v.x, y *= v.y, z *= v.z; return *this; }

	Vector3I& operator /= (const Vector3I& v) { x /= v.x, y /= v.y, z /= v.z; return *this; }

	Vector3I& operator += (const int64 scalar) { x += scalar, y += scalar, z += scalar; return *this; }

	Vector3I& operator -= (const int64 scalar) { x -= scalar, y -= scalar, z -= scalar; return *this; }

	Vector3I& operator *= (const int64 scalar) { x *= scalar, y *= scalar, z *= scalar; return *this; }

	Vector3I& operator /= (const int64 scalar) { x / scalar, y / scalar, z /= scalar; return *this; }

	friend Vector3I operator + (const int64 scalar, const Vector3I& v) { return Vector3I(v.x + scalar, v.y + scalar, v.z + scalar); }

	friend Vector3I operator - (const int64 scalar, const Vector3I& v) { return Vector3I(v.x - scalar, v.y - scalar, v.z - scalar); }

	friend Vector3I operator * (const int64 scalar, const Vector3I& v) { return Vector3I(v.x * scalar, v.y * scalar, v.z *scalar); }

	friend Vector3I operator / (const int64 scalar, const Vector3I& v) { return Vector3I(v.x / scalar, v.y / scalar, v.z / scalar); }
};

