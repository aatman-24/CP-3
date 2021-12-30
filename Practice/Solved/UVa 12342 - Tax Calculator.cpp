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

void calculate_remaining_value(ll int &num,ll int percentage,double &tax)
{
	double cal;
	cal = (num * percentage) / 100.00;
	if ((cal < 2000) && (tax == 0 )) cal = 2000;
	tax += cal;
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
	int n = 0;
	cin >> test_case;
	const std::vector<ll int> criteria = {180000,480000,880000,1180000};
	const std::vector<ll int> percentage = {10,15,20,25};


	while(n++ < test_case)
	{
		ll int a;
		cin >> a;
		if (a <= 180000)
		{
			cout << "Case " << n << ": 0\n";
			continue;
		} 
		a = a - 180000;
		int i = 0;
		double total_tax = 0;
		ll int num;
		while(a != 0)
		{

			if(i >= 3) num = min(a,criteria[3]);
			else num = min(a,(criteria[i+1]-criteria[i]));
			i = min(i,3);
			ll int per = percentage.at(i);
			calculate_remaining_value(num,per,total_tax);
			a -= num;
			i++;
		}
		cout << "Case " << n << ": " << std::fixed << int(ceil(total_tax)) << endl;
	}
	
}	



