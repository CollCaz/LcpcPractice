[link](https://codeforces.com/gym/105390/problem/A)


# Problem Description

Givin a string of zeros and ones, it's length n and a value k, perform the following operations as many times as needed (possibly zero times) to maximize the number of 1s in the string

1. Choose any value i where (k <= i <= n)
2. Set all "bit" to the left of i to 1 stoping at the (i - k + 1)th value
3. Set all "bit" to the right of i to 0 stoping at the (i + k)th value

you must do all three steps each time

# Solution

If you had set each "bit" on the left to 1 *and* each "bit" on the right to 0, you will eventually turn all the "bits" to 1s, except the last one.
however, you have to stop at (i - k + 1), you will always end up with 0s after that point.

So, we will need to minimize that gap.
We can choose the lowest value, i = k, and work our way up to n - k;

## example
n = 4, k = 1
1010

1. i = 1, 1000
2. i = 2, 1100
3. i = 3, 1110

we notice that we start by making the first bit 1, then move all the way up to n-k, therefore; the smallest possible number of zeros is k, and the biggest number of ones is n - k;

This is only wrong if the number of 1s in the original string is already better than that, so we just print which ever is bigger.

```cpp
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;

    // The input string
    string b;
    cin >> b;

    // The numbers of ones we have
    int c = count(b.begin(), b.end(), '1');

    // The answer is whichever is the biggest
    cout << max<int>(c, (n - k)) << endl;
  }
}
```

