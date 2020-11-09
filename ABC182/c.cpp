#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n;
  cin >> n;
  string s = to_string(n);
  ll digit = s.size();
  ll ans = INF;

  rep(bit, 1<< digit) {
    vector<int> d(digit);
    ll sum = 0;

    if (__builtin_popcount(bit) == 0) continue;

    rep(i, digit) if (bit & (1 << i)) {
      d[i] = 1;
      sum += s[i] - '0';
    }

    if (sum % 3 == 0) chmin(ans, digit - __builtin_popcount(bit));
  }
  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
