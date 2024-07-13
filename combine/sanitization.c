#include "header.h"

void line1() {
	printf(" --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//validation check which are only allow user to key in number only and the length of number must be 9
int comNumberCheck(char num[]) {
	int check = 0;
	if (strlen(num) != 9) {
		check = 1;
	}

	else if (strlen(num) == 9) {
		for (int x = 0; x < 9; x++) {
			if (isdigit(num[x]) == 0) {
				check = 1;
			}
		}
	}

	else
		check = 0;

	return check;
}

//validation check which are only allow user to key in number only and the length of number must be 10 or 11
int perNumberCheck(char num[]) {
	int check = 0;
	if (strlen(num) < 10 || strlen(num) > 11) {
		check = 1;
	}

	else if (strlen(num) == 10) {
		for (int x = 0; x < 10; x++) {
			if (isdigit(num[x]) == 0) {
				check = 1;
			}
		}
	}

	else if (strlen(num) == 11) {
		for (int x = 0; x < 11; x++) {
			if (isdigit(num[x]) == 0) {
				check = 1;
			}
		}
	}
	else
		check = 0;

	return check;
}

//validation check which are only allow user to key in character only 
int characterCheck(char name[]) {
	int check = 0;
	for (int x = 0; x < strlen(name); x++) {
		if (name[x] != ' ') {
			if (isalpha(name[x]) == 0) {
				check = 1;
				break;
			}
			else
				check = 0;
		}
	}
	return check;
}

//vaidation check for hour and minute 
void startTimeCheck(char time[100], int* hour, int* minute) {
	int hr, min;
	printf("%s", time);
	rewind(stdin);
	scanf("%d:%d", &hr, &min);
	while (hr < 0 || hr > 23 || min < 0 || min > 59) {
		printf("\tInvalid time!!\n");
		printf("\tPlease reenter the sanitization starting time(in 24 hour)   :");
		rewind(stdin);
		scanf("%d:%d", &hr, &min);
	}
	*hour = hr;
	*minute = min;
}
//validation check for hour and minute
void endTimeCheck(char time[100], int* hour, int* minute) {
	int hr, min;
	printf("%s", time);
	rewind(stdin);
	scanf("%d:%d", &hr, &min);
	while (hr < 0 || hr > 23 || min < 0 || min > 59) {
		printf("\tInvalid time!!\n");
		printf("\tPlease reenter the sanitization ending time(in 24 hour)     :");
		rewind(stdin);
		scanf("%d:%d", &hr, &min);
	}
	*hour = hr;
	*minute = min;
}
void add() {
	//declare variables in add function
	FILE* fptrA, * fptrR, * fptrPA, * fptrPR, * fptrVR;
	int i = 0, countAdd = 0, check = 0, count = 0, y = 0, countVenue = 0, u = 0;
	char option, answer;
	SYSTEMTIME t;
	GetLocalTime(&t);
	struct PaymentDetail p;
	int num = 1, choice;
	char numID[5], IDName[10], payAmountChar[10], payAmountCharDecimal[10], serviceTaxChar[10], serviceTaxCharDecimal[10];
	bool validPayAmount = false;
	bool validServiceTax = false;
	bool validPayAmountDecimal = false;
	bool validServiceTaxDecimal = false;
	bool validDate = false;

	//file open for text file
	fptrA = fopen("sanitization.txt", "a");
	fptrR = fopen("sanitization.txt", "r");
	fptrVR = fopen("venue.txt", "r");

	//check error for the file open
	if (fptrA == NULL || fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	if (fptrVR == NULL) {
		printf("Error, unable to open the file\n");
		exit(-1);
	}
	//file open for binary file
	fptrPA = fopen("payment.dat", "ab");
	fptrPR = fopen("payment.dat", "rb");

	//check error for the file open
	if (fptrPA == NULL || fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}

	//ask user to choose whether want to add record into sanitization.txt or payment.dat
	printf("\n\tDo you want to add record into SANITIZATION.txt for reservation or PAYMENT.dat for recording the previous sanitization details?\n\n");
	printf("\tEnter 1 to add record into SANITIZATION.txt\n");
	printf("\tEnter 2 to add record into PAYMENT.dat\n\n");
	printf("\tYour selection is:");
	rewind(stdin);
	scanf("%d", &choice);
	//validation check for choice
	while (choice != 1 && choice != 2) {
		printf("\tInvalid number!!\n");
		printf("\tPlease reenter the selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &choice);
	}

	system("cls"); loginHeader(7);
	//header for add function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tADD RECORDS\n\n");
	line1();

	//add record into sanitization.txt
	if (choice == 1) {
		//read from sanitization.txt
		while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &s.ID, &s.detail.datetime.san_day, &s.detail.datetime.san_month, &s.detail.datetime.san_year, &s.detail.venue,
			&s.detail.datetime.start_hour, &s.detail.datetime.start_minute, &s.detail.datetime.end_hour, &s.detail.datetime.end_minute, &s.com_Name, &s.com_Number, &s.contact_Person, &s.per_Number, &s.address) != EOF) {

		}
		//read from venue.txt
		while (fscanf(fptrVR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%s\t%d/%d/%d\n", &v[u].venueID, &v[u].venueCat, &v[u].venueName, &v[u].maxVis, &v[u].timeDay.day.opStartDay,
			&v[u].timeDay.day.opEndDay, &v[u].timeDay.opStartTime, &v[u].timeDay.opEndTime, &v[u].status, &v[u].saniTime.saniYear, &v[u].saniTime.saniMonth, &v[u].saniTime.saniDay) != EOF) {
			u++;
		}
		fclose(fptrVR);
		//auto generate sanitization id
		for (int x = 0; x < 4; x++) {
			numID[x] = s.ID[x + 2];
		}
		num = atoi(numID);
		do {
			num++;
			printf("\tEnter the #%d Sanitization record:\n\n", i + 1);
			sprintf(numID, "%04d", num);
			strcpy(IDName, "SA");

			strcat(IDName, numID);
			strcpy(s.ID, IDName);
			printf("\tSanitization ID                                             :%s\n\n", s.ID);

			printf("\tSanitization date (dd/mm/yyyy)                              :");
			rewind(stdin);
			scanf("%d/%d/%d", &s.detail.datetime.san_day, &s.detail.datetime.san_month, &s.detail.datetime.san_year);
			//validation check for day,month,year to let the user only can input the date equal or larger than the system time
			if (s.detail.datetime.san_year >= t.wYear) {
				validDate = true;
				if (s.detail.datetime.san_month < t.wMonth || s.detail.datetime.san_month > 12) {
					validDate = false;
				}
				else if (s.detail.datetime.san_month == t.wMonth) {
					validDate = true;
					if (s.detail.datetime.san_day < t.wDay || s.detail.datetime.san_day > 30) {
						validDate = false;
					}
					else {
						validDate = true;
					}
				}
				else {
					validDate = true;
					if (s.detail.datetime.san_day > 30 || s.detail.datetime.san_day < 0) {
						validDate = false;
					}
					else {
						validDate = true;
					}
				}
			}
			else {
				validDate = false;
			}

			while (validDate == false) {
				printf("\tInvalid date!!\n");
				printf("\tPlease reenter sanitization date (dd/mm/yyyy)               :");
				rewind(stdin);
				scanf("%d/%d/%d", &s.detail.datetime.san_day, &s.detail.datetime.san_month, &s.detail.datetime.san_year);
				if (s.detail.datetime.san_year >= t.wYear) {
					validDate = true;
					if (s.detail.datetime.san_month < t.wMonth || s.detail.datetime.san_month > 12) {
						validDate = false;
					}
					else if (s.detail.datetime.san_month == t.wMonth) {
						validDate = true;
						if (s.detail.datetime.san_day < t.wDay || s.detail.datetime.san_day > 30) {
							validDate = false;
						}
						else {
							validDate = true;
						}
					}
					else {
						validDate = true;
						if (s.detail.datetime.san_day > 30 || s.detail.datetime.san_day < 0) {
							validDate = false;
						}
						else {
							validDate = true;
						}
					}
				}
				else {
					validDate = false;
				}
			}
			printf("\n");

			printf("\tVenue of sanitization                                       :");
			rewind(stdin);
			scanf("%[^\n]", s.detail.venue);
			strupr(s.detail.venue);
			for (int x = 0; x < u + 1; x++) {
				if (strcmp(s.detail.venue, v[x].venueName) == 0) {
					countVenue++;
					break;
				}
			}
			while (countVenue == 0) {
				printf("\tInvalid venue name!!\n");
				printf("\tPlease reenter venue of sanitization                        :");
				rewind(stdin);
				scanf("%[^\n]", &s.detail.venue);
				strupr(s.detail.venue);
				for (int x = 0; x < u + 1; x++) {

					if (strcmp(s.detail.venue, v[x].venueName) == 0) {
						countVenue++;
						break;
					}
				}
			}
			countVenue = 0;
			printf("\n");

			//call function to let the user input start time
			startTimeCheck("\tSanitization starting time(in 24 hour)                      :", &s.detail.datetime.start_hour, &s.detail.datetime.start_minute);
			printf("\n");
			//call function to let the user input end time
			endTimeCheck("\tSanitization ending time(in 24 hour)                        :", &s.detail.datetime.end_hour, &s.detail.datetime.end_minute);
			printf("\n");

			printf("\tSanitization company name                                   :");
			rewind(stdin);
			scanf("%[^\n]", &s.com_Name);
			strupr(s.com_Name);
			printf("\n");

			printf("\tCompany contact number                                      :");
			rewind(stdin);
			scanf("%s", &s.com_Number);
			//validation check for contact number
			check = comNumberCheck(s.com_Number);
			while (check == 1) {
				printf("\tInvalid contact number!!\n");
				printf("\tPlease reenter the company contact number                   :");
				rewind(stdin);
				scanf("%[^\n]", &s.com_Number);
				check = comNumberCheck(s.com_Number);
			}
			printf("\n");

			printf("\tCompany contact person                                      :");
			rewind(stdin);
			scanf("%[^\n]", &s.contact_Person);
			strupr(s.contact_Person);
			//validation check for contact person
			check = characterCheck(s.contact_Person);
			while (check == 1) {
				printf("\tInvalid company contact person!!\n");
				printf("\tPlease reenter the company contact person                   :");
				rewind(stdin);
				scanf("%[^\n]", &s.contact_Person);
				strupr(s.contact_Person);
				check = characterCheck(s.contact_Person);
			}
			printf("\n");

			printf("\tContact number (+60)                                        :");
			rewind(stdin);
			scanf("%s", &s.per_Number);
			//validation check for contact number
			check = perNumberCheck(s.per_Number);
			while (check == 1) {
				printf("\tInvalid contact number!!\n");
				printf("\tPlease reenter the contact number (+60)                     :");
				rewind(stdin);
				scanf("%s", &s.per_Number);
				check = perNumberCheck(s.per_Number);
			}
			printf("\n");

			printf("\tCompany address                                             :");
			rewind(stdin);
			scanf("%[^\n]", s.address);
			strupr(s.address);
			printf("\n");

			//write the records which are input by user into sanitization.txt
			fprintf(fptrA, "%-6s\t%02d/%02d/%d\t%-16s\t%02d:%02d\t%02d:%02d\t%-24s\t%9s\t\t%-16s\t%-11s\t%-24s\n", s.ID, s.detail.datetime.san_day, s.detail.datetime.san_month, s.detail.datetime.san_year,
				s.detail.venue, s.detail.datetime.start_hour, s.detail.datetime.start_minute, s.detail.datetime.end_hour, s.detail.datetime.end_minute, s.com_Name,
				s.com_Number, s.contact_Person, s.per_Number, s.address);
			printf("\tRecord successfully added...\n");
			printf("\tDo you want to continue to add in new record? (Y = yes /N = no):");
			rewind(stdin);
			scanf("%c", &option);
			printf("\n\n");
			i++;
			countAdd += 1;
		} while (toupper(option) == 'Y');

		printf("\t%d of record(s) have been added.\n", countAdd);
	}

	//add record into payment.dat
	else if (choice == 2) {
		//read from sanitization.txt to get the sanitization id to make validation check
		while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
			&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
			i++;
		}
		//read from payment.dat
		while (fread(&p, sizeof(p), 1, fptrPR) != NULL) {

		}
		//auto generate payment.id
		for (int x = 0; x < 4; x++) {
			numID[x] = p.pay_ID[x + 2];
		}
		num = atoi(numID);
		do {
			num++;
			printf("\tEnter the #%d LAST SANITIZATION details:\n\n", y + 1);
			sprintf(numID, "%04d", num);
			strcpy(IDName, "PA");

			strcat(IDName, numID);
			strcpy(p.pay_ID, IDName);
			printf("\tPayment ID                                                                     :%s\n\n", p.pay_ID);

			printf("\tSanitization ID                                                                :");
			rewind(stdin);
			scanf("%s", &p.san_ID);
			strupr(p.san_ID);
			//validation check for sanitization id,only accept the sanitization id from sanitization.txt
			for (int x = 0; x < i + 1; x++) {
				if (strcmp(p.san_ID, sRecord[x].ID) == 0) {
					count++;
					break;
				}
			}
			while (count == 0) {
				printf("\tInvalid sanitization ID!!\n");
				printf("\tThis sanitization ID cannot found in sanitization.txt.\n");
				printf("\tPlease reenter sanitization ID                                                 :");
				rewind(stdin);
				scanf("%s", &p.san_ID);
				strupr(p.san_ID);
				for (int x = 0; x < i + 1; x++) {
					if (strcmp(p.san_ID, sRecord[x].ID) == 0) {
						count++;
						break;
					}
				}
			}
			count = 0;
			printf("\n");

			printf("\tPayment method (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH)               :");
			rewind(stdin);
			scanf("%[^\n]", p.pay_method);
			strupr(p.pay_method);
			//validation check for payment method which are only accept 4 method which are e-wallet,online banking,credit card and cash 
			while (strcmp(p.pay_method, "E-WALLET") != 0 && strcmp(p.pay_method, "ONLINE BANKING") != 0 && strcmp(p.pay_method, "CREDIT CARD") != 0 && strcmp(p.pay_method, "CASH") != 0) {
				printf("\tInvalid payment method!!\n");
				printf("\tPlease reenter payment method (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH):");
				rewind(stdin);
				scanf("%[^\n]", p.pay_method);
				strupr(p.pay_method);
			}

			//if user key in payment method is using cash,then payment merchant will not appear
			if (strcmp(p.pay_method, "E-WALLET") == 0 || strcmp(p.pay_method, "ONLINE BANKING") == 0 || strcmp(p.pay_method, "CREDIT CARD") == 0) {
				printf("\n\tPayment merchant                                                               :");
				rewind(stdin);
				scanf("%[^\n]", p.pay_merchant);
				strupr(p.pay_merchant);
			}
			else
				strcpy(p.pay_merchant, "-");
			printf("\n");

			printf("\tPayment amount(RM 00.00)                                                       :");
			rewind(stdin);
			scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
			//validation check for payment amount to let the user only can input number
			for (int i = 0; i < strlen(payAmountChar); i++) {
				if (isdigit(payAmountChar[i]) == 0) {
					validPayAmount = false;
					break;
				}
				else
					validPayAmount = true;
			}

			for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
				if (isdigit(payAmountCharDecimal[i]) == 0) {
					validPayAmountDecimal = false;
					break;
				}
				else
					validPayAmountDecimal = true;
			}

			if (validPayAmount == false || validPayAmountDecimal == false) {
				printf("\tInvalid payment amount!!\n");
			}
			while (validPayAmount == false || validPayAmountDecimal == false) {
				printf("\tPlease reenter payment amount(RM 00.00)                                        :");
				rewind(stdin);
				scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
				for (int i = 0; i < strlen(payAmountChar); i++) {
					if (isdigit(payAmountChar[i]) == 0) {
						validPayAmount = false;
						break;
					}
					else
						validPayAmount = true;
				}

				for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
					if (isdigit(payAmountCharDecimal[i]) == 0) {
						validPayAmountDecimal = false;
						break;
					}
					else
						validPayAmountDecimal = true;
				}

				if (validPayAmount == false || validPayAmountDecimal == false) {
					printf("\tInvalid payment amount!!\n");
				}
			}

			p.pay_amount = atof(payAmountChar);
			printf("\n");

			printf("\tService tax (RM 00.00)                                                         :");
			rewind(stdin);
			scanf("%[^.].%s", &serviceTaxChar, &serviceTaxCharDecimal);
			//validation check for service tax to let the user only can input number
			for (int i = 0; i < strlen(serviceTaxChar); i++) {
				if (isdigit(serviceTaxChar[i]) == 0) {
					validServiceTax = false;
					break;
				}
				else
					validServiceTax = true;
			}

			for (int i = 0; i < strlen(serviceTaxCharDecimal); i++) {
				if (isdigit(serviceTaxCharDecimal[i]) == 0) {
					validServiceTaxDecimal = false;
					break;
				}
				else
					validServiceTaxDecimal = true;
			}

			if (validServiceTax == false || validServiceTaxDecimal == false) {
				printf("\tInvalid service tax!!\n");
			}
			while (validServiceTax == false || validServiceTaxDecimal == false) {
				printf("\tPlease reenter service tax (RM 00.00)                                          :");
				rewind(stdin);
				scanf("%[^.].%s", &serviceTaxChar, &serviceTaxCharDecimal);
				for (int i = 0; i < strlen(serviceTaxChar); i++) {
					if (isdigit(serviceTaxChar[i]) == 0) {
						validServiceTax = false;
						break;
					}
					else
						validServiceTax = true;
				}

				for (int i = 0; i < strlen(serviceTaxCharDecimal); i++) {
					if (isdigit(serviceTaxCharDecimal[i]) == 0) {
						validServiceTaxDecimal = false;
						break;
					}
					else
						validServiceTaxDecimal = true;
				}

				if (validServiceTax == false || validServiceTaxDecimal == false) {
					printf("\tInvalid service tax!!\n");
				}
			}

			p.service.service_tax = atof(serviceTaxChar);
			printf("\n");

			printf("\tSanitizer brand used by company                                                :");
			rewind(stdin);
			scanf("%[^\n]", p.sanitizer_brand);
			strupr(p.sanitizer_brand);
			printf("\n");

			printf("\tService rating (please give a rate for the company service (1 star - 5 star)   :");
			rewind(stdin);
			scanf("%d", &p.service.service_rate);
			//validation check for service rating that are not allow user to key in number that are not in 1 to 5
			while (p.service.service_rate < 1 || p.service.service_rate >5) {
				printf("\tInvalid rating!!\n");
				printf("\tPlease reenter the rating for the company (1 star - 5 star)                    :");
				rewind(stdin);
				scanf("%d", &p.service.service_rate);
			}
			printf("\n");

			//write the records which are input by user into payment.dat
			fwrite(&p, sizeof(p), 1, fptrPA);

			printf("\tRecord successfully added...\n");
			printf("\tDo you want to continue to add in new record? (Y/N) :");
			rewind(stdin);
			scanf("%c", &option);
			printf("\n\n");
			y++;
			countAdd += 1;
		} while (toupper(option) == 'Y');

		printf("\t%d of record(s) have been added.\n", countAdd);
	}
	//file close
	fclose(fptrA);
	fclose(fptrR);
	fclose(fptrPA);
	fclose(fptrPR);

	//ask user whether he or she want to exit to menu or end the program
	printf("\n\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
	rewind(stdin);
	scanf("%c", &answer);
	if (toupper(answer) == 'Y') {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}

void line2() {
	printf("\t\t ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void line3() {
	printf("\t\t|--------|------------|-----------------------|---------|-------|--------------------------------|----------------|-----------------|-------------|--------------------------------|\n");
}

void line4() {
	printf("\t\t -------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void line5() {
	printf("\t\t|------------|-----------------|----------------------------|----------------------------|----------------|-------------|--------------------------|----------------|\n");
}

//function structure to display all records in payment.dat
void serviceStruct(Service* service) {

}
void paymentDetail(struct PaymentDetail* p, int a) {
	serviceStruct(&(p->service));
	if (a == 0) {
		printf("\n\n");
		printf("\t\t\t\t\t\t\t\t\t\tLIST OF PREVIOUS SANITIZATION RECORDS\n\n");
		line4();
		printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
		line5();
	}
	printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", p->pay_ID, p->san_ID, p->pay_method, p->pay_merchant, p->pay_amount, p->service.service_tax, p->sanitizer_brand, p->service.service_rate);

}
void display() {
	//declare variables in display function
	FILE* fptrR, * fptrPR;
	char IDFrom[7], IDTo[7];
	int option, numFrom, numTo, i = 0, count = 0, choice, a = 0;
	char numID[6], name[3], answer;
	struct PaymentDetail p, pRecord[100];

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}

	//ask user to choose whether want to display record from sanitization.txt or payment.dat
	printf("\n\tDo you want to display record of SANITIZATION or record of PREVIOUS SANITIZATION?\n\n");
	printf("\tEnter 1 to display record of SANITIZATION\n");
	printf("\tEnter 2 to display record of PREVIOUS SANITIZATION\n\n");
	printf("\tYour selection is:");
	rewind(stdin);
	scanf("%d", &choice);
	//validation check for choice
	while (choice != 1 && choice != 2) {
		printf("\n\tInvalid number!!\n");
		printf("\tPlease reenter the selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &choice);
	}

	system("cls"); loginHeader(7);
	//header for display function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tDISPLAY RECORDS\n\n");
	line1();

	//display records in sanitization.txt
	if (choice == 1) {
		//let user choose whether he or she want to display all records or certain records
		printf("\t\t\t\t\t\t\t\t\t\t\t1. ALL sanitization records\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t2. CERTAIN records\n");
		printf("\t\t\t\t\t\t\t\tPlease select what types of records you want to display in Sanitization.txt.(in number): ");
		rewind(stdin);
		scanf("%d", &option);

		//display all records
		if (option == 1) {
			printf("\n\n");
			printf("\t\t\t\t\t\t\t\t\t\tLIST OF SANITIZATION RECORDS\n\n");
			line2();
			printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
			printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
			line3();
			//read from sanitization.txt
			while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &s.ID, &s.detail.datetime.san_day, &s.detail.datetime.san_month, &s.detail.datetime.san_year, &s.detail.venue,
				&s.detail.datetime.start_hour, &s.detail.datetime.start_minute, &s.detail.datetime.end_hour, &s.detail.datetime.end_minute, &s.com_Name, &s.com_Number, &s.contact_Person, &s.per_Number, &s.address) != EOF) {
				//dsiplay output
				printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", s.ID, s.detail.datetime.san_day, s.detail.datetime.san_month, s.detail.datetime.san_year, s.detail.venue,
					s.detail.datetime.start_hour, s.detail.datetime.start_minute, s.detail.datetime.end_hour, s.detail.datetime.end_minute, s.com_Name, s.com_Number, s.contact_Person, s.per_Number, s.address);
			}
			line2();

			//ask user whether he or she want to exit to menu or end the program
			printf("\t\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
			rewind(stdin);
			scanf("%c", &answer);
			if (toupper(answer) == 'Y') {
				system("cls"); loginHeader(7);
				sanitizationMenu();
			}
		}

		//display certain records
		else if (option == 2) {
			//read from sanitization.txt
			while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
				&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
				i++;
			}
			//let user to enter the range of sanitization id
			printf("\n\tPlease enter the range of Sanitization ID you want to display:\n");
			printf("\t                                                        From :");
			rewind(stdin);
			scanf("%s", &IDFrom);
			strupr(IDFrom);
			//validation check for sanitization id,only accept the sanitization id from sanitization.txt
			for (int x = 0; x < i + 1; x++) {
				if (strcmp(IDFrom, sRecord[x].ID) == 0) {
					count++;
					numFrom = x;
					break;
				}
			}
			while (count == 0) {
				printf("\t                           Invalid ID!! Please reenter the ID:");
				rewind(stdin);
				scanf("%s", &IDFrom);
				strupr(IDFrom);
				for (int x = 0; x < i + 1; x++) {
					if (strcmp(IDFrom, sRecord[x].ID) == 0) {
						count++;
						numFrom = x;
						break;
					}
				}
			}
			count = 0;
			printf("\n");
			printf("\t                                                          To :");
			rewind(stdin);
			scanf("%s", &IDTo);
			strupr(IDTo);
			//validation check for sanitization id,only accept the sanitization id from sanitization.txt
			for (int x = 0; x < i + 1; x++) {
				if (strcmp(IDTo, sRecord[x].ID) == 0) {
					count++;
					numTo = x;
					break;
				}
			}
			while (count == 0) {
				printf("\t                           Invalid ID!! Please reenter the ID:");
				rewind(stdin);
				scanf("%s", &IDTo);
				strupr(IDTo);
				for (int x = 0; x < i + 1; x++) {
					if (strcmp(IDTo, sRecord[x].ID) == 0) {
						count++;
						numTo = x;
						break;
					}
				}
			}

			//display output
			printf("\n\n\t\t\t\t\t\t\t\t\t\tLIST OF SANITIZATION RECORDS from %s to %s\n\n", IDFrom, IDTo);
			line2();
			printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
			printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
			line3();
			for (int x = numFrom; x <= numTo; x++) {
				printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[x].ID, sRecord[x].detail.datetime.san_day, sRecord[x].detail.datetime.san_month, sRecord[x].detail.datetime.san_year, sRecord[x].detail.venue,
					sRecord[x].detail.datetime.start_hour, sRecord[x].detail.datetime.start_minute, sRecord[x].detail.datetime.end_hour, sRecord[x].detail.datetime.end_minute, sRecord[x].com_Name, sRecord[x].com_Number, sRecord[x].contact_Person, sRecord[x].per_Number, sRecord[x].address);
			}

			line2();

			//ask user whether he or she want to exit to menu or end the program
			printf("\t\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
			rewind(stdin);
			scanf("%c", &answer);
			if (toupper(answer) == 'Y') {
				system("cls"); loginHeader(7);
				sanitizationMenu();
			}
		}
		//file close
		fclose(fptrR);
	}

	//display records in payment.dat
	else if (choice == 2) {
		//let user choose whether he or she want to display all records or certain records
		printf("\t\t\t\t\t\t\t\t\t\t\t1. ALL records\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t2. CERTAIN records\n");
		printf("\t\t\t\t\t\t\t\tPlease select what types of records you want to display in PAYMENT.dat.(in number): ");
		rewind(stdin);
		scanf("%d", &option);

		//display all records
		if (option == 1) {
			//read from payment.dat
			while (fread(&p, sizeof(p), 1, fptrPR) != NULL) {

				//call function to display output
				paymentDetail(&p, a++);
			}

			line4();
			//ask user whether he or she want to exit to menu or end the program
			printf("\t\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
			rewind(stdin);
			scanf("%c", &answer);
			if (toupper(answer) == 'Y') {
				system("cls"); loginHeader(7);
				sanitizationMenu();
			}
		}

		//display certain records
		else if (option == 2) {
			//read from payment.dat
			while (fread(&pRecord[i], sizeof(pRecord[i]), 1, fptrPR) != NULL) {
				i++;
			}

			//let user to enter the range of payment id
			printf("\n\tPlease enter the range of Payment ID you want to display:\n");
			printf("\t                                                   From :");
			rewind(stdin);
			scanf("%s", &IDFrom);
			strupr(IDFrom);
			//validation check for payment id,only accept the payment id from payment.dat
			for (int x = 0; x < i + 1; x++) {
				if (strcmp(IDFrom, pRecord[x].pay_ID) == 0) {
					count++;
					numFrom = x;
					break;
				}
			}
			while (count == 0) {
				printf("\t                      Invalid ID!! Please reenter the ID:");
				rewind(stdin);
				scanf("%s", &IDFrom);
				strupr(IDFrom);
				for (int x = 0; x < i + 1; x++) {
					if (strcmp(IDFrom, pRecord[x].pay_ID) == 0) {
						count++;
						numFrom = x;
						break;
					}
				}
			}
			count = 0;
			printf("\n");
			printf("\t                                                     To :");
			scanf("%s", &IDTo);
			strupr(IDTo);
			//validation check for payment id,only accept the payment id from payment.dat
			for (int x = 0; x < i + 1; x++) {
				if (strcmp(IDTo, pRecord[x].pay_ID) == 0) {
					count++;
					numTo = x;
					break;
				}
			}
			while (count == 0) {
				printf("\t                      Invalid ID!! Please reenter the ID:");
				rewind(stdin);
				scanf("%s", &IDTo);
				strupr(IDTo);
				for (int x = 0; x < i + 1; x++) {
					if (strcmp(IDTo, pRecord[x].pay_ID) == 0) {
						count++;
						numTo = x;
						break;
					}
				}
			}

			//display output
			printf("\n\n\t\t\t\t\t\t\t\t\tLIST OF PREVIOUS SANITIZATION RECORDS from %s to %s\n\n", IDFrom, IDTo);
			line4();
			printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
			line5();

			for (int x = numFrom; x <= numTo; x++) {
				printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[x].pay_ID, pRecord[x].san_ID, pRecord[x].pay_method, pRecord[x].pay_merchant, pRecord[x].pay_amount, pRecord[x].service.service_tax, pRecord[x].sanitizer_brand, pRecord[x].service.service_rate);
			}
			line4();

			//ask user whether he or she want to exit to menu or end the program
			printf("\t\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
			rewind(stdin);
			scanf("%c", &answer);
			if (toupper(answer) == 'Y') {
				system("cls"); loginHeader(7);
				sanitizationMenu();
			}
		}
		//file close
		fclose(fptrPR);
	}
}

void oneCriteria() {
	//declare variables in oneCriteria function
	FILE* fptrR;
	int i = 0, count = 0, year, countRecord = 0, found = 0, answer;
	char yearChar[5];
	bool validYear = false;

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	//read from sanitization.txt
	while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
		&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
		i++;
		count++;
	}
	//file close
	fclose(fptrR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter date of sanitization (in year only) to search  :");
	rewind(stdin);
	scanf("%s", &yearChar);
	//validation check for year to let user only can key in integer
	while (validYear == false) {
		for (int i = 0; i < strlen(yearChar); i++) {
			if (isdigit(yearChar[i]) == 0) {
				validYear = false;
				printf("\t\tInvalid year!!\n");
				printf("\t\tEnter date of sanitization (in year only) to search  :");
				rewind(stdin);
				scanf("%s", &yearChar);
				break;
			}
			else
				validYear = true;
		}
		year = atoi(yearChar);

	}
	printf("\n");

	for (i = 0; i < count; i++) {
		//compare the year from user input and the year in text file
		if (year == sRecord[i].detail.datetime.san_year) {
			found++;
			if (found == 1) {
				line2();
				printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
				printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
				line3();
			}
			printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
				sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
			countRecord += 1;
		}
	}

	printf("\n\t\tThere are %d record(s) that are found in year = %d.\n\n", countRecord, year);

	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}

void twoCriteria() {
	//declare variables in twoCriteria function
	FILE* fptrR;
	int i = 0, count = 0, year, countRecord = 0, month, found = 0, answer;
	char yearChar[5];
	bool validYear = false;

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	//read from sanitization.txt
	while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
		&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
		i++;
		count++;
	}
	//file close
	fclose(fptrR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();

	//let user to input the key word they want to search
	printf("\t\tEnter date of sanitization (in year only) to search  :");
	rewind(stdin);
	scanf("%s", &yearChar);
	//validation check for year to let user only can key in integer
	while (validYear == false) {
		for (int i = 0; i < strlen(yearChar); i++) {
			if (isdigit(yearChar[i]) == 0) {
				validYear = false;
				printf("\t\tInvalid year!!\n");
				printf("\t\tEnter date of sanitization (in year only) to search  :");
				rewind(stdin);
				scanf("%s", &yearChar);
				break;
			}
			else
				validYear = true;
		}
		year = atoi(yearChar);

	}
	printf("\t\tEnter date of sanitization (in month only) to search :");
	rewind(stdin);
	scanf("%d", &month);
	//validation check for month to let user only can input the month in range 1 to 12
	while (month < 1 || month>12) {
		printf("\t\tInvalid month!!\n");
		printf("\t\tEnter date of sanitization (in month only) to search :");
		rewind(stdin);
		scanf("%d", &month);
	}
	printf("\n");
	for (i = 0; i < count; i++) {
		//compare the year and month from user input and the year and month in text file
		if (year == sRecord[i].detail.datetime.san_year && month == sRecord[i].detail.datetime.san_month) {
			found++;
			if (found == 1) {
				line2();
				printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
				printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
				line3();
			}
			printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
				sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in year = %d and month = %d.\n\n", countRecord, year, month);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}

}

void threeCriteria() {
	//declare variables in threeCriteria function
	FILE* fptrR;
	int i = 0, count = 0, countRecord = 0, month, found = 0, year, answer;
	char venue[50], yearChar[5];
	bool validYear = false;

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	//read from sanitization.txt
	while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
		&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
		i++;
		count++;
	}
	//file close
	fclose(fptrR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter date of sanitization (in year only) to search  :");
	rewind(stdin);
	scanf("%s", &yearChar);
	//validation check for year to let user only can key in integer
	while (validYear == false) {
		for (int i = 0; i < strlen(yearChar); i++) {
			if (isdigit(yearChar[i]) == 0) {
				validYear = false;
				printf("\t\tInvalid year!!\n");
				printf("\t\tEnter date of sanitization (in year only) to search  :");
				rewind(stdin);
				scanf("%s", &yearChar);
				break;
			}
			else
				validYear = true;
		}
		year = atoi(yearChar);
	}

	printf("\t\tEnter date of sanitization (in month only) to search :");
	rewind(stdin);
	scanf("%d", &month);
	//validation check for month to let user only can input the month in range 1 to 12
	while (month < 1 || month>12) {
		printf("\t\tInvalid month!!\n");
		printf("\t\tEnter date of sanitization (in month only) to search :");
		rewind(stdin);
		scanf("%d", &month);
	}
	printf("\t\tEnter venue of sanitization to search                :");
	rewind(stdin);
	scanf("%[^\n]", venue);
	strupr(venue);

	printf("\n");
	for (i = 0; i < count; i++) {
		//compare the year,month and venue from user input and the year,month and venue in text file
		if (year == sRecord[i].detail.datetime.san_year && month == sRecord[i].detail.datetime.san_month && strcmp(venue, sRecord[i].detail.venue) == 0) {
			found++;
			if (found == 1) {
				line2();
				printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
				printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
				line3();
			}
			printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
				sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in year = %d , month = %d and venue of the sanitization = %s.\n\n", countRecord, year, month, venue);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}

void fourCriteria() {
	//declare variables in fourCriteria function
	FILE* fptrR;
	int i = 0, count = 0, year, countRecord = 0, month, found = 0, answer;
	int start_hour, start_minute, end_hour, end_minute;
	char venue[50], yearChar[5];
	bool validYear = false;

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	//read from sanitization.txt
	while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
		&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
		i++;
		count++;
	}

	//file close
	fclose(fptrR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter date of sanitization (in year only) to search                            :");
	rewind(stdin);
	scanf("%s", &yearChar);
	//validation check for year to let user only can key in integer
	while (validYear == false) {
		for (int i = 0; i < strlen(yearChar); i++) {
			if (isdigit(yearChar[i]) == 0) {
				validYear = false;
				printf("\t\tInvalid year!!\n");
				printf("\t\tEnter date of sanitization (in year only) to search                            :");
				rewind(stdin);
				scanf("%s", &yearChar);
				break;
			}
			else
				validYear = true;
		}
		year = atoi(yearChar);

	}

	printf("\t\tEnter date of sanitization (in month only) to search                           :");
	rewind(stdin);
	scanf("%d", &month);
	//validation check for month to let user only can input the month in range 1 to 12
	while (month < 1 || month>12) {
		printf("\t\tInvalid month!!\n");
		printf("\t\tEnter date of sanitization (in month only) to search                           :");
		scanf("%d", &month);
	}
	printf("\t\tEnter venue of sanitization to search                                          :");
	rewind(stdin);
	scanf("%[^\n]", venue);
	strupr(venue);

	printf("\t\tEnter the start time and end time(range) of sanitization to search (in 24 hour):\n");
	printf("\t\t                                                             Start Time (From) :");
	rewind(stdin);
	scanf("%d:%d", &start_hour, &start_minute);
	//validation check for hour and minute that the range of hour is only in 0 to 23 while minute only in 0 to 59
	while (start_hour < 0 || start_hour > 23 || start_minute < 0 || start_minute > 59) {
		printf("\t\t                                                               Invalid time!!\n");
		printf("\t\t                                          Please reenter the Start Time (From) :");
		rewind(stdin);
		scanf("%d:%d", &start_hour, &start_minute);
	}
	printf("\t\t                                                                 End Time (To) :");
	rewind(stdin);
	scanf("%d:%d", &end_hour, &end_minute);
	//validation check for hour and minute that the range of hour is only in 0 to 23 while minute only in 0 to 59
	while (end_hour < 0 || end_hour > 23 || end_minute < 0 || end_minute > 59) {
		printf("\t\t                                                               Invalid time!!\n");
		printf("\t\t                                              Please reenter the End Time (To) :");
		rewind(stdin);
		scanf("%d:%d", &end_hour, &end_minute);
	}

	printf("\n");
	for (i = 0; i < count; i++) {
		//compare the year,month,venue,start hour,start minute,end hour and end minute from user input and the year,month,venue,start hour,start minute,end hour and end minute in text file
		if (year == sRecord[i].detail.datetime.san_year && month == sRecord[i].detail.datetime.san_month && strcmp(venue, sRecord[i].detail.venue) == 0 && sRecord[i].detail.datetime.start_hour >= start_hour &&
			sRecord[i].detail.datetime.start_minute >= start_minute && sRecord[i].detail.datetime.end_hour <= end_hour && sRecord[i].detail.datetime.end_minute <= end_minute) {
			found++;
			if (found == 1) {
				line2();
				printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
				printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
				line3();
			}
			printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
				sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in year = %d , month = %d , venue of the sanitization = %s and the range of time is between %02d:%02d to %02d:%02d.\n\n", countRecord, year, month, venue, start_hour, start_minute, end_hour, end_minute);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}

void service() {
	//declare variables in service function
	FILE* fptrPR;
	int i = 0, count = 0, rate, countRecord = 0, found = 0, answer;
	struct PaymentDetail pRecord[100];

	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}
	//read from payment.dat
	while (fread(&pRecord[i], sizeof(pRecord[i]), 1, fptrPR) != NULL) {
		i++;
		count++;
	}
	//fclose
	fclose(fptrPR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter the company service rating to search (1-5):");
	rewind(stdin);
	scanf("%d", &rate);
	//validation check for rate to ensure user only can key in 1-5
	while (rate < 1 || rate >5) {
		printf("\t\tInvalid rating!!\n");
		printf("\t\tPlease reenter the rating for the company (1-5) :");
		rewind(stdin);
		scanf("%d", &rate);
	}
	printf("\n");
	for (i = 0; i < count; i++) {
		//compare service rate form user input and service rate form binary file
		if (rate == pRecord[i].service.service_rate) {
			found++;
			if (found == 1) {
				line4();
				printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
				line5();
			}
			printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[i].pay_ID, pRecord[i].san_ID, pRecord[i].pay_method, pRecord[i].pay_merchant, pRecord[i].pay_amount, pRecord[i].service.service_tax, pRecord[i].sanitizer_brand, pRecord[i].service.service_rate);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in company service rate = %d.\n\n", countRecord, rate);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void payMethod() {
	//declare variables in payMethod function
	FILE* fptrPR;
	int i = 0, count = 0, countRecord = 0, found = 0, answer;
	char pay_method[20];
	struct PaymentDetail pRecord[100];

	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}
	//read from payment.dat
	while (fread(&pRecord[i], sizeof(pRecord[i]), 1, fptrPR) != NULL) {
		i++;
		count++;
	}
	//fclose
	fclose(fptrPR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH)         :");
	rewind(stdin);
	scanf("%[^\n]", &pay_method);
	strupr(pay_method);
	//validation check for payment method which are only accept 4 method which are e-wallet,online banking,credit card and cash 
	while (strcmp(pay_method, "E-WALLET") != 0 && strcmp(pay_method, "ONLINE BANKING") != 0 && strcmp(pay_method, "CREDIT CARD") != 0 && strcmp(pay_method, "CASH") != 0) {
		printf("\t\tInvalid payment method!!\n");
		printf("\t\tPlease reenter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH):");
		rewind(stdin);
		scanf("%[^\n]", pay_method);
		strupr(pay_method);
	}

	printf("\n");
	for (i = 0; i < count; i++) {
		//compare payment method from user input and payment method from binary file
		if (strcmp(pay_method, pRecord[i].pay_method) == 0) {
			found++;
			if (found == 1) {
				line4();
				printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
				line5();
			}
			printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[i].pay_ID, pRecord[i].san_ID, pRecord[i].pay_method, pRecord[i].pay_merchant, pRecord[i].pay_amount, pRecord[i].service.service_tax, pRecord[i].sanitizer_brand, pRecord[i].service.service_rate);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in payment method = %s.\n\n", countRecord, pay_method);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void payMethodMerchant() {
	//declare variables in payMethodMerchant function
	FILE* fptrPR;
	int i = 0, count = 0, countRecord = 0, found = 0, answer;
	char pay_method[20], pay_merchant[20];
	struct PaymentDetail pRecord[100];

	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}
	//read from payment.dat
	while (fread(&pRecord[i], sizeof(pRecord[i]), 1, fptrPR) != NULL) {
		i++;
		count++;
	}
	//fclose
	fclose(fptrPR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD )               :");
	rewind(stdin);
	scanf("%[^\n]", &pay_method);
	strupr(pay_method);
	//validation check for payment method which are only accept 4 method which are e-wallet,online banking,credit card and cash 
	while (strcmp(pay_method, "E-WALLET") != 0 && strcmp(pay_method, "ONLINE BANKING") != 0 && strcmp(pay_method, "CREDIT CARD") != 0) {
		printf("\t\tInvalid payment method!!\n");
		printf("\t\tPlease reenter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD )      :");
		rewind(stdin);
		scanf("%[^\n]", pay_method);
		strupr(pay_method);
	}

	printf("\t\tEnter the payment merchant to search                                                         :");
	rewind(stdin);
	scanf("%[^\n]", &pay_merchant);
	strupr(pay_merchant);
	printf("\n");

	for (i = 0; i < count; i++) {
		//compare payment method and payment merchant from user input and payment method and payment merchant from binary file
		if (strcmp(pay_method, pRecord[i].pay_method) == 0 && strcmp(pay_merchant, pRecord[i].pay_merchant) == 0) {
			found++;
			if (found == 1) {
				line4();
				printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
				line5();
			}
			printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[i].pay_ID, pRecord[i].san_ID, pRecord[i].pay_method, pRecord[i].pay_merchant, pRecord[i].pay_amount, pRecord[i].service.service_tax, pRecord[i].sanitizer_brand, pRecord[i].service.service_rate);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in payment method = %s and payment merchant = %s.\n\n", countRecord, pay_method, pay_merchant);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void payMethodMerchantAmount() {
	//declare variables in payMethodMerchantAmount function
	FILE* fptrPR;
	int i = 0, count = 0, countRecord = 0, found = 0, pay_amount, answer;
	char pay_method[20], pay_merchant[20], payAmountChar[10], payAmountCharDecimal[10];
	bool validPayAmount = false;
	bool validPayAmountDecimal = false;
	struct PaymentDetail p, pRecord[100];

	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}
	//read from payment.dat
	while (fread(&pRecord[i], sizeof(pRecord[i]), 1, fptrPR) != NULL) {
		i++;
		count++;
	}
	//fclose
	fclose(fptrPR);

	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();
	//let user to input the key word they want to search
	printf("\t\tEnter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH)         :");
	rewind(stdin);
	scanf("%[^\n]", &pay_method);
	strupr(pay_method);
	//validation check for payment method which are only accept 4 method which are e-wallet,online banking,credit card and cash
	while (strcmp(pay_method, "E-WALLET") != 0 && strcmp(pay_method, "ONLINE BANKING") != 0 && strcmp(pay_method, "CREDIT CARD") != 0 && strcmp(pay_method, "CASH") != 0) {
		printf("\t\tInvalid payment method!!\n");
		printf("\t\tPlease reenter the payment method to search (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH):");
		rewind(stdin);
		scanf("%[^\n]", pay_method);
		strupr(pay_method);
	}
	//if user key in payment method is using cash,then payment merchant will not appear
	if (strcmp(pay_method, "E-WALLET") == 0 || strcmp(pay_method, "ONLINE BANKING") == 0 || strcmp(pay_method, "CREDIT CARD") == 0) {
		printf("\t\tEnter the payment merchant to search                                                         :");
		rewind(stdin);
		scanf("%[^\n]", &pay_merchant);
		strupr(pay_merchant);
	}
	else
		strcpy(pay_merchant, "-");

	printf("\t\tEnter the payment amount to search (RM 00.00)                                                :");
	rewind(stdin);
	scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
	//validation check for payment amount to let the user only can input number
	for (int i = 0; i < strlen(payAmountChar); i++) {
		if (isdigit(payAmountChar[i]) == 0) {
			validPayAmount = false;
			break;
		}
		else
			validPayAmount = true;
	}

	for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
		if (isdigit(payAmountCharDecimal[i]) == 0) {
			validPayAmountDecimal = false;
			break;
		}
		else
			validPayAmountDecimal = true;
	}

	if (validPayAmount == false || validPayAmountDecimal == false) {
		printf("\tInvalid payment amount!!\n");
	}
	while (validPayAmount == false || validPayAmountDecimal == false) {
		printf("\tPlease reenter payment amount(RM 00.00)                                                        :");
		rewind(stdin);
		scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
		for (int i = 0; i < strlen(payAmountChar); i++) {
			if (isdigit(payAmountChar[i]) == 0) {
				validPayAmount = false;
				break;
			}
			else
				validPayAmount = true;
		}

		for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
			if (isdigit(payAmountCharDecimal[i]) == 0) {
				validPayAmountDecimal = false;
				break;
			}
			else
				validPayAmountDecimal = true;
		}

		if (validPayAmount == false || validPayAmountDecimal == false) {
			printf("\tInvalid payment amount!!\n");
		}
	}

	pay_amount = atof(payAmountChar);
	printf("\n");

	for (i = 0; i < count; i++) {
		//compare payment method,payment merchant and payment amount from user input and payment method,payment merchant and payment amount from binary file
		if (strcmp(pay_method, pRecord[i].pay_method) == 0 && strcmp(pay_merchant, pRecord[i].pay_merchant) == 0 && pay_amount == pRecord[i].pay_amount) {
			found++;
			if (found == 1) {
				line4();
				printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
				line5();
			}
			printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[i].pay_ID, pRecord[i].san_ID, pRecord[i].pay_method, pRecord[i].pay_merchant, pRecord[i].pay_amount, pRecord[i].service.service_tax, pRecord[i].sanitizer_brand, pRecord[i].service.service_rate);
			countRecord += 1;
		}
	}
	printf("\n\t\tThere are %d record(s) that are found in payment method = %s , payment merchant = %s and payment amount = %d.\n\n", countRecord, pay_method, pay_merchant, pay_amount);
	if (found == 0)
		printf("\t\tNo such record found match with your searching.\n\n");
	found = 0;
	countRecord = 0;

	//ask user whether he or she want to exit to search menu or exit to sanitization main menu
	printf("\t\tDo you want to exit to search menu to do another serching or exit to sanitization main menu??\n");
	printf("\t\t1. Search menu\n");
	printf("\t\t2. Sanitization main menu\n");
	printf("\t\tYour selection is:");
	rewind(stdin);
	scanf("%d", &answer);
	//validation check that only let the user to input 1 or 2
	while (answer != 1 && answer != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter your selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &answer);
	}
	if (answer == 1) {
		system("cls"); loginHeader(7);
		search();
	}
	else if (answer == 2) {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void search() {
	//declare variables in search function
	int i = 0, answer, count = 0, choice;
	char option;
	//ask user to choose whether want to search record from sanitization.txt or payment.dat
	printf("\n\tDo you want to search record for the SANITIZATION or record for the PREVIOUS SANITIZATION?\n\n");
	printf("\tEnter 1 to search record for SANITIZATION\n");
	printf("\tEnter 2 to search record for PREVIOUS SANITIZATION\n\n");
	printf("\tYour selection is:");
	rewind(stdin);
	scanf("%d", &choice);
	//validation check for choice
	while (choice != 1 && choice != 2) {
		printf("\n\t\tInvalid number!!\n");
		printf("\t\tPlease reenter the selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &choice);
	}
	system("cls"); loginHeader(7);

	//header for search function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSEARCH RECORDS\n\n");
	line1();

	//search sanitization records
	if (choice == 1) {
		printf("\t\t\t\t\t\t\t\t\t\t\t1. Searching based on 1 criteria :\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in year only)\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t2. Searching based on 2 criteria :\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in year only)\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in month only)\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t3. Searching based on 3 criteria :\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in year only)\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in month only)\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Venue of sanitization\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t4. Searching based on 4 criteria :\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in year only)\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Date of sanitization (in month only)\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Venue of sanitization\n");
		printf("\t\t\t\t\t\t\t\t\t\t\t   Sanitization time (in 24 hour)\n\n");
		printf("\t\t\t\t\t\t\t\t\tPlease select how many criteria you want to search for (in number):");
		scanf("%d", &answer);
		//call the function that the user selected
		switch (answer) {
		case 1:oneCriteria(); break;
		case 2:twoCriteria(); break;
		case 3:threeCriteria(); break;
		case 4:fourCriteria(); break;
		default: break;
		}
	}
	//search previous sanitization records
	else if (choice == 2) {
		printf("\t\t\t\t\t\t\t\t\t1. Searching based on service rating only\n");
		printf("\t\t\t\t\t\t\t\t\t2. Searching based on payment method only\n");
		printf("\t\t\t\t\t\t\t\t\t3. Searching based on payment method and payment merchant\n");
		printf("\t\t\t\t\t\t\t\t\t4. Searching based on payment method , payment merchant and payment amount\n\n");
		printf("\t\t\t\t\t\t\t\t\tPlease select the data field you want to search for (in number):");
		scanf("%d", &answer);
		//call the function that the user selected
		switch (answer) {
		case 1:service(); break;
		case 2:payMethod(); break;
		case 3:payMethodMerchant(); break;
		case 4:payMethodMerchantAmount(); break;
		default: break;
		}
	}
}


void modify() {
	//declare variables in modify function
	FILE* fptrR, * fptrW, * fptrPR, * fptrPW, * fptrVR;
	SYSTEMTIME t;
	GetLocalTime(&t);
	int modifyCount = 0, count = 0, i = 0, found = 0, check = 0, choice, countID = 0, countVenue = 0, u = 0, countSanitization = 0, y = 0;
	int start_hour, start_minute, end_hour, end_minute, san_day, san_month, san_year;
	char com_Name[80], contact_Person[50], address[100];
	char per_Number[12], com_Number[12], ID[7], venue[50];
	char answer1, answer2, answer;
	char san_ID[7], pay_method[20], pay_merchant[20], sanitizer_brand[30], payAmountChar[10], payAmountCharDecimal[10], serviceTaxChar[10], serviceTaxCharDecimal[10];
	double pay_amount, service_tax;
	int service_rate;
	bool validPayAmount = false;
	bool validServiceTax = false;
	bool validPayAmountDecimal = false;
	bool validServiceTaxDecimal = false;
	bool validDate = false;
	struct PaymentDetail p, pRecord[100];

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	fptrVR = fopen("venue.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}
	if (fptrVR == NULL) {
		printf("Error, unable to open the file\n");
		exit(-1);
	}
	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}
	countSanitization = 0;
	//read from sanitization.txt
	while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
		&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
		i++;
		countSanitization++;
	}
	//fclose
	fclose(fptrR);
	//read from venue.txt
	while (fscanf(fptrVR, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^-]-%[^\t]\t%d-%d\t%s\t%d/%d/%d\n", &v[u].venueID, &v[u].venueCat, &v[u].venueName, &v[u].maxVis, &v[u].timeDay.day.opStartDay,
		&v[u].timeDay.day.opEndDay, &v[u].timeDay.opStartTime, &v[u].timeDay.opEndTime, &v[u].status, &v[u].saniTime.saniYear, &v[u].saniTime.saniMonth, &v[u].saniTime.saniDay) != EOF) {
		u++;
	}
	fclose(fptrVR);

	count = 0;
	//read from payment.dat
	while (fread(&pRecord[y], sizeof(pRecord[y]), 1, fptrPR) != NULL) {
		y++;
		count++;
	}
	//file close
	fclose(fptrPR);

	//ask user to choose whether want to modify record from sanitization.txt or payment.dat
	printf("\n\tDo you want to modify SANITIZATION record or PREVIOUS SANITIZATION record?\n\n");
	printf("\tEnter 1 to modify record for SANITIZATION\n");
	printf("\tEnter 2 to modify record for PREVIOUS SANITIZATION\n\n");
	printf("\tYour selection is:");
	rewind(stdin);
	scanf("%d", &choice);
	//validation check for choice
	while (choice != 1 && choice != 2) {
		printf("\tInvalid number!!\n");
		printf("\tPlease reenter the selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &choice);
	}

	system("cls"); loginHeader(7);

	//header for modify function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tMODIFY RECORDS\n\n");
	line1();

	//modify record from sanitization.txt
	if (choice == 1) {
		do {
			//let user to enter the id they want to modify
			strcpy(ID, "");
			printf("\n\tPlease enter the Sanitization ID you would like to modify:");
			rewind(stdin);
			scanf("%s", &ID);
			strupr(ID);

			for (i = 0; i < countSanitization; i++) {
				//compare the sanitization id form user input and sanitization id text file
				if (strcmp(ID, sRecord[i].ID) == 0) {
					found = 1;
					printf("\n\tRecord found in sanitization.txt :\n");
					line2();
					printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
					printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
					line3();
					printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
						sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
					//sanitization id remain constant
					printf("\n\tPlease enter the NEW RECORD DETAILS for the sanitization ID :%s\n\n", sRecord[i].ID);

					//let user input new record to change the old record
					printf("\tNEW sanitization date (dd/mm/yyyy)                          :");
					rewind(stdin);
					scanf("%d/%d/%d", &san_day, &san_month, &san_year);
					//validation check for day,month,year which are only allow the user to key in the date larger or equal to system time 
					if (san_year >= t.wYear) {
						validDate = true;
						if (san_month < t.wMonth || san_month > 12) {
							validDate = false;
						}
						else if (san_month == t.wMonth) {
							validDate = true;
							if (san_day < t.wDay || san_day > 30) {
								validDate = false;
							}
							else {
								validDate = true;
							}
						}
						else {
							validDate = true;
							if (san_day > 30 || san_day < 0) {
								validDate = false;
							}
							else {
								validDate = true;
							}
						}
					}
					else {
						validDate = false;
					}

					while (validDate == false) {
						printf("\tInvalid date!!\n");
						printf("\tPlease reenter sanitization date (dd/mm/yyyy)               :");
						rewind(stdin);
						scanf("%d/%d/%d", &san_day, &san_month, &san_year);
						if (san_year >= t.wYear) {
							validDate = true;
							if (san_month < t.wMonth || san_month > 12) {
								validDate = false;
							}
							else if (san_month == t.wMonth) {
								validDate = true;
								if (san_day < t.wDay || san_day > 30) {
									validDate = false;
								}
								else {
									validDate = true;
								}
							}
							else {
								validDate = true;
								if (san_day > 30 || san_day < 0) {
									validDate = false;
								}
								else {
									validDate = true;
								}
							}
						}
						else {
							validDate = false;
						}
					}
					printf("\n");

					printf("\tNEW venue of sanitization                                   :");
					rewind(stdin);
					scanf("%[^\n]", venue);
					strupr(venue);
					for (int x = 0; x < u + 1; x++) {
						if (strcmp(venue, v[x].venueName) == 0) {
							countVenue++;
							break;
						}
					}
					while (countVenue == 0) {
						printf("\tInvalid venue name!!\n");
						printf("\tPlease reenter venue of sanitization                        :");
						rewind(stdin);
						scanf("%[^\n]", &venue);
						strupr(venue);
						for (int x = 0; x < u + 1; x++) {

							if (strcmp(venue, v[x].venueName) == 0) {
								countVenue++;
								break;
							}
						}
					}
					countVenue = 0;
					printf("\n");

					//call function to let the user input start time
					startTimeCheck("\tNEW sanitization starting time(in 24 hour)                  :", &start_hour, &start_minute);
					printf("\n");

					//call function to let the user input end time
					endTimeCheck("\tNEW sanitization ending time(in 24 hour)                    :", &end_hour, &end_minute);
					printf("\n");

					printf("\tNEW sanitization company name                               :");
					rewind(stdin);
					scanf("%[^\n]", &com_Name);
					strupr(com_Name);
					printf("\n");

					printf("\tNEW company contact number                                  :");
					rewind(stdin);
					scanf("%s", &com_Number);
					//validation check for contact number
					check = comNumberCheck(com_Number);
					while (check == 1) {
						printf("\tInvalid contact number!!\n");
						printf("\tPlease reenter the company contact number                   :");
						rewind(stdin);
						scanf("%[^\n]", &com_Number);
						check = comNumberCheck(com_Number);
					}
					printf("\n");

					printf("\tNEW company contact person                                  :");
					rewind(stdin);
					scanf("%[^\n]", &contact_Person);
					strupr(contact_Person);
					//validation check for contact person
					check = characterCheck(contact_Person);
					while (check == 1) {
						printf("\tInvalid company contact person!!\n");
						printf("\tPlease reenter the company contact person                   :");
						rewind(stdin);
						scanf("%[^\n]", &contact_Person);
						strupr(contact_Person);
						check = characterCheck(contact_Person);
					}
					printf("\n");

					printf("\tNEW contact number                                          :");
					rewind(stdin);
					scanf("%s", &per_Number);
					//validation check for contact number
					check = perNumberCheck(per_Number);
					while (check == 1) {
						printf("\tInvalid contact number!!\n");
						printf("\tPlease reenter the contact number                           :");
						rewind(stdin);
						scanf("%s", &per_Number);
						check = perNumberCheck(per_Number);
					}
					printf("\n");

					printf("\tNEW company address                                         :");
					rewind(stdin);
					scanf("%[^\n]", address);
					strupr(address);
					printf("\n");

					printf("\n\tAre you sure to modify this ID > %s ?? (Y = yes / N = no)", ID);
					rewind(stdin);
					scanf("%c", &answer1);
					//copy the new records form user input to the old records
					if (toupper(answer1) == 'Y') {
						sRecord[i].detail.datetime.san_day = san_day;
						sRecord[i].detail.datetime.san_month = san_month;
						sRecord[i].detail.datetime.san_year = san_year;
						strcpy(sRecord[i].detail.venue, venue);
						sRecord[i].detail.datetime.start_hour = start_hour;
						sRecord[i].detail.datetime.start_minute = start_minute;
						sRecord[i].detail.datetime.end_hour = end_hour;
						sRecord[i].detail.datetime.end_minute = end_minute;
						strcpy(sRecord[i].com_Name, com_Name);
						strcpy(sRecord[i].com_Number, com_Number);
						strcpy(sRecord[i].contact_Person, contact_Person);
						strcpy(sRecord[i].per_Number, per_Number);
						strcpy(sRecord[i].address, address);
						modifyCount++;
						printf("\n\t\tUpdated sanitization record details:\n");
						line2();
						printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
						printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
						line3();
						printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-16s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
							sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
						line2();
					}

				}

			}
			if (found == 0)
				printf("\n\tNo sanitization record found with this sanitization ID you entered : %s\n", ID);
			found = 0;
			printf("\n\tDo you want to continue to modify?? (Y = yes / N =no)");
			rewind(stdin);
			scanf("%c", &answer2);

		} while (toupper(answer2) == 'Y');

		//file open for text file
		fptrW = fopen("sanitization.txt", "w");
		//check error for the file open
		if (fptrW == NULL) {
			printf("Error.Unable to open this sanitization.txt\n");
			exit(-1);
		}
		for (i = 0; i < countSanitization; i++) {
			//write the new records which are input by user into sanitization.txt
			fprintf(fptrW, "%-6s\t%02d/%02d/%d\t%-16s\t%02d:%02d\t%02d:%02d\t%-24s\t%9s\t\t%-16s\t%-11s\t%-24s\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
				sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
		}
		//file close
		fclose(fptrW);

		printf("\n\t\t%d record(s) mofified.\n\n", modifyCount);

	}

	//modify records from payment.dat
	else if (choice == 2) {
		do {
			//let user to enter the id they want to modify
			strcpy(ID, "");
			printf("\n\tPlease enter the Payment ID you would like to modify:");
			rewind(stdin);
			scanf("%s", &ID);
			strupr(ID);

			for (y = 0; y < count; y++) {
				//compare the payment id form user input and payment id binary file
				if (strcmp(ID, pRecord[y].pay_ID) == 0) {
					found = 1;
					printf("\tRecord found in payment.dat :\n");
					line4();
					printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
					line5();
					printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[y].pay_ID, pRecord[y].san_ID, pRecord[y].pay_method, pRecord[y].pay_merchant, pRecord[y].pay_amount, pRecord[y].service.service_tax, pRecord[y].sanitizer_brand, pRecord[y].service.service_rate);
					//payment id remain constant
					printf("\n\tPlease enter the NEW RECORD DETAILS for the payment ID :%s\n\n", pRecord[y].pay_ID);

					//let user input new record to change the old record
					printf("\tNEW sanitization ID                                                            :");
					rewind(stdin);
					scanf("%s", san_ID);
					strupr(san_ID);
					//validation check for sanitization id,only accept the sanitization id from sanitization.txt
					for (int x = 0; x < y + 1; x++) {
						if (strcmp(san_ID, sRecord[x].ID) == 0) {
							countID++;
							break;
						}
					}
					while (countID == 0) {
						printf("\tInvalid sanitization ID!!\n");
						printf("\tThis sanitization ID cannot found in sanitization.txt.\n");
						printf("\tPlease reenter sanitization ID                                                 :");
						rewind(stdin);
						scanf("%s", &san_ID);
						strupr(san_ID);
						for (int x = 0; x < y + 1; x++) {
							if (strcmp(san_ID, sRecord[x].ID) == 0) {
								countID++;
								break;
							}
						}
					}
					countID = 0;
					printf("\n");

					printf("\tNEW payment method (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH)           :");
					rewind(stdin);
					scanf("%[^\n]", pay_method);
					strupr(pay_method);
					//validation check for payment method which are only accept 4 method which are e-wallet,online banking,credit card and cash 
					while (strcmp(pay_method, "E-WALLET") != 0 && strcmp(pay_method, "ONLINE BANKING") != 0 && strcmp(pay_method, "CREDIT CARD") != 0 && strcmp(pay_method, "CASH") != 0) {
						printf("\tInvalid payment method!!\n");
						printf("\tPlease reenter payment method (E-WALLET / ONLINE BANKING / CEREDIT CARD / CASH):");
						rewind(stdin);
						scanf("%[^\n]", pay_method);
						strupr(pay_method);
					}
					//if user key in payment method is using cash,then payment merchant will not appear
					if (strcmp(pay_method, "E-WALLET") == 0 || strcmp(pay_method, "ONLINE BANKING") == 0 || strcmp(pay_method, "CREDIT CARD") == 0) {
						printf("\n\tNEW payment merchant                                                           :");
						rewind(stdin);
						scanf("%[^\n]", pay_merchant);
						strupr(pay_merchant);
					}
					else
						strcpy(pay_merchant, "-");
					printf("\n");

					printf("\tNEW payment amount(RM 00.00)                                                   :");
					rewind(stdin);
					scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
					//validation check for payment amount to let the user only can input number
					for (int i = 0; i < strlen(payAmountChar); i++) {
						if (isdigit(payAmountChar[i]) == 0) {
							validPayAmount = false;
							break;
						}
						else
							validPayAmount = true;
					}

					for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
						if (isdigit(payAmountCharDecimal[i]) == 0) {
							validPayAmountDecimal = false;
							break;
						}
						else
							validPayAmountDecimal = true;
					}

					if (validPayAmount == false || validPayAmountDecimal == false) {
						printf("\tInvalid payment amount!!\n");
					}
					while (validPayAmount == false || validPayAmountDecimal == false) {
						printf("\tPlease reenter payment amount(RM 00.00)                                        :");
						rewind(stdin);
						scanf("%[^.].%s", &payAmountChar, &payAmountCharDecimal);
						for (int i = 0; i < strlen(payAmountChar); i++) {
							if (isdigit(payAmountChar[i]) == 0) {
								validPayAmount = false;
								break;
							}
							else
								validPayAmount = true;
						}

						for (int i = 0; i < strlen(payAmountCharDecimal); i++) {
							if (isdigit(payAmountCharDecimal[i]) == 0) {
								validPayAmountDecimal = false;
								break;
							}
							else
								validPayAmountDecimal = true;
						}

						if (validPayAmount == false || validPayAmountDecimal == false) {
							printf("\tInvalid payment amount!!\n");
						}
					}

					pay_amount = atof(payAmountChar);
					printf("\n");

					printf("\tNEW service tax (RM 00.00)                                                     :");
					rewind(stdin);
					scanf("%[^.].%s", &serviceTaxChar, &serviceTaxCharDecimal);
					//validation check for service tax to let the user only can input number
					for (int i = 0; i < strlen(serviceTaxChar); i++) {
						if (isdigit(serviceTaxChar[i]) == 0) {
							validServiceTax = false;
							break;
						}
						else
							validServiceTax = true;
					}

					for (int i = 0; i < strlen(serviceTaxCharDecimal); i++) {
						if (isdigit(serviceTaxCharDecimal[i]) == 0) {
							validServiceTaxDecimal = false;
							break;
						}
						else
							validServiceTaxDecimal = true;
					}

					if (validServiceTax == false || validServiceTaxDecimal == false) {
						printf("\tInvalid service tax!!\n");
					}
					while (validServiceTax == false || validServiceTaxDecimal == false) {
						printf("\tPlease reenter service tax (RM 00.00)                                          :");
						rewind(stdin);
						scanf("%[^.].%s", &serviceTaxChar, &serviceTaxCharDecimal);
						for (int i = 0; i < strlen(serviceTaxChar); i++) {
							if (isdigit(serviceTaxChar[i]) == 0) {
								validServiceTax = false;
								break;
							}
							else
								validServiceTax = true;
						}

						for (int i = 0; i < strlen(serviceTaxCharDecimal); i++) {
							if (isdigit(serviceTaxCharDecimal[i]) == 0) {
								validServiceTaxDecimal = false;
								break;
							}
							else
								validServiceTaxDecimal = true;
						}

						if (validServiceTax == false || validServiceTaxDecimal == false) {
							printf("\tInvalid service tax!!\n");
						}
					}

					service_tax = atof(serviceTaxChar);
					printf("\n");

					printf("\tNEW sanitizer brand used by company                                            :");
					rewind(stdin);
					scanf("%[^\n]", sanitizer_brand);
					strupr(sanitizer_brand);
					printf("\n");

					printf("\tNEW service rating (please give a rate for the company service(1 star - 5 star):");
					rewind(stdin);
					scanf("%d", &service_rate);
					//validation check for service rating that are not allow user to key in number that are not in 1 to 5
					while (service_rate < 1 || service_rate > 5) {
						printf("\tInvalid rating!!\n");
						printf("\tPlease reenter the rating for the company (1 star - 5 star)                    :");
						rewind(stdin);
						scanf("%d", &service_rate);
					}
					printf("\n");

					printf("\tAre you sure to modify this ID > %s ?? (Y = yes / N = no)", ID);
					rewind(stdin);
					scanf("%c", &answer1);
					if (toupper(answer1) == 'Y') {
						//copy the new records form user input to the old records
						strcpy(pRecord[y].san_ID, san_ID);
						strcpy(pRecord[y].pay_method, pay_method);
						strcpy(pRecord[y].pay_merchant, pay_merchant);
						pRecord[y].pay_amount = pay_amount;
						pRecord[y].service.service_tax = service_tax;
						strcpy(pRecord[y].sanitizer_brand, sanitizer_brand);
						pRecord[y].service.service_rate = service_rate;
						modifyCount++;
						printf("\t\tUpdated record details:\n");
						line4();
						printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
						line5();
						printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[y].pay_ID, pRecord[y].san_ID, pRecord[y].pay_method, pRecord[y].pay_merchant, pRecord[y].pay_amount, pRecord[y].service.service_tax, pRecord[y].sanitizer_brand, pRecord[y].service.service_rate);
						line4();
					}

				}

			}
			if (found == 0)
				printf("\n\tNo record found with this payment ID you entered : %s\n", ID);
			found = 0;
			printf("\n\tDo you want to continue to modify?? (Y = yes / N =no)");
			rewind(stdin);
			scanf("%c", &answer2);

		} while (toupper(answer2) == 'Y');

		//file open for binary file
		fptrPW = fopen("payment.dat", "wb");
		//check error for the file open
		if (fptrPW == NULL) {
			printf("Error.Unable to open this payment.dat\n");
			exit(-1);
		}

		for (y = 0; y < count; y++) {
			//write the new records which are input by user into payment.dat
			fwrite(&pRecord[y], sizeof(pRecord[y]), 1, fptrPW);
		}
		//fclose
		fclose(fptrPW);

		printf("\n\t\t%d record(s) mofified.\n\n", modifyCount);

	}

	//ask user whether he or she want to exit to menu or end the program
	printf("\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
	rewind(stdin);
	scanf("%c", &answer);
	if (toupper(answer) == 'Y') {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}

void deletes() {
	//declare variables in delete function
	FILE* fptrR, * fptrW, * fptrB, * fptrPR, * fptrPW, * fptrPB;
	int count = 0, i = 0, found = 0, delCount, choice2, y = 0;
	char ID[7], option, choice, answer;
	struct PaymentDetail pRecord[100];

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}

	//file open for binary file
	fptrPR = fopen("payment.dat", "rb");
	//check error for the file open
	if (fptrPR == NULL) {
		printf("Error.Unable to open this payment.dat\n");
		exit(-1);
	}

	//ask user to choose whether want to delete record from sanitization.txt or payment.dat
	printf("\n\tDo you want to delete SANITIZATION record or PREVIOUS SANITIZATION record?\n\n");
	printf("\tEnter 1 to delete SANITIZATION record\n");
	printf("\tEnter 2 to delete PREVIOUS SANITIZATION record\n\n");
	printf("\tYour selection is:");
	rewind(stdin);
	scanf("%d", &choice2);
	//validation check for choice
	while (choice2 != 1 && choice2 != 2) {
		printf("\tInvalid number!!\n");
		printf("\tPlease reenter the selection (1 or 2 only):");
		rewind(stdin);
		scanf("%d", &choice2);
	}

	system("cls"); loginHeader(7);

	//header for delete function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tDELETE RECORDS\n\n");
	line1();

	//delete record from sanitization.txt
	if (choice2 == 1) {
		//read from sanitization.txt
		while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
			&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
			i++;
			count++;
		}
		//file close
		fclose(fptrR);

		do {
			//let user to enter the id they want to delete
			strcpy(ID, "");
			printf("\n\tPlease enter the sanitization ID you want to delete:");
			scanf("%s", &ID);
			strupr(ID);

			for (i = 0; i < count; i++) {
				//compare the sanitization id form user input and sanitization id in text file
				if (strcmp(ID, sRecord[i].ID) == 0) {
					printf("\n\tRecord found in sanitization.txt :\n");
					line2();
					printf(" \t\t|   ID   |    Date    |         Venue         |  Start  |  End  |            Company             |    Company     |     Contact     |   Contact   |             Company            |\n");
					printf(" \t\t|        |            |                       |  Time   |  Time |             Name               | Contact Number |     Person      |   Number    |             Address            |\n");
					line3();
					printf(" \t\t| %s | %02d/%02d/%d | %-22s|  %02d:%02d  | %02d:%02d | %-31s| %-15s| %-12s| %-12s|%-32s|\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
						sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
					line2();
					delCount = i;
					count--;
					found++;
				}
			}
			//if sanitization id form user input match with the sanitization id in text file
			if (found != 0) {
				//file open for sanitization.txt and sanitization_backup.txt
				fptrW = fopen("sanitization.txt", "w");
				fptrB = fopen("sanitization_backup.txt", "a");
				//check error for the file open
				if (fptrW == NULL) {
					printf("Error.Unable to open this sanitization.txt\n");
					exit(-1);
				}
				if (fptrB == NULL) {
					printf("Error.Unable to open this sanitization_backup.txt\n");
					exit(-1);
				}
				printf("\n\tAre you sure to delete the record which is sanitization ID = %s ? (Y = yes / N = no)", ID);
				rewind(stdin);
				scanf("%c", &option);
				if (toupper(option) == 'Y') {
					//copy the record that are deleted from user into backup file
					fprintf(fptrB, "%-6s\t%02d/%02d/%d\t%-16s\t%02d:%02d\t%02d:%02d\t%-24s\t%9s\t\t%-16s\t%-11s\t%-24s\n", sRecord[delCount].ID, sRecord[delCount].detail.datetime.san_day, sRecord[delCount].detail.datetime.san_month, sRecord[delCount].detail.datetime.san_year, sRecord[delCount].detail.venue,
						sRecord[delCount].detail.datetime.start_hour, sRecord[delCount].detail.datetime.start_minute, sRecord[delCount].detail.datetime.end_hour, sRecord[delCount].detail.datetime.end_minute, sRecord[delCount].com_Name, sRecord[delCount].com_Number, sRecord[delCount].contact_Person, sRecord[delCount].per_Number, sRecord[delCount].address);

					//arrange the array of sanitization id from the deleted record until end of record
					for (i = delCount; i < count; i++) {
						strcpy(sRecord[i].ID, sRecord[i + 1].ID);
						sRecord[i].detail.datetime.san_day = sRecord[i + 1].detail.datetime.san_day;
						sRecord[i].detail.datetime.san_month = sRecord[i + 1].detail.datetime.san_month;
						sRecord[i].detail.datetime.san_year = sRecord[i + 1].detail.datetime.san_year;
						strcpy(sRecord[i].detail.venue, sRecord[i + 1].detail.venue);
						sRecord[i].detail.datetime.start_hour = sRecord[i + 1].detail.datetime.start_hour;
						sRecord[i].detail.datetime.start_minute = sRecord[i + 1].detail.datetime.start_minute;
						sRecord[i].detail.datetime.end_hour = sRecord[i + 1].detail.datetime.end_hour;
						sRecord[i].detail.datetime.end_minute = sRecord[i + 1].detail.datetime.end_minute;
						strcpy(sRecord[i].com_Name, sRecord[i + 1].com_Name);
						strcpy(sRecord[i].com_Number, sRecord[i + 1].com_Number);
						strcpy(sRecord[i].contact_Person, sRecord[i + 1].contact_Person);
						strcpy(sRecord[i].per_Number, sRecord[i + 1].per_Number);
						strcpy(sRecord[i].address, sRecord[i + 1].address);
					}

					printf("\n\tRecord successfully deleted...\n");
					printf("\tThe sanitization.txt is remaining %d record(s).\n", count);
					for (i = 0; i < count; i++) {
						//write all the records that have been arranging into sanitization.txt
						fprintf(fptrW, "%-6s\t%02d/%02d/%d\t%-16s\t%02d:%02d\t%02d:%02d\t%-24s\t%9s\t\t%-16s\t%-11s\t%-24s\n", sRecord[i].ID, sRecord[i].detail.datetime.san_day, sRecord[i].detail.datetime.san_month, sRecord[i].detail.datetime.san_year, sRecord[i].detail.venue,
							sRecord[i].detail.datetime.start_hour, sRecord[i].detail.datetime.start_minute, sRecord[i].detail.datetime.end_hour, sRecord[i].detail.datetime.end_minute, sRecord[i].com_Name, sRecord[i].com_Number, sRecord[i].contact_Person, sRecord[i].per_Number, sRecord[i].address);
					}
				}
				//file close
				fclose(fptrW);
				fclose(fptrB);
			}

			else {
				printf("\n\tThe record which is sanitization ID = %s cannot found.\n\n", ID);
			}
			printf("\tDo you want to continue delete record? (Y = yes / N = no)");
			rewind(stdin);
			scanf("%c", &choice);

		} while (toupper(choice) == 'Y');

	}

	//delete record from payment.dat
	else if (choice2 == 2) {
		//read from payment.dat
		while (fread(&pRecord[y], sizeof(pRecord[y]), 1, fptrPR) != NULL) {
			y++;
			count++;
		}
		//file close
		fclose(fptrR);

		do {
			//let user to enter the id they want to delete
			strcpy(ID, "");
			printf("\n\tPlease enter the payment ID you want to delete:");
			scanf("%s", &ID);
			strupr(ID);

			for (y = 0; y < count; y++) {
				//compare the payment id form user input and payment id in binary file
				if (strcmp(ID, pRecord[y].pay_ID) == 0) {
					printf("\n\tRecord found in payment.dat :\n");
					line4();
					printf(" \t\t| Payment ID | Sanitization ID |       Payment Method       |      Payment Merchant      | Payment Amount | Service Tax |    Sanitization Brand    | Service Rating |\n");
					line5();
					printf(" \t\t| %-10s | %-15s | %-26s | %-26s | %-14.2lf | %-12.2lf| %-25s| %-15d|\n", pRecord[y].pay_ID, pRecord[y].san_ID, pRecord[y].pay_method, pRecord[y].pay_merchant, pRecord[y].pay_amount, pRecord[y].service.service_tax, pRecord[y].sanitizer_brand, pRecord[y].service.service_rate);
					line4();
					delCount = y;
					count--;
					found++;
				}
			}
			//if payment id form user input match with the payment id in binary file
			if (found != 0) {
				//file open for payment.dat and payment_backup.dat
				fptrPW = fopen("payment.dat", "wb");
				fptrPB = fopen("payment_backup.dat", "ab");
				//check error for the file open
				if (fptrPW == NULL) {
					printf("Error.Unable to open this payment.dat\n");
					exit(-1);
				}
				if (fptrPB == NULL) {
					printf("Error.Unable to open this payment_backup.dat\n");
					exit(-1);
				}

				printf("\n\tAre you sure to delete the record which is payment ID = %s ? (Y = yes / N = no)", ID);
				rewind(stdin);
				scanf("%c", &option);
				if (toupper(option) == 'Y') {
					//copy the record that are deleted from user into backup file
					fwrite(&pRecord[delCount], sizeof(pRecord[delCount]), 1, fptrPB);

					//arrange the array of payment id from the deleted record until end of record
					for (y = delCount; y < count; y++) {
						strcpy(pRecord[y].pay_ID, pRecord[y + 1].pay_ID);
						strcpy(pRecord[y].san_ID, pRecord[i + 1].san_ID);
						strcpy(pRecord[y].pay_method, pRecord[y + 1].pay_method);
						strcpy(pRecord[y].pay_merchant, pRecord[y + 1].pay_merchant);
						pRecord[y].pay_amount = pRecord[y + 1].pay_amount;
						pRecord[y].service.service_tax = pRecord[y + 1].service.service_tax;
						strcpy(pRecord[y].sanitizer_brand, pRecord[y + 1].sanitizer_brand);
						pRecord[y].service.service_rate = pRecord[y + 1].service.service_rate;
					}

					printf("\n\tRecord successfully deleted...\n");
					printf("\tThe payment.dat is remaining %d record(s).\n", count);
					for (y = 0; y < count; y++) {
						//write all the records that have been arranging into payment.dat
						fwrite(&pRecord[y], sizeof(pRecord[y]), 1, fptrPW);
					}
				}

				//file close
				fclose(fptrPW);
				fclose(fptrPB);
			}

			else {
				printf("\n\tThe record which is payment ID = %s cannot found.\n\n", ID);
			}
			printf("\tDo you want to continue delete record? (Y = yes / N = no)");
			rewind(stdin);
			scanf("%c", &choice);

		} while (toupper(choice) == 'Y');
	}
	//ask user whether he or she want to exit to menu or end the program
	printf("\n\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
	rewind(stdin);
	scanf("%c", &answer);
	if (toupper(answer) == 'Y') {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void line6() {
	printf("  -------------------------------------------\n");
}
void line7() {
	printf(" |-------------------|-----------------------|\n");
}


void line8() {
	printf("\t\t\t\t\t\t\t\t ----------------------------------------------------------\n");
}

void line9() {
	printf("\t\t\t\t\t\t\t\t --------------------------------- ------------------------\n");
}
void report() {
	//declare variables in report function
	FILE* fptrR, * fptrPR;
	struct PaymentDetail pRecord[100];
	int i = 0, month = 0, count = 0, found = 0, countRecord = 0, x = 0;
	char answer, answer2;
	int countTanKwengHoeLibrary = 0, countDatukLeeLibrary = 0, countComputerLab = 0, countScienceLab = 0, countComputerLab2 = 0, countScienceLab2 = 0, countClassroom1 = 0, countClassroom2 = 0;
	int countMainCafeteria = 0, countLectureOffice = 0, countStudentClinic = 0, countMosque = 0, countSouthClub = 0, countNorthClub = 0, countMainHall = 0, countDatukLimHall = 0, countClassroom3 = 0, countClassroom4 = 0, countLectureHall1 = 0, countLectureHall2 = 0, totalCount = 0;

	//file open for text file
	fptrR = fopen("sanitization.txt", "r");
	//check error for the file open
	if (fptrR == NULL) {
		printf("Error.Unable to open this sanitization.txt\n");
		exit(-1);
	}

	system("cls"); loginHeader(7);

	//header for report function
	printf("\n\n");
	line1();
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tREPORT\n\n");
	line1();
	do {
		//read from sanitization.txt
		while (fscanf(fptrR, "%[^\t]\t%d/%d/%d\t%[^\t]\t%d:%d\t%d:%d\t%[^\t]\t%[^\t]\t\t%[^\t]\t%[^\t]\t%[^\n]\n", &sRecord[i].ID, &sRecord[i].detail.datetime.san_day, &sRecord[i].detail.datetime.san_month, &sRecord[i].detail.datetime.san_year, &sRecord[i].detail.venue,
			&sRecord[i].detail.datetime.start_hour, &sRecord[i].detail.datetime.start_minute, &sRecord[i].detail.datetime.end_hour, &sRecord[i].detail.datetime.end_minute, &sRecord[i].com_Name, &sRecord[i].com_Number, &sRecord[i].contact_Person, &sRecord[i].per_Number, &sRecord[i].address) != EOF) {
			i++;
			count++;
		}
		//file close
		fclose(fptrR);

		//let user to enter a month to create report
		printf("\n\t\t\t\t\t\t\t\tPlease enter a month to create a monthly report for the venue:");
		rewind(stdin);
		scanf("%d", &month);
		//validation check for month to ensure that user only can key 1 to 12
		while (month < 1 || month > 12) {
			printf("\t\t\t\t\t\t\t\tInvalid month!!\n");
			printf("\t\t\t\t\t\t\t\tPlease reenter the month:");
			rewind(stdin);
			scanf("%d", &month);
		}

		for (i = 0; i < count; i++) {
			//compare the month form user input and the month in the text file
			if (month == sRecord[i].detail.datetime.san_month) {
				found++;
				if (found >= 1) {
					if (strcmp(sRecord[i].detail.venue, "TAN KWENG HOE LIBRARY") == 0) {
						countTanKwengHoeLibrary++;
					}
					else if (strcmp(sRecord[i].detail.venue, "DATUK LEE LIBRARY") == 0) {
						countDatukLeeLibrary++;
					}
					else if (strcmp(sRecord[i].detail.venue, "COMPUTER LAB") == 0) {
						countComputerLab++;
					}
					else if (strcmp(sRecord[i].detail.venue, "SCIENCE LAB") == 0) {
						countScienceLab++;
					}
					else if (strcmp(sRecord[i].detail.venue, "COMPUTER LAB 2") == 0) {
						countComputerLab2++;
					}
					else if (strcmp(sRecord[i].detail.venue, "SCIENCE LAB 2") == 0) {
						countScienceLab2++;
					}
					else if (strcmp(sRecord[i].detail.venue, "CLASSROOM 1") == 0) {
						countClassroom1++;
					}
					else if (strcmp(sRecord[i].detail.venue, "CLASSROOM 2") == 0) {
						countClassroom2++;
					}
					else if (strcmp(sRecord[i].detail.venue, "MAIN CAFETERIA") == 0) {
						countMainCafeteria++;
					}
					else if (strcmp(sRecord[i].detail.venue, "LECTURE OFFICE") == 0) {
						countLectureOffice++;
					}
					else if (strcmp(sRecord[i].detail.venue, "STUDENT CLINIC") == 0) {
						countStudentClinic++;
					}
					else if (strcmp(sRecord[i].detail.venue, "MOSQUE") == 0) {
						countMosque++;
					}
					else if (strcmp(sRecord[i].detail.venue, "SOUTH CLUB AND SOCIETY") == 0) {
						countSouthClub++;
					}
					else if (strcmp(sRecord[i].detail.venue, "NORTH CLUB AND SOCIETY") == 0) {
						countNorthClub++;
					}
					else if (strcmp(sRecord[i].detail.venue, "MAIN HALL") == 0) {
						countMainHall++;
					}
					else if (strcmp(sRecord[i].detail.venue, "DATUK LIM HALL") == 0) {
						countDatukLimHall++;
					}
					else if (strcmp(sRecord[i].detail.venue, "CLASSROOM 3") == 0) {
						countClassroom3++;
					}
					else if (strcmp(sRecord[i].detail.venue, "CLASSROOM 4") == 0) {
						countClassroom4++;
					}
					else if (strcmp(sRecord[i].detail.venue, "LECTURE HALL 1") == 0) {
						countLectureHall1++;
					}
					else if (strcmp(sRecord[i].detail.venue, "LECTURE HALL 2") == 0) {
						countLectureHall2++;
					}

				}
			}
		}
		//if the month from user input match with the month in text file,display a report
		if (found >= 1) {
			printf("\n\n\t\t\t\t\t\t\t\t\t\tMonthly Report of ");
			monthInEng(month);
			printf("\n");
			line8();
			printf(" \t\t\t\t\t\t\t\t|              Venue              | Number of Sanitization |\n");
			line9();
			printf(" \t\t\t\t\t\t\t\t|  TAN KWENG HOE LIBRARY          | %-22d |\n", countTanKwengHoeLibrary);
			printf(" \t\t\t\t\t\t\t\t|  DATUK LEE LIBRARY              | %-22d |\n", countDatukLeeLibrary);
			printf(" \t\t\t\t\t\t\t\t|  COMPUTER LAB                   | %-22d |\n", countComputerLab);
			printf(" \t\t\t\t\t\t\t\t|  SCIENCE LAB                    | %-22d |\n", countScienceLab);
			printf(" \t\t\t\t\t\t\t\t|  COMPUTER LAB 2                 | %-22d |\n", countComputerLab2);
			printf(" \t\t\t\t\t\t\t\t|  SCIENCE LAB 2                  | %-22d |\n", countScienceLab2);
			printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 1                    | %-22d |\n", countClassroom1);
			printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 2                    | %-22d |\n", countClassroom2);
			printf(" \t\t\t\t\t\t\t\t|  MAIN CAFETERIA                 | %-22d |\n", countMainCafeteria);
			printf(" \t\t\t\t\t\t\t\t|  LECTURE OFFICE                 | %-22d |\n", countLectureOffice);
			printf(" \t\t\t\t\t\t\t\t|  STUDENT CLINIC                 | %-22d |\n", countStudentClinic);
			printf(" \t\t\t\t\t\t\t\t|  MOSQUE                         | %-22d |\n", countMosque);
			printf(" \t\t\t\t\t\t\t\t|  SOUTH CLUB AND SOCIETY         | %-22d |\n", countSouthClub);
			printf(" \t\t\t\t\t\t\t\t|  NORTH CLUB AND SOCIETY         | %-22d |\n", countNorthClub);
			printf(" \t\t\t\t\t\t\t\t|  MAIN HALL                      | %-22d |\n", countMainHall);
			printf(" \t\t\t\t\t\t\t\t|  DATUK LIM HALL                 | %-22d |\n", countDatukLimHall);
			printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 3                    | %-22d |\n", countClassroom3);
			printf(" \t\t\t\t\t\t\t\t|  CLASSROOM 4	                  | %-22d |\n", countClassroom4);
			printf(" \t\t\t\t\t\t\t\t|  LECTURE HALL 1	          | %-22d |\n", countLectureHall1);
			printf(" \t\t\t\t\t\t\t\t|  LECTURE HALL 2	          | %-22d |\n", countLectureHall2);
			line8();

			//calculation of total number of sanitization in a month
			totalCount = countTanKwengHoeLibrary + countDatukLeeLibrary + countComputerLab + countScienceLab + countComputerLab2 + countScienceLab2 + countClassroom1 + countClassroom2 +
				countMainCafeteria + countLectureOffice + countStudentClinic + countMosque + countSouthClub + countNorthClub + countMainHall + countDatukLimHall + countClassroom3 + countClassroom4 + countLectureHall1 + countLectureHall2;

			printf("\t\t\t\t\t\t\t\tTotal sanitization records are %d in ", totalCount);
			monthInEng(month);
			printf("\n");
		}

		if (found == 0)
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

		printf("\t\t\t\t\t\t\t\tDo you want to continue display report? (Y = yes / N = no)");
		rewind(stdin);
		scanf("%c", &answer);
	} while (toupper(answer) == 'Y');

	//ask user whether he or she want to exit to menu or end the program
	printf("\n\t\t\t\t\t\t\t\tDo you want to exit to sanitization main menu?? (Y = yes / N = no):");
	rewind(stdin);
	scanf("%c", &answer2);
	if (toupper(answer2) == 'Y') {
		system("cls"); loginHeader(7);
		sanitizationMenu();
	}
}
void line() {
	printf("\t\t\t\t\t\t\t\t\t-------------------------------------\n");
}

void sanitizationMenu() {
	int choice;
	system("cls"); loginHeader(7);
	printf("\n");
	printf("                 SSSSSSS         A        NN             N   IIII  TTTTTTTTTTTT  IIII  ZZZZZZZZZZZZZZ         A     TTTTTTTTTTTT  IIII          OOOOO        NN             N\n");
	printf("               SSSS     SS      AAA       NNNN           N   IIII      TTTT      IIII        ZZZZZZZ         AAA        TTTT      IIII       OOOOO    OO     NNNN           N\n");
	printf("               SSSS            AAAAA      NNNNNN         N   IIII      TTTT      IIII       ZZZZZZZ         AAAAA       TTTT      IIII     OOOOOOO     OOO   NNNNNN         N\n");
	printf("                 SSSS         A AAAAA     NNNNNNNN       N   IIII      TTTT      IIII      ZZZZZZZ         A AAAAA      TTTT      IIII    OOOOOOOO      OOO  NNNNNNNN       N\n");
	printf("                   SSSS      A    AAAA    N  NNNNNNNN    N   IIII      TTTT      IIII     ZZZZZZZ         A    AAAA     TTTT      IIII    OOOOOOOO      OOO  N  NNNNNNNN    N\n");
	printf("                    SSSS    A      AAAA   N    NNNNNNNN  N   IIII      TTTT      IIII    ZZZZZZZ         A      AAAA    TTTT      IIII     OOOOOOO     OOO   N    NNNNNNNN  N\n");
	printf("              SS     SSSS  AAAAAAAAAAAAA  N      NNNNNNNNN   IIII      TTTT      IIII   ZZZZZZZ         AAAAAAAAAAAAA   TTTT      IIII       OOOOO    OO     N      NNNNNNNNN\n");
	printf("                SSSSSSS   A          AAAA N        NNNNNNN   IIII      TTTT      IIII  ZZZZZZZZZZZZZZ  A          AAAA  TTTT      IIII          OOOOO        N        NNNNNNN\n\n\n");

	//To let the user select which action they would like to perform
	line();
	printf("\t\t\t\t\t\t\t\t\t\t1. Add in New Records\n");
	printf("\t\t\t\t\t\t\t\t\t\t2. Display Records\n");
	printf("\t\t\t\t\t\t\t\t\t\t3. Search Records\n");
	printf("\t\t\t\t\t\t\t\t\t\t4. Modify Records\n");
	printf("\t\t\t\t\t\t\t\t\t\t5. Delete Records\n");
	printf("\t\t\t\t\t\t\t\t\t\t6. Create Report\n");
	printf("\t\t\t\t\t\t\t\t\t\t7. Exit\n");
	printf("\t\t\t\t\t\t\t\t\t\t8. Back\n");
	line();
	printf("\t\t\t\t\t\t\t\tPlease select the action you'd like to perform (in number) >");
	scanf("%d", &choice);

	//call the function that the user selected
	switch (choice) {
	case 1:add(); break;
	case 2:display(); break;
	case 3:search(); break;
	case 4:modify(); break;
	case 5:deletes(); break;
	case 6:report(); break;
	case 8:adminLoginMenu(); break;
	default: break;
	}
}
