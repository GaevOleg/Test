#include <limits.h>
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
    #define MAX_PATH MAX_PATH
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
    #define MAX_PATH PATH_MAX
#endif
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include "sqlite3.h"

int output_full_path(sqlite3 *db,
                      std::string train_num,
                      std::string start_point_input="",
                      std::string end_point_input="");

int date_to_unixtime(std::string date_input,
                     char *date,
                     size_t arr_length=20);
