#include <iostream>
#include <set>
using namespace std;

int main() {
  char c;
  set<char> ss;
  while (cin.get(c)) {
    if (c >= 'a' && c <= 'z')
      ss.insert(c);
  }
  cout << ((ss.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!");
}
