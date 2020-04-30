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
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n), dp(n, INF);
  rep(i, n) cin >> h[i];

  dp[0] = 0;

  rep(i, n) {
    repI(j, 1, k+1) {
      if (i - j >= 0)
        chmin(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
      else break;
    }
  }
  cout << dp[n-1] << endl;

  return 0;
}
