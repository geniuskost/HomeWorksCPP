#include <iostream>
#include <vector>
using namespace std;

static bool contains(const vector<int>& arr, int value) {
	for (int x : arr) if (x == value) return true;
	return false;
}

static int str_compare(const char* a, const char* b) {
	int i = 0;
	while (a[i] && b[i]) {
		if (a[i] != b[i]) return (a[i] > b[i]) ? 1 : -1;
		++i;
	}
	if (a[i] == b[i]) return 0;
	return (a[i] > b[i]) ? 1 : -1;
}

static void str_copy(char* dst, const char* src) {
	int i = 0;
	while (src[i]) { dst[i] = src[i]; ++i; }
	dst[i] = '\0';
}

void addColumn(vector<vector<int>>& matrix, int pos, int value) {
	for (int i = 0; i < matrix.size(); ++i) {
		if (pos >= 0 && pos <= matrix[i].size()) {
			vector<int> newRow;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (j == pos) newRow.push_back(value);
				newRow.push_back(matrix[i][j]);
			}
			if (pos == matrix[i].size()) newRow.push_back(value);
			matrix[i] = newRow;
		}
	}
}

void removeColumn(vector<vector<int>>& matrix, int col) {
	for (int i = 0; i < matrix.size(); ++i) {
		if (col >= 0 && col < matrix[i].size()) {
			vector<int> newRow;
			for (int j = 0; j < matrix[i].size(); ++j) {
				if (j != col) newRow.push_back(matrix[i][j]);
			}
			matrix[i] = newRow;
		}
	}
}

void shiftRows(vector<vector<int>>& matrix, int times, bool down) {
	int m = matrix.size();
	if (m == 0) return;
	times = times % m;
	for (int t = 0; t < times; ++t) {
		if (down) {
			vector<int> lastRow = matrix[m-1];
			for (int i = m-1; i > 0; --i) matrix[i] = matrix[i-1];
			matrix[0] = lastRow;
		} else {
			vector<int> firstRow = matrix[0];
			for (int i = 0; i < m-1; ++i) matrix[i] = matrix[i+1];
			matrix[m-1] = firstRow;
		}
	}
}

void shiftColumns(vector<vector<int>>& matrix, int times, bool right) {
	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();
	times = times % n;
	for (int t = 0; t < times; ++t) {
		if (right) {
			for (int i = 0; i < m; ++i) {
				int last = matrix[i][n-1];
				for (int j = n-1; j > 0; --j) matrix[i][j] = matrix[i][j-1];
				matrix[i][0] = last;
			}
		} else {
			for (int i = 0; i < m; ++i) {
				int first = matrix[i][0];
				for (int j = 0; j < n-1; ++j) matrix[i][j] = matrix[i][j+1];
				matrix[i][n-1] = first;
			}
		}
	}
}

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
	if (matrix.empty()) return vector<vector<int>>();
	int m = matrix.size(), n = matrix[0].size();
	vector<vector<int>> result(n, vector<int>(m));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			result[j][i] = matrix[i][j];
	return result;
}

struct Contact {
	char name[100];
	char phone[30];
};

void addContact(vector<Contact>& contacts, const char* name, const char* phone) {
	Contact c;
	int i = 0;
	while (name[i] && i < 99) { c.name[i] = name[i]; ++i; }
	c.name[i] = 0;
	i = 0;
	while (phone[i] && i < 29) { c.phone[i] = phone[i]; ++i; }
	c.phone[i] = 0;
	contacts.push_back(c);
}

int findByName(const vector<Contact>& contacts, const char* name) {
	for (int i = 0; i < contacts.size(); ++i) {
		int j = 0;
		while (contacts[i].name[j] == name[j] && name[j]) ++j;
		if (contacts[i].name[j] == 0 && name[j] == 0) return i;
	}
	return -1;
}

