

#include "stdafx.h"


order::order() {drink = firstCourse = mainCourse = dessert = false;}
order::order(bool drink, bool firstCourse, bool mainCourse, bool dessert) {
	this->drink = drink;
	this->firstCourse = firstCourse;
	this->mainCourse = mainCourse;
	this->dessert = dessert;
}


const order& order::operator= (const order& o)
{
	this->dessert= o.dessert;
	this->mainCourse= o.mainCourse;
	this->drink= o.drink;
	this->firstCourse= o.firstCourse;

	return *this;

}

// Getters
void order::setDrink(bool drink){
	this->drink = drink;
}
void order::setFirstCourse(bool firstCourse){
	this->firstCourse = firstCourse;
}
void order::setMainCourse(bool mainCourse){
	this->mainCourse = mainCourse;
}
void order::setDessert(bool dessert){
	this->dessert = dessert;
}

//Setters
bool order::getDrink() const {
	return this->drink;
}
bool order::getFirstCourse() const{
	return this->firstCourse;
}
bool order::getMainCourse() const{
	return this->mainCourse;
}
bool order::getDessert() const{
	return this->dessert;
}
