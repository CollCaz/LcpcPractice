#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<string> image;

void zeroConnected(int idx, int idy) {

  if (idy < n - 1) {
    if (image[idx][idy + 1] == '1') {
      image[idx][idy + 1] = '0';
      zeroConnected(idx, idy + 1);
    }
  }
  if (idy > 0) {
    if (image[idx][idy - 1] == '1') {
      image[idx][idy - 1] = '0';
      zeroConnected(idx, idy - 1);
    }
  }
  if (idx < n - 1) {
    if (image[idx + 1][idy] == '1') {
      image[idx + 1][idy] = '0';
      zeroConnected(idx + 1, idy);
    }
  }
  if (idx < n - 1 && idy < n) {
    if (image[idx + 1][idy + 1] == '1') {
      image[idx + 1][idy + 1] = '0';
      zeroConnected(idx + 1, idy + 1);
    }
  }
  if (idx < n - 1 && idy > 0) {
    if (image[idx + 1][idy - 1] == '1') {
      image[idx + 1][idy - 1] = '0';
      zeroConnected(idx + 1, idy - 1);
    }
  }
  if (idx > 0) {
    if (image[idx - 1][idy] == '1') {
      image[idx - 1][idy] = '0';
      zeroConnected(idx - 1, idy);
    }
  }
  if (idx > 0 && idy > 0) {
    if (image[idx - 1][idy - 1] == '1') {
      image[idx - 1][idy - 1] = '0';
      zeroConnected(idx - 1, idy - 1);
    }
  }
  if (idx > 0 && idy < n - 1) {
    if (image[idx - 1][idy + 1] == '1') {
      image[idx - 1][idy + 1] = '0';
      zeroConnected(idx - 1, idy + 1);
    }
  }
}

int main() {
  ifstream cin("Bumble.in");
  freopen("Bumble.out", "w", stdout);

  int c = 0;
  int im = 0;
  while (cin >> n) {
    im++;
    for (int i = 0; i < n; i++) {
      string row;
      cin >> row;
      image.push_back(row);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (image[i][j] == '1') {
          c++;
          zeroConnected(i, j);
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n", im, c);
    image.clear();
    c = 0;
  }
}
