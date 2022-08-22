#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int t;
  cin >> t;
  rep(_, t) {
    int f;
    cin >> f;
    bool prev = false;
    rep(i, f) {
      cout << "READ " << i << endl;
      string s;
      cin >> s;
      if (prev && s == "false") {
        cout << "OUTPUT " << i - 1 << endl;
        break;
      }
      if (s == "true") prev = true;
      if (s == "false") prev = false;
    }
  }
}