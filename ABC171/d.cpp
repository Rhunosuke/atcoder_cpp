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
  ll q;
  cin >> q;
  vector<ll> b(q), c(q);
  rep(i, q)  cin >> b[i] >> c[i];

  Ml m;
  rep(i, n) m[a[i]]++;
  ll ans = accumulate(a.begin(), a.end(), 0ll);

  rep(i, q) {
    ans += (c[i] - b[i]) * m[b[i]];
    cout << ans << endl;
    m[c[i]] += m[b[i]];
    m[b[i]] = 0;
  }

  return 0;
}
