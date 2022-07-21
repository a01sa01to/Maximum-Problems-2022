#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll rand_ll(ll l, ll r) {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> uid(l, r);
  return uid(rng);
}

int main() {
  ll INF;
  cin >> INF;
  printf("%lld %lld %lld %lld\n", rand_ll(-INF, INF), rand_ll(-INF, INF), rand_ll(-INF, INF), rand_ll(-INF, INF));
  return 0;
}