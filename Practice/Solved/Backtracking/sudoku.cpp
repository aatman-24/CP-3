#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;



typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


const int N = 9;

// vector<vii> AdjList;
// vector<pair<int,ii>> EdgeList;


int nr,nc,num;

void display(vvi board)
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++) cout << board[i][j] << ' ';
		cout << endl;
	}
	
}

bool isvalid(vvi board,int r,int c,int num)
{
	// check for the raw
	for(int x = 0 ; x < 9; x++)
	{
		if(board[r][x] == num) return false;
	}

	// check for the col
	for(int x = 0 ; x < 9; x++)
	{
		if(board[x][c] == num) return false;
	}



	// check for the (3 * 3) subboard.

	int r_top = (r / 3) * 3;   // (It's remove the fraction part so it become multiply of 3)
	int c_top = (c / 3) * 3;

	// int startRow = r - r % 3, startCol = c - c % 3;
            

	for(int row = 0 ; row < 3 ; row++)
	{
		for(int col = 0 ; col < 3; col++)
		{
			if(board[r_top+row][c_top+col] == num) return false;
		}
	}

	return true;

}


bool solveSudoku(vvi &board,int r,int c)
{
	// At last condition this r = 9 and c = 0.If we reach here it's means we solved sudoku.
	if(r == N && c == 0) {return true;}


	// its next raw and next col.
	int nr = 0;
	int nc = 0;

	if(c == N-1)
	{
		nr = r+1;
		nc = 0;
	}
	else 
	{
		nr = r;
		nc = c+1;
	}


	// if non-zero number than we skip it.
	if(board[r][c] != 0) return solveSudoku(board,nr,nc);


	// here we try all the number and if number is valid than we go forward if
	// any time we occur the solution is not possible than we do the backtrack/* and again 
	// set the number at 0 so next time with differnt number again we can try.*/
	for(int num = 1; num <= 9 ; num++)
	{
		if(isvalid(board,r,c,num))
		{
			board[r][c] = num;
			if(solveSudoku(board,nr,nc)) return true;
			board[r][c] = 0; // If we put here this statement than its backtracking.
		}
		// if here than its naive apporach.
		
	}
	return false;
}





int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vvi board = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    display(board);
    cout << endl;
	if(solveSudoku(board,0,0)) display(board);
	else cout << "oh fuck" << endl;

	return 0;
}

