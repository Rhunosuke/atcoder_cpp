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

struct UnionFind {
    vector <int> par;
    vector <ll> siz;

    UnionFind(int N) : par(N), siz(N) {
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) siz[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

int main() {
  ll n, m;
  cin >> n >> m;
  UnionFind u(n);

  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    u.unite(a, b);
  }

  ll ans = 0;
  rep(i, n) chmax(ans, u.size(i));

  cout << ans << endl;

  return 0;
}
