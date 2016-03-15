#define _USE_MATH_DEFINES

#include "Vector3.h"
#include <math.h>

// @author Jacob Doiron
// @since 03/08/16

namespace LinearMath {

	Vector3::Vector3(float x, float y, float z) :
		x(x),
		y(y),
		z(z) {
	}

	// adds one vector to another
	Vector3 Vector3::operator+(Vector3 vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	}

	// subtracts one vector from another
	Vector3 Vector3::operator-(Vector3 vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	}

	// multiplies one vector by another
	Vector3 Vector3::operator*(Vector3 vector) {
		return Vector3(x * vector.x, y * vector.y, z * vector.z);
	}
	
	// divides one vector by another
	Vector3 Vector3::operator/(Vector3 vector) {
		return Vector3(x / vector.x, y / vector.y, z / vector.z);
	}

	// checks for equality among two vectors
	bool Vector3::operator==(Vector3 vector) {
		return x == vector.x && y == vector.y && z == vector.z;
	}

	// checks for inequality among two vectors
	bool Vector3::operator!=(Vector3 vector) {
		return x != vector.x || y != vector.y || z != vector.z;
	}

	// scales the source vector by the given scalar
	Vector3 Vector3::scale(float scalar) {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	// finds the cross product of two vectors in Cartesian coordinates
	Vector3 Vector3::cross(Vector3 vector) {
		float i = (y * vector.z) - (z * vector.y);
		float j = (z * vector.x) - (x * vector.z);
		float k = (x * vector.y) - (y * vector.x);
		return Vector3(i, j, k);
	}

	// linearly interpolates two vectors, given a scalar
	Vector3 Vector3::lerp(Vector3 vector, float scalar) {
		return (*this).scale(1 - scalar) + vector.scale(scalar);
	}

	// calculates the reflection vector using a velocity and normal vector
	Vector3 Vector3::reflect(Vector3 normal) {
		return (*this) - (normal.scale(-2 * (*this).dot(normal)));
	}

	// converts Cartesian coordinates to polar coordinates
	// false to get degrees, true to get theta as radians
	Vector3 Vector3::toPolar(bool radians) {
		float x1 = sqrtf(powf(x, 2) + powf(y, 2));
		float y1 = atan2f(y, x);
		return radians ? Vector3(x1, y1, z) : Vector3(x1, (y1 * 180) / M_PI, z);
	}

	// converts polar coordinates to Cartesian coordinates
	// false to get degrees, true to get coordinates as radians
	Vector3 Vector3::toCartesian(bool radians) {
		float x1 = x * cosf(radians ? y : (y * M_PI) / 180);
		float y1 = x * sinf(radians ? y : (y * M_PI) / 180);
		return Vector3(x1, y1, z);
	}

	// finds the component form, given an initial and terminal vector
	Vector3 Vector3::componentForm(Vector3 terminal) {
		return Vector3(terminal.getX() - x, terminal.getY() - y, terminal.getZ() - z);
	}

	// finds the vector triple product of three vectors, which equals a x [b x c]
	Vector3 Vector3::vectorTripleProduct(Vector3 b, Vector3 c) {
		return (*this).cross(b.cross(c));
	}

	// normalizes the source vector to a unit vector
	Vector3 Vector3::normalize() {
		float magnitude = (*this).magnitude();
		return Vector3(x / magnitude, y / magnitude, z / magnitude);
	}

	// inverts the source vector
	Vector3 Vector3::inverse() {
		return Vector3(-x, -y, -z);
	}

	// finds the magnitude (length) of the source vector
	float Vector3::magnitude() {
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	// finds the euclidean distance between two vectors
	float Vector3::distance(Vector3 vector) {
		return sqrtf(powf(x - vector.x, 2) + powf(y - vector.y, 2) + powf(z - vector.z, 2));
	}

	// finds the dot product of two vectors, producing a scalar
	float Vector3::dot(Vector3 vector) {
		return (x * vector.x) + (y * vector.y) + (z * vector.z);
	}

	// finds the angle between two vectors
	// false to get degrees, true to get radians
	float Vector3::angleTo(Vector3 vector, bool radians) {
		float dot = (*this).normalize().dot(vector.normalize());
		return radians ? acosf(dot) : acosf(dot) * 180 / M_PI;
	}

	// finds the projection of the given vector on the source vector
	float Vector3::projectOn(Vector3 vector) {
		return (*this).dot(vector) / vector.magnitude();
	}

	// finds the area of the triangle that two vectors form
	float Vector3::triangleArea(Vector3 vector) {
		return 0.5 * (*this).cross(vector).magnitude();
	}

	// finds the area of the parallelogram that two vectors form
	float Vector3::parallelogramArea(Vector3 vector) {
		return (*this).cross(vector).magnitude();
	}

	// finds the scalar triple product of three vectors, which equals the cross product [a x b] multiplied by vector c as the dot product
	float Vector3::scalarTripleProduct(Vector3 b, Vector3 c) {
		return (*this).dot(b.cross(c));
	}

	// finds the volume of the pyramid that three vectors form
	float Vector3::pyramidVolume(Vector3 b, Vector3 c) {
		return (1.0 / 6) * scalarTripleProduct(b, c);
	}

	// finds the direction cosines that the source vector forms with the coordinate axes
	vector<float> Vector3::directions() {
		vector<float> directions;
		directions.resize(3);
		float magnitude = (*this).magnitude();
		directions[0] = x / magnitude;
		directions[1] = y / magnitude;
		directions[2] = z / magnitude;
		return directions;
	}

	// checks if two vectors are collinear, given their relations are equal
	bool Vector3::collinear(Vector3 vector) {
		float x1 = x / vector.x;
		float y1 = y / vector.y;
		float z1 = z / vector.z;
		return x1 == y1 && y1 == z1;
	}

	// checks if two vectors are orthogonal, given their dot product is 0
	bool Vector3::orthogonal(Vector3 vector) {
		return (*this).dot(vector) == 0;
	}

	// checks if three vectors are coplanar, given their triple product is 0
	bool Vector3::coplanar(Vector3 b, Vector3 c) {
		return scalarTripleProduct(b, c) == 0;
	}

	// returns the source vector's x coordinate
	float Vector3::getX() {
		return x;
	}

	// returns the source vector's y coordinate
	float Vector3::getY() {
		return y;
	}

	// returns the source vector's z coordinate
	float Vector3::getZ() {
		return z;
	}
}