#pragma once
#ifndef ANALYZER
#define ANALYZER
#include "InputLine.h"

class Analyzer
{
private:
	std::ostream& outputStream_;
	std::stack<std::string> pstack;


bool IsMatchingPair(std::string p1, std::string p2);
bool ParenthesesCheck(std::string p);
public:
	Analyzer(std::ostream &outputStream);
	~Analyzer();

	void AnalyzeLine(InputLine& il);
};

#endif