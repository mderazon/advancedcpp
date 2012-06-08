#pragma once
class InputLine
{
private:
	std::string line_;
	std::vector<std::string> tokens_;
public:
	InputLine(std::string line);
	virtual ~InputLine(void);
	
	typedef std::vector<std::string>::const_iterator const_iterator;

	virtual const_iterator begin() const;
	virtual const_iterator end() const;
	
};

