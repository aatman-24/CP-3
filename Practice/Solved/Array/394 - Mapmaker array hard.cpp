#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

class ARRAY
{
public:
	string name;
	int B,CD,D;
	vector<int> Ld;
	vector<int> Ud;
	vector<int> Cd;
};

int finding_index(vector<pair<string,ARRAY>> &array_element , string s)
{
	for (double i = 0 ; i < array_element.size(); i++)
	{
		if (array_element.at(i).first == s) return i;
	}
	return -1;
}


void display(std::vector<pair<string,ARRAY>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i).first   << '\t'  << temp.at(i).second.name << endl;
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

	int N,R; cin >> N >> R;
	vector<pair<string,ARRAY>> array_element;
	while(N--)
	{ 
		ARRAY a;
		cin >> a.name;
		cin >> a.B >> a.CD >> a.D;
		a.Ld.assign(a.D,0);
		a.Ud.assign(a.D,0);
		int p,q; 
		for (int i = 0; i < a.D ; i++)
		{
			cin >> p >> q;
			a.Ld[i] = p;
			a.Ud[i] = q;
		}
		array_element.push_back({a.name,a});
	}
	while(R--)
	{
		std::vector<int> ith_array;
		string arr_name; cin  >> arr_name;
		int i = finding_index(array_element,arr_name);
		ARRAY obj =  array_element[i].second;
		obj.Cd.assign(obj.D+1,0);
		obj.Cd[obj.D] = obj.CD;
		int d = obj.D;
		while(d--)
		{
			int a;cin >> a;
			ith_array.push_back(a);
		}
		for(int d = obj.D - 1 ; d > 0 ; d--)
		{
		
			obj.Cd[d] = (obj.Cd[d+1]) * (obj.Ud[d] - obj.Ld[d] + 1);
		}
		int sum = 0,final_sum = 0;
		for (int i = 0;i < obj.D; i++)
		{
			sum += (obj.Cd[i+1] * (obj.Ld[i]));
			final_sum += (obj.Cd[i+1] * ith_array[i]);
		}
		final_sum += (obj.B - sum);
		cout << obj.name << '[';
		for(double i = 0 ; i < ith_array.size();i++) 
			{
				if(i == 0) cout << ith_array.at(i);
				else cout << ", " << ith_array.at(i);
			}
		cout << "] = " << final_sum << endl; 
	}

	
}	



