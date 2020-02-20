#include "ReadText.h"

DataImport::DataImport(Command dk, int start_pos, int end_pos, int time)
{
	this->dieu_kien = dk;
	this->diem_dau = start_pos;
	this->diem_cuoi = end_pos;
	this->trong_so = time;
}

Command DataImport::DieuKien()
{
	return dieu_kien;
}

int DataImport::DiemDau()
{
	return diem_dau;
}

int DataImport::DiemCuoi()
{
	return diem_cuoi;
}

int DataImport::TrongSo()
{
	return trong_so;
}

Command DataImport::GetDienKien(std::string str)
{
	if (strcmp(str.c_str(), CREATE) == 0)
	{
		return Command::Create;
	}
	else if (strcmp(str.c_str(), DELETE) == 0)
	{
		return Command::Delete;
	}
	else if (strcmp(str.c_str(), SP) == 0)
	{
		return Command::ShortestWay;
	}
	return Command::UnIdentified;
}

int DataImport::GetInt(std::string str)
{
	return NxtLib::ConvertStrtoInt(str);
}


std::queue<DataImport> ReadText::ReadFile(std::string dir_file)
{
	std::queue<DataImport> data_queue = std::queue<DataImport>();
	std::ifstream my_read_file(dir_file);

	if (my_read_file.fail())
	{
		throw std::exception("Link dau vao bi sai!");
	}
	std::string output = std::string();
	{
		while (!my_read_file.eof())
		{
			getline(my_read_file, output);
			std::istringstream buf(output);
			std::istream_iterator<std::string> beg(buf), end;
			std::vector<std::string> tokens(beg, end);
			if (tokens.size() <= 4 && tokens.size() > 1)
			{
				Command txt = DataImport::GetDienKien(tokens[0]);
				int dieu_dau = DataImport::GetInt(tokens[1]);
				int dieu_cuoi = DataImport::GetInt(tokens[2]);
				int trong_so = 0;
				if (tokens.size() > 3)
					trong_so = DataImport::GetInt(tokens[3]);
				data_queue.push(DataImport(txt, dieu_dau, dieu_cuoi, trong_so));
			}
		}
	}
	return data_queue;
}

void ReadText::WriteFile(std::string dir_file, std::queue<std::string> rtrn)
{
	std::ofstream myfile(dir_file, std::ios::out);
	if (myfile.fail())
	{
		throw std::exception("link dau ra bi sai");
	}
	while (rtrn.size())
	{
		myfile << rtrn.front() << "\n";
		rtrn.pop();
	}
	myfile.close();
}
