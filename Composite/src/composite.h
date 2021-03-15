#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <list>
using namespace std;


/**
 * @brief Базовый класс для компонентов
 * @details Определяет поведение как простых компонентов, так и композитных
 */
class BaseComponent 
{
protected:
	/**
	 * @brief Указатель на родителя
	 */
	BaseComponent* _parrent;

public:
	virtual ~BaseComponent() {};
	
	/**
	 * @brief Метод получения указателя на родителя компонента
	 */
	BaseComponent* get_parrent() const
	{
		return _parrent;
	}

	/**
	 * @brief Метод установки родителя компонета
	 */
	void set_parrent(BaseComponent* parrent)
	{
		_parrent = parrent;
	}

	/**
	 * @brief Метод добавления дочерних компонентов
	 */
	virtual void add_child(BaseComponent* component) 
	{
		//
	}

	/**
	 * @brief Метод удаления дочерних компонетов
	 */
	virtual void remove_child(BaseComponent* component)
	{
		// 
	}

	/**
	 * @brief Метод определения возможного наличия дочерних элементов
	 */
	virtual bool is_composite() const
	{
		return false;
	}

	/**
	 * @brief Некая логика, выполняемая компонетом
	 */
	virtual std::string foo() = 0;
};


/**
 * @brief Класс - лист
 * @details Не имеет дочерних элементов (т.е. не является композитным)
 * Обычно такие классы выполняют основную работу, в то время как 
 * композитные классы лишь делегируют им свои обязанности
 */
class SimpleComponent : public BaseComponent
{
public:
	/**
	 * @brief Перегруженный метод логики компонентов для листа
	 */
	std::string foo() 
	{
		return "SimpleComponent";
	}
};



/**
 * @brief Составной класс
 * @details Является хранилищем листовых и составных объектов
 */
class CompositeComponent : public BaseComponent
{
protected:
	std::list<BaseComponent*> _children;

public:
	
	bool is_composite()
	{
		return true;
	}

	void add_child(BaseComponent* child)
	{
		_children.push_back(child);
		child->set_parrent(this);
	}

	void remove_child(BaseComponent* child)
	{
		_children.remove(child);
		child->set_parrent(nullptr);
	}

	std::string foo()
	{
		std::string result;

		for(BaseComponent* comp : _children)
		{
			if (comp == _children.back())
			{
				result += comp->foo(); 
			}
			
			else 
			{
				result += comp->foo() + "+";
			}
		}
		return "Composite+(" + result + ")"; 
	}

};


#endif