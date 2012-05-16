#include "stdafx.h"

void fillOrder (bool* drink,bool* firstCourse,bool* mainCourse,bool* dessert){
	int choice;
	cout<<"drink?\n";
	cin >> choice;
	*drink = (choice !=0);
	cout<<"first Course?\n";
	cin >> choice;
	*firstCourse = (choice !=0);
	cout<<"main Course?\n";
	cin >> choice;
	*mainCourse = (choice !=0);
	cout<<"dessert?\n";
	cin >> choice;
	*dessert = (choice !=0);
}

int main()
{
	restaurant* rest = new restaurant();
	int choice; 
	int finish=0; 
	int guestID;
	bool drink, firstCourse,mainCourse,dessert;
	while(!finish)
	{
		cout<<"1 new guest\n";
		cout<<"2 remove guest \n";
		cout<<"3 new order \n";
		cout<<"4 add to order \n";
		cout<<"5 remove from order \n";
		cout<<"6 list guests \n";
		cout<<"7 exit  \n\n";

		cin>>choice;

		switch(choice)
		{
		case 1: 
			{

				cout<<"enter guest id: (Positive number only) \n";
				cin>>guestID;
				if (guestID < 1){
					cout << "Positive guest ID only \n";
					break;
				}
				if (rest->addGuest(guestID) == -1) 
					cout << "Guest already exists\n\n";
				else
				{
					cout << "Added guest " << guestID << "\n\n";
				}
				break;
			}
		case 2: 
			{
				cout<<"enter guest id: \n";
				cin>>guestID;
				if (rest->removeGuest(guestID) == -1) 
					cout << "Guest doesn't exist exists\n\n";
				else
				{
					cout << "Removed guest " << guestID << "\n\n";
				}
				break;
			}
		case 3: 
			{
				cout<<"enter guest id you would like to add the new order to: \n";
				cin>>guestID;
				if (rest->addGuest(guestID) == NULL) 
					cout << "Guest doesn't exist exists\n\n";
				else
				{
					cout<<"Choose what would you like to add to the new order: 0 - for no, else - add\n";
					fillOrder(&drink, &firstCourse,&mainCourse,&dessert);
					if (rest->addOrderToGuest(guestID,drink, firstCourse,mainCourse,dessert) == -2) {
						cout << "Order already exists for this guest.\n\n";
						break;
					}
					cout << "Created Order to Guest " << guestID << ". Order is: "<<"\n" << rest->getOrderDetailes(guestID) << "\n\n";
				}
				break;
			}
		case 4: 
			{
				cout<<"enter the guest ID which has the order: \n";
				cin>>guestID;
				if (rest->addGuest(guestID) == NULL) {
					cout << "Guest doesn't exist exists\n\n";
					break;
				}
				try {
					 rest->getOrderDetailes(guestID);
				}
				catch (int e) {
						cout << "No order for this guest was created, unable to add items \n";
						break;
				}
				cout << "Current Order to Guest " << guestID << " is: "<<"\n" << rest->getOrderDetailes(guestID) << "\n";
				cout<<"Choose what would you like to add to the existing order: 0 - for no, else - add\n";
				fillOrder(&drink, &firstCourse,&mainCourse,&dessert);
				rest->addToOrder(guestID,drink, firstCourse,mainCourse,dessert);
				cout << "Added Order to Guest " << guestID << ". Order is: "<<"\n" << rest->getOrderDetailes(guestID) << "\n\n";
				
				break;
			}

		case 5: 
			{
				cout<<"enter the guest ID which has the order: \n";
				cin>>guestID;
				if (rest->addGuest(guestID) == NULL) {
					cout << "Guest doesn't exist exists\n\n";
					break;
				}
				try {
					rest->getOrderDetailes(guestID);
				}
				catch (int e) {
					cout << "No order for this guest was created, unable to add items \n";
					break;
				}
				cout << "Current Order to Guest " << guestID << " is: "<<"\n" << rest->getOrderDetailes(guestID) << "\n";
				cout<<"Choose what would you like to remove from the existing order: 0 - for no, else - add\n";
				fillOrder(&drink, &firstCourse,&mainCourse,&dessert);
				rest->RemoveFromOrder(guestID,drink, firstCourse,mainCourse,dessert);
				cout << "Removed from order to Guest " << guestID << ". Order is: "<<"\n" << rest->getOrderDetailes(guestID) << "\n\n";
				
				break;
			}

		case 6: 
			{
				cout << rest->listGuests() << "\n\n";
				break;
			}

		case 7: finish = true;							break;
		}
	}



	
}