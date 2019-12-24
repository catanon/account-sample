#pragma once

template<class T> class DynamicArray
{
	int capacity;
	int used;
	T** list;

	static void moveFromTo(T** src, int num, T** des);
public:
	DynamicArray();
	// Copy constructor for previously not initialized
	DynamicArray(const DynamicArray& other);
	// Assignment for initialized
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	void add(T newArg);
	T get(int i);
	void remove();
	void remove(int position);
	void set(int position, T newValue);
	int size();
};



template<class T>
void DynamicArray<T>::moveFromTo(T** src, int num, T** des)
{
	for (int i = 0; i < num; i++)
	{
		*(des + i) = new T(**(src + i));
	}
}

template<class T>
DynamicArray<T>::DynamicArray()
{
	capacity = 1;
	used = 0;
	list = new T * [capacity];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	capacity = other.capacity;
	used = other.used;
	list = new T * [capacity];
	moveFromTo(other.list, other.used, list);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	capacity = other.capacity;
	// Release old dynamic to prepare for copying new
	this->~DynamicArray();
	// Need to overide used after call the destructor
	used = other.used;
	list = new T * [capacity];
	moveFromTo(other.list, other.used, list);
	return *this;
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	for (int i = 0; i < used; i++)
	{
		delete list[i];
	}
	delete[] list;
}

template<class T>
void DynamicArray<T>::add(T newArg)
{
	list[used] = new T(newArg);

	used++;
	if (used == capacity)
	{
		capacity *= 2;
		T** largerList = new T * [capacity];
		for (int i = 0; i < used; i++)
		{
			*(largerList + i) = *(list + i);
		}
		delete[] list;
		list = largerList;
	}
}

template<class T>
T DynamicArray<T>::get(int i)
{
	if (i < 0 || i >= size()) throw "Dev Error: Out of bound access";
	return **(list + i);
}

template<class T>
void DynamicArray<T>::remove()
{
	if (used == 0) throw "Dev Error: There is no argument to remove";
	used--;
	delete list[used];
}

template<class T>
inline void DynamicArray<T>::remove(int position)
{
	if (position < 0 || position >= size()) throw "Dev Error: Out of bound access";
	used--;
	delete list[position];

	for (int i = position + 1; i < used + 1; i++)
	{
		list[i - 1] = list[i];
	}
}

template<class T>
inline void DynamicArray<T>::set(int position, T newValue)
{
	if (position < 0 || position >= used) throw "Dev Error: Out of bound access";
	delete list[position];
	list[position] = new T(newValue);
}

template<class T>
int DynamicArray<T>::size()
{
	return used;
}
