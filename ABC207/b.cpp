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
  double a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b >= c) {
    cout << -1 << endl;
    return 0;
  }
  cout << ceil(a/(c*d-b)) << endl;

  /*
  5/(3*2-2)

  a + b*i <= c*i*d
  a <= (c*d-b)*i
  a/(c*d-b) <= i

  */


  return 0;
}
