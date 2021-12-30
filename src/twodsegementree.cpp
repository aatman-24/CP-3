#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;



class SegementTreeTwoD
{
 
private:
vvi arr;
vvi seg;


int left(int p) {return 2*p+1;}
int right(int p) { return 2*p+2;}

void build_y(int vx,int lx,int rx,int vy,int ly,int ry)
{
	if(ly == ry)
	{
		if(lx == rx)
		{
			seg[vx][vy] = arr[lx][ly];
		}
		else
		{
			seg[vx][vy] = seg[left(vx)][vy] + seg[right(vx)][vy];
		}
	}
	else
	{
		int midy = (ly + ry) / 2;
		build_y(vx,lx,rx,left(vy),ly,midy);
		build_y(vx, lx, rx, right(vy), midy+1, ry);
		seg[vx][vy] = seg[vx][left(vy)] + seg[vx][right(vy)];
	}
}

void build_x(int vx,int lx,int rx)
{
	if(lx != rx)
	{
		int midx = (lx + rx) / 2;
		build_x(left(vx), lx, midx);
		build_x(right(vx), midx+1, rx);
	}
	build_y(vx,lx,rx,0,0,m-1);
}


int sum_y(int vx,int vy, int tly, int try_,int ly,int ry)
{
	if(ly > ry) return 0;  //|| tly > ry || try_ < ly 

	if((ly == tly) && try_ == ry)
	{
		return seg[vx][vy];
	}
	
	int midy = (tly + try_) / 2;
	
	return sum_y(vx, left(vy), tly, midy, ly, min(ry, midy))
         + sum_y(vx, right(vy), midy+1, try_, max(ly, midy+1), ry);
}

int sum_x(int vx,int tlx,int trx,int lx,int rx,int ly,int ry)
{
	if(lx > rx ) return 0; //|| tlx > rx || trx < lx 

	if((lx == tlx) && (rx == trx))
	{
		return sum_y(vx,0,0,n-1,ly,ry);
	}
	
	int midx =  (tlx + trx) / 2;

	return sum_x(left(vx), tlx, midx, lx, min(rx, midx), ly, ry)
         + sum_x(right(vx), midx+1, trx, max(lx, midx+1), rx, ly, ry);
}


void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            seg[vx][vy] = new_val;
        else
            seg[vx][vy] = seg[left(vx)][vy] + seg[right(vx)][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my && y >= ly)
            update_y(vx, lx, rx, left(vy), ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, right(vy), my+1, ry, x, y, new_val);
        seg[vx][vy] = seg[vx][left(vy)] + seg[vx][right(vy)];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx && x >= lx)
            update_x(left(vx), lx, mx, x, y, new_val);
        else
            update_x(right(vx), mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 0, 0, n-1, x, y, new_val);
}

public:
	int n,m;
	SegementTreeTwoD(vector<vector<int>> &a)
	{
		n = (int)a.size();
		m = (int)a[0].size();
		arr = a;
		seg.assign(4*n,vi(4*m,0));
		build_x(0,0,n-1);
	}

	int query(int lx,int ly,int rx,int ry) {return sum_x(0,0,n-1,lx,rx,ly,ry);}
	void update(int x,int y,int val) { update_x(0,0,n-1,x,y,val);}

};



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,temp;
	int m,r1,c1,r2,c2,r_1,c_1,val;
	char ch_temp;

	cin >> n;
	vector<vector<int>> ab(n,vi(n,0));

	for(int i = 0 ; i < n;i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin >> temp;
			ab[i][j] = temp;
		}
	}


	SegementTreeTwoD seg(ab);
	cin >> m;
	while(m--)
	{
		cin >> ch_temp;
		if(ch_temp == 'q')
		{
			cin >> r1 >> c1 >> r2 >> c2;
			// cout << r1 << c1 << r2 << c2 << endl;
			cout << seg.query(r1-1,c1-1,r2-1,c2-1) << endl;
			// cout << result.first << ' ' << result.second << endl;
		}
		if(ch_temp == 'c')
		{
			cin >> r_1 >> c_1 >> val;
			// cout << r_1-1 << c_1-1 << endl;
			seg.update(r_1-1,c_1-1,val);
		}
	}
	//  lx rx ly ry
	// cout << "Oksy" << endl;
	// cout << seg.query(0,0,2,2) << endl;
	// seg.update(0,0,10);
	// cout << seg.query(0,0,2,2) << endl;
	// cout << "helo" << endl;

	return 0;
}