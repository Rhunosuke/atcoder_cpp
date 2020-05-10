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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> l(n+1, 1), r(n+1, 1);
  l[0] = 0; r[n] = 0;
  rep(i, n) l[i+1] = __gcd(l[i], a[i]);
  rep(i, n) r[n-1-i] = __gcd(r[n-i], a[n-1-i]);

  ll ans = 0;

  rep(i, n) {
    chmax(ans, __gcd(l[i], r[i+1]));
  }

  cout << ans << endl;

  return 0;
}
