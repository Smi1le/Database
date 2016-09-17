#pragma once
//#define _SCL_SECURE_NO_WARNINGS
#include "stdafx.h"



class CDatabase
{
public:
	CDatabase(std::string const & pathInputFile);
	std::vector<std::string> FindAuthor(std::string const & username);
private:
	bool CheckCorrectFile(std::string const & pathInputFile);
	void ProcessFile();

private:
	std::ifstream m_inputFile;
	std::vector<std::string> m_ids;
	std::unordered_map<std::string, std::vector<std::vector<std::string>>> m_authors;
};

