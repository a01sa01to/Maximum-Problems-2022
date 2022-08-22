#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) { s.insert(i); }
  while (true) {
    cout << *s.begin() << endl;
    s.erase(s.begin());
    int x;
    cin >> x;
    if (x == 0) break;
    s.erase(x);
  }
  return 0;
}