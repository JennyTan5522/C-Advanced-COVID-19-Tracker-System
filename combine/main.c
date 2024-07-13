#include "header.h"

//Visitor & staff only can access add and display function of visitor information and visit & exit
//Admin = Add, display, search, delete, report
void loginHeader(int num) {
	printf("\t\t\t\t\t     TTTTTTTTTTTTTTTTTTT                  \n");
	printf("\t\t\t\t\t  TTTTTTTTTTTTTTTTTTTTTTTTT                  \n");
	printf("\t\t\t\t\t TTTTTTTTTTTTTTTTTTTTTTTTTTTT                  \n");
	printf("\t\t\t\t\tTTTTTT                  TTTTTT      A     $$$$   &    &   C$$$$C\n");
	printf("\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT     $ $    $   $  &    &  C           \n");
	printf("\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT    $$A$$   $$R$$  &    &  C         \n");
	printf("\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT   $     $  $    $  &&&&    C$$$$CC        \n");
	printf("\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT              \n");
	printf("\t\t\t\t\t TTTTTTTTTTTT    TTTTTTTTTTTT    T A R U C    S E J A H T E R A    C O N T A C T - T R A C I N G    S Y S T E M\n");
	if (num == 1) {//lingern
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                              Admin Login Interface       \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
	else if (num == 2) {//lingern
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT                   A D M I N    S U M M A R Y    R E P O R T \n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT                              T E L : 03-4145 0278\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT         \n\n\n\n");
	}
	else if (num == 3) { // 3 = first interface
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                               T E L : 03-4145 0278         \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
	else if (num == 4) { // 4 = vincent
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                               Visitor  Interface         \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
	else if (num == 5) { // 5 = yan pin
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                                Venue  Interface         \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
	else if (num == 6) { // 6 = jenny 
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                               Entrance Interface          \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
	else if (num == 7) { //7 = cai yuan part
		printf("\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT\n");
		printf("\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT             Welcome to TarucSejahtera contact-tracing system !\n");
		printf("\t\t\t\t\t      TTTTTTTTTTTTTTTTT                         Sanitization Records Interface         \n"); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__); doubleLine(189);
	}
}


void adminLoginMenu() {
	int choice;
	do {
		system("cls");
		loginHeader(3);
		printf("\t\t\t P l e a s e   c h o o s e   o n   t h e   f i e l d   t h a t   y o u   w o u l d   l i k e   t o   p e r f o r m :\n");
		doubleLine(189);
		printf("\n\t\t\t\t\t\t\t\t\t1.\tVisitor Information  \n\t\t\t\t\t\t\t\t\t2.\tVenue Information \n\t\t\t\t\t\t\t\t\t3.\tAdministrative Staff \n\t\t\t\t\t\t\t\t\t4.\tEntrance Details \n\t\t\t\t\t\t\t\t\t5.\tSanitization Records Module \n\t\t\t\t\t\t\t\t\t6.\tLog Out \n\t\t\t\t\t\t\t\t\t7.\tExit \n\n");

		
		doubleLine(189); printf("Choice >> "); scanf("%d", &choice);
		rewind(stdin);
		switch (choice)
		{
		//	1 Visitor
		case 1:system("cls"); visitorInfoMenu(); break;
			//2 Venue
		case 2:system("cls"); menuVenue(); break;
			//3 Admin
		case 3:system("cls"); adminMenu(); break;
		case 4:// 4 Check IN Check OUT
			system("cls");	VisitAndExit(); break;
		case 5:system("cls"); sanitizationMenu(); break;//sanitization
		case 6:entryInterface(); break;
		case 7:exit(1); break;
		default:
			sound();
			printf("Invalid Choice Entered.\nPlease Try Again.\n"); system("pause");
			break;
		}
	} while (choice !=1&& choice != 2&& choice != 3 && choice != 4&& choice != 5 && choice != 6 && choice != 7);
}

void entryInterface() {
	int option;
	loginHeader(3);
	printf("\n\n\n\n\t\t\t\t\t O \t\t\t O \t\t\t O \t\t\t O \t\t\t O \n");
	printf("\t\t\t\t\t/|\\ \t\t\t/|\\ \t\t\t/|\\ \t\t\t/|\\ \t\t\t/|\\ \n");
	printf("\t\t\t\t\t/ \\ \t\t\t/ \\ \t\t\t/ \\ \t\t\t/ \\ \t\t\t/ \\ \n\n");
	printf("\t\t\t\t\t \"D i s t a n c e   m e a n s   s o   l i t t l e ,  w h e n   l i f e   m e a n s   s o   m u c h.\"\n");
	printf("\t\t\t\t\t\t\t\tSOCAL DISTANCING ---> I'LL BE THERE FOR YOU FROM 6FT AWAY\n\n\n\n\n");
	printf("\t\t\t W  E  L  C  O  M  E       T  O       T  U  N  K  U       A  B  D  U  L       R  A  H  M  A  N       U  N  I  V  E  R  S  I  T  Y       C O L L E G E\n\n\t\t\t\t\t\t\t\t\t\t B E Y O N D    E D U C A T I O N\n");
	printf("\t\t"); doubleLine(160); printf("\n\t\t\t\t\t\t\t\tH I   T H E R E,   W H O   A R E   Y O U ?\n\n\n\t\t\t\t\t\t\t\t1.\tS T U D E N T / V I S I T O R / S T A F F\n\t\t\t\t\t\t\t\t2.\tA D M I N\n\t\t\t\t\t\t\t\t3.\tE X I T\n\n");
	do {
		printf("\n\t\t\t\t   C H O I C E >> "); scanf("%d", &option); rewind(stdin);
		switch (option) {
		case 1:
			visitorMenu();
			break;
		case 2:
			adminLogin();
			break;
		case 3:
			exit(1); break;
		default:
			sound();
			printf("\n\t\t\t\t   I N V A L I D   O P T I O N  !\n");
		}
	} while (option!= 1 && option != 2 && option != 3);
	printf("\n\n\n\n\n\n\n"); system("pause");
}


void main() {
	entryInterface();
}