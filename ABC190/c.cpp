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
  ll n, m, k;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  cin >> k;
  vector<ll> c(k), d(k);
  rep(i, k) cin >> c[i] >> d[i];
  ll ans = 0;

  rep(i, 1<<k) {
    vector<int> t(k);
    rep(j, k) if (i>>j&1) {
      t[j] = 1;
    }

    vector<ll> cnt(n);

    rep(j, k) {
      if (t[j]) cnt[c[j]-1]++;
      else cnt[d[j]-1]++;
    }

    ll sum = 0;
    rep(j, m) {
      if (cnt[a[j]-1] > 0 && cnt[b[j]-1] > 0) sum++;
    }

    chmax(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
