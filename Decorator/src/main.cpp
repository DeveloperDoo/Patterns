#include <iostream>
#include "component.h"
#include "decorator.h"
using namespace std;

/**
 * @brief Пример использования объектов интерфейса IComponent
 * В данном случае вызывает метод foo и печатает его вывод в консоль
 */
void user_logic(IComponent* comp)
{
	if (nullptr == comp) {
		cout << "invalid parametr" << endl;
		return;
	}

	cout << comp->foo() << endl;
}


/**
 * @brief Демонстрация работы паттерна
 */
void pattern_demo()
{
	/**
	 * Использование "чистого" недекорируемого объекта
	 */
	{
		ComponentA compA;
		user_logic(&compA);		
	}

	/**
	 * Использование объекта класса ComponentA
	 * декорируемого декоратором ComponentDecoratorA
	 */
	{
		ComponentA compA;
		ComponentDecoratorA decA(&compA);
		user_logic(&decA);
	}


	/**
	 * Использование объекта класса ComponentA
	 * декорируемого декоратором ComponentDecoratorB
	 */
	{
		ComponentA compA;
		ComponentDecoratorB decB(&compA);
		user_logic(&decB);
	}

	/**
	 * Использование объекта класса ComponentA
	 * декорируемого декоратороми ComponentDecoratorA
	 * и ComponentDecoratorB.
	 */
	{
		IComponent* compA 	= new ComponentA();
		IComponent* decA 	= new ComponentDecoratorA(compA);
		ComponentDecoratorB decB(decA);
		user_logic(&decB);
		delete decA;
		delete compA;
	}

	return;
}

int main(int argc, char **argv)
{
	pattern_demo();
	return 0;
}
