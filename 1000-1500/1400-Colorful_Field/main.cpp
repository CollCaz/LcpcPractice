#include <iostream>
#include <vector>
using namespace std;

enum Crop {
  Carrot,
  Kiwi,
  Grape,
  Waste,
};

string Stringify(Crop c) {
  switch (c) {
  case Carrot:
    return "Carrots";
    break;
  case Kiwi:
    return "Kiwis";
    break;
  case Grape:
    return "Grapes";
    break;
  case Waste:
    return "Waste";
    break;
  }
  return "";
}

int main() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  vector<long long> wastes;
  wastes.reserve(k);

  int cropsPlaces = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    wastes.emplace_back(((x - 1) * m) + y - 1);
  }

  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    unsigned long long idx = (((x - 1) * m) + y - 1);
    unsigned long long before = 0;
    bool isW = false;
    for (auto w : wastes) {
      if (idx == w) {
        isW = true;
        break;
      }
      if (idx > w) {
        before++;
      }
    }
    // cout << "idx: " << idx << ": " << before << endl;
    if (!isW) {
      cout << Stringify((Crop)((idx - before) % 3)) << endl;
    } else {
      cout << Stringify(Waste) << endl;
    }
  }
}
