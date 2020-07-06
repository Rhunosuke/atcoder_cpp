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
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

void calc(int x) {
  repI(i, -200, 200) {
    repI(j, -200, 200) {
      if (pow(i, 5) - pow(j, 5) == x) {
        cout << i << " " << j << endl;
        return;
      }
    }
  }
  return;
}

int main() {
  ll x;
  cin >> x;
  calc(x);

  return 0;
}
