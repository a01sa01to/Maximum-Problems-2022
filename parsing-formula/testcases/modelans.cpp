#include <bits/stdc++.h>
using namespace std;

struct Parser {
  private:
  using S = string::const_iterator;
  string data;
  S idx;
  queue<string> q;
  void formula() {
    idx++;
    term();
    idx++;
    while (idx != data.end()) {
      if (*idx == '*') {
        idx++;
        idx++;
        term();
        idx++;
        q.push("*");
      }
      else if (*idx == '/') {
        idx++;
        idx++;
        term();
        idx++;
        q.push("/");
      }
    }
  }
  void term() {
    num();
    while (true) {
      if (*idx == '+') {
        idx++;
        num();
        q.push("+");
      }
      else if (*idx == '-') {
        idx++;
        num();
        q.push("-");
      }
      else
        break;
    }
  }
  void num() {
    string s = "";
    while (isdigit(*idx)) {
      s += *idx;
      idx++;
    }
    q.push(s);
  }

  public:
  Parser(string& s) {
    data = s;
    idx = data.begin();
  }
  queue<string> get() {
    formula();
    return q;
  }
};

void solve(int d) {
  string _s;
  cin >> _s;
  Parser p(_s);
  // cerr << "\rinit  (rem: " << d << ")" << flush;
  auto que = p.get();
  // cerr << "\rparse (rem: " << d << ")" << flush;
  {
    auto tmp = que;
    while (!tmp.empty()) {
      printf("%s%c", tmp.front().c_str(), tmp.size() == 1 ? '\n' : ' ');
      tmp.pop();
    }
  }
  // cerr << "\rprint (rem: " << d << ")" << flush;
  stack<int> st;
  constexpr int INF = 1e9;
  while (!que.empty()) {
    if (que.front() == "+") {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      // fprintf(stderr, "\rprint (rem: %d): %10intd + %10intd", d, b, a);
      // fflush(stderr);
      // assert(abs(a + b) <= INF);
      st.push(a + b);
    }
    else if (que.front() == "-") {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      // fprintf(stderr, "\rprint (rem: %d): %10intd - %10intd", d, b, a);
      // fflush(stderr);
      // assert(abs(b - a) <= INF);
      st.push(b - a);
    }
    else if (que.front() == "*") {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      // fprintf(stderr, "\rprint (rem: %d): %10intd * %10intd", d, b, a);
      // fflush(stderr);
      // assert(abs(a * b) <= INF);
      st.push(a * b);
    }
    else if (que.front() == "/") {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      // fprintf(stderr, "\rprint (rem: %d): %10intd / %10intd", d, b, a);
      // fflush(stderr);
      // assert(abs(b / a) <= INF);
      st.push(b / a);
    }
    else {
      st.push(stoi(que.front()));
    }
    que.pop();
  }
  // cerr << "\rcalc  (rem: " << d << ")" << flush;
  // cerr << "\r" << flush;
  printf("%d\n", st.top());
}

int main() {
  int t;
  cin >> t;
  while (t--) solve(t);
  return 0;
}