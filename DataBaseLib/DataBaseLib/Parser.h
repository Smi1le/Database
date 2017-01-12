#pragma once
#include <string>
#include <vector>
#include <map>



class CParser
{
public:
	std::map<std::string, CDataTable> Parse(std::string const &fileName);
	


private:
	std::vector<std::string> GetContentsFile(std::string const &fileName);
	std::pair<std::string, CDataTable> GetNewDataTable(std::vector<std::string> const &tableInfo);

};