#ifndef _BUILDARRAY2D_H_
#define _BUILDARRAY2D_H_
#include <iostream>
#include <sstream>
#include <string>
#include "ReadText.h"
#include "ConvertLib.h"
// [diem_dau][diem_cuoi]
class BuildArray
{
private:
	int ** DensityTable;
public:
	BuildArray();
	~BuildArray();
	void Display();
	int Create(int diem_dau, int diem_cuoi, int trong_so);
	int Delete(int diem_dau, int diem_cuoi);
	bool LookUp(int diem_dau, int diem_cuoi, int & desity, std::queue<std::string> & egde);
	std::queue<std::string> SetContraints(std::queue<DataImport> cmds);

};
#endif // !_CONVERTLIB_H_