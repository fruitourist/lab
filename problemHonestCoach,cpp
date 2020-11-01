#include <iostream>
#include <vector>

using namespace std;

int match[2][50];
int enumeration(vector<int> s, bool command, int position, int n) {
	for (int i = (int)s.size() - 1; i >= 0; i--) { //for vector specific
		match[command][position] = s[i];
		s.pop_back();

		if ((int)s.size() == 0) {
			/*wighting processing*/
		}

		//command handling
		if (position + 1 > n / 2) {
			command = 1;
			position = -1;
		}
		
		return enumeration(s, command, position + 1, n);
	}
}

int main() {
	int t, n;
	cin >> t;
	
	vector<int> s; int sj;
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		for (int j = 0; j < n; j++) {
			cin >> sj;
			s.push_back(sj);
		}

		cout << enumeration(s, 0, 0, n);

		s.clear();
	}
}
