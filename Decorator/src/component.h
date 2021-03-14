#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

using namespace std;


/**
 * @brief Базовый интерфейс коспонентов
 * @details Класс, предоставляющий общий интерфейс
 * как для реализации конкретных компонентов, так и 
 * для реализации декораторов.
 */
class IComponent 
{
public:

	virtual ~IComponent() 
	{
		// ...
	}

	virtual std::string foo() = 0;
};


/**
 * @brief Конкретный компонент, реализующий поведение по умолчанию
 * @details Может существовать несколько вариаций реализации класса.
 */
class ComponentA : public IComponent
{
public:

	std::string foo()
	{
		return "ComponentA";
	}
};

#endif