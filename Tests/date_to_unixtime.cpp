#include "main.h"

using namespace std;
struct tm *tm_struct;

/*
 * На вход получает указатель на базу данных, строку, строку, строку.
 * При удачном выполнении возвращает 0, в случае каких либо ошибок, должна по сути возвращать что то,
 * что нулем не является, и не смотря на то что я все это скопировал из той функции,
 * то то как раз возвращает "что то еще", например 1 если дата не укладывается в человеческие понятия о дате,
 * или если пользователь ну ОЧЧЕНЬ любит паравозы. Хотя не удивлюсь, если и после 2000
 * в какой нибудь англии один еще катается.
 * Как гласит великая мудрость, не делай то что можно сделать завтра.
 */

int date_to_unixtime(string date_input, char *date, size_t arr_length){
    //Принимает на вход строку вида "%d.%m.%Y %H:%M", кросплатформенный вариант.
    int dd=0,mm=0,yy=0,HH=0,MM=0;
    time_t raw_time;
    sscanf(date_input.c_str(), "%d.%d.%d %d:%d", &dd, &mm, &yy, &HH, &MM);

    //Очень грубая проверка на правильнось ввода даты
    if(dd > 31 || mm > 12 || yy < 2000 || HH > 23 || MM > 59){
        cout << "Даты: " << date_input << " не существует" << endl;
        return 1;
    }
    tm_struct = localtime(&raw_time);
    tm_struct->tm_mday = dd;
    tm_struct->tm_mon = mm - 1;
    tm_struct->tm_year = yy - 1900;
    tm_struct->tm_hour = HH;
    tm_struct->tm_min = MM;

    strftime(date, arr_length, "%s", tm_struct);
    return 0;
};
