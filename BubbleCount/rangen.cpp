#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = int;

inline int randint(int l, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(l, r);
  return dist(mt);
}

pair<ll, vector<ll>> invNum(vector<ll> a) {
  ll n = a.size();
  if (n <= 1) return { 0, a };
  ll mid = n / 2;
  auto left = invNum(vector<ll>(a.begin(), a.begin() + mid));
  auto right = invNum(vector<ll>(a.begin() + mid, a.end()));
  vector<ll> res;
  ll inv = 0;
  inv += left.first + right.first;
  ll i = 0, j = 0;
  while (i < left.second.size() && j < right.second.size()) {
    if (left.second[i] < right.second[j]) {
      res.push_back(left.second[i]);
      i++;
    }
    else {
      res.push_back(right.second[j]);
      j++;
      inv += left.second.size() - i;
    }
  }
  while (i < left.second.size()) {
    res.push_back(left.second[i]);
    i++;
  }
  while (j < right.second.size()) {
    res.push_back(right.second[j]);
    j++;
  }
  return { inv, res };
}

int main(int argc, char* argv[]) {
  int n, m;
  n = randint(2, 1000);
  m = randint(0, 1000000);
  int x = randint(0, 1);
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  rep(_, 1000) {
    int i = randint(0, n - 1);
    int j = randint(0, n - 1);
    swap(a[i], a[j]);
  }
  m = invNum(a).first;
  cerr << x << endl;
  if (x) {
    m--;
  }
  cout << n << " " << m << endl;
  rep(i, n) cout << a[i] << (i == n - 1 ? "\n" : " ");
}