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
ll const INF = 1ll<<61;
ll const VMAX = 100000;
double pi = 3.141592653589793238;

int main() {
  ll n, w;
  cin >> n >> w;
  vector<ll> vs(n), ws(n);
  rep(i, n) cin >> ws[i] >> vs[i];

  vector<vector<ll>> dp(n+1, vector<ll>(VMAX+1, INF));
  dp[0][0] = 0;

  rep(i, n) {
    rep(j, VMAX+1) {
      if (j-vs[i] >= 0)
        chmin(dp[i+1][j], dp[i][j-vs[i]] + ws[i]);

      chmin(dp[i+1][j], dp[i][j]);
    }
  }

  ll ans = 0;

  rep(i, VMAX+1) {
    if (dp[n][i] <= w) ans = i;
  }

  cout << ans << endl;

  return 0;
}
