

#include "stdafx.h"

class restaurant {
	public:
		restaurant();
		~restaurant();

		int addGuest (int guestID);
		int removeGuest(int guestID);
		std::string getOrderDetailes (int guestID) const;
		int addOrderToGuest(int guestID, bool drink, bool firstCourse, bool mainCourse, bool dessert );
		int addToOrder(int orderID,bool drink,bool firstCourse, bool mainCourse, bool desert);
		int RemoveFromOrder(int orderID,bool drink,bool firstCourse, bool mainCourse, bool desert);
		std::string listGuests ();
	private:
		guest *guestARR;
		int lastArrSpace;
		int arrSize;

		int findGuest(int guestID) const;
		void renew();
		
};