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
	CDataTable() = default;
	CDataTable(std::string const & name, ColumnsNames const & columns = ColumnsNames());
	void AddNote(CNote const &note);
	void RemoveNote(size_t row);
	CNote GetNote(size_t row) const;
	
	void AddColumnsNames(std::vector<Column> const &columns);

	void AddEmptyColumn(std::string const & columnName, std::string const & type);
	void RemoveColumn(std::string const & columnName);
	void RenameColumn(std::string const & columnName, std::string const & newColumnName);

	void SetName(std::string const & name);
	std::string GetName() const;
	void Show();

	size_t GetNotesCount() const;
	size_t GetColumnCount() const;
private:
	std::string m_name;
	std::vector<CNote> m_table;
	ColumnsNames m_columnNames;
};

