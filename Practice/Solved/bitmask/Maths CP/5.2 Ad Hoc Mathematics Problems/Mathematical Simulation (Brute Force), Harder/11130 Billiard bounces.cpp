#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// V = Vo + at -> V = 0 + at -> a = V / T;

// D = (V^2 - VO^2) / 2A -> V^2 - 0 / 2(V/T) -> V*T/2....


// So total distance = (V * T) / 2;

// we find both the horizontal and vertical distance traverl by ball with velocity = v;
// for horizontal -> cos(theta) and vertical -> sin(theta) and divided by the
// length of the Billiard table and width so we get the how many time it touched the side. 


// for vertical total_distance =  (V * T * cos(A)) / 2 + a / 2; (intital distance also covered).

// don't forget to change the angle A into radian.

const double conv = 3.14159265 / 180;


int distance_travel_x(int L, int A, int v, int s) //horizontal distance
{
	return ((L + v * s * cos(A * conv))) / (2*L);
}

int distance_travel_y(int L, int A, int v, int s)
{
	return ((L + v  *  s * sin(A * conv))) / (2*L);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int a,b,v,A,t;
	while(cin >> a >> b >> v >> A >> t)
	{
		if(!(a || b || v || A || t)) break;

		int o = distance_travel_x(a, A, v, t);
		int s = distance_travel_y(b, A, v, t);
		cout << o << ' ' << s << endl;

	}



	return 0;
}

