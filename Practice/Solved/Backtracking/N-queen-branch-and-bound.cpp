#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;




// #apporach : You can check prepcoding branch and bound video for n queens problems.
// If more constraint given in board then we can easily modify this problems using two-d board. and given constrain in
// isvalid function.

// Notes : In matrix,
//		   (r+c) is same for right diagonal.
// 		   (r- c) is same for left diagonal but if need positive index we can add offset. (here offset = N - 1)

int N;
vi cols;

bitset<30> cw, ld, rd;

int count_possiblity = 0;

void display(vi &arr)
{
	for(double i = 0 ; i < arr.size() ; i++) cout << arr[i] << ' ';
	cout << endl;
}

bool isvaild(int r,int c)
{
	if(cw[c] == true || rd[r+c] == true || ld[r-c+N-1] == true) return false;
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
		// if(isvaild(raw,col))  (same with below line)
		if(cw[col] != true && rd[raw+col] != true && ld[raw-col+N-1] != true)
		{		
			cw[col] = rd[raw + col] = ld[raw - col + N - 1] = true;	// set cw,rd,ld (bound)

			cols[raw] = col; // To store the actual value.

			backtracking(raw+1);

			cw[col] = rd[raw + col] = ld[raw - col + N - 1] = false;	// reset cw,rd,ld (backtrack)
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
	cols.assign(N,0);
	backtracking(0);
	cout << count_possiblity << endl;

	return 0;
}



// Like in,

// UVa 11195 -> some of the bad cells given where we can not put the our queens for this we can update the function like this.
// (N = 12 queen is vaild).

// void backtrack(int c) {

	// if (c == n) { ans++; return; } // a solution
	// for (int r = 0; r < n; r++) // try all possible row
	// if (  [board[r][c] != ’*']    && !rw[r] && !ld[r - c + n - 1] && !rd[r + c]) {  <- see here.
	// rw[r] = ld[r - c + n - 1] = rd[r + c] = true; // flag off
	// backtrack(c + 1);
	// rw[r] = ld[r - c + n - 1] = rd[r + c] = false; // restore
// } }