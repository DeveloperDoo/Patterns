/**
 *
 * Класс, реализующий простой logger.
 * - Класс хранит ссылку на один из объектов стратегии (которые реализуют способ вывода логов);
 * - Класс не знает ничего о какой либо отдельной стратегии и знает только интерфейс стратегии;
 *
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include "strategys.h"

class MiniLogger {
public:
	MiniLogger(LogStrategy* lstrategy)
		: _lstrategy(lstrategy) 
	{};

	~MiniLogger() {
		if (nullptr != _lstrategy)
			delete _lstrategy;
	}
	
	void Debug(std::string msg) {
		if (nullptr != _lstrategy)
	        _lstrategy->Debug(msg);
	}

	void Info(std::string msg) {
		if (nullptr != _lstrategy)
			_lstrategy->Info(msg);
	}

	void Warning(std::string msg) {
		if (nullptr != _lstrategy)
			_lstrategy->Warning(msg);
	}

	void Error(std::string msg) {
		if (nullptr != _lstrategy)
			_lstrategy->Error(msg);
	}

	void Fatal(std::string msg) {
		if (nullptr != _lstrategy)
			_lstrategy->Fatal(msg);
	}
private:
	LogStrategy* 	_lstrategy; 	//Указатель на класс конкретной стратегии
};

#endif

