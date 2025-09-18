#include <fstream>
#include "Matrix.h"

using namespace std;

int main() {
	Matrix m;

	cin >> m;

	cout << m;

	ofstream fout("matrix.txt");
	fout << m;
	fout.close();

	Matrix m2;
	ifstream fin("matrix.txt");
	fin >> m2;
	fin.close();

	cout << "Matrix read from file:\n" << m2;

	return 0;
}