#include <iostream>
using namespace std;

int main() {
  string dubstep;
  cin >> dubstep;
  for (int i = 0; i < dubstep.length(); i++) {
    if (dubstep[i] == 'W' && dubstep[i + 1] == 'U' && dubstep[i + 2] == 'B') {
      i += 2;
    } else {
      cout << dubstep[i];
      if (dubstep[i+1] == 'W' && dubstep[i + 2] == 'U' && dubstep[i + 3] == 'B') {
        cout << " ";
      }
    }
  }
}
