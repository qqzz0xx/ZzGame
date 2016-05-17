#pragma once
#include "pch.h"
#include "Math.h"
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
	uint64 x;
	uint64 y;

	Vector2I() {}

	Vector2I(uint64 _x, uint64 _y) : x(_x), y(_y) {}

	Vector2I(const Vector2I& v) : x(v.x), y(v.y) {}

	Vector2I(const uint64 coord[2]) : x(coord[0]), y(coord[1]) {}

	void FromFloat(const Vector2F& v)
	{
		x = FLOAT2FIXED(v.x);
		y = FLOAT2FIXED(v.y);
	}

	void ToFloat(Vector2F& v)
	{
		v.x = FIXED2FLOAT(x);
		v.y = FIXED2FLOAT(y);
	}

	int64 Length() const
	{
		return SqrtI(x*x + y*y);
	}

	int64 SquaredLength() const
	{
		return x*x + y*y;
	}

	int64 Dot(const Vector2I& v) const
	{
		return (x*v.x + y*v.x) / POINT_UNIT;
	}

	Vector2I Coss(const Vector2I& v) const
	{
		Vector2I tmp;
		tmp.x = x*v.y - v.y*x;
		tmp.y = y*v.x - v.x*y;
		return tmp;
	}

	void Normalize()
	{
		int64 length = Length();
		x = x / length * POINT_UNIT;
		y = y / length * POINT_UNIT;
	}

	Vector2I GetNormalize()
	{
		Normalize();
		return *this;
	}

	Vector2I Lerp(const Vector2I& v, int64 factor)
	{
		Vector2I temp;
		temp.x = LerpI(x, v.x, factor);
		temp.y = LerpI(y, v.y, factor);

		return temp;
	}

	Vector2I& operator = (const Vector2I& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	uint64& operator [] (size_t i)
	{
		assert(i < 2);
		return *(&x + i);
	}

	const uint64& operator [] (size_t i) const
	{
		assert(i < 2);
		return *(&x + i);
	}

	uint64* Ptr() { return &x; }

	const uint64* Ptr() const { return &x; }

	bool operator == (const Vector2I& v) const { return (x == v.x) && (y == v.y); }

	bool operator != (const Vector2I& v) const { return !(*this == v); }

	Vector2I operator + (const Vector2I& v) const { return Vector2I(x + v.x, y + v.y); }

	Vector2I operator - (const Vector2I& v) const { return Vector2I(x - v.x, y - v.y); }

	Vector2I operator * (const Vector2I& v) const { return Vector2I(x * v.x, y * v.y); }

	Vector2I operator / (const Vector2I& v) const { return Vector2I(x / v.x, y / v.y); }

	Vector2I operator + (const uint64 scalar) const { return Vector2I(x + scalar, y + scalar); }

	Vector2I operator - (const uint64 scalar) const { return Vector2I(x - scalar, y - scalar); }

	Vector2I operator * (const uint64 scalar) const { return Vector2I(x * scalar, y * scalar); }

	Vector2I operator / (const uint64 scalar) const { return Vector2I(x / scalar, y / scalar); }

	Vector2I& operator += (const Vector2I& v) { x += v.x, y += v.y; return *this; }

	Vector2I& operator -= (const Vector2I& v) { x -= v.x, y -= v.y;  return *this; }

	Vector2I& operator *= (const Vector2I& v) { x *= v.x, y *= v.y; return *this; }

	Vector2I& operator /= (const Vector2I& v) { x /= v.x, y /= v.y; return *this; }

	Vector2I& operator += (const uint64 scalar) { x += scalar, y += scalar; return *this; }

	Vector2I& operator -= (const uint64 scalar) { x -= scalar, y -= scalar; return *this; }

	Vector2I& operator *= (const uint64 scalar) { x *= scalar, y *= scalar; return *this; }

	Vector2I& operator /= (const uint64 scalar) { x / scalar, y / scalar; return *this; }

	friend Vector2I operator + (const uint64 scalar, const Vector2I& v) { return Vector2I(v.x + scalar, v.y + scalar); }

	friend Vector2I operator - (const uint64 scalar, const Vector2I& v) { return Vector2I(v.x - scalar, v.y - scalar); }

	friend Vector2I operator * (const uint64 scalar, const Vector2I& v) { return Vector2I(v.x * scalar, v.y * scalar); }

	friend Vector2I operator / (const uint64 scalar, const Vector2I& v) { return Vector2I(v.x / scalar, v.y / scalar); }

};

