// DataBaseLib.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "DataBaseLib.h"

int main()
{
	try
	{	
		CDataBaseLib db;
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
	}
    return 0;
}

