#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;


bool check_magic_matrix(string s)
{
	int n = sqrt(s.length());
	int c = 0;
	std::vector<string> matrix;
	for (int i = 0 ; i < n;i++)
	{
		string temp = "";
		for (int j = 0; j < n ; j++)
		{
			temp += s[c];
			c++;
		}
		matrix.push_back(temp);
	}

	for (int i = 0 ; i < n;i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (matrix[i][j] != matrix[j][i]) return 0;
		}
		
	}
	for (int i = 0 ; i < n ;i++)
	{
		if(matrix[i][i] != matrix[n-1-i][n-1-i])
			return 0;
	}
	return 1;	
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	int t;
	cin >> t;
	string s;
	getline(cin,s);
	int i = 0;
	while(i++ != t)
	{

		getline(cin,s);
		int n = s.length()-1;
		string new_string = "";
		for(int i = 0;i<=n;i++)
		{
			if ((int(s[i]) >= 65) && (int(s[i]) <= 122))
			{
				if (s[i] < 97)
				{
					new_string += char(int(s[i])+32);
				}
				else
				{
					new_string += s[i];
				}	
			} 
		}
		double new_n = sqrt(new_string.length());
		if ((int(new_n) - new_n) != 0) cout << "Case #" << i << ":\nNo magic :(\n";
		else{
			if(check_magic_matrix(new_string)) cout << "Case #" << i << ":\n" << int(new_n) << endl;
			else cout << "Case #" << i << ":\nNo magic :(\n";

		}


	}
}



