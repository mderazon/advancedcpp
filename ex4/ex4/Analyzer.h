#pragma once
#ifndef ANALYZER
#define ANALYZER
#include "InputLine.h"

class Analyzer
{
private:
	std::ostream& outputStream_;		// output stream of the analyzer
	std::stack<std::string> pstack;		// parentheses stack	
	struct pair							// struct to store type and variable
	{
		std::string type;
		std::string variable;
	};
	std::vector<pair> variables;		// vector to store all variables


	bool InSet(std::string str, std::set<std::string>& set);	// check if a string is in a set
	bool IsMatchingPair(std::string p1, std::string p2);		// check if open and close parentheses match
	bool ParenthesesCheck(std::string p);						// check if so far legal parentheses
	std::string Match(std::string p);								// return string that matches the parentheses
	bool Contains(pair v, std::vector<pair> variables);			// check if variables already contains some variable
	void PrintVariables();


public:
	Analyzer(std::ostream &outputStream);
	~Analyzer();

	void Analyze(std::vector<InputLine*> &lines);
};

#endif