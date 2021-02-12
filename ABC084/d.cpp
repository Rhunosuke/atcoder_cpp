#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;
vector<bool> is_prime;
vector<bool> is_2017;
vector<ll> is2017_table;

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

void Calc2017(size_t max) {
  if(max+1 > is_2017.size()){
      is_2017.resize(max+1,true);
  }
  is_prime[0] = false;
  is_prime[1] = false;

  rep(i, ll(max)+1) {
    is_2017[i] = is_prime[i] && is_prime[int((i+1)/2)];
  }

}

int main() {
  Sieve(1e5+1);
  Calc2017(1e5+1);
  vector<ll> is_2017_table(1e5+1);
  repI(i, 1, 1e5+2) {
    is_2017_table[i] = is_2017_table[i-1];
    if (is_2017[i]) is_2017_table[i]++;
  }

  ll q;
  cin >> q;

  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    cout << is_2017_table[r] - is_2017_table[l-1] << endl;
  }


  return 0;
}
