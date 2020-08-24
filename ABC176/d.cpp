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
using PPl = pair<ll, pair<ll, ll>>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll h, w, ch, cw, dh, dw;
  cin >> h >> w >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  int dy[4] = {-1, 0, 0, 1};
  int dx[4] = {0, -1, 1, 0};

  int ddy[20] = {-2, -2, -2, -2, -2, -1, -1, -1, -1,  0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  int ddx[20] = {-2, -1,  0,  1,  2, -2, -1,  1,  2, -2, 2,-2,-1, 1, 2,-2,-1, 0, 1, 2};

  ll cost[h][w];
  rep(i, h) {
    rep(j, w) {
      cost[i][j] = INF;
    }
  }
  cost[ch][cw] = 0;

  queue<P> q;
  q.push(P(ch, cw));
  priority_queue<PPl, vector<PPl>, greater<PPl>> pq;
  pq.push(PPl(0, Pl(ch, cw)));

  // int cnt = 1;
  // int ans = 0;

  while(! pq.empty()) {
    int yy = pq.top().second.first;
    int xx = pq.top().second.second;
    pq.pop();

    ll wallnum = 0;

    rep(i, 4) {
      int ny, nx;
      ny = yy + dy[i]; nx = xx + dx[i];

      if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
        wallnum++;
        continue;
      }
      if (s[ny][nx] == '#') {
        wallnum++;
        continue;
      }
      if (cost[ny][nx] <= cost[yy][xx]) continue;
      pq.push(PPl(cost[yy][xx], Pl(ny, nx)));
      cost[ny][nx] = cost[yy][xx];

      if (ny == dh && nx == dw) {
        cout << cost[dh][dw] << endl;
        return 0;
      }
    }

    if (wallnum >= 2) {
      rep(i, 20) {
        int ny, nx;
        ny = yy + ddy[i]; nx = xx + ddx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if (s[ny][nx] == '#') continue;
        if (cost[ny][nx] <= cost[yy][xx] + 1) continue;
        pq.push(PPl(cost[yy][xx]+1, Pl(ny, nx)));
        cost[ny][nx] = cost[yy][xx] + 1;
      }
    }

  }
  if (cost[dh][dw] == INF) cout << -1 << endl;
  else cout << cost[dh][dw] << endl;

  return 0;
}
