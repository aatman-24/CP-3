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

const int MAX_N = 100010;
const int p = 1e9+7;                             // p is a prime > MAX_N


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int Cat[11];
    Cat[0] = 1;
 

    for (int m = 1; m < 11; m++) {
        Cat[m] =  ((2*m) * (2*m - 1) * Cat[m-1]) / ((m+1) * m);
    }


    int k;
    cin >> k;
    while(true) {
        cout << Cat[k] << endl;
        if(cin >> k) cout << endl;
        else break;
    }

    return 0;
}

