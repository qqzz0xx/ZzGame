#pragma once
#include "pch.h"

struct Vector2F
{
	float x, y;
	Vector2F(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	Vector2F(const Vector2F& v)
	{
		x = v.x;
		y = v.y;
	}
	Vector2F& operator = (const Vector2F& v)
	{
		x = v.x;
		y = v.y;
	}
};
class Vector2I
{
public:
	int64 x;
	int64 y;

	Vector2I() {}

	Vector2I(int64 _x, int64 _y) : x(_x), y(_y) {}

	Vector2I(const Vector2I& v) : x(v.x), y(v.y) {}

	Vector2I(const int64 coord[2]) : x(coord[0]), y(coord[1]) {}



	Vector2I& operator = (const Vector2I& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	int64& operator [] (size_t i)
	{
		assert(i < 2);
		return *(&x + i);
	}

	const int64& operator [] (size_t i) const
	{
		assert(i < 2);
		return *(&x + i);
	}

	int64* Ptr() { return &x; }

	const int64* Ptr() const { return &x; }

	bool operator == (const Vector2I& v) const { return (x == v.x) && (y == v.y); }

	bool operator != (const Vector2I& v) const { return !(*this == v); }

	Vector2I operator + (const Vector2I& v) const { return Vector2I(x + v.x, y + v.y); }

	Vector2I operator - (const Vector2I& v) const { return Vector2I(x - v.x, y - v.y); }

	Vector2I operator * (const Vector2I& v) const { return Vector2I(x * v.x, y * v.y); }

	Vector2I operator / (const Vector2I& v) const { return Vector2I(x / v.x, y / v.y); }

	Vector2I operator + (const int64 scalar) const { return Vector2I(x + scalar, y + scalar); }

	Vector2I operator - (const int64 scalar) const { return Vector2I(x - scalar, y - scalar); }

	Vector2I operator * (const int64 scalar) const { return Vector2I(x * scalar, y * scalar); }

	Vector2I operator / (const int64 scalar) const { return Vector2I(x / scalar, y / scalar); }

	Vector2I& operator += (const Vector2I& v) { x += v.x, y += v.y; return *this; }

	Vector2I& operator -= (const Vector2I& v) { x -= v.x, y -= v.y;  return *this; }

	Vector2I& operator *= (const Vector2I& v) { x *= v.x, y *= v.y; return *this; }

	Vector2I& operator /= (const Vector2I& v) { x /= v.x, y /= v.y; return *this; }

	Vector2I& operator += (const int64 scalar) { x += scalar, y += scalar; return *this; }

	Vector2I& operator -= (const int64 scalar) { x -= scalar, y -= scalar; return *this; }

	Vector2I& operator *= (const int64 scalar) { x *= scalar, y *= scalar; return *this; }

	Vector2I& operator /= (const int64 scalar) { x / scalar, y / scalar; return *this; }

	friend Vector2I operator + (const int64 scalar, const Vector2I& v) { return Vector2I(v.x + scalar, v.y + scalar); }

	friend Vector2I operator - (const int64 scalar, const Vector2I& v) { return Vector2I(v.x - scalar, v.y - scalar); }

	friend Vector2I operator * (const int64 scalar, const Vector2I& v) { return Vector2I(v.x * scalar, v.y * scalar); }

	friend Vector2I operator / (const int64 scalar, const Vector2I& v) { return Vector2I(v.x / scalar, v.y / scalar); }


};

