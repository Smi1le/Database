// DataBaseLib.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "DataTable.h"
#include "Parser.h"


int main()
{
	CDataTable dataTable;
	CParser parser;
	parser.Parse("example.txt");
    return 0;
}

