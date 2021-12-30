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

CATALAN NUMBER IS EXACT .......    
 
In catalan Number we count such that all n is cover like...  
1) Count number of distinct binary tree with n nodes.       
        (HERE binary tree (parent has max 2 child))

2) Count the number of different ways n + 1 factors can be completely parenthesized.
        (completely [symbols or parenthesized groups]) 

3) counts the number of ways a convex polygon of n + 2 sides can be triangulated.
        (HERE triangulated)


Cat(n) = [2m * 2m-1 / (m+1) * m] * cat(n-1); cat(1) = 1;


In supercatalan number we,
1) counts the number of different plane trees with n leaves and with all internal vertices having two or more children.
                (HERE internal vertices having two or more children) not exact.
2) counts the number of different ways of inserting parentheses into a sequence of n + 1 symbols,
 with each pair of parentheses  surrounding two or more symbols or parenthesized groups, 
 and without any parentheses surrounding the entire sequence.
                (two or more [symbols or parenthesized groups]) not exact.

3) counts the number of different ways of subdividing of a polygon with n + 1 sides into smaller polygons
 by adding diagonals of the original polygon.
                (smaller polygons not triangulated) can be divide into two,three and also four.....


SuperCat(n) = 1/n * [((6n-9) * SuperCat(n-1))- ((n-3) * SuperCat(n-2))] n(1) == n(2) == 1.



*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    ll cat[27];
    cat[0] = (ll)1;
    for (int m = 1; m < 27; m++) {
        cat[m] =  ((2*m) * (2*m - 1) * cat[m-1]) / ((m+1) * m);
    }

    ll superCat[27];
    superCat[0] = 1; superCat[1] = 1;

    for(int n = 2;n < 27; n++) {
        superCat[n] = (((6*n-9) * superCat[n-1]) - ((n-3) * superCat[n-2]) / n);
    }
    
    for(int m = 0; m < 27; m++) {
        cout << superCat[m] << endl;
    }

    return 0;
}

