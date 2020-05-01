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

int main() {
  ll n;
  cin >> n;
  vector<ll> G[n];
  rep(i, n-1) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<Pl> q;
  q.push(Pl(0, 0));
  q.push(Pl(n-1, 1));

  vector<ll> area(n, -1);
  area[0] = 0;
  area[n-1] = 1;

  vector<ll> cntwho(2, 0);

  while(!q.empty()) {
    ll pos = q.front().first;
    ll who = q.front().second;
    q.pop();

    rep(i, ll(G[pos].size())) {
      ll to =G[pos][i];
      if (area[to] != -1) continue;
      q.push(Pl(to, who));
      area[to] = who;
      cntwho[who]++;
    }
  }

  if (cntwho[0] > cntwho[1]) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;

  return 0;
}
