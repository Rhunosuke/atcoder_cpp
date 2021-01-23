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
  ll n, x;
  cin >> n >> x;
  vector<ll> v(n), p(n);
  rep(i, n) cin >> v[i] >> p[i];

  x *= 100;
  ll sum = 0;
  rep(i, n) {
    sum += v[i] * p[i];
    if (sum > x) {
      cout << i+1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
