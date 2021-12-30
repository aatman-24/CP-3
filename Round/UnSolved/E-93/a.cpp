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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int test_case;
	cin >> test_case;
	while(test_case--)
	{
		int n;
		cin >> n;
		int size = 2*n - 1;
		string s;
		cin >> s;
		if (s.size() == 1) 
		{
			cout << s << endl;
			continue;
		}
		int number_of_0 = 0;
		int number_of_1 = 0;
		for (int i = 0; i <= size - n; i++)
		{
			int p = i;
			int c = n;
			while(c--)
			{
				if (s.at(p) == '0') number_of_0 += 1;
				if (s.at(p) == '1') number_of_1 += 1;
				p++;
			}
		}
		int a = ceil((number_of_1*1.0));
		int b = ceil((number_of_0*1.0));
		string result = " ";
		while(a > 0)
		{
			result += '1';
			a--;
		}
		// cout << a << endl;
		while(b > 0)
		{
			result += '0';
			b--;
		}
		for(int i=1; i <= n; i++)
		{
			cout << result.at(i);
		}
		cout << endl;

	}
}	



