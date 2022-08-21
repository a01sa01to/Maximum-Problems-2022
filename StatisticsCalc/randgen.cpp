#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll rand_ll(ll l, ll r) {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> uid(l, r);
  return uid(rng);
}

bool chk(int n, const vector<ll>& a) {
  // 平均値の計算
  ll avg = accumulate(a.begin(), a.end(), 0LL);
  if (avg % n != 0) return false;
  avg /= n;

  // 分散×Nの計算
  ll var_n = 0;
  rep(i, n) var_n += (a[i] - avg) * (a[i] - avg);

  // 標準偏差が100の倍数となるかの判定
  if (var_n % (10000 * n) == 0) {
    ll x = var_n / (10000 * n);
    for (ll i = 0; i <= 200000; i++) {
      // xが平方数
      if (i * i == x) {
        return true;
      }
    }
    return false;
  }
  else {
    return false;
  }
}

int main() {
  ll cnt = 0;
  set<vector<ll>> st;
  while (true) {
    cerr << ++cnt << "\r" << flush;
    ll n = rand_ll(3, 100);
    vector<ll> a(n);
    rep(i, n) a[i] = rand_ll(-1000, 1000) * 10000;
    sort(a.begin(), a.end());
    if (st.count(a)) continue;
    st.insert(a);
    if (chk(n, a)) {
      printf("%lld\n", n);
      rep(i, n) printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
      break;
    }
  }
  return 0;
}