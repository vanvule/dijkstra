#include "BinaryHeap.h"

static void SwapData(Data * s1, Data * s2)
{
	Data temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

std::list<int> Data::GetKeys()
{
	return keys;
}

int Data::GetPriority()
{
	return priority;
}

MinBinaryHeap::MinBinaryHeap(int capacity) :max_size(capacity),
heap_size(0),
mang_(new Data[capacity])
{

}

MinBinaryHeap::~MinBinaryHeap()
{
	if (mang_ != NULL)
		delete[] mang_;
}

void MinBinaryHeap::MinHeapify(int i)
{
	int left = Left(i);
	int right = Right(i);
	int smallest = i;
	if (left < heap_size && mang_[left] < mang_[i])
		smallest = left;
	if (right < heap_size && mang_[right] < mang_[smallest])
		smallest = right;
	if (smallest != i)
	{
		SwapData(&mang_[i], &mang_[smallest]);
		MinHeapify(smallest);
	}
}

int MinBinaryHeap::Parent(int i)
{
	return (i - 1) / 2;
}

int MinBinaryHeap::Left(int i)
{
	return (2 * i + 1);
}

int MinBinaryHeap::Right(int i)
{
	return 2 * i + 2;
}

Data MinBinaryHeap::PopTop()
{
	if (heap_size <= 0)
		return Data();
	if (heap_size == 1)
	{
		heap_size--;
		return mang_[0];
	}
	Data root = mang_[0];
	mang_[0] = mang_[heap_size - 1];
	heap_size--;
	MinHeapify(0);
	return root;
}

void MinBinaryHeap::DecreateKey(int i, Data new_val)
{
	mang_[i] = new_val;
	while (i != 0 && mang_[Parent(i)] > mang_[i])
	{
		SwapData(&mang_[i], &mang_[Parent(i)]);
		i = Parent(i);
	}
}

Data MinBinaryHeap::GetTop()
{
	return mang_[0];
}

void MinBinaryHeap::Delete(int k)
{
	DecreateKey(k, Data());
	PopTop();
}

void MinBinaryHeap::Insert(Data k)
{
	if (heap_size == max_size)
	{
		std::cout << "Full Bo nho roi";
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	mang_[i] = k;
	while (i != 0 && mang_[Parent(i)] > mang_[i])
	{
		SwapData(&mang_[i], &mang_[Parent(i)]);
		i = Parent(i);
	}
}

int MinBinaryHeap::HeapSize()
{
	return heap_size;
}

int MinBinaryHeap::Maxsize()
{
	return max_size;
}
