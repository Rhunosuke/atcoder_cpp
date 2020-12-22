#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int dy[4] = {-1, 0, 0, 1};
  int dx[4] = {0, -1, 1, 0};

  int r, c;
  cin >> r >> c;
  int sy, sx;
  cin >> sy >> sx;
  sy--; sx--;
  int gy, gx;
  cin >> gy >> gx;
  gy--; gx--;

  char cost[r][c];
  rep(i, r){
    rep(j, c)
      cin >> cost[i][j];
  }

  int dist[r][c];
  rep(i, r) {
    rep(j, c)
      dist[i][j] = 10010;
  }


  queue<P> q;
  q.push(P(sy, sx));
  dist[sy][sx] = 0;

  while(!q.empty()) {
    int yy = q.front().first;
    int xx = q.front().second;
    q.pop();

    if (yy == gy && xx == gx) {
      cout << dist[yy][xx] << endl;
      break;
    }

    rep(i, 4) {
      int ny = yy + dy[i];
      int nx = xx + dx[i];
      if (ny < 0 || ny >= r) continue;
      if (nx < 0 || nx >= c) continue;
      if (cost[ny][nx] == '#') continue;
      if (dist[ny][nx] != 10010) continue;

      q.push(P(ny, nx));
      dist[ny][nx] = dist[yy][xx] + 1;
    }
  }

  return 0;
}
