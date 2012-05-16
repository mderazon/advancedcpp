
#include "stdafx.h"


restaurant::restaurant()
{
	this->guestARR = new guest[8]; 
	this->lastArrSpace=0;
	this->arrSize=8;
}

restaurant::~restaurant()
{
	delete[] guestARR;
}

void restaurant::renew () 
{
	guest *tmp = new guest[this->arrSize+8];

	for (int i=0; i<arrSize;i++) 
	{
		tmp[i] = this->guestARR[i];
	}
	delete[] this->guestARR;
	this->guestARR = tmp;
	this->arrSize+=8;
}

int restaurant::addGuest (int guestID)
{
	if ( this->findGuest(guestID) != -1) 
		return -1;
	if (lastArrSpace ==  arrSize) 
			this->renew();

	(this->guestARR)[this->lastArrSpace++].setID(guestID);

	return 0;
	
}
int restaurant::removeGuest(int guestID)
{
	int myGuestPos = this->findGuest(guestID);
	if (myGuestPos == -1) 
	{
		return -1;
	}

	for (int j=myGuestPos ; j<lastArrSpace-1 ; j++)
		{
			this->guestARR[j] = this->guestARR[j+1];
		}
	// The next two lines are removing the last guest, as itis  duplicated in the last two places in the array. Because we chose to implement an array of guests and not *guests, we can't call the destructor, so we have to imulate it.
	this->guestARR[lastArrSpace-1].removeOrder(); 
	this->guestARR[--lastArrSpace].setID(0);
	
	return 0;
}


int restaurant::addOrderToGuest(int guestID, bool drink, bool firstCourse, bool mainCourse, bool dessert )
{
	
	int myGuestPos = this->findGuest(guestID);
	if (myGuestPos == -1) 
	{
		return -1; // no guest with this this id
	}
	try {
		this->guestARR[myGuestPos].getOrder();
	}
	catch (int e) { // we expect to get the exception, as the order does not exist
		order* myOrder = (new order(drink,firstCourse,mainCourse,dessert));
		this->guestARR[myGuestPos].setOrder(*myOrder);
		return 0;
	}
	return -2; //order already exists

	return 0;
}
int restaurant::addToOrder(int guestID,bool drink,bool firstCourse, bool mainCourse, bool dessert)
{
	int myGuestPos = this->findGuest(guestID);
	if (myGuestPos == -1) 
	{
		return -1; // no guest with this this id
	}
	try {
		this->guestARR[myGuestPos].getOrder();
	}
	catch (int e) { 
		return -2; // order hasn't been initilized, meaning no order was created;
	}

	if (guestARR[myGuestPos].getOrder().getDessert() == false ){
		guestARR[myGuestPos].getOrder().setDessert(dessert);
	}
	if (guestARR[myGuestPos].getOrder().getDrink() == false ){
		guestARR[myGuestPos].getOrder().setDrink(drink);
	}
	if (guestARR[myGuestPos].getOrder().getMainCourse() == false ){
		guestARR[myGuestPos].getOrder().setMainCourse(mainCourse);
	}
	if (guestARR[myGuestPos].getOrder().getFirstCourse() == false ){
		guestARR[myGuestPos].getOrder().setFirstCourse(firstCourse);
	}

	return 0;
}
int restaurant::RemoveFromOrder(int guestID,bool drink,bool firstCourse, bool mainCourse, bool dessert)
{
	int myGuestPos = this->findGuest(guestID);
	if (myGuestPos == -1) 
	{
		return -1; // no guest with this this id
	}
	try {
		this->guestARR[myGuestPos].getOrder();
	}
	catch (int e) { 
		return -2; // order hasn't been initilized, meaning no order was created;
	}

	if (guestARR[myGuestPos].getOrder().getDessert() == true ){
		guestARR[myGuestPos].getOrder().setDessert(!dessert);
	}
	if (guestARR[myGuestPos].getOrder().getDrink() == true ){
		guestARR[myGuestPos].getOrder().setDrink(!drink);
	}
	if (guestARR[myGuestPos].getOrder().getMainCourse() == true ){
		guestARR[myGuestPos].getOrder().setMainCourse(!mainCourse);
	}
	if (guestARR[myGuestPos].getOrder().getFirstCourse() == true ){
		guestARR[myGuestPos].getOrder().setFirstCourse(!firstCourse);
	}

	return 0;
}

std::string restaurant::listGuests () {
	std::stringstream s;
	s << "Array size: " << this->arrSize << ".\tNumber of guests: " << lastArrSpace << ".\tGuests info: \n\n";
	for (int i=0;i<lastArrSpace;i++)
	{
		s << "Guest ID: " << this->guestARR[i].getID() << ".\t Array place: " << i;
		try 
		{
			getOrderDetailes(this->guestARR[i].getID());
		}
		catch (int e)
		{
			s << ".\t Has no order.\n";
			continue;
		}
		s << ".\tOrder Details: \n\t" << getOrderDetailes(this->guestARR[i].getID()) << "\n";
	}
	return s.str();
}

int restaurant::findGuest(int guestID) const {
	for (int i=0;i<lastArrSpace;i++)
	{
		if ((this->guestARR)[i].getID() == guestID)
		{
			return i;
		}
	}

	return -1;
}

std::string restaurant::getOrderDetailes (int guestID) const
{
	int myGuestPos = this->findGuest(guestID);
	if (myGuestPos == -1) 
	{
		return NULL; //
	}
	try {
		this->guestARR[myGuestPos].getOrder();
	}
	catch (int e) { 
		throw 25; // order hasn't been initilized, meaning no order was created;
	}
	order& or = guestARR[myGuestPos].getOrder();
	//string s = "Guest ID: " + guestARR[myGuestPos].getID() + "Drink: " +  or.getDrink() + " FirstCourse: " + or.getFirstCourse() + " MainCourse: " + or.getMainCourse() + " Dessert: " + or.getDessert() + "\n";
	std::string s;
	s+="Drink: ";
	s+=or.getDrink();
	s+=" FirstCourse: ";
	s+=or.getFirstCourse();
	s+=" MainCourse: ";
	s+=or.getMainCourse();
	s+=" Dessert: ";
	s+=or.getDessert();
	s+="\n";

	return s;
	//cout<<"Guest ID: " << guestARR[myGuestPos].getID() << " Drink: " <<  or.getDrink() << " FirstCourse: " << or.getFirstCourse() << " MainCourse: " << or.getMainCourse() << " Dessert: " << or.getDessert() << "\n";
}

