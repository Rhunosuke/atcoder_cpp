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
using Pll = pair<pair<ll, ll>, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

vector<ll> dijikstra(ll start, vector<Pll> *G, ll n) {
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, start));

  vector<ll> dist(n);
  rep(i, n) dist[i] = INF;
  dist[start] =  0;

  while (!pq.empty()) {
    ll pos = pq.top().second;
    pq.pop();

    rep(i, int(G[pos].size())) {
      ll cost = G[pos][i].first.second;
      ll to = G[pos][i].first.first;
      ll k = G[pos][i].second;

      if (dist[to] > dist[pos] +(k-dist[pos]%k)%k + cost) {
        dist[to] = dist[pos] +(k-dist[pos]%k)%k + cost;
        pq.push(P(dist[to], to));
        continue;
      }
    }
  }

  return dist;
}

int main() {
  ll n, m, x, y;
  cin >> n >> m >> x >> y;
  x--; y--;

  vector<Pll> G[n];
  rep(i, m) {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    G[a].push_back(Pll(Pl(b, t), k));
    G[b].push_back(Pll(Pl(a, t), k));
  }

  vector<ll> dist = dijikstra(x, G, n);
  if (dist[y] == INF) cout << -1 << endl;
  else cout << dist[y] << endl;

  return 0;
}
