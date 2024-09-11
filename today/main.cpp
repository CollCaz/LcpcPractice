#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  string nums;
  cin >> nums;

  stack<int> s;
  int l = nums.length();
  while (l != 0) {
    if (nums.length() == 0) {
      break;
    }
    char c = nums[0];
    nums = nums.erase(0);
    if (s.empty() && s.top() != c) {
      s.pop();
    } else {
      s.push(c);
    }
  }
  cout << s.size() << endl;
}
