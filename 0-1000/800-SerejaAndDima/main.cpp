#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ser = 0;
  int dim = 0;
  int n;
  cin >> n;
  vector<int> cards;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cards.push_back(c);
  }

  int i = -1;
  while (!cards.empty()) {
    i++;
    int bestCard = 0;
    if (*cards.begin() > cards[cards.size() - 1]) {
      bestCard = *cards.begin();
      cards.erase(cards.begin());
    } else {
      bestCard = cards[cards.size() - 1];
      cards.erase(cards.end());
    }
    if (i % 2 == 0) {
      ser += bestCard;
    } else {
      dim += bestCard;
    }
  }

  cout << ser << " " << dim << endl;
}
