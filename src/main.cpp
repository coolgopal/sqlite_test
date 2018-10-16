#include <iostream>

#include <sqlite3.h>

using namespace std;

const char* SQLITE_CREATE_TABLE_TEACHER = "CREATE TABLE teacher (teacher_id integer PRIMARY KEY, teacher_name text NOT NULL, area text);";
const char* SQLITE_INSERT_INTO_TEACHER = "INSERT INTO teacher (teacher_name, area) values ('Dines Pal', 'Sonarpur');";
const char* SQLITE_SELECT_ALL_TEACHER = "SELECT * from teacher;";

static int callback(void* NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
        cout << azColName[i] << " = " << argv[i] << endl;

    cout << endl;
    return 0;
}

int main()
{
    char dbName[20] = "mathomota.db";

    sqlite3* db;
    int rc = sqlite3_open(dbName, &db);
    if (rc)
    {
        cout << "Can't open database: " << sqlite3_errmsg(db);
        sqlite3_close(db);
        return 1;
    }

    char* zErrMsg = 0;
    rc = sqlite3_exec(db, SQLITE_CREATE_TABLE_TEACHER, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "SQLite error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    rc = sqlite3_exec(db, SQLITE_INSERT_INTO_TEACHER, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "SQLite error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    rc = sqlite3_exec(db, SQLITE_SELECT_ALL_TEACHER, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        cout << "SQLite error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}

