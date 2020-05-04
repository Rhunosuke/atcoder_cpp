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
ll n;
vector<vector<P>> shogen;
ll ans;

void dfs(vector<int> v) {
  if ((ll)v.size() == n) {
    bool is_ok = true;
    rep(i, n) {
      if (v[i] == 0) continue;
      rep(j,ll(shogen[i].size())) {
        if (v[shogen[i][j].first] != shogen[i][j].second) {
          is_ok = false;
        }
      }
    }
    if (is_ok) chmax(ans, (ll)count(v.begin(), v.end(), 1));

    return;
  }

  v.push_back(0);
  dfs(v);
  v.back()++;
  dfs(v);
}

int main() {
  cin >> n;
  shogen.resize(n);
  rep(i, n) {
    ll a;
    cin >> a;
    shogen[i] = vector<P>(a);
    rep(j, a) {
      cin >> shogen[i][j].first >> shogen[i][j].second;
      shogen[i][j].first--;
    }
  }

  dfs(vector<int>(0));

  cout << ans << endl;;



  return 0;
}
