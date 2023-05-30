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

struct Node
{
	u16 PatientID;
	u8 PatientName[50];
	u8 PatientAge;
	u8 PatientGender[10];
	u8 TimeSlot;

	struct Node *NextNode;
};
struct Node *HeadNode = NULL;

u8 Global_au8SlotCheck[5] = {0,0,0,0,0};


void Clinic_voidAdminMode(void)
{
	u16 Local_u8AdminPassword;
	u16 Local_u8Passwordtrails;
	u8 Local_u8PasswordCheck=0;
	for(Local_u8Passwordtrails=0;Local_u8Passwordtrails<3;Local_u8Passwordtrails++)
	{
		printf ("Please enter the Password : ");
		scanf ("%d",&Local_u8AdminPassword);
		if(Local_u8AdminPassword==ADMIN_PASSWORD)
		{
			u8 Local_u8SelectedOperation;
			printf("Correct Password\n");
			printf ("Operations :\n1-Add New Patient\t2-Edit patient record\t3-Reserve a slot with the doctor\t4-Cancel Reservation\n");
			printf ("Please select the number of wanted operation : ");
			scanf ("%d",&Local_u8SelectedOperation);
			Clinic_voidAdminOperations(Local_u8SelectedOperation);
			Local_u8PasswordCheck=1;
			break;
		}
		else
		{
			printf("Incorrect password\t");
		}
	}
	if (Local_u8PasswordCheck==0)
	{
		printf ("\n");
		printf ("Invalid password for 3 times,no more tries\n");
	}
	else
	{
		//Empty
	}
}

void Clinic_voidAdminOperations(u8 Copy_u8SelectedOperation)
{
	u16 Local_u16PatientID;
	
	switch(Copy_u8SelectedOperation)
	{
		case 1: 
				printf ("Please enter the patient ID: ");
				scanf ("%d",&Local_u16PatientID);
				Clinical_voidAddNewPatient(Local_u16PatientID);
		break;
		case 2: 
				if (HeadNode == NULL)
				{
					printf ("There is no patient records \n");
				}
				else
				{
					printf ("Please enter the patient ID: ");
					scanf ("%d",&Local_u16PatientID);
					Clinical_voidEditPatientRecord(Local_u16PatientID);
				}
		break;
		case 3:
				if (HeadNode == NULL)
				{
					printf ("There is no patient records \n");
				}
				else
				{
					printf ("Please enter the patient ID: ");
					scanf ("%d",&Local_u16PatientID);
					Clinical_voidReserveSlotWithDoctor(Local_u16PatientID);
				}
		break;
		case 4: 
				if (HeadNode == NULL)
				{
					printf ("There is no patient records \n");
				}
				else
				{
					printf ("Please enter the patient ID: ");
					scanf ("%d",&Local_u16PatientID);
					Clinical_voidCancelReservation(Local_u16PatientID);
				}
		break;
		default : printf("Invalid Choice");
		break;
	}
}


void Clinical_voidAddNewPatient (u16 Copy_u16PatientID)
{
	u8 Local_u8IDExistCheck = 0;
	struct Node *NewPatient=(struct Node *) malloc(sizeof(struct Node));
    NewPatient->NextNode = NULL;

	if (HeadNode == NULL)
	{
		NewPatient->PatientID = Copy_u16PatientID;

		printf ("Please enter new patient name : ");
		scanf ("%s",&NewPatient->PatientName);

		printf ("Please enter new patient age: ");
		scanf ("%d",&NewPatient->PatientAge);

		printf("(Male / Female) Please enter new patient gender : ");
		scanf ("%s",&NewPatient->PatientGender);

		HeadNode = NewPatient;

		printf ("New patient record is entered \n");
	}
	else
	{
        struct Node *CurrentNode;
        CurrentNode=HeadNode;
		while(CurrentNode->NextNode!=NULL)
		{
			CurrentNode=CurrentNode->NextNode;
			if(CurrentNode->PatientID == Copy_u16PatientID)
			{
				Local_u8IDExistCheck = 1;
			}
			else
			{
				//Empty
			}
		}
		if(CurrentNode->PatientID == Copy_u16PatientID)
			{
				Local_u8IDExistCheck = 1;
			}
			else
			{
				//Empty
			}
		if(Local_u8IDExistCheck == 1)
		{
			printf ("You entered exists ID , please try again\n");
		}
		else
		{
			
			CurrentNode->NextNode=NewPatient;
			NewPatient->PatientID = Copy_u16PatientID;

			printf ("Please enter the new patient name : ");
			scanf ("%s",&NewPatient->PatientName);

			printf ("Please enter the new patient age: ");
			scanf ("%d",&NewPatient->PatientAge);

			printf("(Male / Female) new enter patient gender : ");
			scanf ("%s",&NewPatient->PatientGender);
			printf ("New patient record is entered \n");
		}
	}
}
	// This is function to edit the data of exist patient
