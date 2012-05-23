#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
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
	T& GetFirst() const;
	T& GetLast() const;
	T& Find(T const& item) const;
	T& operator [](unsigned i);
	int Size();
	void Insert(T* const item);
	
	std::string Print();
};

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
		throw Exception("Illegal index exception")
	}
}


template<typename T, typename R>
T& tContainer_t<T, R>::Find( T const& item ) const
{
	// using lambda expressions, found in most modern compilers
	typename R::const_iterator it = std::find_if(Container.begin(), Container.end(),  [item](const T* v) { return *v == item; });
	if (it != Container.end())
		return (**it);
	else
		throw Exception("Item not found in container");
	
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
	s << " ]" << std::endl;
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
T& tContainer_t<T, R>::GetLast() const
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
T& tContainer_t<T, R>::GetFirst() const
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
	std::cout <<"Vector example" << std::endl << "--------------" << std::endl;
	try
	{
		tContainer_t<double, std::vector<double*> > v;
		double f1 = 1.1;
		double f2 = 2.2;
		double f3 = 3.3;
		v.Insert(&f1);
		v.Insert(&f2);
		v.Insert(&f3);
		std::cout << "Found " << v.Find(1.1) << std::endl;
		std::cout << v.Print();
		std::cout << "container empty ? : " << v.IsEmpty()<< std::endl
			<< "container size: " << v.Size() << std::endl
			<<"first element: " << v.GetFirst() << std::endl
			<< "last element: " << v.GetLast() << std::endl;	
	}	
	catch (Exception& e)
	{
		std::cout << e.what() << std::endl;
	}
				
	

	// List example
	std::cout << std::endl <<"List example" << std::endl << "------------" << std::endl;
	try
	{
		tContainer_t<int, std::list<int*> > l;
		int i1 = 1;
		int i2 = 2;
		int i3 = 3;
		l.Insert(&i1);
		l.Insert(&i2);
		l.Insert(&i3);	
		std::cout << l.Print();
		std::cout << "container empty ? : " << l.IsEmpty()<< std::endl
			<< "container size: " << l.Size() << std::endl
			<<"first element: " << l.GetFirst() << std::endl
			<< "last element: " << l.GetLast() << std::endl;
	}
	catch (Exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}