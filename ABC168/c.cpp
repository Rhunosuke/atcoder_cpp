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
  double a, b, h, m;
  cin >> a >> b >> h >> m;

  double hour = 30 * h + 0.5 * m;
  double minute = 6 * m;

  double dif = max(hour, minute) - min(hour, minute);
  double ans2 = pow(a, 2) + pow(b, 2) - 2 * a * b * cos(dif / 180.0 * pi);
  printf("%.10f\n", pow(ans2, 0.5));

  return 0;
}
