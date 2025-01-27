#pragma once

// Needs to be a templated struct
template<typename T>
struct Node
{
public:
	Node<T>();
	Node<T>(T value);
	// Explicitely stating that the default node destructor is the destructor
	~Node<T>() = default;
	
public:
	T value;
	// Points to the next node
	Node<T>* next;
	// Points to the previous node
	Node<T>* previous;
};

// Currently setting value to not be anything
template<typename T>
inline Node<T>::Node() : next(nullptr), previous(nullptr)
{
}

// Sets next and previous to null and stores the value
template<typename T>
inline Node<T>::Node(T value) : next(nullptr), previous(nullptr), value(value)
{
}