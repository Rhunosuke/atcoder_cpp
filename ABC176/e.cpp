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
using MPb = map<Pl, bool>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll h, w, m;
  cin >> h >> w >> m;
  vector<ll> hh(m), ww(m);
  MPb mpb;
  rep(i, m) {
    cin >> hh[i] >> ww[i];
    hh[i]--; ww[i]--;
    mpb[Pl(hh[i], ww[i])] = true;
  }

  ll ans = 0;

  ll row[h] = {};
  ll col[w] = {};

  rep(i, m) {
    row[hh[i]]++;
    col[ww[i]]++;
  }

  ll rowmax = *max_element(row, row+h);
  ll colmax = *max_element(col, col+w);

  set<ll> rowset;
  set<ll> colset;

  rep(i, m) {
    if (row[hh[i]] == rowmax) rowset.insert(hh[i]);
    if (col[ww[i]] == colmax) colset.insert(ww[i]);
  }

  ans = rowmax + colmax -1;

  for( auto i = rowset.begin(); i != rowset.end(); ++i ) {
    for (auto j = colset.begin(); j != colset.end(); ++j) {
      if (!mpb[Pl(*i, *j)]) {
        ans = rowmax + colmax;
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
