#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

bool isPrime(int n) {
	if (n <= 1)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

int special(int n) {
	if (sqrt(n) == (int)sqrt(n))
		return sqrt(n);

	int p = 1;
	for (int m = 2; m < n / 2; m++)
		if (n % m == 0)
			if (n / m != n / p)
				p = n / m;
			else
				return p;
}

map<int, int> decision;

int enumeration(int n) {
	int on = n;

	vector<int> trajectory;

	while (n != 0) {

		if (decision[n]) {
			int spell = decision[n];
			for (int i = 0; i < (int)trajectory.size(); i++)
				decision[trajectory[i]] += spell;

			return decision[on];
		}
		else
			trajectory.push_back(n);

		if (!isPrime(n) && n != 1)
			n = special(n); //min b from n = a * b: 1 < a <= b
		else
			n--;

		//spelling
		for (int i = 0; i < (int)trajectory.size(); i++)
			decision[trajectory[i]]++;
	}

	return decision[on];
}

int main() {
	int q;
	cin >> q;

	int n;
	vector<int> answer;
	for (int i = 0; i < q; i++) {
		cin >> n;
		answer.push_back(enumeration(n));
	}

	for (int i = 0; i < q; i++)
		cout << answer[i] << '\n';
}
