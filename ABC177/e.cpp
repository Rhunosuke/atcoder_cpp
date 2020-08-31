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

vector<ll> divtable;

void Sieve(ll maxnum){
  if(maxnum+1 > ll(divtable.size())){
    divtable.resize(maxnum+1,0);
  }

  rep(i, maxnum+1) {
    divtable[i] = i;
  }

  for (ll i = 2; i * i <= maxnum; i++) {
    if (divtable[i] == i) {
      for (ll j = 2; i * j <= maxnum; j++) {
        divtable[i*j] = i;
      }
    }
  }
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll allgcd = a[0];
  reps1(i, n) allgcd = __gcd(allgcd, a[i]);
  if (allgcd != 1) {
    cout << "not coprime" << endl;
    return 0;
  }

  Sieve(1e6);
  map<ll, bool> isused;

  rep(i, n) {
    set<ll> divset;
    divset.insert(divtable[a[i]]);
    while(a[i] != divtable[a[i]]) {
      a[i] /= divtable[a[i]];
      divset.insert(divtable[a[i]]);
    }
    for(auto i = divset.begin(); i != divset.end(); i++){
      if (isused[*i] && *i != 1) {
        cout << "setwise coprime" << endl;
        return 0;
      }
      isused[*i] = true;
    }
  }

  cout << "pairwise coprime" << endl;

  return 0;
}
