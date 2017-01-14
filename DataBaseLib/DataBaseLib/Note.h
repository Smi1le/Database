#pragma once
#include <map>
#include "Value.h"


class CNote
{
public:
	CNote() = default;

	void AddColumn(size_t idColumn, CValue const & value);
	void RemoveNote();
	void RemoveColumn(size_t columnId);

	void UpdateNote(size_t column, std::string const &value);
	void Show();
	CValue GetColumnValue(size_t column) const;
private:
	// id column and value
	std::map<size_t, CValue> m_note;
};

