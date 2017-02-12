/*
 * DataStructure.h
 *
 *  Created on: Jan 13, 2017
 *      Author: liron_s
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#include <iostream> //TODO
#include "Key.h"
#include "Value.h"
#include "Node.h"
#include <cstddef>

#include "functions.h"

#define DEBUG false

//		dynamic_cast<MyKey*>(_A[i]->key())->print();
//		std::cout <<"left = ";

using std::cout;
using std::endl;
using std::string;

typedef enum {max,min} heapType;

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
	void print() const { cout << key << "\n"; }
private:
	unsigned key;
};
class MyValue : public Value
{
public:
	MyValue(string val) : value(val){}
	~MyValue(){}
	MyValue(MyValue const &v)	{ value = v.value; }
	MyValue* clone() const	{ return new MyValue(*this); }
	string get_value()	{ return value; }
	void set_value(string val){ value = val; }
	void print() const { cout << value << "\n"; }
private:
	string value;
};


class DataStructure
{
public:
	DataStructure(Key** keys_array ,Value** values_array, unsigned length);
//	~DataStructure(){}//TODO

	void Insert(const Key* nkey, const Value* nval);
	void Extract_Max();
	void Extract_Min();
	void Extract_Median();
	Key* Get_Min_Key() const{return _left->key()->clone();};
	Key* Get_Max_Key() const{return _right->key()->clone();};
	Key* Get_Median_Key()const{return _root->key()->clone();};
	Value* Get_Min_Value() const{return _right->val()->clone();};
	Value* Get_Max_Value() const{return _root->val()->clone();};
	Value* Get_Median_Value()const{return _root->val()->clone();};

	Node* get_i(unsigned i) const {return (_A[i]);}
private:
	unsigned _length;
	Node* _root;
	Node* _left;
	Node* _right;
	Node** _A;
	void print(string str);
	void print(Node** A, unsigned len, string str);
	void printHeap(string str);

	void heapifyMaxArray(Node** A, unsigned pi,unsigned len);
	void heapifyMinArray(Node** A, unsigned pi, unsigned len);
	Node* createHeap(Node** A, unsigned pi, unsigned len,heapType type);

};



#endif /* DATASTRUCTURE_H_ */
