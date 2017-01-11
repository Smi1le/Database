#pragma once
#include <map>
#include "Value.h"


class CNote
{
public:
	CNote() = default;

	void AddColumn();
	void RemoveNote();
	void RemoveColumn(size_t id);

	CValue GetColumnValue(size_t id) const;
private:
	// id column and value
	std::map<size_t, CValue> m_note;
};

