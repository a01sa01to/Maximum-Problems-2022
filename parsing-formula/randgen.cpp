#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline int randint(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}

void generate(int d) {
  cerr << "\r" << d << flush;
  string s = "";
  ll res = 1;
  ll tmp = 0;
  string tm = "";
  constexpr ll INF = 1e9;
  int cnt = 0;
  while (s.size() + tm.size() <= 980) {
    const int op = randint(0, 3);
    const ll x = randint(0, INF);
    if (op == 0 && abs(tmp + x) <= INF) {
      tmp += x;
      tm += (tm.empty() ? "" : "+") + to_string(x);
    }
    if (op == 1 && abs(tmp - x) <= INF) {
      tmp -= x;
      tm += (tm.empty() ? "0-" : "-") + to_string(x);
    }
    if (op == 2 && abs(res * tmp) <= INF && tmp != 0) {
      res *= tmp;
      s += string(s.empty() ? "" : "*") + "(" + tm + ")";
      tm = "";
      tmp = 0;
    }
    if (op == 3 && tmp != 0 && res / tmp != 0 && !s.empty()) {
      res /= tmp;
      s += "/(" + tm + ")";
      tm = "";
      tmp = 0;
    }
  }
  if (!tm.empty() && tmp != 0 && res / tmp != 0) s += string(s.empty() ? "" : "/") + "(" + tm + ")";
  assert(s.size() <= 1000);
  printf("%s\n", s.c_str());
}

int main() {
  int n = 1000;
  cerr << n << endl;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) generate(i);
  cerr << "\r" << flush;
}