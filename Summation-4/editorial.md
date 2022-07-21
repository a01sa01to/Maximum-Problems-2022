# Summation 4

## 問題概要

$A+B+C+D$ の値を出力する。

## 解説

問題文の通り、 $A+B+C+D$ の値を出力すればよい。

しかし、制約に注目してみてほしい。
$|A|\le{10}^{9}$ である（ $B,C,D$ についても同様）。
よって、答えの最大値は $4 \times {10}^{9}$ となり、C++での `int` 型にはおさまらない。
したがって、C++では `long long` 型を使うことが必要である。

## 実装例（C++）

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a + b + c + d << endl;
  return 0;
}
```