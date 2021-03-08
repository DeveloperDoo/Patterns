#ifndef STRATEGYS_H
#define STRATEGYS_H

#include <iostream>
#include <string>
#include <fstream>


/**
 *
 * Интерфейс LogStrategy описывает общие операции для всех алгоритмов логгирования.
 * Клиентский класс MiniLogger использует данный интерфейс для вызова алгоритма
 * определенного конкретными стратегиями.
 *
 */
class LogStrategy {
public:
	virtual ~LogStrategy() {}
	virtual void Debug(std::string& msg) = 0;
	virtual void Info(std::string& msg) = 0;
	virtual void Warning(std::string& msg) = 0;
	virtual void Error(std::string& msg) = 0;
	virtual void Fatal(std::string& msg) = 0;
};


/**
 *
 * Конкретная стратегия StdOutMinimal
 * Реализует алгоритм минимального вывода лог-сообщения в стандартный поток вывода
 *
 */
class StdOutMinimal : public LogStrategy {
public:
	void Debug(std::string& msg) override {
		std::cout << "[DEBUG] -- " << msg << std::endl;
	}
	
	void Info(std::string& msg) override {
		std::cout << "[INFO] -- " << msg << std::endl;
	}
	
	void Warning(std::string& msg) override {
		std::cout << "[WARNING] -- " << msg << std::endl;
	}
	
	void Error(std::string& msg) override {
		std::cout << "[ERROR] -- " << msg << std::endl;
	}
	
	void Fatal(std::string& msg) override {
		std::cout << "[FATAL] -- " << msg << std::endl;
	}
};


/**
 *
 * Конкретная стратегия StdOutExtended
 * Реализует алгоритм вывода лог-сообщения в файл
 *
 */
class FileOutMinimal : public LogStrategy {
private:
	std::ofstream* lfile;

public:
	FileOutMinimal(std::string fname) : lfile(nullptr) {
		try {
			lfile = new std::ofstream(fname);
		}
	   	catch (...) {
			std::cout << "Constructor failed" << std::endl;
			lfile = nullptr;
		}	
	}

	~FileOutMinimal() {
		if (nullptr != lfile)
			lfile->close();
	}

	void Debug(std::string& msg) override {
		if (nullptr != lfile)
			*lfile << "[DEBUG] -- " << msg << std::endl;
	}
	
	void Info(std::string& msg) override {
		if (nullptr != lfile) 
			*lfile << "[INFO] -- " << msg << std::endl;
	}
	
	void Warning(std::string& msg) override {
		if (nullptr != lfile)
			*lfile << "[WARNING] -- " << msg << std::endl;
	}
	
	void Error(std::string& msg) override {
		if (nullptr != lfile)
			*lfile << "[ERROR] -- " << msg << std::endl;
	}
	
	void Fatal(std::string& msg) override {
		if (nullptr != lfile)
			*lfile << "[FATAL] -- " << msg << std::endl;
	}
};

#endif
