#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N,D;
vi arr;

void display(vi arr)
{
	for(double i = 0; i < arr.size() ; i++) cout << arr[i];
	cout << endl;
}


void backtracking(int nIndex,int nZero)
{
	if(nZero == D)
	{
		display(arr);
		return;
	}
	if(nIndex == N) return;

	for(int i = nIndex ; i < N; i++)
	{
		if(nZero+1 <= D)
		{
			nZero++;
			arr[i] = 0;
			backtracking(i+1,nZero);
			arr[i] = 1;
			nZero--;
		}
	}
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	


	// N = 4;
	// D = 2;
	// arr.assign(N,1);
	// backtracking(0,0);






	int t; cin >> t;
	int no_of_1;
	while(t--)
	{
		cin >> N >> no_of_1;
		D = N - no_of_1;
		arr.assign(N,1);
		backtracking(0,0);

		if(t)cout << endl;
	}



	return 0;
}

