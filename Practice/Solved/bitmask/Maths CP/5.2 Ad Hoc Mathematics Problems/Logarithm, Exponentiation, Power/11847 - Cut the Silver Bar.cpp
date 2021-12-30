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
Simple,
Try with 1,2,3,4,5,6,7 You got Idea.
For 5 -> 1,2,3(part) and three cut using this you can make 4,5. So It's -> 2 (cut).
For 6 -> 1,2,4(part) and three cut using this you can make 5,6. So It's -> 2 (cut).
For 7 -> 1,2,5(part) and three cut using this you can make 6,7. So It's -> 2 (cut).
For 8 -> 1,2,6(part) and three cut using this you can make 5,7,8 So It's -> 2 (cut).

For 9 Le't discuss deep,
    creditor    miner
1   1           8
2   2           1,6
3   2,1         6
4   3,1         2,3
5   3,2         1,3
6   3,3         2,1
7   3,3,1        2
8   3,3,2       1
9   3,3,2,1     -  (So Total 3 Cut)


Same For 10,
4   3,1         2,4
5   3,2         1,4
6   3,2,1       4
7   4,2,1       3 
8   4,3,1       2
9   4,3,2       1
10  4,3,2,1     - (So Total 3 Cut)


Same for 11,
4   3,1         2,5
5   3,2         1,5
6   3,2,1       5
7   5,2       3,1 
8   5,2,1       3
9   5,3,1       2
10  5,3,2       1
11  5,3,2,1     - (So Total 3 Cut)

Same For until the 15.
Now for 16 We have to Cut 1 extra cut needed.

Like,
Check the alog.

Another Approach:
- 2^0 2^1 2^2 2^3 2^4 2^5.... (2^K) -> means from the 2^K to 2^(K+1) It's K cut needed.
we got sequence like 1|2 3|4 5 6 7|8 9 10 11 12 13 14 15|... so I think about it after the
first soultion.
*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int N;
    while(cin >> N)
    {
        if(N == 0) break;
        int i = 2;
        int cnt = 0;
        while(N)
        {
            N /= i;
            if(N) cnt++;
        }
        cout << cnt << endl;


        // Or floor(log2(N)) is also true.

        // cout << floor(log2(N)) << endl;
    }


    return 0;
}

