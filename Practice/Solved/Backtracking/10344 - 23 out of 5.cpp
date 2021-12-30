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


// #Apporach : backtrack with all the mark sign. But Here one more thing we also have to try
// all combination because as per the statement,

// 	π : {1, 2, 3, 4, 5} → {1, 2, 3, 4, 5} is a bijective function.

// It means when the our output is depedent  not only given a[0] and a[1] but we have to try
// all bcz it is bijective function. 


int N = 5;
int TARGET = 23;
vi arr(N,0);
vector<char> mark = {'+','*','-'};


int do_opreation(int num1, int num2, char mark_sign)
{
	if(mark_sign == '+') return (num1 + num2);
	if(mark_sign == '-') return (num1 - num2);
	return (num1 * num2);
}

void display(vi &arr)
{
	for(double i = 0; i < arr.size() ; i++) cout << arr[i] << ' ';
	cout << endl;
}


bool backtrack(int nIndex,int sum_ans)
{
	if(nIndex == 5 && sum_ans == 23)  return true;
	if(nIndex == 5)  {return false;}

	for(int i = 0 ; i < 3; i++)
	{
		int temp = sum_ans;
		sum_ans =  do_opreation(sum_ans,arr[nIndex],mark[i]);
		if(backtrack(nIndex+1,sum_ans)) return true;
		sum_ans = temp;
	}
	return false;
}


bool start_from_here_backtrack(vi arr)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		int sum_ans_for_first_two = do_opreation(arr[0],arr[1],mark[i]);
		if(backtrack(2,sum_ans_for_first_two)) return true;
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
	

	while(true)
	{
		for(int i = 0 ; i < N ; i++) cin >> arr[i];
		if(!(arr[0] || arr[1] || arr[2] || arr[3] || arr[4])) break;
		int set = 0;
		sort(arr.begin(),arr.end());
		do{
			if(start_from_here_backtrack(arr)) 
			{
				cout << "Possible" << endl;
				set = 1;
				break;
			}

		} while(next_permutation(arr.begin(),arr.end()));
		if(!set) cout << "Impossible" << endl;
	}

	return 0;
}

