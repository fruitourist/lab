#include <iostream>
/*#include <vector>*/

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

/*decision vector*/

int enum(int n) {
  	
        /*decision processing*/
        
        int s = 0;
        while (n != 0) {

	    if (!isPrime(n))
		    n = special(n); //min b from n = a * b: 1 < a <= b
            else
		    n--;
            
            s++;
        }
	
	return s;
}

int main() {
	cout << enum(4) << '\n' << enum(7);
}

/*int main() {
	int q;
	cin >> q;

	int n;
  	vector<int> answer;
	for (int i = 0; i < q; i++) {
		cin >> n;
		a[i] = enum(n);
	}

	for (int i = 0; i < q; i++)
		cout << a[i] << '\n';
}*/
