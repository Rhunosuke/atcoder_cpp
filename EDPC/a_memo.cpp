#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

vector<ll> h;
vector<ll> dp;

ll rec(int i) {
  if (dp[i] != INF) return dp[i];
  if (i == 0) return 0;

  ll res = INF;
  chmin(res, rec(i-1) + abs(h[i] - h[i-1]));
  if (i > 1) chmin(res, rec(i-2) + abs(h[i] - h[i-2]));

  return dp[i] = res;
}


int main() {
  ll n;
  cin >> n;

  h.assign(n, 0);
  dp.assign(n, INF);

  rep(i, n) cin >> h[i];
  cout << rec(n-1) << endl;


  return 0;
}
