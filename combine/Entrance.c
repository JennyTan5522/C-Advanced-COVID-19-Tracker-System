#include "header.h"

void loginHeader(int num);
//For the invalid option will pop out 
void sound() {
	Beep(610, 450);
}

//Check the input whether is a digit 
bool checkIsNum(int input) {
	'0' + input;
	if (input < 0 || input>127) {
		return false; //not a number 
	}
	else return true; //Is a number

}
void VisitAndExit() {
	struct Entrance entry[50];
	bool validate = false;
	int choice;
	system("cls"); loginHeader(6);
	printf("\n\n");
	printf("\t\t     EEEEEEEEEEEEEEEE     NN             N    TTTTTTTTTTTT  RRRRRRRRR               A         NN             N     CCCCCCCCCCCCC    EEEEEEEEEEEEEEEE      \n");
	printf("\t\t     EEEEEEEEEEEEEE       NNNN           N        TTTT      RR       R             AAA        NNNN           N     C                EEEEEEEEEEEEEE\n");
	printf("\t\t     EEEEEEEEEEEE         NNNNNN         N        TTTT      RR       RR           AAAAA       NNNNNN         N     C                EEEEEEEEE\n");
	printf("\t\t     EEEEEEEE             NNNNNNNN       N        TTTT      RR       RRR         A AAAAA      NNNNNNNN       N     C                EEEE \n");
	printf("\t\t     EEEEEE               N  NNNNNNNN    N        TTTT      RRRRRRRRRRRR        A    AAAA     N  NNNNNNNN    N     C                EEE\n");
	printf("\t\t     EEEEEEEEE            N    NNNNNNNN  N        TTTT      RR       RRR       A      AAAA    N    NNNNNNNN  N     C                EEEEEEEE\n");
	printf("\t\t     EEEEEEEEEEEE         NNNNNNNNN      N        TTTT      RR       RRRR     AAAAAAAAAAAAA   N      NNNNNNNNN     C                EEEEEEEEEEEE \n");
	printf("\t\t     EEEEEEEEEEEEEEEE     N        NNNNNNN        TTTT      RR       RRRRRR  A          AAAA  N        NNNNNNN     CCCCCCCCCCCCCC   EEEEEEEEEEEEEEEEE     \n\n\n");
	printf("*********************************************************************************************************************************************************************************************\n");
	printf("\n\n\t\t\t\t\t\t\t   --------------------------------------------\n");
	printf("\t\t\t\t\t\t\t   |         VISIT AND EXIT MENU              |\n");
	printf("\t\t\t\t\t\t\t   |                                          |\n");
	printf("\t\t\t\t\t\t\t   |   ( 1 ) - DISPLAY ENTRY HISTORY          |\n");
	printf("\t\t\t\t\t\t\t   |   ( 2 ) - UPDATE VISITOR DETAILS         |\n");
	printf("\t\t\t\t\t\t\t   |   ( 3 ) - SEARCH ENTRY INFORMATION       |\n");
	printf("\t\t\t\t\t\t\t   |   ( 4 ) - DELETE ENTRY RECORD            |\n");
	printf("\t\t\t\t\t\t\t   |   ( 5 ) - ENTRY REPORT /CONCLUSION       |\n");
	printf("\t\t\t\t\t\t\t   |   ( 6 ) - EXIT WHOLE FUNCTION            |\n");
	printf("\t\t\t\t\t\t\t   |   ( 7 ) - BACK                           |\n");
	printf("\t\t\t\t\t\t\t   --------------------------------------------\n");
	do {
		do {
			printf("\n\t\t\t\t\t\t\t\t      Your option -> ");
			rewind(stdin);
			scanf("%d", &choice);
			validate = checkIsNum(choice);
			switch (choice) {
			case 1:
				displayHistoryAdmin(entry);
				break;
			case 2:
				modifyEntry(entry);
				break;
			case 3:
				searchEntry(entry);
				break;
			case 4:
				deleteEntry(entry);
				break;
			case 5:
				entranceReport(entry);
				break;
			case 6:
				exit(1); 
				break;
			case 7:
				adminLoginMenu();
				break;
			default:
				sound();

			}
		} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
	} while (validate == false);

}
//Used in every visit & exit function when user do not want to continue the function
void action() {
	printf("\n    --------------------------------------\n");
	printf("    |   What actions do you wish to ?    |\n");
	printf("    |    >> 1. Back to MENU              |\n");
	printf("    |    >> 2. EXIT                      |\n");
	printf("    --------------------------------------\n");
	printf("\tYour option (1/2) -> ");
}

//Pass the report month to the function 
void monthInEng(int mth) {
	int x = 0;
	if (mth == 1) {
		printf("JANUARY");
	}

	else if (mth == 2) {
		printf("FEBRUARY");
	}

	else if (mth == 3) {
		printf("MARCH");
	}

	else if (mth == 4) {
		printf("APRIL");
	}

	else if (mth == 5) {
		printf("MAY");
	}

	else if (mth == 6) {
		printf("JUNE");
	}

	else if (mth == 7) {
		printf("JULY");
	}

	else if (mth == 8) {
		printf("AUGUST");
	}

	else if (mth == 9) {
		printf("SEPTEMBER");
	}

	else if (mth == 10) {
		printf("OCTOBER");
	}

	else if (mth == 11) {
		printf("NOVEMBER");

	}

	else if (mth == 12) {
		printf("DECEMBER");
	}
}
//For user to choose type of entry
void typeOfEntrance(char currentUserId[]) {
	struct Entrance entry[50];
	FILE* fptr, * fp;
	char type;
	system("cls"); loginHeader(6);
	printf("\n\n");
	printf("\t\t     EEEEEEEEEEEEEEEE     NN             N    TTTTTTTTTTTT  RRRRRRRRR               A         NN             N     CCCCCCCCCCCCC    EEEEEEEEEEEEEEEE      \n");
	printf("\t\t     EEEEEEEEEEEEEE       NNNN           N        TTTT      RR       R             AAA        NNNN           N     C                EEEEEEEEEEEEEE\n");
	printf("\t\t     EEEEEEEEEEEE         NNNNNN         N        TTTT      RR       RR           AAAAA       NNNNNN         N     C                EEEEEEEEE\n");
	printf("\t\t     EEEEEEEE             NNNNNNNN       N        TTTT      RR       RRR         A AAAAA      NNNNNNNN       N     C                EEEE \n");
	printf("\t\t     EEEEEE               N  NNNNNNNN    N        TTTT      RRRRRRRRRRRR        A    AAAA     N  NNNNNNNN    N     C                EEE\n");
	printf("\t\t     EEEEEEEEE            N    NNNNNNNN  N        TTTT      RR       RRR       A      AAAA    N    NNNNNNNN  N     C                EEEEEEEE\n");
	printf("\t\t     EEEEEEEEEEEE         NNNNNNNNN      N        TTTT      RR       RRRR     AAAAAAAAAAAAA   N      NNNNNNNNN     C                EEEEEEEEEEEE \n");
	printf("\t\t     EEEEEEEEEEEEEEEE     N        NNNNNNN        TTTT      RR       RRRRRR  A          AAAA  N        NNNNNNN     CCCCCCCCCCCCCC   EEEEEEEEEEEEEEEEE     \n\n\n");
	printf("*********************************************************************************************************************************************************************************************\n");
	printf("\n\t\t\t\t\t\t\t   ===================================================\n");
	printf("\t\t\t\t\t\t\t                 CHECK-IN AND CHECK-OUT        \n");
	printf("\t\t\t\t\t\t\t   ===================================================\n");
	do {

		printf("\n\t\t\t\t\t\t                 +__________________________________+\n");
		printf("\t\t\t\t\t\t                 |                                  |\n");
		printf("\t\t\t\t\t\t                 |       -- Safe entry --           |\n");
		printf("\t\t\t\t\t\t                 |                                  |\n");
		printf("\t\t\t\t\t\t                 |  (1) - CHECK IN ('I')            |\n ");
		printf("\t\t\t\t\t\t                 |  (2) - CHECK OUT('O')            |\n ");
		printf("\t\t\t\t\t\t                 +__________________________________+\n");
		printf("\n\t\t\t\t\t\t               Please enter your entry ('I'/'O') -> ");
		rewind(stdin);
		scanf("%c", &type);
	
	switch (type) {
	case 'I':
	case 'i':
		system("cls");
		checkIn(currentUserId);
		break;
	case 'o':
	case 'O':
		system("cls");
		checkOut(currentUserId);
		break;
	default:
		sound();

	}
	} while (type != 'I' && type != 'i' && type != 'O' && type != 'o');
}


