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
vector<ll> l;
ll n, a, b, c;
ll ans = INF;

void dfs(vector<ll> list) {
  if (ll(list.size()) == n) {

    if (count(list.begin(), list.end(), 0) == n) return;
    ll acnt = 0, bcnt = 0, ccnt = 0;
    rep(i, n) {
      if (list[i] == 1) acnt += l[i];
      if (list[i] == 2) bcnt += l[i];
      if (list[i] == 3) ccnt += l[i];
    }
    chmin(ans, )

  }
  list.push_back(0);
  dfs(list);
  rep(i, 3) {
    list.back()++;
    dfs(list);
  }
}

int main() {
  ll a, b, c;
  l.assign(n, 0);
  rep(i, n) cin >> l[i];
  dfs(vector<ll>());


  return 0;
}
