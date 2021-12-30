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



	vector<string> all_per,result;
	string s = "WORDFISH";
	for(double i = 0 ; i < s.size() ;i++)
	{
		s = "WORDFISH";
		sort(s.end() - i ,s.end());
		do
		{
			if(s == "WORDFISH") break;
			all_per.push_back(s);
			
		}
		while(next_permutation(s.begin(),s.end()));
		if(all_per.size() > 10) break;
		all_per.clear();

	}
	int loop_cn_element = all_per.size();
	int start;
	if (loop_cn_element > 10 ) start = loop_cn_element - 10;
	else start = 0;
	while(start < loop_cn_element)
	{
		result.push_back(all_per[start]);
		start++;
	}
	s = "WORDFISH";
	int before_total_cn = result.size();
	double count = 0 ;
	do
	{
		result.push_back(s);
		count++;
	}while((count < (21 - before_total_cn)) && (next_permutation(s.begin(),s.end())));

	int index,cost;
	int lt = 99999999;
	int value;
	for(double j = 0 ; j < result.size();j++)
	{
		string k = result[j];
		// index = 0;
		// value = 0;
		for(double i = 1 ; i < k.size(); i++)
		{
			value = abs(int(k[i-1]) - int(k[i]));
			if(value < lt)
			{
				lt = value;
				cost = lt;
				index = j;
			}
		}
		// if(lt > value)
		// {
		// 	lt = value;
		// 	index = j;
		// }
	}
	cout << index << cost << endl;


}	



