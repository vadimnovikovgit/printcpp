#include <iostream>
#include "DatabaseHandler.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	database_handler db;
	db.db_connect();
	db.query("yo");

}