#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, mn[100][100];
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mn[i][j];

	vector<int> stack;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			stack.push_back(mn[j][i - j]);

		sort(stack.begin(), stack.end(), greater<int>());

		for (int j = 0; j < i + 1; j++)
			mn[j][i - j] = stack[j];

		stack.clear();
	}

	/*second half processing*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mn[i][j] << ' ';
		
		cout << '\n';
	}
}
