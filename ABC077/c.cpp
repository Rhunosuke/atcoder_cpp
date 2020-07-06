#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);

  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;

  rep(i, n) {
    int left_i = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    if (left_i == -1) {
      break;
    }

    int right_i = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
    if (right_i == -1) {
      break;
    }

    // cout << i << " " << " " << left_i << " " << right_i << endl;
    ans += left_i * (n - right_i);
  }

  cout << ans << endl;

  return 0;
}
