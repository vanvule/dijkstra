#include "ReadText.h"
#include "BuildArray2d.h"
#include "BinaryHeap.h"
#include "Dijkstra.h"

using namespace std;

void InterfaceUser()
{
	BuildArray * mang_2d = NULL;
	try
	{
	std:string in_dir = std::string();
		std::string out_dir = std::string();;
		std::cout << "==> Nhap duong dan du lieu dau vao:";
		getline(std::cin, in_dir);
		std::cout << "==> Nhap duong dan du lieu dau ra:";
		getline(std::cin, out_dir);
		std::queue<DataImport> tmp = ReadText::ReadFile(in_dir);
		mang_2d = new BuildArray();
		std::queue<std::string> rlt_ = mang_2d->SetContraints(tmp);
		ReadText::WriteFile(out_dir, rlt_);
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what();
	}
	if (mang_2d != NULL)
	{
		delete mang_2d;
	}
}


int main()
{
	InterfaceUser();
	std::cout << "\n\t\tDA XONG (Finish)." << endl;
	std::cin.ignore();
	std::cin.get();
	return 0;
}