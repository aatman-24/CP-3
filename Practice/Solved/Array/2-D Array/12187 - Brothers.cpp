#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<std::vector<int>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		for(double j = 0 ; j < temp.at(i).size(); j++)
		{
			if (j == temp.at(i).size()-1 ) cout << temp.at(i).at(j) << endl;
			else cout << temp.at(i).at(j) << ' ';
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

	int temp;
	int Token = 1;
	int new_x,new_y;
	vector<int> temp_vector,temp_just;
	vector<vector<int>> two_day_vector;
	vector<vector<int>> token_verification;

	int x[] = {1,-1,0,0};
	int y[] = {0,0,1,-1};

	int n,r,c,k;
	while(cin>>n>>r>>c>>k,(n||r||c||k))
	{

		vector<pair<int,int>> heirs;
		for(int i = 0 ; i < n ; i++)
		{
			if(i == n-1) heirs.push_back({i,0});
			else heirs.push_back({i,i+1});
		}
		two_day_vector.clear();
		vector<vector<int>> matrix;
		for(int i = 0 ; i < r ; i++)
		{
			for(int j = 0 ; j < c ;j++)
			{
				cin >> temp;
				temp_vector.push_back(temp);
			}
			matrix.push_back(temp_vector);
			two_day_vector.push_back(temp_vector);
			temp_vector.clear();
		}
		for(int i = 0 ; i < r ; i++)
			{
				vector<int> temp_okay_now(c,0);
				token_verification.push_back(temp_okay_now);
			}

		for (int how_much = 0 ; how_much < k ; how_much++)
		{
			for(double i = 0 ; i < r ;i++)
			{
				for(double j = 0 ; j < c;j++)
				{
					int i_am = matrix[i][j];

					int my_heir = heirs.at(i_am).second;

					for(int t = 0 ; t <= 3; t++)
					{
							new_x = i+x[t];
							new_y = j+y[t];

							if ((new_x < 0) || (new_x >=  r)) continue;
							if ((new_y < 0) || (new_y >=  c)) continue; 

							if (matrix[new_x][new_y] == my_heir)
							{
								two_day_vector[new_x][new_y] = i_am;
								token_verification[new_x][new_y] = Token;
							}
					}
					
				}
			}
			matrix = two_day_vector;
			Token++;
		}
		
		display(matrix);
	}

	
}	



