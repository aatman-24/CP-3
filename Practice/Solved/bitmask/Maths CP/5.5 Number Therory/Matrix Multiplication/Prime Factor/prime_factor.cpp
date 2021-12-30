#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Therory <=============================================

Prime Factorization:
1) Brute force -> O(N)


*/


vii getFactor(int N){           // Brute Force O(N). (when N is prime it take O(N)).

    vii result;
    int cnt;

    int i = 2;
    while(N != 1){
        if(N % i == 0) {
            cnt = 0;
            while(N % i == 0) {N /= i; cnt++;}
            result.push_back({i,cnt});
        }
        i++;
    }
    return result;
}

vii getFactors(int N){           // Optimized Way O(sqrt(N)).

    vii result;
    int cnt;

    int i = 2;
    while(N != 1 && i * i < N){
        if(N % i == 0) {
            cnt = 0;
            while(N % i == 0) {N /= i; cnt++;}
            result.push_back({i,cnt});
        }
        i++;
    }
    if(N > 1) result.push_back({N,1});   // Remaining N is also prime factor..
    return result;
}

ll _sieve_size = 10000007;
vi arr(_sieve_size,-1);

void sieveForFactor() {                  // get O(N)
    for(int i = 2; i <= _sieve_size; i++){
        if(arr[i] == -1) {
            for(int  j = i; j < _sieve_size; j+=i) {
                if(arr[j] == -1)
                arr[j] = i;
            }
        }
    }

}


mii getFactors(int N) {             // get O(logN)
     sieveForFactor();
     mii result;
     while(N != 1) {
        if(result.find(arr[N]) == result.end()) result[arr[N]] = 1;
        else  result[arr[N]]++;
        N = N / arr[N];
     }
     return result;
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    // vii result = getFactors(39);
    // for(int i = 0 ; i < (int)result.size(); i++) {
    //     cout << result[i].first << '^' << result[i].second <<  ' ';
    // }


    mii result = getFactors(846);
    for(auto i : result) {
        cout << i.first << '^' << i.second << ' ';
    }

    return 0;
}

