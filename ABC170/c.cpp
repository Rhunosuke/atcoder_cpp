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
  ll x, n;
  cin >> x >> n;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  rep(i, 101) {
    rep(j, 2) {
      ll tmp;
      if (j == 0) tmp = x - i;
      else tmp = x + i;

      if (find(p.begin(), p.end(), tmp) == p.end()) {
        cout << tmp << endl;
        return 0;
      }
    }
  }

  return 0;
}
