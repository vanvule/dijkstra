#include "Dijkstra.h"


//bool operator<(const Pack& a, const Pack &b) {
//	return a.s > b.s;
//}

template<typename X>
static void PushListInList(std::list<X> * host_list, const std::list<X> * slave_list)
{
	for (std::list<X>::iterator iter = slave_list->begin(); iter != slave_list->end(); iter++)
	{
		host_list->push_back(*iter);
	}
}

bool Dijkstra::GetShortestWay(int ** graph, int diem_dau, int diem_cuoi, Data & the_shortest_way)
{
	std::list<int> Visited = std::list<int>();
	MinBinaryHeap * heap = new MinBinaryHeap(MAX_SIZE);
	int i = 0;
	{
		int step_dau = diem_dau;
		Visited.push_back(step_dau);
		Data tmp_ = Data();
		while (heap->Maxsize()>0)
		{
			if (step_dau == diem_cuoi)
			{
				the_shortest_way = tmp_;
				return true;
			}
			for (int step_cuoi = 0; step_cuoi < MAX_SIZE; step_cuoi++)
			{
				if (graph[step_dau][step_cuoi] != -1)
				{
					std::list<int> keys = tmp_.GetKeys();
					int priority = tmp_.GetPriority();
					if (keys.empty())
					{
						keys.push_back(step_dau);
						keys.push_back(step_cuoi);
						priority = graph[step_dau][step_cuoi];
					}
					else
					{
						keys.push_back(step_cuoi);
						priority = graph[step_dau][step_cuoi] + priority;
					}
					heap->Insert(Data(keys, priority));
				}
			}
			while (true)
			{
				if (heap->HeapSize() == 0)
				{
					return false;
				}
				tmp_ = heap->PopTop();
				bool is_check = true;
				for (std::list<int>::iterator iter = Visited.begin(); iter != Visited.end(); ++iter)
				{
					if (tmp_.GetKeys().back() == *iter)
					{
						is_check = false;
						break;
					}
				}
				if (is_check)
				{
					step_dau = tmp_.GetKeys().back();
					Visited.push_back(tmp_.GetKeys().back());
					break;
				}
			}
			i++;
		}
	}

	delete heap;
	return true;
}

