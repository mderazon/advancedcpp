#pragma once
#ifndef PARSER
#define PARSER

#include "Analyzer.h"
#include "InputLine.h"
class Parser
{
private:
	std::istream& inputStream_;
	Analyzer& analyzer_;
	std::vector<InputLine*> lines_;

public:
	Parser(std::istream &inputStream, Analyzer& analyzer);
	~Parser(void);

	void Parse();
	void Analyze();

	
};

#endif