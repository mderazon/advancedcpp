// ex5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Aquarium.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	Aquarium* aqua = &Aquarium::getInstance();
	cout << "add('Gold')" << endl;
	cout << "add('Piranha')" << endl;
	cout << "add('Salmon')" << endl;
	aqua->add("Gold");
	aqua->add("Piranha");
	aqua->add("Salmon");
	cout << aqua->debug() << endl;
	// feeding
	cout << "feed()" << endl;
	aqua->feed();
	std::cout << aqua->debug() << endl;
	// pausing
	cout << "pause()" << endl;
	aqua->pause();
	std::cout << aqua->debug() << endl;
	// playing
	cout << "play()" << endl;
	aqua->play();
	std::cout << aqua->debug() << endl;
	// removing
	cout << "remove(Piranha)" << endl;
	aqua->remove("Piranha Fish");
	std::cout << aqua->debug() << endl;
	// emptying
	cout << "empty()" << endl;
	aqua->empty();
	std::cout << aqua->debug() << endl;
}

