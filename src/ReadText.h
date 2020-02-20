#ifndef _READTEXT_H_
#define _READTEXT_H_

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <iterator>
#include <sstream>
#include "constant.h"
#include "ConvertLib.h"
enum Command{ Create, Delete, ShortestWay, UnIdentified };
class DataImport
{
private:
	Command dieu_kien;
	int diem_dau = 0;;
	int diem_cuoi = 0;
	int trong_so = 0;
public:
	DataImport(Command dk, int start_pos, int end_pos, int time);
	Command DieuKien();
	int DiemDau();
	int DiemCuoi();
	int TrongSo();
public:
	static Command GetDienKien(std::string str);
	static int GetInt(std::string str);
};

class ReadText
{
public:
	ReadText()
	{
	}
	static std::queue<DataImport> ReadFile(std::string dir_file);
	static void WriteFile(std::string dir_file, std::queue<std::string> rtrn);
};

#endif // !_READTEXT_H_
