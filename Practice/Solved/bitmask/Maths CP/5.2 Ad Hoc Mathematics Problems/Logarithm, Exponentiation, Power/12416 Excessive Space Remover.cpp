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

Simple If you have max_space = 8 then 8 -> 4 -> 2 -> 1  (action 3)
for 4, 4 -> 2 -> 1 -> 0 (action 2)
for 9, 9 -> 4.5 -> 2.25 -> 1.25 -> 1 (action 4)


simple 2^k = N -> k = log2(N) But we take ceil value bcz for odd number it is 1 space also ceil(log2(N))


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
    while(getline(cin,s)){
        int max_space_in_line = 0;
        for(int i = 0; i < (int)s.size() ; i++)
        {
            if(s[i] == ' ')
            {
                int j = i;
                while(i < (int)s.size() && s[i] == ' ')i++;
                if(max_space_in_line < (i-j)) max_space_in_line = i - j;
            }
        }
        cout << ceil(log2(max_space_in_line))   << endl;
    }

    return 0;
}

