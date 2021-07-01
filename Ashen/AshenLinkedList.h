#pragma once
#include<memory>
#include<stdexcept>
template<typename T>
class AshenLinkedList {
private:
	struct Node {
		T val;
		std::unique_ptr<Node> next;
		Node(T data) : val{ data }, next{ nullptr }{};
	};
protected:
	std::unique_ptr<Node> head;
public:
	AshenLinkedList();
	void push(T val);
	T pop();
};

template<typename T>
inline AshenLinkedList<T>::AshenLinkedList() :head{ nullptr } {};

template<typename T>
void AshenLinkedList<T>::push(T val)
{
	auto temp{ std::make_unique<Node>(val) };
	if (head)
	{
		temp->next = std::move(head);
		head = std::move(temp);
	}
	else
	{
		head = std::move(temp);
	}
}
template<typename T>
inline T AshenLinkedList<T>::pop()
{
	T val;
	if (head)
	{
		val = head->val;
		head = std::move(head->next);
		return val;
	}
	else
	{
		throw std::runtime_error("Underflow");
	}
}
;
