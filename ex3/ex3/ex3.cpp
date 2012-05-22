#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
//using namespace std;
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
	int Size();
	void Insert(T* const element);
	std::string Print();

};

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
void tContainer_t<T, R>::Insert(T* const element )
{
	Container.push_back(element);
}

template<typename T, typename R>
int tContainer_t<T, R>::Size()
{
	return Container.size();
}

template<typename T, typename R>
T& tContainer_t<T, R>::GetLast() const
{
	typename R::const_iterator it = Container.end();
	//TODO add check here for empty
	it--;
	return (**it);
}

template<typename T, typename R>
T& tContainer_t<T, R>::GetFirst() const
{
	typename R::const_iterator it = Container.begin();
	return (**it);
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
				
	tContainer_t<double, std::vector<double*> > v;
	double f1 = 1.1;
	double f2 = 2.2;
	double f3 = 3.3;
	v.Insert(&f1);
	v.Insert(&f2);
	v.Insert(&f3);
	std::cout << v.Print();
	std::cout << "container empty ? : " << v.IsEmpty()<< std::endl << "container size: " << v.Size() << std::endl <<"first element: " << v.GetFirst() << std::endl << "last element: " << v.GetLast() << std::endl;	

	// List example
	std::cout << std::endl <<"List example" << std::endl << "------------" << std::endl;
	tContainer_t<int, std::list<int*> > l;
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	l.Insert(&i1);
	l.Insert(&i2);
	l.Insert(&i3);	
	std::cout << l.Print();
	std::cout << "container empty ? : " << l.IsEmpty()<< std::endl << "container size: " << l.Size() << std::endl <<"first element: " << l.GetFirst() << std::endl << "last element: " << l.GetLast() << std::endl;
	return 0;
}