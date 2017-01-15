#include "stdafx.h"
#include <iostream>
#include "../DataBaseLib/DataTable.h"
#include "../DataBaseLib/Parser.h"
#include "../DataBaseLib/Note.h"
#include "../DataBaseLib/Value.h"

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
		BOOST_CHECK_THROW(newNote.GetColumnValue(2), std::out_of_range);
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
		BOOST_CHECK_THROW(newNote.RemoveColumn(6), std::runtime_error);
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

//*******************************************************************************************

BOOST_AUTO_TEST_SUITE(Data_Base_Lib_Value)

	BOOST_AUTO_TEST_CASE(It_can_be_initialized_without_parameters)
	{
		BOOST_CHECK_NO_THROW(CValue value());
	}

	BOOST_AUTO_TEST_CASE(initialization_parameters_with_the_exception_not_released)
	{
		BOOST_CHECK_NO_THROW(CValue value("string"));
	}

	BOOST_AUTO_TEST_CASE(initialization_parameters_with_the_correct_value_is_saved)
	{
		CValue value("string");
		BOOST_CHECK_EQUAL("string", value.GetValue());
	}


	BOOST_AUTO_TEST_CASE(Replacement_values_are_stored_correctly)
	{
		CValue value("string");
		BOOST_CHECK_NO_THROW(value.ReplaceValue("newValue"));
		BOOST_CHECK_EQUAL("newValue", value.GetValue());
	}

BOOST_AUTO_TEST_SUITE_END()

//*******************************************************************************************

struct data_table_can_be_declared_by_default_
{
	CDataTable dataTable;
};

BOOST_FIXTURE_TEST_SUITE(Data_Base_Lib_Data_Table, data_table_can_be_declared_by_default_)

	BOOST_AUTO_TEST_CASE(you_can_not_get_the_note_of_an_empty_table)
	{
		BOOST_CHECK_THROW(dataTable.GetNote(0), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(name_of_the_table_to_initialize_will_be_the_empty_string)
	{
		BOOST_CHECK_EQUAL(dataTable.GetName(), "");
	}

	BOOST_AUTO_TEST_CASE(uninitialized_number_of_columns_in_the_table_will_be_zero)
	{
		BOOST_CHECK_EQUAL(dataTable.GetColumnCount(), 0);
	}

	BOOST_AUTO_TEST_CASE(uninitialized_number_of_entries_in_the_table_will_be_zero)
	{
		BOOST_CHECK_EQUAL(dataTable.GetNotesCount(), 0);
	}

	BOOST_AUTO_TEST_CASE(you_can_pass_the_table_name)
	{
		BOOST_CHECK_NO_THROW(dataTable.SetName("new table"));
	}

	BOOST_AUTO_TEST_CASE(you_can_pass_the_note)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_NO_THROW(dataTable.AddNote(newNote));
	}

	BOOST_AUTO_TEST_CASE(You_can_not_delete_an_entry_from_an_empty_table)
	{
		BOOST_CHECK_THROW(dataTable.RemoveNote(0), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(You_can_not_delete_column_from_an_empty_table)
	{
		BOOST_CHECK_THROW(dataTable.RemoveColumn("0"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(You_can_not_rename_column_from_an_empty_table)
	{
		BOOST_CHECK_THROW(dataTable.RenameColumn("first", "second"), std::runtime_error);
	}

	BOOST_AUTO_TEST_CASE(You_can_add_the_names_of_the_columns)
	{
		std::vector<std::pair<std::string, std::string>> names;
		for (size_t i = 0; i != 5; ++i)
		{
			names.push_back(std::pair<string, string>("name" + to_string(i), "type" + to_string(i)));
		}
		BOOST_CHECK_NO_THROW(dataTable.AddColumnsNames(names));
	}

	BOOST_AUTO_TEST_CASE(You_can_add_a_blank_column)
	{
		std::vector<std::pair<std::string, std::string>> names;
		BOOST_CHECK_NO_THROW(dataTable.AddEmptyColumn("column", "first"));
	}

BOOST_AUTO_TEST_SUITE_END()

struct initialized_data_table_table_
{
	CParser parser;
	CDataTable dataTable = parser.Parse("testing_files/example.txt");
};

BOOST_FIXTURE_TEST_SUITE(Data_Base_Lib_Data_Table_Initialize, initialized_data_table_table_)

	BOOST_AUTO_TEST_CASE(You_can_add_the_names_of_the_columns_when_table_initialize)
	{
		std::vector<std::pair<std::string, std::string>> names;
		for (size_t i = 0; i != 5; ++i)
		{
			names.push_back(std::pair<string, string>("name" + to_string(i), "type" + to_string(i)));
		}
		BOOST_CHECK_NO_THROW(dataTable.AddColumnsNames(names));
	}

	BOOST_AUTO_TEST_CASE(You_can_add_a_blank_column_when_table_initialize)
	{
		std::vector<std::pair<std::string, std::string>> names;
		BOOST_CHECK_NO_THROW(dataTable.AddEmptyColumn("column", "first"));
	}

	BOOST_AUTO_TEST_CASE(You_can_rename_colum)
	{
		BOOST_CHECK_NO_THROW(dataTable.RenameColumn("id_note", "second"));
	}

	BOOST_AUTO_TEST_CASE(You_can_delete_column)
	{
		BOOST_CHECK_NO_THROW(dataTable.RemoveColumn(0));
	}

	BOOST_AUTO_TEST_CASE(you_can_pass_the_note_when_table_initialize)
	{
		CNote newNote;
		for (size_t i = 0; i != 5; ++i)
		{
			BOOST_CHECK_NO_THROW(newNote.AddColumn(i, CValue("first" + std::to_string(i))));
		}
		BOOST_CHECK_NO_THROW(dataTable.AddNote(newNote));
	}

	BOOST_AUTO_TEST_CASE(you_can_pass_the_table_name_when_table_initialize)
	{
		BOOST_CHECK_NO_THROW(dataTable.SetName("new table"));
	}

	BOOST_AUTO_TEST_CASE(uninitialized_number_of_entries_in_the_table_will_be_five)
	{
		BOOST_CHECK_EQUAL(dataTable.GetNotesCount(), 3);
	}

	BOOST_AUTO_TEST_CASE(uninitialized_number_of_columns_in_the_table_will_be_zero)
	{
		BOOST_CHECK_EQUAL(dataTable.GetColumnCount(), 5);
	}

	BOOST_AUTO_TEST_CASE(name_of_the_table_not_empty_string)
	{
		BOOST_CHECK_EQUAL(dataTable.GetName(), "My_table");
	}

	BOOST_AUTO_TEST_CASE(you_can_get_the_note)
	{
		CNote note;
		BOOST_CHECK_NO_THROW(note = dataTable.GetNote(0));
		BOOST_CHECK_EQUAL(note.GetColumnValue(0).GetValue(), "1");
		BOOST_CHECK_EQUAL(note.GetColumnValue(1).GetValue(), "asus");
		BOOST_CHECK_EQUAL(note.GetColumnValue(2).GetValue(), "Vasya");
		BOOST_CHECK_EQUAL(note.GetColumnValue(3).GetValue(), "qwerty123");
		BOOST_CHECK_EQUAL(note.GetColumnValue(4).GetValue(), "Vasya_ya");
	}

BOOST_AUTO_TEST_SUITE_END()