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
  ll n, w;
  cin >> n >> w;
  vector<vector<ll>> wv(n, vector<ll>(2));
  rep(i, n) cin >> wv[i][0] >> wv[i][1];

  vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));

  rep(i, n) {
    reps1(j, w+1) {
      if (j-wv[i][0] >= 0)
        chmax(dp[i+1][j], dp[i][j-wv[i][0]] + wv[i][1]);

      chmax(dp[i+1][j], dp[i][j]);
    }
  }

  cout << dp[n][w] << endl;
  
  return 0;
}
