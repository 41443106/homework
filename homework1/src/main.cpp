#include<iostream> 

using namespace std;

int Ackermann(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	else if (n == 0) {
		return Ackermann(m - 1, n);
	}
	else {
		return Ackermann(m - 1, Ackermann(m, n - 1));
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << Ackermann(m, n) << endl;
}