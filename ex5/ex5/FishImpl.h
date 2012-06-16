#pragma once
#ifndef FISHIMPL
#define FISHIMPL
class FishImpl
{
public:
	FishImpl(std::string type);
	~FishImpl(void);

	std::string getType() const;
	virtual std::string feed() = 0;
	std::string getState() const;

protected:
	std::string type_;
	int speed_;
	int transparency_;
	int size_;
	std::string direction_;
};

class GoldFishImpl : public FishImpl
{
public:
	GoldFishImpl();
	virtual std::string feed();
};

class PiranhaFishImpl : public FishImpl
{
public:
	PiranhaFishImpl();
	virtual std::string feed();
};

class SalmonFishImpl : public FishImpl
{
public:
	SalmonFishImpl();
	virtual std::string feed();
};

#endif