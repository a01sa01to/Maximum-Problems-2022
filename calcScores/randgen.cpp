#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

inline int randint(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}

int main() {
  int t = randint(1, 100);
  cout << t << endl;
  rep(_, t) {
    int n = randint(1, 10000);
    cout << n << "\n";
    cerr << "\r" << _ + 1 << " / " << t << ": " << n << flush;
    rep(__, n) {
      int a = randint(0, 100);
      int b = randint(0, 100);
      int c = randint(0, 100);
      cout << a << " " << b << " " << c << "\n";
    }
  }
  cerr << "\r" << flush;
}