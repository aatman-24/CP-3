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

#Approach : Here One thing you notice is that  b(0 ≤ b ≤ 50) Here 0's bit is also
counted.

Acutally b bits have maximum 2^K data.
And Here number of bits a compressed file -> 2^(K+1) (maximum)

when 0'bits allowd to have means that 0 bit can have -> so total data we can store is 2^0 -> 1 

So Just need to compare (N < 2^(b+1)) take it in long long bcz (b <= 50).

*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll N,K;
    while(cin >> N >> K)
    {
        if(N < (1LL << (K + 1))) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}

