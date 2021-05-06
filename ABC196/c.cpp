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
  ll keta = 1;
  ll tmp = n;
  while(tmp / 10 != 0) {
    keta++;
    tmp /= 10;
  }
  if (keta % 2 == 1) {
    cout << pow(10, (keta-1)/2) - 1<< endl;
    return 0;
  }
  string sn = to_string(n);
  ll first = stoll(sn.substr(0, keta/2));
  ll latter = stoll(sn.substr(keta/2, keta/2));

  if (first <= latter) cout << first << endl;
  else cout << first -1 << endl;

  return 0;
}
