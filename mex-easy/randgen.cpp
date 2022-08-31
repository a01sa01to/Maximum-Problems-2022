#include <bits/stdc++.h>
using namespace std;

inline int randint(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}

int main() {
  int n = 100000;
  cout << n << "\n";
  int a = randint(0, 100000);
  vector<int> used(n);
  for (int i = 0; i < a; i++) used[i] = i;
  for (int i = a; i < n; i++) {
    used[i] = randint(0, 1000000000);
  }
  for (int i = 0; i < n; i++) {
    int j = randint(0, n - 1);
    swap(used[i], used[j]);
  }
  for (int i = 0; i < n; i++) {
    cout << used[i] << (i < n - 1 ? " " : "\n");
  }
}