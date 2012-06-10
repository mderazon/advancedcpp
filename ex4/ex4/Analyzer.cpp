#include "stdafx.h"
#include "Analyzer.h"

char const* types_[] = { "char", "short", "int", "long", "float", "double", "void"};
char const* control_[] = { "if", "else", "for" , "while", "function"};
char const* operators_[] = {"++",  "--",  "==",  "->" ,  "=",  "+",  "-",  "*",  "&",  "<<",  ">>"};
char const* modifiers_[] = {"class", "private", "public", "const", "virtual"};
char const* enclosures_[] = { "(", ")", "{", "}", "<", ">", "[", "]" };

std::set<std::string> reservedWords;
std::set<std::string> types(std::begin(types_),std::end(types_));
std::set<std::string> control(std::begin(control_),std::end(control_));
std::set<std::string> operators(std::begin(operators_),std::end(operators_));
std::set<std::string> modifiers(std::begin(modifiers_),std::end(modifiers_));
std::set<std::string> enclosures(std::begin(enclosures_),std::end(enclosures_));




Analyzer::Analyzer()
{
	reservedWords.insert(std::begin(types_),std::end(types_));
	reservedWords.insert(std::begin(control_),std::end(control_));
	reservedWords.insert(std::begin(operators_),std::end(operators_));
	reservedWords.insert(std::begin(modifiers_),std::end(modifiers_));
	reservedWords.insert(std::begin(enclosures_),std::end(enclosures_));
}


Analyzer::~Analyzer()
{
}

