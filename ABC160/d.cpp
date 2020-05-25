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
  ll n, x, y;
  cin >> n >> x >> y;
  x--; y--;
  vector<ll> ans(n);

  rep(i, n) {
    queue<ll> q;
    vector<ll> dist(n, INF);
    auto push = [&](ll v, ll d) {
      if (dist[v] != INF) return;
      dist[v] = d;
      q.push(v);
    };
    push(i, 0);
    while(!q.empty()) {
      ll pos = q.front(); q.pop();
      ll d = dist[pos];
      if (pos-1 >= 0) push(pos-1, d+1);
      if (pos+1 <= n-1) push(pos+1, d+1);
      if (pos == x) push(y, d+1);
      if (pos == y) push(x, d+1);
    }
    rep(j, n) ans[dist[j]]++;
  }

  reps1(i, n) {
    cout << ans[i] / 2 << endl;
  }

  return 0;
}
