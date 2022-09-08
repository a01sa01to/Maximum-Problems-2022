#include <bits/stdc++.h>
using namespace std;

inline int randint(int l, int r) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(l, r);
  return dis(gen);
}

int main() {
  int n = 1e6;
  // int n = 1e6;
  // int m = randint(1, n);
  int m = 1;
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    int ch = randint(0, 2);
    if (ch == 0) {
      printf("%c", randint('a', 'z'));
    }
    else if (ch == 1) {
      printf("%c", randint('A', 'Z'));
    }
    else {
      printf("%c", randint('0', '9'));
    }
  }
  // cout << s;
  printf("\n");
  // cout << s << endl;
  for (int i = 0; i < m; i++) {
    int ch = randint(0, 2);
    if (ch == 0) {
      printf("%c", randint('a', 'z'));
    }
    else if (ch == 1) {
      printf("%c", randint('A', 'Z'));
    }
    else {
      printf("%c", randint('0', '9'));
    }
  }
  printf("\n");
  return 0;
}