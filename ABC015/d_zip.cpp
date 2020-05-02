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

  vector<vector<ll>> dp(k+1, vector<ll>(w+1, 0));
  
  rep(l, n) {
    for(int i=k; i>0; i--) {
      for(int j = w-a[l]; j >= 0; j--) {
        chmax(dp[i][j+a[l]], dp[i-1][j] + b[l]);
        chmax(dp[i][j], dp[i-1][j]);

      }
    }
  }

  cout << dp[k][w] << endl;

  return 0;
}
