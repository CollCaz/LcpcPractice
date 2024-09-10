#include <iostream>
#include <ostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  int t = n;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    if (in != t) {
      pq.push(in);
      cout << endl;
    } else {
      cout << in;
      while (pq.size() > 0 && pq.top() == (t - 1)) {
        cout << " " << pq.top();
        pq.pop();
        t--;
      }
      cout << endl;
      t--;
    }
  }
}
