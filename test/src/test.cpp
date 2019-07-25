#include <iostream>
#include "DatabaseHandler.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	database_handler db("HELL\\MY_DB", "Cartriges", "","", true);
	db.db_connect();

}