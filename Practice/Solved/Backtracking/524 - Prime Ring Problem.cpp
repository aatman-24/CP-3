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


// #Approach : here we have to find the ring such that all adjancent number sum is prime.
// -> odd + even = prime. I arrange my index like this and using backtracking it is possible.

// It takes O(N^(N/2)). So its work maybe until N <= 16.



vi prime_numbers,final_ar,arr,visited;

int N;
int s_index;

void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++) 
		if(i != arr.size() - 1) printf("%d ",arr[i]);
		else printf("%d\n",arr[i]);	
}

bool isvalid(int index,int j)
{
	// cout << index << endl;

	if(visited[index]) return false;
	if(!prime_numbers[index + final_ar[j]]) return false;
	// display(final_ar);
	if(j == N-2 && (prime_numbers[1+index] == 0)) return false; 
	// if((j == N-1) && (prime_numbers[1+index] == 0)) return false;
	return true;

	// if((p_val + arr[index]) % 2 == 0) return false;
	// if(index % 2 == 0 && arr[index] % 2 != 0) return false;
	// if(index % 2 != 0 && arr[index] % 2 == 0) return false;
	// if(visited_n == N - 2 && ((arr[index] + 1) % 2) == 0) return false;

	// // cout << p_val << '|' << arr[index] << endl;
	// return true; 
}


void backtracking(int nIndex,int j)
{
	if(j == N-1) {display(final_ar); return;}
	// if(nIndex == N - 1) {cout << "heldo" << endl; return;}

	if(nIndex % 2 == 0) s_index = 0;
	else s_index = 1;

	for(int index = s_index ; index < N - 1 ; index += 2)
	{

		if(isvalid(arr[index], j))
		{

			int pre_val = final_ar[j+1];
			visited[arr[index]] = 1;
			final_ar[j+1] = arr[index];

			backtracking(index+1,j+1);

			visited[arr[index]] = 0 ;
			final_ar[j+1] = pre_val;
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
	

	prime_numbers.assign(50,0);
	vi acutal_numbers = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37,41,43,47};
	for(double i = 0 ; i < acutal_numbers.size(); i++) prime_numbers[acutal_numbers[i]] = 1;


	int t = 1;
	scanf("%d\n",&N);
	while(true)
	{

		final_ar.assign(N,0);
		final_ar[0] = 1;
		
		arr.assign(N-1,0);
		visited.assign(N+1,0);

		for(int i = 0 ; i <= N-2 ; i++) arr[i] = i+2;

		printf("Case %d:\n",t);
		backtracking(0,0);
		if(scanf("%d\n",&N) == EOF) break;
		printf("\n");
		t++;
	}

	return 0;
}

 