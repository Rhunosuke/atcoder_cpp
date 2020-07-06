#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using Pll = pair<ll, Pl>;
using Pv = pair<ll, vector<ll>>;
using Plv = pair<ll, Pv>;
using M = map<int, int>;
ll INF = 1ll<<61;
ll const MAX = 2500;
double pi = 3.141592653589793238;

int main() {
  ll n, m, s;
  cin >> n >> m >> s;

  s = min(s, MAX);

  vector<Pll> G[n];
  rep(i, m) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    u--; v--;
    G[u].push_back(Pll(v, Pl(a, b)));
    G[v].push_back(Pll(u, Pl(a, b)));
  }

  vector<Pl> exch(n);
  rep(i, n) {
    ll c, d;
    cin >> c >> d;
    exch[i] = Pl(c, d);
  }

  priority_queue<Pll, vector<Pll>, greater<Pll>> pq;

  pq.push(Pll(0, Pl(0, s)));
  ll dist[n][MAX+1];
  rep(i, n) rep(j, MAX+1) dist[i][j] = INF;
  dist[0][s] = 0;

  while(!pq.empty()) {
    ll time = pq.top().first;
    ll money = pq.top().second.second;
    ll pos = pq.top().second.first;
    pq.pop();

    if (money + exch[pos].first <= MAX) {
      ll n_money = money + exch[pos].first;
      ll n_time = time + exch[pos].second;
      if (chmin(dist[pos][n_money], n_time)) {
        pq.push(Pll(n_time, Pl(pos, n_money)));
      }
    }

    rep(i, int(G[pos].size())) {

      ll to = G[pos][i].first;
      ll timeCost = G[pos][i].second.second;

      if (money < G[pos][i].second.first) continue;

      if (chmin(dist[to][money-G[pos][i].second.first], dist[pos][money] + timeCost)) {
        pq.push(Pll(dist[pos][money] + timeCost, Pl(to, money-G[pos][i].second.first)));
      }
    }
  }

  repI(i, 1, n) {
    ll ans = INF;
    rep(j, MAX+1)  ans = min(ans, dist[i][j]);
    cout << ans << endl;
  }

  return 0;
}
