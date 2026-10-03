#include <iostream>

using namespace std;

// 1. »¼°jª©¥»
long long ackermann_recursive(long long m, long long n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ackermann_recursive(m - 1, 1);
    }
    else {
        return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1));
    }
}

// 2. «D»¼°jª©¥»
long long ackermann_non_recursive(long long m, long long n) {
    long long s[100000];
    int top = 0;

    s[top++] = m;

    while (top > 0) {
        m = s[--top];

        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            s[top++] = m - 1;
            n = 1;
        }
        else {
            s[top++] = m - 1;
            s[top++] = m;
            n = n - 1;
        }
    }
    return n;
}

int main() {
    long long  m, n;
    cin >> m >> n;
    cout << "Recursive A(" << m << ", " << n << ") = " << ackermann_recursive(m, n) << endl;
    cout << "Non-Recursive A(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}