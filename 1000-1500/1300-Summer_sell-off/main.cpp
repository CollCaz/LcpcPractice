#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> day;

bool sortDays(const day &a, const day &b) {
  // int lhs = min((a.first * 2), a.second);
  // int rhs = min((b.first * 2), b.second);
  long long oldA = min(a.first, a.second);
  long long oldB = min(b.first, b.second);
  long long lhs = min(a.first * 2, a.second) - oldA;
  long long rhs = min(b.first * 2, b.second) - oldB; 
  // cout << "lhs: " << lhs << " rhs: " << rhs << endl;
  return lhs > rhs;
}

int main() {
  int n, f;
  unsigned long long sol = 0;
  cin >> n >> f;
  vector<day> days;
  for (int i = 0; i < n; i++) {
    long long k, l;
    cin >> k >> l;
    day d(k, l);
    days.push_back(d);
  }
  sort(days.begin(), days.end(), sortDays);
  // for (auto d : days) {
  //   cout << d.first << " " << d.second << endl;
  // }
  for (int i = 0; i < f; i++) {
    // cout << "A" << endl;
    // cout << "m " << min(days[i].first * 2, days[i].second) << endl;
    sol += min(days[i].first * 2, days[i].second);
  }
  for (int i = f; i < n; i++) {
    // cout << "A" << endl;
    // cout << "m " << min(days[i].first, days[i].second) << endl;
    sol += min(days[i].first, days[i].second);
  }
  cout << sol << endl;
}
