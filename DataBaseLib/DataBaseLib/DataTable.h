#pragma once
#include <string>
#include <vector>
#include <map>
#include "Note.h"
//¬озможно эта структура излишн€€
/*struct SColumn
{
	size_t id; //«ачем у каждой колонки хранить id?
	std::string m_type; // TODO: заменить на Enum
};
*/
//using ColumnsNames = std::map<std::string, SColumn>;

class CDataTable
{
public:
	CDataTable() = default;
	void RemoveNote();
	void RemoveColumn(std::string const & columnName);
	void Update();
	void AddNote(CNote const &note);
	CNote GetNote(size_t row) const;
private:
	std::string m_name;
	std::vector<CNote> m_table;
	//с этими данными не работаю
	//ColumnsNames m_columnNames;
};

