#include <stdio.h>
#include "SQLite/sqlite3.h"
int callback(void *data, int argc, char **argv, char **colName);
int main()
{
    sqlite3 *db;
    if (sqlite3_open("DBFile.db", &db))
    {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
　　　　 exit(0);
    }
    else
    {
        printf("Opened database successfully\n");
        const char *sql = "select * from Student";
        const char* data = "Callback function called";
        char *errMsg;
        if(SQLITE_OK == sqlite3_exec(db, sql, callback, (void*)data, &errMsg))
        {
            printf("Operation done successfully\n");
            if (SQLITE_OK == sqlite3_exec(db, "delete from Student where id=-100", NULL, NULL, &errMsg))
            {
                printf("The record deleted");
            }
            else
            {
                printf("SQL error: %s\n", errMsg);
                sqlite3_free(errMsg);
            }
        }
        else
        {
            printf("SQL error: %s\n", errMsg);
            sqlite3_free(errMsg);
        }
    }
    sqlite3_close(db);
    return 0;
}
int callback(void *data, int argc, char **argv, char **colName)
{
    int i;
    fprintf(stderr, "%s:\n", (const char*)data);
    for(i=0; i<argc; i++)
    {
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}