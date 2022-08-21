# Statistics Calculation

## 問題概要

数列に対して、最大値・最小値・平均値・標準偏差を出力する。また、標準偏差が100で割り切れる場合にはYes、そうでない場合にはNoと出力する。

## 解説

### 最大値と最小値
最大値・最小値は、for文で計算してもよいし、`max_element` 等の関数を用いてもよい。

### 平均値
まずは総和を求める。これはfor文で計算してもよいし、`accumulate` 等の関数を用いてもよい。<br>
次に、総和を要素数で割ることで平均値を求める。

割る際には、double型にキャストする必要があるので注意。

### 標準偏差
先ほど求めた平均値を用いて、for文で実際に計算し、最後にNで割ればよい。

### 100で割り切れるかどうか
標準偏差を $\sigma$ とする。このとき、 $\sigma \equiv 0 \pmod {100}$ かどうかを判定したい。
double型では、`%`演算子が定義されていないため、 `sd % 100` といったように判定することはできない。
そこで、式変形を行う。

1. まず、 $\sigma \equiv 0 \pmod {100}$ であるとき、整数 $x$ を用いて $\sigma = 100x$ 、つまり $\sigma \div 100 = x$ とおける。
2. 両辺を2乗する。 $\sigma^2 \div 10000 = x^2$
3. $\sigma$ の定義を戻す。 $\displaystyle \sigma^2 \div 10000 = \sum_{i=1}^N (a_i - \mu)^2 \div 10000N = x^2$

この形になれば、 $\mu$ が整数であることから、整数型で誤差なく $x^2$ が求められる。
$x$ が整数のとき、 $x^2$ は平方数であるから、ここで求めた $x^2$ が平方数であるかも確かめる必要がある。
少し手を動かして考えると、 $x$ の取りうる値は、制約から高々 $2 \times 10^5$ である [^1] から、 $x$ の値をfor文によって求めることができる。
なお、実際にはこの上限値をとることはない。

[^1]: $\displaystyle \sigma \le \frac{1}{N} \sum_{i=1}^N \left| a_i - \mu \right| \le \frac{1}{N} \sum_{i=1}^N \left( \max a_i - \min a_i \right) \le \frac{1}{N} \times N \times (2 \times 10^7)$ より $\sigma \le 2 \times 10^7$ となる。よって、 $x = \sigma \div 100 \le 2 \times 10^5$

この場合の計算量は $O(N + \max |a_i|)$ となる。
なお、 $x$ を二分探索などによって求めることにより、高速化できる。

## 実装例

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 最大値・最小値の計算
  ll maxim = *max_element(a.begin(), a.end());
  ll minim = *min_element(a.begin(), a.end());
  cout << maxim << endl;
  cout << minim << endl;

  // 平均値の計算
  ll avg = accumulate(a.begin(), a.end(), 0LL) / n;
  cout << avg << endl;

  // 分散×Nの計算
  ll var_n = 0;
  rep(i, n) var_n += (a[i] - avg) * (a[i] - avg);

  // 標準偏差の計算
  double sd = sqrt(double(var_n) / n);
  cout << fixed << setprecision(10) << sd << endl;

  // 標準偏差が100の倍数となるかの判定
  if (var_n % (10000 * n) == 0) {
    ll x = var_n / (10000 * n);
    for (ll i = 0; i <= 200000; i++) {
      // xが平方数
      if (i * i == x) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}
```