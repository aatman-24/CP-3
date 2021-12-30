#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double,double> pdd;


// #Approach :

// Here We have to Consider Home as a center point of the triangle.

// ---------------------------------------------------------------------------
// Some Properies About equivalent triangle:

// height of traingle = (sqrt(3)/2)*a;    where a = length of side.
// center of traingle is divide the height by 2:1 ratio in equivalent traingle.
// so for,

// 			/
// 		/		\
// 	/				\
// /	_	_	_	_	_	_  

// - This Type of traingle (regular) has upward side 2h/3 and downward side
// h/3.

// --------------------------------------------------------------------------

// Now try to solve the problem,

// RULES 1: I am going to consider the distance from the top of the traingle.
// RULES 2: We consider x-axis distance from the center of the top traingle.

// Let's Try with single triangle first,

// - For regular traingle, center point = (0,2h/3);
// 	  reverse_triangle, center point = (0,h/3);

// Now check the given figure....

// see the triangle index very carefully if you can see....

// for the first level -> 0
// 		second level -> 1,2,3
// 		third level -> 4,5,6,7,8
// 		fourth level -> 9,10,11,12,13,14,15


// - One point you should check out is, the height or base level of any triangle
// is int(sqrt(index)).

// Let's see..


// for the first level -> 0    -> 0
// 		second level -> 1,2,3  -> 1
// 		third level -> 4,5,6,7,8  -> 2
// 		fourth level -> 9,10,11,12,13,14,15 -> 3

// So we use like that for the first level we use this as base level,

// (sqrt(0)+1)*h - h/3 = 2h/3 (we do the reverse calculation here).

// same for the second level reverse_triangle,

// (sqrt(2)+1)*h - 2h/3 = h+h/3.

// so we are done in Y axis.


// Now for the x-axis,

// check on figure,
// from the middle line you have to count how many recatnagle is between there,
// and you take half of this because all recatnagle contribute only 1/2.


// formula for this: normalize =  index - int(sqrt(index)) * int(sqrt(index));

// using this we got the normalize the form and traingle number from the
// left side...

// and you if need the triangle X center:

// than you also need to subtract int(sqrt(index)) from the normalize,

// so finally,

// X = (0.5) * (normalize - int(sqrt(index)));

// This is all possible bcz the traingle is equivalent.




double x,y,disp,result,x1,y1,x2,y2;
int height_of_triangle;


double h = sqrt(3)/2;
double h_3 = h/3;
double h2_3 = 2*h/3;

// #Top point of triangle we consider as = (0,0);
pdd find_center_of_triangle(int index){

	height_of_triangle = int(sqrt(index));

	y = (height_of_triangle+1) * h;

	if(height_of_triangle % 2 == index % 2)
	{
		y -= h_3;  //(regular traingle)
	}
	else
	{
		y -= h2_3;   // reverse_triangle
	}

	disp = index - (height_of_triangle * height_of_triangle); //  
	x = (0.5) * (disp - height_of_triangle); //

	return {x,y};
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int a,b;
	while(cin >> a >> b)
	{
		pdd p1 = find_center_of_triangle(a);
		pdd p2 = find_center_of_triangle(b);
		x1 = p1.first; x2 = p2.first; y1 = p1.second; y2 = p2.second;
		result = sqrt((y1-y2)*(y1-y2) + (x1-x2)*(x1-x2));
		printf("%.3f\n",result);

		// printf("[%.3f,%.3f] - [%.3f,%.3f]\n",x1,y1,x2,y2);
	}
	


	return 0;
}

