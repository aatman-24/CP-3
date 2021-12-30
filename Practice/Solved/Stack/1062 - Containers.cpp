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

	double t = 0,j,temp;
	vector<int> result;
	string s;
	while(cin >> s)
	{
		if (s == "end") break;
		result.clear();
		result.push_back(int(s.at(0)));
		for(double i = 1; i < s.size() ;i++)
		{
			temp = int(s.at(i));
			j = 0;
			while(j != result.size())
			{
				if(temp <= result.at(j))
				{
					result[j] = temp;
					break;
				}
				j++;
			}
			if(j == result.size()) result.push_back(temp);
		}
		cout << "Case " << ++t << ": " << result.size() << endl;


	}

}	



