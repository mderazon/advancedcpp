#include "stdafx.h"
#include "Parser.h"
#include "Analyzer.h"

using namespace std;
int main()
{
	ifstream ifs("program.txt" , ifstream::in);
	ofstream ofs("output.txt" , ofstream::out);
	
	Analyzer basicAnalyzer(ofs);
	Parser parser(ifs, basicAnalyzer);

	parser.Parse();
	parser.Analyze();

	ifs.close();
	ofs.close();
	return 0;
}

