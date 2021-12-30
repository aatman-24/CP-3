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


	sort(data.begin(),data.end());

	int i = 0;
	int j;
	int distinct_num = 0; // Question logic is here. (Here total distinct_num find)
	while (i < size)
	{
		j = min(i + 1,size-1);
		while(data[i] == data[j])
		{
			if (j >= size) break;
			j++;
		}
		i = j;
		distinct_num++; // And also do change as per requirment.
	}

	cout << distinct_num << endl;
}	



