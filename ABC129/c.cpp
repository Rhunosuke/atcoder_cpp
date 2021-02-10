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
ll const MOD = 1e9+7;
double pi = 3.141592653589793238;
set<ll> a;
vector<ll> dp;

ll rec(int i) {
  if (dp[i] < INF) return dp[i];
  if (i == 0) return 1;
  if (a.find(i) != a.end()) return dp[i] = 0;

  ll res = 0;
  res += rec(i-1) % MOD;
  if (i > 1) res += rec(i-2) % MOD;

  return dp[i] = res % MOD;
}

int main() {
  ll n, m;
  cin >> n >> m;
  rep(i, m) {
    ll tmp;
    cin >> tmp;
    a.insert(tmp);
  }
  dp.assign(n+1, INF);

  cout << rec(n) << endl;

  return 0;
}
