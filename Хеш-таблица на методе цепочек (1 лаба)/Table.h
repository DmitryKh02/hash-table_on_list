#pragma once
//#include <list>
#include <iostream>
#include"DoubleList.h"
#include "polynom.h"

template <class T>
class HASH_TABLE {
	List<T>** mas;
	//std::list<T>** mas;
	int tableSize;
protected:
	int hash(T obj);
public:
	HASH_TABLE(int size);
	~HASH_TABLE();	
	void push(T obj);
	void pop(T obj);
	void print();
};

template<class T>
HASH_TABLE<T>::HASH_TABLE(int size){
	size = abs(size);
	if (size == 0) size++;
	tableSize = size;

	mas = new List<T>*[tableSize];
	for (size_t i = 0; i < tableSize; i++)
		mas[i] = nullptr;
}

template<class T>
HASH_TABLE<T>::~HASH_TABLE(){
	for (size_t i = 0; i < tableSize; i++)
		delete mas[i];
	delete[] mas;
}

template<class T>
int HASH_TABLE<T>::hash(T obj){
	POLYNOM example(obj);
	return example.hashPolynom() % tableSize;
}

template<class T>
void HASH_TABLE<T>::push(T obj){
	int place = hash(obj);
	mas[place]->addToHead(mas[place], obj);
}

template<class T>
void HASH_TABLE<T>::pop(T obj){
	int place = hash(obj);
	mas[place] = mas[place]->replaceElem(mas[place], obj);
}

template<class T>
void HASH_TABLE<T>::print(){
	for (size_t i = 0; i < tableSize; i++) {
		std::cout << "\n Cell number is " << i;
		if (mas[i] != nullptr) {
			mas[i]->print(mas[i]);
		}
		else std::cout<<"\nEmpty!";
		
	}
}
