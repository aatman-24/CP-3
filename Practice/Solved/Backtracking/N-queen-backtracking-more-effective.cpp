#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;



// (N = 8 queen is vaild).


int N;
vi cols;
int count_possiblity = 0;

void display(vi &arr)
{
	for(double i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
	cout << endl;
}

bool isvalid(int r,int c)
{
	
	for(int raw = 0; raw < r; raw++)
	{
		if((cols[raw] >= 0) && (cols[raw] == c || (abs(cols[raw] - c) == abs(raw - r)))) return false;
	}
	return true;
}



void backtracking(int raw)
{

	if(raw == N) {
		display(cols);
		count_possiblity++;
		 return;
	}

	for(int col = 0; col < N; col++)
	{
		if(isvalid(raw,col))
		{			
			int temp_v = cols[raw]; //(1)
			cols[raw] = col;
			backtracking(raw+1);
			cols[raw] = temp_v; //(2)    -> This both line if you need all the possiblity than you need to undo the last value.
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
	

	N = 4;
	cols.assign(N,-1);
	cols[0] = 0;
	backtracking(0);
	cout << count_possiblity << endl;

	return 0;
}

