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
  ll a, b, x;
  cin >> a >> b >> x;
  ll tmp = 1;

  while (a * tmp + b * (ll(log10(tmp))+1) <= x && tmp <= 1e9) {
    tmp *= 10;
  }

  tmp /= 10;

  cout << min(ll(1e9), (x - b * (ll(log10(tmp)) + 1)) / a) << endl;
  cout << x - b * (ll(log10(tmp)) + 1) << endl;
  cout << ll(log10(tmp)) + 1 << endl;
  cout << 303238506ll * 1000000000ll +  317063340ll * ll(log10(tmp)+1) << endl;
    cout << 303238506ll * 1000000000ll +  317063340ll * 10 << endl;
  cout << 303238508894523551 << endl;

  return 0;
}
