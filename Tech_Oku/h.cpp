#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using PP = pair<int, P>;
using M = map<int, int>;
ll INF = 1ll<<61;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> t(n);

  repI(i, 1, n-1) cin >> t[i];
  t[0] = 0; t[n-1] = 0;
  vector<int> d(n);
  vector<PP> G[n];

  rep(i, m) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    G[a].push_back(PP(b, P(c, d)));
    G[b].push_back(PP(a, P(c, d)));
  }

  priority_queue <Pl, vector<Pl>, greater<Pl>> pq;
  pq.push(Pl(0, 0));

  vector<ll> dist(n);
  rep(i, n) dist[i] = INF;
  dist[0] = 0;

  while(! pq.empty()) {
    int pos = pq.top().second;
    pq.pop();

    rep(i, int(G[pos].size())) {
      int to = G[pos][i].first;
      int cost = G[pos][i].second.first + t[pos];
      int wait = (dist[pos] + t[pos]) % G[pos][i].second.second;
      if (wait != 0) wait = G[pos][i].second.second - wait;
      // cout << "d[pos] + t[pos] " << (d[pos] + t[pos]) << " G[pos][i].second.second " << G[pos][i].second.second << endl;
      // cout << "d[pos] + cost + wait " << dist[pos] << " " << cost << " " << wait << endl;
      // cout << "pos:to " << pos << ":" << to << " cost " << cost << " wait" << wait << " dist[to] " << dist[to] << " calc " << d[pos] + cost + wait << endl;
      if (dist[to] > dist[pos] + cost + wait) {
        dist[to] = dist[pos] + cost + wait;
        pq.push(Pl(dist[to], to));
      }
    }
  }

  if (dist[n-1] > k) cout << -1 << endl;
  else cout << dist[n-1] << endl;


  return 0;
}
