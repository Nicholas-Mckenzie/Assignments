
#include "Application.h"
#include "InfixToPostfix.h"

#include <stack>
#include <iostream>


Application::Application()
{
	run();
}

void Application::run()
{
	queueTest();

	std::cout << "\n----------------------------" << std::endl;
	std::cout << "--- End of Queue Testing ---" << std::endl;
	std::cout << "----------------------------\n" << std::endl;


	std::string input;

	std::cout << "Enter \"quit\" at anytime to exit the program\n" << std::endl;

	while (true)
	{
		std::cout << "expression: ";
		getline(std::cin, input);

		if (input == "quit")
			break;
		else
		{
			InfixToPostfix temp(input);

			if (temp.balancedParentheses())
			{
				std::cout << "Postfix: " << temp.getPostfix() << std::endl;
			}
			else
				std::cout << "Expression doesn't have balanced parentheses!\n" << std::endl;
		}
		std::cout << std::endl;
	}
}


void Application::queueTest()
{
	Queue<int> queue;

	std::cout << "Adding elements to queue . . ." << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		queue.push(i);
	}
	printQueue(queue);

	std::cout << "Poping element" << std::endl;
	queue.pop();
	printQueue(queue);
	std::cout << "Front of Queue: " << queue.front() << std::endl;
	printQueue(queue);

}