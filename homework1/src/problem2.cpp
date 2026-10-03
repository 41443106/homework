#include <iostream>

using namespace std;

// 遞迴印出所有子集
void printPowerset(char s[], int n, int i, char current[], int len) {
    // 走到最後一個元素時，直接印出目前的結果
    if (i == n) {
        cout << "{ ";
        for (int j = 0; j < len; j++) {
            cout << current[j] << " ";
        }
        cout << "}\n";
        return;
    }

    // 選擇 1：不要當前字元
    printPowerset(s, n, i + 1, current, len);

    // 選擇 2：要當前字元
    current[len] = s[i];
    printPowerset(s, n, i + 1, current, len + 1);
}

int main() {
    int n;
    cout << "請輸入集合元素個數 n: ";
    if (cin >> n) {
        char s[100];
        cout << "請依序輸入 " << n << " 個字元: ";
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        char current[100];
        cout << "\n結果如下:\n";
        printPowerset(s, n, 0, current, 0);
    }

    return 0;
}