/******************************************************************************
* Name 	   : Abdelrahman Osam Khaled
* Date	   : 27 March , 2023
* SWC 	   : Clinic System
* Version  : 1.3
* Compiler : GNU GCC
******************************************************************************/

#ifndef CLINIC_H
#define CLINIC_H

	// Macros for admin functions
void Clinic_voidAdminMode(void);

void Clinic_voidAdminOperations(u8 Copy_u8SelectedOperation);

void Clinical_voidAddNewPatient (u16 Copy_u16PatientID);

void Clinical_voidEditPatientRecord(u16 Copy_u16PatientID);

void Clinical_voidReserveSlotWithDoctor(u16 Copy_u16PatientID);


void Clinical_voidCancelReservation(u16 Copy_u16PatientID);

/********************************************************/

void Clinic_voidUserMode(void);

void Clinic_voidViewPatientRecord(u16 Copy_u16PatientID);

void Clinic_ViewTodayReservations(void);

	// Macros for modes
#define ADMIN_MODE		1
#define USER_MODE		2

#define ADMIN_PASSWORD	1234

//#define NULL   ((void*)0)


#endif