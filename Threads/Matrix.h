#pragma once
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

class Matrix {
	int rows, cols;
	int** data;
public:
	Matrix() :rows(0), cols(0), data(nullptr) {}
	Matrix(int r, int c) : rows(r), cols(c) {
		allocate();
		fillrandom();
	}
	~Matrix() {
		deallocate();
	}

	Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
		allocate();
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				data[i][j] = other.data[i][j];
	}
	Matrix& operator=(const Matrix& other) {
		if (this != &other) {
			deallocate();
			rows = other.rows;
			cols = other.cols;
			allocate();
			for (int i = 0; i < rows; ++i)
				for (int j = 0; j < cols; ++j)
					data[i][j] = other.data[i][j];
		}
		return *this;
	}
	friend istream& operator>>(istream& in, Matrix& m) {
		cout << "Enter rows and cols: ";
		in >> m.rows >> m.cols;
		m.deallocate();
		m.allocate();
		m.fillRandom();
		return in;
	}

	friend ostream& operator<<(ostream& out, const Matrix& m) {
		for (int i = 0; i < m.rows; ++i) {
			for (int j = 0; j < m.cols; ++j)
				out << m.data[i][j] << " ";
			out << endl;
		}
		return out;
	}

	friend ifstream& operator>>(ifstream& in, Matrix& m) {
		string label;
		fin >> label >> m.cols >> label >> m.rows;
		m.deallocate();
		m.allocate();
		for (int i = 0; i < m.rows; ++i)
			for (int j = 0; j < m.cols; ++j)
				in >> m.data[i][j];
		return fin;
	}
	friend ofstream& operator<<(ofstream& out, const Matrix& m) {
		out << "cols " << m.cols << " rows " << m.rows << endl;
		for (int i = 0; i < m.rows; ++i) {
			for (int j = 0; j < m.cols; ++j)
				fout << m.data[i][j] << " ";
			fout << endl;
		}
		return fout;
	}

private: 
	void allocate() {
		if (rows <= 0 || cols <= 0) {
			data = nullptr;
			return;
		}
		data = new int* [rows];
		for (int i = 0; i < rows; ++i)
			data[i] = new int[cols];
	}

	void deallocate() {
		if (data) {
			for (int i = 0; i < rows; ++i)
				delete[] data[i];
			delete[] data;
			data = nullptr;
		}
	}
	void fillRandom() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 9);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
				data[i][j] = dist(gen);
	}
};