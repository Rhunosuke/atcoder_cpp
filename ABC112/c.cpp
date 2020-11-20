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
  vector<ll> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];
  set<ll> s[n];
  ll table[101][101][n];
  bool iszero[n];
  rep(i, n) iszero[i] = false;
  ll base[101][101];
  rep(i, 101) rep(j, 101) rep(k, n) table[i][j][k] = INF;
  rep(i, 101) rep(j, 101) base[i][j] = INF;

  rep(i, n) {
    if (h[i] == 0) iszero[i] = true;
    rep(j, 101) {
      rep(k, 101) {
        table[j][k][i] = h[i]+abs(x[i]-j)+abs(y[i]-k);
        if (!iszero[i]) base[j][k] = table[j][k][i];
      }
    }
  }

  rep(i, 101) {
    rep(j, 101) {
      bool ans = true;
      rep(k, n-1) {
        if (iszero[k]) {
          if (table[i][j][k] < base[i][j]) ans = false;
        } else if (iszero[k+1]) {
          if (base[i][j] > table[i][j][k+1]) ans = false;
        } else {
          if (table[i][j][k] != base[i][j]) ans = false;
        }
      }
      if (ans) {
        cout << i << " " << j << " " << base[i][j] << endl;
        break;
      }
    }
  }

  return 0;
}
