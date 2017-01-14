// DataBaseLib.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "DataBaseLib.h"

int main()
{
	try
	{	
		CDataBaseLib db;
		db.LoadTableFromFile("example.txt");
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
    return 0;
}

