#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;

int main() {
  int k;
  cin >> k;

  ll ans = 0;

  repI(a, 1, k+1) {
    repI(b, 1, k+1) {
      repI(c, 1, k+1) {
        ans += __gcd(a, __gcd(b, c));
      }
    }
  }

  cout << ans << endl;

  return 0;
}
