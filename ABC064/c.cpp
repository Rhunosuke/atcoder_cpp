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
  vector<bool> color(8);
  ll cnt = 0;

  rep(i, n) {
    ll a;
    cin >> a;
    if (a < 400) color[0] = true;
    else if (a < 800) color[1] = true;
    else if (a < 1200) color[2] = true;
    else if (a < 1600) color[3] = true;
    else if (a < 2000) color[4] = true;
    else if (a < 2400) color[5] = true;
    else if (a < 2800) color[6] = true;
    else if (a < 3200) color[7] = true;
    else cnt++;
  }

  ll sum = 0;
  rep(i, 8) if (color[i]) sum++;

  cout << max(sum, 1ll) << " " << sum+cnt << endl;

  return 0;
}
