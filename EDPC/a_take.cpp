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
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  vector<ll> dp(n, INF);
  dp[0] = 0;

  repI(i, 1, n) {
    chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
    if (i > 1) chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
  }

  cout << dp[n-1] << endl;


  return 0;
}
