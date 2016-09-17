// Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DataBase.h"

using namespace std;
using namespace boost;

void PrintResult(std::vector<std::string> const & result)
{
	if (result.empty())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Result id: ";
		for (auto const & it : result)
		{
			cout << it << ", ";
		}
		cout << endl;
	}
}

int main() //TODO: вставлять кавычки в слова с пробелами
{
	CDatabase db("db.csv");
	std::string username;
	//PrintResult(db.FindAuthor("\"Yaroslav Polyakov\""));
	//PrintResult(db.FindAuthor("\"Peter Winter-Smith\""));
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "Enter username: ";
		std::cin >> username;
		if (!std::cin.fail())
		{
			PrintResult(db.FindAuthor(username));
		}
	}
    return 0;
}

