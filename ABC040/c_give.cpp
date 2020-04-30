#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> dp(n, INF);
  dp[0] = 0;

  rep(i, n-1) {
    chmin(dp[i+1], dp[i]+abs(a[i+1]-a[i]));
    if (i < n-2) chmin(dp[i+2], dp[i]+abs(a[i+2]-a[i]));
  }

  cout << dp[n-1] << endl;


  return 0;
}
