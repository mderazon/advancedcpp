#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include "Exception.h"

template<typename T, typename R>
class tContainer_t
{
	R Container;
public:
	tContainer_t();
	~tContainer_t();

	bool IsEmpty();
	T& GetFirst() ;
	T& GetLast();
	T* Find(T const& item);
	T& operator [](unsigned i);
	int Size();
	void Insert(T* const item);	
	void Erase(T item);
	T* Remove(T item);
	void Clear();
	std::string Print();
};

template<typename T, typename R>
T* tContainer_t<T, R>::Remove( T item )
{
	// using lambda expressions, found in most compilers
	typename R::const_iterator it = std::find_if(Container.begin(), Container.end(),  [item](const T* v) { return std::abs(*v - item) < DBL_EPSILON; });
	if (it != Container.end())
	{
		T* pItem = (*it);
		Container.erase(it);
		return pItem;
	}
	else
		return NULL;
}

template<typename T, typename R>
void tContainer_t<T, R>::Erase( T item )
{
	T* pItem;
	if ((pItem = Remove(item)) != NULL )
	{
		delete pItem;
	}
	
}

template<typename T, typename R>
void tContainer_t<T, R>::Clear()
{
	Container.clear();
}

template<typename T, typename R>
T& tContainer_t<T, R>::operator[]( unsigned i )
{
	
	if (i < Container.size())
	{
		// using iterator for both vector and list as optimal efficiency is guaranteed :
		// http://stackoverflow.com/questions/10719145/operator-overloading-and-template-specialization
		typename R::const_iterator it = Container.begin();
		std::advance(it, i);
		return (**it);
	} 
	else
	{
		throw Exception("Illegal index exception");
	}
}

template<typename T, typename R>
T* tContainer_t<T, R>::Find( T const& item ) 
{
	// using lambda expressions, found in most compilers
	typename R::const_iterator it = std::find_if(Container.begin(), Container.end(),  [item](const T* v) { return *v == item; });
	if (it != Container.end())
		return (*it);
	else
		return NULL;
	
}

template<typename T, typename R>
std::string tContainer_t<T, R>::Print()
{
	int i = 0;
	std::ostringstream s;
	s << "[ ";
	typename R::const_iterator it;
	for(it = Container.begin(); it != Container.end(); it++)
	{
		s << (**it);
		if (i != Container.size()-1)
		{
			s << ", ";
		}
		i++;
	}
	s << " ]";
	return s.str();
}

template<typename T, typename R>
void tContainer_t<T, R>::Insert(T* const item )
{
	Container.push_back(item);
}

template<typename T, typename R>
int tContainer_t<T, R>::Size()
{
	return Container.size();
}

template<typename T, typename R>
T& tContainer_t<T, R>::GetLast()
{
	if (!Container.empty())
	{
		typename R::const_iterator it = Container.end();
		it--;
		return (**it);
	}
	else
	{
		throw Exception("Empty container exception");
	}
	
}

template<typename T, typename R>
T& tContainer_t<T, R>::GetFirst()
{
	if (!Container.empty())
	{
		typename R::const_iterator it = Container.begin();
		return (**it);
	}
	else
	{
		throw Exception("Empty container exception");
	}
}

template<typename T, typename R>
bool tContainer_t<T, R>::IsEmpty()
{
	return Container.empty();
}

//CTOR
template<typename T, typename R>
tContainer_t<T, R>::tContainer_t() : Container()
{
	
}
//DTOR
template<typename T, typename R>
tContainer_t<T, R>::~tContainer_t()
{

}

int main() 
{
	// Vector example
	std::cout <<"vector<double*> example" << std::endl << "-----------------------" << std::endl;
	try
	{
		tContainer_t<double, std::vector<double*> > v;
		double* f1 = new double; *f1 = 1.1;
		double* f2 = new double; *f2 = 2.2;
		double* f3 = new double; *f3 = 3.3;
		v.Insert(f1);
		v.Insert(f2);
		v.Insert(f3);
		std::cout << "v.Print()		: " << v.Print() << std::endl;
		std::cout << "v.Find(1.1)		: "<< "Found " << *v.Find(1.1) << std::endl;
		std::cout << "v[2]			: " << v[2] << std::endl;		
		std::cout << "v.IsEmpty()		: " << v.IsEmpty() << std::endl;
		std::cout << "v.Size()		: " << v.Size() << std::endl;
		std::cout << "v.GetFirst()		: " << v.GetFirst() << std::endl;
		std::cout << "v.GetLast()		: " << v.GetLast() << std::endl;
		std::cout << "v.Remove(3.3)		: " << "Removed " << *v.Remove(3.3) << std::endl;
		std::cout << "v.Print()		: " << v.Print() << std::endl;
		std::cout << "l.Clear()		: Clearing..." << std::endl; v.Clear();
		std::cout << "v.Print()		: " << v.Print() << std::endl;
	}	
	catch (Exception& e)
	{
		std::cout << e.what() << std::endl;
	}
				
	

	// List example
	std::cout << std::endl <<"list<int*> example" << std::endl << "------------------" << std::endl;
	try
	{
		tContainer_t<int, std::list<int*> > l;
		int* i1 = new int; *i1 = 1;
		int* i2 = new int; *i2 = 2;
		int* i3 = new int; *i3 = 3;
		l.Insert(i1);
		l.Insert(i2);
		l.Insert(i3);	
		std::cout << "l.Print()		: " << l.Print() << std::endl;
		std::cout << "l.Find(2)		: " << "Found " << *l.Find(2) << std::endl;
		std::cout << "l[0]			: " << l[0] << std::endl;		
		std::cout << "l.IsEmpty()		: " << l.IsEmpty()<< std::endl;
		std::cout << "l.Size()		: " << l.Size() << std::endl;
		std::cout <<"l.GetFirst()		: " << l.GetFirst() << std::endl;
		std::cout << "l.GetLast()		: " << l.GetLast() << std::endl;
		std::cout << "l.Remove(2)		: " << "Removed " << *l.Remove(2) << std::endl;
		std::cout << "l.Print()		: " << l.Print() << std::endl;
		std::cout << "l.Erase(3)		: Erasing..." << std::endl; l.Erase(3);
		std::cout << "l.Print()		: " << l.Print() << std::endl;
		std::cout << "l.Clear()		: Clearing..." << std::endl; l.Clear();
		std::cout << "l.Print()		: " << l.Print() << std::endl;
	}
	catch (Exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}