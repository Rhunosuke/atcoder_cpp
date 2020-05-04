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
int g[15][15];

int main() {
  int n;
  cin >> n;
  rep(i, n)rep(j, n) g[i][j] = -1;
  rep(i, n) {
    int m;
    cin >> m;
    rep(j, m) {
      int a, x;
      cin >> a >> x;
      --a;
      g[i][a] = x;
    }
  }

  int ans = 0;
  rep(i, 1<<n) {
    vector<int> d(n);
    rep(j, n) if (i>>j&1) {
      d[j] = 1;
    }
    bool ok = true;
    rep(j, n) {
      if (d[j]) {
        rep(k, n) {
          if (g[j][k] == -1) continue;
          if (g[j][k] != d[k]) ok = false;
        }
      }
    }
    if (ok) ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << endl;

  return 0;
}
