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

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll dp[n];
  dp[0] = 1000;
  reps1(i, n) dp[i] = 0;
  
  reps1(i, n) {
    rep(j, i) {
      ll tmp = dp[i-j-1] / a[i-j-1];
      chmax(dp[i], dp[i-j-1]);
      chmax(dp[i], dp[i-j-1] - tmp * a[i-j-1] + tmp * a[i]);
    }
  }

  cout << dp[n-1] << endl;

  return 0;
}
