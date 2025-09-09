#include <iostream>
#include <fstream>

using namespace std;

class Matrix {
private:
	int rows_ = 0;
	int cols_ = 0;
	int** data_ = nullptr; // динамический 2D-массив

	void allocate(int r, int c) {
		if (r <= 0 || c <= 0) { rows_ = cols_ = 0; data_ = nullptr; return; }
		rows_ = r; cols_ = c;
		data_ = new int*[rows_];
		for (int i = 0; i < rows_; ++i) {
			data_[i] = new int[cols_];
			for (int j = 0; j < cols_; ++j) data_[i][j] = 0;
		}
	}

	void clear() {
		if (!data_) { rows_ = cols_ = 0; return; }
		for (int i = 0; i < rows_; ++i) delete[] data_[i];
		delete[] data_;
		data_ = nullptr; rows_ = cols_ = 0;
	}

public:
	Matrix() = default;
	Matrix(int r, int c) { allocate(r, c); }
	// Конструктор: размеры + заполнение случайными числами в диапазоне [lo; hi]
	Matrix(int r, int c, int lo, int hi) {
		if (lo > hi) { int t = lo; lo = hi; hi = t; }
		allocate(r, c);
		// Заполняем псевдослучайными числами без дополнительных заголовков
		// Детерминированная формула на основе позиции (i,j)
		unsigned int span = (unsigned int)(hi - lo + 1);
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				unsigned int idx = (unsigned int)(i * cols_ + j + 1);
				unsigned int s = 1103515245u * idx + 12345u;
				int val = lo + (int)(((s >> 16) % span));
				data_[i][j] = val;
			}
		}
	}
	~Matrix() { clear(); }

	// Копирование
	Matrix(const Matrix& other) { allocate(other.rows_, other.cols_); for (int i=0;i<rows_;++i) for (int j=0;j<cols_;++j) data_[i][j]=other.data_[i][j]; }
	Matrix& operator=(const Matrix& other) {
		if (this == &other) return *this;
		Matrix tmp(other);
		// ручной swap без <utility>
		int** tdata = data_; data_ = tmp.data_; tmp.data_ = tdata;
		int t = rows_; rows_ = tmp.rows_; tmp.rows_ = t;
		t = cols_; cols_ = tmp.cols_; tmp.cols_ = t;
		return *this;
	}

	// Перемещение
	Matrix(Matrix&& other) noexcept {
		rows_ = other.rows_; cols_ = other.cols_; data_ = other.data_;
		other.rows_ = other.cols_ = 0; other.data_ = nullptr;
	}
	Matrix& operator=(Matrix&& other) noexcept {
		if (this == &other) return *this;
		clear();
		rows_ = other.rows_; cols_ = other.cols_; data_ = other.data_;
		other.rows_ = other.cols_ = 0; other.data_ = nullptr;
		return *this;
	}

	int rows() const { return rows_; }
	int cols() const { return cols_; }

	// Доступ к элементам
	int* operator[](int r) { return data_[r]; }
	const int* operator[](int r) const { return data_[r]; }

	void fill(int value) {
		for (int i = 0; i < rows_; ++i)
			for (int j = 0; j < cols_; ++j)
				data_[i][j] = value;
	}

	void print(ostream& os = cout) const {
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				os << data_[i][j] << (j + 1 == cols_ ? '\n' : ' ');
			}
		}
	}

	// Простой ввод/вывод в файл через fstream
	bool saveToFile(const char* filename) const {
		ofstream out(filename);
		if (!out) return false;
		out << rows_ << ' ' << cols_ << '\n';
		for (int i = 0; i < rows_; ++i) {
			for (int j = 0; j < cols_; ++j) {
				out << data_[i][j] << (j + 1 == cols_ ? '\n' : ' ');
			}
		}
		return true;
	}

	bool loadFromFile(const char* filename) {
		ifstream in(filename);
		if (!in) return false;
		int r, c;
		if (!(in >> r >> c)) return false;
		Matrix tmp(r, c);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (!(in >> tmp.data_[i][j])) tmp.data_[i][j] = 0;
		*this = static_cast<Matrix&&>(tmp);
		return true;
	}

};


// Перегрузка операторов вывода/ввода
ostream& operator<<(ostream& os, const Matrix& m) {
	os << m.rows() << ' ' << m.cols() << '\n';
	for (int i = 0; i < m.rows(); ++i) {
		for (int j = 0; j < m.cols(); ++j) {
			os << m[i][j] << (j + 1 == m.cols() ? '\n' : ' ');
		}
	}
	return os;
}

istream& operator>>(istream& is, Matrix& m) {
	int r, c;
	if (!(is >> r >> c)) return is;
	if (r <= 0 || c <= 0) { m = Matrix(); return is; }
	Matrix tmp(r, c);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (!(is >> tmp[i][j])) {
				is.setstate(ios::failbit);
				return is;
			}
		}
	}
	m = static_cast<Matrix&&>(tmp);
	return is;
}


int main() {
	Matrix a(3, 4, -10, 10);
	cout << "Matrix a via operator<<:" << '\n' << a;

	ofstream fout("matrix.txt");
	if (fout) fout << a;
	fout.close();

	ifstream fin("matrix.txt");
	Matrix b;
	if (fin) fin >> b;
	cout << "\nMatrix b (loaded from file via operator>>):" << '\n' << b;

	return 0;
}