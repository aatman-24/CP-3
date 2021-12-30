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



ll power(int base,int n) {   // Iterative
    ll result = 1;
    while(n){

        if(n % 2) result *= base;
        base *= base;
        n /= 2;
    }
    return result;
}

ll power(int base, int n) {  // Recursive
    if(n == 0) return 1;
    ll result = power(base,n/2);
    result *= result;
    if(n % 2) result *= base;
    return result;
}


ll power(int base, int n, int k) {      // modular exponetation.

    ll result = 1;
    while(n){

        if(n % 2) result = (result * base % k);
        base = (base * base % k);
        n /= 2;
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


    cout << power(3,3,25) << endl;

    return 0;
}

