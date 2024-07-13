#include "header.h"

void venueList() {
	printf("\n\t\t\t\t\t\tList of venue category\n\t\t\t\t\t\t");
	doubleLine(10);
	printf("\t\t\t\t\t\t1.Library\n");
	printf("\t\t\t\t\t\t2.Lab\n");
	printf("\t\t\t\t\t\t3.Cafeteria\n");
	printf("\t\t\t\t\t\t4.Office\n");
	printf("\t\t\t\t\t\t5.Clinic\n");
	printf("\t\t\t\t\t\t6.Prayer Room\n");
	printf("\t\t\t\t\t\t7.Club and Society\n");
	printf("\t\t\t\t\t\t8.Hall\n");
	printf("\t\t\t\t\t\t9.Classroom\n");
	printf("\t\t\t\t\t\t10.Lecture Hall\n");
}




void menuVenue() {
	int choice;
	system("cls");
	loginHeader(5);
	printf("\n\n\t\t\tvvvvvvv           vvvvvvv eeeeeeeeeeee    nnnn  nnnnnnnn    uuuuuu    uuuuuu      eeeeeeeeeeee    \n");
	printf("\t\t\t v:::::v         v:::::vee::::::::::::ee  n:::nn::::::::nn  u::::u    u::::u    ee::::::::::::ee  \n");
	printf("\t\t\t  v:::::v       v:::::ve::::::eeeee:::::een::::::::::::::nn u::::u    u::::u   e::::::eeeee:::::ee\n");
	printf("\t\t\t   v:::::v     v:::::ve::::::e     e:::::enn:::::::::::::::nu::::u    u::::u  e::::::e     e:::::e\n");
	printf("\t\t\t    v:::::v   v:::::v e:::::::eeeee::::::e  n:::::nnnn:::::nu::::u    u::::u  e:::::::eeeee::::::e\n");
	printf("\t\t\t     v:::::v v:::::v  e:::::::::::::::::e   n::::n    n::::nu::::u    u::::u  e:::::::::::::::::e \n");
	printf("\t\t\t      v:::::v:::::v   e::::::eeeeeeeeeee    n::::n    n::::nu::::u    u::::u  e::::::eeeeeeeeeee  \n");
	printf("\t\t\t       v:::::::::v    e:::::::e             n::::n    n::::nu:::::uuuu:::::u  e:::::::e           \n");
	printf("\t\t\t        v:::::::v     e::::::::e            n::::n    n::::nu:::::::::::::::uue::::::::e          \n");
	printf("\t\t\t         v:::::v       e::::::::eeeeeeee    n::::n    n::::n u:::::::::::::::u e::::::::eeeeeeee  \n");
	printf("\t\t\t          v:::v         ee:::::::::::::e    n::::n    n::::n  uu::::::::uu:::u  ee:::::::::::::e  \n");
	printf("\t\t\t           vvv            eeeeeeeeeeeeee    nnnnnn    nnnnnn    uuuuuuuu  uuuu    eeeeeeeeeeeeee  \n\n");



	do {
		printf("\n\t\t\t\t\t\t|| (1) - Add new venue				\n");
		printf("\t\t\t\t\t\t|| (2) - Modify venue information		\n");
		printf("\t\t\t\t\t\t|| (3) - Display venue information		\n");
		printf("\t\t\t\t\t\t|| (4) - Search for venue			\n");
		printf("\t\t\t\t\t\t|| (5) - Reservation				\n");
		printf("\t\t\t\t\t\t|| (6) - Delete record				\n");
		printf("\t\t\t\t\t\t|| (7) - Exit module				\n");
		printf("\t\t\t\t\t\t|| (8) - Back				\n");
		printf("\n\t\t\t\t\t\tEnter your choice(1/2/3/4/5/6/7/8):");
		scanf("%d", &choice);
		rewind(stdin);

		switch (choice) {
		case 1:
			addVenue(); break;
		case 2:
			modifyVenue(); break;
		case 3:
			displayVenue(); break;
		case 4:
			searchVenue(); break;
		case 5:
			reserveVenue(); break;
		case 6:
			deleteVenue(); break;
		case 7:
			system("pause"); break;
		case 8:
			adminLoginMenu(); break;
		default:
			printf("\n\t\t\t\t\t\tError, unknown input\n"); break;
		}
	} while (choice != 7);
}

