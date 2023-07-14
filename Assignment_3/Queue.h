#pragma once

#include <exception>


template<typename T>
class Queue
{
public:

	Queue();

	Queue(const Queue<T>& queue);
		

	bool empty() const;

	size_t size() const;

	T front() const;

	void push(T data);

	T pop();



private:
	struct Node
	{
		Node(T newData, Node* nextNode = nullptr)
			:data(newData), next(nextNode)
		{};

		Node(const Node& node)
			:data(node.data), next(node.next)
		{
		}

	public:
		T data;
		Node* next;
	};


	Node* head;
	Node* tail;
	size_t m_size;

};





template<typename T>
Queue<T>::Queue()
	: head(nullptr), tail(nullptr), m_size(0)
{}

template<typename T>
Queue<T>::Queue(const Queue<T>& queue)
	: head(nullptr), tail(nullptr), m_size(queue.size())
{
	if (!queue.empty())
	{
		head = new Node(*queue.head);

		Node* thisCurrentNode = head;
		Node* copyCurrentNode = queue.head;

		size_t length = queue.size();
		for (size_t i = 0; i < length-1; i++)
		{
			thisCurrentNode->next = new Node(*(copyCurrentNode->next));
			thisCurrentNode = thisCurrentNode->next;
			copyCurrentNode = copyCurrentNode->next;
		}
		tail = thisCurrentNode;
	}
}

template<typename T>
bool Queue<T>::empty() const
{
	return !m_size;
}

template<typename T>
size_t Queue<T>::size() const
{
	return m_size;
}

template<typename T>
T Queue<T>::front() const
{
	if (m_size == 0)
		throw std::runtime_error("Queue is empty");

	return head->data;
}

template<typename T>
void Queue<T>::push(T data)
{
	if (m_size == 0)
	{
		head = new Node(data);
		tail = head;
		m_size++;
		return;
	}

	Node* previousNode = tail;
	tail = new Node(data);
	previousNode->next = tail;
	m_size++;

}

template<typename T>
T Queue<T>::pop()
{
	if (m_size == 0)
		throw std::runtime_error("Queue is empty");

	T data = head->data;
	Node* nextNode = head->next;

	delete head;
	head = nextNode;
	m_size--;

	return data;
}