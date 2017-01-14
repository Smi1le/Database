// DataBaseLib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DataBaseLib.h"
#include "Parser.h"


int main()
{
	//CDataTable dataTable;
	CDataBaseLib lib;
	lib.LoadTableFromFile("example.txt");
	//CParser parser;
	//parser.Parse("example.txt");
    return 0;
}

