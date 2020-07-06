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
  vector<ll> x(m);
  rep(i, m) cin >> x[i];

  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }

  sort(x.begin(), x.end(), greater<ll>());

  ll ans = x[0] - x[m-1];
  vector<ll> l(m-1);

  rep(i, m-1) l[i] = x[i] - x[i+1];
  sort(l.begin(), l.end(), greater<int>());
  rep(i, n-1) ans -= l[i];

  cout << ans << endl;


  return 0;
}
