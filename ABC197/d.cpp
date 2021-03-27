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
  double n;
  double x0, y0, xn2, yn2;
  cin >> n >> x0 >> y0 >> xn2 >> yn2;

  double xc, yc;
  xc = (x0+xn2)/2;
  yc = (y0+yn2)/2;

  // diameter
  // double diam = sqrt((x0-xn2) * (x0-xn2) + (y0-yn2) * (y0-yn2));

  double xrol, yrol, xans, yans;
  xrol = x0-xc;
  yrol = y0-yc;

  xans = xrol * cos(360/n *pi/180) - yrol * sin(360/n *pi/180);
  yans = xrol * sin(360/n *pi/180) + yrol * cos(360/n *pi/180);

  xans += xc;
  yans += yc;

  printf("%.6f %.6f\n", xans, yans);

  return 0;
}
