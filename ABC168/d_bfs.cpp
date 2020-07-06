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
  ll n, m;
  cin >> n >> m;
  vector<ll> G[n];
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--;  b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<ll> q;
  q.push(0);
  vector<ll> prev(n, INF);
  prev[0] = 0;

  while(!q.empty()) {
    ll pos = q.front();
    q.pop();
    rep(i, ll(G[pos].size())) {
      if (prev[G[pos][i]] != INF) continue;
      prev[G[pos][i]] = pos+1;
      q.push(G[pos][i]);
    }
  }

  cout << "Yes" << endl;
  reps1(i, n) {
    cout << prev[i] << endl;
  }

  return 0;
}
