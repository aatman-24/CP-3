#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long
#define EPS 1e-9
using namespace std;


// #Apporach : Here we have to reach 0 from differnce between two bills. First you need to get total 
// unit which is consumed.

// 1) either use direct function like here i used get_unit()
// 2) You can use the sum of the given consumption as upper limit to find the
// total unit until binary search your cost is given consumption like i did. notice mid is work as cur_unit. 

// Then you need to simply binary search when the differnce is exact given value.Every time you define
// two low_unit(which is our) and high_unit(neighbour unit) and try to get the cost of that using getbill()
// function and when both differnce is exact given value at a time return your cost.


ll a,b;
ll unit;


ll get_unit(ll price)
{
	ll cur_unit = 0;
	if(price >= 1)
	{
		if(price >= 100*2) {cur_unit += 100; price -= 100*2;}
		else {return price/2.0;}
	}
	if(price >= 1)
	{
		if(price >= 9900*3) {cur_unit += 9900 ; price -= 9900*3;}
		else {return cur_unit + price/3;}
	}
	if(price >= 1)
	{
		if(price >= 990000*5) {cur_unit += 990000 ; price -= 990000*5;}
		else {return cur_unit + price/5;}
	}
	if(price >= 1)
	{
		return cur_unit + price / 7;
	}
	return cur_unit;
}



ll getbill(ll n){

    ll e=0;
    if(n<=100) return n*2;

    e+=100*2;

    if(n<=10000)return e+(n-100)*3;

    e+=(10000-100)*3;

    if(n<=1000000)return e+(n-10000)*5;

    e+=(1000000-10000)*5;

    return e+(n-1000000)*7;

}

ll get_lowest_bill(ll l, ll h)
{
	ll mid = (l + h) / 2;

	ll x = getbill(mid);
	ll y = getbill(unit - mid);

	if((y - x) == b) return x;

	if(x > y || y - x < b) return get_lowest_bill(l, mid-1);
	else return get_lowest_bill(mid+1, h);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	while(cin >> a >> b)
	{
		if(a == 0 && b == 0) break;

		ll l = 0, h = a, mid;


		while(l <= h)
		{
			mid = (l + h) / 2;
			ll d = getbill(mid);

			if(d == a) break;
			else if(d > a) h = mid - 1;
			else l = mid + 1;
		}

		unit = mid;
		cout <<  get_lowest_bill(0,unit) << endl;
	}

	return 0;
}

