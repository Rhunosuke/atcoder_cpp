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
  vector<ll> a(pow(2, n));

  rep(i, pow(2, n)) cin >> a[i];

  ll num1 = -INF, num2 = -INF;
  ll ans1, ans2;
  rep(i, pow(2, n)/2) if (chmax(num1, a[i])) ans1 = i+1;
  repI(i, pow(2, n)/2, pow(2, n)) if (chmax(num2, a[i])) ans2 = i+1;

  if (num1 > num2) cout << ans2 << endl;
  else cout << ans1 << endl;

  return 0;
}
