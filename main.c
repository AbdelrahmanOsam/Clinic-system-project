/******************************************************************************
* Name 	   : Abdelrahman Osam Khaled
* Date	   : 27 March , 2023
* SWC 	   : Clinic System
* Version  : 1.3
* Compiler : GNU GCC
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include"STD_TYPES.h"

#include "Clinic.h"

int main(void)
{
	while(1)
	{
		u8 Local_u8UserMode;
		printf ("Modes : \n 1- Admin mode\t2- User mode\n");
		printf ("Please enter mode : ");
		scanf("%d",&Local_u8UserMode);
		switch(Local_u8UserMode)
		{
			case ADMIN_MODE: Clinic_voidAdminMode();
			break;
			case USER_MODE: Clinic_voidUserMode();
			break;
			default: printf("Invalid input\n");
			break;
		}	
	}
	return 0;
}

