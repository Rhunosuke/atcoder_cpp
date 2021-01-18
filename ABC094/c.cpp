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
  vector<ll> x(n), xsort(n);
  rep(i, n) cin >> x[i];
  copy(x.begin(), x.end(), xsort.begin());
  sort(xsort.begin(), xsort.end());
  rep(i, n) {
    if (x[i] >= xsort[n/2]) cout << xsort[n/2 -1] << endl;
    else cout << xsort[n/2] << endl;
  }

  return 0;
}
