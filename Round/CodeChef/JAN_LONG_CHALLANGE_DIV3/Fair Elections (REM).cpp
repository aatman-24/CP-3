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

bool sort_func(ll a1, ll a2) {
    if(a1 > a2) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // vi firstOne,secondOne;
    int N,M;
    int t; cin >> t;
    while(t--) {

        cin >> N >> M;
        ll firstOne[N];
        ll secondOne[M];
        int sumN = (ll)0;
        for(int i = 0 ; i < N; i++) {
            cin >> firstOne[i];
            sumN += firstOne[i];
            // cout << firstOne[i] << endl;
        }


        int sumM = (ll)0;
        for(int i = 0 ; i < M ; i++) {cin >> secondOne[i]; sumM += secondOne[i];}

        // cout << sumN << ' ' << sumM << endl;
        if(sumM == sumN) cout <<  "-1" << endl;
        else {

            sort(firstOne,firstOne+N);
            sort(secondOne,secondOne+M,sort_func);

            int i = 0, j = 0;
            int cnt = 0;
            while(i < N && j < M && sumM > sumN && firstOne[i] <= secondOne[j]) {


            sumN -= firstOne[i];
            sumN += secondOne[j];

            sumM += firstOne[i];
            sumM -= secondOne[j];

            cnt++; i++; j++;
            }

            // cout << sumM << ' ' << sumN << endl;

            // cout << cnt << endl;
            if(sumM < sumN) cout << cnt << endl;
            else cout << "-1" << endl;
        }




    }

    return 0;
}

