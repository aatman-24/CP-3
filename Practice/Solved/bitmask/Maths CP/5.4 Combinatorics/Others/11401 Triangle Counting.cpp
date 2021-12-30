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

TIME COMPLEXITY O(N): 

Approach : a + b > c (three side of the triagualr).

    1 2 3 4 5 6 7 8 9 10 11 12 

3   0
4   0 1
5   0 1 1
6   0 1 2 1
7   0 1 2 2 1
8   0 1 2 3 2 1
9   0 1 2 3 3 2 1
10  0 1 2 3 4 3 2 1
11  0 1 2 3 4 4 3 2 1

Means that When we are given suppose n = 10,
we begin with 8 (n-2) bcz 9 + 1 == 10 which is not possible so try with (n-2)
and you see this pattern.

so total possible triangular for n = 10 is,

arr[10] = sum(8) + sum(7) + sum(6) .... sum(3).   


so simple DP.


---------------------------------------------------------------------
k = i - 2;
if(n % 2 == 0) arr[i] = arr[i-1] + (2 * sumof(1...(k/2-1))) + k/2; 
else arr[i] = arr[i-1] + (2 * sumof(1...(k/2)))
-----------------------------------------------------------------------


*/

ll get_sum(ll n)
{
    return (n * (n+1)) / 2;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    vector<ll> arr(1000001, (ll)0);
    arr[4] = (ll)1;

    ll k;
    for(ll i = 5; i <= (ll)1000001 ; i++) {
        k = (i - 2) / 2;
        if(i % 2 == 0) arr[i] = arr[i-1] + 2 * get_sum(k-1) + k;
        else arr[i] = arr[i-1] + 2 * get_sum(k);  
    }

    int index;
    while(cin >> index){
        if(index < 3) break;
        cout << arr[index] << endl;
    }


}

