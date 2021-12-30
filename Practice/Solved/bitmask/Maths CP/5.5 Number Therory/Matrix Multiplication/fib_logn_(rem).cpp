#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define debug cout << "Ok" << endl

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

TIME COMPLEXITY : 

    // f(n) = 2 * f(n-1) + 3 * f(n-2)


    f1 f2 = A B -> [f2 f3]   -> f1 * A + f2 * C = f2 
            C D                 f1 * B + f2 * D = f3


    af2 + bf1 = f3

    f1 * A + f2 * C = f2;
    f1(A - 0) = 0
    f2(C - 1) = 0



    f1 * B + f2 * D = f3
    f1 * B + f2 * D = af2 + bf1 
    f1 (B - 1) = 0;
    f2 (D - 1) = 0;

 
     f1(A - 0) = 0      A = 0
     f2(C - 1) = 0      C = 1
     f1 (B - b) = 0;    B = b;
     f2 (D - a) = 0;    D = a;

*/


#define N 101
int I[N][N];

void mul(int A[][N], int B[][N], int dim) {

    int R[dim][dim];

    REP(i,n) REP(j,n) {
        R[i][j] = 0;
        REP(k,n) {
            R[i][j] += A[i][k] * B[k][j];
        }
    }
    REP(i,n) REP(j,n) A[i][j] = R[i][j];

}


void powerOfMat(int a[][N],int dim,int n) {


    REP(i,dim) REP(j,dim) {
        if(i == j) I[i][j] = 1;
        else I[i][j] = 0;
    }


    REP(i,n) I = I * A;

    REP(i,dim) REP(j,dim) A[i][j] = I[i][j];
}






int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif



    int dim = 2;
    int a = 0, b = 3, c = 1, d = 2;
    int n = 5;

    if(n == 1) 



    return 0;
}

