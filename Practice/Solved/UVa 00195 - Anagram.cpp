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


void store(std::vector<int> a,std::vector<string> v,std::vector<string> &result) 
{ 
	string s = " ";
    for (int i = 0; i < int(a.size()); i++) { 
		s += v.at(a.at(i));        
    } 
    result.push_back(s);
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
	while (t--)
	{
		string word;
		cin >> word;
		std::vector<string> all_string;
		sort(word.begin(),word.end());
		string new_word = ""; 
		for (double i = 0; i < word.size() ; i++)
		{
			all_string.push_back(new_word + word.at(i));
		}
		std::vector<int> v;
		for (double i=0;i < all_string.size();i++) v.push_back(i);
		std::vector<string> result;
		sort(v.begin(),v.end());
		do
		{
			store(v,all_string,result);
		} while(next_permutation(v.begin(),v.end()));
		sort(result.begin(),result.end());
		double n = result.size();
		double i = 1;
		cout << result.at(0) << endl;
		while (i < n)
		{
			
			if (result.at(i-1) != result.at(i))
			{
				cout << result.at(i) << endl;
			}
			i++;
		}

	}






}


	