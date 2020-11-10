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
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  rep(i, n) {
    repI(j, i+1, n) {
      ll a = y[i] - y[j];
      ll b = - (y[i] - y[j]) * x[i] + (x[i]- x[j]) * y[i];

      repI(k, j+1, n) {
        if ((x[i]- x[j]) * y[k] == a * x[k] + b) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
