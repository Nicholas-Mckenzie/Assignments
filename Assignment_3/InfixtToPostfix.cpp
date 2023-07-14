
#include "InfixToPostfix.h"

#include <iostream>

InfixToPostfix::InfixToPostfix(std::string expression)
	: infixStr(expression)
{
	infixToPostfix();

}

std::string InfixToPostfix::getPostfix() const
{
	return postfixStr;
}

void InfixToPostfix::infixToPostfix()
{
	size_t size = infixStr.size();
	for(size_t i = 0; i < size; i++)
	{
		char nextChar = infixStr[i + 1];
		char currentChar = infixStr[i];

		if (isOpenParenthese(currentChar) ||
			isClosingParenthese(currentChar))
		{
			processOperator(currentChar);
		}
		else if (!isOperator(currentChar))
			postfixStr.push_back(currentChar);
		else if (isOperator(currentChar))
			processOperator(currentChar);
		else
			std::cout << "Syntax error" << std::endl;
	}

	while (!operatorStack.empty())
	{
		postfixStr.push_back(operatorStack.top());
		operatorStack.pop();
	}
}

void InfixToPostfix::processOperator(char oper)
{
	if (operatorStack.empty() || isOpenParenthese(oper))
	{
		operatorStack.push(oper);
	}
	else if (isClosingParenthese(oper))
	{
		while (!operatorStack.empty() &&
			!isOpenParenthese(operatorStack.top()) &&
			operatorPrecedence(oper) <= operatorPrecedence(operatorStack.top()))
		{
			postfixStr.push_back(operatorStack.top());
			operatorStack.pop();
		}

		if (isClosingParenthese(oper))
		{
			if (!operatorStack.empty() && isOpenParenthese(operatorStack.top()))
			{
				operatorStack.pop();
			}
		}
	}
	else if (operatorPrecedence(oper) > operatorPrecedence(operatorStack.top()))
		operatorStack.push(oper);
	else
	{
		while (!operatorStack.empty() &&
			operatorPrecedence(oper) <= operatorPrecedence(operatorStack.top()))
		{
			postfixStr.push_back(operatorStack.top());
			operatorStack.pop();
		}
		operatorStack.push(oper);
	}

	//std::cout << "New Stack: " << getOperatorStack() << std::endl;
}


bool InfixToPostfix::balancedParentheses()
{
	std::stack<char> parentheses;

	for (char character : infixStr)
	{
		if (isOpenParenthese(character))
			parentheses.push(character);
		else if (isClosingParenthese(character))
		{
			if (parentheses.empty())
				return false;
			else if (balancedPair(parentheses.top(), character))
				parentheses.pop();
			else
				return false;
		}
	}

	return parentheses.empty();
}

bool InfixToPostfix::isOperator(char oper)
{
	char operators[5] = { '+','-','*','/','%' };

	for (char element : operators)
		if (element == oper)
			return true;

	return false;
}

int InfixToPostfix::operatorPrecedence(char oper)
{
	if (oper == '%' || oper == '/' || oper == '*')
		return 2;
	else if (oper == '+' || oper == '-')
		return 1;
	else
		return 0;

	return -1;
}

bool InfixToPostfix::isOpenParenthese(char character)
{
	char openPar[3] = { '(','[','{' };

	for (char temp : openPar)
	{
		if (character == temp)
			return true;
	}

	return false;
}

bool InfixToPostfix::isClosingParenthese(char character)
{
	char closePar[3] = { ')', ']', '}' };

	for (char temp : closePar)
	{
		if (character == temp)
			return true;
	}

	return false;
}

bool InfixToPostfix::balancedPair(char char1, char char2)
{
	if (char1 == '(' && char2 == ')')
		return true;
	else if (char1 == '[' && char2 == ']')
		return true;
	else if (char1 == '{' && char2 == '}')
		return true;

	return false;
}

std::string InfixToPostfix::getOperatorStack() const
{
	std::string temp;
	std::stack<char> stackTemp = operatorStack;

	while (!stackTemp.empty())
	{
		temp.push_back(stackTemp.top());
		stackTemp.pop();
	}

	return temp;
}