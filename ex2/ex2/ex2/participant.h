#pragma once
class participant
{
public:
	participant(int id, std::string name);
	~participant();

	int getId() const;
	std::string getName() const;

private:
	int id;
	std::string name;
};

