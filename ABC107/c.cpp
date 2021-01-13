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
  ll n, k;
  cin >> n >> k;

  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  ll index = n;
  rep(i, n) {
    if (x[i] >= 0) {
      index = i;
      break;
    }
  }

  ll ans = INF;

  rep(i, k+1) {
    if (index-k+i < 0 || index+i-1 >= n) continue;
    if (i == 0) {
      chmin(ans, abs(x[index-k]));
      continue;
    }
    if (i == k) {
      chmin(ans, x[index+k-1]);
    }
    chmin(ans, min(abs(x[index-k+i]), abs(x[index+i-1])) * 2 + max(abs(x[index-k+i]), abs(x[index+i-1])));
  }

  cout << ans << endl;

  return 0;
}
