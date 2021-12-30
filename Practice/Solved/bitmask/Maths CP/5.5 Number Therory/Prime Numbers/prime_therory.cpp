#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
#define ll long long

using namespace std;

typedef vector<int> vi;

/*
==============================> Therory <=============================================

1) Primality Test - O(sqrt(N)) ->    Upto sqrt of N.
                  - O(sqrt(N)/2) ->  Only odd Number.
                  - O(sqrt(N)/log(sqrt(N))).  -> Only prime Number upto sqrt(N).

2) Sieve of Eratothenes - O(N log log N).

*/

ll _sieve_size;                
bitset<10000010> bs;            // 10^7 be enough for the most case.
vi primes;                     // compact list of primes in form of vector<int>

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;       // Add 1 to include upperBound.
    bs.set();                           // set all bits (all are prime).
    bs[0] = bs[1] = 0;                  // set 0 and 1 non - prime.

    for(ll i = 2; i < _sieve_size; i++) {

        if(bs[i]) {
            // cross out multiples of i starting from i * i!
            for(ll j = i * i; j <= _sieve_size; j+=i) bs[j] = 0;
            primes.push_back((int)i);       // add this prime to the list of primes.
        }
    }
}


bool isPrime(ll N) {
    if(N <= _sieve_size) return bs[N];
    
    for(int i = 0 ; i < (int)primes.size(); i++) 
        if(N % primes[i] == 0) return false;
    return true;        //  it takes longer time if N is a large prime!
}           // note: only work for N <= (last prime in vi "primes")^2



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    sieve(10000000);                            // can go up to 10^7 (need few seconds)
    // printf("%d\n", isPrime(2147483647));        // 10-digits prime
    // printf("%d\n", isPrime(136117223861LL));    // not a prime, 104729*1299709
    

    cout << primes.size() << endl;
    return 0;
}

