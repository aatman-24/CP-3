#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#include <math.h>
#define ll long long

using namespace std;



// #Approach : we given a number we have to split number into 2 number such that (a + b = n).
// but we have to follow constraint like if n =  110110101. Herw i1 = 1, i2 = 3, i3 = 5, i4 = 6,
// i5 = 8 , i6 = 9.

// odd index (i1,i3,i5) a = 010010001 (put one where i1,i3,i5 is set in n)
// even index (i2,i4,i6) b = 100100100 (same as above)


// we take two number a=0,b=0;
// while(n != 0) (bcz set bit become 0 so at last is going to be 0)
// {
	// every time we find LSB which is set in n. Then we update a and b using bitwise or.
	// and then toggle the LSB so now it become 0. 
	// Now again find LSB and do the same.
	// one time for A and one time for B.
// }



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		int a = 0,b = 0,set = 1;
		int LSB = log2(n & (-n));
		while(n != 0)
		{
			if(set) 
			{
				
				a |= (1 << LSB);
				set = 0;				
			}
			else 
			{
				b |= (1 << LSB);
				set = 1;
			}
			n ^= (1 << LSB);
			LSB = log2(n & (-n));
		}
		cout << a << ' ' << b << endl;
	}
	


	return 0;

}