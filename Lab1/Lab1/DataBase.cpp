
#include "stdafx.h"
#include "DataBase.h"
#include <boost/algorithm/string.hpp>

using namespace std;

namespace
{
	static const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	static const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	static const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
	static const std::string DELIMITER = ",";
}

size_t IndexOf(string const & value, vector<string> const & arr)
{
	size_t index = 0;
	for (auto const &it : arr)
	{
		if (it == value)
		{
			break;
		}
		++index;
	}
	return index;
}

std::vector<std::string> SpliteWordOnDelimiter(string const & text, std::string const & delimiter)
{
	std::vector<std::string> words;
	boost::split(words, text, boost::is_any_of(delimiter), boost::token_compress_on);
	return words;
}

CDatabase::CDatabase(std::string const & pathInputFile)
{
	if (CheckCorrectFile(pathInputFile))
	{
		ProcessFile();
	}
}

std::vector<std::string> CDatabase::FindAuthor(std::string const & username)
{
	std::vector<std::string> ids;
	for (auto const & content : m_authors[username])
	{
		ids.push_back(content.front());
	}
	return ids;
}

bool CDatabase::CheckCorrectFile(std::string const & pathInputFile)
{
	m_inputFile.open(pathInputFile);
	m_inputFile.exceptions(ifstream::badbit);
	if (!m_inputFile.is_open())
	{
		cerr << "can't open " + pathInputFile << endl;
		return false;
	}
	return true;
}

void CDatabase::ProcessFile()
{
	string inputStr;
	getline(m_inputFile, inputStr);
	m_ids = SpliteWordOnDelimiter(inputStr, DELIMITER);
	auto index = IndexOf("author", m_ids);
	while (getline(m_inputFile, inputStr))
	{
		auto content = SpliteWordOnDelimiter(inputStr, DELIMITER);
		m_authors[content[index]].push_back(content);
	}
}

