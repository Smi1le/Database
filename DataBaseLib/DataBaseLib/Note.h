#pragma once
#include <map>
#include "Value.h"


class CNote
{
public:
	CNote(std::vector<std::string> const &columnsName);

	void AddColumn();
	void RemoveNote();
	void RemoveColumn(std::string const & columnName);
	void UpdateNote(std::string const & columnName, std::string const &value);
	void Show();
	CValue GetColumnValue(std::string const & columnName) const;
private:
	// id column and value
	std::map<std::string, CValue> m_note;
};

