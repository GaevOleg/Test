#include "main.h"

using namespace std;

/*
 * На вход получает указатель на базу данных, строку, строку, строку.
 * При удачном выполнении возвращает 0, в случае каких либо ошибок, должна по сути возвращать что то,
 * что нулем не является, но нме пока лень, а завтра еще целый день.
 * Как гласит великая мудрость, не делай то что можно сделать завтра.
 */

int output_full_path(sqlite3 *db, string train_num, string start_point_input, string end_point_input){
    // input id_train
    const char* _get_full_path_by_train_num = "SELECT\n"
            "\t(SELECT name from station WHERE id=id_station) AS station_name,\n"
            "\tSTRFTIME('%H:%M', time_t, 'unixepoch', '+3 hours') AS capital_time,\n"
            "\tSTRFTIME('%d.%m.%Y', time_t, 'unixepoch', '+3 hours') AS capital_date,\n"
            "\tSTRFTIME('%H:%M', time_t, 'unixepoch', 'localtime') AS local_time,\n"
            "\tSTRFTIME('%d.%m.%Y', time_t, 'unixepoch', 'localtime') AS local_date\n"
            "FROM\n"
            "\ttrain_station\n"
            "WHERE\n"
            "\tid_train=(SELECT id FROM train where num=?);";

    bool in_path = false;
    sqlite3_stmt *train_path_stmt;
    string station_name, capital_time, capital_date, local_time, local_date;

    sqlite3_prepare(db, _get_full_path_by_train_num, -1, &train_path_stmt, 0);
    sqlite3_bind_text(train_path_stmt, 1, (const char*)train_num.c_str(), -1, 0);
    cout << endl;
    cout << "\t " << "   " << "STATION" << setw(13) << " | " << " MSK " << " | "
    << " MSK DATE " << " | " << "LOCAL" << " | " << "LOCAL DATE" << endl;

    while (sqlite3_step(train_path_stmt) == SQLITE_ROW){
        station_name = (char*)sqlite3_column_text(train_path_stmt, 0);
        capital_time = (char*)sqlite3_column_text(train_path_stmt, 1);
        capital_date = (char*)sqlite3_column_text(train_path_stmt, 2);
        local_time = (char*)sqlite3_column_text(train_path_stmt, 3);
        local_date = (char*)sqlite3_column_text(train_path_stmt, 4);
        if(start_point_input != "" && end_point_input != "") {
            if (not in_path && station_name == start_point_input.c_str()){
                cout << "\t*";
                in_path = true;
            }
            else if (in_path && station_name == end_point_input.c_str()){
                cout << "\t*";
                in_path = false;
            }
            else if (in_path){
                cout << "\t*";
            }
            else {
                cout << "\tX";
            }
        }
        else{
            cout << "\t ";
        }
        cout << " | " << station_name << setw(20-strlen(station_name.c_str())) << " | " << capital_time << " | "
        << capital_date << " | " << local_time << " | " << local_date << endl;
    }
    cout << endl;
    sqlite3_reset(train_path_stmt);
    sqlite3_finalize(train_path_stmt);
    return 0;
}
