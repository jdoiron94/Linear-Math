#include "Vector3.h"
#include "Matrix.h"
#include <iostream>

// @author Jacob Doiron
// @since 03/08/16

using std::cout;
using LinearMath::Vector3;
using LinearMath::Matrix;

void printMatrix(Matrix matrix) {
	vector<vector<float>> vec = matrix.getVector();
	for (int i = 0; i < vec.size(); i++) {
		vector<float> row = vec[i];
		for (int j = 0; j < row.size(); j++) {
			std::cout << row[j];
		}
		std::cout << std::endl;
	}
}

int main(void) {
	/*Vector3 a = Vector3(1, 1, 1);
	Vector3 b = Vector3(5, 5, 5);
	Vector3 c = a + b;
	std::cout << "Addition: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	c = a - b;
	std::cout << "Subtraction: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	c = a * b;
	std::cout << "Multiplication: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	c = a / b;
	std::cout << "Division: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	c = Vector3(3, 2, -1);
	c = c.normalize();
	std::cout << "Normalization: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	std::cout << "Magnitude: " << a.magnitude() << std::endl;
	std::cout << "Dot: " << a.dot(b) << std::endl;
	c = a.cross(b);
	std::cout << "Cross: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	std::cout << "Angle: " << a.angleTo(b, true) << std::endl;
	std::cout << "Projection: " << a.projectOn(b) << std::endl;
	std::cout << "Collinear: " << a.collinear(b) << std::endl;
	std::cout << "Orthogonal: " << a.orthogonal(b) << std::endl;
	std::cout << "Triangle area: " << a.triangleArea(b) << std::endl;
	std::cout << "Parallelogram area: " << a.parallelogramArea(b) << std::endl;
	c = a.componentForm(b);
	std::cout << "Component form: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	a = Vector3(1, 2, 3);
	c = Vector3(9, 9, 5);
	std::cout << "Scalar triple product: " << a.scalarTripleProduct(b, c) << std::endl;
	Vector3 d = a.vectorTripleProduct(b, c);
	std::cout << "Vector triple product: " << d.getX() << ", " << d.getY() << ", " << d.getZ() << std::endl;
	std::cout << "Pyramid area: " << a.pyramidVolume(b, c) << std::endl;
	a = Vector3(1, 2, 3);
	vector<float> directions = a.directions();
	std::cout << "Cos Directions: " << directions[0] << ", " << directions[1] << ", " << directions[2] << std::endl;
	c = Vector3(9, 9, 9);
	std::cout << "Coplanar: " << a.coplanar(b, c) << std::endl;
	a = Vector3(1, 1, 1);
	c = a.scale(5);
	std::cout << "C: (" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")" << std::endl;
	std::cout << "B == C: " << (b == c) << std::endl;
	std::cout << "B != C: " << (b != c) << std::endl;
	a = Vector3(1, 1, 6);
	c = a.cross(b);
	std::cout << "Cross: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	c = b.toPolar(false);
	std::cout << "Polar: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;
	b = Vector3(5, 60, 0);
	c = b.toCartesian(true);
	std::cout << "Cartesian: " << c.getX() << ", " << c.getY() << ", " << c.getZ() << std::endl;*/
	/*vector<float> vec1;
	vec1.resize(25);
	vec1[20] = 1;
	Matrix mat1 = Matrix(vec1, 5, 5);
	printMatrix(mat1);
	vector<float> vec2;
	vec2.resize(25);
	std::fill(vec2.begin(), vec2.end(), 5);
	Matrix mat2 = Matrix(vec2, 5, 5);
	Matrix mat3 = mat1 + mat2;
	std::cout << std::endl;
	printMatrix(mat3);
	Matrix mat4 = Matrix(vec1, 5, 5);
	std::cout << "== test: " << (mat1 == mat4) << std::endl;*/
	vector<vector<float>> vec1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	Matrix mat1 = Matrix(vec1);
	Matrix mat2 = mat1.transpose();
	printMatrix(mat2);
	std::cin.get();
    return 0;
}
