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

TIME COMPLEXITY - O(N) WHERE N = 10000;

- BRUTE FORCE IS WORKED HERE. 

SUMMARY:

    WE TRY TO ELIMINATE THE HIGHTEST POWER TERM,

    X^4 + X^2 + X + 1 - [X^3(X+1)] -> -X^3 + X^2 + X + 1 MEANS THAT WE ARE ADDING ->  (-1) * X^3 TERM AND ELIMINATE X^4 TERM.

    EQUATIONN IS  -> -X^3 + X^2 + X + 1,

    -X^3 + X^2 + X + 1 - [X^2(X+1)] ->  X + 1 MEANS THAT WE ARE ADDING ->  (-1) * X^2 BUT IT SUBTRACT WITH X^2 TERM,  AND ELIMINATE X^3 TERM.

    EQUATIONN IS  -> X + 1,

    X + 1 - 1(X+1) -> 0 

    ELEMINATE THE TERM MEANS -> MAKE THE COEFFICIENT OF THIS TERM = 0.

    SO IT IS VERY CLEAR THAT OUR ALGORIGHTM IS GOING TO WORK WE ELEMINATE HIGHEST TERM AND ADDING THE NEW TERM OF (-1) * X^(N-K),
    BUT IF THE TERM IS ALREADY THERE SO WE HAVE TO ADDITION WITH THIS NEW TERM.


    SO WE JUST NEED TO FOCUS ON THE COEFFICIENT OF ALL THE TERM. WHICH IS VERY SIMPLE.
    AND WE TRY TO ALWAYS ELIMINATE THE HIGHTEST TERM UNTIL WE REACH (K > N).


WHILE(N <= K)
{
    // NEW TERM POWER.
    NEW_TERM_POWER = N - K;

    // UPDATE THE COEFF OF THE NEW TERM.
    COEFF[NEW_TERM_POWER] += (-1) * (COEFF[n] * COEFF[k]); //  COEFF[K] = 1 (FOR THIS PROBLEM.)
}


AND LAST HOW TO KNOW THE REMIANDER IS 0 OR NOT?
-> CHECK ALL THE COEFF FROM THE 0->N-1 IF ALL ARE 0 MEANS REMAINEDER IS 0 OTHERWISE NOT.

*/










int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vi coeff;
    int n,k;
    int flag = -1;
    while(cin >> n >> k)
    {
        if(n == -1 && k == -1) break;
        else
        {
            coeff.assign(n+1,0);
            for(int i = 0; i < n+1; i++) cin >> coeff[i];


            if(k == 0) {cout << '0' << endl; continue;}

            while(n >= k)
            {
                coeff[n-k] += (flag * (coeff[n])); 
                n--;
            }


            if(accumulate(coeff.begin(),coeff.begin()+k,0) == 0) cout << '0' << endl;
            else
            {
                int i = 0;
                while(i <= n){
                    if(i == n) cout << coeff[n] << endl;
                    else  cout << coeff[i] << ' ';
                    i++;
                } 
            }


        }
    }


    return 0;
}

