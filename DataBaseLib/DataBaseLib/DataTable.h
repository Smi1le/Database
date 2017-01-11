#pragma once
#include <string>
#include <vector>
#include <map>
#include "Note.h"

struct SColumn
{
	size_t id;
	std::string m_type; // TODO: заменить на Enum
};

using ColumnsNames = std::map<std::string, SColumn>;

class CDataTable
{
public:
	CDataTable() = default;
	void RemoveNote();
	void RemoveColumn(std::string const & columnName);
	void Update();
	void AddNote();
	CNote GetNote(size_t row) const;
private:
	std::string m_name;
	std::vector<CNote> m_table;
	ColumnsNames m_columnNames;
};

