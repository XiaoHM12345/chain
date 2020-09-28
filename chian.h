#pragma once
#ifndef _CHIAN_
#define _CHIAN_
#include "type.h"
#include<iostream>

_DSCPP_BEGIN
template <class T>
struct chainNode
{
	//ds member
	T element;
	chainNode<T>* next;

	//methon
	chainNode() {}
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};

template<class T>
class chain
{
public:
	chain(CAPACITY initialCapacity = 10);
	chain(const chain<T>&);
	~chain()
	{
		while (firstNode != nullptr)
		{
			chainNode<T>* nextNode = firstNode->next;
			delete firstNode;
			firstNode = nextNode;
		}
	}

	//ADT methon
	bool empty() const { return listSize == 0; }
	SIZE size() const { return listSize; }
	T& get(int theIndex)
	{
		if (!CHECK_INDEX(theIndex, listSize))
		{
			std::cerr << "the index out of range" << std::endl;
			exit(-1);
		}

		chainNode<T>* currentNode = firstNode;
		for (int i = 0; i < theIndex; i++)
			currentNode = currentNode->next;
		return currentNode->element;
	}

	void insert(int theIndex, const T& theElement)
	{
		if (theIndex < 0 || theIndex > listSize)
		{
			std::cerr << "the index out of range" << std::endl;
			exit(-1);
		}

		if (theIndex == 0)
			//first noed insert
			firstNode = new chainNode<T>(theElement, firstNode);
		else
		{
			chainNode<T>* p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)
				p = p->next;
			p->next = new chainNode<T>(theElement, p->next);
		}
		listSize++;
	}

protected:
	/*
	int checkIndex(int theIndex) const
	{
		if (theIndex < 0 || theIndex >= listSize)
			return INDEX_ERROR;
	}*/
	chainNode<T>* firstNode;
	SIZE listSize;
};

template<class T>
chain<T>::chain(CAPACITY initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::cerr << "initial capacity must be > 0" << std::endl;
		exit(-1);
	}

	firstNode = nullptr;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
	//copy constructor
	listSize = theList.listSize;

	if (listSize == 0)
	{
		//if the chain it empty
		firstNode = nullptr;
		return;
	}

	//if the chain is not empty
	chainNode<T>* sourceNode = theList.firstNode;
							//copy the first node
	firstNode = new chainNode<T>(sourceNode->element);
							//copy the element of the first node
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;
							//the last node of the current chain *this
	while (sourceNode != nullptr)
	{
		//copy the remaining element
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}

_DSCPP_END

#endif // !_CHIAN_