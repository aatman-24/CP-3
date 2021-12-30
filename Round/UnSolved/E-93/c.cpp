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

	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    int n;
	    cin >> s >> n;
	    std::vector<int> v;
	    for(int i = 0 ; i < int(s.size()); i++)
	    {
	    	int n = int(s.at(i));
	    	if(n == 48) v.push_back(0);
	    	else v.push_back(1);
	    }
	    string result = "";
	    int p = s.size();
	    int i = 0;
	    // n--;
	    while(i < p)
	    {
	    	if(i > n)
	    	{
	    		int n = v.at(i);
	    		if (n == 0) result += '0';
	    		else result += '1';
	    	}
	    	else if ((i+n) <= p)
	    	{
	    		int n = v.at(i);
	    		if (n == 0) result += '0';
	    		else result += '1';
	    	}
	    	i++;
	    }
	    if (int(result.size()) != p)
	    {
	    	cout << "-1\n";
	    }
	    else
	    {
	    	cout << result << endl;
	    }

	}


}	


// 3
// 101110
// 2
// 01
// 1
// 110
// 1
// 101110
// -1
// 110


