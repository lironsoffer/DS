/*
 * DataStructure.h
 *
 *  Created on: Jan 13, 2017
 *      Author: liron_s
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#include "Key.h"
#include "Value.h"
#include "Node.h"
#include <cstddef>
typedef enum {max,min} heapType;
#define DEBUG true
// MyKey is temporary here for debugging. spouse to be in the main (now as a comment)
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
class DataStructure
{
public:
	DataStructure(Key** keys_array ,Value** values_array, unsigned length);
	~DataStructure(){
				for (unsigned i=0;i<_length;i++)
					{
						delete _A[i];
					}
		delete [] _A;
	}
	void Insert(const Key* nkey, const Value* nval);
	void Extract_Max();
	void Extract_Min();
	void Extract_Median();
	Key* Get_Min_Key() const{Key* tmp=_left->key()->clone();return tmp;};
	Key* Get_Max_Key() const{Key* tmp=_right->key()->clone();return tmp;};
	Key* Get_Median_Key()const{Key* tmp=_root->key()->clone();return tmp;};
	Value* Get_Min_Value() const{Value* tmp=_left->val()->clone();return tmp;};
	Value* Get_Max_Value() const{Value* tmp=_right->val()->clone();return tmp;};
	Value* Get_Median_Value()const{Value* tmp=_left->val()->clone();return tmp;};
private:
	unsigned _length;
	Node* _root;
	Node* _left;
	Node* _right;
	Node** _A;
	void print(std::string str);
	void print(Node** A, unsigned len, std::string str);
	void printHeap(std::string str);
	Node* createHeap(Node** A, unsigned pi, unsigned len,heapType type);
	void heapifyMaxArray(Node** A, unsigned pi,unsigned len);
	void heapifyMinArray(Node** A, unsigned pi, unsigned len);
};
#endif /* DATASTRUCTURE_H_ */
