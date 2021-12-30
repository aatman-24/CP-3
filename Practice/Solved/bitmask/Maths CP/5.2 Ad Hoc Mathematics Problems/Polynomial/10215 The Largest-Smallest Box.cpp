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

double EPS = 1e-6;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

Here Volume V = X * (L - 2X) * (W - 2X).

Let's simplify this equation..
V = 4X^3 - 2(L+W)X^2 + (LW)X   

What is Minimum Value of Volume have is 0.

Let's take L+W = S and LW = P.
so, 

4X^3 - 2SX^2 + PX = 0
X(4X^2 - 2SX + P) = 0
SO ONE VALUE IS X = O AND ANOTHER (4X^2 - 2SX + P) = 0 --- (1)
FOR THIS,
(4X^2 - 2SX + P) = 0

DELTA = b^2 - 4ac -> 4S^2 - 4*4*P -> 4(L+W)^2 - 16(LW) -> F[L^2 + W^2 + 2LW - 4LW] -> 4(L-W)^2.

SO DELTA = 4(L-W)^2.


X = (-b +/- sqrt(delta)) / 2 
put all the value,
we got X = L/2 OR W/2 but we can take which is minimum. (bcz we find for the minimum of x).


so we got the minimum x = 0 or min(L/2,W/2)


for the maximum let's take first derivate of this equation we got,

-> d/dx(4X^3 - 2SX^2 + PX)

we got, 

F'(X) = 12X^2 -4SX + P 
F''(X) = 24X - 4S > 0 (FOR ALL X VALUE.)

SO F'(X) PROVIDE THE MAXIMUM VALUE OF X.


12X^2 -4SX + P  -> FIND THE ROOT OF THIS EQUATION SAME AS ABOVE.

YOU GOT,


X = (L+W) +- SQRT(L*L+W*W-L*W) / 6;

BUT FOR THE MAX VALUE WE TAKE,


X = ((L+W) - SQRT(L*L+W*W-L*W)) / 6; (WHY BCZ X IS DECREASE THE VOLUME IS INCREASE.)

SO FINALY,


MINIMUM VALUE OF X = 0 AND MIN(L/2,W/2)
AND MAXIMUM VALUE OF X =  ((L+W) - SQRT(L*L+W*W-L*W)) / 6;

*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    double L,W;
    while(cin >> L >> W)
    {
        double MAX = ((L + W) - sqrt(L*L+W*W-L*W)) / 6; 
        double MIN_VAL = min(L/2,W/2) + EPS;
        printf("%.3f 0.000 %.3f\n",MAX,MIN_VAL);
    }



    return 0;
}

