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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif



    string zeros;
    vi arr;
    int k,flag,result,n;
    while(cin >> zeros)
    {
        if(zeros == "~") break;

        if(zeros.size() == 1){flag=1;}
        if(zeros.size() == 2){flag=0;}
        arr.clear();

        while(cin >> zeros)
        {
            if(zeros == "#") break;

            if(zeros.size() < 3){

                if(zeros.size() == 1){flag=1;}
                if(zeros.size() == 2){flag=0;}
            }
            else
            {
                k = zeros.size() - 2;
                while(k--)
                {
                    arr.push_back(flag);
                }
            }
        }


        result = 0;
        n = arr.size() - 1;
        for(int i = 0; i <= n; i++) result += (1 << (n - i)) * arr[i];
        cout << result << endl;

    }
    
    return 0;
}

