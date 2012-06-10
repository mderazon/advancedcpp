#include "stdafx.h"
#include "Parser.h"
#include "Analyzer.h"

using namespace std;
int main()
{
	ifstream ifs("program.txt" , ifstream::in);
	
	Analyzer basicAnalyzer;
	Parser parser(ifs, basicAnalyzer);
	
	ifs.close();
	return 0;
}

