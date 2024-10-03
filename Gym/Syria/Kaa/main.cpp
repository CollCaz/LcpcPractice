#include <iostream>
#include <variant>
using namespace std;

int main() {
  string needle = "KaaaKaaaKaaa";
  string haystack;
  cin >> haystack;

	auto r = haystack.find(needle);
  if (r == variant_npos) {
    cout << "Still Asleep\n";
  } else {
    cout << "Woken Up\n";
  }
}
