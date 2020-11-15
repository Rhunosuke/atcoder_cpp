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
  ll n, k;
  cin >> n >> k;
  ll t[n][n];
  rep(i, n) rep(j, n) cin >> t[i][j];

  vector<ll> o(n-1);
  ll ans = 0;
  rep(i, n-1) o[i] = i+1;
  do {
    ll prev = 0;
    ll time = 0;
    rep(i, n-1) {
      time += t[prev][o[i]];
      prev = o[i];
    }
    time += t[prev][0];
    if (time == k) ans++;
  } while(next_permutation(o.begin(), o.end()));

  cout << ans << endl;

  return 0;
}
