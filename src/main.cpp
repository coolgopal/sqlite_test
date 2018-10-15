#include <iostream>

#include <sqlite3.h>

using namespace std;

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

    return 0;
}

