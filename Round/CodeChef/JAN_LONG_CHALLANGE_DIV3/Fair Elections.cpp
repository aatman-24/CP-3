#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define debug cout << "Ok" << endl

using namespace std;


// typedef pair<int,int> ii;
// typedef vector<ii> vii;
// typedef map<char,int> mci;
// typedef vector<int> vi;
// typedef vector<vi> vvi;

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


    int N,M;
    int t; cin >> t;

    while(t--) {

        cin >> N >> M;
        int A[N],B[M];

        REP(i,N) cin >> A[i];
        REP(j,M) cin >> B[j];

        int sumN = 0, sumM = 0;
        REP(i,N) sumN += A[i];
        REP(j,M) sumM += B[j];

            
        sort(A,A+N);
        sort(B,B+M,greater<int>());

        int cnt = 0;
        for(int k = 0; k < min(N,M); k++) {
            
                if(sumN > sumM) break;

                sumN -= A[k];
                sumN += B[k];

                sumM += A[k];
                sumM -= B[k];
                cnt++;

            }

            cout << (sumN > sumM ? cnt : -1) << endl;

        }


    }


    return 0;
}

