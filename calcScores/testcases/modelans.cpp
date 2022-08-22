#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

void solve() {
  int n;
  cin >> n;
  pair<int, int> ans = { -1, -1 };
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c > ans.first) ans = { a + b + c, i };
  }
  cout << ans.second + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}