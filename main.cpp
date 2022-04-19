#include "sqlite3/sqlite3.h"
#include <iostream>
int callback(void *, int, char **, char **) { return 0; }
int main(int argc, const char **argv) {

  sqlite3 *db;
  auto ret = sqlite3_open("test.db", &db);
  if (ret) {
    std::cout << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    return 0;
  }
  auto sql = "create table Person("
             "id INT PRIMARY KEY     NOT NULL,"
             "name           TEXT    NOT NULL,"
             "age            INT     NOT NULL);";
  char *msg = 0;
  ret = sqlite3_exec(db, sql, callback, 0, &msg);
  if (ret != SQLITE_OK) {
    std::cout << "error : " << msg << std::endl;
    sqlite3_free(msg);
  } else {
    std::cout << "Table created successfully" << std::endl;
  }
  sqlite3_close(db);

  return 0;
}