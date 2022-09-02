#include <bits/stdc++.h>
using namespace std;

inline int randint(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}

int main() {
  int n = 200000;
  cout << n << "\n";
  for (int i = 0; i < n - 1; i++) {
    printf("INSERT %d\n", i);
  }
  printf("MEX 0\n");
}