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
			cout << abs(temp.at(i).at(j)) << ' ';
		}
		cout << endl;
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

	// Prirequisite 
	int x[] = {1,-1,0,0};
	int y[] = {0,0,1,-1};
	vector<pair<int,int>> indexes = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

	// Variable Declaration
	vector<vector<int>> matrix;
	int new_x,new_y;

	string s;
	int i = 0;
	while(getline(cin,s))
	{
		for(int i = 0 ; i < 3 ;i++)
		{
			vector<int> temp(3,0);
			matrix.push_back(temp);
		}
		for(double i = 0 ; i < s.length();i++)
		{
			int index = int(s.at(i)) - int('a');
			int cur_x = indexes.at(index).first;
			int cur_y = indexes.at(index).second;
			matrix[cur_x][cur_y] -= 1;
			if( matrix[cur_x][cur_y] < -9 ) matrix[cur_x][cur_y] = 0 ;
				for(int t = 0 ; t <= 3; t++)
				{
					new_x = cur_x+x[t];
					new_y = cur_y+y[t];

					if ((new_x < 0) || (new_x >=  3)) continue;
					if ((new_y < 0) || (new_y >=  3)) continue; 
					matrix[new_x][new_y] -= 1;
					if( matrix[new_x][new_y] < -9  ) matrix[new_x][new_y] = 0;

				}
		}
		cout << "Case #" << i+1 << ':' << endl;
		for (double i=0; i < matrix.size() ; i++)
		{ 
			for(double j = 0 ; j < matrix.at(i).size(); j++)
			{
				if (j == matrix.at(i).size()-1 ) cout << abs(matrix.at(i).at(j)) << endl;
				else cout << abs(matrix.at(i).at(j)) << ' ';
			}
		}
		matrix.clear();
		i++;
	}

}	



