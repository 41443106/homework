# Homework 1 - Problem 1: Ackermann 函數

## 1. 解題
### 問題描述
Ackermann 函數 $A(m, n)$ 是一個經典的數學函數，其數值在 $m$ 和 $n$ 較小的時候成長極快。其數學定義如下：
- 若 $m = 0$，則 $A(m, n) = n + 1$
- 若 $n = 0$，則 $A(m, n) = A(m - 1, 1)$
- 其他情況，則 $A(m, n) = A(m - 1, A(m, n - 1))$

### 解題策略
1. **遞迴版本**：直接依照數學定義進行遞迴呼叫。
2. **非遞迴版本**：由於不能使用標準庫的 `<stack>`，因此自行宣告固定大小的陣列來模擬堆疊行為，透過迴圈與指標來動態追蹤 $m$ 與 $n$ 的數值變化，避免過深遞迴導致 Stack Overflow。

## 2. 程式實作
以下為本次作業的完整程式碼：

```cpp
#include <iostream>

using namespace std;

// 1. 遞迴版本
long long ackermann_recursive(long long m, long long n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann_recursive(m - 1, 1);
    } else {
        return ackermann_recursive(m - 1, ackermann_recursive(m, n - 1));
    }
}

// 2. 非遞迴版本（使用陣列手刻堆疊模擬）
long long ackermann_non_recursive(long long m, long long n) {
    long long s[100000];
    int top = 0;
    
    s[top++] = m;
    
    while (top > 0) {
        m = s[--top];
        
        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            s[top++] = m - 1;
            n = 1;
        } else {
            s[top++] = m - 1;
            s[top++] = m;
            n = n - 1;
        }
    }
    return n;
}

int main() {
    long long m = 3, n = 2;
    cout << "Recursive A(" << m << ", " << n << ") = " << ackermann_recursive(m, n) << endl;
    cout << "Non-Recursive A(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}
```
