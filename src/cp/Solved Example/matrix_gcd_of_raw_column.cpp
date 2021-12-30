#include <bits/stdc++.h>
#define ll long long
using namespace std;

void show(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

int gcd(int a,int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b,a%b);
}

int gcd_of_array(vector<int> a)
{
	int gcd_of_two_number = a[0];
	for (double i=0; i < a.size() -1 ;i++)
	{
		gcd_of_two_number = gcd(gcd_of_two_number,a[i+1]);
	}
	return gcd_of_two_number;
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
		int m,n;
		cin >> n >> m;
		vector <vector<int>> input_array;
		for (int i=0;i<n;i++)
		{
			std::vector<int> v;
			for (int j=0;j<m;j++)
			{
				int o;
				cin >> o;
				v.push_back(o);
			}
			input_array.push_back(v);
		}
		std::vector<int> raw; 
		// Addding element into the raw
		for (int i=0;i<n;i++)
		{	

			 raw.push_back(gcd_of_array(input_array[i]));
			
		}
		// Adding element into the column
		std::vector<int> column; 
		vector<int> inner;
		for (int j=0;j<m;j++)
		{
			for (int k=0;k<n;k++)
			{	
				inner.push_back(input_array[k][j]);
			}
			column.push_back(gcd_of_array(inner)); 
			inner.clear();
		}
	for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
	
				cout << max(raw[i],column[j]) << " ";
			}
			cout << "\n" << endl;
		}
	return 0;
	
	}
}	