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
  ll h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i, h) cin >> c[i];

  ll ans = 0;

  rep(bit, 1<<h) {
    vector<int> d(h);
    rep(i, h) if (bit & (1 << i)) {
      d[i] = 1;
    }
    rep(bitW, 1<<w) {
      vector<int> dW(w);
      rep(j, w) if (bitW & (1 << j)) {
        dW[j] = 1;
      }

      ll cnt = 0;
      rep(m, h) {
        rep(l, w) {
          if (d[m] != 0 || dW[l] != 0) continue;
          if (c[m][l] == '#') cnt++;
        }
      }

      if (cnt == k) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
