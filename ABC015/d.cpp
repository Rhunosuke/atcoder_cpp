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
double pi = 3.141592653589793238;

int main() {
  ll w, n, k;
  cin >> w >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(w+1, vector<ll>(k+1, -INF)));
  rep(i, n+1) rep(j, w+1) dp[i][j][0] = 0;
  rep(i, w+1) rep(j, k+1) dp[0][i][j] = 0;

  rep(i, n) {
    rep(j, w+1) {
      rep(l, k) {
        if (j-a[i] >= 0) {
            chmax(dp[i+1][j][l+1], dp[i][j-a[i]][l] + b[i]);
        }
        chmax(dp[i+1][j][l+1], dp[i][j][l+1]);
      }
    }
  }
  
  cout << dp[n][w][k] << endl;

  return 0;
}
