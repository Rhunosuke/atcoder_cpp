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
ll n, m, x;
vector<vector<ll>> a;
vector<ll> cost;
ll ans = INF;

void dfs(vector<int> v) {
  if ((ll)v.size() == n) {
    vector<ll> score(m, 0);
    ll money = 0;

    rep(i, n) {
      if (v[i] == 1) {
        rep(j, m) score[j] += a[i][j];
        money += cost[i];
      }
    }
    
    bool flg = true;
    rep(i, m) {
      if (score[i] < x) flg = false;
    }
    if (flg) chmin(ans, money);
    return;
  }

  v.push_back(0);
  dfs(v);
  v.back()++;
  dfs(v);
}

int main() {

  cin >> n >> m >> x;
  a.assign(n, vector<ll>(m));
  cost.resize(n);

  rep(i, n) {
    cin >> cost[i];
    rep(j, m) cin >> a[i][j];
  }

  dfs(vector<int>(0));

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
