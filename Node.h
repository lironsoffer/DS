/*
 * Node.h
 *
 *  Created on: Jan 21, 2017
 *      Author: liron_s
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream> //TODO: delete in the end
#include "Key.h"
#include "Value.h"
#include <cstddef>

class Node
{
public:
	 Node(Key* key, Value* val, Node* pi=NULL, Node* left=NULL, Node* right=NULL):
		 _key(key->clone()),_val(val->clone()),_pi(pi),_left(left),_right(right),_specialKey(this){}

	 Node():_key(NULL),_val(NULL),_pi(NULL),_left(NULL),_right(NULL),_specialKey(this){}

	 Node(Node* n):_key(n->key()->clone()),_val(n->val()->clone()),
			 _pi(n->pi()),_left(n->left()),_right(n->right()),_specialKey(this)
	 {
		 if(n!=n->_specialKey)
		 {
			 _specialKey=n->_specialKey;
		 }
	 }

	virtual ~Node()
	{
		if (_key!=NULL)
			delete _key;
		if (_val!=NULL)
			delete _val;
	}
	Node* pi() const{return _pi;}
	Node* left() const{return _left;}
	Node* right() const{return _right;}
	void pi(Node* node){if (node!=NULL)	_pi=node->_pi;}
	void left(Node* node){if (node!=NULL)	_left=node->_left;}
	void right(Node* node){if (node!=NULL)	_right=node->_right;}
	virtual Node* getSpecialKey() const {return _specialKey;}
	virtual void updateSpecialKey(){}
	bool isLeaf() const
	{
		if((_left==NULL)&&(_right==NULL))
			return true;
		else
			return false;
	}

	Node* copy(Node* n);

	Value* val() const {return _val;}
	Key* key() const {return _key;}


protected:
	Key* _key;
	Value* _val;
	Node* _pi;
	Node* _left;
	Node* _right;
	Node* _specialKey;
};

/*
 * bool keyCmp(Node* a,Node* b)
 * Returns true if a<b,
 * false otherwise
 * In case a=b returns false
 */
bool keyCmp(Node* a,Node* b);

class MaxNode : public Node //Belongs to Max heap, saves min key as special key
{
public:
	MaxNode(Node* n):Node(n){}
	MaxNode(Key* key, Value* val, Node* pi=NULL, Node* left=NULL, Node* right=NULL):
		 Node(key,val,left,right)
	{
		 updateSpecialKey();
	}
	 void updateSpecialKey();

};

class MinNode : public Node //Belongs to Min heap, saves max key as special key
{
public:
	MinNode(Node* n):Node(n){}
	MinNode(Key* key, Value* val, Node* pi=NULL, Node* left=NULL, Node* right=NULL):
		 Node(key,val,left,right)
	{
		 updateSpecialKey();
	}
	void updateSpecialKey();

};


void swapNodes(Node* a,Node* b);

unsigned* bubbleSort(Node** A,unsigned len);

unsigned naive_median(Node** A,unsigned len);



#endif /* NODE_H_ */
