#include "stdafx.h"
#include "Analyzer.h"

char const* types_[] = { "char", "short", "int", "long", "float", "double", "void"};
char const* control_[] = { "if", "else", "for" , "while", "function"};
char const* operators_[] = {"++",  "--",  "==",  "->" ,  "=",  "+",  "-",  "*",  "&",  "<<",  ">>"};
char const* modifiers_[] = {"class", "private", "public", "const", "virtual"};
char const* parentheses_[] = { "(", ")", "{", "}", "<", ">", "[", "]" };

std::set<std::string> reservedWords;
std::set<std::string> types(std::begin(types_),std::end(types_));
std::set<std::string> control(std::begin(control_),std::end(control_));
std::set<std::string> operators(std::begin(operators_),std::end(operators_));
std::set<std::string> modifiers(std::begin(modifiers_),std::end(modifiers_));
std::set<std::string> parentheses(std::begin(parentheses_),std::end(parentheses_));




Analyzer::Analyzer()
{
	reservedWords.insert(std::begin(types_),std::end(types_));
	reservedWords.insert(std::begin(control_),std::end(control_));
	reservedWords.insert(std::begin(operators_),std::end(operators_));
	reservedWords.insert(std::begin(modifiers_),std::end(modifiers_));
	reservedWords.insert(std::begin(parentheses_),std::end(parentheses_));
}


Analyzer::~Analyzer()
{
}

void Analyzer::AnalyzeLine( InputLine& il )
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


