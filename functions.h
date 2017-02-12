/*
 * functions.h
 *
 *  Created on: Feb 2, 2017
 *      Author: liron_s
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Node.h"
unsigned partition(Node** A, unsigned n, Node* idx)
{
	unsigned b(0),t(n-1);
	while(b<t)
	{
		 while ((keyCmp(A[b],idx)||(idx==A[b]))&&(b<t))
				b++;
		while ((keyCmp(idx,A[t]))&&(b<t))
				t--;
		if (b<t){
			swapNodes(A[b],A[t]);
			b++;
			t--;
		}
	}
	unsigned i;
	for (i=0;i<n;i++){
		if (A[i]==idx)break;
	}
	if ((i<t)&&(keyCmp(A[i],A[t]))) {swapNodes(A[i],A[t-1]);return t-1;}
	if ((t<i)&&(keyCmp(A[t],A[i]))) {swapNodes(A[i],A[t+1]);return t+1;}
	else{
	swapNodes(A[i],A[t]);
	return t;
	}
}
/****************************Asaf******************************/
int bigger(int a, int b)
{
	return a > b ? a : b;
}
//this is the prime Recursive SelectionFive.
//the function gets an number i which represent the index in which we want to
//return the number of the subtable index array by ref, number right boundary
//and number left boundary he function will return the number i of it's size
const int ONE_INDEX=1;
Node* SelectionFiveRecursiveHelper(int i, Node** a, int left, int right)
{
	Node* PivotValue;
	int n = right - left + ONE_INDEX;

	//stopping condition
	if (n <= 5)
	{
		bubbleSort(a,right-left);
		return a[left + i - ONE_INDEX];
	}

	else
	{
		Node* five[5];

		int j = 0;
		int five_ind;

		//round up if not divide in five
		int b_size;
		if (n%5==0) b_size=n/5;
		else b_size=(n/5)+1;
		Node** B = new Node*[b_size];
		for (int k = left; k <= right;)
		{

			for (five_ind = 0; ((five_ind < 5) && (k <= right)); five_ind++, k++)
				five[five_ind] = a[k];

			//sorted each five item using the bubble sort algorithm
			bubbleSort(five, five_ind - ONE_INDEX);


			//the middle variable
			B[j] = five[five_ind / 2];
			j++;
		}
		//call in recursive in order to find the number n/10 in his size in B
		PivotValue = SelectionFiveRecursiveHelper(bigger(b_size / 2, 1), B, 0, b_size - ONE_INDEX);
//		//place the number into his place
		int PivotPlace = partition(a,right-left,PivotValue);
		int SizeLeftPart = PivotPlace - left;
		//this is the item i of it's size in the sub array
		if (i == (SizeLeftPart + ONE_INDEX))
			{delete[] B;return a[PivotPlace];}
		//those 2 lines were added by vered they are not part of the code
		delete[] B;
		return a[0];
//		//call in recursive from the left to PivotPlace
//		else if (i < SizeLeftPart + ONE_INDEX)
//			{delete[] B;return SelectionFiveRecursiveHelper(i, a, left, PivotPlace - ONE_INDEX);}
//
//		//(i>SizeLeftPart+1) call in recusive from the right of PivotPlace
//		else{delete[] B;
//			return SelectionFiveRecursiveHelper
//			(i - (SizeLeftPart + ONE_INDEX), a, PivotPlace + ONE_INDEX, right);}
	}
}


//this is the surround function of SelectionFiveRecursiveHelper that get an
//index i, array a (getting by value in order not to change the original array),
//number right boundary and number left boundary the function call to the prime
//recursive function in order to do the selection five algorithm
Node* SelectionFiveRecursive(int i, Node**  a, int left, int right)
{
	return SelectionFiveRecursiveHelper(i, a, left, right);
}




#endif /* FUNCTIONS_H_ */
