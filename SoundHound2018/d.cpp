#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
using M = map<ll, ll>;
ll INF = 100100100100100;
ll MONEY = 1e15;

vector<ll> dijikstra(ll start, vector<P> *G, ll n) {
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, start));

  vector<ll> dist(n);
  rep(i, n) dist[i] = INF;
  dist[start] =  0;

  while (! pq.empty()) {
    ll pos = pq.top().second;
    pq.pop();

    rep(i, int(G[pos].size())) {
      ll cost = G[pos][i].second;
      ll to = G[pos][i].first;

      if (dist[to] > dist[pos] + cost) {
        dist[to] = dist[pos] + cost;
        pq.push(P(dist[to], to));
      }
    }
  }

  return dist;
}

int main() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  s--; t--;

  vector<P> G_s[n];
  vector<P> G_t[n];

  rep(i, m) {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    u--; v--;
    G_s[u].push_back(P(v, a));
    G_s[v].push_back(P(u, a));
    G_t[u].push_back(P(v, b));
    G_t[v].push_back(P(u, b));
  }

  vector <ll> dist_s = dijikstra(s, G_s, n);
  vector <ll> dist_t = dijikstra(t, G_t, n);

  vector<ll> dist(n);
  rep(i, n) {
    dist[i] = dist_s[i] + dist_t[i];
  }

  vector<ll> ans(n);
  ans[n-1] = dist[n-1];

  rep(i, n-1) {
    ans[n-2-i] = min(dist[n-2-i], ans[n-1-i]);
  }

  rep(i, n) {
    cout << MONEY - ans[i] << endl;
  }

  return 0;
}
