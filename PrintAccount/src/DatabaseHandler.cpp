#include "../header/DatabaseHandler.h"


database_handler::database_handler():
	m_dbServer(""), m_dbName(""), m_login(""), m_pwd(""), m_auth(false) {};

database_handler::database_handler(std::string server, std::string name, std::string login, std::string pwd, bool auth) :
	m_dbServer(server), m_dbName(name), m_login(login), m_pwd(pwd), m_auth(auth) {};



void database_handler::get_error(unsigned int handletype, const SQLHANDLE& handle)
{

	SQLCHAR sqlstate[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
		std::cout << "Message: " << message << "\nSQLSTATE: " << sqlstate << std::endl;
}

void database_handler::db_connect()
{

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
		return;

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlenvhandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		return;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
		return;



	SQLCHAR retconstring[1024];


	switch (SQLDriverConnect(sqlconnectionhandle, NULL,
		(SQLCHAR*)"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=MyDatabase;UID=sa;PWD=Admin-123;",
		SQL_NTS, retconstring, 1024, NULL, SQL_DRIVER_NOPROMPT))
	{
	case SQL_SUCCESS_WITH_INFO:
		get_error(SQL_HANDLE_DBC, sqlconnectionhandle);
		break;
	case SQL_INVALID_HANDLE:
	case SQL_ERROR:
		get_error(SQL_HANDLE_DBC, sqlconnectionhandle);
		retcode = -1;
		break;
	default:
		break;
	}

}