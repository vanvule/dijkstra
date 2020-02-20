#include"ConvertLib.h"

int NxtLib::ConvertStrtoInt(std::string str)
{
	int ret = atoi(str.c_str());
	return ret;
}

std::string NxtLib::ConvertInttoStr(int val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();

}
