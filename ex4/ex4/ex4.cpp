#include "stdafx.h"
#include "Parser.h"
#include "Analyzer.h"

using namespace std;
int main()
{
	ifstream ifs("program.txt" , ifstream::in);
	ofstream ofs("output.txt" , ifstream::out);
	
	Analyzer basicAnalyzer(ofs);
	Parser parser(ifs, basicAnalyzer);
	
	ifs.close();
	ofs.close();
	return 0;
}

