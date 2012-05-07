#include "stdafx.h"

int main()
{
	int choice;
	while(1)  {
		cout <<  "1. Add appointments." 	<< endl ;            
		cout <<  "2. Remove appointment" 	<< endl ;           
		cout <<  "3. Clean Diary. "		<< endl ;         
		cout <<  "4. Find appointment "		<< endl ;       
		cout <<  "5. Print Diary 		"<< endl ;           
		cout <<  "6. Quit." 			<< endl ;      
		cout <<  "Enter your choice:"	<< endl ;      
		
		cin >> choice ;

		switch (choice)  {
		case 1:		 
			addMeeting (…);	break; 			
		case 2:		
			rmvMeeting(…);	break;
		case 3:
			cleanDiary(…);	break;
		case 4:
			findMeeting(…);  	break;
		case 5:
			printDiary(…);     	break;
		case 6:				break;
		}		
	}

}