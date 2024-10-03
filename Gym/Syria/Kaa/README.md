[link](https://codeforces.com/gym/105264/problem/M)

Simplest problem no need for an explanation

the C++ method
```cpp
string.find()
```
returns the position of the first occurance or npos (-1) so we check for that

Time Complexity: O(n * m)

```cpp
int main() {
  string needle = "KaaaKaaaKaaa";
  string haystack;
  cin >> haystack;

  auto r = haystack.find(needle);
  cout << ((r == -1) ? "Still Asleep\n" : "Woken Up\n");
}
```
