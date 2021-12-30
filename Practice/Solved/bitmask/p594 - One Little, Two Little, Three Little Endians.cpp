#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


// #Approach : We given 32 bits with 4 bytes (8 bit per once).We have to replace whole bytes
// like (1->4) (2->3) (3->2) (4->1).
// we need a single byte so we can use the or opreator to make another number so we use.
// (32 bit number like ...0000000011111111...0000 like this so we can get those 8 bit easily)
// FF -> 11111111.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif



	int n;
	int ans;
	while(cin >> n)
	{
		ans = 0;
		ans |= (n << 24); 					// also we use this ((n & 0x000000FF) << 24)
		ans |= ((n & 0x0000FF00) << 8);	
		ans |= ((n & 0x00FF0000) >> 8);
		ans |= ((n & 0xFF000000) >> 24);
		cout << n << " converts to " << ans << endl;
	}
	return 0;
}
