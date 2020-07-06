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
  ll n, m;
  cin >> n >> m;
  vector<ll> h(n);
  rep(i, n) cin >>h[i];
  vector<ll> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  vector<bool> is_high(n, true);
  rep(i, m) {
    if (h[a[i]] < h[b[i]]) {
      is_high[a[i]] = false;
    } else if(h[a[i]] > h[b[i]]) {
      is_high[b[i]] = false;
    } else {
      is_high[a[i]] = false;
      is_high[b[i]] = false;
    }
  }

  ll ans = 0;
  rep(i, n) {
    if (is_high[i]) ans++;
  }

  cout << ans << endl;

  return 0;
}
