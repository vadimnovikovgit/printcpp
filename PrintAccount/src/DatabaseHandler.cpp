#include "../header/DatabaseHandler.h"


database_handler::database_handler() :
	m_dbServer(""), m_dbName(""), m_login(""), m_pwd(""), m_auth(false) {};

database_handler::database_handler(std::string server, std::string name, std::string login, std::string pwd, bool auth) :
	m_dbServer(server), m_dbName(name), m_login(login), m_pwd(pwd), m_auth(auth) {};