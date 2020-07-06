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
vector<bool> is_prime;
ll const MAX = 1e6;

void Sieve(size_t max){
    if(max+1 > is_prime.size()){
        is_prime.resize(max+1,true);
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for(size_t i=2; i*i<=max; ++i)
        if(is_prime[i])
            for(size_t j=2; i*j<=max; ++j)
                is_prime[i*j] = false;
}

int main() {
  ll x;
  cin >> x;

  Sieve(MAX);
  ll ans = 0;
  while(!ans) {
    if (is_prime[x]) ans = x;
    x++;
  }

  cout << ans << endl;

  return 0;
}
