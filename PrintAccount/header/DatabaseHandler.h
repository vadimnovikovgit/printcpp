#pragma once
#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>


class database_handler
{
	std::string		m_dbServer;
	std::string		m_dbName;
	std::string		m_login;
	std::string		m_pwd;
	bool			m_auth;


	
public:
	//Constructors-Destructors-----------------------------------------------
	database_handler();
	database_handler(std::string server , std::string dbname, std::string login, std::string pwd, bool auth);
	//-----------------------------------------------------------------------




	//get-set methods--------------------------------------------------------
	std::string getServer() const { return m_dbServer; }
	void setServer(std::string val) { m_dbServer = val; }

	std::string getName() const { return m_dbName; }
	void setName(std::string val) { m_dbName = val; }

	std::string getLogin() const { return m_login; }
	void setLogin(std::string val) { m_login = val; }

	std::string getPwd() const { return m_pwd; }
	void setPwd(std::string val) { m_pwd = val; }

	bool getAuth() const { return m_auth; }
	void setAuth(bool val) { m_auth = val; }
	//------------------------------------------------------------------------


	//database methods--------------------------------------------------------

	SQLHANDLE sqlenvhandle;
	SQLHANDLE sqlconnectionhandle;
	SQLHANDLE sqlstatementhandle;
	SQLRETURN retcode;

	void db_connect();									//connection to database
	void query();										//sql query maker
	void get_error(unsigned int, const SQLHANDLE&);		//error output




	//------------------------------------------------------------------------



};