#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
	int t; cin >> t;
 
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		
		vector<int> a(n);
		for (int& j : a)
			cin >> j;
		
		sort(a.begin(), a.end());
		
		int r = a[n - 1] - a[0];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				r = min(r, a[j] - a[i]);
		
		cout << r << '\n';
	}
 
	return 0;
}
