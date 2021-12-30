#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

// #apporach : total_square = (R - 8 + 1) * (C - 8 + 1).

// if you think
// when,
// R == C == 8  and bottom_right = 1, ans = 1;
// R == C == 8  and bottom_right = 0, ans = 0;    here total_square = 1 + 0 = 1


// R == C == 9  and bottom_right = 1, ans = 2;
// R == C == 9  and bottom_right = 0, ans = 2;    here, total_square = 2 + 2 = 4


// R == C == 10  and bottom_right = 5, ans = 1;
// R == C == 10  and bottom_right = 4, ans = 0;   here, total_square = 5 + 4 = 9.
// ....


// means that,

// if bottom_right = 1,  we got more or equal square.
// else we got less or equal square.

// here there is only two group, means   
// bottom_right's group have =  ceil(total_square/2)
// other group have square = floor(total_square/2)

// and total_square = (R-8+1) * (C-8+1)..

// IN SIMPLE LANGUGAGE,
// we can calculate the square from the bottom_right side how many space or grip both side we can
// use and mutliply it and majority is bottom_right group.


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	
	int R,C,b_w;
	while(cin >> R >> C >> b_w)
	{
		if(!(R || C || b_w)) break;

		double total_square = (R - 8 + 1) * (C - 8 + 1);

		if(b_w) cout << (int)ceil(total_square/2) << endl;
		else cout << (int)floor(total_square/2) << endl;
	}


	return 0;
}

