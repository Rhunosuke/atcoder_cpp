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
  ll r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  // ll ans = 0;

  //ll tonum = c2 - r2;
  if (r1 == r2 && c1 == c2) {
    cout << 0 << endl;
  }
  else if (r1+c1 == r2+c2 || r1-c1 == r2-c2 || abs(r1-r2)+abs(c1-c2) <= 3) {
    cout << 1 << endl;
  }
  else if (abs((r1-c1) - (r2-c2)) % 2 == 0 || abs((r1+c1) - (r2+c2)) % 2 == 0) {
    cout << 2 << endl;
  }
  else if (abs((r1-c1) - (r2-c2)) <= 3  || abs((r1+c1) - (r2+c2)) <= 3 || abs((r1-c1) - (r2-c2)) <= 6) {
    cout << 2 << endl;
  }
  else {
    cout << 3 << endl;
  }
  /*
  while(true) {
  if (r1+c1 == r2+c2 || r1-c1 == r2-c2 || abs(r1-r2)+(c1-c2) <= 3) {
  ans++;
  break;
}

}
*/

return 0;
}
