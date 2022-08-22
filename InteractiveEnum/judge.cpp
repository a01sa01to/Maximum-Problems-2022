#include "validate.h"

#include <random>
#include <vector>
using namespace std;

struct BIT {
  public:
  BIT(): _n(0) {}
  BIT(int n): _n(n), data(n) {}
  void add(int i, int x) {
    i++;
    while (i <= _n) {
      data[i - 1] += x;
      i += i & -i;
    }
  }
  int sum(int l, int r) { return sum(r) - sum(l); }

  private:
  int _n;
  vector<int> data;
  int sum(int r) {
    int s = 0;
    while (r > 0) {
      s += data[r - 1];
      r -= r & -r;
    }
    return s;
  }
};

inline int randInt(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r - 1);
  return dist(mt);
}

int main(int argc, char* argv[]) {
  init_io(argc, argv);

  // N の出力
  int n;
  assert(judge_in >> n);
  cout << n << endl;

  // BIT 構築
  BIT bit(n);
  for (int i = 0; i < n; i++) bit.add(i, 1);

  // Interactive
  int q = 0;
  while (true) {
    q++;
    // 答え入力
    int ans;
    if (!(author_out >> ans)) {
      wrong_answer("Turn %d: No output\n", q);
    }
    if (ans <= 0 || ans > n) {
      wrong_answer("Turn %d: Out of range (%d, where n = %d)\n", q, ans, n);
    }
    // 存在チェック
    if (bit.sum(ans - 1, ans) == 0) {
      wrong_answer("Turn %d: Already used\n", q);
    }
    bit.add(ans - 1, -1);

    // Output
    int size = bit.sum(0, n);
    if (size == 0) {
      cout << 0 << endl;
      break;
    }
    int next_i = randInt(1, size);
    int ok = n, ng = 0;
    while (ok - ng > 1) {
      int mid = (ok + ng) / 2;
      (bit.sum(0, mid) >= next_i ? ok : ng) = mid;
    }
    assert(bit.sum(0, ok) == next_i);
    bit.add(ok - 1, -1);
    cout << ok << endl;
  }

  // 余計な出力確認
  string trash;
  if (author_out >> trash) {
    wrong_answer("Extra output: %s\n", trash.c_str());
  }
  accept();
}
