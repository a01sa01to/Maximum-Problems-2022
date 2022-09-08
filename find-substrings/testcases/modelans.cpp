#include <climits>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct RollingHash {
  using ull = unsigned long long;

  public:
  static const ull Mod = (1LL << 61) - 1;
  ull base;
  RollingHash(const string &s, ull _base = 0) {
    if (_base == 0) {
      random_device rnd;
      mt19937 mt(rnd());
      uniform_int_distribution<ull> rand(128, INT_MAX);
      _base = rand(mt);
    }

    base = _base;
    powr.assign(1, 1);
    int n = s.size();
    hash.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      hash[i + 1] = mulMod(hash[i], base) + s[i];
      hash[i + 1] = getMod(hash[i + 1]);
    }
  }

  ull get(int l, int r) {
    ull res = hash[r] - mulMod(hash[l], getPow(r - l));
    return getMod(res + Positivizer);
  }

  private:
  static const ull Positivizer = 7 * Mod;
  vector<ull> hash;
  vector<ull> powr;
  ull getPow(int n) {
    while (powr.size() <= n) {
      powr.push_back(mulMod(powr.back(), base));
    }
    return powr[n];
  }

  ull mulMod(ull x, ull y) {
    __int128_t t = (__int128_t) x * y;
    t = (t >> 61) + (t & Mod);
    if (t >= Mod) t -= Mod;
    return (ull) t;
  }
  ull getMod(ull val) {
    val = (val & Mod) + (val >> 61);
    if (val >= Mod) val -= Mod;
    return val;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  string _s, _t;
  cin >> _s >> _t;
  RollingHash s(_s);
  RollingHash t(_t, s.base);
  vector<int> ans;
  for (int i = 0; i + m <= n; ++i) {
    if (s.get(i, i + m) == t.get(0, m)) {
      ans.push_back(i);
    }
  }
  printf("%zu\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
  }
  return 0;
}