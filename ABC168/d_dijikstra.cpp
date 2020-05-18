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
using PP = pair<ll, P>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
vector<ll> ans;

vector<ll> dijikstra(ll start, vector<ll> *G, ll n) {
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push(P(0, start));

  vector<ll> dist(n);
  rep(i, n) dist[i] = INF;
  dist[start] =  0;

  while (! pq.empty()) {
    ll pos = pq.top().second;
    pq.pop();

    rep(i, int(G[pos].size())) {
      ll to = G[pos][i];

      if (dist[to] > dist[pos] + 1) {
        dist[to] = dist[pos] + 1;
        pq.push(P(dist[to], to));
        ans[to] = pos + 1;
      }
    }
  }

  return dist;
}

int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> G[n];

  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  ans = vector<ll>(n);

  vector <ll> dist = dijikstra(0, G, n);


  if (find(dist.begin(), dist.end(), INF) != dist.end())
    cout << "No" << endl;

  else {
    cout << "Yes" << endl;
    reps1(i, n) {
      cout << ans[i] << endl;
    }
  }

  return 0;
}
