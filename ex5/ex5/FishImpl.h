#pragma once
#ifndef FISHIMPL
#define FISHIMPL

class FishImpl
{
public:
	FishImpl(std::string type);
	~FishImpl(void);

	virtual std::string getType() const;
	virtual void feed() = 0;
	virtual std::string getState() const;
	virtual void pause();
	virtual void play();
	


protected:
	std::string type_;
	int speed_;
	int transparency_;
	int size_;
	std::string direction_;
	bool paused_;
};

class GoldFishImpl : public FishImpl
{
public:
	GoldFishImpl();
	virtual void feed();
};

class PiranhaFishImpl : public FishImpl
{
public:
	PiranhaFishImpl();
	virtual void feed();
};

class SalmonFishImpl : public FishImpl
{
public:
	SalmonFishImpl();
	virtual void feed();
};

#endif