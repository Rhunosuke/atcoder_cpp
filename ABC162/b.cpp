#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  repI(i, 1, n+1) {
    if (i % 3 != 0 && i % 5 != 0) ans += i;
  }

  cout << ans << endl;


  return 0;
}
