#pragma once
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

// Deciding not to use capitalization on this class name because it's such a universal concept
class vec3 {
	public:
		double e[3]; // TODO change this into a modern type like vector

		vec3() : e{0, 0, 0} {}

		vec3(double a, double b, double c) : e{a, b, c} {}

		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		// these two respectively for getting and for setting it seems.
		// TODO: add some bound check here?
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; }

		vec3& operator+=(const vec3& v2)
		{
			e[0] += v2.e[0];
			e[1] += v2.e[1];
			e[2] += v2.e[2];
			return *this;
		}

		vec3& operator*=(double t)
		{
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		vec3& operator/=(double t)
		{
			return *this *= (1 / t);
		}

		double length() const
		{
			return sqrt(length_squared());
		}

		double length_squared() const
		{
			return e[0] * e[0] +
				   e[1] * e[1] +
				   e[2] * e[2];
		}
};

// common alias:
using point3 = vec3;

// Binary operators and other vector functions:
inline std::ostream& operator<<(std::ostream& outstream, const vec3& v)
{
	return outstream << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

inline vec3 operator*(double t, const vec3& v)
{
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t)
{
	return t * v;
}

inline vec3 operator/(const vec3& v, double t)
{
	return v * (1 / t);
}

inline double dot(const vec3& v1, const vec3& v2)
{
	return v1.e[0] * v2.e[0] +
		   v1.e[1] * v2.e[1] +
		   v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
	return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
				v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0],
				v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit_vector(const vec3& v)
{
	return v / v.length();
}

#endif // !VEC3_H
