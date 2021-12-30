#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<ll> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

TIME COMPLEXITY : 


*/

ll _sieve_size;
bitset<20000000> bt;
vi primes;

void sieve(ll ub) {
    bt.set();
    _sieve_size = ub + 1;
    bt[0] = bt[1] = 0;

    for(ll i = 2; i < _sieve_size; i++) {
        if(bt[i]) {
            for(ll j = i * i ; j < _sieve_size; j+=i) bt[j] = 0;
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



    sieve(19000000);
    vii result;

    for(double i = 0 ; i < (int)primes.size() - 1; i++) {
        if(primes[i] + 2 == primes[i+1]){
            result.push_back({primes[i],primes[i+1]});
        }
    }

    int N;
    while(cin >> N) {
        printf("(%d, %d)\n",result[N-1].first,result[N-1].second);
    }


    return 0;



}

