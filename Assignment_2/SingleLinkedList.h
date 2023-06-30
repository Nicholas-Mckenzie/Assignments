#pragma once

#include <iostream>



template<typename T>
class SingleLinkedList
{
private:

	struct Node
	{
		T data;
		Node* next;

		Node(const T& initData, Node* nextPtr = nullptr)
			: data(initData), next(nextPtr)
		{
		}

	};

	Node* head;
	Node* tail;
	size_t numItems;


public:

	SingleLinkedList(T initData[], size_t size);
	SingleLinkedList();

	// Prints current Size of list
	size_t size() const;

	// Adds element to front of list
	void pushFront(T data);

	// Adds element to back of list
	void pushBack(T data);

	// Removes element from front of list
	void popFront();

	// Removes element from back of list
	void popBack();

	// Returns data at front of lijst
	T front() const;

	// Returns data at back of list
	T back() const;

	// Checks if list is empty or not
	bool empty() const;

	// Inserts elment at given index of list
	// If index is beyond end of list pushBack() is called
	void insert(T data, size_t index);

	// Removes an element at given index
	// Returns true if successful false otherwise
	bool remove(size_t index);

	// Finds the first instance of the given data and returns its index
	size_t find(T data);

	// Prints entire list to console
	void printList() const;

	template<size_t n>
	static void testSingleLinkedList(int array[n]);
};


/*
*   ////////////////////////////////////
*	Template Class Implementation below
*	//////////////////////////////////// 
*/


template<typename T>
SingleLinkedList<T>::SingleLinkedList(T initData[], size_t size)
	: head(nullptr), tail(nullptr), numItems(size)
{
	if (size > 0)
		head = new Node(initData[0]);

	Node* currentNode;
	Node* previousNode = head;

	for (size_t i = 1; i < size; i++)
	{
		currentNode = new Node(initData[i]);
		previousNode->next = currentNode;
		previousNode = currentNode;
	}

	tail = previousNode;
}

template<typename T>
SingleLinkedList<T>::SingleLinkedList()
	: head(nullptr), tail(nullptr), numItems(0)
{
}

template<typename T>
size_t SingleLinkedList<T>::size() const
{
	return numItems;
}

template<typename T>
void SingleLinkedList<T>::pushFront(T data)
{
	Node* nextNode = head;
	head = new Node(data, nextNode);
	numItems++;
}

template<typename T>
void SingleLinkedList<T>::pushBack(T data)
{
	Node* previousNode = tail;
	tail = new Node(data);
	previousNode->next = tail;
	numItems++;
}

template<typename T>
void SingleLinkedList<T>::popFront()
{
	Node* tempNode = head;
	head = head->next;
	delete tempNode;
	numItems--;
}

template<typename T>
void SingleLinkedList<T>::popBack()
{
	Node* tempNode = head;

	for (size_t i = 1; i < numItems - 1; i++)
	{
		tempNode = tempNode->next;
	}

	tail = tempNode;
	tempNode = tempNode->next;
	delete tempNode;

	numItems--;
}

template<typename T>
T SingleLinkedList<T>::front() const
{
	return head->data;
}

template<typename T>
T SingleLinkedList<T>::back() const
{
	return tail->data;
}

template<typename T>
bool SingleLinkedList<T>::empty() const
{
	if (numItems == 0)
		return true;

	return false;
}

template<typename T>
void SingleLinkedList<T>::insert(T data, size_t index)
{
	if (numItems == 0 && index == 0)
	{
		head = new Node(data);
		tail = head;
		numItems++;
		return;
	}
	else if (index == 0)
	{
		pushFront(data);
		return;
	}
	else if (index >= numItems)
	{
		pushBack(data);
		return;
	}

	Node* temp = head;

	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}

	Node* newNode = new Node(data, temp->next);
	temp->next = newNode;
	numItems++;
}

template<typename T>
bool SingleLinkedList<T>::remove(size_t index)
{
	if (numItems == 0)
	{
		return false;
	}
	else if (index == 0)
	{
		popFront();
		return true;;
	}
	else if (index == numItems - 1)
	{
		popBack();
		return true;;
	}
	else if (index >= numItems)
	{
		return false;
	}

	Node* previousNode = head;
	Node* temp;

	for (int i = 0; i < index - 1; i++)
	{
		previousNode = previousNode->next;
	}

	temp = previousNode->next;
	previousNode->next = previousNode->next->next;
	delete temp;

	numItems--;

	return true;
}

template<typename T>
size_t SingleLinkedList<T>::find(T data)
{
	Node* temp = head;

	for (size_t i = 0; i < numItems; i++)
	{
		if (temp->data == data)
			return i;

		temp = temp->next;
	}

	return 0;
}

template<typename T>
void SingleLinkedList<T>::printList() const
{
	if (numItems == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}

	Node* temp = head;

	std::cout << "{ ";
	while (temp != tail)
	{
		std::cout << temp->data << ", ";

		temp = temp->next;
	}
	std::cout << tail->data << " }, size: " << size() << std::endl;
}
