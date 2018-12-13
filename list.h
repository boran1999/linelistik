#ifndef _LIST_H
#define _LIST_H
#include <iostream>

using namespace std;

class LineListException {};

template <class T> class LineListElem
{
	T data;
	LineListElem* next;
public:
	LineListElem(const T& adata, LineListElem* anext)
	{
		data = adata;
		next = anext;
	}
	const T& getData() const 
	{
		return data;
	}
	LineListElem* getNext()
	{
		return next;
	}
	template <class T>	friend class LineList;
};

template <class T> class LineList
{
	LineListElem<T>* start;
	LineList(const LineList& list);
	LineList& operator =(const LineList& list)
	{
		start = list.start;
	}

public:
	LineList()
	{
		start = 0;
	}
	~LineList() 
	{
		while (start)
			deleteFirst();
	}
	LineListElem<T>* getStart()
	{
		return start;
	}
	void deleteFirst()
	{
		if (start)
		{
			LineListElem<T>* temp = start->next;
			delete start;
			start = temp;
		}
		else
			throw LineListException();
	}
	void deleteAfter(LineListElem<T>* ptr)
	{
		if (ptr && ptr->next)
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
		}
		else
			throw LineListException();
	}
	void insertFirst(const T& data)
	{
		LineListElem<T>* second = start;
		start = new LineListElem<T>(data, second);
	}
	void insertAfter(LineListElem<T>* ptr, const T& data) 
	{
		if (ptr)
		{
			LineListElem<T>* temp = ptr->next;
			ptr->next = new LineListElem<T>(data, temp);
		}
		else
			throw LineListException();
	}
	LineListElem<T>* findptr(const T& adata)
	{
		LineListElem<T>* ptr = start;
		for (LineListElem<T>* it = ptr; it; it = it->getNext())
		{
			if (it->data==adata)
			{
				return it;
			}
		}
		throw LineListException();
		return 0;
	}
	LineListElem<T>* getptr(const int& i)
	{
		LineListElem<T>* ptr = start;
		int j = 0;
		for (LineListElem<T>* it = ptr; it; it = it->getNext()) 
		{
			if (j == i)
			{
				return it;
			}
			j++;
		}
		throw LineListException();
		return 0;
	}
	template <class T> friend ostream &operator<<(ostream &out, const LineList<T> &list) 
	{
		LineListElem<T>* ptr = list.start;
		if (!ptr)
			cout << "EMPTY" << endl;
		else
			while (ptr)
			{
				out << ptr->getData() << ' ';
				ptr = ptr->getNext();
			}
		return out;
	}

};

#endif -
