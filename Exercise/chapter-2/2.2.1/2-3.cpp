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


	int size,k;
	cin >> size >> k;


	std::vector<int> data;
	data.reserve(size);

	int a;
	for (int i = 0; i < size ; i++)
	{
		cin >> a;
		data.push_back(a);
	}


	sort(data.begin(),data.end());

	if ((data[0]+data[1] > k) || (data[size-1]+data[size-2] < k))
	{
		cout << "Not Possible such Number" << endl;
	}
	else
	{
		int i = 0;
		int j = 1;
		int print_or_not = 1; // Question logic is here. (Here total distinct_num find)
		while (i < size)
		{
			if (data[i] + data[j] ==  k)
			{
				cout << "First Number:  " << data[i] << "|  Second NUmber: " << data[j] << endl;
				print_or_not = 0;
				break;
			}
			else if (data[i] + data[size-1] < k)
			{
				i++;
				j = i + 1;
			}
			else if ((data[i] + data[j] > k) || (j >= size))
			{
				i++;
				j = i + 1;
			}
			else
			{
				j++;
			}
		}
		if(print_or_not) cout << "Not Possible such Number" << endl;
	}

}	



