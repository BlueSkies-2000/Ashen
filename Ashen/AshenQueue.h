#pragma once
#include<memory>
#include<stdexcept>
#include<array>
template<typename T>
class AshenQueue {
public:
	AshenQueue();
	void enqueue(T val);
	T dequeue();
private:
	struct Node
	{
		T val;
		std::unique_ptr<Node> next;
		Node(T data) : val{ data }, next{ nullptr }{};
	};
protected:
	std::unique_ptr<Node> front;
	std::unique_ptr<Node> rear;
};

template<typename T>
AshenQueue<T>::AshenQueue() :rear{ nullptr } {}
template<typename T>
void AshenQueue<T>::enqueue(T val)
{
	auto temp{ std::make_unique<Node>(val) };
	if (rear)
	{
		rear->next = std::move(temp);
		rear = std::move(temp);
	}
	else
	{
		rear = std::move(temp);
		front = std::move(temp);
	}
}
template<typename T>
T AshenQueue<T>::dequeue()
{
	if (rear)
	{
		T val = front->val;
		front = std::move(front->next);
	}
	else
	{
		throw std::runtime_error("Underflow");
	}
}
;
