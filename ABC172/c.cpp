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
  cin >> n >> m >> k;

  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  ll ans = 0;

  vector<ll> sumA(n+1), sumB(m);
  sumA[0] = 0; sumB[0] = b[0];
  reps1(i, n+1) sumA[i] = sumA[i-1] + a[i-1];
  reps1(i, m) sumB[i] = sumB[i-1] + b[i];

  rep(i, n+1) {
    ll count = sumA[i];
    if (count > k) break;

    ll pos = upper_bound(sumB.begin(), sumB.end(), k-count) - sumB.begin();

    chmax(ans, i+pos);
  }

  cout << ans << endl;

  return 0;
}
