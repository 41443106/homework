# 41443106 

## 1. 解題說明
### 問題描述
- **第一題(Ackermann 函數):** 是一個的數學函數，需要在使用遞迴跟不使用$stack$來寫非遞迴版本。

- **第二題(冪集合):** 給定一個集合，找出其所有可能的子集組合，使用遞迴函數且不使用$stack$。


### 解題策略
 - **problem1- 遞迴版本：** 直接依照 $Ackermann$ 函數進行遞迴呼叫。
 
 - **problem1- 非遞迴版本：** 由於不能使用 $stack$ ，因此宣告固定大小的陣列來模擬堆疊行為，透過迴圈來看 $m$ 與 $n$ 的數值變化。

 - **problem2-** 透過不斷地選擇或不選每個元素來找出所有組合，當所有元素都做完決定時就輸出結果。


## 2. 程式實作
以下為本次作業的程式碼：

### problem1:
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

// 2. 非遞迴版本
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
    long long  m , n ;
    cin  >> m >> n ;
    cout << "Recursive A(" << m << ", " << n << ") = " << ackermann_recursive(m, n) << endl;
    cout << "Non-Recursive A(" << m << ", " << n << ") = " << ackermann_non_recursive(m, n) << endl;
    return 0;
}
```
### problem2:

```cpp
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
```
## 3. 效能分析
針對本次作業的程式碼進行 Big-O 分析：

 1. **時間複雜度:**
   - **Problem 1 (Ackermann 函數):** 計算量隨參數呈超指數級成長，時間複雜度為 $O(2^n)$。
   - **Problem 2 (Powerset 冪集):** 集合共有 $2^n$ 種子集組合，必須完整巡訪所有分支，所以時間複雜度為 $O(2^n)$。

 2. **空間複雜度:**
   - **Problem 1:** 使用固定大小的陣列模擬堆疊，空間複雜度取決於堆疊最大深度，為 $O(n)$。
   - **Problem 2:** 遞迴呼叫的深度最高為集合大小 $n$，空間複雜度為 $O(n)$。
  
## 4.測試與驗證

### 測試案例

 **problem1**

|  | 輸入參數 $m,n$ | 預期輸出 | 實際輸出(遞迴) | 實際輸出(非遞迴)|
|----------|--------------|----------|----------|-------------------  |
| 測試一   | $m = 1,n = 1$ | 3        | 3        |3                    |
| 測試二   | $m = 1,n = 0$ | 2        | 2        |2                    |
| 測試三   | $m = 0,n = 0$ | 1        | 1        |1                    |
| 測試四   | $m = 3,n = 2$ | 29       | 29       |29                   |
| 測試五   | $m = 3,n = 5$ | 253      | 253      |253                  |

 **problem2**

|  | 數量 | 輸入元素 | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|-------------------  |
| 測試一   | 3 | a b c |八個子集合 |{ }{ c }{ b }{ b c }{ a }{ a c }{ a b }{ a b c } |
| 測試二   | 2 | x y   |三個子集合  |{ }{ y }{ x }{ x y }|
| 測試三   | 0 |       |一個空子集合|{    }|

### 編譯與執行指令
 **problem1**
```shell
 $ g++ -std=c++17 -o problem1 src/problem1.cpp
 $ ./problem1
 3
 2
 Recursive A(3, 2) = 29
 Non-Recursive A(3, 2) = 29
 ```

**problem2**
```shell
 $ g++ -std=c++17 -o problem2 src/problem2.cpp
 $ ./problem2
 請輸入集合元素個數 n: 3
 請依序輸入 3 個字元: a b c
 結果如下:
 { }
 { c }
 { b }
 { b c }
 { a }
 { a c }
 { a b }
 { a b c }
 ```
## 5.申論及開發報告
 
- 實作 $Ackermann$ 函數時，遞迴的部分直接照著題目改寫遞回函數，相較非遞迴簡單，非遞迴因為不能使用 $stack$，要使用陣列來去堆疊，放入的數字要注意是先放外層，再放內層，才可以先算完內層。
 
- 實作 $Powerset$ 時，因為也不能使用 $satck$，所以利用選和不選，先做完內層之後再來做外層，達成每一種情況都會出現。