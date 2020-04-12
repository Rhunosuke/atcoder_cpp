#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  double border = (double)accumulate(a.begin(), a.end(), 0) / (double)(4 * m);
  //cout << border << endl;
  int cnt = 0;
  rep(i, n) {
    if (a[i] >= border) {
      cnt += 1;
    }
  }

  if (cnt >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
