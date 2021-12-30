#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define REP(i,n) for(int i = 1; i <= n; i++)

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<ll> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

TIME COMPLEXITY : 


*/

#define N 101

int ar[N][N], I[N][N];

void mul(int A[][N], int B[][N], int dim){

    int R[dim+1][dim+1];

    REP(i,dim) {

        REP(j,dim) {

            R[i][j] = 0;
            REP(k,dim) R[i][j] += A[i][k] * B[k][j];
        }
    }

    REP(i,dim) REP(j,dim) A[i][j] = R[i][j];
}


void powerMat(int A[][N], int dim, int n) {

    REP(i,dim) REP(j,dim) {
        if(i == j)  I[i][j] = 1;
        else        I[i][j] = 0;
    }

    while(n) {
        if(n % 2) mul(I,A,dim);

        mul(A,A,dim);
        n /= 2;
    }
       
    REP(i,dim) REP(j,dim) A[i][j] = I[i][j];

}

void printMat(int A[][N], int dim) {
    REP(i,dim){
      REP(j,dim) {
        cout << A[i][j] << ' ';
      }  
      cout << endl;
    } 
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif



    int t,dim,n;
    cin >> t;
    while(t--) {

        cin >> dim >> n;
        REP(i,dim) REP(j,dim) cin >> ar[i][j];

        powerMat(ar,dim,n);

        printMat(ar,dim); 
    }

    

    return 0;
}

