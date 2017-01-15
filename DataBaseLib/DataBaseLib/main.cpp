// DataBaseLib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DataBaseLib.h"
#include "Application.h"

int main()
{
	try
	{	
		CApplication app;
		app.Run();
	}
	catch (const std::exception& error)
	{
		std::cerr << "-------- ERROR!!! -------\n" << 
			error.what() << std::endl
			<< "-------------------------" << std::endl;
	}
    return 0;
}

