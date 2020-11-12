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
  vector<ll> r(n), p(n), q(n);
  rep(i, n) r[i] = i+1;
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  ll a, b;
  ll cnt = 0;

  do {
    bool pflag = true, qflag = true;
    rep(i, n) {
      if (r[i] != p[i]) pflag = false;
      if (r[i] != q[i]) qflag = false;
    }

    if (pflag) a = cnt;
    if (qflag) b = cnt;

    cnt++;

  } while(next_permutation(r.begin(), r.end()));

  cout << abs(a-b) << endl;

  return 0;
}
