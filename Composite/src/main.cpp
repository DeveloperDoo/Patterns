#include <iostream>
#include "composite.h"
using namespace std;


/**
 * @brief Пример использования Composite
 */
void user_logic(BaseComponent* comp)
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
	 * @brief Пример работы с листовым компонетом
	 */
	{
		SimpleComponent sComp;
		user_logic(&sComp);	
	}


	/**
	 * @brief Пример работы с композитным компонетом
	 */
	{
		SimpleComponent sCompA1;
		CompositeComponent branchA;
		branchA.add_child(&sCompA1);

		SimpleComponent sCompB1;
		SimpleComponent sCompB2;
		CompositeComponent branchB;
		branchB.add_child(&sCompB1);
		branchB.add_child(&sCompB2);

		CompositeComponent tree;
		tree.add_child(&branchA);
		tree.add_child(&branchB);

		user_logic(&tree);
	}
	

	return;
}

int main(int argc, char **argv)
{
	pattern_demo();
	return 0;
}