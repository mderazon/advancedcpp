
#include "stdafx.h"


guest::guest()
{
this->id=0;
this->guestOrder = NULL;
}

guest::guest(int id)
{
	this->id=id;
	this->guestOrder = NULL;
}

guest::~guest(){
	this->removeOrder();
}

guest& guest::operator= (const guest& g)
{ 
	if(this!=&g){ 
		this->removeOrder();
		this->guestOrder= new order();
		this->id=g.getID();
		try {
			*(this->guestOrder) = g.getOrder();
		}
		catch (int e) {
			this->guestOrder = NULL;
		}

	return *this;
	}
}

void guest::setID (int id)
{
	this->id=id;
}
int guest::getID() const
{

	return this->id;
}
void guest::setOrder (const order& guestOrder)
{
	if (this->guestOrder == NULL)
	{
		this->guestOrder = new order();
	}
	*(this->guestOrder) = guestOrder;
}
order& guest::getOrder() const
{
	if (this->guestOrder == NULL)
		throw 25;
	return *(this->guestOrder);
}
void guest::removeOrder()
{
	if (! (this->guestOrder == NULL))
		delete this->guestOrder;
	this->guestOrder = NULL;
}