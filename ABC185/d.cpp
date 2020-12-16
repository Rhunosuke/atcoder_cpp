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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m+2);
  rep(i, m) cin >> a[i];
  a[m] = 0;
  a[m+1] = n+1;
  sort(a.begin(), a.end());

  vector<ll> diff(m+1);
  ll minval = INF;

  rep(i, m+1) {
    diff[i] = a[i+1] - a[i] - 1;
    if (diff[i] != 0) minval = min(minval, diff[i]);
  }
  ll ans = 0;
  rep(i, m+1) ans += (diff[i]+minval-1) / minval;

  cout << ans << endl;

  return 0;
}
