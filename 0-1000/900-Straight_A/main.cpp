#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  double n, k;
  cin >> n >> k;
  vector<double> grades = {0};
  grades.reserve(100);
  long sum = 0;
  for (int i = 0; i < n; i++) {
    double g;
    cin >> g;
    grades.emplace_back(g);
    sum += g;
  }
  double i = n;
  while (round(sum / i) != k) {
    i++;
    grades.emplace_back(k);
    sum += k;
  }
  cout << i - n << endl;
}
