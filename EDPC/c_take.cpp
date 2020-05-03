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
  ll n;
  cin >> n;
  vector<vector<ll>> abc(n, vector<ll>(3));
  rep(i, n) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  vector<vector<ll>> dp(n, vector<ll>(3, -1));
  rep(i, 3) dp[0][i] = abc[0][i];

  reps1(i, n) {
    rep(j, 3) {
      rep(k, 3) {
        if (j != k) chmax(dp[i][j], dp[i-1][k] + abc[i][j]);
      }
    }
  }
  cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
  //rep(i, n) rep(j, 3) cout << dp[i][j] << endl;

  return 0;
}
