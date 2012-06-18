#include "stdafx.h"
#include "FishImpl.h"

FishImpl::FishImpl(std::string type) : type_(type)
{
}
FishImpl::~FishImpl(void)
{
}

void FishImpl::pause()
{
	paused_ = true;
}

void FishImpl::play()
{
	paused_ = false;
}

std::string FishImpl::getState() const
{
	std::ostringstream s;
	if(paused_)
	{
		s << type_ << "is not swimming." << std::endl;
	}
	else
	{
		s << type_ << " is swimming " << direction_ << " at speed " << speed_ << ". Size: " <<
			size_ << " Transparency: " << transparency_ << "." << std::endl;
	}
	
	return s.str();
}

std::string FishImpl::getType() const
{
	return type_;
}


GoldFishImpl::GoldFishImpl() : FishImpl("Gold Fish")
{
	FishImpl::direction_ = "left";
	FishImpl::size_ = 1;
	FishImpl::speed_ = 1;
	FishImpl::transparency_ = 4;
	FishImpl::paused_ = false;
}
PiranhaFishImpl::PiranhaFishImpl() : FishImpl("Piranha Fish")
{
	FishImpl::direction_ = "right";
	FishImpl::size_ = 3;
	FishImpl::speed_ = 8;
	FishImpl::transparency_ = 1;
	FishImpl::paused_ = false;
}
SalmonFishImpl::SalmonFishImpl() : FishImpl("Salmon Fish")
{
	FishImpl::direction_ = "left";
	FishImpl::size_ = 6;
	FishImpl::speed_ = 5;
	FishImpl::transparency_ = 2;
	FishImpl::paused_ = false;
}

void GoldFishImpl::feed()
{
	FishImpl::transparency_++;
}
void PiranhaFishImpl::feed() { 
	FishImpl::size_++;
}
void SalmonFishImpl::feed() {
	FishImpl::speed_++;
}