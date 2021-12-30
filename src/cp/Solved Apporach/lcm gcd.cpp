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

int GCD(int a,int b)
{
	if (a == 0) return b;
	else return GCD(b%a,a);
}

// extended_Euclidean_alog = aX+bY --> gcd(x,y)
int extended_Euclidean_alog(int x,int y,int* a,int* b) 
{
	if (y==0)
	{
		*a  = 1;
		*b = 0;
		return x;
	}
	int gcd = extended_Euclidean_alog(y,x%y,a,b);
	int a1,b1; // To store the value so a and b is not changed.
	a1 =  *b;
	b1 = *a - int(x/y) * (*b);
	*a = a1;  // Assgain  the new value of a and b from previous one.
	*b = b1;
	return gcd;
}

int LCM(int a[], int n)
{
	int ans;
	ans = a[0];
	for (int i = 0;i<n;i++)
	{
		ans = (ans * a[i])/GCD(ans,a[i]);
	}
	return ans;
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
	cin >> t ;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0;i<n;i++)
		{
			cin >> a[i];
		}
		cout << LCM(a,n);

	 }
	return 0;
}	