#include <bits/stdc++.h>
#include <cmath>
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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    unsigned int  N,K,D,tmp,sm;
    unsigned int t; cin >> t;
    while(t--){
        cin >> N >> K >> D;
        sm = 0;
        while(N--){
            cin >> tmp;
            sm += tmp;
        }
        cout << min(D,sm/K) << endl;
    }

    return 0;
}

