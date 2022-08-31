#include "validate.h"

using namespace std;

int main(int argc, char* argv[]) {
  init_io(argc, argv);

  // N の出力
  int n;
  assert(judge_in >> n);
  cout << n << endl;

  // 数列出力
  int max_a = -1;
  for (int i = 0; i < n; i++) {
    int a;
    assert(judge_in >> a);
    max_a = max(max_a, a);
    cout << a << (i == n - 1 ? "\n" : " ");
  }
  cout << flush;

  // 答え入力
  int ans, judgeans;
  if (!(author_out >> ans)) {
    wrong_answer("No output\n");
  }
  if (!(judge_ans >> judgeans)) {
    judge_error("No answer\n");
  }

  string trash;
  if (author_out >> trash) {
    wrong_answer("Extra output: %s\n", trash.c_str());
  }

  if (ans != judgeans) {
    if (max_a <= 100000) {
      wrong_answer("Wrong answer with subtask 1\n");
    }
    else {
      judge_message("Wrong answer with subtask 2\n");
      accept_with_score(0);
    }
  }
  accept_with_score(1);
  return 0;
}