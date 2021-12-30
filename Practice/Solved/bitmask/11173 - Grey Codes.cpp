#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#define ll long long

using namespace std;

// #Approach : Here we have to find the equivalent gray code of the binary code. As we know 
// how to find gray code from the binary : MSB same to same and the two-two pair EXOR opr.

// n = 9 ->  1010 
// n >> 1 -> 0101 and we do the EXOR.  and also for the length of the binary we also use (0 << n).


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int N;
	cin >> N;
	while(N--)
	{
		int k,n;
		cin >> k >> n;
		int ans = 0;
		ans = (ans << k) | (n ^ (n >> 1));
		cout << ans << endl;
	}

	return 0;
}




