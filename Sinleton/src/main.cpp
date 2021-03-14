#include <iostream>
#include <mutex>
using namespace std;

class MayersSingleton 
{
private:
	/**
	 * @brief Внутренний объект синхронизации
	 * @details Применяется для защиты данных и разграничения доступа к 
	 * ресурсам в многопоточной среде
	 */
	std::mutex sync_obj;

	/**
	 * @brief Конструктор класса
	 * @details Спрятан от клиента
	 */
	MayersSingleton() {}

public:

	/**
	 * @brief Конструктор копирования
	 * @details Удаляем т.к. одиночка не должен быть копируемым
	 */
	MayersSingleton(MayersSingleton&) = delete;

	/**
	 * @brief Оператор присваивания
	 * @details Удаляем т.к. одиночка не должен быть копируемым
	 */
	void operator=(const MayersSingleton&) = delete;

	/**
	 * @brief  Отложенная инициализация и получение ссылки
	 * @details Инициализация одиночки происходит при первом запросе ссылки на него
	 */

	static MayersSingleton& inst()
	{
		static MayersSingleton instance;
		return instance;
	}

	/**
	 * @brief  Бизнес-логика одиночки
	 * @details Просто печатает текст в консоль
	 */
	void foo() 
	{
		/**
		 * В данном случает стандартный поток вывода является
		 * разделяемым ресурсом, поэтому защищаем его мьютексом
		 */
		sync_obj.lock();
		cout << "FOO" << endl;
		sync_obj.unlock();
	}

};


int main(int argc, char **argv)
{
	MayersSingleton::inst().foo();
	MayersSingleton::inst().foo();
	MayersSingleton::inst().foo();
	return 0;
}
