#pragma once
#include <string>
#include <vector>
#include <map>



class CParser // ����� ���������� ������ �� ������ �����
{
public:
	CDataTable Parse(std::string const &fileName);
	


private:
	std::vector<std::string> GetContentsFile(std::string const &fileName);
	CDataTable GetNewDataTable(std::vector<std::string> const &tableInfo);

};