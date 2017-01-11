#include "stdafx.h"
#include "Note.h"

void CNote::AddColumn()
{
	// TODO: create method
}

void CNote::RemoveNote()
{
	m_note.clear();
}

void CNote::RemoveColumn(size_t id)
{
	m_note.erase(id);
}

CValue CNote::GetColumnValue(size_t id) const
{
	return m_note.at(id);
}
