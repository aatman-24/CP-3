#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;



int N;
int r_temp,c_temp;


void display(vvi arr)
{
	for(double i = 0 ; i < N ; i++)
	{
		for(double j = 0 ; j < N; j++) cout << arr[i][j] << ' ';
		cout << endl;
	}
		
}

bool isvalid(vvi &board,int r,int c)
{
	// check for the col;
	for(int x = 0; x < N; x++)
		if(board[x][c] == 1) return false;


	// check upward side in diagonal ((3,3) -> (0-0))
	r_temp = r; c_temp = c;
	while(r_temp >= 0 && c_temp >= 0)
	{
		if(board[r_temp][c_temp] == 1) return false;
		r_temp--; c_temp--;
	}


	// check downward side in diagonal ((0,0) -> (3-3))
	r_temp = r; c_temp = c;
	while(r_temp < N && c_temp < N)
	{
		if(board[r_temp][c_temp] == 1) return false;
		r_temp++; c_temp++;
	}

	// check downward side in diagonal ((0,0) -> (0-0))
	r_temp = r; c_temp = c;
	while(c_temp >= 0 && r_temp < N)
	{
		if(board[r_temp][c_temp] == 1) return false;
		r_temp++; c_temp--;
	}

	// check downward side in diagonal ((3,3) -> (3-3))
	r_temp = r; c_temp = c;
	while(r_temp >= 0 && c_temp < N)
	{
		if(board[r_temp][c_temp] == 1) return false;
		r_temp--; c_temp++;
	}

	return true;
}

void backtracking(vvi &board, int raw)
{

	if(raw == N) {
		display(board);
		cout << endl;
		 return;
	}

	for(int col = 0; col < N; col++)
	{
		if(isvalid(board,raw,col))
		{
			board[raw][col] = 1;
			backtracking(board,raw+1);
			board[raw][col] = 0;
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
	
	int t; cin >> t;
	while(t--)
	{
		cin >> N;
		vvi board(N,vi(N,0));
		backtracking(board,0);
	}


	
	
	
	return 0;
}

