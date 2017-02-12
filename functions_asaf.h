/*
 * functions.h
 *
 *  Created on: Feb 2, 2017
 *      Author: liron_s
 */
/*
#ifndef FUNCTIONS_ASAF_H_
#define FUNCTIONS_ASAF_H_
#include "Node.h"

class MyKey :public Key
{
public:
	MyKey(unsigned k) : key(k){}
	MyKey(MyKey const &mk) :key(mk.key){}
	~MyKey(){}
	MyKey* clone() const
	{
		return new MyKey(*this);
	}
	unsigned get_key(){ return key; }
	void set_key(unsigned k){ key = k; }
	bool operator<(const Key &rhs) const{ return key <((MyKey&)rhs).key; }
	void print() const { std::cout << key << "\n"; }
private:
	unsigned key;
};
unsigned partition(Node** A, unsigned n, Node idx)
{
	unsigned b(0),t(n-1);
	while(b<t)
	{
		 while ((keyCmp(A[b],&idx)||(&idx==A[b]))&&(b<t))
				b++;
		while ((keyCmp(&idx,A[t]))&&(b<t))
				t--;
		if (b<t){
			swapNodes(A[b],A[t]);
			b++;
			t--;
		}
	}
	unsigned i;
	for (i=0;i<n;i++)
	if ((i<t)&&(keyCmp(A[i],A[t]))) {swapNodes(A[i],A[t-1]);return t-1;}
	if ((t<i)&&(keyCmp(A[t],A[i]))) {swapNodes(A[i],A[t+1]);return t+1;}
	else{
	swapNodes(A[i],A[t]);
	return t;
	}
}
unsigned quick_select(Node** v, unsigned n, unsigned k)
{
	    if (n == 1 && k == 0) {;return 0;}

    unsigned m = (n + 4)/5;
	    Node **medians = new Node*[m];
	    for (unsigned i=0; i<m; i++) {
	        if (5*i + 4 < n) {
	            Node **w = v + 5*i;
	            for (int j0=0; j0<3; j0++) {
	                int jmin = j0;
	                for (int j=j0+1; j<5; j++) {
	                    if (keyCmp(w[j],w[jmin])) jmin = j;
	                }
	                Node* tmp=w[j0];
	                w[j0]=w[jmin];
	                w[jmin]=tmp;
	            }
	            medians[i] = w[2];
	        } else {
	            medians[i] = v[5*i];
	        }
	    }

	    unsigned pivot = quick_select(medians, m, m/2);
	    delete [] medians;

	    for (unsigned i=0; i<n; i++) {
	        if (v[i] == v[pivot]) {
	            swapNodes(v[i], v[n-1]);
	            break;
	        }
	    }

	    unsigned store = 0;
	    for (unsigned i=0; i<n-1; i++) {
	        if (keyCmp(v[i], v[pivot])) {
	            swapNodes(v[i], v[store++]);
	        }
	    }
	    swapNodes(v[store], v[n-1]);

	    if (store == k) {
	        return pivot;
	    } else if (store > k) {
	        return quick_select(v, store, k);
	    } else {
	        return quick_select(v+store+1, n-store-1, k-store-1);
	    }
}




/****************************Asaf******************************//*
int max(int a, int b)
{
	return a > b ? a : b;
}

 void swap(int& a, int& b)
{
	int c(a); a = b; b = c;
}
//the function gets array B by ref left boundary, right boundary and number p
// the function will place from the left size all the number that are smaller then p
// and place all the number than are bigger from the right size
//the function will return the pivot index
int Partition(int * B, int left, int right, int pivot)
{
	int l = left;
	int r = right;

	//loop until all the smaller item from the left to the pivot and the
	//bigger items are from the right, if there are same pivot then he need to
	//be from the right
	while (l < r)
	{
		//if the items from the left are smaller from the pivot
		while (B[l] < pivot)
			l++;

		//if the items from the right are bigger from the pivot
		while (B[r] > pivot)
			r--;

		//if needed to be change or the items are equals
		if ((l < r))
		{
			if (B[l] == B[r])
				r--;
			else
				swap(B[l], B[r]);
		}
	}
	return r;
}


//the function get array of a left boundary and right boundary 
//the function will return the Array a sorted using the bubble sort algorithm
void BubbleSort(int * a, int left, int right)
{
	for (int i = left; i < right; i++)
		for (int j = right; j > i; j--)

			//if the left variable if bigger from the right variable
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}


const int ONE_INDEX=1;


//this is the prime Recursive SelectionFive. 
//the function gets an number i which represent the index in which we want to 
//return the number of the subtable index array by ref, number right boundary 
//and number left boundary he function will return the number i of it's size 
int SelectionFiveRecursiveHelper(int i, int* a, int left, int right)
{
	int PivotValue;
	int n = right - left + ONE_INDEX;

	//stopping condition
	if (n <= 5)
	{
		BubbleSort(a, left, right);
		return a[left + i - ONE_INDEX];
	}

	else
	{
		int five[5];

		int j = 0;
		int five_ind;

		//round up if not divide in five
		int b_size = ((int)ceil((double)n / 5));
		int* B = new int[b_size];

		for (int k = left; k <= right;)
		{

			for (five_ind = 0; ((five_ind < 5) && (k <= right)); five_ind++, k++)
				five[five_ind] = a[k];

			//sorted each five item using the bubble sort algorithm
			BubbleSort(five, 0, five_ind - ONE_INDEX);


			//the middle variable
			B[j] = five[five_ind / 2];
			j++;
		}

		//call in recursive in order to find the number n/10 in his size in B
		PivotValue = SelectionFiveRecursiveHelper
		(max(b_size / 2, 1), B, 0, b_size - ONE_INDEX);

		//place the number into his place 
		int PivotPlace = Partition(a, left, right, PivotValue);

		int SizeLeftPart = PivotPlace - left;

		//this is the item i of it's size in the sub array
		if (i == (SizeLeftPart + ONE_INDEX))
			return a[PivotPlace];

		//call in recursive from the left to PivotPlace
		else if (i < SizeLeftPart + ONE_INDEX)
			return SelectionFiveRecursiveHelper(i, a, left, PivotPlace - ONE_INDEX);

		//(i>SizeLeftPart+1) call in recusive from the right of PivotPlace
		else
			return SelectionFiveRecursiveHelper
			(i - (SizeLeftPart + ONE_INDEX), a, PivotPlace + ONE_INDEX, right);
	}
}


//this is the surround function of SelectionFiveRecursiveHelper that get an 
//index i, array a (getting by value in order not to change the original array),
//number right boundary and number left boundary the function call to the prime 
//recursive function in order to do the selection five algorithm
int SelectionFiveRecursive(int i, int*  a, int left, int right)
{
	return SelectionFiveRecursiveHelper(i, a, left, right);
}





#endif /* FUNCTIONS_ASAF_H_ */
