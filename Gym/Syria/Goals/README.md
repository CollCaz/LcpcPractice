[link](https://codeforces.com/gym/105264/problem/A)

Idea from Hussein

The minimum number of contributions is the total number of contributions divided by 2
except when one player has done more goals than that because a player can not assist himself, therefore all of his contributions most be goals other.

Time Complexity: O(n)

```cpp
void solve() {
  int n;
  cin >> n;

  int m = 0;
  long long sum = 0;
  for (long i = 0; i < n; i++) {
    int c;
    cin >> c;
    m = max(m, c);
    sum += c;
  }
  printf("%lld %lld\n", max<long long int>(m, ceil(sum / 2.0)), sum);
}

```
