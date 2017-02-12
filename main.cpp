#include <iostream>
#include <string>
#include <cstddef>
#include "DataStructure.h"
#define CHECK_SIZE 23
#define MIN_KEY_INDEX 0
#define MEDIAN_KEY_INDEX 1
#define MAX_KEY_INDEX 2
#define MIN_VALUE_INDEX 0
#define MEDIAN_VALUE_INDEX 1
#define MAX_VALUE_INDEX 2
#define RESULT_POINTERS_ARRAY_SIZE 3

using namespace std;


//class MyKey :public Key
//{
//public:
//	MyKey(unsigned k) : key(k){}
//	MyKey(MyKey const &mk) :key(mk.key){}
//	~MyKey(){}
//	MyKey* clone() const
//	{
//		return new MyKey(*this);
//	}
//	unsigned get_key(){ return key; }
//	void set_key(unsigned k){ key = k; }
//	bool operator<(const Key &rhs) const{ return key <((MyKey&)rhs).key; }
//	void print() const { cout << key << "\n"; }
//private:
//	unsigned key;
//};


class MyValue : public Value
{
public:
	MyValue(string val) : value(val){}
	~MyValue(){}
	MyValue(MyValue const &v) { value = v.value; }
	MyValue* clone() const
	{
		return new MyValue(*this);
	}
	string get_value(){ return value; }
	void set_value(string val){ value = val; }
	void print() const { cout << value << "\n"; }
private:
	string value;
};


void Print_Delete_And_Set_To_NULL(DataStructure* D)
{
	MyKey* res_keys_array[RESULT_POINTERS_ARRAY_SIZE] = { NULL, NULL, NULL };
	MyValue* res_values_array[RESULT_POINTERS_ARRAY_SIZE] = { NULL, NULL, NULL };
	res_keys_array[MAX_KEY_INDEX] = dynamic_cast<MyKey*>(D->Get_Max_Key());
	res_keys_array[MIN_KEY_INDEX] = dynamic_cast<MyKey*>(D->Get_Min_Key());
	res_keys_array[MEDIAN_KEY_INDEX] = dynamic_cast<MyKey*>(D->Get_Median_Key());
	res_values_array[MAX_VALUE_INDEX] = dynamic_cast<MyValue*>(D->Get_Max_Value());
	res_values_array[MIN_VALUE_INDEX] = dynamic_cast<MyValue*>(D->Get_Min_Value());
	res_values_array[MEDIAN_VALUE_INDEX] = dynamic_cast<MyValue*>(D->Get_Median_Value());
	for (unsigned i = 0; i < RESULT_POINTERS_ARRAY_SIZE; i++)
	{
		if (res_keys_array[i] == NULL)
		{
			cout << "NULL" << "\n";
		}
		else
		{
			if (i == MAX_KEY_INDEX)
			{
				cout << "max key=";
			}
			else
			{
				if (i == MEDIAN_KEY_INDEX)
				{
					cout << "median key=";
				}
				else
				{
					cout << "min key=";
				}
			}
			res_keys_array[i]->print();
			delete res_keys_array[i];
			res_keys_array[i] = NULL;
		}
		if (res_values_array[i] == NULL)
		{
			cout << "NULL" << "\n";
		}
		else
		{
			if (i == MAX_VALUE_INDEX)
			{
				cout << "max value=";
			}
			else
			{
				if (i == MEDIAN_VALUE_INDEX)
				{
					cout << "median value=";
				}
				else
				{
					cout << "min value=";
				}
			}
			res_values_array[i]->print();
			delete res_values_array[i];
			res_values_array[i] = NULL;
		}
	}
	cout << "---------------------------------" << "\n";;
}

int main()
{
//	/*Asaf test start*/
//	int bubbleSortTest[] = { 45,21,	26,	86,	68,	58,	36,	14,2, 44,95,51,89,37,39,10,	82,	90,	12,	66,	56,70,31 };
//	BubbleSort(bubbleSortTest, 0, (sizeof(bubbleSortTest) / sizeof(int))-1);
//	//BubbleSort(bubbleSortTest, 0, 4);
//
//
//
//	int partitionTest[] = { 45,	21,	26,	86,	68,	58,	36,	14,2, 44,95,51,89,37,39,10,	82,	90,	12,	66,	56,70,31 };
//
//	Partition(partitionTest, 0, (sizeof(partitionTest) / sizeof(int)) - 1, 60);
//
//
//	int selectionFiveRecursiveTest[] = { 45,	21,	26,	86,	68,	58,	36,	14,2, 44,95,51,89,37,39,10,	82,	90,	12,	66,	56,70,31 };
//
//	int res = SelectionFiveRecursive(5, selectionFiveRecursiveTest, 0, (sizeof(selectionFiveRecursiveTest) / sizeof(int)) - 1);
//
//	/*Asaf test end*/




	unsigned keys_array[CHECK_SIZE] = {45,	21,	26,	86,	68,	58,	36,	14,2, 44,95,51,89,37,39,10,	82,	90,	12,	66,	56,70,31};
	string values_array[CHECK_SIZE] = { "45", "21", "26", "86", "68", "58", "36", "14", "2","a", "b", "z", "ab", "cv", "s", "d", "y", "yy", "ab", "yy", "s", "h", "31" };
	MyKey** my_keys_array = new MyKey*[CHECK_SIZE];
	MyValue** my_values_array = new MyValue*[CHECK_SIZE];
	unsigned i = 0;

	for (i = 0; i < CHECK_SIZE; i++)
	{
		my_keys_array[i] = new MyKey(keys_array[i]);
		my_values_array[i] = new MyValue(values_array[i]);
	}
	DataStructure* DS = new DataStructure((Key**)my_keys_array, (Value**)my_values_array, CHECK_SIZE);
//	Print_Delete_And_Set_To_NULL(DS);
//
//	for (i = 0; i < (CHECK_SIZE/2); i++)
//	{
//		DS->Extract_Median();
//	}
//	Print_Delete_And_Set_To_NULL(DS);
//
//	DS->Extract_Min();
//	DS->Extract_Min();
//	DS->Extract_Min();
//	DS->Extract_Max();
//	DS->Extract_Max();
//	DS->Extract_Max();
//	Print_Delete_And_Set_To_NULL(DS);
//
//	for (i = 0; i < CHECK_SIZE ; i++)
//	{
//		DS->Extract_Max();
//	}
//	Print_Delete_And_Set_To_NULL(DS);
//
//	DS->Insert(my_keys_array[0], my_values_array[0]);
//	Print_Delete_And_Set_To_NULL(DS);
//
//	for (i = CHECK_SIZE-1; i > 0; i--)
//	{
//		DS->Insert(my_keys_array[i], my_values_array[i]);
//	}
//	Print_Delete_And_Set_To_NULL(DS);
//
//	DS->Extract_Min();
//	DS->Extract_Min();
//	DS->Extract_Min();
//	DS->Extract_Median();
//	DS->Extract_Median();
//	DS->Extract_Max();
//	DS->Extract_Max();
//	DS->Extract_Max();
//	Print_Delete_And_Set_To_NULL(DS);
//
	delete DS;
	for (unsigned i = 0; i < CHECK_SIZE; i++)
	{
		delete my_keys_array[i];
		delete my_values_array[i];
	}
	delete[] my_keys_array;
	delete[] my_values_array;


}