void addVenue() {
	char repeat;
	int cont = 0;
	system("cls");
	loginHeader(5);
	char checkCount[100], intCheck[10], inputName[50];
	int count = 0, catChoice = 0, dayChoiceStart = 0, dayChoiceEnd = 0, validResult = 0, validDate = 0, validDay = 0, exist = 0;
	FILE* fptrA, * fptrR;


	do {

		fptrA = fopen("venue.txt", "a");
		fptrR = fopen("venue.txt", "r");

		if (fptrA == NULL || fptrR == NULL) {
			printf("\t\t\t\t\t\tError, unable to open the file\n");
			exit(-1);
		}

		count = 0;

		while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\-]-%[^\t]\t%d-%d\t%[^\t]\t%d/%d/%d %d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {
			count++;
			printf("%d", count);

		}



		if (strcmp(v[0].venueID, "T%.3d", count) == 0) {
			count++;
		}

		venueList();

		do {
			do {
				printf("\n\t\t\t\t\t\tChoose T%.3d venue category:", count + 1);
				scanf("%s", &intCheck);
				rewind(stdin);

				//integer checking
				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			//convert the input from string to integer then copy to an integer variable
			catChoice = atoi(intCheck);

			switch (catChoice) {
			case 1:strcpy(&v[0].venueCat, "LIBRARY"); break;
			case 2:strcpy(&v[0].venueCat, "LAB"); break;
			case 3:strcpy(&v[0].venueCat, "CAFETERIA"); break;
			case 4:strcpy(&v[0].venueCat, "OFFICE"); break;
			case 5:strcpy(&v[0].venueCat, "CLINIC"); break;
			case 6:strcpy(&v[0].venueCat, "PRAYER ROOM"); break;
			case 7:strcpy(&v[0].venueCat, "CLUB AND SOCIETY"); break;
			case 8:strcpy(&v[0].venueCat, "HALL"); break;
			case 9:strcpy(&v[0].venueCat, "CLASSROOM"); break;
			case 10:strcpy(&v[0].venueCat, "LECTURE HALL"); break;
			default:printf("Invalid input\n"); break;
			}

		} while (catChoice > 10 || catChoice < 0);

		do {
			printf("\n\t\t\t\t\t\tEnter T%.3d venue name:", count + 1);
			scanf("%[^\n]", &inputName);
			rewind(stdin);

			strupr(inputName);

			//check if the name already exist in the text file
			for (int i = 0; i < count; i++) {
				if (strcmp(v[i].venueName, inputName) == 0) {
					printf("\t\t\t\t\t\tThe name already exist, please key in another name\n");
					exist = 1;
					break;
				}
				else
					exist = 0;

			}


		} while (exist == 1);

		strcpy(v[0].venueName, inputName);

		do {
			printf("\n\t\t\t\t\t\tEnter T%.3d venue maximum visitors allowed:", count + 1);
			scanf("%s", &intCheck);
			rewind(stdin);

			validResult = integerCheck(intCheck);

		} while (validResult == 0);

		v[0].maxVis = atoi(intCheck);

		do {
			printf("\t\t\t\t\t\tDay\n\t\t\t\t\t\t");
			doubleLine(3);
			printf("\t\t\t\t\t\t1.Monday\n");
			printf("\t\t\t\t\t\t2.Tuesday\n");
			printf("\t\t\t\t\t\t3.Wednesday\n");
			printf("\t\t\t\t\t\t4.Thursday\n");
			printf("\t\t\t\t\t\t5.Friday\n");
			printf("\t\t\t\t\t\t6.Saturday\n");
			printf("\t\t\t\t\t\t7.Sunday\n");

			do {
				printf("\n\t\t\t\t\t\tChoose T%.3d venue operating day start:", count + 1);
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			dayChoiceStart = atoi(intCheck);

			switch (dayChoiceStart) {
			case 1:strcpy(v[0].timeDay.day.opStartDay, "MONDAY"); validDay = 1; break;
			case 2:strcpy(v[0].timeDay.day.opStartDay, "TUESDAY"); validDay = 1; break;
			case 3:strcpy(v[0].timeDay.day.opStartDay, "WEDNESDAY"); validDay = 1; break;
			case 4:strcpy(v[0].timeDay.day.opStartDay, "THURSDAY"); validDay = 1; break;
			case 5:strcpy(v[0].timeDay.day.opStartDay, "FRIDAY"); validDay = 1; break;
			case 6:strcpy(v[0].timeDay.day.opStartDay, "SATURDAY"); validDay = 1; break;
			case 7:strcpy(v[0].timeDay.day.opStartDay, "SUNDAY"); validDay = 1; break;
			default:printf("Invalid input\n\n"); validDay = 0; break;
			}
		} while (validDay == 0);

		do {
			do {
				printf("\n\t\t\t\t\t\tChoose T%.3d venue operating day end:", count + 1);
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			dayChoiceEnd = atoi(intCheck);


			switch (dayChoiceEnd) {
			case 1:strcpy(v[0].timeDay.day.opEndDay, "MONDAY"); validDay = 1; break;
			case 2:strcpy(v[0].timeDay.day.opEndDay, "TUESDAY"); validDay = 1; break;
			case 3:strcpy(v[0].timeDay.day.opEndDay, "WEDNESDAY"); validDay = 1; break;
			case 4:strcpy(v[0].timeDay.day.opEndDay, "THURSDAY"); validDay = 1; break;
			case 5:strcpy(v[0].timeDay.day.opEndDay, "FRIDAY"); validDay = 1; break;
			case 6:strcpy(v[0].timeDay.day.opEndDay, "SATURDAY"); validDay = 1; break;
			case 7:strcpy(v[0].timeDay.day.opEndDay, "SUNDAY"); validDay = 1; break;
			default:printf("\t\t\t\t\t\tInvalid input\n\n"); validDay = 0; break;
			}

			if (dayChoiceStart >= dayChoiceEnd) {
				printf("\t\t\t\t\t\tError, day end should not be earlier than day start\n");
				validDay = 0;
			}

		} while (validDay == 0);

		do {
			do {
				printf("\n\t\t\t\t\t\tEnter T%.3d venue operation start time in 24 hour format(hhmm):", count + 1);
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			v[0].timeDay.opStartTime = atoi(intCheck);

			do {
				printf("\n\t\t\t\t\t\tEnter T%.3d venue operation end time in 24 hour format(hhmm):", count + 1);
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			v[0].timeDay.opEndTime = atoi(intCheck);

			if (v[0].timeDay.opEndTime <= v[0].timeDay.opStartTime)
				printf("\t\t\t\t\t\tend time must not be earlier than start time, please enter again\n");

			else if (v[0].timeDay.opStartTime < 700)
				printf("\t\t\t\t\t\tToo early, the school still not yet open\n");


		} while (v[0].timeDay.opEndTime <= v[0].timeDay.opStartTime || v[0].timeDay.opStartTime < 700);
		do {
			printf("\n\t\t\t\t\t\tEnter the last sanitization date(yyyy/mm/dd):");
			scanf("%d/%d/%d", &v[0].saniTime.saniYear, &v[0].saniTime.saniMonth, &v[0].saniTime.saniDay);
			rewind(stdin);

			//check year
			if (v[0].saniTime.saniYear >= 1900 && v[0].saniTime.saniYear <= 9999)
			{
				//check month
				if (v[0].saniTime.saniMonth >= 1 && v[0].saniTime.saniMonth <= 12)
				{
					//check days in the month
					if ((v[0].saniTime.saniDay >= 1 && v[0].saniTime.saniDay <= 31) && (v[0].saniTime.saniMonth == 1 || v[0].saniTime.saniMonth == 3 || v[0].saniTime.saniMonth == 5 || v[0].saniTime.saniMonth == 7 || v[0].saniTime.saniMonth == 8 || v[0].saniTime.saniMonth == 10 || v[0].saniTime.saniMonth == 12)) {
						printf("Date is valid.\n");
						validDate = 1;
					}
					else if ((v[0].saniTime.saniDay >= 1 && v[0].saniTime.saniDay <= 30) && (v[0].saniTime.saniMonth == 4 || v[0].saniTime.saniMonth == 6 || v[0].saniTime.saniMonth == 9 || v[0].saniTime.saniMonth == 11)) {
						printf("Date is valid.\n");
						validDate = 1;
					}
					else if ((v[0].saniTime.saniDay >= 1 && v[0].saniTime.saniDay <= 28) && (v[0].saniTime.saniMonth == 2)) {
						printf("Date is valid.\n");
						validDate = 1;
					}
					else if (v[0].saniTime.saniDay == 29 && v[0].saniTime.saniMonth == 2 && (v[0].saniTime.saniDay % 400 == 0 || (v[0].saniTime.saniDay % 4 == 0 && v[0].saniTime.saniDay % 100 != 0))) {
						printf("Date is valid.\n");
						validDate = 1;
					}
					else {
						printf("Day is invalid.\n");
						validDate = 0;
					}
				}
				else {
					printf("Month is not valid.\n");
					validDate = 0;
				}
			}
			else {
				printf("Year is not valid.\n");
				validDate = 0;
			}
		} while (validDate == 0);

		strcpy(v[0].status, "AVAILABLE");
		v[0].currentVisitors = 0;

		fprintf(fptrA, "T%.3d\t%s\t%s\t%d\t%s-%s\t%d-%d\t%s\t%d/%d/%d\t%d\n", count + 1, v[0].venueCat, v[0].venueName, v[0].maxVis, v[0].timeDay.day.opStartDay, v[0].timeDay.day.opEndDay, v[0].timeDay.opStartTime, v[0].timeDay.opEndTime, v[0].status, v[0].saniTime.saniYear, v[0].saniTime.saniMonth, v[0].saniTime.saniDay, v[0].currentVisitors);

		fclose(fptrA);

		system("cls");
		loginHeader(5);

		printf("Successfully entered a new venue\n\n");
		printf("Venue ID\tVenue category\t\tVenue description\tVenue maximum visitor allowed\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
		doubleLine(211);
		while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%[^\t]\t%d/%d/%d\t%d\n", &v[0].venueID, &v[0].venueCat, &v[0].venueName, &v[0].maxVis, &v[0].timeDay.day.opStartDay, &v[0].timeDay.day.opEndDay, &v[0].timeDay.opStartTime, &v[0].timeDay.opEndTime, &v[0].status, &v[0].saniTime.saniYear, &v[0].saniTime.saniMonth, &v[0].saniTime.saniDay, &v[0].currentVisitors) != EOF) {
			printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[0].venueID, v[0].venueCat, v[0].venueName, v[0].maxVis, v[0].currentVisitors, v[0].timeDay.day.opStartDay, &v[0].timeDay.day.opEndDay, v[0].timeDay.opStartTime, v[0].timeDay.opEndTime, v[0].status, v[0].saniTime.saniYear, v[0].saniTime.saniMonth, v[0].saniTime.saniDay);
		}
		printf("\nDo you want to add another venue?(y/n):");
		scanf("%c", &repeat);
		rewind(stdin);

		if (toupper(repeat) == 'Y')
			cont = 1;

		else if (toupper(repeat) == 'N') {
			cont = 0;
			system("cls");
			loginHeader(5);
			return 0;
		}

	} while (cont == 1);
	fclose(fptrR);
}

void modifyVenue() {

	char checkId[50], code[10], cat[50], name[50], confirmation, cont = 0, intCheck[10], dayStart[10], dayEnd[10];
	int i = 0, count = 0, found = 0, maxVis = 0, choice = 0, chooseStart = 0, chooseEnd = 0, catChoice = 0, validResult = 0, chooseDayStart = 0, chooseDayEnd = 0, sYear = 0, sMonth = 0, sDay = 0, validDate = 0, existName = 0;
	FILE* fptrR;
	fptrR = fopen("venue.txt", "r");

	if (fptrR == NULL) {
		printf("Error, unable to open the file\n");
		exit(-1);
	}

	while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%[^\t]\t%d/%d/%d\t%d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {
		count++;
	}

	do {
		system("cls");
		loginHeader(5);

		printf("List of venue\n");
		doubleLine(10);
		printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
		doubleLine(211);

		for (i = 0; i < count; i++) {
			printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
		}

		printf("\t\t\t\t\t\t\nEnter the venue Id you wish to modify:");
		scanf("%s", &code);
		rewind(stdin);

		system("cls");
		loginHeader(5);
		strupr(code);

		for (i = 0; i < count; i++) {
			if (strcmp(v[i].venueID, code) == 0) {
				found = 1;
				printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);
				printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
				printf("\n\t\t\t\t\t\tModify menu\n\t\t\t\t\t\t");
				doubleLine(11);
				printf("\t\t\t\t\t\t1.Change venue category\n");
				printf("\t\t\t\t\t\t2.Change venue name\n");
				printf("\t\t\t\t\t\t3.Change venue maximum visitor allowed\n");
				printf("\t\t\t\t\t\t4.Change operation day\n");
				printf("\t\t\t\t\t\t5.Change venue operation time\n");
				printf("\t\t\t\t\t\t6.Change last sanitization date\n");
				printf("\t\t\t\t\t\t7.Modify all\n");
				printf("\t\t\t\t\t\t8.Return to main menu\n\n");
				printf("\t\t\t\t\t\tWhat do you want to modify? (1/2/3/4/5/6/7):");
				scanf("%d", &choice);
				rewind(stdin);
			}
		}

		if (choice == 1) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					venueList();
					do {
						do {
							printf("\n\t\t\t\t\t\tChoose the venue category:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						catChoice = atoi(intCheck);

						switch (catChoice) {
						case 1:strcpy(cat, "LIBRARY"); break;
						case 2:strcpy(cat, "LAB"); break;
						case 3:strcpy(cat, "CAFETERIA"); break;
						case 4:strcpy(cat, "OFFICE"); break;
						case 5:strcpy(cat, "CLINIC"); break;
						case 6:strcpy(cat, "PRAYER ROOM"); break;
						case 7:strcpy(cat, "CLUB AND SOCIETY"); break;
						case 8:strcpy(cat, "HALL"); break;
						case 9:strcpy(cat, "CLASSROOM"); break;
						case 10:strcpy(cat, "LECTURE HALL"); break;
						default:printf("Invalid input\n"); break;
						}

					} while (catChoice > 10 || catChoice < 0);

					printf("\n\t\t\t\t\t\tAre you sure you want to modify the data?(y/n):");
					scanf("%c", &confirmation);
					rewind(stdin);

					if (toupper(confirmation) == 'Y') {
						strcpy(v[i].venueCat, cat);
						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 2) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					do {
						printf("\t\t\t\t\t\tEnter the new venue name:");
						scanf("%[^\n]", &name);
						rewind(stdin);

						strupr(name);
						for (int c = 0; c < count; c++) {
							if (strcmp(name, v[c].venueName) == 0) {
								printf("\t\t\t\t\t\tThe name already exist, please key in another name\n");
								existName = 1;
								break;

							}
							else existName = 0;
						}
					} while (existName == 1);

					printf("\t\t\t\t\t\tAre you sure you want to modify the data?(Y/N):");
					scanf("%c", &confirmation);
					rewind(stdin);

					if (toupper(confirmation) == 'Y') {
						strcpy(v[i].venueName, name);
						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 3) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					do {
						printf("\t\t\t\t\t\tEnter the new venue maximum visitor allowed");
						scanf("%s", &intCheck);
						rewind(stdin);

						validResult = integerCheck(intCheck);

					} while (validResult == 0);

					maxVis = atoi(intCheck);

					printf("\t\t\t\t\t\tAre you sure you want to modify the data?(Y/N):");
					scanf("%c", &confirmation);
					rewind(stdin);
					if (toupper(confirmation) == 'Y') {
						v[i].maxVis = maxVis;
						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 4) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					printf("Day\n\t\t\t\t\t\t");
					doubleLine(3);
					printf("1.Monday\n");
					printf("2.Tuesday\n");
					printf("3.Wednesday\n");
					printf("4.Thursday\n");
					printf("5.Friday\n");
					printf("6.Saturday\n");
					printf("7.Sunday\n\t");

					do {
						do {
							printf("\t\t\t\t\t\tChoose the venue operating day start:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseDayStart = atoi(intCheck);

						switch (chooseDayStart) {
						case 1:strcpy(dayStart, "MONDAY"); break;
						case 2:strcpy(dayStart, "TUESDAY"); break;
						case 3:strcpy(dayStart, "WEDNESDAY"); break;
						case 4:strcpy(dayStart, "THURSDAY"); break;
						case 5:strcpy(dayStart, "FRIDAY"); break;
						case 6:strcpy(dayStart, "SATURDAY"); break;
						case 7:strcpy(dayStart, "SUNDAY"); break;
						default:printf("Invalid input\n"); break;
						}

						do {
							printf("\t\t\t\t\t\tChoose the venue operating day end:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseDayEnd = atoi(intCheck);

						switch (chooseDayEnd) {
						case 1:strcpy(dayEnd, "MONDAY"); break;
						case 2:strcpy(dayEnd, "TUESDAY"); break;
						case 3:strcpy(dayEnd, "WEDNESDAY"); break;
						case 4:strcpy(dayEnd, "THURSDAY"); break;
						case 5:strcpy(dayEnd, "FRIDAY"); break;
						case 6:strcpy(dayEnd, "SATURDAY"); break;
						case 7:strcpy(dayEnd, "SUNDAY"); break;
						default:printf("Invalid input\n"); break;
						}
					} while (chooseDayStart < 1 || chooseDayStart>7 || chooseDayEnd < 1 || chooseDayEnd>7);

					printf("\t\t\t\t\t\tAre you sure you want to modify the data?(Y/N):");
					scanf("%c", &confirmation);
					rewind(stdin);

					if (toupper(confirmation) == 'Y') {
						strcpy(&v[i].timeDay.day.opStartDay, dayStart);
						strcpy(&v[i].timeDay.day.opEndDay, dayEnd);
						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 5) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					do {
						do {
							printf("\t\t\t\t\t\tEnter the venue operation start time in 24 hour format (hhmm):");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseStart = atoi(intCheck);

						do {
							printf("\t\t\t\t\t\tEnter venue operation end time in 24 hour format (hhmm):");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseEnd = atoi(intCheck);

						if (chooseEnd <= chooseStart)
							printf("\t\t\t\t\t\tend time must not be earlier than start time, please enter again\n");
						else if (chooseStart < 700)
							printf("\t\t\t\t\t\tToo early, the school still not yet open\n");


					} while (chooseEnd <= chooseStart || chooseStart < 700);

					printf("Are you sure you want to modify the data?(Y/N):");
					scanf("%c", &confirmation);
					rewind(stdin);

					if (toupper(confirmation) == 'Y') {
						v[i].timeDay.opStartTime = chooseStart;
						v[i].timeDay.opEndTime = chooseEnd;

						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 6) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					do {
						printf("Enter the last sanitization date in (yyyy/mm/dd):");
						scanf("%d/%d/%d", &sYear, &sMonth, &sDay);
						rewind(stdin);

						//check year
						if (sYear >= 1900 && sYear <= 9999)
						{
							//check month
							if (sMonth >= 1 && sMonth <= 12)
							{
								//check days in the month
								if ((sDay >= 1 && sDay <= 31) && (sMonth == 1 || sMonth == 3 || sMonth == 5 || sMonth == 7 || sMonth == 8 || sMonth == 10 || sMonth == 12)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((sDay >= 1 && sDay <= 30) && (sMonth == 4 || sMonth == 6 || sMonth == 9 || sMonth == 11)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((sDay >= 1 && sDay <= 28) && (sMonth == 2)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if (sDay == 29 && sMonth == 2 && (sDay % 400 == 0 || (sDay % 4 == 0 && sDay % 100 != 0))) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else {
									printf("Day is invalid.\n");
									validDate = 0;
								}
							}
							else {
								printf("Month is not valid.\n");
								validDate = 0;
							}
						}
						else {
							printf("Year is not valid.\n");
							validDate = 0;
						}
					} while (validDate == 0);

					if (validDate == 1) {
						printf("\nAre you sure you want to modify the data?(Y/N):");
						scanf("%c", &confirmation);
						rewind(stdin);

						v[i].saniTime.saniYear = sYear;
						v[i].saniTime.saniMonth = sMonth;
						v[i].saniTime.saniDay = sDay;

						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 7) {
			for (i = 0; i < count; i++) {
				if (strcmp(code, v[i].venueID) == 0) {
					found = 1;
					system("cls");
					loginHeader(5);
					venueList();

					do {
						do {
							printf("\t\t\t\t\t\tChoose the venue category:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						catChoice = atoi(intCheck);

						switch (catChoice) {
						case 1:strcpy(cat, "LIBRARY"); break;
						case 2:strcpy(cat, "LAB"); break;
						case 3:strcpy(cat, "CAFETERIA"); break;
						case 4:strcpy(cat, "OFFICE"); break;
						case 5:strcpy(cat, "CLINIC"); break;
						case 6:strcpy(cat, "PRAYER ROOM"); break;
						case 7:strcpy(cat, "CLUB AND SOCIETY"); break;
						case 8:strcpy(cat, "HALL"); break;
						case 9:strcpy(cat, "CLASSROOM"); break;
						case 10:strcpy(cat, "LECTURE HALL"); break;
						default:printf("Invalid input\n"); break;
						}

					} while (catChoice > 10 || catChoice < 0);

					do {
						printf("\t\t\t\t\t\tEnter the new venue name:");
						scanf("%[^\n]", &name);
						rewind(stdin);

						strupr(name);
						for (int c = 0; c < count; c++) {
							if (strcmp(name, v[c].venueName) == 0) {
								printf("\t\t\t\t\t\tThe name already exist, please key in another name\n");
								existName = 1;
								break;

							}
							else existName = 0;
						}
					} while (existName == 1);

					do {
						printf("\n\t\t\t\t\t\tEnter the new venue maximum visitor allowed:");
						scanf("%s", &intCheck);
						rewind(stdin);

						validResult = integerCheck(intCheck);

					} while (validResult == 0);

					maxVis = atoi(intCheck);
					printf("\n\t\t\t\t\t\tDay\n\t\t\t\t\t\t");
					doubleLine(3);
					printf("\n\t\t\t\t\t\t1.Monday\n");
					printf("\t\t\t\t\t\t2.Tuesday\n");
					printf("\t\t\t\t\t\t3.Wednesday\n");
					printf("\t\t\t\t\t\t4.Thursday\n");
					printf("\t\t\t\t\t\t5.Friday\n");
					printf("\t\t\t\t\t\t6.Saturday\n");
					printf("\t\t\t\t\t\t7.Sunday\n");

					do {
						do {
							printf("\n\t\t\t\t\t\tChoose the venue operating day start:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseDayStart = atoi(intCheck);

						switch (chooseDayStart) {
						case 1:strcpy(dayStart, "MONDAY"); break;
						case 2:strcpy(dayStart, "TUESDAY"); break;
						case 3:strcpy(dayStart, "WEDNESDAY"); break;
						case 4:strcpy(dayStart, "THURSDAY"); break;
						case 5:strcpy(dayStart, "FRIDAY"); break;
						case 6:strcpy(dayStart, "SATURDAY"); break;
						case 7:strcpy(dayStart, "SUNDAY"); break;
						default:printf("Invalid input\n"); break;
						}

						do {
							printf("\n\t\t\t\t\t\tChoose the venue operating day end:");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseDayEnd = atoi(intCheck);

						switch (chooseDayEnd) {
						case 1:strcpy(dayEnd, "MONDAY"); break;
						case 2:strcpy(dayEnd, "TUESDAY"); break;
						case 3:strcpy(dayEnd, "WEDNESDAY"); break;
						case 4:strcpy(dayEnd, "THURSDAY"); break;
						case 5:strcpy(dayEnd, "FRIDAY"); break;
						case 6:strcpy(dayEnd, "SATURDAY"); break;
						case 7:strcpy(dayEnd, "SUNDAY"); break;
						default:printf("Invalid input\n"); break;
						}
					} while (chooseDayStart < 1 || chooseDayStart>7 || chooseDayEnd < 1 || chooseDayEnd>7);

					do {
						do {
							printf("\n\t\t\t\t\t\tEnter the venue operation start time in 24 hour format (hhmm):");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseStart = atoi(intCheck);

						do {
							printf("\n\t\t\t\t\t\tEnter the venue operation end time in 24 hour format (hhmm):");
							scanf("%s", &intCheck);
							rewind(stdin);

							validResult = integerCheck(intCheck);

						} while (validResult == 0);

						chooseEnd = atoi(intCheck);

						if (chooseEnd <= chooseStart)
							printf("\n\t\t\t\t\t\tend time must not be earlier than start time, please enter again\n");
						else if (chooseStart < 700)
							printf("\n\t\t\t\t\t\tToo early, the school still not yet open\n");


					} while (chooseEnd <= chooseStart || chooseStart < 700);

					do {
						printf("\n\t\t\t\t\t\tEnter the last sanitization date in (yyyy/mm/dd):");
						scanf("%d/%d/%d", &sYear, &sMonth, &sDay);
						rewind(stdin);

						//check year
						if (sYear >= 1900 && sYear <= 9999)
						{
							//check month
							if (sMonth >= 1 && sMonth <= 12)
							{
								//check days in the month
								if ((sDay >= 1 && sDay <= 31) && (sMonth == 1 || sMonth == 3 || sMonth == 5 || sMonth == 7 || sMonth == 8 || sMonth == 10 || sMonth == 12)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((sDay >= 1 && sDay <= 30) && (sMonth == 4 || sMonth == 6 || sMonth == 9 || sMonth == 11)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((sDay >= 1 && sDay <= 28) && (sMonth == 2)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if (sDay == 29 && sMonth == 2 && (sDay % 400 == 0 || (sDay % 4 == 0 && sDay % 100 != 0))) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else {
									printf("Day is invalid.\n");
									validDate = 0;
								}
							}
							else {
								printf("Month is not valid.\n");
								validDate = 0;
							}
						}
						else {
							printf("Year is not valid.\n");
							validDate = 0;
						}
					} while (validDate == 0);

					printf("\n\t\t\t\t\t\tAre you sure you want to modify the data?(Y/N):");
					scanf("%c", &confirmation);
					rewind(stdin);

					if (toupper(confirmation) == 'Y') {
						strcpy(v[i].venueCat, cat);
						strcpy(v[i].venueName, name);
						v[i].maxVis = maxVis;
						strcpy(&v[i].timeDay.day.opStartDay, dayStart);
						strcpy(&v[i].timeDay.day.opEndDay, dayEnd);
						v[i].timeDay.opStartTime = chooseStart;
						v[i].timeDay.opEndTime = chooseEnd;
						v[i].saniTime.saniYear = sYear;
						v[i].saniTime.saniMonth = sMonth;
						v[i].saniTime.saniDay = sDay;

						system("cls");
						loginHeader(5);
						printf("Updated record\n");
						printf("\nVenue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
						doubleLine(211);
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

					}
				}
			}
		}
		else if (choice == 8) {
			system("cls");
			loginHeader(5);

			return 0;
		}
		if (strcmp(code, v[i].venueID) == 0)
			printf("Id not found\n");

		FILE* fptrW;
		fptrW = fopen("venue.txt", "w");

		if (fptrW == NULL) {
			printf("\t\t\t\t\t\tError, unable to open the file\n");
			exit(-1);
		}

		for (i = 0; i < count; i++) {
			fprintf(fptrW, "%s\t%s\t%s\t%d\t%s-%s\t%d-%d\t%s\t%d/%d/%d\t%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].timeDay.day.opStartDay, v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay, v[i].currentVisitors);
		}
		fclose(fptrW);

		printf("\n\t\t\t\t\t\tDo you want to modify other venue information?(y/n):");
		scanf("%c", &cont);
		rewind(stdin);

		if (toupper(cont) == 'N') {
			system("cls");
			loginHeader(5);

			return 0;
		}

	} while (toupper(cont) == 'Y');

	fclose(fptrR);
}

void searchVenue() {
	system("cls");

	char search[100], repeat = 0, intCheck[10];
	int i = 0, count = 0, choice, searchInt = 0, result = 0, opChoice = 0, validResult = 0, catSearch = 0, dayChoice = 0, saniDayChoice = 0, foundCount = 0;

	FILE* fptrR;
	fptrR = fopen("venue.txt", "r");

	if (fptrR == NULL) {
		printf("\t\t\t\t\t\tError, unable to open the file\n");
		exit(-1);
	}

	while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%[^\t]\t%d/%d/%d\t%d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {
		count++;
	}

	do {
		foundCount = 0;
		system("cls");
		loginHeader(5);
		printf("\n\t\t\t\t\t\tType of search field\n\t\t\t\t\t\t");
		doubleLine(20);
		printf("\t\t\t\t\t\t1.Venue category\n");
		printf("\t\t\t\t\t\t2.Venue name\n");
		printf("\t\t\t\t\t\t3.Venue maximum visitor allowed\n");
		printf("\t\t\t\t\t\t4.Venue operating day\n");
		printf("\t\t\t\t\t\t5.Venue last sanitization date\n");
		printf("\t\t\t\t\t\t6.Venue operating time\n");
		printf("\t\t\t\t\t\t7.Exit to main menu\n");

		printf("\n\t\t\t\t\t\tEnter your choice):");
		scanf("%d", &choice);
		rewind(stdin);

		if (choice == 1) {
			system("cls");
			loginHeader(5);
			venueList();

			do {
				do {
					printf("\n\t\t\t\t\t\tChoose the venue category:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);

				} while (validResult == 0);

				catSearch = atoi(intCheck);

				switch (catSearch) {
				case 1:strcpy(search, "LIBRARY"); break;
				case 2:strcpy(search, "LAB"); break;
				case 3:strcpy(search, "CAFETERIA"); break;
				case 4:strcpy(search, "OFFICE"); break;
				case 5:strcpy(search, "CLINIC"); break;
				case 6:strcpy(search, "PRAYER ROOM"); break;
				case 7:strcpy(search, "CLUB AND SOCIETY"); break;
				case 8:strcpy(search, "HALL"); break;
				case 9:strcpy(search, "CLASSROOM"); break;
				case 10:strcpy(search, "LECTURE HALL"); break;
				default:printf("Invalid input\n"); break;
				}
			} while (catSearch > 10 || catSearch < 0);

			printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
			doubleLine(211);
			for (i = 0; i < count; i++) {
				if (strcmp(search, v[i].venueCat) == 0) {


					printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
					result = 1;
					foundCount++;
				}
			}
			printf("%d record found\n", foundCount);
		}
		else if (choice == 2) {
			printf("Enter the venue name:");
			scanf("%[^\n]", &search);
			rewind(stdin);

			strupr(search);
			printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
			doubleLine(211);
			for (i = 0; i < count; i++) {
				if (strcmp(search, v[i].venueName) == 0) {

					printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
					result = 1;
					foundCount++;
				}
			}
			printf("%d record found\n", foundCount);
		}
		else if (choice == 3) {
			do {
				printf("Enter the number of visitor allowed :");
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			searchInt = atoi(intCheck);


			printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
			doubleLine(211);
			for (i = 0; i < count; i++) {
				if (searchInt == v[i].maxVis) {
					printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
					result = 1;
					foundCount++;
				}
			}
			printf("%d record found\n", foundCount);

		}
		else if (choice == 4) {
			do {
				printf("1.Search operating day start\n");
				printf("2.Search operating day end\n");
				printf("3.Which one do you want to search?(1/2):");
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);

			} while (validResult == 0);

			opChoice = atoi(intCheck);

			if (opChoice == 1) {
				printf("1.Monday\n");
				printf("2.Tuesday\n");
				printf("3.Wednesday\n");
				printf("4.Thursday\n");
				printf("5.Friday\n");
				printf("6.Saturday\n");
				printf("7.Sunday\n");

				do {
					printf("Choose	the venue operating day start:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);

				} while (validResult == 0);

				searchInt = atoi(intCheck);

				switch (searchInt) {
				case 1:strcpy(search, "MONDAY"); break;
				case 2:strcpy(search, "TUESDAY"); break;
				case 3:strcpy(search, "WEDNESDAY"); break;
				case 4:strcpy(search, "THURSDAY"); break;
				case 5:strcpy(search, "FRIDAY"); break;
				case 6:strcpy(search, "SATURDAY"); break;
				case 7:strcpy(search, "SUNDAY"); break;
				default:printf("Invalid input\n"); break;
				}
				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);
				for (i = 0; i < count; i++) {
					if (strcmp(search, v[i].timeDay.day.opStartDay) == 0) {
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;
					}
				}
				printf("%d record found\n", foundCount);


			}
			else if (opChoice == 2) {
				printf("1.Monday\n");
				printf("2.Tuesday\n");
				printf("3.Wednesday\n");
				printf("4.Thursday\n");
				printf("5.Friday\n");
				printf("6.Saturday\n");
				printf("7.Sunday\n");

				do {
					printf("Choose	the venue operating day start:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);

				} while (validResult == 0);

				searchInt = atoi(intCheck);

				switch (searchInt) {
				case 1:strcpy(search, "MONDAY"); break;
				case 2:strcpy(search, "TUESDAY"); break;
				case 3:strcpy(search, "WEDNESDAY"); break;
				case 4:strcpy(search, "THURSDAY"); break;
				case 5:strcpy(search, "FRIDAY"); break;
				case 6:strcpy(search, "SATURDAY"); break;
				case 7:strcpy(search, "SUNDAY"); break;
				default:printf("Invalid input\n"); break;
				}
				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);

				for (i = 0; i < count; i++) {
					if (strcmp(search, v[i].timeDay.day.opStartDay) == 0) {
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;
					}
				}
				printf("%d record found\n", foundCount);

			}

		}
		else if (choice == 5) {
			do {
				printf("Choices");
				doubleLine(7);
				printf("1.year\n");
				printf("2.month\n");
				printf("3.Day\n");
				printf("\nSelect your choice:");
				scanf("%s", intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);
			} while (validResult == 0);

			saniDayChoice = atoi(intCheck);

			if (saniDayChoice == 1) {
				do {
					printf("Enter the year of the last sanitization date:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);
				} while (validResult == 0);

				searchInt = atoi(intCheck);

				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);

				for (i = 0; i < count; i++) {
					if (searchInt == v[i].saniTime.saniYear) {
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;;
					}
				}
				printf("%d record found\n", foundCount);

			}
			else if (saniDayChoice == 2) {
				do {
					printf("Enter the month of the last sanitization date:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);
				} while (validResult == 0);

				searchInt = atoi(intCheck);
				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);

				for (i = 0; i < count; i++) {
					if (searchInt == v[i].saniTime.saniMonth) {
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;

					}
				}
				printf("\n%d record found\n", foundCount);

			}
			else if (saniDayChoice == 3) {
				do {
					printf("Enter the month of the last sanitization date:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);
				} while (validResult == 0);

				searchInt = atoi(intCheck);

				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);

				for (i = 0; i < count; i++) {
					if (searchInt == v[i].saniTime.saniDay) {

						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;

					}
				}
				printf("\n%d record found\n", foundCount);
			}

		}
		else if (choice == 6) {
			do {
				printf("\t\t\t\t\t\tOperating Time\n\t\t\t\t\t\t");
				doubleLine(10);
				printf("\t\t\t\t\t\t1.Operating time start\n");
				printf("\t\t\t\t\t\t2.Operating time end\n\n");
				printf("\t\t\t\t\t\tdo you want to search operating time start or operating time end?:");
				scanf("%s", &intCheck);
				rewind(stdin);

				validResult = integerCheck(intCheck);
			} while (validResult == 0);

			opChoice = atoi(intCheck);

			system("cls");

			loginHeader(5);

			if (opChoice == 1) {
				do {
					printf("\t\t\t\t\t\tEnter venue operation start time in 24hr format:");
					scanf("%s", &intCheck);
					rewind(stdin);

					validResult = integerCheck(intCheck);

				} while (validResult == 0);

				searchInt = atoi(intCheck);
				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);
				for (i = 0; i < count; i++) {
					if (searchInt == v[i].timeDay.opStartTime) {

						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
						foundCount++;
					}
				}
				printf("\n%d record found\n", foundCount);
			}
			else if (opChoice == 2) {
				do {
					printf("Enter venue operation end time:");
					scanf("%s", &intCheck);

					validResult = integerCheck(intCheck);

				} while (validResult == 0);

				searchInt = atoi(intCheck);
				printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
				doubleLine(211);
				for (i = 0; i < count; i++) {
					if (searchInt == v[i].timeDay.opEndTime) {
						printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);
						result = 1;
					}
				}
				printf("\n%d record found\n", foundCount);

			}
		}
		else if (choice == 7) {
			system("cls");
			loginHeader(5);

			return 0;
			break;

		}
		if (result == 0)
			printf("\t\t\t\t\t\tthe item you searched is not found\n");

		printf("\t\t\t\t\t\tdo you want to do another search ? (y / n) : ");
		scanf("%c", &repeat);

		if (toupper(repeat) == 'N') {
			system("cls");
			loginHeader(5);
			return 0;
		}

	} while (toupper(repeat) == 'Y');

	fclose(fptrR);
}

void displayVenue() {

	FILE* fptrR, * binR;
	fptrR = fopen("venue.txt", "r");
	binR = fopen("reserve.bin", "rb");
	int i = 0, recordChoice = 0, validInput = 0, count = 0, confirm = 0;
	char intCheck[10], confirmation;

	if (fptrR == NULL || binR == 0) {
		printf("Error, unable to open the file\n");
		exit(-1);
	}

	while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%s\t%d/%d/%d\t%d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {
		updateStatus(&v[count].status);
		count++;
	}


	do {
		system("cls");
		loginHeader(5);
		do {
			printf("\t\t\t\t\t\tRecord type\n");

			printf("\t\t\t\t\t\t1.Venue information\n");
			printf("\t\t\t\t\t\t2.Venue reservation\n\n");
			printf("\t\t\t\t\t\tEnter your choice:");
			scanf("%s", &intCheck);
			rewind(stdin);

			validInput = integerCheck(intCheck);

		} while (validInput == 0);

		recordChoice = atoi(intCheck);

		if (recordChoice == 1) {

			printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
			doubleLine(220);

			for (i = 0; i < count; i++) {

				printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

			}

			fclose(fptrR);
		}
		else if (recordChoice == 2) {
			printf("Venue Id\tVenue reserve date\tVenuereserve time\tReason\n");
			doubleLine(100);
			while (fread(&reserveV[i], sizeof(reserve), 1, binR) != 0) {

				printf("%-10s\t%d/%d/%d\t\t%.2d.%.2d-%.2d.%.2d\t\t%s\n\n", reserveV[i].venueId, reserveV[i].reserveYear, reserveV[i].reserveMonth, reserveV[i].reserveDay, reserveV[i].reserveStartHr, reserveV[i].reserveStartMin, reserveV[i].reserveEndHr, reserveV[i].reserveEndMin, reserveV[i].reserveReason);
				i++;

			}
			fclose(binR);
		}
		else
			printf("\t\t\t\t\t\tInvalid input\n");

		do {
			printf("\t\t\t\t\t\tDo you want to display again?(y/n):");
			scanf("%c", &confirmation);
			rewind(stdin);

			if (toupper(confirmation) == 'Y')
				confirm = 1;
			else if (toupper(confirmation) == 'N') {
				system("cls");
				loginHeader(5);
				return 0;
			}
			else {
				printf("\t\t\t\t\t\tInvalid input\n");
				confirm = 0;
			}
		} while (confirm == 0);
	} while (toupper(confirmation) == 'Y');
}

void reserveVenue() {
	system("cls");
	loginHeader(5);
	int i = 0, count = 0, rYear = 0, rMonth = 0, rDay = 0, rStartTime = 0, rStartHr = 0, rStartMin = 0, rEndTime = 0, rEndHr = 0, rEndMin = 0, bCount = 0, validDate = 0, existence = 0;
	char choice[5];
	FILE* fptrR, * fptr, * binR;
	fptrR = fopen("venue.txt", "r");
	fptr = fopen("reserve.bin", "ab");
	binR = fopen("reserve.bin", "rb");

	if (fptr == NULL && fptrR == NULL && binR == NULL) {
		printf("Error, unable to open the file\n");
		exit(-1);
	}
	//get system time
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
	doubleLine(220);
	while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%[^\t]\t%d/%d/%d\t%d\n", &v[count].venueID, &v[count].venueCat, &v[count].venueName, &v[count].maxVis, &v[count].timeDay.day.opStartDay, &v[count].timeDay.day.opEndDay, &v[count].timeDay.opStartTime, &v[count].timeDay.opEndTime, &v[count].status, &v[count].saniTime.saniYear, &v[count].saniTime.saniMonth, &v[count].saniTime.saniDay, &v[count].currentVisitors) != EOF) {
		count++;
	}

	for (i = 0; i < count; i++) {
		printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

	}



	printf("Which venue do you wish to make reservation?:");
	scanf(" %s", &choice);
	rewind(stdin);

	strupr(choice);

	while (fread(&reserveV[bCount], sizeof(reserve), 1, binR) != 0) {
		bCount++;
	}

	for (i = 0; i < count; i++) {
		if (strcmp(choice, v[i].venueID) == 0) {
			system("cls");
			loginHeader(5);
			printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
			doubleLine(230);
			printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[i].venueID, v[i].venueCat, v[i].venueName, v[i].maxVis, v[i].currentVisitors, v[i].timeDay.day.opStartDay, &v[i].timeDay.day.opEndDay, v[i].timeDay.opStartTime, v[i].timeDay.opEndTime, v[i].status, v[i].saniTime.saniYear, v[i].saniTime.saniMonth, v[i].saniTime.saniDay);

			do {
				printf("\n\t\t\t\t\t\tEnter which day you want to reserve (yyyy/mm/dd):");
				scanf("%d/%d/%d", &rYear, &rMonth, &rDay);
				rewind(stdin);



				//check year
				if (rYear >= tm.tm_year && rYear <= 2030)
				{
					//check month
					if (rMonth >= 1 && rMonth <= 12)
					{
						if (rMonth > tm.tm_mon + 1) {
							//check days
							if ((rDay >= 1 && rDay <= 31) && (rMonth == 1 || rMonth == 3 || rMonth == 5 || rMonth == 7 || rMonth == 8 || rMonth == 10 || rMonth == 12)) {
								printf("Date is valid.\n");
								validDate = 1;
							}
							else if ((rDay >= 1 && rDay <= 30) && (rMonth == 4 || rMonth == 6 || rMonth == 9 || rMonth == 11)) {
								printf("Date is valid.\n");
								validDate = 1;
							}
							else if ((rDay >= 1 && rDay <= 28) && (rMonth == 2)) {
								printf("Date is valid.\n");
								validDate = 1;
							}
							else if (rDay == 29 && rMonth == 2 && (rYear % 400 == 0 || (rYear % 4 == 0 && rYear % 100 != 0))) {
								printf("Date is valid.\n");
								validDate = 1;
							}
							else {
								printf("Day is invalid.\n");
								validDate = 0;
							}
						}
						else if (rMonth == tm.tm_mon + 1) {
							if (rDay > tm.tm_mday) {
								if ((rDay >= 1 && rDay <= 31) && (rMonth == 1 || rMonth == 3 || rMonth == 5 || rMonth == 7 || rMonth == 8 || rMonth == 10 || rMonth == 12)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((rDay >= 1 && rDay <= 30) && (rMonth == 4 || rMonth == 6 || rMonth == 9 || rMonth == 11)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if ((rDay >= 1 && rDay <= 28) && (rMonth == 2)) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else if (rDay == 29 && rMonth == 2 && (rYear % 400 == 0 || (rYear % 4 == 0 && rYear % 100 != 0))) {
									printf("Date is valid.\n");
									validDate = 1;
								}
								else {
									printf("Day is invalid.\n");
									validDate = 0;
								}
							}
							else
								printf("Date is invalid\n");
						}
					}
					else {
						printf("Month is not valid.\n");
						validDate = 0;
					}
				}
				else {
					printf("Year is not valid.\n");
					validDate = 0;
				}

			} while (validDate == 0);

			do {
				printf("\n\t\t\t\t\t\tEnter the time you wish to reserve(hh.mm)\n");
				printf("\t\t\t\t\t\tStart time:");
				scanf("%d.%d", &rStartHr, &rStartMin);
				rewind(stdin);

				rStartTime = rStartHr * 100 + rStartMin;

				if (rStartTime <= v[i].timeDay.opStartTime)
					printf("\n\t\t\t\t\t\tsorry,too early, the venue still not open\n");
			} while (rStartTime <= v[i].timeDay.opStartTime);

			do {
				printf("\t\t\t\t\t\tEnd time:");
				scanf("%d.%d", &rEndHr, &rEndMin);
				rewind(stdin);

				rEndTime = rEndHr * 100 + rEndMin;

				if (rEndTime > v[i].timeDay.opEndTime)
					printf("\t\t\t\t\t\tsorry, the venue already closed\n");

			} while (rEndTime > v[i].timeDay.opEndTime);




			printf("\n\t\t\t\t\t\tPlease state why you wish to reserve this venue:");
			scanf("%[^\n]", &reserveV[0].reserveReason);
			rewind(stdin);
			if (rYear == reserveV[i].reserveYear && rMonth == reserveV[i].reserveMonth && rDay == reserveV[i].reserveDay && rStartHr == reserveV[i].reserveStartHr && rEndHr == reserveV[i].reserveEndHr && rStartMin == reserveV[i].reserveStartMin && rEndMin == reserveV[i].reserveEndMin) {
				printf("\t\t\t\t\t\tsorry, this venue at this time is already reserved\n");
			}

			strcpy(reserveV[0].venueId, v[i].venueID);
			reserveV[0].reserveYear = rYear;
			reserveV[0].reserveMonth = rMonth;
			reserveV[0].reserveDay = rDay;
			reserveV[0].reserveStartHr = rStartHr;
			reserveV[0].reserveStartMin = rStartMin;
			reserveV[0].reserveEndHr = rEndHr;
			reserveV[0].reserveEndMin = rEndMin;
			fwrite(&reserveV[0], sizeof(reserve), 1, fptr);
			printf("\nVenue Id\tVenue reserve date\tVenuereserve time\tReason\n");
			doubleLine(100);
			printf("%-10s\t%d/%d/%d\t\t%d.%d-%d.%d\t\t%s\n\n", reserveV[0].venueId, reserveV[0].reserveYear, reserveV[0].reserveMonth, reserveV[0].reserveDay,
				reserveV[0].reserveStartHr, reserveV[0].reserveStartMin, reserveV[0].reserveEndHr, reserveV[0].reserveEndMin, reserveV[0].reserveReason);
		}




	}



	while (fread(&reserveV[0], sizeof(reserve), 1, binR) != 0) {
		printf("%-10s	%d	%d %d %d%d %d%d\n\n", reserveV[0].venueId, reserveV[0].reserveYear, reserveV[0].reserveMonth, reserveV[0].reserveDay,
			reserveV[0].reserveStartHr, reserveV[0].reserveStartMin, reserveV[0].reserveEndHr, reserveV[0].reserveEndMin);
	}

	fclose(fptrR);
	fclose(fptr);
	fclose(binR);
}

void deleteVenue() {
	system("cls");
	loginHeader(5);
	FILE* fptr, * fptrTemp;
	int found = 0, conDel = 0, count = 0;
	char venueID[5], confirmation, cont;


	do {
		fptr = fopen("venue.txt", "r");

		if (fptr == NULL) {
			printf("Error, unable to open the file\n");
			exit(-1);
		}

		fptrTemp = fopen("delete.txt", "w");

		if (fptrTemp == NULL) {
			printf("Error, unable to open the file\n");
			exit(-1);
		}
		printf("Enter the venue ID you wish to delete:");
		scanf("%s", &venueID);
		rewind(stdin);

		strupr(venueID);

		printf("Venue ID\tVenue category\t\tVenue Name\t\tVenue maximum visitor allowed\tVenue current visitor\tVenue operating day\tVenue operating time(24hr format)\tVenue status\tLast sanitization date (yyyy/mm/dd)\n");
		doubleLine(220);

		while (fscanf(fptr, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%s\t%d/%d/%d\t%d\n", &v[0].venueID, &v[0].venueCat, &v[0].venueName, &v[0].maxVis, &v[0].timeDay.day.opStartDay, &v[0].timeDay.day.opEndDay, &v[0].timeDay.opStartTime, &v[0].timeDay.opEndTime, &v[0].status, &v[0].saniTime.saniYear, &v[0].saniTime.saniMonth, &v[0].saniTime.saniDay, &v[0].currentVisitors) != EOF) {
			if (strcmp(venueID, v[0].venueID) == 0) {
				found = 1;

				printf("%-10s\t%-20s\t%-20s\t%-25d\t%-20d\t%s-%-10s\t%.4d-%-30.4d\t%s\t%d/%d/%d\n", v[0].venueID, v[0].venueCat, v[0].venueName, v[0].maxVis, v[0].currentVisitors, v[0].timeDay.day.opStartDay, &v[0].timeDay.day.opEndDay, v[0].timeDay.opStartTime, v[0].timeDay.opEndTime, v[0].status, v[0].saniTime.saniYear, v[0].saniTime.saniMonth, v[0].saniTime.saniDay);

				printf("\n\t\t\t\t\t\tThe record is found, are you sure you want to delete?(y/n):");
				scanf("%c", &confirmation);
				rewind(stdin);

				if (toupper(confirmation) == 'Y') {
					printf("The record is found and deleted\n");
					conDel = 1;
				}
				else if (toupper(confirmation) == 'N') {
					conDel = 0;
				}
			}
			else {
				fprintf(fptrTemp, "%s\t%s\t%s\t%d\t%s-%s\t%d-%d\t%s\t%d/%d/%d\t%d\n", v[0].venueID, v[0].venueCat, v[0].venueName, v[0].maxVis, v[0].timeDay.day.opStartDay, v[0].timeDay.day.opEndDay, v[0].timeDay.opStartTime, v[0].timeDay.opEndTime, v[0].status, v[0].saniTime.saniYear, v[0].saniTime.saniMonth, v[0].saniTime.saniDay, v[0].currentVisitors);
			}
		}
		if (found == 0)
			printf("\n\t\t\t\t\t\trecord no found\n");

		fclose(fptr);
		fclose(fptrTemp);

		if (conDel == 1) {
			remove("venue.txt");
			rename("delete.txt", "venue.txt");
		}

		printf("\n\t\t\t\t\t\tDo you want to delete another record?(y/n):");
		scanf("%c", &cont);

		if (toupper(cont) == 'N') {
			system("cls");
			loginHeader(5);
			return 0;
		}




	} while (toupper(cont) == 'Y');




}

int integerCheck(char input[])
{
	int number = 0;

	for (int i = 0; i < strlen(input); i++) {
		if (isalpha(input[i]) != 0) {
			printf("Invalid input\n");
			number = 0;
			return number;
		}
		else
			number = atoi(input);
	}

	return number;
}

void updateStatus(char* status) {
	//declare type definitions structure for date and time
	typedef struct {
		int start_hour, start_minute, end_hour, end_minute, san_day, san_month, san_year;
	}DateTime;

	//declare tagged structure for sanitization detail
	struct SanitizationDetail {
		char venue[50];
		DateTime datetime;
	};

	//declare structure variable for sanitization.txt
	struct {
		char com_Name[80], contact_Person[50], address[100];
		char per_Number[12], com_Number[10], ID[7];
		struct SanitizationDetail detail;
	}s, sRecord[100];

	//declare type definitions for service details
	typedef struct {
		double service_tax;
		int service_rate;
	}Service;

	//declare tagged structure for payment.dat
	struct PaymentDetail {
		char pay_ID[7], san_ID[7], pay_method[20], pay_merchant[20], sanitizer_brand[30];
		double pay_amount;
		Service service;
	};

	FILE* fptrR, * fptrSR, * binR, * binW;
	fptrR = fopen("venue.txt", "r");
	fptrSR = fopen("sanitization.txt", "r");
	binR = fopen("reserve.bin", "rb");
	int h = 0, b = 0, x = 0, found = 0, foundTime = 0, c = 0;
	char test[300];

	if (fptrR == NULL || fptrSR == NULL) {
		printf("Error, unable to open the file1\n");
		exit(-1);
	}

	if (binR == 0) {
		printf("Error, unable to open the file2\n");
		exit(-1);
	}

	//get system time
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	while (fread(&reserveV[b], sizeof(reserve), 1, binR) != 0) {
		b++;
	}

	while (fscanf(fptrR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%s\t%d/%d/%d\t%d\n", &v[h].venueID, &v[h].venueCat, &v[h].venueName, &v[h].maxVis, &v[h].timeDay.day.opStartDay, &v[h].timeDay.day.opEndDay, &v[h].timeDay.opStartTime, &v[h].timeDay.opEndTime, &v[h].status, &v[h].saniTime.saniYear, &v[h].saniTime.saniMonth, &v[h].saniTime.saniDay, &v[h].currentVisitors) != EOF) {
		h++;
	}

	while (fscanf(fptrSR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[x].ID, &sRecord[x].detail.datetime.san_day, &sRecord[x].detail.datetime.san_month, &sRecord[x].detail.datetime.san_year, &sRecord[x].detail.venue, &sRecord[x].detail.datetime.start_hour, &sRecord[x].detail.datetime.start_minute, &sRecord[x].detail.datetime.end_hour, &sRecord[x].detail.datetime.end_minute, &sRecord[x].com_Name, &sRecord[x].com_Number, &sRecord[x].contact_Person, &sRecord[x].per_Number, &sRecord[x].address) != EOF) {
		x++;
	}

	for (int i = 0; i < b; i++) {
		if (reserveV[i].reserveYear == tm.tm_year + 1900) {
			if (tm.tm_mon + 1 == reserveV[i].reserveMonth) {
				if (tm.tm_mday == reserveV[i].reserveDay) {
					if (tm.tm_hour == reserveV[i].reserveStartHr) {
						if (tm.tm_hour * 100 + tm.tm_min == reserveV[i].reserveStartHr * 100 + reserveV[i].reserveStartMin) {
							strcpy(&status, "UNAVAILABLE");
						}
					}
					else if (tm.tm_hour == reserveV[i].reserveEndHr) {
						if (tm.tm_hour * 100 + tm.tm_min == reserveV[i].reserveEndHr * 100 + reserveV[i].reserveEndMin) {
							strcpy(&status, "AVAILABLE");

							binW = fopen("reservetmp.bin", "wb");

							if (binW == 0) {
								printf("Error, unable to open the file2\n");
								exit(-1);
							}

							while (fread(&reserveV[0], sizeof(reserve), 1, binR) != NULL) {
								if (tm.tm_hour == reserveV[i].reserveEndHr && tm.tm_min == reserveV[i].reserveEndMin)
									found = 1;

								else
									fwrite(&reserveV[i], sizeof(reserve), 1, binW);


								fclose(binW);

								remove("reserve.bin");
								rename("reservetmp.bin", "reserve.bin");
							}
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < x; i++) {

		if (sRecord[i].detail.datetime.san_year == tm.tm_year + 1900) {
			if (tm.tm_mon + 1 == sRecord[i].detail.datetime.san_month) {
				if (tm.tm_mday == sRecord[i].detail.datetime.san_day) {
					if (tm.tm_hour >= sRecord[i].detail.datetime.start_hour) {
						if (tm.tm_hour * 100 + tm.tm_min >= sRecord[i].detail.datetime.start_hour * 100 + sRecord[i].detail.datetime.start_minute) {
							foundTime = i;
							for (int c = 0; c < h; c++) {
								if (strcmp(v[c].venueName, sRecord[foundTime].detail.venue) == 0) {
									strcpy(&status, "UNAVAILABLE");
								}
							}
						}
					}
					else if (tm.tm_hour >= sRecord[i].detail.datetime.end_hour) {
						if (tm.tm_hour * 100 + tm.tm_min >= sRecord[i].detail.datetime.end_hour * 100 + sRecord[i].detail.datetime.end_minute) {
							foundTime = i;
							for (int c = 0; c < t; c++);
							if (strcmp(v[c].venueName, sRecord[foundTime].detail.venue) == 0)
								strcpy(&status, "AVAILABLE");
						}
					}
				}
			}
		}
	}


	fclose(fptrR);
	fclose(binR);
	return 0;
}



