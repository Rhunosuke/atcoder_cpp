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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  ll dp[n+1][m+1];
  rep(i, n+1) rep(j, m+1) dp[i][j] = INF;
  dp[0][0] = 0;

  rep(i, n+1) {
    rep(j, m+1) {
      if (i > 0) chmin(dp[i][j], dp[i-1][j] + 1);
      if (j > 0) chmin(dp[i][j], dp[i][j-1] + 1);

      if (i > 0 && j > 0) {
        if (a[i-1] != b[j-1]) chmin(dp[i][j], dp[i-1][j-1] + 1);
        else chmin(dp[i][j], dp[i-1][j-1]);
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
