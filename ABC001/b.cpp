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
  ll m;
  cin >> m;

  if (m < 100) {
    cout << "00" << endl;
  } else if (m <= 5000) {
    printf("%02lld\n", m/100);
  } else if (m <= 30000) {
    printf("%lld\n", m/1000 + 50);
  } else if (m <= 70000) {
    printf("%lld\n", (m/1000 - 30) / 5 + 80);
  } else {
    cout << "89" << endl;
  }

  return 0;
}
