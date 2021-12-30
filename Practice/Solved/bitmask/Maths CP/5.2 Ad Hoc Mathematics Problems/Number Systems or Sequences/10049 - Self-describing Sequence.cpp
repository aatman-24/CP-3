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


// #Explaination : Sequence is formed like,

// initial value,

// 1 2 2 3 3 4 4 4

// like see for the 2nd place value is -> 2 so (2 is for 2 times)
// for 3rd place value is -> 2 so (3 is for 2 times)
// for 4th place value is -> 3 so (4 is for 3 times)

// ....

// #I used apporach Here is little bit trickier.
// I make sequence like....

// 1 2 3 4 5  6  7  8  9  10  11 (f(n) value)
// 1 3 5 8 11 15 19 23 28 33  38 (last pos for above value...) It's means if n is 21 then f(n) = 8.

// how i generate?
// -> I used three pointer,
// j         increasing number (1 -> Unknown)
// cur_val   Acutual Number n.....
// index 	  pointer.



		 	
// 1 2 3 4 5  6 
// 1 3 5 8 11 


// if our sequence is like this...

// j = 6;
// cur_val = 11;
// index = 4   (bcz arr[3] < j) arr[4] > j....

// for the given j if it's value is less than arr[index] it means that it occurance is index times...

// like here for the 6 arr[4] > 6.... so (6 6 6 6) It comes for time so we directly count value;
// cur_val += 4 so 6 comes at last 15.... index number.



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vi arr = {1,3};
	int j = 3;
	int cur_val = 3;
	int index = 2;

	while(cur_val <= 2000000000)
	{
		if(arr[index-1] < j) index++;
		cur_val += index;
		arr.push_back(cur_val);
		j++;
	}
	

	int N;
	while(cin >> N)
	{
		if(!N) break;
		int i = 1;
		while(arr[i-1] < N) i++;
		cout << i << endl;
	}


	return 0;
}

