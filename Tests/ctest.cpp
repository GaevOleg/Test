#include "ctest.h"
#include "main.h"

using namespace std;

const int max_size = 20;



CTEST(date_to_unixtime, boundary_values)
{
	//Given
	string date ="31.12.2000 23:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 0;
	ASSERT_EQUAL(EXresult,result);
	char EXTime[] = "978307140";
	ASSERT_STR(EXTime,time);
}

CTEST(date_to_unixtime, wrong_values_1)
{
	//Given
	string date ="31.12.1999 23:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_2)
{
	//Given
	string date ="31.13.2000 23:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_3)
{
	//Given
	string date ="32.12.2000 23:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_4)
{
	//Given
	string date ="31.12.2000 24:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_5)
{
	//Given
	string date ="31.12.2000 23:60";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_6)
{
	//Given
	string date ="-20.4.2020 14:35";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_7)
{
	//Given
	string date ="14.-8.2003 11:30";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_8)
{
	//Given
	string date ="13.3.-2009 22:00";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_9)
{
	//Given
	string date ="10.2.2016 -21:22";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_10)
{
	//Given
	string date ="13.3.2009 22:-01";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_11)
{
	//Given
	string date ="-32.-13.30000 -24:-60";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_12)
{
	//Given
	string date ="31.12.199923:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_13)
{
	//Given
	string date ="31";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}

CTEST(date_to_unixtime, wrong_values_14)
{
	//Given
	string date ="23:59";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 1;
	ASSERT_EQUAL(EXresult,result);
	
}


CTEST(date_to_unixtime, correct_value_1)
{
	//Given
	string date ="11.07.2030 23:20";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 0;
	ASSERT_EQUAL(EXresult,result);
	char EXTime[] = "1910042400";
	ASSERT_STR(EXTime,time);
	
}

CTEST(date_to_unixtime, correct_value_2)
{
	//Given
	string date ="13.10.2052 11:45";
	char time[max_size];
	
	//When
	int result = date_to_unixtime(date,time);

	//Then
	int EXresult = 0;
	ASSERT_EQUAL(EXresult,result);
	char EXTime[] = "2612432700";
	ASSERT_STR(EXTime,time);
	
}

CTEST(output_full_path, correct_value_1)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Novosibirsk", end = "Novokuznetsk", num = "23";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, correct_value_2)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Gerg", end = "Gergo", num = "893";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, correct_value_3)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Kemerovo", end = "Kurundus", num = "893";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}


CTEST(output_full_path, wrong_value_1)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "St-Petersurg", end = "St-Petersurg", num = "24";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, wrong_value_2)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "1", end = "1", num = "24";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, wrong_value_3)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "St-Petersurg", end = " ", num = "-24";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, wrong_value_4)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Novokuznetsk", end = "Novosibirsk", num = "23";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, wrong_value_5)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Kurundus", end = "Kemerovo", num = "23";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}

CTEST(output_full_path, correct_value_6)
{
	//Given
	sqlite3* db;
	sqlite3_open("test.db",&db);
	
	string start = "Kemerovo", end = "Toguchin", num = "893";
	
	//When
	int result = output_full_path(db,num,start,end);

	//Then
	ASSERT_FALSE(result);
	
}


