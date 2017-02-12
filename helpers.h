/*
 * helpers.h
 *
 *  Created on: Feb 3, 2017
 *      Author: liron_s
 */

#ifndef HELPERS_H_
#define HELPERS_H_



#endif

/* FROM DS */


//DataStructure(Key** keys_array ,Value** values_array, unsigned length):
//	_length(length),_root(NULL),_left(NULL),_right(NULL),_A(new Node*[length]){
//			for (unsigned i=0;i<length;i++)
//			{
//				_A[i]=new Node(keys_array[i],values_array[i]);
//			}
//			unsigned median=quick_select(_A,_length,_length/2);
//
//			//Initialize the internal Node* _root to the Median
//			_root=_A[median];
//
//			for (unsigned i=_length-1;i>median;i--)
//				this->heapifyMaxArray(i);
//
//			for (unsigned i=median-1;i>=0;i--) //TODO: check correctness
//				this->heapifyMinArray(i,median);
//
//			//Initialize the internal Node* _left to max heap
//			_left=_A[0];
//
//			//Initialize the internal Node* _right to min heap
//			_left=_A[median+1];
//
//			this->createHeap(median+1,_length);
//			this->createHeap(0,median);
//		}
//	void heapifyMinArray(unsigned pi)
//	{
//		unsigned left=((pi+1)*2)-1;
//		unsigned right=((pi+1)*2);
//
//		//Max is the maximun between pi,left,right
//		unsigned max=pi;
//
//		if(left<_length) //max<left
//		{
//			if(keyCmp(_A[max],_A[left]))
//				max=left;
//		}
//
//		if(right<_length) //max<right
//		{
//			if(keyCmp(_A[max],_A[right]))
//				max=right;
//		}
//
//		if (max!=pi)
//		{
////			std::cout <<"swap "<<pi<<" with "<<max<<endl;
//			swapNodes(_A[pi],_A[max]);
//			this->heapifyMaxArray(max);
//		}
//	}

//	void heapifyMinArray(unsigned i,unsigned median){
//		unsigned left=((i+1)*2)-1;
//		unsigned right=((i+1)*2);
//		unsigned min=i;
//		if((left<median)&&(_A[left]->key()<_A[i]->key())) //left<i
//			min=left;
//		if((right<median)&&(_A[right]->key()<_A[min]->key())) //right<min
//			min=right;
//		if (min!=i)
//		{
//			swap(_A[i],_A[min]);
//			this->heapifyMinArray(min,median);
//		}
//	}
//	Node* deleteLastFromA(){
//		return _A[_length--];
//	}
//	Node* extractMaxFromA(){
//		swap(_A[0],_A[_length]);
//		Node* tmp=this->deleteLastFromA();
//		this->heapifyMaxArray(0);
//		return tmp;
//	}
//	void createHeap(unsigned i, unsigned len){
//		for(;i<(len/2);i++) //TODO: Check correctness
//		{
//			unsigned left=((i+1)*2)-1;
//			if (left<len)
//			{
//				_A[i]->left(_A[left]);
//				_A[left]->pi(_A[i]);
//			}
//			unsigned right=((i+1)*2);
//			if (right<len)
//			{
//				_A[i]->right(_A[right]);
//				_A[right]->pi(_A[i]);
//			}
//		}
//	}
