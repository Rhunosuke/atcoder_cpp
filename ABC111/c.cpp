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
  ll n;
  cin >> n;
  vector<Pl> cnt1(1e5+1), cnt2(1e5+1);
  rep(i, 1e5+1) {
    cnt1[i] = Pl(0, i);
    cnt2[i] = Pl(0, i);
  }
  rep(i, n) {
    ll v;
    cin >> v;
    if (i % 2 == 0) cnt1[v].first++;
    else cnt2[v].first++;
  }
  sort(cnt1.begin(), cnt1.end(), greater<Pl>());
  sort(cnt2.begin(), cnt2.end(), greater<Pl>());


  if (cnt1[0].second != cnt2[0].second) {
    cout << n - cnt1[0].first - cnt2[0].first << endl;
  } else {
    cout << min(n - cnt1[0].first - cnt2[1].first, n - cnt1[1].first - cnt2[0].first) << endl;
  }

  return 0;
}
