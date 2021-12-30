#include <bits/stdc++.h>
#define ll long long

using namespace std;

void price_relaxtion(double* money,double drp_value,int* month,double* l_money,int a, double installment)
	{
		if(a)
		{
			(*l_money) -= installment;
			(*month)++;
		}
		*(money) -= ((*money) * drp_value);

	}

bool check_price_comprasion(double money,double loan,int total_month,int month)
{
	cout << loan << " " << money << endl;
	return ((loan <= money) or ( total_month < month ));

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	while (cin)
	{
		double total_month,down_pay,loan_amount,t;
		cin >> total_month >> down_pay >> loan_amount >> t;
		// cout << total_month << " " <<down_pay << " " << loan_amount << endl;
		double total_price = down_pay + loan_amount;
		double install_ment = loan_amount / total_month;
		int month = 1;
		double a,depreciation_value;
		cin >> a >> depreciation_value;
		price_relaxtion(&total_price,depreciation_value,&month, &loan_amount , 0 , install_ment);
		if (check_price_comprasion(total_price,loan_amount,total_month,month))
				{
					cout << month << endl;
					while (t > 0)
					{
						int a,b;
						cin >> a >> b;
						t--;
					}
				}	
		while(t>0)
		{
			// cout << t << endl;
			double a,depreciation_value;
			cin >> a >> depreciation_value;
			if (t == 1)
			{
				while (1 & (total_price <= loan_amount))
				{
					price_relaxtion(&total_price,depreciation_value,&month,&loan_amount,1,install_ment);
					if (check_price_comprasion(total_price,loan_amount,total_month,month))
					{
						break;
					}
					
				}
			}
			else
			{
				for (double i=0 ; i < a ;i++)
					{
						price_relaxtion(&total_price,depreciation_value,&month,&loan_amount,1,install_ment);
						if (check_price_comprasion(total_price,loan_amount,total_month,month))
							{
								break;
							}

					}
			}
			if (check_price_comprasion(total_price,loan_amount,total_month,month))
				{
					cout << month << endl;
					while (t > 0)
					{
						int a,b;
						cin >> a >> b;
						t--;
					}
					break;
				}
		}
	}
	return 0;
}

