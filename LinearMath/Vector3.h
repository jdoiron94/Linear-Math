#ifndef Vector3_H
#define Vector3_H

#include <vector>

using std::vector;

#pragma once

/*
* @author Jacob Doiron
* @since 03/08/16
*/

namespace LinearMath {

	class Vector3 {

	public:

		Vector3(float x, float y, float z);

		Vector3 operator+(Vector3 vector);
		Vector3 operator-(Vector3 vector);
		Vector3 operator*(Vector3 vector);
		Vector3 operator/(Vector3 vector);
		bool operator==(Vector3 vector);
		bool operator!=(Vector3 vector);

		Vector3 scale(float scalar);
		Vector3 cross(Vector3 vector);
		Vector3 lerp(Vector3 vector, float scalar);
		Vector3 reflect(Vector3 normal);
		Vector3 toPolar(bool radians);
		Vector3 toCartesian(bool radians);
		Vector3 componentForm(Vector3 terminal);
		Vector3 vectorTripleProduct(Vector3 b, Vector3 c);
		Vector3 normalize();
		Vector3 inverse();

		float magnitude();
		float distance(Vector3 vector);
		float dot(Vector3 vector);
		float angleTo(Vector3 vector);
		float projectOn(Vector3 vector);
		float triangleArea(Vector3 vector);
		float parallelogramArea(Vector3 vector);
		float scalarTripleProduct(Vector3 b, Vector3 c);
		float pyramidVolume(Vector3 b, Vector3 c);

		vector<float> directions();

		bool collinear(Vector3 vector);
		bool orthogonal(Vector3 vector);
		bool coplanar(Vector3 b, Vector3 c);

		float getX();
		float getY();
		float getZ();

	private:

		float x;
		float y;
		float z;

	};
}

#endif