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
  double D, H;
  cin >> n >> D >> H;
  double d = 0, h = 0;
  rep(i, n) {
    ll dtmp, htmp;
    cin >> dtmp >> htmp;
    if (htmp > h) {
      h = htmp;
      d = dtmp;
    }
    if (htmp == h && dtmp > d) {
      d = dtmp;
    }
  }

  if (h == H) cout << h << endl;
  else cout << -(H-h)/(D-d)*D + H << endl;

  return 0;
}
