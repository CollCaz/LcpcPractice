#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<long long int> contribs;
  for (long i = 0; i < n; i++) {
    long c;
    cin >> c;
    contribs.push_back(c);
  }

  long long int m = *max_element(contribs.begin(), contribs.end());

  // accumulate is the dumbest function i have ever seen in my life
  // instead of using the template system or something that makes sense
  // it just stores the accumulated values in the last argument
  // so if that one is an integer it just stores an integer....
  // if you just put a 0 there thats an integer... so stupid...
  // oh and btw thats not an out param, you HAVE to put in a value of the type
  // you want but you can't put the variable you want to store that value in
  // because reasons
  long long int sum =
      accumulate(contribs.begin(), contribs.end(), (long long int)0);
  printf("%lld %lld\n", max<long long int>(m, ceil(sum / 2.0)), sum);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
