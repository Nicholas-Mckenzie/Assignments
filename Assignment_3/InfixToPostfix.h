#pragma once

#include <string>
#include <stack>

class InfixToPostfix
{
public:
	InfixToPostfix(std::string expression);

	std::string getPostfix() const;

	bool balancedParentheses();

private:
	std::string infixStr;
	std::string postfixStr;
	std::stack<char> operatorStack;

	void infixToPostfix();

	void processOperator(char oper);

	bool isOperator(char oper);

	int operatorPrecedence(char oper);

	bool isOpenParenthese(char character);

	bool isClosingParenthese(char character);

	bool balancedPair(char char1, char char2);

	std::string getOperatorStack() const;

};