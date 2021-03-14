#include "component.h"

#ifndef DECORATOR_H
#define DECORATOR_H

/*
 * Базовый класс декоратора. 
 * Следует тому же интерфейсу, что и декорируемые компоненты.
 * Определяет общий интерфейс для реализации конкретных декораторов
 */
class ComponentDecorator : public IComponent
{

public:
	/**
	 * @brief Конструктор декоратора
	 * @details Принимает указатель на декорируемый объект
	 */
	ComponentDecorator(IComponent* component) 
		: _component(component) 
	{
		// ...
	}

	/**
	 * @brief Переопределенный метод интерфейса объектов
	 * @details Вызывается метод компонета, переданного в конструкторе
	 */
	std::string foo()
	{
		return _component->foo();
	}

protected:
	/**
	 * Указатель на декорируемый компонет
	 */
	IComponent*	_component;
};



/**
 * @brief Реализация конкретного декоратора ComponentDecoratorA
 * @details Унаследован от базового определения декораторов
 */
class ComponentDecoratorA : public ComponentDecorator
{

public:	
	/**
	 * @brief Конструктор конкретного декоратора
	 * @details Принимает указатель на декорируемый объект и вызывает 
	 * родительский конструктор
	 */
	ComponentDecoratorA(IComponent* component) 
		: ComponentDecorator(component)
	{
		// ..
	}

	/**
	 * @brief Переопределенный метод интерфейса объектов
	 */
	std::string foo()
	{
		return "ComponentDecoratorA <--" + ComponentDecorator::foo();
	}
};



class ComponentDecoratorB : public ComponentDecorator
{

public:
	/**
	 * @brief Конструктор конкретного декоратора
	 * @details Принимает указатель на декорируемый объект и вызывает 
	 * родительский конструктор
	 */
	ComponentDecoratorB(IComponent* component) 
		: ComponentDecorator(component)
	{
		// ..
	}

	/**
	 * @brief Переопределенный метод интерфейса объектов
	 */
	std::string foo()
	{
		return "ComponentDecoratorB <--" + ComponentDecorator::foo();
	}
};

#endif