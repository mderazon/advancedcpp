#include <stdio.h>

class order {
public:
	order();
	order(bool drink, bool firstCourse, bool mainCourse, bool dessert);
	const order& operator= (const order& p);

	void setDrink(bool drink);
	void setFirstCourse(bool firstCourse);
	void setMainCourse(bool mainCourse);
	void setDessert(bool dessert);

	bool getDrink() const;
	bool getFirstCourse() const;
	bool getMainCourse() const;
	bool getDessert() const;

private:
	bool drink;
	bool firstCourse;
	bool mainCourse;
	bool dessert;

	
};