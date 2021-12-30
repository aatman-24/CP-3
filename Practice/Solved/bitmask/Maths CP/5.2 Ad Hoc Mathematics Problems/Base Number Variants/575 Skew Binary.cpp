#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


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

    string s;
    while(getline(cin,s))
    {
        if(s == "0")break;
        int i = 1;
        int dec_val = 0;
        int n = (int)s.size();
        while(n--)
        {
           dec_val +=  ((s[n]-'0') * ((1 << i) - 1));
           i++;
        }


        cout << dec_val << endl;
    }


    return 0;
}

