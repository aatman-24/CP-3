#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>
#include <bitset>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

TIME COMPLEXITY : O(31)
using bitset is very easy to solve.

*/


bitset<32> bset;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,p;
    while(cin >> n)
    {
        if(n == 0) break;
        bset = n;
        p = bset.count();

        cout << "The parity of ";
        int i = 31;
        while(i > -1 && bset[i] != 1)
        {
            i--;            
        }
        while(i > -1)
        {
            cout << bset[i];
            i--;
        }
        cout << " is " << p << " (mod 2)." << endl;
    }


    return 0;
}

