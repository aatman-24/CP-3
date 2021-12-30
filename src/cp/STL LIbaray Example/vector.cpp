void sort_distinct(std::vector<int> &num_array)
{
	int n = num_array.size();
	for(int i=0; i < n - 1; i++)
	{
		int j = i + 1;
		while ((j > 0) && (num_array[j] <= num_array[j-1]))
		{
			int temp = num_array[j-1];
			num_array[j-1] = num_array[j];
			num_array[j] = temp;
			j--;
		}
	}
}


void show(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}


// 1
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 
void show(vector<int> &v)
{
	for (double i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int* show_array(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
	a[n] = 778;
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	// About Capacity of Vector:

	// size() – Returns the number of elements in the vector.
	// max_size() – Returns the maximum number of elements that the vector can hold.
	// capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
	// resize(n) – Resizes the container so that it contains ‘n’ elements.
	// empty() – Returns whether the container is empty.
	// shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
	// reserve() – Requests that the vector capacity be at least enough to contain n elements
	

	std::vector<int> num;
	num = {1,2,3,4,5,6};


	// Element access:

	// reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
	// at(g) – Returns a reference to the element at position ‘g’ in the vector
	// front() – Returns a reference to the first element in the vector
	// back() – Returns a reference to the last element in the vector
	// data() – Returns a direct pointer to the memory array used internally by the vector to store its owned element.
	// If you do the opreation on the array it will not affect the vector.


	// Notice : num.data() is give the pointer of array which we can direct use.
	// If you did this address of array just create one pointer variable for it 
	// you don't have to create a array variable or something.
	// Or also whenever you return the address of the array you just return the variable
	// name because it is already pointer.and return type must be pointer.
	// And when it come to main you also have to create a pointer variable not array
	// variable.Because array is one type of pointer.

	// Check this one.

		// int* show_array(int a[],int n)
		// {
		// 	for (int i=0;i<n;i++)
		// 	{
		// 		cout << a[i] << "   ";
		// 	}
		// 	cout << endl;
		// 	a[n] = 778;
		// 	return a;
		// }

	// int* a = num.data();
	// int* b = show_array(a,6);
	// for (int i=0 ; i < 7; i++)
	// {
	// 	cout << b[i];
	// }
	


	// Modifiers:

	// assign() – It assigns new value to the vector elements by replacing old ones
	// push_back() – It push the elements into a vector from the back
	// pop_back() – It is used to pop or remove elements from a vector from the back.
	// insert() – It inserts new elements before the element at the specified position
	// erase() – It is used to remove elements from a container from the specified position or range.
	// swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
	// clear() – It is used to remove all the elements of the vector container
	// emplace() – It extends the container by inserting new element at position
	// emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector


	show(num);
 	num.emplace(num.begin(),24);
 	show(num);

	return 0;		
}