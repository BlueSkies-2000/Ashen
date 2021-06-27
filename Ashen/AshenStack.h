#pragma once
#include<memory>
#include<stdexcept>

template<typename T>
class AshenStack {
	size_t head = 0;
	size_t length = 1;
	T* items = new T[1];
public:
	T get_head() const;
	void push(T);
	T pop();
private: 
	void resize(size_t);
};
template<typename T>
void AshenStack<T>::resize(size_t new_size)
{
	T* temp = new T[new_size];
	for (int i = 0; i < length; i++)
	{
		temp[i] = items[i];
	}
	items = temp;
	length = new_size;
}
template<typename T>
T AshenStack<T>::get_head() const {
	return items[head];
};
template<typename T>
void AshenStack<T>::push(T val)
{
	if (head == length)
		resize(2 * length);
	items[head++] = val;
}
template<typename T>
T AshenStack<T>::pop()
{
	if (head > 0 && head == length / 4)
		resize(length / 2);
	return items[head--];
}