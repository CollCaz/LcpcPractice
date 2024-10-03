#include <iostream>
using namespace std;

int main() {
  string needle = "KaaaKaaaKaaa";
  string haystack;
  cin >> haystack;

  auto r = haystack.find(needle);
  cout << ((r == -1) ? "Still Asleep\n" : "Woken Up\n");
}
