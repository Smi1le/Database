#include "stdafx.h"
#include <iostream>
#include "../DataBaseLib/DataTable.h"
#include "../DataBaseLib/Parser.h"

//#include "../DataBaseLib/Parser.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Data_Base_Lib_Parser)

BOOST_AUTO_TEST_CASE(pass_parser_correct_file_path)
{
	CParser parser;
	BOOST_CHECK_NO_THROW(parser.Parse("testing_files/example.txt"));
}

BOOST_AUTO_TEST_CASE(pass_parser_incorrect_file_path)
{
	CParser parser;
	BOOST_CHECK_THROW(parser.Parse("testing_files/123.txt"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(no_table_name_in_input_file)
{
	CParser parser;
	BOOST_CHECK_THROW(parser.Parse("testing_files/no_table_name.txt"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(number_of_names_mismatch_column_with_the_number_of_types)
{
	CParser parser;
	BOOST_CHECK_THROW(parser.Parse("testing_files/4_to_5.txt"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(They_were_used_the_wrong_type)
{
	CParser parser;
	BOOST_CHECK_THROW(parser.Parse("testing_files/wrong_type.txt"), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()