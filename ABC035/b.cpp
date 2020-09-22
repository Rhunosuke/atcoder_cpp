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
  string s;
  ll t;
  cin >> s >> t;
  ll qcnt, ucnt, rcnt;
  qcnt = ucnt = rcnt = 0;

  for(char c: s) {
    if (c == '?') qcnt++;
    if (c == 'L') rcnt--;
    if (c == 'R') rcnt++;
    if (c == 'U') ucnt++;
    if (c == 'D') ucnt--;
  }

  if (t == 1) cout << abs(rcnt) + abs(ucnt) + qcnt << endl;
  if (t == 2) {
    if (abs(rcnt) + abs(ucnt) >= qcnt) cout << abs(rcnt) + abs(ucnt) - qcnt << endl;
    else cout << (qcnt - abs(rcnt) - abs(ucnt)) % 2 << endl;
  }

  return 0;
}
