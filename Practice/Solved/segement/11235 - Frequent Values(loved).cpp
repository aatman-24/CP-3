#include <bits/stdc++.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#define ll long long

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<ii,mii> pmii;
typedef vector<pmii> vpmii;
typedef vector<map<int,int>> vmii;



class SegementTree
{

private:
	
	int n;
	int left(int p) {return 2*p+1;}
	int right(int p) { return 2*p+2;}

	int build(int ind,int low,int high)
	{
		if(low == high)
		{
			seg[ind] = a[low];
			return seg[ind];
		}

		int mid = (low + high)/2;
		build(left(ind), low, mid);
		build(right(ind), mid+1, high);
		seg[ind] = max(seg[left(ind)],seg[right(ind)]);
		return seg[ind];

	}


	int query(int ind,int low,int high,int l,int r)
	{

		if(low >= l && high <= r)
		{
			return seg[ind];
		}

		if(low > r || high < l) 
			{
				return 0;
			}

		int mid = (low + high) / 2;
		return max(query(left(ind), low, mid, l, r),query(right(ind), mid+1, high, l, r));
	}


	void make_all_map(vi &arr)
	{
		int i = 0;
		int j = i;
		while(j <= n)
		{
			if (j == n)
			{
				int oc = j - i;
				cnt[arr[i]] = oc;
				start[arr[i]] = i;
				last[arr[i]] = j - 1;
				break;
			}

			if(arr[i] == arr[j]) j++;
			else 
			{
				int oc = j - i;
				cnt[arr[i]] = oc;
				start[arr[i]] = i;
				last[arr[i]] = j - 1;
				i = j;
			}
		}
	}


	vi make_freq(mii &map,vi &arr)
	{
		int n = (int)arr.size();
		vi freq(n,0);
		for(int i = 0 ; i < n ;i++)
			freq[i] = cnt[arr[i]];
		return freq;
	}

public:

	mii start,cnt,last;
	vi freq,arr,a,seg;

	SegementTree(vi arr)
	{
		this->arr = arr;
		n = (int)arr.size();
		make_all_map(arr);
		freq = make_freq(cnt,arr);
		a = freq;
		seg.assign(4*n,0);
		build(0,0,n-1);
	}

	int query(int qs,int qe)
	{
		if(arr[qs] == arr[qe])
		{
			return qe - qs + 1;
		}
		else
		{

		int l_index,f_index;

		if(last[arr[qs]] - cnt[arr[qs]] == qs) f_index = qs;
		else f_index = last[arr[qs]] + 1;

		if(start[arr[qe]] + cnt[arr[qe]] == qe + 1) l_index = qe;
		else l_index = start[arr[qe]] - 1;


		return max({start[arr[qs]] + cnt[arr[qs]] - qs, (qe-start[arr[qe]] + 1), query(0,0,n-1,f_index,l_index)});
		}
	}
};



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	


	vi arr;
	int n,m,temp,num1,num2;
	while(cin >> n && n != 0)
	{
		cin >> m;
		arr.clear();
		for(int i = 0 ; i < n ;i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		SegementTree seg(arr);
		while(m--)
		{
			cin >> num1 >> num2;
			cout << seg.query(num1-1,num2-1) << endl;
		}
	}

	return 0;
}


// // C++ Program to find the occurrence 
// // of the most frequent number within 
// // a given range 

// // A utility function to get the middle index 
// // from corner indexes. 
// int getMid(int s, int e) { return s + (e - s) / 2; } 

// /* A recursive function to get the maximum value in 
// 	a given range of array indexes. The following 
// 	are parameters for this function. 

// 	st --> Pointer to segment tree 
// 	index --> Index of current node in the segment 
// 			tree. Initially 0 is passed as root is 
// 			always at index 0 
// 	ss & se --> Starting and ending indexes of the 
// 				segment represented by current node, 
// 				i.e., st[index] 
// 	qs & qe --> Starting and ending indexes of query 
// 				range */
// int RMQUtil(int* st, int ss, int se, int qs, int qe, 
// 										int index) 
// { 
// 	// If segment of this node is a part of given range, 
// 	// then return the min of the segment 
// 	if (qs <= ss && qe >= se) 
// 		return st[index]; 

// 	// If segment of this node is outside the 
// 	// given range 
// 	if (se < qs || ss > qe) 
// 		return 0; 

// 	// If a part of this segment overlaps 
// 	// with the given range 
// 	int mid = getMid(ss, se); 
// 	return max(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1), 
// 			RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2)); 
// } 

