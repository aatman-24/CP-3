#include <bits/stdc++.h>
#define ll long long
using namespace std;


void show(vector<int> &v)
{
	for (double i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void sort_distinct(std::vector<vector<int>> &num_array,int key)
{
	int n = num_array.size();
	for(int i=0; i < n - 1; i++) // 0 -> Date 1 -> Month 2 -> Year
	{
		int j = i + 1;
		while ((j > 0) && (num_array[j][key] < num_array[j-1][key]))
		{
			swap(num_array[j-1],num_array[j]);
			j--;
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

	vector<vector<int>> in_vector;
	int n;
	cin >> n;
	in_vector.reserve(n);
	for (int i=0;i<n;i++)
	{
		std::vector<int> v;
		v.reserve(3);
		for (int j=0;j<3;j++)
		{	
			int a;
			cin >> a;
			v.push_back(a);
		}
		in_vector.push_back(v);
	}
	sort_distinct(in_vector,1);
	sort_distinct(in_vector,0);
	sort_distinct(in_vector,2);
	for (int i=0; i<n; i++)
	{
		for (int j = 0; j<3;j++)
		{
			cout << in_vector[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;		
}