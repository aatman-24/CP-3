#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define debug cout << "Clear" << endl;
using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


/*
==============================> Apporach <=============================================

TIME COMPLEXITY : 


*/

ll MAX_SIZE = 2147483647;
ll _sieve_size;
bitset<1000000> bt;
vector<ll> primes;

void sieve(ll ub){
    _sieve_size = ub + 1;
    bt.set();
    bt[0] = bt[1] = 0;
    for(ll i = 2; i < _sieve_size; i++) {
        if(bt[i]){
            for(ll j = i * i; j < _sieve_size; j+=i) bt[j] = 0;
            primes.push_back(i);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int M = sqrt(MAX_SIZE);
    sieve(M);
    int K = (int)primes.size();

    
    ll L,U,i;
    vector<ll> prime,prime_in_range;


    while(cin >> L >> U) {

        ii min_gap = {0,INT_MAX};
        ii max_gap = {0,0};

        int N = U - L+1;
        prime.assign(N,1);
        ll k = 0;
        while(k < K && primes[k] <= U) {
            if(L % primes[k]) i = L + (primes[k] - L % primes[k]);
            else i = L;
            for(;i <= U; i+=primes[k]) prime[i-L] = 0;
            if(L <= primes[k]) prime[primes[k]-L] = 1;
            k++;

        } 


        
        prime_in_range.clear();
        for(int i = 0 ; i < N; i++) {
            if(prime[i]) {
                if(i+L != 1) prime_in_range.push_back(i+L);
            }
        }


        if((int)prime_in_range.size() < 2) {
            cout << "There are no adjacent primes." << endl;
        }
        else {

            for(int i = 1 ; i < (int)prime_in_range.size(); i++) {

                if(prime_in_range[i] - prime_in_range[i-1] < (min_gap.second - min_gap.first)) {
                    min_gap = {prime_in_range[i-1],prime_in_range[i]};
                }

                if(prime_in_range[i] - prime_in_range[i-1] > (max_gap.second - max_gap.first)) {
                    max_gap = {prime_in_range[i-1],prime_in_range[i]};
                }

            }

            ll a,b,c,d;
            a = min_gap.first; b = min_gap.second; c = max_gap.first; d = max_gap.second;
            cout << a << ',' << b << " are closest, " << c << ',' << d << " are most distant." << endl;

        }
    }

    return 0;
}