// // Return minimum of elements in range from 
// // index qs (query start) to 
// // qe (query end). It mainly uses RMQUtil() 
// int RMQ(int* st, int n, int qs, int qe) 
// { 
// 	// Check for erroneous input values 
// 	if (qs < 0 || qe > n - 1 || qs > qe) { 
// 		// printf("Invalid Input"); 
// 		return -1; 
// 	} 

// 	return RMQUtil(st, 0, n - 1, qs, qe, 0); 
// } 

// // A recursive function that constructs Segment Tree 
// // for array[ss..se]. si is index of current node in 
// // segment tree st 
// int constructSTUtil(int arr[], int ss, int se, int* st, 
// 											int si) 
// { 
// 	// If there is one element in array, store it in 
// 	// current node of segment tree and return 
// 	if (ss == se) { 
// 		st[si] = arr[ss]; 
// 		return arr[ss]; 
// 	} 

// 	// If there are more than one elements, then 
// 	// recur for left and right subtrees and store 
// 	// the minimum of two values in this node 
// 	int mid = getMid(ss, se); 
// 	st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1), 
// 				constructSTUtil(arr, mid + 1, se, st, si * 2 + 2)); 
// 	return st[si]; 
// } 

// /* Function to construct segment tree from given 
// array. This function allocates memory for segment 
// tree and calls constructSTUtil() to fill the 
// allocated memory */
// int* constructST(int arr[], int n) 
// { 
// 	// Allocate memory for segment tree 

// 	// Height of segment tree 
// 	int x = (int)(ceil(log2(n))); 

// 	// Maximum size of segment tree 
// 	int max_size = 2 * (int)pow(2, x) - 1; 
// 	cout << max_size << "\\\\\\\\\\\\" << endl;

// 	int* st = new int[max_size]; 

// 	// Fill the allocated memory st 
// 	constructSTUtil(arr, 0, n - 1, st, 0); 

// 	// Return the constructed segment tree 
// 	return st; 
// } 

// int maximumOccurrence(int arr[], int n, int qs, int qe) 
// { 
// 	// Declaring a frequency array 
// 	int freq_arr[n + 1]; 

// 	// Counting frequencies of all array elements. 
// 	unordered_map<int, int> cnt; 
// 	for (int i = 0; i < n; i++) 
// 		cnt[arr[i]]++; 



// 	// Creating frequency array by replacing the 
// 	// number in array to the number of times it 
// 	// has appeared in the array 
// 	for (int i = 0; i < n; i++) 
// 		freq_arr[i] = cnt[arr[i]]; 



// 	// Build segment tree from this frequency array 
// 	int* st = constructST(freq_arr, n); 

// 	for(int i = 0 ; i < 31 ;i++)
// 	{
// 		cout << st[i] << ' ';
// 	}
// 	cout << endl;

// 	int maxOcc; // to store the answer 

// 	// Case 1: numbers are same at the starting 
// 	// and ending index of the query 
// 	if (arr[qs] == arr[qe]) 
// 		maxOcc = (qe - qs + 1); 

// 	// Case 2: numbers are different 
// 	else { 
// 		int leftmost_same = 0, righmost_same = 0; 

// 		// Partial Overlap Case of a number with some 
// 		// occurrences lying inside the leftmost 
// 		// part of the range and some just before the 
// 		// range starts 

// 		while (qs > 0 && qs <= qe && arr[qs] == arr[qs - 1]) { 
// 			qs++; 
// 			leftmost_same++; 
// 		} 

// 		// Partial Overlap Case of a number with some 
// 		// occurrences lying inside the rightmost part of 
// 		// the range and some just after the range ends 
// 		while (qe >= qs && qe < n - 1 && arr[qe] == arr[qe + 1]) { 
// 			qe--; 
// 			righmost_same++; 
// 		} 

// 		// Taking maximum of all three 
// 		maxOcc = max({leftmost_same, righmost_same, 
// 								RMQ(st, n, qs, qe)}); 
// 	} 
// 	return maxOcc; 
// } 


// Driver Code 
// int main() 
// { 
// 	int arr[] = { -5, -5, 2, 2, 2, 2, 3, 7, 7, 7 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 

// 	int qs = 0; // Starting index of query range 
// 	int qe = 9; // Ending index of query range 

// 	// Print occurrence of most frequent number 
// 	// within given range 
// 	cout << "Maximum Occurrence in range is = "
// 		<< maximumOccurrence(arr, n, qs, qe) << endl; 

// 	qs = 4; // Starting index of query range 
// 	qe = 9; // Ending index of query range 

// 	// Print occurrence of most frequent number 
// 	// within given range 
// 	cout << "Maximum Occurrence in range is = "
// 		<< maximumOccurrence(arr, n, qs, qe) << endl; 

// 	return 0; 
// } 

