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
  ll a, b, w;
  cin >> a >> b >> w;
  ll minval = INF;
  ll maxval = 0;

  for(ll i=1;a*i<=w*1000;i++) {
    if (b*i>=w*1000) {
      chmin(minval, i);
      chmax(maxval, i);
    }
  }

  if (maxval == 0) cout << "UNSATISFIABLE" << endl;
  else cout << minval << " " << maxval << endl;

  return 0;
}
