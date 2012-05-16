
#include "stdafx.h"

class guest {
public:
	guest();
	guest(int id);
	~guest();
	guest& operator= (const guest& p);
	void setID (int id);
	int getID() const;
	void setOrder (const order& guestOrder);
	order& getOrder() const;
	void removeOrder();

private:
	int id;
	order* guestOrder;

	

};