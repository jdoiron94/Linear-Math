#include "Matrix.h"

// @author Jacob Doiron
// @since 03/14/16

namespace LinearMath {

	Matrix::Matrix(vector<vector<float>> vec) :
		vec(vec),
		rows(vec.size()),
		columns(vec[0].size()) {
	}

	// adds given matrix to source matrix
	Matrix Matrix::operator+(Matrix matrix) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				matrix.vec[row][col] = vec[row][col] + matrix.vec[row][col];
			}
		}
		return Matrix(matrix.vec);
	}

	// subtracts given matrix from source matrix
	Matrix Matrix::operator-(Matrix matrix) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				matrix.vec[row][col] = vec[row][col] - matrix.vec[row][col];
			}
		}
		return Matrix(matrix.vec);
	}

	// multiplies source matrix by given matrix
	Matrix Matrix::operator*(Matrix matrix) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				matrix.vec[row][col] = vec[row][col] * matrix.vec[row][col];
			}
		}
		return Matrix(matrix.vec);
	}

	// divides source matrix to given matrix
	Matrix Matrix::operator/(Matrix matrix) {
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				matrix.vec[row][col] = vec[row][col] / matrix.vec[row][col];
			}
		}
		return Matrix(matrix.vec);
	}

	// checks if two matrices are equal
	bool Matrix::operator==(Matrix matrix) {
		return rows == matrix.rows && columns == matrix.columns && vec == matrix.vec;
	}

	// checks if two matrices are different
	bool Matrix::operator!=(Matrix matrix) {
		return rows != matrix.rows || columns != matrix.columns || vec != matrix.vec;
	}

	// scales the source matrix by the given scalar
	Matrix Matrix::scale(float scalar) {
		vector<vector<float>> result = vec;
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				result[row][col] = vec[row][col] * scalar;
			}
		}
		return Matrix(result);
	}

	// raises the matrix to the given power
	Matrix Matrix::pow(int power) {
		vector<vector<float>> result = vec;
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < columns; col++) {
				result[row][col] = powf(vec[row][col], power);
			}
		}
		return Matrix(result);
	}

	// transposes (inverts) the source matrix
	Matrix Matrix::transpose() {
		vector<vector<float>> result;
		result.resize(columns);
		for (int col = 0; col < columns; col++) {
			vector<float> data;
			data.resize(rows);
			for (int row = 0; row < rows; row++) {
				data[row] = vec[row][col];
			}
			result[col] = data;
		}
		return Matrix(result);
	}

	// returns the source matrix's vector
	vector<vector<float>> Matrix::getVector() {
		return vec;
	}

	// returns the source matrix's row count
	int Matrix::getRows() {
		return rows;
	}

	// returns the source matrix's column count
	int Matrix::getColumns() {
		return columns;
	}
}