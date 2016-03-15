#ifndef Matrix_H
#define Matrix_H

#include <vector>

using std::vector;

#pragma once

// @author Jacob Doiron
// @since 03/14/16

namespace LinearMath {

	class Matrix {

	public:

		Matrix(vector<vector<float>> vec);

		Matrix operator+(Matrix matrix);
		Matrix operator-(Matrix matrix);
		Matrix operator*(Matrix matrix);
		Matrix operator/(Matrix matrix);
		bool operator==(Matrix matrix);
		bool operator!=(Matrix matrix);

		Matrix scale(float scalar);
		Matrix pow(int power);
		Matrix transpose();

		vector<vector<float>> getVector();

		int getRows();
		int getColumns();

	private:

		vector<vector<float>> vec;

		int rows;
		int columns;
	};
}

#endif