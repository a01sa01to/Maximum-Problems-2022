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
  ll avg = accumulate(a.begin(), a.end(), 0LL);
  assert(avg % n == 0);
  avg /= n;
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