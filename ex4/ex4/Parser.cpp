#include "stdafx.h"
#include "Parser.h"

Parser::Parser(std::istream &inputStream, Analyzer& analyzer ) : inputStream_(inputStream), analyzer_(analyzer) {}

Parser::~Parser(void)
{
	for ( std::vector<InputLine*>::iterator it = this->lines_.begin(); 
		it != this->lines_.end(); ++it ) {
			delete * it;
	}
	this->lines_.clear();
}

void Parser::Parse()
{
	std::string line;
	while(!this->inputStream_.eof()) 
	{
		std::getline(this->inputStream_,line);
		InputLine *il = new InputLine(line);
		this->lines_.push_back(il);
	}

}
