#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_
#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Data
{
private:
	std::list<int> keys = std::list<int>();
	int priority;
	bool IsEmpty;
public:
	Data() :keys(NULL), priority(0), IsEmpty(false)
	{
	};
	Data(std::list<int> k, int pr) :keys(k), priority(pr), IsEmpty(true)
	{
	}
	std::list<int> GetKeys();
	int GetPriority();
public:
	bool operator> (const Data & other_1)
	{
		return this->priority > other_1.priority;
	}
	bool operator< (const Data & other_1)
	{
		return this->priority < other_1.priority;
	}
	bool operator== (const Data & other_1)
	{
		return this->priority == other_1.priority;
	}
};

class MinBinaryHeap
{
private:
	Data * mang_;
	int max_size;
	int heap_size;
public:
	MinBinaryHeap(int capacity);
	~MinBinaryHeap();
	Data PopTop();
	Data GetTop();
	void Insert(Data k);
	int HeapSize();
	int Maxsize();
private:
	void MinHeapify(int i);
	int Parent(int i);
	int Left(int i);
	int Right(int i);
	void DecreateKey(int i, Data new_val);
	void Delete(int k);

};

#endif
