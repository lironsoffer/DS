
#include "DataStructure.h"
#include "functions.h"
void DataStructure::print(std::string str="")
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

void DataStructure::print(Node** A, unsigned len, std::string str="")
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

void DataStructure::printHeap(std::string str="")
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
}
DataStructure::DataStructure(Key** keys_array ,Value** values_array, unsigned length):
		_length(length),_root(NULL),_left(NULL),_right(NULL),_A(new Node*[length]){
				for (unsigned i=0;i<length;i++)
				{
					_A[i]=new Node(keys_array[i],values_array[i]);
				}
				//Node* Median=SelectionFiveRecursiveHelper(_length/2,_A,0,length);
				unsigned median=partition(_A,_length,_A[0]);//TODO change from A[0] to Median
				_root=_A[median];
				swapNodes(_A[median],_A[0]);
				//if (DEBUG) print(_A,_length,"A ARRAY after partition");
					//Create Min Heap
					unsigned B_len = length/2;
					Node** B = new Node*[B_len]; //TODO: realise
					for (unsigned i=0;i<B_len;i++)
						B[i]=new Node(_A[i+1]);
					//if (DEBUG)	print(B, B_len,"B ARRAY");
					for (unsigned i=B_len/2;i>0;i--)
						this->heapifyMinArray(B,i,B_len);
					this->heapifyMinArray(B,0,B_len);
					//if (DEBUG)	print(B,B_len,"B_Min_HEAPIFIED");
					_left=createHeap(B, 0, B_len,max); //equals to B[0]


					//Create Max Heap
					unsigned C_len = length/2;
					Node** C = new Node*[C_len]; //TODO: realise
					for (unsigned i=0;i<C_len;i++)
					{
						C[i]=new Node(_A[i+1+B_len]);
					}
					//print(C, C_len,"C ARRAY");
					for (unsigned i=C_len/2;i>0;i--)
							this->heapifyMaxArray(C,i,C_len);
						this->heapifyMaxArray(C,0,C_len);
					//if (DEBUG)	print(C,C_len,"C_Max_HEAPIFIED");
					_right=createHeap(C, 0, C_len,min); //equals to C[0]

					for (unsigned i=0;i<B_len;i++)
						delete B[i];
					delete[] B;
					for (unsigned i=0;i<C_len;i++)
						delete C[i];
					delete[] C;
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



