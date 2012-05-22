#pragma once

template<typename T, typename R>
class tContainer_t
{
public:
	tContainer_t(void);
	~tContainer_t(void);

	bool isEmpty();
	T getFirst();
	T getLast();
	int size();
};

private:
	