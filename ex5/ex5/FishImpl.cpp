#include "stdafx.h"
#include "FishImpl.h"

FishImpl::FishImpl(std::string type) : type_(type) { }
FishImpl::~FishImpl(void) { }

std::string FishImpl::getState() const
{
	// TODO complete
	return NULL;
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
}
PiranhaFishImpl::PiranhaFishImpl() : FishImpl("Piranha Fish")
{
	FishImpl::direction_ = "right";
	FishImpl::size_ = 3;
	FishImpl::speed_ = 8;
	FishImpl::transparency_ = 1;
}
SalmonFishImpl::SalmonFishImpl() : FishImpl("Salmon Fish")
{
	FishImpl::direction_ = "left";
	FishImpl::size_ = 6;
	FishImpl::speed_ = 5;
	FishImpl::transparency_ = 2;
}

std::string GoldFishImpl::feed()
{
	FishImpl::transparency_++;
	return "Gold fish has become more transparent";
}
std::string PiranhaFishImpl::feed() { 
	FishImpl::size_++;
	return "Piranha fish has become bigger";
}
std::string SalmonFishImpl::feed() {
	FishImpl::speed_++;
	return "Salmon fish has become faster";
}