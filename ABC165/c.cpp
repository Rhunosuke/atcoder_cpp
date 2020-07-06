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
vector<ll> a, b, c, d;
ll n, m, q;
ll ans  = 0;

void dfs(vector<ll> A) {
  if (ll(A.size()) == n+1) {
    ll sum = 0;
    rep(i, q) {
      if (A[b[i]] - A[a[i]] == c[i])
        sum += d[i];
    }
    chmax(ans, sum);
    return;
  }

  A.push_back(A.back());
  while(A.back() <= m) {
    dfs(A);
    A.back()++;
  }
}

int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

  dfs(vector<ll>(1, 1));

  cout << ans << endl;


  return 0;
}
