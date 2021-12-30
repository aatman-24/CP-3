#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
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

	
	int size;
	cin >> size;

	std::vector<int> data;
	data.reserve(size);

	int a;
	for (int i = 0; i < size ; i++)
	{
		cin >> a;
		data.push_back(a);
	}

	// display(data);

	// sort(data.begin(),data.end());

	int i = 0;
	int j = 0;
	int max_length = 0;// Question logic is here. (Here total distinct_num find)
	while ((i < size - 1) & (j < size))
	{
		j = i + 1;
		int k = 0;
		while((data[i] < data[j]))
		{
			i++;
			j++;
			k++;
			if (j >= size) break;
		}
		max_length = max(max_length,k); 
		i = j;
		
	}
	cout << "Max Length is  " << max_length + 1  << endl;
}	



