#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll randint(ll l, ll r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<ll> dist(l, r);
  return dist(mt);
}

int main() {
  // ll n = randint(4, 2000);
  ll n = 4;
  ll x = randint(1, 1e12);
  printf("%lld %lld\n", n, x);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) a[i] = randint(1, 1e12);
  a[0] = randint(1, x - 100);
  a[1] = randint(1, x - a[0] - 75);
  a[2] = randint(1, x - a[0] - a[1] - 50);
  a[3] = x - a[0] - a[1] - a[2];
  for (int _ = 0; _ < n; _++) {
    int i = randint(0, n - 1);
    int j = randint(0, n - 1);
    swap(a[i], a[j]);
  }
  for (int i = 0; i < n; i++) printf("%lld%c", a[i], " \n"[i == n - 1]);
}