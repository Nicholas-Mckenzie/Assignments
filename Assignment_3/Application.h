#pragma once

#include <string>
#include <stack>
#include <iostream>

#include "Queue.h"


class Application
{
private:
	std::string infixStr;
	std::string postfix;
	std::stack<char> operators;

public:

	Application();


	void run();

	void queueTest();

	template<typename T>
	void printQueue(Queue<T> queue);

};

template<typename T>
void Application::printQueue(Queue<T> queue)
{
	if (queue.empty())
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	size_t temp = queue.size();

	std::cout << "{ ";
	for (size_t i = 0; i < temp; i++)
	{
		std::cout << queue.pop();

		if (i + 1 != temp)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}

