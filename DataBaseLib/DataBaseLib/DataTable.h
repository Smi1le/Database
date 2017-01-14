#pragma once
#include <string>
#include <vector>
#include <map>
#include "Note.h"

struct SColumn
{
	size_t id;
	std::string type; // TODO: заменить на Enum
	SColumn(size_t id, std::string const & type)
		: id(id)
		, type(type)
	{}
};

using ColumnsNames = std::map<std::string, SColumn>;
using Column = std::pair<std::string, std::string>;

class CDataTable
{
public:
	CDataTable(std::string const & name, ColumnsNames const & columns = ColumnsNames());
	void RemoveNote(size_t row);
	void RemoveColumn(std::string const & columnName);
	void Update();
	void AddNote(CNote const &note);
	CNote GetNote(size_t row) const;
	std::string GetName() const;
	void SetName(std::string const &name);
	void AddColumnsNames(std::vector<Column> const &columns);

	void Show();
private:
	std::string m_name;
	std::vector<CNote> m_table;
	ColumnsNames m_columnNames;
};