void Clinical_voidEditPatientRecord(u16 Copy_u16PatientID)
{
	struct Node *CurrentNode;
	CurrentNode = HeadNode;
	while((CurrentNode->PatientID!=Copy_u16PatientID)&&(CurrentNode->NextNode!=NULL))
	{
		CurrentNode = CurrentNode->NextNode;
	}
	if((CurrentNode->NextNode==NULL)&&(CurrentNode->PatientID!=Copy_u16PatientID))
	{
		printf("This patient ID is not exist\n");
	}
	else
	{
		printf ("Please enter the updated patient name : ");
		scanf ("%s",&CurrentNode->PatientName);
		
		printf ("Please enter the updated patient age: ");
		scanf ("%d",&CurrentNode->PatientAge);
				
		printf("(Male / Female) Please enter patient gender : ");
		scanf ("%s",&CurrentNode->PatientGender);
		
		printf("Patient record is updated\n");
	}
}

void Clinical_voidReserveSlotWithDoctor(u16 Copy_u16PatientID)
{
	u8 Local_u8Slot;
	u16 Local_u8RandomCounter;

	struct Node *CurrentNode;
	CurrentNode=HeadNode;
	while((CurrentNode->PatientID!=Copy_u16PatientID)||(CurrentNode->NextNode!=NULL))
	{
		CurrentNode = CurrentNode->NextNode;
	}
	if ((CurrentNode->NextNode == NULL) && (CurrentNode->PatientID != Copy_u16PatientID))
	{
		printf ("This patient ID is not exist\n");
	}
	else
	{
		if (Global_au8SlotCheck[0]==0)
		{
			printf("Press 1 for Slot : 2.00->2.30 \n");
		}
		if (Global_au8SlotCheck[1]==0)
		{
			printf("Press 2 for Slot : 2.30->3.00\n");
		}if (Global_au8SlotCheck[2]==0)
		{
			printf("Press 3 for Slot : 3.00->3.30\n");
		}if (Global_au8SlotCheck[3]==0)
		{
			printf("Press 4 for Slot : 4.00->4.30\n");
		}if (Global_au8SlotCheck[4]==0)
		{
			printf("press 5 for Slot : 4.30->5.00\n");
		}
		
		printf ("Please enter wanted slot from available slots:");
		scanf("%d",&Local_u8Slot);
		switch(Local_u8Slot)
		{
			case 1 :
					CurrentNode->TimeSlot = Local_u8Slot;
					Global_au8SlotCheck[0]==1;
			break;
			case 2 :
					CurrentNode->TimeSlot = Local_u8Slot;
					Global_au8SlotCheck[1]==1;
			break;
			case 3 :
					CurrentNode->TimeSlot = Local_u8Slot;
					Global_au8SlotCheck[2]==1;
			break;
			case 4 :
					CurrentNode->TimeSlot = Local_u8Slot;
					Global_au8SlotCheck[3]==1;
			break;
			case 5 :
					CurrentNode->TimeSlot = Local_u8Slot;
					Global_au8SlotCheck[4]==1;
			break;
			default :	printf("Invalid input\n");
			break;
		}
	}
	
}

