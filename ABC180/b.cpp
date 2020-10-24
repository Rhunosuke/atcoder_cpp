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
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  ll ans1, ans3;
  double ans2;
  ans1 = ans2 = ans3 = 0;
  rep(i, n) {
    ans1 += abs(x[i]);
    ans2 += abs(x[i]) * abs(x[i]);
    ans3 = max(ans3, abs(x[i]));
  }

  ans2 = sqrt(ans2);

  cout << ans1 << endl;
  printf("%.9f\n", ans2);
  cout << ans3 << endl;

  return 0;
}
