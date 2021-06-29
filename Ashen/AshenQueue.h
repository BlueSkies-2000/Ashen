#pragma once
#include<memory>
#include<stdexcept>
#include<array>
template<typename T>
class AshenQueue {
	size_t head = 0;
	std::unique_ptr<T[]> items;

};