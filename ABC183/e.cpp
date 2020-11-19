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
ll const MOD = 1e9 + 7;

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];


  vector<vector<ll>> dp(h+1, vector<ll>(w+1));
  vector<vector<ll>> x(h+1, vector<ll>(w+1));
  vector<vector<ll>> y(h+1, vector<ll>(w+1));
  vector<vector<ll>> z(h+1, vector<ll>(w+1));

  dp[0][0] = 1;

  rep(i, h) {
    rep(j, w) {
      if (s[i][j] == '#') continue;
      if (i == 0 && j== 0) continue;

      if (j>= 1) {
        dp[i][j] += (x[i][j-1] + dp[i][j-1]) % MOD;
        x[i][j] += (x[i][j-1] + dp[i][j-1]) % MOD;
      }

      if (i >= 1) {
        dp[i][j] += (y[i-1][j] + dp[i-1][j]) % MOD;
        y[i][j] += (y[i-1][j] + dp[i-1][j]) % MOD;
      }

      if (i >= 1 && j >= 1) {
        dp[i][j] += (z[i-1][j-1] + dp[i-1][j-1]) % MOD;
        z[i][j] += (z[i-1][j-1] + dp[i-1][j-1]) % MOD;
      }
      dp[i][j] %= MOD;
      x[i][j] %= MOD;
      y[i][j] %= MOD;
      z[i][j] %= MOD;

    }
  }
  cout << dp[h-1][w-1] << endl;;

  return 0;
}
