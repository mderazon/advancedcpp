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
	T GetFirst();
	T GetLast();
	int Size();
	void Insert(T* element);
	std::string Print();

};

template<typename T, typename R>
std::string tContainer_t<T, R>::Print()
{
	std::ostringstream s;
	s << "[";
	for(auto it = Container.begin(); it != Container.end(); it++)
	{
		s << (**it);
	}
	return s.str();
}

template<typename T, typename R>
void tContainer_t<T, R>::Insert( T* element )
{
	Container.push_back(element);
}

template<typename T, typename R>
int tContainer_t<T, R>::Size()
{
	return R.size();
}

template<typename T, typename R>
T tContainer_t<T, R>::GetLast()
{
	//R<T*>::const_iterator it = Container.end();
	return Container.end();
}

template<typename T, typename R>
T tContainer_t<T, R>::GetFirst()
{

}

template<typename T, typename R>
bool tContainer_t<T, R>::IsEmpty()
{
	R.empty()
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
	tContainer_t<int, std::list<int*> > l;
	int i1 = 1;
	int i2 = 2;
	l.Insert(&i1);
	l.Insert(&i2);
	std::cout << l.Print();
	return 0;
}