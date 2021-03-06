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
  vector<Pl> a(n), b(n);
  rep(i, n) {
    cin >> a[i].first  >> b[i].first;
    a[i].second = i;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans;
  if (a[0].second != b[0].second) {
    ans = max(a[0].first, b[0].first);
  } else {
    ans = a[0].first + b[0].first;
    chmin(ans, max(a[0].first, b[1].first));
    chmin(ans, max(a[1].first, b[0].first));
  }

  cout << ans << endl;

  return 0;
}