Clinical_voidCancelReservation(u16 Copy_u16PatientID)
{
	struct Node *CurrentNode;
	CurrentNode=HeadNode;
	while((CurrentNode->PatientID!=Copy_u16PatientID)||(CurrentNode->NextNode!=NULL))
	{
		CurrentNode = CurrentNode->NextNode;
	}
	if ((CurrentNode->NextNode == NULL) && (CurrentNode->PatientID != Copy_u16PatientID))
	{
		printf ("This patient ID is not exist\n");
	}
	else
	{
		switch(CurrentNode->TimeSlot)
		{
			case 1 :
					Global_au8SlotCheck[0]==0;
			break;
			case 2 :
					Global_au8SlotCheck[1]==0;
			break;
			case 3 :
					Global_au8SlotCheck[2]==0;
			break;
			case 4 :
					Global_au8SlotCheck[3]==0;
			break;
			case 5 :
					Global_au8SlotCheck[4]==0;
			break;
			default :	printf("Invalid input\n");
			break;
		}
		CurrentNode->TimeSlot = 0;
	}
}
void Clinic_voidUserMode(void)
{
	u8 Local_u8SelectedOperation;
	u16 Local_u16PatientID;
	printf ("Operations :\n1-View patient record\t2-View today's reservations\n");
	printf ("Please select the number of wanted operation : ");
	scanf ("%d",&Local_u8SelectedOperation);
	switch(Local_u8SelectedOperation)
	{
		case 1:	
				if (HeadNode == NULL)
				{
					printf ("There is no patient record \n");
				}
				else
				{
					printf ("Please enter the Patient ID : ");
					scanf ("%d",&Local_u16PatientID);
					ViewPatientRecord(Local_u16PatientID);
				}
		break;
		case 2:
				if (HeadNode == NULL)
				{
					printf("There are no Patients are recorded\n");
				}
				else
				{
					Clinic_ViewTodayReservations();
				}
		break;
		default : printf ("Invalid choice\n");
		break;
	}
}

/***** Function that provide record of patient  ******/
void ViewPatientRecord(u16 Copy_u16PatientID)
{
	u16 Local_u16RandomCounter;
	struct Node *CurrentNode;
	CurrentNode=HeadNode;
	while((CurrentNode->NextNode != NULL)||(CurrentNode->PatientID!=Copy_u16PatientID))
	{
		CurrentNode=CurrentNode->NextNode;
	}
	if((CurrentNode->NextNode==NULL)&&(CurrentNode->PatientID!=Copy_u16PatientID))
	{
		printf ("This patient ID is not exist\n");
	}
	else
	{
		printf ("Patient ID : %d",CurrentNode->PatientID);
		printf ("Patient name : %s",CurrentNode->PatientName);
		printf ("Patient age : %d\n",CurrentNode->PatientAge);
		printf("Patient gender : %s",CurrentNode->PatientGender);

	}
}
void Clinic_ViewTodayReservations(void)
{
		printf ("Today's reservations : \n");
		struct Node *CurrentNode;
		CurrentNode=HeadNode;
		while(CurrentNode->NextNode != NULL)
		{
			switch(CurrentNode->TimeSlot)
			{
				case 1 :
						printf ("For ID %d : Slot 2.00->2.30\n",CurrentNode->PatientID);
				break;
				case 2 :
						printf ("For ID %d : Slot 2.30->3.00\n",CurrentNode->PatientID);
				break;
				case 3 :
						printf ("For ID %d : Slot 3.00->3.30\n",CurrentNode->PatientID);
				break;
				case 4 :
						printf ("For ID %d : Slot 4.00->4.30\n",CurrentNode->PatientID);
				break;
				case 5 :
						printf ("For ID %d : Slot 4.30->5.00\n",CurrentNode->PatientID);
				break;
				default :	//Error
				break;
			}
		}
	}
}