void checkIn(char currentUserId[]) {
	//venue variables
	reserve reserveV[100];

	//visitor infromation variables
	VisitorInfo display[1000];

	//entry variables
	struct Entrance entry[50];

	//variables of check-in variables ( i,j,k is store array variables )
	int   i = 0, num = 0, k = 0, j = 0, confirmCheckIn, choice, countRecord = 0, checkinCount = 0, checkoutCount = 0, inHour, inMins, venueOption, fever, breath,
		contact = 0, cough, headache, feedback, rating, runningnum = 0, found = 0, checkInDay, checkInMonth, checkInYear, option, order = 0, catChoice = 0, count = 0, validResult = 0,
		time = 0, existVenue = 0, invalidVenueId = 0, currentVisitor = 0;
	char personalId[10], reason[70], ch, confirmID, inVenueId[10], status[12], purpose[30], feed[14], rate[7], entryId[10], proceedcheckOut,intCheck[10];
 bool validate = false; //check is a digit 
	double temp;

	//Variables for venue id
	int maxVisitor = 0, venueDay, venueMonth, venueYear, venueStartTime, venueEndTime, currentVisitors;
	char venueId[10], venueCat[40], venueName[40], venueStartday[20], venueEndday[20], venueStatus[30];

	

	//read the user ID from the text file 
	FILE* displayFptr;
	displayFptr = fopen("visitor-info-database2.txt", "r");

	if (displayFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}

	//read the whole text file into an array 
	while (fscanf(displayFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &display[k].visitorUserId, &display[k].visitorIcNo, &display[k].visitorPassportNo, &display[k].visitorName, &display[k].visitorGender, &display[k].visitorBd.day, &display[k].visitorBd.month, &display[k].visitorBd.year, &display[k].visitorEmail, &display[k].visitorContactNo, &display[k].visitorAddress, &display[k].visitorAccStatus) != EOF)
	{
		if (strcmp(currentUserId, display[k].visitorUserId) == 0) {
			order = k;
		}
		k++;
	}
	//close visitor file
	fclose(displayFptr);
	
	//read data from binary file and store into array
	FILE* fptr, * fp;
	fp = fopen("VisitAndExit.bin", "rb");
	if (fp == NULL) {
		printf("Unable to open \n");
		exit(1);
	}
	
	//ensure integer I is start from 0 
	i = 0;
	//read the running number from the binary file
	while (fread(&entry[i], sizeof(struct Entrance), 1, fp) != 0) {
		//read the entry ID from the binary file
		sscanf(entry[i].entryId, "X%d", &runningnum);
		num++;
		i = num;
	}
	//close binary file
	fclose(fp);

	

	//Continue entry on for the running number 
	runningnum++;
	//print the running number 
	sprintf(entryId, "X%003d", runningnum);
	system("cls");
	loginHeader(6);

	printf("\n\t=============================\n");
	printf("\t\tCHECK-IN\n");
	printf("\t=============================\n");
	
	SYSTEMTIME t;
	GetLocalTime(&t);

	printf("\n         = [ Your entry  ID -> %s  ] =\n", entryId);
	printf("   ____________________________________________\n");
	//Get from the visitor ID
	printf("\n    Your user ID                 -> %s\n", display[order].visitorUserId);
    //copy variable into entry ID
	strcpy(personalId, display[order].visitorUserId);
	printf("\n    User Full Name               -> %s\n", display[order].visitorName);
	printf("\n    Check-in Date                -> %02d/%02d/%4d \n", t.wDay, t.wMonth, t.wYear);
	printf("\n    Check-in Time                -> %02d:%02d:%02d   \n", t.wHour, t.wMinute, t.wSecond);
	//Move into temporary varables
	checkInDay = t.wDay;
	checkInMonth = t.wMonth;
	checkInYear = t.wYear;
	inHour = t.wHour;
	inMins = t.wMinute;
	
		//Read the Venue ID
		FILE* fptrR;
		fptrR = fopen("venue.txt", "r");
		while (fscanf(fptrR, "%[^\t] %[^\t] %[^\t] %d %[^\-]-%[^\t] %d-%d	%[^\t] %d/%d/%d %d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {

			count++;
		}
		//close the venue file
		fclose(fptrR);

		//Sum up the time so it can compare with the text file
		time = t.wHour * 100 + t.wMinute;

		printf("\n    ____________________________________________________\n");
		printf("\n        VENUE ID                   VENUE NAME                \n");
		printf("   *==================================================*\n");
		printf("   |                                                  |\n");
		for (j = 0; j < count; j++) {
			//Only display the available time & no reservation place & the available current visitors less than the maximum visitors that allow to enter for user
			if (time >= v[j].timeDay.opStartTime && time <= v[j].timeDay.opEndTime&&strcmp(strupr(v[j].status), "AVAILABLE") == 0 && v[j].currentVisitors<v[j].maxVis) {
				//If got venue available for visit assign as 1
				existVenue = 1;
				printf("   |    %6s   %30s       |\n", v[j].venueID, v[j].venueName);
				

			}
		}
		//If all of  time is not available in the venue list
		if (existVenue == 0) {
			printf("   |        ---                         ---           |\n");
			printf("\n     - [ Sorry , all venue is not allow to visit ] -\n");
			//call back menu function
			profileMenu(currentUserId);
		}

		printf("   *==================================================*\n");
	
		
		do {
			printf("\n   Your check-in Venue ID        -> ");
			rewind(stdin);
			scanf("%s", &inVenueId);
			//Do-while loop is checking the current Venue ID enter is available or not 
			do {
				//Assign again or else it will be overwritten
				invalidVenueId = 0;
				for (j = 0; j < count; j++) {
					//check the venue ID is same as the venue ID provided
					if (strcmp(strupr(inVenueId), v[j].venueID) == 0 && time >= v[j].timeDay.opStartTime && time <= v[j].timeDay.opEndTime && strcmp(strupr(v[j].status), "AVAILABLE") == 0 && v[j].currentVisitors < v[j].maxVis) {
						invalidVenueId = 1;
					}
				}
				//If invlaid ID will loop 
				if (invalidVenueId == 0) {
					sound();
					printf("\n   Sorry.Invalid Venue ID        -> ");
					rewind(stdin);
					scanf("%s", &inVenueId);
				}
				//If invalid ID will loop
			} while (invalidVenueId == 0);

			//For-user double checking their venue ID
			printf("\n  * Kindly remind that cannot change the venue after you have check-in  *\n");
			printf("  >> Are you confirm your venue ID ? ('Y'/'N') -> ");
			rewind(stdin);
			scanf("%c", &confirmID);
			ch = toupper(confirmID);
			while (ch != 'Y' && ch != 'N') {
				sound();
				printf(" Invalid option. Please enter again       -> ");
				rewind(stdin);
				scanf("%c", &confirmID);
				ch = toupper(confirmID);
			}
		} while (ch == 'N');
		
		if (toupper(ch) == 'Y') {
			printf("\n   Temperature                    -> ");
			scanf("%lf", &temp);
			while (temp < 36 || temp>40) {
				sound();
				printf("  Invalid temperature range. Please enter temperature again ->");
				scanf("%lf", &temp);
			}
			if (temp >= 36 && temp <= 36.9) {
				printf("  -[ Normal temperature ]-\n");
				strcpy(status, "LOW");
			}
			else if (temp >= 37 && temp <= 40) {
				sound();
				printf("  -[ Abnormal temperature . You're not allow to enter ]-\n");
				profileMenu(currentUserId);
				//call function to menu
			}
			printf("\n   Entry purpose (XXX to PROFILE) -> ");
			rewind(stdin);
			scanf("%[^\n]", &purpose);

			if (strcmp(strupr(purpose), "XXX") == 0) {
				system("cls");
				profileMenu(currentUserId);
			}
			//Ensure the user no experience the covid-19 sysmptoms
			printf("\n   --------------------------------------------------------------------------\n");
			printf("   Are you currently experiencing any of these symptoms ? ('1'-Yes / '0'-NO)\n ");
			
				printf("   (1) - Fever and /or chills ?   ->");
				rewind(stdin);
				scanf("%d", &fever);
				
				while (fever != 1 && fever != 0) {
					sound();
					printf("    Invalid option.Enter again     ->");
					rewind(stdin);
					scanf("%d", &fever);
				}

			
				printf("\n    (2) - Cough or croup ?         ->");
				rewind(stdin);
				scanf("%d", &cough);

			 while (cough != 1 && cough != 0) {
				 sound();
				 printf("    Invalid option.Enter again     ->");
				 rewind(stdin);
				 scanf("%d", &cough);
			}

				printf("\n    (3) - Shortness of breath ?    ->");
				rewind(stdin);
				scanf("%d", &breath);

				while (breath != 1 && breath != 0) {
					sound();
					printf("    Invalid option.Enter again     ->");
					rewind(stdin);
					scanf("%d", &breath);
			 }

			
				printf("\n    (4) - Headache ?               ->");
				rewind(stdin);
				scanf("%d", &headache);

				while (headache != 1 && headache != 0) {
					sound();
					printf("    Invalid option.Enter again     ->");
					rewind(stdin);
					scanf("%d", &headache);
			}

			printf("   --------------------------------------------------------------------------\n");

			if (fever == 1 || cough == 1 || breath == 1 || headache == 1) {
				do {
					printf("\n   In the last 14 days , have you been close contact of someone who currently has COVID-19 ?('1'-Yes /'0'-NO) ->");
					rewind(stdin);
					scanf("%d", &contact);
				} while (contact != 1 && contact != 0);


				if (contact == 1) {
					sound();
					printf("\n  -[ Current status : HIGH RISK -> You're not allowed to enter ]- \n");
					printf("\n   ==================================================================\n");
					printf("    *  \t\t YOU SHOULD :                                       *\n");
					printf("    * (1) - Contact the school to let them know .                   *\n");
					printf("    * (2) - You and your entire household MUST ISOLATE for 14 days. *\n");
					printf("   ==================================================================\n");
					contact = 1;
					//Not allow to enter  
					strcpy(status, "HIGH");
					profileMenu(currentUserId);
				}
				else { //If no close contact with covid-19 people
					printf("\n  -[ Current status : MODERATE RISK ->");
					printf("    Please take care and you're allowed to enter ]-\n");
					strcpy(status, "MODERATE");
					contact = 0;
				}
			}
			else {
				printf("\n     -[ Your current status : LOW RISK -> You're allowed to enter ]- \n");
				strcpy(status, "LOW");
				contact = 0;
			}
			printf("\n  *****************************************");
			printf("\n  |\t  -YOUR CHECK-IN DETAILS -        |\n");
			printf("  |                                       |\n");
			printf("  |  Entry ID       ->   %-6s           |\n", entryId);
			printf("  |  Personal ID    ->   %-6s           |\n", personalId);
			printf("  |  Venue ID       ->   %-6s           |\n", inVenueId);
			printf("  |  Date entry     ->   %-02d/%02d/%4d       |\n", checkInDay, checkInMonth, checkInYear);
			printf("  |  Time entry     ->   %-2d:%2d            |\n", inHour, inMins);
			printf("  |  Temperature    ->   %-7.2lf          |\n", temp);
			printf("  |  Purpose        ->   %-14s   |\n", purpose);
			printf("  |  Current Risk   ->   %-10s       |\n", status);
			printf("  *****************************************\n");

			printf("\n  ---------------------------------------------------\n");
			printf("  |          Are you sure to check-in  ?            |\n");
			printf("  |             ( 1 ) - Yes                         |\n");
			printf("  |             ( 2 ) - No                          |\n");
			printf("  ---------------------------------------------------\n");
			do {
				printf(" \tYour option ('1'/'2') -> ");
				rewind(stdin);
				scanf("%d", &confirmCheckIn);
				validate = checkIsNum(confirmCheckIn);
			} while (validate == false);
			while (confirmCheckIn != 1 && confirmCheckIn != 2) {
				sound();
				printf("\nInvalid action.Please enter again -> ");
				rewind(stdin);
				scanf("%d", &confirmCheckIn);
			}
			if (confirmCheckIn == 1) {
                //Move all variables into array variables
				strcpy(entry[i].entryId, entryId);
				strcpy(entry[i].in.id, personalId);
				strcpy(entry[i].in.venueId, inVenueId);
				strcpy(entry[i].in.purpose, purpose);
				entry[i].symptoms.contact = contact;
				entry[i].in.symptoms.breath = breath;
				entry[i].in.symptoms.fever = fever;
				entry[i].in.symptoms.headache = headache;
				entry[i].in.symptoms.cough = cough;
				strcpy(entry[i].in.risk, status);
				entry[i].in.temp = temp;
				entry[i].in.checkInHours = inHour;
				entry[i].in.checkInMinutes = inMins;
				entry[i].in.checkInDay = checkInDay;
				entry[i].in.checkInMonth = checkInMonth;
				entry[i].in.checkInYear = checkInYear;
				//the system will automatically help them to check out if the user no check out 
				entry[i].out.outHour = 23;
				entry[i].out.outMins = 59;
				entry[i].out.totalMins = (entry[i].out.outHour - entry[i].in.checkInHours) * 60 + entry[i].out.outMins - entry[i].in.checkInMinutes;
				strcpy(entry[i].out.feed, "--");
				strcpy(entry[i].out.rate, "--");
				printf("\n  -[ You have successfully check in  on %d:%d ! ]-\n", inHour, inMins);
				FILE* fptr;
				//Append check-in records into the file
				fptr = fopen("VisitAndExit.bin", "ab");
				if (fptr == NULL) {
					printf("Unable to open\n");
					exit(1);
				}
				fwrite(&entry[i], sizeof(struct Entrance), 1, fptr);

				fclose(fptr);
					for (j = 0; j < count; j++) {
						//Check the condition whether the venue id , time , reservation and current visitors is available
						if (strcmp(strupr(inVenueId), v[j].venueID) == 0 && time >= v[j].timeDay.opStartTime && time <= v[j].timeDay.opEndTime && strcmp(strupr(v[j].status), "AVAILABLE") == 0 && v[j].currentVisitors < v[j].maxVis) {
							//Move all the venue variables into the temporary variables
							strcpy(venueId, v[j].venueID);
							strcpy(venueCat, v[j].venueCat);
							strcpy(venueName, v[j].venueName);
							maxVisitor = v[j].maxVis;
							strcpy(venueStartday, v[j].timeDay.day.opStartDay);
							strcpy(venueEndday, v[j].timeDay.day.opStartDay);
							venueStartTime = v[j].timeDay.opStartTime;
							venueEndTime = v[j].timeDay.opEndTime;
							strcpy(venueStatus, v[j].status);
							venueDay = v[j].saniTime.saniYear;
							venueMonth = v[j].saniTime.saniMonth;
							venueYear = v[j].saniTime.saniYear;
							currentVisitors = v[j].currentVisitors;

							//Write all into text fie
							FILE* venueFile;
							venueFile = fopen("venue.txt", "w");
							if (venueFile == NULL) {
								printf("Unable to open\n");
								exit(1);
							}
							//Move temporary variables into venue array
							strcpy(v[j].venueID, venueId);
							strcpy(v[j].venueCat, venueCat);
							strcpy(v[j].venueName, venueName);
							v[j].maxVis = maxVisitor;
							strcpy(v[j].timeDay.day.opStartDay, venueStartday);
							strcpy(v[j].timeDay.day.opStartDay, venueEndday);
							v[j].timeDay.opStartTime = venueStartTime;
							v[j].timeDay.opEndTime = venueEndTime;
							strcpy(v[j].status, venueStatus);
							v[j].saniTime.saniYear = venueDay;
							v[j].saniTime.saniMonth = venueMonth;
							v[j].saniTime.saniYear = venueYear;
							//entry current visitors into the text file
							v[j].currentVisitors = currentVisitors + 1;
							for (j = 0; j < count; j++) {
								fprintf(venueFile, "%s\t%s\t%s\t%d\t%s-%s\t%.4d-%.4d\t%s\t%d/%d/%d\t%d\n", v[j].venueID, v[j].venueCat, v[j].venueName, v[j].maxVis, v[j].timeDay.day.opStartDay, v[j].timeDay.day.opEndDay, v[j].timeDay.opStartTime, v[j].timeDay.opEndTime, v[j].status, v[j].saniTime.saniYear, v[j].saniTime.saniMonth, v[j].saniTime.saniDay, v[j].currentVisitors);
							}
							fclose(venueFile);
						}
					}
				
			}
		}

	else if (confirmCheckIn == 2) {
		do {
			do {
				action();
				rewind(stdin);
				scanf("%d", &choice);
				validate = checkIsNum(choice);
				switch (choice) {
				case 1:
					profileMenu(currentUserId);
					break;
				case 2:
					exit(0);
				}
			} while (choice != 1 && choice != 2);
		} while (validate == false);

		system("cls");

	}

	printf("\n    Do you want to check-out ? ('Y'-yes ,'N' -No ) -> ");
	rewind(stdin);
	scanf("%c", &proceedcheckOut);
	while (proceedcheckOut != 'Y' && proceedcheckOut != 'y' && proceedcheckOut == 'N' && proceedcheckOut == 'n') {
		sound();
		printf("       Invalid option. Please enter again -> ");
		rewind(stdin);
		scanf("%c", &proceedcheckOut);
	}
	if (proceedcheckOut == 'Y' || proceedcheckOut == 'y') {
		system("cls");
		checkOut(currentUserId);
	}
	else if (proceedcheckOut == 'N' || proceedcheckOut == 'n') {
		do {
			//call from action
			action();
			rewind(stdin);
			scanf("%d", &option);
			validate = checkIsNum(option);
			switch (option) {
			case 1:
				profileMenu(currentUserId);
				break;
			case 2:
				exit(0);
			}
		} while (option != 1 && option != 2);
	} while (validate == false);
}

void checkOut(char currentUserId[]) {
	loginHeader(6);
	//visitor information variables
	VisitorInfo display[1000];
	//Entry variables
	struct Entrance entry[50];
	int i = 0, k = 0, num = 0, choice, confirmCheckout, inHour, inMins, fever, breath, contact = 0, cough, headache, feedback, rating,  checkInDay, checkInMonth, checkInYear, quit, option, order = 0,
		outHour, outMins, totalDuration, count = 0, j = 0, time = 0, existVenue = 0, invalidEntryId = 0, existCheckInID = 0, foundEntryId = 0;
	char personalId[10], reason[70], record, confirmID, ch, type, status[12], purpose[30], feed[14], rate[7], entryId[10], proceedcheckIn, outVenueId[10];
	double temp;
	bool validate = false;
	//Variables for venue id
	int maxVisitor = 0, venueDay, venueMonth, venueYear, venueStartTime, venueEndTime, currentVisitors;
	char venueId[10], venueCat[40], venueName[40], venueStartday[20], venueEndday[20], venueStatus[30];
	//read the user ID from the text file 
	FILE* displayFptr;
	displayFptr = fopen("visitor-info-database2.txt", "r");

	if (displayFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}

	//read the whole text file into an array 
	while (fscanf(displayFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &display[k].visitorUserId, &display[k].visitorIcNo, &display[k].visitorPassportNo, &display[k].visitorName, &display[k].visitorGender, &display[k].visitorBd.day, &display[k].visitorBd.month, &display[k].visitorBd.year, &display[k].visitorEmail, &display[k].visitorContactNo, &display[k].visitorAddress, &display[k].visitorAccStatus) != EOF)
	{
		if (strcmp(currentUserId, display[k].visitorUserId) == 0) {
			order = k;
		}
		k++;
	}

	fclose(displayFptr);

	i = 0;
	//read from binary file and store into array
	FILE* fptr, * fp;
	fp = fopen("VisitAndExit.bin", "rb");
	if (fp == NULL) {
		printf("Unable to open \n");
		exit(1);
	}
	while (fread(&entry[i], sizeof(struct Entrance), 1, fp) != 0) {
		num++;
		i = num;

	}
	fclose(fp);
	
	strcpy(personalId, display[order].visitorUserId);  //Copy variables into Personal ID
	FILE* venueFile;
	venueFile = fopen("venue.txt", "r");
	if (venueFile == NULL) {
		printf("Unable to open \n");
		exit(0);
	}
	while (fscanf(venueFile, "%[^\t] %[^\t] %[^\t] %d %[^\-]-%[^\t] %d-%d	%[^\t] %d/%d/%d %d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {

		count++;
	}
	fclose(venueFile);

	SYSTEMTIME t;
	GetLocalTime(&t);

	for (i = 0; i < num; i++) {
		//23:59 make sure is no check-out before and compare the date of check-in only today
		if (strcmp(personalId, entry[i].in.id) == 0 && entry[i].out.outHour == 23 && entry[i].out.outMins == 59&&entry[i].in.checkInDay==t.wDay) {
			foundEntryId = 1;
			//Show for user see the current records
			printf("\n  *****************************************");
			printf("\n  |\t  -YOUR CHECK-IN DETAILS -        |\n");
			printf("  |                                       |\n");
			printf("  |  Entry ID       ->   %-6s           |\n", entry[i].entryId);
			printf("  |  Personal ID    ->   %-6s           |\n", entry[i].in.id);
			printf("  |  Venue ID       ->   %-6s           |\n", entry[i].in.venueId);
			printf("  |  Date entry     ->   %-02d/%02d/%4d       |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
			printf("  |  Time entry     ->   %-2d:%2d            |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
			printf("  *****************************************\n");
		}
		//If no entry ID existing 
	}if (foundEntryId == 0) {
		sound();
				printf("\n  -[ Sorry .No check-in record(s) existing / All places have been check-out before ]- \n");
				do {
					//call from action
					action();
					rewind(stdin);
					scanf("%d", &quit);
					validate = checkIsNum(quit);
					switch (quit) {
					case 1:
						profileMenu(currentUserId);
						break;
					case 2:
						exit(0);
					}
				} while (quit != 1 && quit != 2);
	}
	       	printf("\n   Kindly enter your entry ID where you want to check-out  -> ");
	        rewind(stdin);
	        scanf("%s", &entryId);
	do {
		//Assign again or else it will be overwritten
		invalidEntryId = 0;
		//check the entry ID , time do not chekc-out before 
		for (i = 0; i < num; i++) {
			if (strcmp(strupr(entryId), entry[i].entryId) == 0 && entry[i].out.outHour == 23 && entry[i].out.outMins == 59) {
				//If the ID founded
				invalidEntryId = 1;
				strcpy(entryId, entry[i].entryId);
				strcpy(personalId, entry[i].in.id);
				strcpy(outVenueId, entry[i].in.venueId);
				strcpy(status, entry[i].in.risk);
				strcpy(purpose, entry[i].in.purpose);
				breath = entry[i].in.symptoms.breath;
				fever = entry[i].in.symptoms.fever;
				headache = entry[i].in.symptoms.headache;
				strcpy(status, entry[i].in.risk);
				temp = entry[i].in.temp;
				inHour = entry[i].in.checkInHours;
				inMins = entry[i].in.checkInMinutes;
				checkInDay = entry[i].in.checkInDay;
				checkInMonth = entry[i].in.checkInMonth;
				checkInYear = entry[i].in.checkInYear;
				totalDuration = entry[i].out.totalMins;
				printf("\n  \t=============================\n");
				printf("\t\t  CHECK-OUT\n");
				printf("\t=============================\n");
				printf("\n    -----------------------------------------------------------\n");
				printf("    |    Feedback of the Standard Operating Procedure (SOP)   |\n");
				printf("    |       ( 1 ) - Excellence                                |\n");
				printf("    |       ( 2 ) - Good                                      |\n");
				printf("    |       ( 3 ) - Bad                                       |\n");
				printf("    -----------------------------------------------------------\n");
				do {
					do {
						printf("        Your option -> ");
						rewind(stdin);
						scanf("%d", &feedback);
						validate = checkIsNum(feedback);

					} while (validate == false);

				} while (feedback != 1 && feedback != 2 && feedback != 3);
				//copy the word
				if (feedback == 1) {
					strcpy(feed, "Excellence");
				}
				else if (feedback == 2) {
					strcpy(feed, "Good");
				}
				else if (feedback == 3) {
					strcpy(feed, "Bad");
				}
				do {
					do {
						printf("\n\n     Rating of MySejahtera '*'-> STAR\n");
						printf("      -----------------------\n");
						printf("       -[  1  - *        ]-\n ");
						printf("      -[  2  - **       ]-\n ");
						printf("      -[  3  - ***      ]-\n ");
						printf("      -[  4  - ****     ]-\n ");
						printf("      -[  5  - *****    ]-\n ");
						printf("     -----------------------\n");
						printf("      Your rating >> ");
						rewind(stdin);
						scanf("%d", &rating);
						validate = checkIsNum(rating);
					} while (rating != 1 && rating != 2 && rating != 3 && rating != 4 && rating != 1 && rating != 5);
				} while (validate == false);
				if (rating == 1) {
					strcpy(rate, "*");

				}
				else if (rating == 2) {
					strcpy(rate, "**");
				}
				else if (rating == 3) {
					strcpy(rate, "***");
				}
				else if (rating == 4) {
					strcpy(rate, "****");
				}
				else {
					strcpy(rate, "*****");
				}
				do {
					do {
						printf("\n  Do you want to check-out ('1'- YES '2' - No ) ? -> ");
						rewind(stdin);
						scanf("%d", &confirmCheckout);
						validate = checkIsNum(confirmCheckout);
					} while (confirmCheckout != 1 && confirmCheckout != 2);
				} while (validate == false);
				//Automatically get user check out time from the system
				SYSTEMTIME t;
				GetLocalTime(&t);
				//Get exit time from system
				outHour = t.wHour;
				outMins = t.wMinute;
				totalDuration = ((outHour - inHour) * 60) + (outMins - inMins);

				if (confirmCheckout == 1) {
					//Move the temporary variables into array
					GetLocalTime(&t);
					strcpy(entry[i].entryId, entryId);
					strcpy(entry[i].in.id, personalId);
					strcpy(entry[i].in.venueId, outVenueId);
					strcpy(entry[i].in.risk, status);
					strcpy(entry[i].in.purpose, purpose);
					entry[i].in.symptoms.breath = breath;
					entry[i].in.symptoms.fever = fever;
					entry[i].in.symptoms.headache = headache;
					strcpy(entry[i].in.risk, status);
					entry[i].in.temp = temp;
					entry[i].in.checkInHours = inHour;
					entry[i].in.checkInMinutes = inMins;
					entry[i].in.checkInDay = checkInDay;
					entry[i].in.checkInMonth = checkInMonth;
					entry[i].in.checkInYear = checkInYear;
					//check-out time get from the system
					strcpy(entry[i].out.rate, rate);
					strcpy(entry[i].out.feed, feed);
					entry[i].out.outHour = outHour;
					entry[i].out.outMins = outMins;
					entry[i].out.totalMins = totalDuration;
					printf("\n-[ You have successfully check out  on %d:%d ! ]-\n", outHour, outMins);
					printf("\n  Total duration of time visited                    ->  %d minutes \n", totalDuration);
					//write into the file
					fptr = fopen("VisitAndExit.bin", "wb");
					if (fptr == NULL) {
						printf("Unable to open\n");
						exit(1);
					}
					for (i = 0; i < num; i++) {
						fwrite(&entry[i], sizeof(struct Entrance), 1, fptr);
					}
					fclose(fptr);

					for (j = 0; j < count; j++) {
						if (strcmp(strupr(v[j].venueID), strupr(outVenueId)) == 0) {
							//Move all the venue variables into the temporary variables
							strcpy(venueId, v[j].venueID);
							strcpy(venueCat, v[j].venueCat);
							strcpy(venueName, v[j].venueName);
							maxVisitor = v[j].maxVis;
							strcpy(venueStartday, v[j].timeDay.day.opStartDay);
							strcpy(venueEndday, v[j].timeDay.day.opStartDay);
							venueStartTime = v[j].timeDay.opStartTime;
							venueEndTime = v[j].timeDay.opEndTime;
							strcpy(venueStatus, v[j].status);
							venueDay = v[j].saniTime.saniYear;
							venueMonth = v[j].saniTime.saniMonth;
							venueYear = v[j].saniTime.saniYear;
							currentVisitors = v[j].currentVisitors;

							//Write all into text fie
							FILE* venueFile;
							venueFile = fopen("venue.txt", "w");
							if (venueFile == NULL) {
								printf("Unable to open\n");
								exit(1);
							}
							//Move temporary variables into venue array
							strcpy(v[j].venueID, venueId);
							strcpy(v[j].venueCat, venueCat);
							strcpy(v[j].venueName, venueName);
							v[j].maxVis = maxVisitor;
							strcpy(v[j].timeDay.day.opStartDay, venueStartday);
							strcpy(v[j].timeDay.day.opStartDay, venueEndday);
							v[j].timeDay.opStartTime = venueStartTime;
							v[j].timeDay.opEndTime = venueEndTime;
							strcpy(v[j].status, venueStatus);
							v[j].saniTime.saniYear = venueDay;
							v[j].saniTime.saniMonth = venueMonth;
							v[j].saniTime.saniYear = venueYear;
							//Delete one current visitors into the text file
							v[j].currentVisitors = currentVisitors - 1;
							for (j = 0; j < count; j++) {
								fprintf(venueFile, "%s\t%s\t%s\t%d\t%s-%s\t%.4d-%.4d\t%s\t%d/%d/%d\t%d\n", v[j].venueID, v[j].venueCat, v[j].venueName, v[j].maxVis, v[j].timeDay.day.opStartDay, v[j].timeDay.day.opEndDay, v[j].timeDay.opStartTime, v[j].timeDay.opEndTime, v[j].status, v[j].saniTime.saniYear, v[j].saniTime.saniMonth, v[j].saniTime.saniDay, v[j].currentVisitors);
							}
							fclose(venueFile);
						}
					}
					//Ask the user want to check in for another place after check out
					printf("\n  Do you want to check-in for another place ? ('Y'-yes ,'N' -No ) -> ");
					rewind(stdin);
					scanf("%c", &proceedcheckIn);
					while (proceedcheckIn != 'Y' && proceedcheckIn != 'y' && proceedcheckIn == 'N' && proceedcheckIn == 'n') {
						sound();
						printf("  Invalid option. Please enter again -> ");
						rewind(stdin);
						scanf("%c", &proceedcheckIn);
					}
					if (proceedcheckIn == 'Y' || proceedcheckIn == 'y') {
						//if want to check-in call to check-in function
						checkIn(currentUserId);
					}
					else if (proceedcheckIn == 'N' || proceedcheckIn == 'n') {
						do {
							//call from action
							action();
							rewind(stdin);
							scanf("%d", &option);
							validate = checkIsNum(option);
							switch (option) {
							case 1:
								system("cls");
								profileMenu(currentUserId);
								break;
							case 2:
								exit(0);
							}
						} while (option != 1 && option != 2);
					} while (validate == false);

				}
				else if (confirmCheckout == 2) {
					do {
						do {
							//call from action
							action();
							rewind(stdin);
							scanf("%d", &confirmCheckout);
							validate = checkIsNum(confirmCheckout);
						} while (confirmCheckout != 1 && confirmCheckout != 2);
					} while (validate == false);

					system("cls"); loginHeader(6);
					switch (confirmCheckout) {
					case 1:
						system("cls"); loginHeader(6);
						profileMenu(currentUserId);
						break;
					case 2:
						exit(0);
					}
				}
			}
		}

		//If invlaid ID will loop 
		if (invalidEntryId == 0) {
			sound();
			printf("\n   Sorry.Invalid Entry ID where you want to check-out      -> ");
			rewind(stdin);
			scanf("%s", &entryId);
		}
		//If invalid ID will loop
	} while (invalidEntryId == 0);



}

//Visitor Site only can dsiplay his/her's own history details
void displayHistoryVisitor(char currentUserId[], struct Entrance entry[50]) {
	system("cls");
	VisitorInfo display[1000];
	int order = 0, i = 0, count = 0, k = 0, found = 0, proceed = 0;
	//read the user ID from the text file 
	FILE* displayFptr;
	displayFptr = fopen("visitor-info-database2.txt", "r");

	if (displayFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}
	//read the whole text file into an array 
	while (fscanf(displayFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &display[k].visitorUserId, &display[k].visitorIcNo, &display[k].visitorPassportNo, &display[k].visitorName, &display[k].visitorGender, &display[k].visitorBd.day, &display[k].visitorBd.month, &display[k].visitorBd.year, &display[k].visitorEmail, &display[k].visitorContactNo, &display[k].visitorAddress, &display[k].visitorAccStatus) != EOF)
	{
		//check the current user
		if (strcmp(currentUserId, display[k].visitorUserId) == 0) {
			order = k;
		}
		k++;
	}
	fclose(displayFptr);

	//read from binary file
	FILE* fptr;
	fptr = fopen("VisitAndExit.bin", "rb");
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}
	//Show all entry records
	printf("\n\n\t\t\t\t\t          ==========================================================\n");
	printf("\t\t\t\t\t          |           YOUR CHECK-IN AND CHECK-OUT HISTORY          |\n");
	printf("\t\t\t\t\t          ==========================================================\n");
	printf("\n\t     *----------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
	printf("\t     | Entry ID   |  Venue ID |    Date    | Time entry | Temperatue('c)|       Purpose    | Current risk | Time exit | Duration visit  |Feedback of SOP |   Rating   |\n");
	printf("\t     *----------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
	while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
		//Filter for the current user ID
		if (strcmp(currentUserId, entry[i].in.id) == 0) {
			found = 1;
			count++;
			printf("\t#%02d- | %6s     |  %5s    | %4d/%02d/%02d | %5d:%2d   |  %7.2lf      | %16s |  %10s  |", count, entry[i].entryId,  entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].in.temp, entry[i].in.purpose, entry[i].in.risk);
			printf("%4d:%2d    |   %03d minutes   |%11s     | %7s    |\n", entry[i].out.outHour, entry[i].out.outMins, entry[i].out.totalMins, entry[i].out.feed, entry[i].out.rate);
		}

	}
	printf("\t     *----------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
	printf("\t\t\t\t\t\t\t                                                                                          -[ Total %d places check-in ]-            ",count);
	fclose(fptr);
	//If no check-in ID existing
	if (found == 0) {
		printf("     -[ No record check-in before ]-\n");
	}

	do {
		action();
		rewind(stdin);
		scanf("%d", &proceed);

		switch (proceed) {
		case 1:
			system("cls"); loginHeader(6);
			profileMenu(currentUserId);
			break;
		case 2:
			exit(0);
		default:
			printf("\n>> Invalid option\n");
			sound();
		}
	} while (proceed != 1 && proceed != 2);
}
	




//Admin display site 
void displayHistoryAdmin(struct Entrance entry[50]) {
	int type, count = 0, i = 0, num = 0, field, date, time, temp, feedback, skip = 0, proceed;
	bool skipDate = true, skipTime = true, skipTemp = true, skipFeedback = true, validate = false;
	char continueDisplay;
	do {
		FILE* fptr;
		fptr = fopen("VisitAndExit.bin", "rb");
		if (fptr == NULL) {
			printf("Unable to open");
			exit(1);
		}


		system("cls"); loginHeader(6);

		do {
			do {
				printf("\n\t\t\t\t\t\t     ========================================\n");
				printf("\t\t\t\t\t\t     |         DISPLAY ENRTY HISTORY        |\n");
				printf("\t\t\t\t\t\t     ========================================\n");
				//Filter delete data and current data
				printf("\n\t\t\t\t\t      ---------------------------------------------------------\n");
				printf("\t\t\t\t\t      | Do you want to display delete info or current info ?  |\n");
				printf("\t\t\t\t\t      |  ( 1 )   ->   Delete info                             |\n");
				printf("\t\t\t\t\t      |  ( 2 )   ->   Current info                            |\n");
				printf("\t\t\t\t\t      ---------------------------------------------------------\n");
				printf("\n\t\t\t\t\t\t   Your option -> ");
				rewind(stdin);
				scanf("%d", &type);
				validate = checkIsNum(type);
			} while (validate == false);
		} while (type != 1 && type != 2);

		if (type == 1) {
			FILE* fr;
			fr = fopen("backup.txt", "r");
			if (fr == NULL) {
				printf("Unable to open");
				exit(1);
			}
			system("cls");
			loginHeader(6);
			//Display deleted records
			printf("\n\t\t\t\t\t\t\t           ==========================================\n");
			printf("\t\t\t\t\t\t\t                     DISPLAY DELETED  HISTORY \n");
			printf("\t\t\t\t\t\t\t           ==========================================\n");
			printf("\n\t\t  *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
			printf("\t\t  | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry | Temperatue('c)|       Purpose    | Current risk | Time exit | Duration visit  |Feedback of SOP |   Rating   |\n");
			printf("\t\t  *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
			while (fscanf(fr, "%[^\|] | %[^\|] | %[^\|]| %d/%d/%d | %d:%d | %lf | %[^\|] | %[^\|] | %d:%d | %d | %[^\|] | %[^\|] |\n", &backup.entryId, &backup.personalId, &backup.venueId, &backup.checkInYear, &backup.checkInMonth, &backup.checkInDay, &entry[i].in.checkInHours,
				&backup.checkInMins, &backup.temp, &backup.purpose, &backup.risk, &backup.exitHour, &backup.exitMins, &backup.duration, &backup.feedback, &backup.rate) != EOF) {
				count++;
				printf("\t      #%02d-| %6s     |  %6s      |  %6s   | %4d/%02d/%02d | %5d:%2d   |  %7.2lf      | %16s | %10s   | %02d:%02d     | %04d minutes    |  %12s  |  %6s    |\n", count, backup.entryId, backup.personalId, backup.venueId, backup.checkInYear, backup.checkInMonth, backup.checkInDay, entry[i].in.checkInHours,
					backup.checkInMins, backup.temp, backup.purpose, backup.risk, backup.exitHour, backup.exitMins, backup.duration, backup.feedback, backup.rate);
				//printf("%s\n", backup.entryId);	
			}
			printf("\t\t  *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
			fclose(fr);
		}
		if (type == 2) {
			do {
				do {
					system("cls");
					loginHeader(6);
					//Display current records
					printf("\n\t\t\t\t       ==============================================\n");
					printf("\t\t\t\t                 DISPLAY CURRENT ENRTY HISTORY \n");
					printf("\t\t\t\t        ==============================================\n\n");
					printf("\t\t                        ----------------------------------------------\n");
					printf("\t\t                        |                                            |\n");
					printf("\t\t                        |  1. DISPLAY VENUE ID                       |\n");
					printf("\t\t                        |  2. DISPLAY DATE                           |\n");
					printf("\t\t                        |  3. DISPLAY TIME (VISIT & EXIT)            |\n");
					printf("\t\t                        |  4. DISPLAY TEMPERATURE WITH CURRENT RISK  |\n");
					printf("\t\t                        |  5. DISPLAY FEEDBACK AND RATING            |\n");
					printf("\t\t                        |  6. DISPLAY MIXED                          |\n"); //Display Mixed able to display more than 2 field
					printf("\t\t                        |  7. DISPLAY ALL                            |\n");
					printf("\t\t                        |                                            |\n");
					printf("\t\t                        ----------------------------------------------\n");
					printf("\n\t\t\t\t        Enter the field you want to display    -> ");
					rewind(stdin);
					scanf("%d", &field);
					//validate whether is numeric 
					validate = checkIsNum(field);
				} while (field != 1 && field != 2 && field != 3 && field != 4 && field != 5 && field != 6 && field != 7 && field != 8);

			} while (validate == false);

			system("cls"); loginHeader(6);
			switch (field) {
			case 1:
				count = 0;
				printf("\n\t\t\t            VENUE ID    \n");
				printf("\t\t    *-----------------------------------------*\n");
				printf("\t\t     | Entry ID   | Personal  ID |  Venue ID  |\n");
				printf("\t\t    *-----------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;

					printf("\t\t#%02d- | %6s     |  %6s      |   %6s   |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId);
				}
				printf("\t\t    *-----------------------------------------*\n");
				printf("\n\t\t                        -[ Total : %d records ]- \n", count);
				fclose(fptr);
				break;
			case 2:
				count = 0;
				printf("\n\t\t\t                 VISIT DATE    \n");
				printf("\t\t    *----------------------------------------------------*\n");
				printf("\t\t    | Entry ID   | Personal  ID |  Venue ID |   Date     | \n");
				printf("\t\t    *----------------------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;
					printf("\t\t#%02d-| %6s     |  %6s      |  %5s    | %4d/%02d/%02d |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay);
				}
				printf("\t\t    *----------------------------------------------------*\n");
				fclose(fptr);
				printf("\n\t\t                                  -[ Total : %d records ] -\n", count);
				break;
			case 3:
				printf("\n\t\t\t                  VISIT AND EXIT TIME    \n");
				printf("\t\t    *--------------------------------------------------------------------*\n");
				printf("\t\t    | Entry ID   | Personal  ID |  Venue ID |  Time entry  |  Time exit  |\n");
				printf("\t\t    *--------------------------------------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;
					printf("\t\t#%02d-| %6s     |  %6s      |  %5s    |  %5d:%2d    |  %4d:%2d    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins);
				}
				printf("\t\t    *--------------------------------------------------------------------*\n");
				printf("\n\t\t                                                   -[ Total : %d records ]-\n", count);
				fclose(fptr);
				break;
			case 4:
				printf("\n\t\t                       TEMPERATURE WITH CURRENT RISK   \n");
				printf("\t\t     *------------------------------------------------------------------------*\n");
				printf("\t\t     | Entry ID   | Personal  ID |  Venue ID | Temperatue('c)|   Current risk |\n");
				printf("\t\t     *------------------------------------------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;
					printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |  %7.2lf      |%15s |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.temp, entry[i].in.risk);
				}
				printf("\t\t     *------------------------------------------------------------------------*\n");
				printf("\n\t\t                                                        -[ Total : %d records ]-\n", count);
				fclose(fptr);
				break;
			case 5:
				printf("\n\t\t                      FEEDBACK AND RATING    \n");
				printf("\t\t     *-----------------------------------------------------------------------*\n");
				printf("\t\t     | Entry ID   | Personal  ID |  Venue ID | Feedback of SOP |   Rating    |\n");
				printf("\t\t     *-----------------------------------------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;
					printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |  %11s    |  %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].out.feed, entry[i].out.rate);
				}
				printf("\t\t     *-----------------------------------------------------------------------*\n");
				printf("\n\t\t                                                       -[ Total : %d records ]-\n", count);
				fclose(fptr);
				break;
			case 6:
				count = 0;
				skip = 0;
				printf("\n\t\t   ============================================\n");
				printf("\t\t                 DISPLAY MIXED\n");
				printf("\t\t   ============================================\n");
				printf("\t\t  *Kindly remind that cannot only choose one field*\n\n");
				printf("\n     =[ '1'-to SKIP , '0'- to display ]= \n");

				printf("  _______________________________________\n");
				do {
					do {
						printf("\n   (1)   DATE OF ENTRY                  -> ");
						rewind(stdin);
						scanf("%d", &date);
						validate = checkIsNum(date);
					} while (date != 1 && date != 0);
				} while (validate == false);

				if (date == 1) {
					skipDate = true;
					skip++;
				}
				else {
					skipDate = false;
				}

				do {
					do {
						printf("\n   (2)   TIME OF ENTRY                  -> ");
						rewind(stdin);
						scanf("%d", &time);
						validate = checkIsNum(time);
					} while (time != 1 && time != 0);
				} while (validate == false);

				if (time == 1) {
					skipTime = true;
					skip++;
				}
				else {
					skipTime = false;
				}

				do {
					do {
						printf("\n   (3)   TEMPERATURE WITH CURRENT RISK  -> ");
						rewind(stdin);
						scanf("%d", &temp);
						validate = checkIsNum(temp);
					} while (temp != 1 && temp != 0);
				} while (validate == false);

				if (temp == 1) {
					skipTemp = true;
					skip++;
				}
				else {
					skipTemp = false;
				}

				do {
					do {
						printf("\n   (4)   FEEDBACK AND RATING            -> ");
						rewind(stdin);
						scanf("%d", &feedback);
						validate = checkIsNum(feedback);
					} while (feedback != 1 && feedback != 0);
				} while (validate == false);

				if (feedback == 1) {
					skipFeedback = true;
					skip++;
				}
				else {
					skipFeedback = false;
				}
				
				//if skip more than 2 cannot display 

					//Display time,date,temperature,feedback,rating
				if (skipDate == false && skipTime == false && skipTemp == false && skipFeedback == false) {
					if (date == 0 && time == 0 && temp == 0 && feedback == 0) {
						printf("\n\t\t                        DISPLAY DATE ,TIME ,TEMPEATURE ,FEEDBACK ,RATING    \n");
						printf("     *---------------------------------------------------------------------------------------------------------------------------------------------*\n");
						printf("     | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry | Temperatue('c)|  Current risk | Time exit  | Feedback of SOP |   Rating   |\n");
						printf("     *---------------------------------------------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d | %5d:%2d   |  %7.2lf      | %10s    | %4d:%2d    | %11s     | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear,
								entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].in.temp, entry[i].in.risk, entry[i].out.outHour, entry[i].out.outMins, entry[i].out.feed, entry[i].out.rate);
						}
						printf("     *---------------------------------------------------------------------------------------------------------------------------------------------*\n");
						printf("\n                                                                                                                           -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//display date and time
				if (skipDate == false && skipTime == false && skipTemp == true && skipFeedback == true) {
					if (date == 0 && time == 0 && temp == 1 && feedback == 1) {
						printf("\n  \t\t\t\t              DISPLAY DATE AND TIME    ");
						printf("\n\t\t     *------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry |  Time exit | \n");
						printf("\t\t     *------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d | %5d:%2d   |  %4d:%2d   | \n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins);
						}
						printf("\t\t     *------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                  -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//display date ,temperature,current risk
				if (skipDate == false && skipTime == true && skipTemp == false && skipFeedback == true) {
					if (date == 0 && time == 1 && temp == 0 && feedback == 1) {
						printf("\n  \t\t\t                      DISPLAY DATE ,TEMPEATURE ,CURRENT RISK    \n");
						printf("\t\t     *----------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |  Time entry  |   Time exit | Temperatue('c)|  Current risk |  \n");
						printf("\t\t     *----------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |  %5d:%2d    |  %4d:%2d    |    %7.2lf    | %10s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins, entry[i].in.temp, entry[i].in.risk);
						}
						printf("\t\t     *----------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                          -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//display time and feedback
				if (skipDate == false && skipTime == true && skipTemp == true && skipFeedback == false) {
					if (date == 0 && time == 1 && temp == 1 && feedback == 0) {
						printf("\n   \t\t\t\t          DISPLAY TIME ,FEEDBACK ,RATING    \n");
						printf("\t\t     *--------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |      Date     | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *--------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |   %4d/%02d/%02d  |   %11s   | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *--------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                            -[ Total : %d records ]-\n", count);
						fclose(fptr); 
					}
				}
				//display temperature and feedback
				if (skipDate == true && skipTime == true && skipTemp == false && skipFeedback == false) {
					if (date == 1 && time == 1 && temp == 0 && feedback == 0) {
						printf("\n  \t\t\t                    DISPLAY TEMPEATURE ,CURRENT RISK ,FEEDBACK ,RATING    \n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |  Temperatue('c)|  Current risk | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |    %7.2lf     | %10s    | %11s     | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.temp, entry[i].in.risk, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *-------------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                              -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}

				//only skip feedback
				if (skipDate == false && skipTime == false && skipTemp == false && skipFeedback == true) {
					if (date == 0 && time == 0 && temp == 0 && feedback == 1) {
						printf("\n   \t\t\t                    DISPLAY DATE, TIME ,TEMPERATURE ,CURRENT RISK    \n");
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry |  Time exit | Temperatue('c)|  Current risk | \n");
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d | %5d:%2d   |  %4d:%2d   | %7.2lf       | %10s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins, entry[i].in.temp, entry[i].in.risk);
						}
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                                    -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}

				//only skip date
				if (skipDate == true && skipTime == false && skipTemp == false && skipFeedback == false) {
					if (date == 1 && time == 0 && temp == 0 && feedback == 0) {
						printf("\n  \t\t\t                        DISPLAY VENUE ID  ,TIME ,TEMPEATURE ,FEEDBACK ,RATING    \n");
						printf("\t\t     *----------------------------------------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |   Time entry | Temperatue('c)|  Current risk | Time exit  | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *----------------------------------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    |  %5d:%2d    |  %7.2lf      | %10s    | %4d:%2d    | %11s     | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].in.temp, entry[i].in.risk, entry[i].out.outHour, entry[i].out.outMins, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *----------------------------------------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                                                      -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//only skip time
				if (skipDate == false && skipTime == true && skipTemp == false && skipFeedback == false) {
					if (date == 0 && time == 1 && temp == 0 && feedback == 0) {
						printf("\n   \t\t\t                     DISPLAY VENUE ID ,DATE ,TEMPEATURE ,FEEDBACK ,RATING    \n");
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |    Date    |  Temperatue('c)|  Current risk | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d |   %7.2lf      | %10s    |  %11s    | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.temp, entry[i].in.risk, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *--------------------------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                                    -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//only skip temperature
				if (skipDate == false && skipTime == false && skipTemp == true && skipFeedback == false) {
					if (date == 0 && time == 0 && temp == 1 && feedback == 0) {
						printf("\n\t\t                                 DISPLAY DATE ,TIME , FEEDBACK ,RATING    \n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry | Time exit  | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d | %5d:%2d   | %4d:%2d    | %11s     | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear,
								entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *-------------------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                               -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//display time and feedback
				if (skipDate == true && skipTime == false && skipTemp == true && skipFeedback == false) {
					if (date == 1 && time == 0 && temp == 1 && feedback == 0) {
						printf("\n\t\t                                  DISPLAY TIME , FEEDBACK ,RATING    \n");
						printf("\t\t     *------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID | Time entry | Time exit  | Feedback of SOP |   Rating   |\n");
						printf("\t\t     *------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %5d:%2d   | %4d:%2d    | %11s     | %7s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId,
								entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins, entry[i].out.feed, entry[i].out.rate);
						}
						printf("\t\t     *------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                  -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				//display time and temperature
				if (skipDate == true && skipTime == false && skipTemp == false && skipFeedback == true) {
					if (date == 1 && time == 0 && temp == 0 && feedback == 1) {
						printf("\n\t\t\t                      DISPLAY TIME ,TEMPERATURE AND CURRENT RISK    \n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------*\n");
						printf("\t\t     | Entry ID   | Personal  ID |  Venue ID | Time entry | Time exit  | Temperatue('c)|  Current risk |\n");
						printf("\t\t     *-------------------------------------------------------------------------------------------------*\n");
						while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
							count++;
							printf("\t\t#%02d- | %6s     |  %6s      |  %5s    | %5d:%2d   | %4d:%2d    | %7.2lf       | %10s    |\n", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId,
								entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].out.outHour, entry[i].out.outMins, entry[i].in.temp, entry[i].in.risk);
						}
						printf("\t\t     *-------------------------------------------------------------------------------------------------*\n");
						printf("\n\t                                                                                   -[ Total : %d records ]-\n", count);
						fclose(fptr);
					}
				}
				if (skip >= 3) {
					printf("\n            >>  Please choose up to 2 field to display because this is the mixed display  <<\n");
				}

				break;
			case 7:
				printf("\n\t\t\t\t\t         ==========================================================\n");
				printf("\t\t\t\t\t         |            CHECK-IN AND CHECK-OUT SUMMARY              |\n");
				printf("\t\t\t\t\t         ==========================================================\n");
				printf("\n\n\t     *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
				printf("\t     | Entry ID   | Personal  ID |  Venue ID |    Date    | Time entry | Temperatue('c)|       Purpose    | Current risk | Time exit | Duration visit  |Feedback of SOP |   Rating   |\n");
				printf("\t     *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
				while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
					count++;
					printf("\t#%02d- | %6s     |  %6s      |  %5s    | %4d/%02d/%02d | %5d:%2d   |  %7.2lf      | %16s |  %10s  |", count, entry[i].entryId, entry[i].in.id, entry[i].in.venueId, entry[i].in.checkInYear, entry[i].in.checkInMonth, entry[i].in.checkInDay, entry[i].in.checkInHours, entry[i].in.checkInMinutes, entry[i].in.temp, entry[i].in.purpose, entry[i].in.risk);
					printf("%4d:%2d    |   %03d minutes   |%11s     | %7s    |\n", entry[i].out.outHour, entry[i].out.outMins, entry[i].out.totalMins, entry[i].out.feed, entry[i].out.rate);
				}
				printf("\t     *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
				printf("\n\t\t\t\t\t\t\t\t\t\t                                                                                         -[ Total : %d records ]-\n", count);
				fclose(fptr);
				break;

			}
		}
		printf("\n\t     __________________________________________________________________________________\n");
		do {
			printf("\n\t     Do you want to continue display the history records ? ('Y'-yes,'N'-no) -> ");
			rewind(stdin);
			scanf("%c", &continueDisplay);
		} while (continueDisplay != 'Y' && continueDisplay != 'y' && continueDisplay != 'N' && continueDisplay != 'n');

	} while (continueDisplay == 'Y' || continueDisplay == 'y');
	if (continueDisplay == 'N' || continueDisplay == 'n') {
		action();
		scanf("%d", &proceed);
		switch (proceed) {
		case 1:
			system("cls"); loginHeader(6);
			VisitAndExit();
			break;
		case 2:
			exit(0);
		default:
			printf("\n>> Invalid option\n");
			sound();
		}
	}

}


void modifyEntry(struct Entrance entry[50]) {
	//Temporary array variables
	int field, fever, cough, breath, headache, contact = 0, option, i = 0, found = 0, num = 0, confirm, nDay,
		nMonth, nYear, nHours, nMins, nExithour, nExitmins, nFeedback, proceed, nRating, updatedCount = 0, nTotalHour, nTotalMins,
		totalExitmins, totalInmins;
	char choice, record[20], update, ch, nRisk[10],  nPurpose[30], nAction, improvement[50], nFeed[15], nRate[15], entryId[10], inVenueId[10], visitorId[10];
	double nTemp;
	bool validate = false; //For digit validation
	FILE* fptr;
	fptr = fopen("VisitAndExit.bin", "rb");
	//File checking
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}
	//Store into temporary variables
	while (fread(&entry[num], sizeof(struct Entrance), 1, fptr) != 0) {
		num++;
	}
	//CLose file
	fclose(fptr);

	do {
		system("cls"); loginHeader(6);
		printf("\n\t\t\t==========================================\n");
		printf("\t\t\t|       UPDATE VISITOR INFORMATION       |  ");
		printf("\n\t\t\t==========================================\n");
        printf("\n  Enter entry ID to be validated  [XXXXX] ->");
		rewind(stdin);
		scanf("%s", &entryId);


		for (i = 0; i < num; i++) {
			if (strcmp(entry[i].entryId, strupr(entryId)) == 0) {
				found = 1;
				//check whether exist or not if exist
				printf("\n  *******************************************");
				printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
				printf("  |                                         |\n");
				printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
				printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
				printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
				printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
				printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
				printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
				printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
				printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
				printf("  *******************************************\n");
				printf("\n\t     CHECK-OUT DETAILS\n");
				printf("  *------------------------------------------*\n");
				printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
				printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
				printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
				printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
				printf("  *------------------------------------------*\n");
				do {
					do {
						printf("\n     =============================\n");
						printf("            UPDATE DETAILS           \n");
						printf("     =============================\n");
						printf("  ________________________________________\n\n");
						printf("  |    1. UPDATED TEMPERATURE            |\n");
						printf("  |    2. UPDATED PURPOSE                |\n");
						printf("  |    3. UPDATED SYMPTOMS               |\n");
						printf("  |    4. UPDATED FEEDBACK               |\n");
						printf("  |    5. UPDATED RATING                 |\n");
						printf("  |    6. UPDATED ALL                    |\n");
						printf("  |    7. BACK TO MENU                   |\n");
						printf("  ________________________________________\n");
						printf("\n  Enter the field you want to update     -> ");
						rewind(stdin);
						scanf("%d", &field);
						//check if user whether suddenly enter the alphabets 
						validate = checkIsNum(field);
					} while (field != 1 && field != 2 && field != 3 && field != 4 && field != 5 && field != 6 && field != 7);
				} while (validate == false);

				//Id,date and time cannot modify 
				strcpy(entryId, entry[i].entryId);
				strcpy(visitorId, entry[i].in.id);
				strcpy(inVenueId, entry[i].in.venueId);
				nDay = entry[i].in.checkInDay;
				nMonth = entry[i].in.checkInMonth;
				nYear = entry[i].in.checkInYear;
				nHours = entry[i].in.checkInHours;
				nMins = entry[i].in.checkInMinutes;
				nExithour = entry[i].out.outHour;
				nExitmins = entry[i].out.outMins;
				if (field == 7) {
					adminLoginMenu();
				}
				if (field == 1 || field == 6) {
					do {
						printf("\n  New Temperature                        -> ");
						rewind(stdin);
						scanf("%lf", &nTemp);
						validate = checkIsNum(nTemp);
					} while (validate == false);
					while (nTemp < 36 || nTemp>40) {
						printf("\n  Invalid temperature range. Please enter temperature again ->");
						rewind(stdin);
						scanf("%lf", &nTemp);
					}
					if (nTemp >= 37 && nTemp <= 40) {
						sound();
						printf(" -[ Abnormal temperature . You're not allow to enter ]-\n");
						VisitAndExit();
						//call function to exit 
					}

				}
				else {
					nTemp = entry[i].in.temp;
				}
				if (field == 2 || field == 6) {

					printf("\n  New entry purpose                      -> ");
					rewind(stdin);
					scanf("%[^\n]", &nPurpose);

				}
				else {
					strcpy(nPurpose, entry[i].in.purpose);
				}
				if (field == 3 || field == 6) {

					printf("\n  --------------------------------------------------------------------------\n");
					printf("  Are you currently experiencing any of these symptoms ? ('1'-Yes / '0'-NO)\n ");
					printf(" (1) - Fever and /or chills ?  ->");
					rewind(stdin);
					scanf("%d", &fever);


					while (fever != 1 && fever != 0) {
						sound();
						printf("  Invalid option .Please re-enter option ('1'-Yes / '0'-NO) ->");
						rewind(stdin);
						scanf("%d", &fever);
					}


					printf("  (2) - Cough or croup ?        ->");
					rewind(stdin);
					scanf("%d", &cough);
					while (cough != 1 && cough != 0) {
						sound();
						printf("  Invalid option .Please re-enter option ('1'-Yes / '0'-NO) ->");
						scanf("%d", &cough);
					}

					printf("  (3) - Shortness of breath ?   ->");
					rewind(stdin);
					scanf("%d", &breath);
					while (breath != 1 && breath != 0) {
						sound();
						printf("  Invalid option .Please re-enter option ('1'-Yes / '0'-NO) ->");
						scanf("%d", &breath);
					}

					printf("  (4) - Headache ?              ->");
					rewind(stdin);
					scanf("%d", &headache);
					while (headache != 1 && headache != 0) {
						sound();
						printf("  Invalid option .Please re-enter option ('1'-Yes / '0'-NO) ->");
						scanf("%d", &headache);
					}

					printf("  --------------------------------------------------------------------------\n");
					if (fever == 0 && cough == 0 && breath == 0 && headache == 0) {
						strcpy(nRisk, "LOW");
					}
					if (fever == 1 || cough == 1 || breath == 1 || headache == 1) {
						printf("\n   In the last 14 days , have you been close contact of someone who currently has COVID-19 ?('1'-Yes /'0'-NO) ->");
						scanf("%d", &contact);
						while (contact != 1 && contact != 0) {
							sound();
							printf("Invalid option.Please enter again -> ");
							rewind(stdin);
							scanf("%d", &contact);
						}
						if (contact == 1) {
							strcpy(nRisk, "HIGH");
						}
						if (contact == 0) {
							strcpy(nRisk, "MODERATE");
						}


					}
				}
				else {
					strcpy(nRisk, entry[i].in.risk);

				}


				if (field == 4 || field == 6) {
					do {
						do {
							printf("\n   -----------------------------------------------------------\n");
							printf("   |    Feedback of the Standard Operating Procedure (SOP)   |\n");
							printf("   |       ( 1 ) - Excellence                                |\n");
							printf("   |       ( 2 ) - Good                                      |\n");
							printf("   |       ( 3 ) - Bad                                       |\n");
							printf("   -----------------------------------------------------------\n");

							printf("         Your option -> ");
							rewind(stdin);
							scanf("%d", &nFeedback);
							validate = checkIsNum(nFeedback);
						} while (nFeedback != 1 && nFeedback != 2 && nFeedback != 3);
					} while (validate == false);



					//copy the word
					if (nFeedback == 1) {
						strcpy(nFeed, "Excellence");
					}
					else if (nFeedback == 2) {
						strcpy(nFeed, "Good");
					}
					else if (nFeedback == 3) {
						strcpy(nFeed, "Bad");
					}

				}
				else {
					strcpy(nFeed, entry[i].out.feed);

				}
				if (field == 5 || field == 6) {
					do {
						do {
							printf("\n   Rating of MySejahtera '*'-> STAR\n");
							printf("    -----------------------\n");
							printf("     -[  1  - *        ]-\n ");
							printf("    -[  2  - **       ]-\n ");
							printf("    -[  3  - ***      ]-\n ");
							printf("    -[  4  - ****     ]-\n ");
							printf("    -[  5  - *****    ]-\n ");
							printf("   -----------------------\n");
							printf("      Your rating >> ");
							rewind(stdin);
							scanf("%d", &nRating);
							validate = checkIsNum(nRating);
						} while (nRating != 1 && nRating != 2 && nRating != 3 && nRating != 4 && nRating != 5);
					} while (validate == false);
					//Copy the star into the nRate string
					if (nRating == 1) {
						strcpy(nRate, "*");

					}
					else if (nRating == 2) {
						strcpy(nRate, "**");
					}
					else if (nRating == 3) {
						strcpy(nRate, "***");
					}
					else if (nRating == 4) {
						strcpy(nRate, "****");
					}
					else {
						strcpy(nRate, "*****");
					}
				}
				else {
					strcpy(nRate, entry[i].out.rate);
				}
				//Count the total minutes visited
				nTotalMins = (nExithour - nHours) * 60 + nExitmins - nMins;
				do {
					do {
						printf("\n   ---------------------------------------------------\n");
						printf("   |      Are you confirm to update entry module ?    |\n");
						printf("   |             ( 1 ) - Yes                          |\n");
						printf("   |             ( 2 ) - No                           |\n");
						printf("   ---------------------------------------------------\n");

						printf(" Your option (1/2) -> ");
						rewind(stdin);
						scanf("%d", &confirm);
						validate = checkIsNum(confirm);
					} while (confirm != 1 && confirm != 2);
				} while (validate == false);

				if (confirm == 1) {
					//Move all variables into temporary variables 
					strcpy(entry[i].entryId, entryId);
					strcpy(entry[i].in.id, visitorId);
					strcpy(entry[i].in.venueId, inVenueId);
					entry[i].in.checkInDay = nDay;
					entry[i].in.checkInMonth = nMonth;
					entry[i].in.checkInYear = nYear;
					entry[i].in.checkInHours = nHours;
					entry[i].in.checkInMinutes = nMins;
					entry[i].out.outHour = nExithour;
					entry[i].out.outMins = nExitmins;
					entry[i].in.temp = nTemp;
					entry[i].out.totalMins = nTotalMins;
					entry[i].in.symptoms.contact = contact;
					strcpy(entry[i].in.purpose, nPurpose);
					strcpy(entry[i].out.rate, nRate);
					strcpy(entry[i].out.feed, nFeed);
					strcpy(entry[i].in.risk, nRisk);
					updatedCount++;
					printf("\n  *******************************************");
					printf("\n  |\t  -UPDATED CHECK-IN DETAILS -       |\n");
					printf("  |                                         |\n");
					printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
					printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
					printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
					printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
					printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
					printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
					printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
					printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
					printf("  *******************************************\n");
					printf("\n\t   -UPDATED CHECK-OUT DETAILS -\n");
					printf("  *------------------------------------------*\n");
					printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
					printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
					printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
					printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
					printf("  *------------------------------------------*\n");
				}
			}//if loop
		}//for loop
		if (found == 0) {
			sound();
			printf("\n    >> Sorry.No such record(s) existing. \n");
		}
		FILE* fr;
		fr = fopen("VisitAndExit.bin", "wb");

		for (i = 0; i < num; i++) {
			fwrite(&entry[i], sizeof(struct Entrance), 1, fr);
		}
		if (fr == NULL) {
			printf("Error opening the file\n");
			exit(-1);
		}


		fclose(fr);
		printf("\n   Are you want to continue update ?('Y'/'N') ->");
		rewind(stdin);
		scanf("%c", &nAction);
		ch = toupper(nAction);
		while (ch != 'Y' && ch != 'N') {
			printf("Invalid option. Please enter again ->");
			sound();
			rewind(stdin);
			scanf("%c", &nAction);
			ch = toupper(nAction);
		}
		if (ch == 'N') {

			do {
				action();
				scanf("%d", &proceed);
				switch (proceed) {
				case 1:
					system("cls"); loginHeader(6);
					VisitAndExit();
					break;
				case 2:
					exit(0);
					break;
				default:
					printf("\n>> Invalid option\n");
				}
			} while (proceed != 1 && proceed != 2);

		}
		system("cls");
	} while (ch == 'Y');

}


void searchEntry(struct Entrance entry[50]) {
	char  vId[10],entryId[10], venueid[15], ctn = "", next;
	int i = 0, num = 0, found = 0, sDay, sMonth, sYear, sHours, sMins, countRecord = 0;
	double sTemp;
	bool skipId = true, skipDate = true, skipTime = true, skipEntryId = true, validate = false;
	FILE* fptr;
	fptr = fopen("VisitAndExit.bin", "rb");
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}
	while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
		num++;
		i = num;
	}

	do {
		system("cls");
		loginHeader(6);
		printf("\n\t\t\t\t\t\t==========================================\n");
		printf("\t\t\t\t\t\t|       SEARCH VISITOR INFORMATION       |  ");
		printf("\n\t\t\t\t\t\t==========================================\n");
		//check ID compare or not
		printf("\n    Enter VISITOR ID to search  [XXXX]         -> ");
		rewind(stdin);
		scanf("%s", &vId);

		for (i = 0; i < num; i++) {
			if (strcmp(entry[i].in.id, strupr(vId)) == 0) {
				found = 1;
				//Allow the skip function to user
				printf("\n\n\n    #  ENTER THE CRITERIA WHICH YOU WANT TO SEARCH   #\n");
				printf("   ______________________________________________________\n\n");
				printf("   (1)   Entry ID  ('S'  to skip / 'XXX' to  MENU )  -> ");
				rewind(stdin);
				scanf("%s", &entryId);

				//XXX let user back to  VisitAndExit 
				if (strcmp(strupr(entryId), "XXX") == 0) {
					VisitAndExit();
				}
				if (strcmp(strupr(entryId), "S") == 0) {
					skipEntryId = true;
				}
				else {
					skipEntryId = false;

				}
				printf("\n   (2)   VENUE ID  ('S' to skip )                    -> ");
				rewind(stdin);
				scanf("%s", &venueid);

				if (strcmp(strupr(venueid), "S") == 0) {
					skipId = true;
				}
				else {
					skipId = false;

				}

				printf("\n   (3)   Date of entry [ dd/mm/yyyy ] (1/1/1-SKIP)   -> ");
				rewind(stdin);
				scanf("%d/%d/%d", &sDay, &sMonth, &sYear);
				//date validation
				while (sDay < 1 || sDay>30 || sMonth < 1 || sMonth>12 || sYear > 2021) {
					printf("Invalid date.Please re-enter again [ dd/ mm/ yyyy ]   ->");
					scanf("%d/%d/%d", &sDay, &sMonth, &sYear);
				}

				if (sDay == 1 && sMonth == 1 && sYear == 1) {
					skipDate = true;
				}
				else {
					skipDate = false;
				}


				printf("\n   (4)   Time of entry (XX:XX)  (1:1) - SKIP)        -> ");
				rewind(stdin);
				scanf("%d:%d", &sHours, &sMins);

				//time validation
				while (sHours > 24 || sHours < 0 || sMins>60 || sMins < 0) {
					printf("Invalid time of entry.Please enter again(XX:XX)         ->");
					rewind(stdin);
					scanf("%d:%d", &sHours, &sMins);
				}

				if (sHours == 1 && sMins == 1) {
					skipTime = true;
				}
				else {
					skipTime = false;

				}

				if (skipId == false && skipEntryId == false && skipDate == false && skipTime == false) {

					//enter venue id,date and also time
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && strcmp(strupr(entryId), entry[i].entryId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				else if (skipId == true && skipEntryId == false && skipDate == false && skipTime == false) {
					//enter date, time ,entry id
					if (strcmp(strupr(entryId), entry[i].entryId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}
				}
				else if (skipId == false && skipEntryId == true && skipDate == false && skipTime == false) {
					//enter venue id,date and time
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}
				}
				else if (skipId == false && skipEntryId == false && skipDate == true && skipTime == false) {
					//enter id and time
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && strcmp(strupr(entryId), entry[i].entryId) == 0 && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}


				}
				else if (skipId == false && skipEntryId == false && skipDate == false && skipTime == true) {
					//enter id and date
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && strcmp(strupr(entryId), entry[i].entryId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}
				}
				else if (skipId == false && skipEntryId == true && skipDate == true && skipTime == true) {
					//enter venue id only
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}
				}
				else if (skipId == true && skipEntryId == false && skipDate == true && skipTime == true) {
					//enter entry id only
					if (strcmp(strupr(entryId), entry[i].entryId) == 0) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}
				}
				else if (skipId == true && skipEntryId == true && skipDate == false && skipTime == true) {
					//enter date only
					if (sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				else if (skipId == true && skipEntryId == true && skipDate == true && skipTime == false) {
					//enter time only
					if (sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");

						countRecord++;
					}
				}
				if (skipId == false && skipEntryId == false && skipDate == true && skipTime == true) {
					//enter venue id and entry id
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && strcmp(strupr(entryId), entry[i].entryId) == 0) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				if (skipId == false && skipEntryId == true && skipDate == false && skipTime == true) {
					//enter venue id and date
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				if (skipId == false && skipEntryId == true && skipDate == true && skipTime == false) {
					//enter venue id and time
					if (strcmp(strupr(venueid), entry[i].in.venueId) == 0 && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				if (skipId == true && skipEntryId == true && skipDate == false && skipTime == false) {
					//enter date and time
					if (sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				if (skipId == true && skipEntryId == false && skipDate == true && skipTime == false) {
					//enter entry id and time
					if (strcmp(strupr(entryId), entry[i].entryId) == 0 && sHours == entry[i].in.checkInHours && sMins == entry[i].in.checkInMinutes) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				if (skipId == true && skipEntryId == false && skipDate == false && skipTime == true) {
					//enter entry id and date
					if (strcmp(strupr(entryId), entry[i].entryId) == 0 && sDay == entry[i].in.checkInDay && sMonth == entry[i].in.checkInMonth && sYear == entry[i].in.checkInYear) {
						found = 1;
						printf("\n  *******************************************");
						printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
						printf("  |                                         |\n");
						printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
						printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
						printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
						printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
						printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
						printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
						printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
						printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
						printf("  *******************************************\n");
						printf("\n\t     CHECK-OUT DETAILS\n");
						printf("  *------------------------------------------*\n");
						printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
						printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
						printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
						printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
						printf("  *------------------------------------------*\n");
						countRecord++;
					}

				}
				//not allowed to skip all 
				else if (skipId == true && skipEntryId == true && skipDate == true && skipTime == true) {
					printf("\n\n-[ You have skip everything. No record is found. ]-\n");
				}
				if (countRecord == 0) {
					sound();
					printf("\n    >> %d matching record(s) found <<\n", countRecord);
					break;
				}
				else {
					printf("\n    >> %d matching record(s) found <<\n", countRecord);
					break;
				}

			}

		}
		if (found == 0) {
			sound();
			printf("\n     - [ Sorry no visitor ID founded ]-\n");
		}
		printf("\n   Do you wish to search another record?('Y'-continue search /'N'-Back to MENU) -> ");
		rewind(stdin);
		scanf("%c", &ctn);
		while (toupper(ctn) != 'N' && toupper(ctn) != 'Y') {
			sound();
			printf("\nInvalid option.Please enter again -> ");
			rewind(stdin);
			scanf("%c", &ctn);
		}
		if (toupper(ctn) == 'N') {
			system("cls"); loginHeader(6);
			VisitAndExit();
		}

	} while (toupper(ctn) == 'Y');

}
//Function with parameter pass by value
int deleteIndex(int i) {
	struct Entrance entry[50];
	int num = 0, j = 0;
	FILE* fptr;
	//Read from binary file
	fptr = fopen("VisitAndExit.bin", "rb");
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}
	//Store into variables
	while (fread(&entry[num], sizeof(struct Entrance), 1, fptr) != 0) {
		num++;
	}
	fclose(fptr);

	//Delete records from binary file
	for (i = 0; i < num; i++) {
		for (j = i; j < num - 1; j++) {
			entry[j] = entry[j + 1];
		}
	}

	return;
}
//Only Admin can access , visitors are not allowed
void deleteEntry(struct Entrance entry[50]) {
	int i = 0, j = 0, k = 0, num = 0, deleteCount = 0, found = 0, updated = 0, count = 0, option;
	char  venueId[10], confirm, ch, continueDelete, vId[10], entryId[10], totalMins[20];
	FILE* fptr;
	fptr = fopen("VisitAndExit.bin", "rb");
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}

	while (fread(&entry[num], sizeof(struct Entrance), 1, fptr) != 0) {
		num++;
	}
	fclose(fptr);

	do {
		system("cls"); loginHeader(6);
		printf("\n\t\t\t\t\t\t==========================================\n");
		printf("\t\t\t\t\t\t|       DELETE VISITOR INFORMATION       |  ");
		printf("\n\t\t\t\t\t\t==========================================\n");
		printf("\n\t\t\t Enter the entry ID you want to delete     -> ");
		rewind(stdin);
		scanf("%s", &entryId);

		for (i = 0; i < num; i++) {
			if ( strcmp(entry[i].entryId, strupr(entryId)) == 0) {
				//personal id and venue id founded
				found = 1;
				printf("\n   -[ Venue ID & entry ID founded ]-\n");
				printf("\n  *******************************************");
				printf("\n  |\t  -YOUR CHECK-IN DETAILS -          |\n");
				printf("  |                                         |\n");
				printf("  |  Entry ID       ->   %-6s             |\n", entry[i].entryId);
				printf("  |  Personal ID    ->   %-6s             |\n", entry[i].in.id);
				printf("  |  Venue ID       ->   %-6s             |\n", entry[i].in.venueId);
				printf("  |  Date entry     ->   %-02d/%02d/%4d         |\n", entry[i].in.checkInDay, entry[i].in.checkInMonth, entry[i].in.checkInYear);
				printf("  |  Time entry     ->   %-2d:%2d              |\n", entry[i].in.checkInHours, entry[i].in.checkInMinutes);
				printf("  |  Temperature    ->   %-7.2lf            |\n", entry[i].in.temp);
				printf("  |  Purpose        ->   %-14s     |\n", entry[i].in.purpose);
				printf("  |  Current Risk   ->   %-10s         |\n", entry[i].in.risk);
				printf("  *******************************************\n");
				printf("\n\t     CHECK-OUT DETAILS\n");
				printf("  *------------------------------------------*\n");
				printf("  |  Time Exit           ->    %-02d:%02d         |\n", entry[i].out.outHour, entry[i].out.outMins);
				printf("  |  Feedback of th SOP  ->    %-11s   |\n", entry[i].out.feed);
				printf("  |  Rating              ->    %-8s      |\n", entry[i].out.rate);
				printf("  |  Duration visit      ->    %-03d minutes   |\n", entry[i].out.totalMins);
				printf("  *------------------------------------------*\n");
				printf("\n Are you confirm want to delete the record ?('Y'/'N')  -> ");
				rewind(stdin);
				scanf("%c", &confirm);
				while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
					printf("\n Invalid option .Please enter again ('Y'/'N')  -> ");
					rewind(stdin);
					scanf("%c", &confirm);
				}

				if (confirm == 'Y' || confirm == 'y') {
					//the deleted items will move to the backup variable 
					strcpy(backup.personalId, entry[i].in.id);
					strcpy(backup.entryId, entry[i].entryId);
					strcpy(backup.venueId, entry[i].in.venueId);
					backup.checkInDay = entry[i].in.checkInDay;
					backup.checkInMonth = entry[i].in.checkInMonth;
					backup.checkInYear = entry[i].in.checkInYear;
					backup.checkInHours = entry[i].in.checkInHours;
					backup.checkInMins = entry[i].in.checkInMinutes;
					backup.exitHour = entry[i].out.outHour;
					backup.exitMins = entry[i].out.outMins;
					backup.temp = entry[i].in.temp;
					strcpy(backup.purpose, entry[i].in.purpose);
					strcpy(backup.rate, entry[i].out.rate);
					strcpy(backup.feedback, entry[i].out.feed);
					strcpy(backup.risk, entry[i].in.risk);
					backup.duration = entry[i].out.totalMins;

					//for the deleted records all will be moved to back up text file
					fptr = fopen("backup.txt", "a");
					if (fptr == NULL) {
						printf("Unable to open");
						exit(1);
					}
					//write into text file
					fprintf(fptr, "%s| %6s | %6s | %4d/%02d/%02d | %5d:%2d  |%5.2lf | %14s |%10s| %4d:%2d | %10d | %12s | %7s|\n", backup.entryId, backup.personalId, backup.venueId, backup.checkInYear, backup.checkInMonth, backup.checkInDay, backup.checkInHours,
						backup.checkInMins, backup.temp, backup.purpose, backup.risk, backup.exitHour, backup.exitMins, backup.duration, backup.feedback, backup.rate);
					fclose(fptr);

					//deleteIndex(i);
					for (j = i; j < num - 1; j++) {
						entry[j] = entry[j + 1];
					}

					num--;
					//Write into binary file
					FILE* fpr;
					fpr = fopen("VisitAndExit.bin", "wb");
					if (fpr == NULL) {
						printf("Unable to open");
						exit(1);
					}
					for (i = 0; i < num; i++) {
						fwrite(&entry[i], sizeof(struct Entrance), 1, fpr);
					}

					fclose(fptr);
					count++;

				}
			}

		}
		if (found == 0) {
			sound();
			printf("\n\t\t\t\t\t   >> No entry ID found. <<\n");
		}
		
		printf("\n Do you want to continue delete record ('Y'/'N')       -> ");
		rewind(stdin);
		scanf("%c", &continueDelete);
		while (continueDelete != 'y' && continueDelete != 'Y' && continueDelete != 'n' && continueDelete != 'N') {
			printf("\n Invalid option .Please enter again ('Y'/'N')  -> ");
			rewind(stdin);
			scanf("%c", &continueDelete);
		}
		if (continueDelete == 'n' || continueDelete == 'N') {
			printf("\n    << %d record has been successful deleted  >>\n", count);
			loginHeader(6);
			VisitAndExit();
		}


	} while (continueDelete == 'Y' || continueDelete == 'y');
}

void entranceReport(struct Entrance entry[50]) {
	system("cls");
	int i = 0, num = 0, statusLow = 0, statusModerate = 0, statusHigh = 0, choice, contact = 0, excellent = 0, good = 0, bad = 0, rate1 = 0, rate2 = 0, rate3 = 0, rate4 = 0, rate5 = 0, option, count = 0, month, found = 0;
	//Count the venue 
	int countTanKwengHoeLibrary = 0, countDatukLeeLibrary = 0, countComputerLab = 0, countScienceLab = 0, countComputerLab2 = 0, countScienceLab2 = 0, countClassroom1 = 0, countClassroom2 = 0;
	int countMainCafeteria = 0, countLectureOffice = 0, countStudentClinic = 0, countMosque = 0, countSouthClub = 0, countNorthClub = 0, countMainHall = 0, countDatukLimHall = 0, countClassroom3 = 0, countClassroom4 = 0, countLectureHall1 = 0, countLectureHall2 = 0, totalCount = 0;
	char  low[10], high[10], moderate[10], feedback[10], rating[10], continueReport;
	bool validate = false;
	do {
	FILE* fptr;
	fptr = fopen("VisitAndExit.bin", "rb");
	if (fptr == NULL) {
		printf("Unable to open");
		exit(1);
	}
	while (fread(&entry[i], sizeof(struct Entrance), 1, fptr) != 0) {
		//Count each of the feedback 
		if (strcmp(strupr(entry[i].out.feed), "EXCELLENT") == 0) {
			excellent++;
		}
		else if (strcmp(strupr(entry[i].out.feed), "GOOD") == 0) {
			good++;
		}
		else if (strcmp(strupr(entry[i].out.feed), "BAD") == 0) {
			bad++;
		}

		//Count each of the rating
		if (strcmp(entry[i].out.rate, "*") == 0) {
			rate1++;
		}
		else if (strcmp(entry[i].out.rate, "**") == 0) {
			rate2++;
		}
		else if (strcmp(entry[i].out.rate, "***") == 0) {
			rate3++;
		}
		else if (strcmp(entry[i].out.rate, "****") == 0) {
			rate4++;
		}
		 else if (strcmp(entry[i].out.rate, "*****") == 0) {
			rate5++;
		}


	}
	fclose(fptr);
		system("cls");
		loginHeader(6);
		printf("\n\t\t\t============================================\n");
		printf("\t\t\t|        REPORT OF ENTRY INFORMATION       |  \n");
		printf("\t\t\t============================================\n");

		do {
			do {
				printf("\n\n\t\t\t ------------------------------------------\n");
				printf("\t\t\t |        TYPE OF REPORT                   |\n");
				printf("\t\t\t |   1. Overall feedback of SOP            |\n");
				printf("\t\t\t |   2. Rating of the Mysejahtera          |\n");
				printf("\t\t\t |   3. Number of visitors in every venue  |\n");
				printf("\t\t\t |   4. Back                               |\n");
				printf("\t\t\t ------------------------------------------\n");
				printf("\t\t\t   Enter the type of report you want -> ");
				rewind(stdin);
				scanf("%d", &choice);
				validate = checkIsNum(choice);
			} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
		} while (validate == false);
		switch (choice) {
		case 1:
			system("cls"); loginHeader(6);
			printf("\n\t\t                    Overall feedback of SOP                      ");
			printf("\n\t\t   -------------------------------------------------------------\n");
			printf("\t\t   |    Excellence  : %2d number of people                       |\n", excellent);
			printf("\t\t   |    Good        : %2d number of people                       |\n", good);
			printf("\t\t   |    Bad         : %2d number of people                       |\n", bad);
			printf("\t\t   -------------------------------------------------------------\n");
			printf("\n\t\t\t\t   Conclusion :\n ");
			//Compare each of the feedback and do conclusion
			if (excellent > good && excellent > bad) {
				//If excellent the most
				printf("\n\t\t   -[ Based on the feedback , most of the people choose excellent ]-\n");
			}
			else if (good > bad && good > excellent) {
				//If good the most
				printf("\n\t\t   -[ Based on the feedback , most of the people choose good ]-\n");
			}
			else {
				//If bad the most
				printf("\n\t\t   -[ Based on the feedback , most of the people choose bad ]-\n");
			}
			break;
		case 2:
			system("cls"); loginHeader(6);
			printf("\n\t\t               Overall rating of Mysejahtera                      ");
			printf("\n\t\t   -----------------------------------------------------\n");
			printf("\t\t   | ->  *     : %2d number of people                   |\n", rate1);
			printf("\t\t   | ->  **    : %2d number of people                   |\n", rate2);
			printf("\t\t   | ->  ***   : %2d number of people                   |\n", rate3);
			printf("\t\t   | ->  ****  : %2d number of people                   |\n", rate4);
			printf("\t\t   | ->  ***** : %2d number of people                   |\n", rate5);
			printf("\t\t   -----------------------------------------------------\n");
			printf("\n\t\t\t\t   Conclusion :\n ");
			//Compare each of the rating and do conclusion
			if (rate1 > rate2 && rate1 > rate3 && rate1 > rate4 && rate1 > rate5) {
				//If rate 1 the most
				printf("\n\t\t   -[ Based on the rating , most of the people choose 1 star  ]-\n");
			}
			else if (rate2 > rate1 && rate2 > rate3 && rate2 > rate4 && rate2 > rate5) {
				//If rate 2 the most
				printf("\n\t\t   -[ Based on the rating , most of the people choose 2 star  ]-\n");
			}
			else if (rate3 > rate1 && rate3 > rate2 && rate3 > rate4 && rate3 > rate5) {
				//If rate 3 the most
				printf("\n\t\t   -[ Based on the rating , most of the people choose 3 star  ]-\n");
			}
			else if (rate4 > rate1 && rate4 > rate2 && rate4 > rate3 && rate4 > rate5) {
				//If rate 4 the most
				printf("\n\t\t   -[ Based on the rating , most of the people choose 4 star  ]-\n");
			}
			else if (rate5 > rate1 && rate5 > rate2 && rate5 > rate3 && rate5 > rate4) {
				//If rate 5 the most
				printf("\n\t\t   -[ Based on the rating , most of the people choose 5 star  ]-\n");
			}
			break;
		case 3:
			printf("\n      Please enter a month to create a monthly report for the current visitors in each venue :");
			rewind(stdin);
			scanf("%d", &month);
			//validation check for month to ensure that user only can key 1 to 12
			while (month < 1 || month > 12) {
				printf("\t\t\t\t\t\t\t\tInvalid month !\n");
				printf("\t\t\t\t\t\t\t\tPlease re-enter the month:");
				rewind(stdin);
				scanf("%d", &month);
			}
			FILE* fptr;
			fptr = fopen("VisitAndExit.bin", "rb");
			if (fptr == NULL) {
				printf("Unable to open");
				exit(1);
			}
			while (fread(&entry[num], sizeof(struct Entrance), 1, fptr) != 0) {
				num++;
			}
			fclose(fptr);

			for (i = 0; i < num; i++) {

				//compare the month form user input and the month in the text file
				if (month == entry[i].in.checkInMonth) {
					found++;
					if (found >= 1) {
						//Compare each of the Venue ID and count visitors in each venue
						if (strcmp(entry[i].in.venueId, "T001") == 0) {
							countTanKwengHoeLibrary++;
						}
						else if (strcmp(entry[i].in.venueId, "T002") == 0) {
							countDatukLeeLibrary++;
						}
						else if (strcmp(entry[i].in.venueId, "T003") == 0) {
							countComputerLab++;
						}
						else if (strcmp(entry[i].in.venueId, "T004") == 0) {
							countScienceLab++;
						}
						else if (strcmp(entry[i].in.venueId, "T005") == 0) {
							countComputerLab2++;
						}
						else if (strcmp(entry[i].in.venueId, "T006") == 0) {
							countScienceLab2++;
						}
						else if (strcmp(entry[i].in.venueId, "T007") == 0) {
							countClassroom1++;
						}
						else if (strcmp(entry[i].in.venueId, "T008") == 0) {
							countClassroom2++;
						}

						else if (strcmp(entry[i].in.venueId, "T009") == 0) {
							countMainCafeteria++;
						}

						else if (strcmp(entry[i].in.venueId, "T010") == 0) {
							countLectureOffice++;
						}
						else if (strcmp(entry[i].in.venueId, "T011") == 0) {
							countStudentClinic++;
						}
						else if (strcmp(entry[i].in.venueId, "T012") == 0) {
							countMosque++;
						}
						else if (strcmp(entry[i].in.venueId, "T013") == 0) {
							countSouthClub++;
						}
						else if (strcmp(entry[i].in.venueId, "T014") == 0) {
							countNorthClub++;
						}
						else if (strcmp(entry[i].in.venueId, "T015") == 0) {
							countMainHall++;
						}
						else if (strcmp(entry[i].in.venueId, "T016") == 0) {
							countDatukLimHall++;
						}
						else if (strcmp(entry[i].in.venueId, "T017") == 0) {
							countClassroom3++;
						}
						else if (strcmp(entry[i].in.venueId, "T018") == 0) {
							countClassroom4++;
						}
						else if (strcmp(entry[i].in.venueId, "T019") == 0) {
							countLectureHall1++;
						}
						else if (strcmp(entry[i].in.venueId, "T020") == 0) {
							countLectureHall2++;
						}

					}
				}
			}
			//if the month from user input match with the month in text file,display a report
			if (found >= 1) {
				printf("\n\n\t\t\t\t\t\t\t       Monthly Report of Number of visitors in each Venue in : ");
				monthInEng(month);
				printf("\n");
				//Show for the admin see each of the venue contain how many visitors
				printf(" \t\t\t\t\t\t\t\t+________________________________________________________+\n");
				printf(" \t\t\t\t\t\t\t\t|              Venue              |  Number of Visitors  |\n");
				printf(" \t\t\t\t\t\t\t\t|=================================|======================|\n");
				printf(" \t\t\t\t\t\t\t\t|  TAN KWENG HOE LIBRARY          |      %6d          |\n", countTanKwengHoeLibrary);
				printf(" \t\t\t\t\t\t\t\t|  DATUK LEE LIBRARY              |      %6d          |\n", countDatukLeeLibrary);
				printf(" \t\t\t\t\t\t\t\t|  COMPUTER LAB                   |      %6d          |\n", countComputerLab);
				printf(" \t\t\t\t\t\t\t\t|  SCIENCE LAB                    |      %6d          |\n", countScienceLab);
				printf(" \t\t\t\t\t\t\t\t|  COMPUTER LAB 2                 |      %6d          |\n", countComputerLab2);
				printf(" \t\t\t\t\t\t\t\t|  SCIENCE LAB 2                  |      %6d          |\n", countScienceLab2);
				printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 1                    |      %6d          |\n", countClassroom1);
				printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 2                    |      %6d          |\n", countClassroom2);
				printf(" \t\t\t\t\t\t\t\t|  MAIN CAFETERIA                 |      %6d          |\n", countMainCafeteria);
				printf(" \t\t\t\t\t\t\t\t|  LECTURE OFFICE                 |      %6d          |\n", countLectureOffice);
				printf(" \t\t\t\t\t\t\t\t|  STUDENT CLINIC                 |      %6d          |\n", countStudentClinic);
				printf(" \t\t\t\t\t\t\t\t|  MOSQUE                         |      %6d          |\n", countMosque);
				printf(" \t\t\t\t\t\t\t\t|  SOUTH CLUB AND SOCIETY         |      %6d          |\n", countSouthClub);
				printf(" \t\t\t\t\t\t\t\t|  NORTH CLUB AND SOCIETY         |      %6d          |\n", countNorthClub);
				printf(" \t\t\t\t\t\t\t\t|  MAIN HALL                      |      %6d          |\n", countMainHall);
				printf(" \t\t\t\t\t\t\t\t|  DATUK LIM HALL                 |      %6d          |\n", countDatukLimHall);
				printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 3                    |      %6d          |\n", countClassroom3);
				printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 4	                  |      %6d          |\n", countClassroom4);
				printf(" \t\t\t\t\t\t\t\t|  LECTURE HALL 1	          |      %6d          |\n", countLectureHall1);
				printf(" \t\t\t\t\t\t\t\t|  LECTURE HALL 2	          |      %6d          |\n", countLectureHall2);
				printf(" \t\t\t\t\t\t\t\t+________________________________________________________+\n");

				//Total visitors in that month
				totalCount = countTanKwengHoeLibrary + countDatukLeeLibrary + countComputerLab + countScienceLab + countComputerLab2 + countScienceLab2 + countClassroom1 + countClassroom2 +
					countMainCafeteria + countLectureOffice + countStudentClinic + countMosque + countSouthClub + countNorthClub + countMainHall + countDatukLimHall + countClassroom3 + countClassroom4 + countLectureHall1 + countLectureHall2;

				printf("\n\t\t\t\t\t\t\t          - Total visitors records are %d in ", totalCount);
				monthInEng(month);
				
				printf("\n");
			}

			if (found == 0) {
				//0 visitors in that month
				printf("\n\t\t\t\t\t\t\t\tThe month you enter which is %d is not found in the record.\n", month);
				
				//clear the history
				found = 0;
				countTanKwengHoeLibrary = 0;
				countDatukLeeLibrary = 0;
				countComputerLab = 0;
				countScienceLab = 0;
				countComputerLab2 = 0;
				countScienceLab2 = 0;
				countClassroom1 = 0;
				countClassroom2 = 0;
				countMainCafeteria = 0;
				countLectureOffice = 0;
				countStudentClinic = 0;
				countMosque = 0;
				countSouthClub = 0;
				countNorthClub = 0;
				countMainHall = 0;
				countDatukLimHall = 0;
				countClassroom3 = 0;
				countClassroom4 = 0;
				countLectureHall1 = 0;
				countLectureHall2 = 0;
			}
			break;
			case 4:
				VisitAndExit();
			default:sound();

		}	printf("\n\n       Are you want to continue to view Visit & Exit report ? ('Y'-yes ,'N'-No) ->");
		rewind(stdin);
		scanf("%c", &continueReport);
		while (toupper(continueReport) != 'Y' && toupper(continueReport) != 'N') {
			sound();
			printf("  Invalid option .Please enter again ->");
			scanf("%c", &continueReport);
		}
		if (toupper(continueReport) == 'N') {
			do {
				do {
					action();
					rewind(stdin);
					scanf("%d", &option);
					validate = checkIsNum(option);
					switch (option) {
					case 1:
						system("cls"); loginHeader(6);
						VisitAndExit();
						break;
					case 2:
						exit(0);
						break;

					}
				} while (option != 1 && option != 2);
			} while (validate == false);
		}
	} while (toupper(continueReport) == 'Y');
	


}