int findByPhone(const vector<Contact>& contacts, const char* phone) {
	for (int i = 0; i < contacts.size(); ++i) {
		int j = 0;
		while (contacts[i].phone[j] == phone[j] && phone[j]) ++j;
		if (contacts[i].phone[j] == 0 && phone[j] == 0) return i;
	}
	return -1;
}

void editContact(vector<Contact>& contacts, int idx, const char* name, const char* phone) {
	if (idx >= 0 && idx < contacts.size()) {
		int i = 0;
		while (name[i] && i < 99) { contacts[idx].name[i] = name[i]; ++i; }
		contacts[idx].name[i] = 0;
		i = 0;
		while (phone[i] && i < 29) { contacts[idx].phone[i] = phone[i]; ++i; }
		contacts[idx].phone[i] = 0;
	}
}

void inputAndSortNames() {
	char names[5][100];
	cout << "Введите 5 фамилий:\n";
	for (int i = 0; i < 5; ++i) cin >> names[i];
	for (int i = 0; i < 5; ++i)
		for (int j = i+1; j < 5; ++j)
			if (str_compare(names[i], names[j]) > 0) {
				char tmp[100];
				str_copy(tmp, names[i]);
				str_copy(names[i], names[j]);
				str_copy(names[j], tmp);
			}
	cout << "Отсортированные фамилии:\n";
	for (int i = 0; i < 5; ++i) cout << names[i] << endl;
}

vector<int> getCommon(const vector<vector<int>>& A, const vector<vector<int>>& B, const vector<vector<int>>& C) {
	vector<int> res;
	vector<int> a, b, c;
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[i].size(); ++j)
			if (!contains(a, A[i][j])) a.push_back(A[i][j]);
	for (int i = 0; i < B.size(); ++i)
		for (int j = 0; j < B[i].size(); ++j)
			if (!contains(b, B[i][j])) b.push_back(B[i][j]);
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			if (!contains(c, C[i][j])) c.push_back(C[i][j]);
	for (int i = 0; i < a.size(); ++i)
		if (contains(b, a[i]) && contains(c, a[i])) res.push_back(a[i]);
	return res;
}

vector<int> getUnique(const vector<vector<int>>& A, const vector<vector<int>>& B, const vector<vector<int>>& C) {
	vector<int> all, unique;
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[i].size(); ++j)
			all.push_back(A[i][j]);
	for (int i = 0; i < B.size(); ++i)
		for (int j = 0; j < B[i].size(); ++j)
			all.push_back(B[i][j]);
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			all.push_back(C[i][j]);
	for (int i = 0; i < all.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < all.size(); ++j)
			if (all[i] == all[j]) cnt++;
		bool seen = false;
		for (int k = 0; k < unique.size(); ++k) if (unique[k] == all[i]) { seen = true; break; }
		if (cnt == 1 && !seen) unique.push_back(all[i]);
	}
	return unique;
}

vector<int> getCommonAC(const vector<vector<int>>& A, const vector<vector<int>>& C) {
	vector<int> res, a, c;
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[i].size(); ++j)
			if (!contains(a, A[i][j])) a.push_back(A[i][j]);
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			if (!contains(c, C[i][j])) c.push_back(C[i][j]);
	for (int i = 0; i < a.size(); ++i)
		if (contains(c, a[i])) res.push_back(a[i]);
	return res;
}

vector<int> getNegativeUnique(const vector<vector<int>>& A, const vector<vector<int>>& B, const vector<vector<int>>& C) {
	vector<int> neg;
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[i].size(); ++j)
			if (A[i][j] < 0 && !contains(neg, A[i][j])) neg.push_back(A[i][j]);
	for (int i = 0; i < B.size(); ++i)
		for (int j = 0; j < B[i].size(); ++j)
			if (B[i][j] < 0 && !contains(neg, B[i][j])) neg.push_back(B[i][j]);
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			if (C[i][j] < 0 && !contains(neg, C[i][j])) neg.push_back(C[i][j]);
	return neg;
}