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
  ll n, q;
  string s;
  cin >> n >> s >> q;

  bool isforward = true;

  rep(i, q) {
    ll t, a, b;
    cin >> t >> a >> b;
    a--; b--;

    if (t == 1) {
      if (isforward) {
        char c = s[a];
        s[a] = s[b];
        s[b] = c;
      } else {
        char c = s[(n+a)%(2*n)];
        s[(n+a)%(2*n)] = s[(n+b)%(2*n)];
        s[(n+b)%(2*n)] = c;
      }
    }

    if (t == 2) {
      isforward = !isforward;
    }
  }

  if (isforward) {
    cout << s << endl;
  } else {
    cout << s.substr(n, n) + s.substr(0, n) << endl;
  }

  return 0;
}
