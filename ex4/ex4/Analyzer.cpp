#include "stdafx.h"
#include "Analyzer.h"

char const* TYPES_[] = { "char", "short", "int", "long", "float", "double", "void"};
char const* CONTROL_[] = { "if", "else", "for" , "while", "function"};
char const* OPERATORS_[] = {"++",  "--",  "==",  "->" ,  "=",  "+",  "-",  "*",  "&",  "<<",  ">>"};
char const* MODIFIERS_[] = {"class", "private", "public", "const", "virtual"};
char const* PARENTHESES_[] = { "(", ")", "{", "}", "<", ">", "[", "]" };

std::set<std::string> RESERVD_WORDS;
std::set<std::string> TYPES(std::begin(TYPES_),std::end(TYPES_));
std::set<std::string> CONTROL(std::begin(CONTROL_),std::end(CONTROL_));
std::set<std::string> OPERATORS(std::begin(OPERATORS_),std::end(OPERATORS_));
std::set<std::string> MODIFIERS(std::begin(MODIFIERS_),std::end(MODIFIERS_));
std::set<std::string> PARENTHESES(std::begin(PARENTHESES_),std::end(PARENTHESES_));


std::ostringstream summary_output;

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


void Analyzer::Analyze( std::vector<InputLine*> &lines )
{
	std::vector<InputLine*>::iterator it = lines.begin();
	InputLine::const_iterator line_it = (*it)->begin();
	if (*line_it != "main()")
	{
		outputStream_ << "Error: program has to start with main()" << std::endl;
	}
	// main loop - iterate the whole stream, line by line
	for ( it; it != lines.end(); it++ )
	{
		int line_number = std::distance(lines.begin(), it);
		line_it = (*it)->begin();
		// iterate the line
		while (line_it != (*it)->end())
		{
			if (InSet(*line_it, TYPES))
			{
				std::string type = *line_it;
				line_it++;
				if (InSet(*line_it,RESERVD_WORDS))
				{
					outputStream_ << "Line " << line_number << ": Error - Only variable can come after type specifier" << std::endl;
					break;
				}
				summary_output << type << "	" << *line_it << std::endl;

			} 
			else
			{
			}
		}
	}
}
