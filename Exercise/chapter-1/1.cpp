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

void swap(int* f_num,int* s_num)
{

	int temp = *s_num;
	*s_num = *f_num;
	*f_num = temp;
}

void sort_distinct(std::vector<int> &num_array)
{
	int n = num_array.size();
	for(int i=0; i < n - 1; i++)
	{
		int j = i + 1;
		while ((j > 0) && (num_array[j] <= num_array[j-1]))
		{
			int temp = num_array[j-1];
			num_array[j-1] = num_array[j];
			num_array[j] = temp;
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

	// Exercise 1.2.3 - Language Fundamental regarding.....

	// Question - 4
	std::vector<int> v;
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		v.push_back(a);

	}
	sort_distinct(v);
	for (double i=0; i< v.size();)
		{
			cout << v.at(i);
			if (v[i] == v[i+1])
				{
					i += 2;
				}
			else
			{
				i++;
			}
		}
	v.clear();
	// Note : Passing the vector to function.Fucntion create a new copy so it 
			// will not affect the main function copy if you want that changes is made into
			// the main vector then pass through the addresss.Just like we did above.


	// Question - 5
	Who is the most oldest ?
	



	return 0;		
}