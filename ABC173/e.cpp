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
ll const MOD = 1e9+7;
ll k;

ll calcMinus(vector<ll> plus, vector<ll> minus) {
  sort(plus.begin(), plus.end());
  sort(minus.begin(), minus.end(), greater<ll>());

  ll ans = 1;

  rep(i, k) {
    ans = ans * minus[i] % MOD;
    if (ans < 0) ans += MOD;
  }
  return ans;
}

ll calcPlus(vector<ll> plus, vector<ll> minus) {
  sort(plus.begin(), plus.end(), greater<ll>());
  sort(minus.begin(), minus.end());

  ll ans = 1;
  ll indexP = 0;
  ll indexM = 0;

  rep(i, k) {
    if (i == 0 && k > ll(minus.size()) && k % 2 == 1) {
      ans = ans * plus[indexP] % MOD;
      indexP++;
      continue;
    }

    if (k-i < 2 || ll(minus.size()) - indexM < 2) {
      ans = ans * plus[indexP] % MOD;
      indexP++;
      continue;
    }
/*
    if (ll(plus.size()) - indexP == 2 && k % 2 == 1) {
      ans = ans * plus[indexP] % MOD;
      indexP++;
      continue;
    }
    */

    if (ll(plus.size()) - indexP < 2) {
      ans = ans * minus[indexM] % MOD * minus[indexM + 1] % MOD;
      indexM += 2;
      i += 1;
      continue;
    }

    if (plus[indexP] * plus[indexP + 1] >= minus[indexM] * minus[indexM + 1]) {
      ans = ans * plus[indexP] % MOD * plus[indexP + 1] % MOD;
      indexP += 2;
      i += 1;
      continue;
    } else {
      ans = ans * minus[indexM] % MOD * minus[indexM + 1] % MOD;
      indexM += 2;
      i += 1;
      continue;
    }

  }
  return ans;
}

int main() {
  ll n;
  cin >> n >> k;

  vector<ll> plus, minus;

  rep(i, n) {
    ll a;
    cin >> a;
    if (a >= 0) plus.push_back(a);
    else minus.push_back(a);
  }

  ll ans = 1;

  if (k == n) {
    rep(i, ll(plus.size())) ans = ans * plus[i] % MOD;
    rep(i, ll(minus.size())) ans = ans * minus[i] % MOD;
    if (ans < 0) ans = ans + MOD;
  } else if (ll(plus.size() == 0) && k % 2 == 1) {
    ans = calcMinus(plus, minus);
  } else {
    ans = calcPlus(plus, minus);
  }

  cout << ans << endl;

  return 0;
}
