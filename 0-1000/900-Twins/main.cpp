#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  int mySum = 0;
  vector<int> coins;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    sum += c;
    coins.push_back(c);
  }
  sort(coins.begin(), coins.end(), greater<>());
  for (int i = 0; i < n; i++) {
    mySum += coins[i];
    if ((float)mySum > (float)(sum - mySum)) {
      cout << i + 1 << endl;
      break;
    }
  }
}
