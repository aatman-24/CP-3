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

void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
}

// It's Dart Sequence You can read more about it:

// but Sequence is = {1,1,1,1,3,8,21....}
// and for n > 6;

//                 /   (n^3 - 16n + 27)/6    if n is odd
//       v(n)  =  (
//                 \   (n^3 - 16n + 30)/6    if n is even


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int n,ans; 
	int case_n = 1;
	while(cin >> n)
	{
		if(!n) break;
		if(n <= 2) ans = 1;
		else if(n == 3) ans = 1;
		else if(n == 4) ans = 3;
		else if(n == 5) ans = 8;
		else if(n == 6) ans = 21;
		else if(n > 6 && n % 2 == 0)
		{
			ans = (n * n * n - (16 * n) + 30) / 6;
		}
		else
		{
			ans = (n * n * n - (16 * n) + 27) / 6;
		}

		printf("Case #%d: %d\n",case_n++, ans);
	}


	
	return 0;
}

