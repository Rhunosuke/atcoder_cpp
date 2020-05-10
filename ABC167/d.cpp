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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }
  vector<ll> m(n, -1);
  m[0] = 0;
  ll from = 0;
  ll to = -1;

  rep(i, k) {
    to = a[from];

    if (m[to] != -1) {
      ll cnt = k - m[from] - 1;
      cnt %= (m[from] - m[to] + 1);
      rep(j, n) {
        if (m[j] == m[to]+cnt) {
          to = j;
          break;
        }
      }
      break;
    }
    m[to] = m[from] + 1;
    from = to;
  }

  cout << to+1 << endl;;

  return 0;
}
