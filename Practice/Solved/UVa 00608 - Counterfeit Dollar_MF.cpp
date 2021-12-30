#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
	}
}



void incremental(string &s,std::vector<int> &visited,std::vector<int> &character_vector,int step,int &visiter_token,std::vector<int> &permit)
{

	for (int i = 0 ; i < int(s.size()) ; i++)
	{
		if(permit[int(s[i])] != visiter_token)
		{
			if (step == 0) visited[int(s[i])] =  step;
			else visited[int(s[i])] +=  step;
			if ((step == 0) || (visited[int(s[i])] == 0)) permit[int(s[i])] = visiter_token;
			character_vector[int(s[i])] = 1;
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


	int t;
	cin >> t;
	while(t--)
	{
		std::vector<int> character_vector;
		std::vector<string> left;
		std::vector<string> right;
		std::vector<string> outcomes;

		std::vector<int> visited;
		std::vector<int> permit;
		int how_much_equal = 0;
		int visiter_token = 999;
		character_vector.assign(100,0);
		visited.assign(100,0);
		permit.assign(100,1);

		int a = 0;
		while(a++ != 3)
		{
			string left_string,right_string,out;
			cin >> left_string >> right_string >> out;
			if (out == "even")
			{
				incremental(left_string,visited,character_vector,0,visiter_token,permit);
				incremental(right_string,visited,character_vector,0,visiter_token,permit);
				how_much_equal++;
			}
			else if (out == "up")
			{
				incremental(left_string,visited,character_vector,1,visiter_token,permit);
				incremental(right_string,visited,character_vector,-1,visiter_token,permit);
			}
			else
			{
				incremental(left_string,visited,character_vector,-1,visiter_token,permit);
				incremental(right_string,visited,character_vector,1,visiter_token,permit);
			}
			right.push_back(right_string);
			left.push_back(left_string);
			outcomes.push_back(out);
		}
		int match_token = 3 - how_much_equal;
		for (int i = 0 ; i < 100 ; i++)
		{
			if((abs(visited[i]) == match_token) && (character_vector[i] == 1))
				{
					if (visited[i] < 1) cout << char(i) << " is the counterfeit coin and it is light.\n";
					else cout << char(i) << " is the counterfeit coin and it is heavy.\n";
				}
		}

	}
}	
