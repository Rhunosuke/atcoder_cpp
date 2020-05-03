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

vector<vector<ll>> abc, dp;

ll rec(int i, int j) {
  if (dp[i][j] > -1) return dp[i][j];

  ll res = -1;
  rep(k, 3)
    if (j != k) chmax(res, rec(i-1, k) + abc[i][j]);

  return dp[i][j] = res;
}

int main() {
  ll n;
  cin >> n;
  abc.assign(n, vector<ll>(3));
  rep(i, n) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  dp.assign(n, vector<ll>(3, -1));
  rep(i, 3) dp[0][i] = abc[0][i];

  ll ans = -1;
  rep(i, 3) chmax(ans, rec(n-1, i));

  cout << ans << endl;

  return 0;
}
