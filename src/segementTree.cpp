#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;



class SegementTree
{

private:
	vi a,seg;
	int n;
	int left(int p) {return 2*p+1;}
	int right(int p) { return 2*p+2;}

	void build(int ind,int low,int high)
	{
		if(low == high)
		{
			seg[ind] = a[low];
			return;
		}

		int mid = (low + high)/2;
		build(left(ind), low, mid);
		build(right(ind), mid+1, high);
		seg[ind] = max(seg[left(ind)],seg[right(ind)]);
	}

	int query(int ind,int low,int high,int l,int r)
	{
		if(low >= l && high <= r)
		{
			return seg[ind];
		}
		if(low > r || high < l) return INT_MIN;
		int mid = (low + high) / 2;
		int left_va = query(left(ind), low, mid, l, r);
		int right_va = query(right(ind), mid+1, high, l, r);
		return max(left_va,right_va);
	}

	void pointUpdate(int ind,int low,int high,int node, int val)
	{
		if(low == high)
		{
			seg[ind] += val;
			a[node] += val;   // In main array 
		}
		else
		{
			int mid = (low + high) / 2;
			if(node <= mid && node >= low) pointUpdate(left(ind), low, mid, node, val);
			else pointUpdate(right(ind), mid+1, high, node, val);
			seg[ind] = max(seg[left(ind)],seg[right(ind)]);
		}
	}

public:

	SegementTree(const vi arr)
	{
		n = (int)arr.size();
		a = arr;
		seg.assign(4*n,0);
		build(0,0,n-1);
	}
	int query(int i,int j) { return query(0,0,n-1,i,j);}
	void pointUpdate(int index, int val) {pointUpdate(0,0,n-1,index,val);}
};


class LazySegementTree
{

private:
	vi a,seg,lazy;
	int n;
	int left(int p) {return 2*p+1;}
	int right(int p) { return 2*p+2;}

	void build(int ind,int low,int high)
	{
		if(low == high)
		{
			seg[ind] = a[low];
			return;
		}

		int mid = (low + high)/2;
		build(left(ind), low, mid);
		build(right(ind), mid+1, high);
		seg[ind] = seg[left(ind)] + seg[right(ind)];
	}

// 	int query(int ind,int low,int high,int l,int r)
// 	{
// 		if(low >= l && high <= r)
// 		{
// 			return seg[ind];
// 		}
// 		if(low > r || high < l) return INT_MIN;
// 		int mid = (low + high) / 2;
// 		int left_va = query(left(ind), low, mid, l, r);
// 		int right_va = query(right(ind), mid+1, high, l, r);
// 		return max(left_va,right_va);
// 	}

	void rangeUpdate(int ind, int low, int high, int l, int r, int val)
	{
		if(lazy[ind] != 0)
		{
			seg[ind] += (high - low + 1) * lazy[ind];
			if(low != high)
			{
				lazy[left(ind)] += lazy[ind];
				lazy[right(ind)] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if(r < low || l > high || low > high) return;

		if(low >= l && high <= r)
		{
			seg[ind] += (high - low + 1) * val;
			if(low != high)
			{
				lazy[left(ind)] += val;
				lazy[right(ind)] += val;
			}
			return;
		}

		int mid = (low + high) / 2;
		rangeUpdate(left(ind), low, mid, l, r, val);
		rangeUpdate(right(ind), mid+1, high, l, r, val);
		seg[ind] = seg[left(ind)] + seg[right(ind)];
		
	}



	int querySumLazy(int ind, int low,int high,int l, int r)
	{
		if(lazy[ind] != 0)
		{
			seg[ind] += (high - low + 1) * lazy[ind];
			if(low != high)
			{
				lazy[left(ind)] += lazy[ind];
				lazy[right(ind)] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if(r < low || l > high || low > high) return 0;

		if(low >= l && high <= r)
		{
			return seg[ind];
		}

		int mid = (low + high) / 2;
		return querySumLazy(left(ind), low, mid, l, r) + querySumLazy(right(ind), mid+1, high, l, r);
	}


	void pointUpdate(int ind,int low,int high,int node, int val)
	{
		if(low == high)
		{
			seg[ind] += val;
			a[node] += val;   // In main array 
		}
		else
		{
			int mid = (low + high) / 2;
			if(node <= mid && node >= low) pointUpdate(left(ind), low, mid, node, val);
			else pointUpdate(right(ind), mid+1, high, node, val);
			seg[ind] = seg[left(ind)] + seg[right(ind)];
		}
	}



public:

	LazySegementTree(const vi arr)
	{
		n = (int)arr.size();
		a = arr;
		seg.assign(4*n,0);
		lazy.assign(4*n,0);
		build(0,0,n-1);
	}
	// int query(int i,int j) { return query(0,0,n-1,i,j);}
	void pointUpdate(int index, int val) {pointUpdate(0,0,n-1,index,val);}
	int querySumLazy(int l,int r) { return querySumLazy(0,0,n-1,l,r);}
	void rangeUpdate(int l,int r, int val) {rangeUpdate(0,0,n-1,l,r,val);} 


};




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vi arr = {10, 2, 47, 3, 7, 9, 1, 98, 21};
	// SegementTree sg(arr);
	// sg.pointUpdate(1,2);  // {18,17+2=19,13,19,15,11,20};
	// cout << sg.query(0,3) << endl;

	LazySegementTree sg(arr);
	// sg.pointUpdate(1,2);
	sg.rangeUpdate(3,5,1);
	cout << sg.querySumLazy(3,5) << endl;

	return 0;

}