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
  ll k;
  string ss, st;
  cin >> k >> ss >> st;
  vector<ll> table(10);
  rep(i, 10) table[i] = k;
  vector<ll> cnt_s(10), cnt_t(10);
  rep(i, 10) {
    cnt_s[i] = 0;
    cnt_t[i] = 0;
  }
  ll const ttl = 9 * k - 8;

  ll s[4], t[4];
  rep(i, 4) {
    s[i] = ss[i] - '0';
    t[i] = st[i] - '0';
    table[s[i]]--;
    table[t[i]]--;
    cnt_s[s[i]]++;
    cnt_t[t[i]]++;
  }

  double ans = 0;

  reps1(i, 10) {
    reps1(j, 10) {
      if (i == j) {
        if (table[i] < 2) {
          // cout << i << " " << j << " " << -1 << endl;
          continue;
        }
      } else {
        if (table[i] < 1 || table[j] < 1) {
          // cout << i << " " << j << " " << -1 << endl;
          continue;
        }
      }

      ll score_s = 0, score_t = 0;
      reps1(k, 10) {
        ll lcnt_s = cnt_s[k], lcnt_t = cnt_t[k];
        if (k == i) lcnt_s++;
        if (k == j) lcnt_t++;

        score_s += k * pow(10, lcnt_s);
        score_t += k * pow(10, lcnt_t);
      }

      if (score_s <= score_t) {
        // cout << i << " " << j << " " << -1 << endl;
        continue;
      }

      if (i == j) {
        ans += double(table[i] * (table[i] - 1)) / (ttl * (ttl-1));
        // cout << i << " " << j << " " << double(table[i] * (table[i] - 1)) / (ttl * (ttl-1)) << endl;
      } else {
        ans += double(table[i] * table[j]) / (ttl * (ttl-1));
        // cout << i << " " << j << " " << double(table[i] * table[j]) / (ttl * (ttl-1)) << endl;
      }

    }
  }

  printf("%.6f\n", ans);
  // cout << ans << endl;

  return 0;
}
