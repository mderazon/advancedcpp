#include "stdafx.h"
#include "InputLine.h"


InputLine::InputLine(std::string line) : line_(line)
{	
	std::string buf;
	std::stringstream ss(line);
	// this tokenize the string with whitespace delimiter
	while (ss >> buf)
		this->tokens_.push_back(buf);
}


InputLine::~InputLine(void) {}

InputLine::const_iterator InputLine::begin() const
{
	return(this->tokens_.begin());
}

InputLine::const_iterator InputLine::end() const
{
	return(this->tokens_.end());
}