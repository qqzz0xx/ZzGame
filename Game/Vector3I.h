#pragma once
#include "pch.h"
#include "Math.h"

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

	Vector3I() : x(0), y(0), z(0) {}

	Vector3I(int64 _x, int64 _y, int64 _z) : x(_x), y(_y), z(_z) {}

	Vector3I(const int64 v[]) : x(v[0]), y(v[1]), z(v[2]) {}

	Vector3I(const Vector3I& v) : x(v.x), y(v.y), z(v.z) {}

	void FromFloat(const Vector3F& vec) 
	{
		x = FLOAT2FIXED(vec.x);
		y = FLOAT2FIXED(vec.y);
		z = FLOAT2FIXED(vec.z);
	}

	void ToFloat(Vector3F& v)
	{
		v.x = FIXED2FLOAT(x);
		v.y = FIXED2FLOAT(y);
		v.z = FIXED2FLOAT(z);
	}

	int64 Length() const
	{
		return SqrtI(x*x + y*y + z*z);
	}

	int64 SquaredLength() const
	{
		return x*x + y*y + z*z;
	}

	int64 Dot(const Vector3I& v) const
	{
		return (x*v.x + y*v.x + z*v.z) / POINT_UNIT;
	}

	Vector3I Coss(const Vector3I& v) const
	{
		Vector3I tmp;
		tmp.x = y*v.z - v.y*z;
		tmp.y = x*v.z - v.x*z;
		tmp.z = x*v.y - v.x*y;
		return tmp;
	}

	void Normalize()
	{
		int64 length = Length();
		x = x / length * POINT_UNIT;
		y = y / length * POINT_UNIT;
		z = z / length * POINT_UNIT;
	}

	Vector3I Lerp(const Vector3I& v, int64 factor)
	{
		Vector3I temp;
		temp.x = LerpI(x, v.x, factor);
		temp.y = LerpI(y, v.y, factor);
		temp.z = LerpI(z, v.z, factor);
		return temp;
	}

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

