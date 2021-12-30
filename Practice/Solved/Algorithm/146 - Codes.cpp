#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <string>

#define ll long long


using namespace std;




void display(std::vector<std::vector<int>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		for(double j = 0 ; j < temp.at(i).size(); j++)
		{
			cout << temp.at(i).at(j) << ' ';
		}
		cout << endl;
	}
}

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';	
	}
	cout << endl;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	while(cin >> s)
	{
		if (s == "#") break;
		string temp_s = s;
		// sort(s.begin(),s.end()); // I mistaked here first no need to sort all string.
		int set = 0;
		do
		{	
			if(set == 1)
			{
				cout << s << endl;
				set = 2;
				break;
			}
			if(s == temp_s)
			{
				set = 1;
			}

		}while(next_permutation(s.begin(),s.end()));
		if(set != 2) cout << "No Successor" << endl;
	}

}	



