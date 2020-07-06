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
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  ll c0, c1, c2, c3;
  c0 = 0; c1 = 0; c2 = 0; c3 = 0;

  rep(i, n) {
    if (s[i] == "AC") c0++;
    if (s[i] == "WA") c1++;
    if (s[i] == "TLE") c2++;
    if (s[i] == "RE") c3++;
  }

  cout << "AC x  " << c0 << endl;
  cout << "WA x  " << c1 << endl;
  cout << "TLE x  " << c2 << endl;
  cout << "RE x  " << c3 << endl;

  return 0;
}
