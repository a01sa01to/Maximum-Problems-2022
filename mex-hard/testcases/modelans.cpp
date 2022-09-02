#include <bits/stdc++.h>
using namespace std;

struct mex {
  private:
  set<pair<int, int>> s;

  public:
  mex() {
    s.insert({ INT_MIN, INT_MIN });
    s.insert({ INT_MAX, INT_MAX });
  }
  bool insert(int x) {
    auto nitr = s.lower_bound({ x + 1, x + 1 });
    auto itr = prev(nitr);
    auto [l, r] = *itr;
    auto [nl, nr] = *nitr;
    if (l <= x && x <= r) return false;
    if (r == x - 1) {
      if (nl == x + 1) {
        s.erase(itr);
        s.erase(nitr);
        s.insert({ l, nr });
      }
      else {
        s.erase(itr);
        s.insert({ l, x });
      }
    }
    else {
      if (nl == x + 1) {
        s.erase(nitr);
        s.insert({ x, nr });
      }
      else {
        s.insert({ x, x });
      }
    }
    return true;
  }
  bool erase(int x) {
    auto nitr = s.lower_bound({ x + 1, x + 1 });
    auto itr = prev(nitr);
    auto [l, r] = *itr;
    if (l > x) return false;
    if (l == x) {
      if (r == x) {
        s.erase(itr);
      }
      else {
        s.erase(itr);
        s.insert({ x + 1, r });
      }
    }
    else {
      if (r == x) {
        s.erase(itr);
        s.insert({ l, x - 1 });
      }
      else {
        s.erase(itr);
        s.insert({ l, x - 1 });
        s.insert({ x + 1, r });
      }
    }
    return true;
  }
  int get(int x = 0) {
    auto nitr = s.lower_bound({ x + 1, x + 1 });
    auto itr = prev(nitr);
    auto [l, r] = *itr;
    if (l <= x && x <= r) return r + 1;
    return x;
  }
};

int main() {
  int n;
  cin >> n;
  mex mx;
  while (n--) {
    char tmp[101];
    scanf("%100s", tmp);
    string s = tmp;
    int x;
    scanf("%d", &x);
    if (s == "INSERT") {
      assert(mx.insert(x));
    }
    else if (s == "ERASE") {
      assert(mx.erase(x));
    }
    else {
      printf("%d\n", mx.get(x));
    }
  }
}