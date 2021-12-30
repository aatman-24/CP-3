#include <bits/stdc++.h>
#define ll long long

using namespace std;

// 621
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
		string en_msg;
		cin >> en_msg;
		if ( (en_msg == "1") | (en_msg == "4") | (en_msg == "78"))
		{
			cout << "+" << endl;
		}

		else if ((en_msg[en_msg.length()-1] == '5') & (en_msg[en_msg.length()-2] == '3' ))
		{
			cout << "-" << endl;
		}
		else if ((en_msg[0] == '9') & (en_msg[en_msg.length()-1] == '4' ))
		{
			cout << "*" << endl;
		}
		else if ((en_msg[2] == '0') & (en_msg[1] == '9' ) & (en_msg[0] == '1'))
		{
			cout << "?" << endl;
		}
		else
		{
			cout << "+" << endl;
		}
	}

}

