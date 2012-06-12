#include "stdafx.h"
#include "Analyzer.h"

char const* TYPES_[] = { "char", "short", "int", "long", "float", "double", "void", "function"};
char const* CONTROL_[] = { "if", "else", "for" , "while"};
char const* OPERATORS_[] = {"++",  "--",  "==",  "->" ,  "=",  "+",  "-",  "*",  "&",  "<<",  ">>"};
char const* MODIFIERS_[] = {"class", "private", "public", "const", "virtual"};
char const* PARENTHESES_[] = { "(", ")", "{", "}", "<", ">", "[", "]" };

std::set<std::string> RESERVD_WORDS;
std::set<std::string> TYPES(std::begin(TYPES_),std::end(TYPES_));
std::set<std::string> CONTROL(std::begin(CONTROL_),std::end(CONTROL_));
std::set<std::string> OPERATORS(std::begin(OPERATORS_),std::end(OPERATORS_));
std::set<std::string> MODIFIERS(std::begin(MODIFIERS_),std::end(MODIFIERS_));
std::set<std::string> PARENTHESES(std::begin(PARENTHESES_),std::end(PARENTHESES_));



Analyzer::Analyzer(std::ostream &outputStream) : outputStream_(outputStream)
{
	RESERVD_WORDS.insert(std::begin(TYPES_),std::end(TYPES_));
	RESERVD_WORDS.insert(std::begin(CONTROL_),std::end(CONTROL_));
	RESERVD_WORDS.insert(std::begin(OPERATORS_),std::end(OPERATORS_));
	RESERVD_WORDS.insert(std::begin(MODIFIERS_),std::end(MODIFIERS_));
	RESERVD_WORDS.insert(std::begin(PARENTHESES_),std::end(PARENTHESES_));
}


Analyzer::~Analyzer()
{
}

bool Analyzer::IsMatchingPair( std::string p1, std::string p2 )
{
	if(p1 == "(" && p2 == ")")
		return true;
	else if(p1 == "{" && p2 == "}")
		return true;
	else if(p1 == "[" && p2 == "]")
		return true;
	else
		return false;
}


bool Analyzer::ParenthesesCheck( std::string p )
{
	if (p == "{" || p == "(" || p == "[" || p == "<")
	{
		this->pstack.push(p);
		return true;
	} 
	else
	{
		if (pstack.empty())
		{
			return false;
		}
		else if (IsMatchingPair(pstack.top(), p))
		{
			pstack.pop();
			return true;
		}
		else
		{
			return false;
		}
	}
}


bool Analyzer::InSet( std::string str, std::set<std::string>& set )
{
	const bool is_in = set.find(str) != set.end();
	return is_in;
}


bool Analyzer::Contains( pair v, std::vector<pair> variables )
{
	std::vector<pair>::const_iterator it = variables.begin();
	for (it; it != variables.end(); it++)
	{
		if (v.variable == it->variable)
		{
			return true;
		}
	}
	return false;
}


void Analyzer::PrintVariables()
{
	this->outputStream_ << "Variables summary:" << std::endl;
	std::vector<pair>::const_iterator it = variables.begin();
	for (it; it != variables.end(); it++)
	{
		this->outputStream_ << it->type << "	" << it->variable << std::endl;
	}	
}



void Analyzer::Analyze( std::vector<InputLine*> &lines )
{
	std::vector<InputLine*>::iterator it = lines.begin();
	InputLine::const_iterator line_it = (*it)->begin();
	int line_number = 1;
	// check for main()
	if ((*line_it) != "main" || *(line_it+1) != "(" || *(line_it+2) != ")")
	{
		this->outputStream_ << "Line " << line_number << ": Error - " << "Program has to start with main()" << std::endl;
	}
	it++;
	// main loop - iterate the whole stream, line by line
	for ( it; it != lines.end(); it++ )
	{		
		line_it = (*it)->begin();
		line_number++;
		// iterate a line
		bool prev_if = false;
		while (line_it != (*it)->end())
		{			
			if (InSet(*line_it, TYPES))
			{
				std::string type = *line_it;
				line_it++;
				if (InSet(*line_it, TYPES))
				{
					this->outputStream_ << "Line " << line_number << ": Error - " << *line_it << " after " << type << std::endl;
					break;
				}
				if (InSet(*line_it,RESERVD_WORDS))
				{
					this->outputStream_ << "Line " << line_number << ": Error - Only variables can follow predefined types" << std::endl;
					break;
				}
				pair v = {type, *line_it};
				if (Contains(v, variables))
				{
					this->outputStream_ << "Line " << line_number << ": Error - Variable " << v.variable << "already declared" << std::endl;
					break;
				}
				variables.push_back(v);
			} 
			else if(InSet(*line_it, PARENTHESES))
			{
				if (!ParenthesesCheck(*line_it))
				{
					this->outputStream_ << "Line " << line_number << ": Error - '}' without '{'" << std::endl;
				}
			}
			else if (*line_it == "if")
			{
				prev_if = true;
			}
			else if (*line_it == "else")
			{
				if (!prev_if)
				{
					outputStream_ << "Line " << line_number << ": Error - 'else' without 'if'" << std::endl;
				}
			}
			line_it++;
		}
	}
	PrintVariables();
}
