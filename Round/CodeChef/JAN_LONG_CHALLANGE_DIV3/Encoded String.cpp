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

char arr[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    
    int ind,t,n; 
    cin >> t;
    for(int test = 0 ; test < t; test++){

        cin >> n;
        char str[n],result[n/4]; 
        for(int k = 0 ; k < n ; k++){
            cin >> str[k];
        }
        for(int p = 0 ; p < n;){
            ind = 0;
            int start = p;
            int end = min(p+4,n);
            for(int k = start; k < end; k++)
            {   
                if(str[k] == '1') ind += pow(2,k % 4);
            }
            result[p/4] = arr[ind];
            p+=4;
        }

        for(int i = 0; i < n/4 ; i++) cout << result[i];
        cout << endl;

    }


    return 0;
}

