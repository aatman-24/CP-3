#include <bits/stdc++.h>
#include <iostream>
#define ll long long

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

const ll _sieve_size = 1000007;
vi primes;
bitset<_sieve_size> bt;

void sieve() {
    bt.set();
    bt[0] = bt[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++) {
        if(bt[i]){
            for(ll j = i*i; j <=_sieve_size; j+=i) bt[j] = 0;
            primes.push_back((int)i);
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

    sieve();
    int N;
    while(true){
        cin >> N; 
        if(!N) break;

        int i = 0,j = 0;
        while(primes[i] < N) i++;



        while(j < i && primes[i] + primes[j] != N) {
            if(primes[i] + primes[j] < N) j++;
            else i--;
        }

        if(primes[i] + primes[j] == N)
            cout << N << " = " << primes[j] << " + " << primes[i] << endl;
        else 
            cout << "Goldbach's conjecture is wrong." << endl; 

    }

    return 0;
}

