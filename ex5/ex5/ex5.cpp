// ex5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Aquarium.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Aquarium* aqua = &Aquarium::getInstance();
	aqua->add("Gold");
	aqua->add("Piranha");
	aqua->add("Salmon");
	aqua->feed();
}

