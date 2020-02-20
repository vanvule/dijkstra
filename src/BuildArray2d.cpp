#include "BuildArray2d.h"
#include "Dijkstra.h"
#include "BinaryHeap.h"
BuildArray::BuildArray()
{
	DensityTable = new int *[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
	{
		DensityTable[i] = new int[MAX_SIZE];
		for (int j = 0; j < MAX_SIZE; j++)
		{
			DensityTable[i][j] = -1;
		}
	}
}

BuildArray::~BuildArray()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		delete[] DensityTable[i];
	}
	delete[] DensityTable;
}

void BuildArray::Display()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			std::cout << DensityTable[i][j];
		}
		std::cout << std::endl;
	}
}

int BuildArray::Create(int diem_dau, int diem_cuoi, int trong_so)
{
	if (DensityTable[diem_dau][diem_cuoi] == -1)
	{
		DensityTable[diem_dau][diem_cuoi] = trong_so;
		return 1;
	}
	return 0;
}

int BuildArray::Delete(int diem_dau, int diem_cuoi)
{
	if (DensityTable[diem_dau][diem_cuoi] != -1)
	{
		DensityTable[diem_dau][diem_cuoi] = -1;
		return 1;
	}
	return 0;
}

bool BuildArray::LookUp(int diem_dau, int diem_cuoi, int & desity, std::queue<std::string>& egdes)
{
	Data tmp = Data();
	if (Dijkstra::GetShortestWay(DensityTable, diem_dau, diem_cuoi, tmp))
	{
		desity = tmp.GetPriority();
		std::list<int> int_ = tmp.GetKeys();
		for (std::list<int>::iterator iter = int_.begin(); iter != int_.end();)
		{
			std::list<int>::iterator tmp = iter;
			if (++iter == int_.end())
				break;
			std::string val_1 = NxtLib::ConvertInttoStr(*tmp);
			std::string val_2 = NxtLib::ConvertInttoStr(*iter);
			std::string val = val_1 + " " + val_2;
			egdes.push(val);
		}
		return true;
	}
	return false;
}

static void MergedQueue(std::queue<std::string>& host_queue, std::queue<std::string> slave_queue)
{
	while (slave_queue.size())
	{
		host_queue.push(slave_queue.front());
		slave_queue.pop();
	}
}

std::queue<std::string> BuildArray::SetContraints(std::queue<DataImport> cmds)
{
	std::queue<std::string> rtrn = std::queue<std::string>();
	while (cmds.size())
	{
		DataImport tmp = cmds.front();
		if (tmp.DieuKien() == Command::Create)
			rtrn.push(NxtLib::ConvertInttoStr(Create(tmp.DiemDau(), tmp.DiemCuoi(), tmp.TrongSo())));
		else if (tmp.DieuKien() == Command::Delete)
			rtrn.push(NxtLib::ConvertInttoStr(Delete(tmp.DiemDau(), tmp.DiemCuoi())));
		else if (tmp.DieuKien() == Command::ShortestWay)
		{
			int density = 0;
			std::queue<std::string> egdes = std::queue<std::string>();
			if (LookUp(tmp.DiemDau(), tmp.DiemCuoi(), density, egdes))
			{
				rtrn.push(NxtLib::ConvertInttoStr(density));
				MergedQueue(rtrn, egdes);
			}
			else
			{
				rtrn.push("-1");
			}
		}
		cmds.pop();
	}
	return rtrn;
}


