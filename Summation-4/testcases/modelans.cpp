#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  constexpr ll INF = 1'000'000'000;
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  assert(-INF <= a && a <= INF);
  assert(-INF <= b && b <= INF);
  assert(-INF <= c && c <= INF);
  assert(-INF <= d && d <= INF);
  cout << a + b + c + d << endl;
  return 0;
}