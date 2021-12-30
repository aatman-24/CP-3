#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

// Time Complexity = O(n^4) IN worst case but at all matrix is B.
// otherwise O((count*B_n^2)* A_n^2)

void display(std::vector<vector<char>> temp)
{
	int n = temp.size();
	cout << n << endl;
	for (double i=0; i < n ; i++)
	{
		for (double j=0; j < n; j++)
		{
			cout << temp.at(i).at(j) << ' ';
		}
		cout << endl;
	}
}


void rotate_into_90(vector<vector<char>> &temp)
{
	int n = temp.size(); //first swap vector into the two_d_array
	for(int i = 0 ; i < n/2 ; i++)
	{
		swap(temp.at(i),temp.at(n-1-i));
	}

	for(int i = 0 ; i < n ; i++) // Swap the [i,j] and [j,i] only once.
	{
		for(int k = i ; k < n ; k++)
		{
					char temp_char;
		temp_char = temp[i][k];
			temp[i][k] = temp[k][i];
		temp[k][i] = temp_char;
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

	int A_n,B_n;
	while((cin >> A_n >> B_n),(A_n || B_n))
	{
		char temp_char;
		vector<vector<char>> A;
		vector<vector<char>> B;
		for(int i = 0 ; i < A_n;i++) // Add into A
		{
			vector<char> temp;
			for(int j = 0 ; j < A_n ; j++)
			{
				cin >> temp_char;
				temp.push_back(temp_char);
			}
			A.push_back(temp);
		}
		for(int i = 0 ; i < B_n;i++)	// Add element into B
		{
			vector<char> temp;
			for(int j = 0 ; j < B_n ; j++)
			{
				cin >> temp_char;
				temp.push_back(temp_char);
			}
			B.push_back(temp);
		}
		for(int k = 0 ; k < 4 ; k++) // Four Time rotate 90-degree
		{
			int A_i_j,A_i;
			int count = 0;
			bool set;
			for(int i = 0 ; i < A_n - B_n + 1;i++)
			{
				for (int j = 0 ; j < A_n - B_n + 1 ; j++)
				{
					set = false;
					A_i = i;
					for(int p = 0; p < B_n ; p++,A_i++)
					{
						 A_i_j = j;
						for(int q = 0; q < B_n ; q++, A_i_j++)
						{
							if(A[A_i][A_i_j] != B[p][q])
							{
								set = true; 
								break;
							}
							if((p == B_n - 1 ) && (q == B_n - 1))
							{
								count++;
							} 
						}
						if(set) break;
					}
				}
			}
			if(k !=3 ) cout << count << ' ';
			else cout << count << endl;
			change_into_90(B);
		}
	}
	
}