#include "stdafx.h"
#include "Analyzer.h"

char const* types_[] = { "char", "short", "int", "long", "float", "double", "void"};
char const* control_[] = { "if", "else", "for" , "while", "function"};
char const* operators_[] = {"++",  "--",  "==",  "->" ,  "=",  "+",  "-",  "*",  "&",  "<<",  ">>"};
char const* modifiers_[] = {"class", "private", "public", "const", "virtual"};

std::set<std::string> reservedWords;
std::set<std::string> types;
std::set<std::string> control;
std::set<std::string> operators;
std::set<std::string> modifiers;




Analyzer::Analyzer()
{
	reservedWords.insert(std::begin(types_),std::end(types_));
	types.insert(std::begin(types_),std::end(types_));
	control.insert(std::begin(control_),std::end(control_));
	operators.insert(std::begin(operators_),std::end(operators_));
	modifiers.insert(std::begin(modifiers_),std::end(modifiers_));
}


Analyzer::~Analyzer()
{
}

