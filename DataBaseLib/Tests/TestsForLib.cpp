#include "stdafx.h"
#include <iostream>
#include "../DataBaseLib/DataTable.h"
#include "../DataBaseLib/Parser.h"
#include "../DataBaseLib/Note.h"

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

//*******************************************************************************************

BOOST_AUTO_TEST_SUITE(Data_Base_Lib_Note)

	BOOST_AUTO_TEST_CASE(the_addition_of_10_columns_in_the_record_does_not_throw_exceptions)
	{
		CNote newNote;
		for (size_t i = 0; i != 10; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_EQUAL(10, newNote.GetSize());
	}

	BOOST_AUTO_TEST_CASE(when_cleaning_recording_completely_deletes_the_contents)
	{
		CNote newNote;
		for (size_t i = 0; i != 10; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		newNote.RemoveNote();
		BOOST_CHECK_EQUAL(0, newNote.GetSize());
	}

	BOOST_AUTO_TEST_CASE(the_function_GetColumnValue_returns_the_correct_value)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_EQUAL("first2", newNote.GetColumnValue(2).GetValue());
	}

	BOOST_AUTO_TEST_CASE(when_you_remove_a_column_from_the_record_entry_value_is_changed_to_null)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		newNote.RemoveColumn(2);
		BOOST_CHECK_EQUAL("null", newNote.GetColumnValue(2).GetValue());
	}

	BOOST_AUTO_TEST_CASE(record_update_works_properly)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		newNote.UpdateNote(2, "update");
		BOOST_CHECK_EQUAL("update", newNote.GetColumnValue(2).GetValue());
	}

	BOOST_AUTO_TEST_CASE(re_deleting_already_deleted_record_does_not_throw_an_exception)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		newNote.RemoveColumn(2);
		BOOST_CHECK_NO_THROW(newNote.RemoveColumn(2));
	}

	BOOST_AUTO_TEST_CASE(defunct_record_deletion_causes_the_release_of_exclusion)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_THROW(newNote.RemoveColumn(5), std::exception);
	}

	BOOST_AUTO_TEST_CASE(call_a_nonexistent_record_causes_an_exception_emissions)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_THROW(newNote.GetColumnValue(5), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(call_not_update_an_existing_record_will_throw_an_exception)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_THROW(newNote.UpdateNote(5, "update"), std::exception);
	}

	BOOST_AUTO_TEST_CASE(when_trying_to_get_the_value_of_the_index_which_does_not_throw_an_exception)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_THROW(newNote.GetColumnValue(5), std::exception);
	}



BOOST_AUTO_TEST_SUITE_END()