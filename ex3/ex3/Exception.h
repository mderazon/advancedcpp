#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(std::string msg)
	{
		error = msg;
	}

	~Exception() throw() { }

	virtual const char* what() const throw()
	{
		return error.c_str();
	}
private:
	std::string error;
};