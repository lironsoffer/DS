/*
 * DataStructure.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: liron_s
 */

#include "DataStructure.h"

DataStructure::DataStructure(Key** keys_array ,Value** values_array, unsigned length):
	_length(length),_root(NULL),_left(NULL),_right(NULL),_A(new Node*[length])
{
	for (unsigned i=0;i<length;i++)
	{
		_A[i]=new Node(keys_array[i],values_array[i]);
	}

	//TODO: change to real
	if (length>2)
	{
		_root=_A[length/2];
		_left=_A[0];
		_right=_A[length-1];
	}
	else if (length>1)
		{
			_root=_A[length/2];
			_left=_A[0];
		}
	else if (length>0)
	{
		_root=_A[0];
	}

//	print("ORIGINAL");

	//	bubbleSort(_A,_length);
	//	print("SORTED");

	unsigned median =  naive_median(_A,_length);
	partition(_A, length,median);
	cout << "MDEIAN="<<median<<"\n";
	print("PARTITIONED");

	_root=_A[0];

//	std::cout <<"A[0] = ";
//	dynamic_cast<MyKey*>(_A[0]->key())->print();
//	std::cout <<"root = ";
//	dynamic_cast<MyKey*>(_root->key())->print();


	//Create Max Heap
	unsigned B_len = length/2;
	Node** B = new Node*[B_len]; //TODO: realise
	for (unsigned i=0;i<B_len;i++)
		B[i]=new Node(_A[i+1]);
//	if (DEBUG)	print(B, B_len,"B ARRAY");
	for (unsigned i=B_len/2;i>0;i--)
		this->heapifyMaxArray(B,i,B_len);
	this->heapifyMaxArray(B,0,B_len);
	if (DEBUG)	print(B,B_len,"B_MAX_HEAPIFIED");
	_left=createHeap(B, 0, B_len ,max); //equals to B[0]


	//Create Max Heap
	unsigned C_len = length/2;
	Node** C = new Node*[C_len]; //TODO: realise
	for (unsigned i=0;i<C_len;i++)
	{
		C[i]=new Node(_A[i+1+B_len]);
	}
//	print(C, C_len,"C ARRAY");
	for (unsigned i=C_len/2;i>0;i--)
			this->heapifyMinArray(C,i,C_len);
		this->heapifyMinArray(C,0,C_len);
	if (DEBUG)	print(C,C_len,"C_MIN_HEAPIFIED");
	_right=createHeap(C, 0, C_len, min); //equals to C[0]

	for (unsigned i=0;i<B_len;i++)
		delete B[i];
	delete[] B;
	for (unsigned i=0;i<C_len;i++)
		delete C[i];
	delete[] C;

}


void DataStructure::print(string str="")
{
	if (!DEBUG)
		return;
	std::cout << str << "\n";
	for (unsigned i = 0; i < _length; i++)
	{
		std::cout<< i <<" = ";
		dynamic_cast<MyKey*>(_A[i]->key())->print();
	}

	std::cout << "---------------------------------" << "\n";
}

void DataStructure::print(Node** A, unsigned len, string str="")
	{
		if (!DEBUG)
			return;
		std::cout << str << "\n";
		for (unsigned i = 0; i < len; i++)
		{
			std::cout<< i <<" = ";
			dynamic_cast<MyKey*>(A[i]->key())->print();
		}

		std::cout << "---------------------------------" << "\n";
	}

void DataStructure::printHeap(string str="")
{
	if (!DEBUG)
		return;
	std::cout << str << "\n";
	for (unsigned i = 1; i < _length/2; i++)
	{
		std::cout<< i <<" = ";
		dynamic_cast<MyKey*>(_A[i]->key())->print();
		dynamic_cast<MyKey*>(_A[i*2]->key())->print();
		dynamic_cast<MyKey*>(_A[i*2+1]->key())->print();

	}

	std::cout << "---------------------------------" << "\n";
}

void DataStructure::heapifyMaxArray(Node** A, unsigned pi,unsigned len)
{
	unsigned left=((pi+1)*2)-1;
	unsigned right=((pi+1)*2);

	//Max is the maximun between pi,left,right
	unsigned max=pi;

	if(left<len) //max<left
	{
		if(keyCmp(A[max],A[left]))
			max=left;
	}

	if(right<len) //max<right
	{
		if(keyCmp(A[max],A[right]))
			max=right;
	}

	if (max!=pi)
	{
//			std::cout <<"swap "<<pi<<" with "<<max<<endl;
		swapNodes(A[pi],A[max]);
		this->heapifyMaxArray(A, max,len);
	}
}

void DataStructure::heapifyMinArray(Node** A, unsigned pi, unsigned len)
	{
		unsigned left=((pi+1)*2)-1;
		unsigned right=((pi+1)*2);

		//Max is the minimun between pi,left,right
		unsigned min=pi;

		if(left<len) //left<min
		{
			if(keyCmp(A[left],A[min]))
				min=left;
		}

		if(right<len) //right<min
		{
			if(keyCmp(A[right],A[min]))
				min=right;
		}

		if (min!=pi)
		{
//			std::cout <<"swap "<<pi<<" with "<<max<<endl;
			swapNodes(A[pi],A[min]);
			this->heapifyMinArray(A,min,len);
		}
	}

Node* DataStructure::createHeap(Node** A, unsigned pi, unsigned len, heapType type)
{
	Node* a;
	Node* b;
	Node* c;
	if (type==max)
		a=new MaxNode(A[pi]);
	else
		a=new MinNode(A[pi]);

	unsigned left=((pi+1)*2)-1;

	if (left<len)
	{
		if (type==max)
			b=new MaxNode(A[left]);
		else
			b=new MinNode(A[left]);
		a->left(b);
		b->pi(a);
	}
	unsigned right=((pi+1)*2);
	if (right<len)
	{
		if (type==max)
			c=new MaxNode(A[right]);
		else
			c=new MinNode(A[right]);
		a->left(c);
		c->pi(a);
	}

	pi++;
	a->updateSpecialKey();
	if (pi<len)	createHeap(A,pi	,len,type);
	return a;
}

void DataStructure::Extract_Min()
{

}

void DataStructure::Extract_Median()
{
	if((_length-1)%2==0) //Both right and left heaps have same number of elements
		// Than new median is from left heap
	{

		Node* special=_left->getSpecialKey();
		Node* newRoot=new Node(special->key(),special->val(),NULL,
				_root->left(),_root->right());
		_root=newRoot;
	}
	else // Than new median is from right heap
	{

	}
}

