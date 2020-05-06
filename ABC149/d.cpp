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
char rsp[3] = {'r', 's', 'p'};
char const blank = 'z';

int main() {
  ll n, k;
  vector<ll> rsp_point(3);
  string t;

  cin >> n >> k;
  cin >> rsp_point[1] >> rsp_point[2] >> rsp_point[0];
  cin >> t;

  vector<char> record(n);
  ll ans = 0;

  rep(i, k) {
    for(int j = i; j < n; j += k) {
      rep(l, 3) {
        if (t[j] == rsp[l]) {
          if (j - k >= 0) {
            if(record[j-k] == t[j]) {
              record[j] = blank;
              continue;
            }
          }
          ans += rsp_point[l];
          record[j] = rsp[l];
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
