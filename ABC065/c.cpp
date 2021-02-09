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
ll const MOD = 1e9 + 7;
double pi = 3.141592653589793238;

int main() {
  ll n, m;
  cin >> n >> m;

  if (abs(n-m) >=2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == m) {
    ll ans = 2;
    reps1(i, n+1) {
      ans = (ans * i % MOD) * i % MOD;
    }

    cout << ans << endl;

    return 0;
  }

  ll ans = 1;
  reps1(i, n+1) ans = ans * i % MOD;
  reps1(i, m+1) ans = ans * i % MOD;

  cout << ans << endl;

  return 0;
}
