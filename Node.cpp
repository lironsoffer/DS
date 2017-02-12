/*
 * Node.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: liron_s
 */
#include "Node.h"

bool keyCmp(Node* a,Node* b)
{
	if (a==b)
		return false;
	if ( *(a->key()) < *(b->key()) )
		return true;
	else
		return false;
}

void swapNodes(Node* a,Node* b)
{
	Node* tmp = new Node(a);
	a->copy(b);
	b->copy(tmp);
	delete tmp;
}

unsigned* bubbleSort(Node** A,unsigned len)
{
	unsigned* indexes = new unsigned[len];
	for(unsigned i=0;i<len;++i)
	{
		indexes[i]=i;
	}

	for(unsigned i=1;i<len;++i)
	{
		for(unsigned j=0;j<(len-i);++j)
			if(keyCmp(A[j+1],A[j]))
			{
				swapNodes(A[j+1],A[j]);

				unsigned tmp=indexes[j];
				indexes[j]=indexes[j+1];
				indexes[j+1]=tmp;
			}
	}

	return indexes;
}

unsigned naive_median(Node** A,unsigned len)
{
	Node** B = new Node*[len];
	for (unsigned i=0;i<len;i++)
	{
		B[i]=new Node(A[i]);
	}

	unsigned* indexes = bubbleSort(B,len);
//	Node* tmp = new Node(B[len/2]);

	for (unsigned i=0;i<len;i++)
	{
		delete B[i];
	}
	delete[] B;
	return indexes[len/2];
}

Node* Node::copy(Node* n)
	{
		if (_key!=NULL)
			delete _key;;
		_key=n->key()->clone();
		if (_val!=NULL)
			delete _val;
		_val=n->val()->clone();

		_left=n->left();
		_right=n->right();

		return this;
	}

void MinNode::updateSpecialKey()
{
	_specialKey=this;
	 if(!this->isLeaf())
	 {
		 if (keyCmp(_left->getSpecialKey(),_right->getSpecialKey()))
		 {
			 _specialKey=_left->getSpecialKey();
		 }
		 else
		 {
			 _specialKey=_right->getSpecialKey();
		 }
	 }
}

void MaxNode::updateSpecialKey()
{
	 if(this->isLeaf())
	 {
		 _specialKey=this;
	 }
	 else
	 {
		 if (keyCmp(_left->getSpecialKey(),_right->getSpecialKey()))
		 {
			 _specialKey=_right->getSpecialKey();
		 }
		 else
		 {
			 _specialKey=_left->getSpecialKey();
		 }
	 }
}

