#include"header.h"
struct DateJoined {
	int date, month, year;
};

typedef struct {
	char street[30];
	int pCode;
	char town[15], state[15];
}S_Address;

typedef struct {
	char staff_id[6];
	char name[35], icNo[14], hpNo[14], position[20], dept[5], branch[3], email[30];
	char gender; int age;
	S_Address s_address;
	struct DateJoined dateJoined;
	char password[30];
}AdminInfo;

// 0 = normal / 1 =special
void inputAdmin(char icCheck[12], AdminInfo* admin) {
	int a; int validAlp = 0, count = 0;
	printf("\n\n***For the following section, you may enter XXX to stop if you wish to quit the section***\n\nEnter Name:"); scanf("%[^\n]", admin->name); rewind(stdin);
	if (strcmp("XXX", admin->name) == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->name) > 30)
	{
		printf("Name cannot be null or exceed 30 characters. \nPlease re-enter again:");
		scanf("%[^\n]", admin->name);
		rewind(stdin);
	}

	AdminInfo adminTemp; int foundIC = 0;
	do {
		FILE* checkIC;
		checkIC = fopen("admin.bin", "rb"); foundIC = 0;
		printf("Enter IC NO:"); scanf("%[^\n]", admin->icNo); rewind(stdin);
		if (strcmp("XXX", admin->icNo) == 0) { system("pause"); system("cls"); adminMenu(); } //if user key in XXX ,backt to the menu
		for (a = 0; a < 12; a++) {
			while (strlen(admin->icNo) != 12 || isdigit(admin->icNo[a]) == 0)// equal to false
			{
				printf("Invalid IC Number ! IC number must be 12 numerical digits. \nPlease re-enter again:");
				scanf("%[^\n]", &admin->icNo);
				rewind(stdin);
			}
			foundIC = 0;
		}
		while (fread(&adminTemp, sizeof(AdminInfo), 1, checkIC) != 0)
		{
			if (strcmp(adminTemp.icNo, admin->icNo) == 0) { foundIC = 1; break; } //Compare with existing file, if found duplicated file then re-run again
		}
		if (icCheck != NULL)
		{
			if (strcmp(icCheck, admin->icNo) == 0) { --foundIC;  break; }
		} fclose(checkIC);//if the user key in their own ic then no problem
		if (foundIC == 1) { printf("IC existed. Please key in your own IC number.\n"); foundIC = 1; continue; }
		fclose(checkIC);
	} while (foundIC == 1);
	int gder;
	switch (admin->icNo[11])
	{
	case '1':case '3': case '5': case '7': case '9':
		gder = 1; break; //1 = male
	case '0':case '2': case '4': case '6': case '8':
		gder = 2; break; // 2 = female
	} rewind(stdin);

	printf("Enter Contact Number:"); scanf("%[^\n]", admin->hpNo); rewind(stdin); if (strcmp("XXX", admin->hpNo) == 0) { system("pause"); system("cls"); adminMenu(); }
	for (a = 0; a < 12; a++) {
		while (strlen(admin->icNo) != 12 || isdigit(admin->icNo[a]) == 0)// equal to false
		{
			printf("Invalid IC Number ! IC number must be 12 numerical digits. \nPlease re-enter again:");
			scanf("%[^\n]", &admin->icNo);
			rewind(stdin);
		}
	}
	printf("Enter Position (E.g. Manager):"); scanf("%[^\n]", admin->position); rewind(stdin); if (strcmp("XXX", admin->position) == 0) { system("pause"); system("cls"); adminMenu(); }
	for (a = 0; a < 20; a++) {
		while (strlen(admin->position) > 20)// equal to false
		{
			printf("Position Name Exceeded 20 characters. \nPlease re-enter again:");
			scanf("%[^\n]", &admin->position);
			rewind(stdin);
		}
	}
	printf("Enter Department (E.g. FOCS):"); scanf("%[^\n]", admin->dept); rewind(stdin); if (strcmp(admin->dept, "XXX") == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->dept) > 5)
	{
		printf("Error ! Please enter maximum 5 alphabet only. \nPlease re-enter again:");
		scanf("%[^\n]", &admin->dept);
		rewind(stdin);
	}
	printf("Enter Branch (E.g. PG - for Penang):"); scanf("%[^\n]", admin->branch); rewind(stdin); if (strcmp("XXX", admin->branch) == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->branch) > 2 || isalpha(admin->branch[0]) == 0 || isalpha(admin->branch[1]) == 0)
	{
		printf("Error ! Please enter maximum 2 alphabet only. (E.g. PG) \nPlease re-enter again:");
		scanf("%[^\n]", &admin->branch);
		rewind(stdin);
	}
	printf("Enter Email:"); scanf("%[^\n]", admin->email); rewind(stdin); if (strcmp("XXX", admin->email) == 0) { system("pause"); system("cls"); adminMenu(); }
	do {
		for (a = 0; a < strlen(admin->email); a++) {
			if (admin->email[a] == '@') { count = 1; break; } //if yes -> straight away return
			else count = 0;
		}
		if (count == 0) {
			printf("\n\nInvalid Email ! Missing @. \nPlease re-enter again:");
			scanf("%[^\n]", &admin->email); rewind(stdin);
		}
	} while (count == 0);
	if (gder == 1) { admin->gender = 'M'; }
	else { admin->gender = 'F'; }
	printf("\nGender (F - Female/ M - Male): %c \n", admin->gender);  rewind(stdin);
	printf("Enter Age:"); scanf("%d", &admin->age); rewind(stdin);
	printf("Enter Address:\nStreet:"); scanf("%[^\n]", admin->s_address.street); rewind(stdin); if (strcmp("XXX", admin->s_address.street) == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->s_address.street) > 30)
	{
		printf("Street exceeded 30 characters. \nPlease re-enter again:");
		scanf("%[^\n]", &admin->s_address.street);
		rewind(stdin);
	}
	printf("Postcode:"); scanf("%d", &admin->s_address.pCode);
	int post; post = admin->s_address.pCode; rewind(stdin); count = 0;
	while (post != 0)
	{
		post = post / 10;
		++count;
	}
	while (count != 5)
	{
		rewind(stdin); printf("Postcode exceeded 5 characters. \nPlease re-enter again:");
		scanf("%d", &admin->s_address.pCode); post = admin->s_address.pCode; rewind(stdin); count = 0; while (post != 0)
		{
			post = post / 10;
			++count;
		}
	}
	printf("City /Town /Village:"); scanf("%[^\n]", admin->s_address.town); rewind(stdin); if (strcmp("XXX", admin->s_address.town) == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->s_address.town) > 15)
	{
		printf("City exceeded 15 characters. \nPlease re-enter again:");
		scanf("%[^\n]", &admin->s_address.town);
		rewind(stdin);
	}
	printf("State:"); scanf("%[^\n]", admin->s_address.state); rewind(stdin); if (strcmp("XXX", admin->s_address.state) == 0) { system("pause"); system("cls"); adminMenu(); }
	while (strlen(admin->s_address.state) > 15)
	{
		printf("State exceeded 15 characters. \nPlease re-enter again:");
		scanf("%[^\n]", &admin->s_address.state);
		rewind(stdin);
	}
	//Get date joined
	int valid = 0; // 0 = invalid
	do {
		printf("Date Joined (dd mm yyyy):"); scanf("%d %d %d", &admin->dateJoined.date, &admin->dateJoined.month, &admin->dateJoined.year); rewind(stdin);
		if (admin->dateJoined.year >= 1900 && admin->dateJoined.year <= 2021)
		{
			if (admin->dateJoined.month >= 1 && admin->dateJoined.month <= 12)
			{
				if ((admin->dateJoined.date >= 1 && admin->dateJoined.date <= 31) && (admin->dateJoined.month == 1 || admin->dateJoined.month == 3 || admin->dateJoined.month == 5 || admin->dateJoined.month == 7 || admin->dateJoined.month == 8 || admin->dateJoined.month == 10 || admin->dateJoined.month == 12))
					valid = 1;
				else if ((admin->dateJoined.date >= 1 && admin->dateJoined.date <= 30) && (admin->dateJoined.month == 4 || admin->dateJoined.month == 6 || admin->dateJoined.month == 9 || admin->dateJoined.month == 11))
					valid = 1;
				else if ((admin->dateJoined.date >= 1 && admin->dateJoined.date <= 28) && (admin->dateJoined.month == 2))
					valid = 1;
				else if (admin->dateJoined.date == 29 && admin->dateJoined.month == 2 && (admin->dateJoined.year % 400 == 0 || (admin->dateJoined.year % 4 == 0 && admin->dateJoined.year % 100 != 0)))
					valid = 1;
				else
				{
					valid = 0; printf("Invalid Date\n");
				}
			}
			else { valid = 0; printf("Invalid Month\n"); }
		}
		else { valid = 0; printf("Invalid Year\n"); }
	} while (valid == 0);
}

void doubleLine(int max) {
	int a;
	for (a = 0; a < max; a++)
		printf("=");
	printf("\n");
}

void displayHeader() {
	printf("\n\n\t\t\t\t\t\t\t\tA d m i n    P e r s o n a l    I n f o :\n"); doubleLine(189);
	printf("Staff ID     Name \t\t     IC No. \t\t Contact Number    Position \tDepartment   Branch\t\tEmail \t\t Gender\t  Date Joined\t\tAddress\n");
	doubleLine(189);
}

void displayAdmin(AdminInfo* admin) {
	printf("%-8s   %-25s %-12s\t %-12.11s \t   %-15s %-4s\t\t%-3s\t%-25s  %c\t  %-2d-%-2d-%4d\t %-s\n", admin->staff_id, admin->name, admin->icNo, admin->hpNo, admin->position, admin->dept, admin->branch, admin->email, admin->gender, admin->dateJoined.date, admin->dateJoined.month, admin->dateJoined.year, admin->s_address.street);
	printf("%166.5d, %s %s\n", admin->s_address.pCode, admin->s_address.town, admin->s_address.state);
	//printf("Password: %s\n", admin.password);
}

void displayAllAdmin() {
	AdminInfo adminInfo;
	//Open File 
	FILE* open;
	open = fopen("admin.bin", "rb");
	if (open == NULL)
	{
		printf("ERROR.\n");
		exit(-1);
	}
	displayHeader();
	while (fread(&adminInfo, sizeof(AdminInfo), 1, open) != 0) {
		displayAdmin(&adminInfo);
	}fclose(open);
	system("pause"); system("cls"); adminMenu();
}

int adminMenu() {
	int choice;
	do {
		loginHeader(1);
		printf("\t\t\t\t           AAAAA       DDDDDDDDDD     MMMMMM     MMMMMM   IIIIIIII   NNNNNNN    NNN\n");
		printf("\t\t\t\t           AAAAA        DDDDDDDDDDD    MMMMMM   MMMMMM      IIII      NNNNNNN    N\n");
		printf("\t\t\t\t          AA  AAA       DDDD   DDDDD   MM MMMM MMMM MM      IIII      NNNNNNNN   N\n");
		printf("\t\t\t\t         AA    AAA      DDDD    DDDD   MM  MMMMMMM  MM      IIII      NNN NNNNN  N\n");
		printf("\t\t\t\t        AAAAAAAAAAA     DDDD   DDDD    MM   MMMMM   MM      IIII      NNN  NNNNN N\n");
		printf("\t\t\t\t       AA        AAA    DDDDDDDDDD     MM    MMM    MM      IIII      NNN   NNNNNN\n");
		printf("\t\t\t\t      AAAAA     AAAAA  DDDDDDDDD      MMMM    M    MMMM   IIIIIIII   NNNNN   NNNNN\n");
		printf("\t\t\t\t\t\t\t\t  W E L C O M E   T O   A D M I N   S I D E  ! !\n");
		doubleLine(189);
		printf("\tH i   T h e r e,   p l e a s e   c h o o s e  :\n\n\t\t\t\t\t1.\tRegister/Add New Admin \t\t\t\t 6.\tChange Password\n\t\t\t\t\t2.\tModify/Update Admin Record \t\t\t 7.\tSummary Report\n\t\t\t\t\t3.\tDisplay All Admin Record \t\t\t 8.\tLog Out\n\t\t\t\t\t4.\tSearch Admin Record(s) \t\t\t\t 9.\tExit \n\t\t\t\t\t5.\tDelete Admin (Record) \t\t\t\t 10.\tBack \n\n");
		doubleLine(189); printf("Choice >> "); scanf("%d", &choice);
		rewind(stdin);
		switch (choice)
		{
			//1 for add record
		case 1:addAdmin(); break;
			//2 for modify
		case 2:modifyAdmin(1); break;
			//3 for display
		case 3:displayAllAdmin(); break;
		case 4:// 4 for search
			searchAdmin(); break;
		case 5:deleteAdmin(); break;
		case 6:modifyAdmin(2); break;
		case 7:adminReport(); break;
		case 8:system("pause"); adminLogin(); break;
		case 9:exit(1); break;
		case 10:adminLoginMenu(); break;
		default:
			printf("Invalid Choice Entered.\nPlease Try Again.\n"); system("pause"); system("cls");
			break;
		}
	} while (choice < 1 || choice>10);
	return 0;
}

int checkID(char id[6]) {
	AdminInfo admin; int found = 0;
	FILE* Rptr;
	Rptr = fopen("admin.bin", "rb"); if (Rptr == NULL) { printf("ERROR.\n"); exit(-1); }
	while (fread(&admin, sizeof(admin), 1, Rptr) != 0) {
		if (strcmp(admin.staff_id, id) == 0)
		{
			fclose(Rptr); return 1;
		}//one means founded record
		else found = 0;
	}
	if (found == 0) { fclose(Rptr); return 0; }
	fclose(Rptr);
}

void addAdmin() {
	AdminInfo admin;
	char yesNo; char pass[30]; int valid = 0, validAlp = 0, count = 0, check = 0;
	//read input
	FILE* addAdmin;
	addAdmin = fopen("admin.bin", "ab"); if (addAdmin == NULL) { printf("ERROR.\n"); exit(-1); }
	printf("\nPlease Insert Admin Record:\n"); rewind(stdin);
	do {
		printf("Enter Staff ID (**Enter 00000 to stop):"); fgets(admin.staff_id, 6, stdin); rewind(stdin); admin.staff_id[0] = toupper(admin.staff_id[0]);
		if (strcmp("00000", admin.staff_id) == 0) { fclose(addAdmin); system("pause"); system("cls"); adminMenu(); }
		check = checkID(&admin.staff_id);
		if (check == 1) { printf("\n\nUser Existed. \nPlease with another ID.\n"); count = 0; continue; }
		if (isalpha(admin.staff_id[0]) != 0)//return non-zero means true = is an alphabet
			validAlp = 1;//valid = 1 means we found 1st character is true alphabet
		if (isdigit(admin.staff_id[1]) != 0 && isdigit(admin.staff_id[2]) != 0 && isdigit(admin.staff_id[3]) != 0 && isdigit(admin.staff_id[4]) != 0) count = 1;
		if (!(validAlp == 1 && count == 1)) { printf("\n\nInvalid Staff ID ! \nID must be in only 5 characters and first Letter must be alphabet (E.g. M0001). Please re-enter again:\n"); count = 0; }
	} while (validAlp == 0 || count == 0);
	inputAdmin(NULL, &admin);
	//Get Password
	char ch_store;
	int i = 0;
	printf("\n\nPassword:");
	while ((ch_store = getch()) != 13) {
		if (i < 0)
			i = 0;
		//8 = backspace
		if (ch_store == 8) {
			putch('\b');
			putch(NULL);
			putch(' ');
			putch('\b');
			i--;
			continue;
		}
		admin.password[i++] = ch_store;
		putch('*');
	}
	admin.password[i] = '\0';
	rewind(stdin); i = 0; ch_store = NULL;
	printf("\nRe-enter Password:");
	while ((ch_store = getch()) != 13) {
		if (i < 0)
			i = 0;
		if (ch_store == 8) { //backspace
			putch('\b');
			putch(NULL);
			putch(' ');
			putch('\b');
			i--; continue;
		}
		pass[i++] = ch_store;
		putch('*');
	}
	pass[i] = '\0';
	if (strcmp(admin.password, pass) == 0)
		printf("\nPassword Matched.\n");
	else
	{
		do {
			printf("Error.\nPasswords Not Matched. Please try again.\n");
			printf("\nPassword:");	rewind(stdin); i = 0; ch_store = NULL; while ((ch_store = getch()) != 13) {
				if (i < 0)
					i = 0;
				//8 = backspace
				if (ch_store == 8) {
					putch('\b');
					putch(NULL);
					putch(' ');
					putch('\b');
					i--;
					continue;
				}
				admin.password[i++] = ch_store;
				putch('*');
			}
			admin.password[i] = '\0';
			rewind(stdin); i = 0; ch_store = NULL;
			printf("\nRe-enter Password:"); while ((ch_store = getch()) != 13) {
				if (i < 0)
					i = 0;
				if (ch_store == 8) { //backspace
					putch('\b');
					putch(NULL);
					putch(' ');
					putch('\b');
					i--; continue;
				}
				pass[i++] = ch_store;
				putch('*');
			}
			pass[i] = '\0';
		} while (!(strcmp(admin.password, pass) == 0));
		printf("\nPassword Matched.\n");
	}
	rewind(stdin);
	//get user confirmation
	do {
		printf("\nConfirm save? (Y/N):"); scanf("%c", &yesNo); rewind(stdin);
		switch (yesNo)
		{
		case 'Y':case 'y':
			fwrite(&admin, sizeof(AdminInfo), 1, addAdmin); fclose(addAdmin);
			printf("Record Saved.\n"); valid = 1; break;
		case 'N':case 'n':fclose(addAdmin);
			printf("Cancelled.\n"); valid = 1; break;
		default:
			printf("Invalid response.\n"); valid = 0; break;
		}
	} while (valid == 0);
	system("pause"); system("cls");
	adminMenu(); exit;
}

void singleLine(int maxLen) {
	int a;
	for (a = 0; a < maxLen; a++)
		printf("_");
	printf("\n");
}
void searchAdmin() {
	AdminInfo admin;
	int found = 0; char sInput[30]; int searchNum[6]; //1=ture/exit  --- 0=does not exist
	int pInput; char gInput; int choice; char yesNo;
	do {
		do {
			system("cls"); loginHeader(1);
			printf("\t\t\t\t\t\t\t\t\t<<<<  S e a r c h    B y  >>>>\n"); doubleLine(189);
			printf("\t\t\t\t\t1.\tStaff ID \t\t\t\t\t 7.\tBranch\n\t\t\t\t\t2.\tName \t\t\t\t\t\t 8.\tEmail\n\t\t\t\t\t3.\tIC No \t\t\t\t\t\t 9.\tGender\n\t\t\t\t\t4.\tContact Number \t\t\t\t\t 10.\tAddress (Postcode)\n\t\t\t\t\t5.\tPosition \t\t\t\t\t 11.\tDate (By Year)\n\t\t\t\t\t6.\tDepartment/Faculty \t\t\t\t 12.\tExit\n"); doubleLine(189);
			printf("Choice >> "); scanf("%d", &choice); rewind(stdin);
		} while (choice < 1 || choice >13);
		rewind(stdin);
		FILE* fptr;
		fptr = fopen("admin.bin", "rb");
		switch (choice)
		{
		case 1:
			printf("Please enter Staff ID:");
			scanf("%s", &sInput);
			rewind(stdin); sInput[0] = toupper(sInput[0]);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.staff_id, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 2:
			printf("Please enter Name:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.name, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 3:
			printf("Please enter IC No:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.icNo, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 4:
			printf("Please enter contact number:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.hpNo, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 5:
			printf("Please enter admin position:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.position, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 6:
			printf("Please enter department/faculty:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.dept, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 7:
			printf("Please enter branch:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.branch, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 8:
			printf("Please enter admin email:");
			scanf("%[^\n]", &sInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (strcmp(admin.email, sInput) == 0)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 9:
			printf("Please enter admin gender:");
			scanf("%c", &gInput); gInput = toupper(gInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (gInput == admin.gender)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 11:
			printf("Please enter (Year of) admin joined in the branch:");
			scanf("%d", &pInput);
			rewind(stdin);
			printf("Record Founded:\n"); displayHeader();
			while ((fread(&admin, sizeof(AdminInfo), 1, fptr)) != 0)
			{
				if (pInput == admin.dateJoined.year)
				{
					displayAdmin(&admin); found = 1;
				}
			}break;
		case 12:exit; system("pause"); fclose(fptr); system("cls"); adminMenu(); exit(1); break;
		default:
			printf("Invalid Number.\n"); exit;
			break;
		}if (found == 0)
			printf("\n\t\t\t\t\t\t\t    -------------------- Record not exist----------------------\n");
		fclose(fptr); printf("\n\n\n\n__________________________________________________________________________________<<< End of Result >>>______________________________________________________________________________________\n");
		do { printf("\nContinue to Search ? (Y -Yes / N -No) >> "); scanf("%c", &yesNo); rewind(stdin); yesNo = toupper(yesNo); } while (yesNo != 'Y' && yesNo != 'N');
	} while (yesNo == 'Y');
	system("pause"); system("cls"); adminMenu();
}

void modifyAdmin(int num) { //num = 1 = change personal detail else num = 2 = change password
	int found = 0; char staffID[6]; char yesNo; char curPass[30], conPass[30], savePass[30], curIC[12];
	AdminInfo admin; FILE* fptr;
	if (num == 1) {
		printf("\nTo Modify ");
		printf("\nPlease Enter the Admin ID (Staff ID) that you want to modify/update: "); //make this num = 1
		scanf("%s", staffID); rewind(stdin); staffID[0] = toupper(staffID[0]); num = 1; displayHeader();
	}
	else {
		printf("\n\nChange Password:\n");
		printf("\nPlease Enter the Admin ID (Staff ID): "); //make this num = 2
		scanf("%s", staffID); rewind(stdin); staffID[0] = toupper(staffID[0]); num = 2; displayHeader();
	}
	fptr = fopen("admin.bin", "rb+");
	if (fptr == NULL) {
		printf("ERROR.\n");
		exit(-1);
	}
	while ((fread(&admin, sizeof(admin), 1, fptr) != 0))
	{
		if (strcmp(staffID, admin.staff_id) == 0)
		{
			strcpy(savePass, admin.password); strcpy(curIC, admin.icNo);
			displayAdmin(&admin); found = 1; break;  //make another --> conditio as found==1 && num == 2
		}
	}
	//Update personal details --> no id allow to change pls make modification later
	char ch_store; int i;
	if (found == 1 && num == 1) {
		printf("\nUser %s exits !\nYou may update the information now: \n", staffID);
		inputAdmin(curIC, &admin);
		fseek(fptr, -(long)sizeof(admin), 1);
		do {
			rewind(stdin); printf("\n\nDraft Saved Successfully.\nConfirm Save ? (Y/N):"); scanf("%c", &yesNo); rewind(stdin);
			switch (toupper(yesNo))
			{
			case 'Y':found = 1;
				fwrite(&admin, sizeof(admin), 1, fptr);
				fclose(fptr);
				printf("\n Record Updated.\n");
				break;
			case 'N':
				printf("Cancelled Update Action.\n"); fclose(fptr); found = 1; break;
			default:
				printf("Invalid Response.\n"); found = 2;
				break;
			}
		} while (found == 2);
	}
	//Reset for password
	else if (found == 1 && num == 2) {
		do {
			rewind(stdin); i = 0; ch_store = NULL;
			printf("\nPlease enter the current password:");//get old password and compare it
			while ((ch_store = getch()) != 13) {
				if (i < 0)
					i = 0;
				//8 = backspace
				if (ch_store == 8) {
					putch('\b');
					putch(NULL);
					putch(' ');
					putch('\b');
					i--;
					continue;
				}
				curPass[i++] = ch_store;
				putch('*');
			}
			curPass[i] = '\0';
			rewind(stdin); i = 0; ch_store = NULL;
			if (strcmp(curPass, savePass) == 0) {
				do {
					printf("\n\nEnter New Password:"); while ((ch_store = getch()) != 13) {
						if (i < 0)
							i = 0;
						//8 = backspace
						if (ch_store == 8) {
							putch('\b');
							putch(NULL);
							putch(' ');
							putch('\b');
							i--;
							continue;
						}
						admin.password[i++] = ch_store;
						putch('*');
					}
					admin.password[i] = '\0';
					rewind(stdin); i = 0; ch_store = NULL;
					printf("\nRe-enter Password:");
					while ((ch_store = getch()) != 13) {
						if (i < 0)
							i = 0;
						//8 = backspace
						if (ch_store == 8) {
							putch('\b');
							putch(NULL);
							putch(' ');
							putch('\b');
							i--;
							continue;
						}
						conPass[i++] = ch_store;
						putch('*');
					}
					conPass[i] = '\0';
					rewind(stdin); i = 0; ch_store = NULL;
					if (strcmp(admin.password, conPass) == 0) {
						printf("\nPassword Matched.\n");
						do {
							printf("Confirm save? (Y/N):"); scanf("%c", &yesNo); rewind(stdin); yesNo = toupper(yesNo);
							switch (yesNo) {
							case 'Y':
								fseek(fptr, -(long)(sizeof(admin) - sizeof(admin.staff_id) - sizeof(admin.name) - sizeof(admin.icNo) - sizeof(admin.hpNo) - sizeof(admin.position) - sizeof(admin.dept) - sizeof(admin.branch) - sizeof(admin.email) - sizeof(admin.gender) - sizeof(admin.age) - sizeof(admin.s_address) - sizeof(admin.dateJoined)), 1);
								fwrite(&admin.password, sizeof(admin.password), 1, fptr); printf("\n\nPassword Changed Successfully.\n");
								fclose(fptr); break;
							case 'N':fclose(fptr);
								printf("\nCancelled.\n"); break;
							default:
								printf("\nInvalid response.\n"); break;
							}
						} while (yesNo != 'Y' && yesNo != 'N');
						found = 1; break;
					}
					else
						printf("\nError.\nPasswords Not Matched. Please try again.\n"); found = 0;
				} while (found != 1);
				found = 1;
			}
			else { printf("\n\nIncorrect Password.\nPlease Try Again.\n"); found = 0; }
		} while (found == 0);
	}
	else printf("\n Record Not Found\n");
	fclose(fptr); system("pause"); system("cls"); adminMenu();
}

void deleteAdmin() {
	AdminInfo admin; char yesNo;
	FILE* deletePtr;
	FILE* writePtr;
	int found = 0, rtn; char sInput[6];
	deletePtr = fopen("admin.bin", "rb");
	if (deletePtr == NULL) {
		printf("ERROR.\n");
		exit(-1);
	}
	writePtr = fopen("tempAdmin.bin", "wb");
	if (writePtr == NULL) {
		printf("ERROR.\n");
		exit(-1);
	}
	printf("Delete Admin Record:\n");
	rewind(stdin); printf("\nPlease Enter the Admin ID (Staff ID) that you want to delete: ");
	fgets(sInput, 6, stdin); sInput[0] = toupper(sInput[0]); rewind(deletePtr);
	displayHeader();
	while ((fread(&admin, sizeof(AdminInfo), 1, deletePtr)) != 0)
	{
		if (strcmp(sInput, admin.staff_id) == 0)//delete the rest
		{
			displayAdmin(&admin); found = 1;
		}
		else {
			fwrite(&admin, sizeof(AdminInfo), 1, writePtr);//back up anotherfclose(writePtr);
		}
	}
	if (found == 1) {
		do {
			rewind(stdin); printf("\n\nA record founded.\nConfirm Delete ? (Y/N):"); scanf("%c", &yesNo); rewind(stdin);
			switch (toupper(yesNo))
			{
			case 'Y':
				fclose(deletePtr); fclose(writePtr);
				if (remove("admin.bin") == 0)
				{
					printf("File Remove sucessfully.\n"); if (rename("tempAdmin.bin", "admin.bin") == 0) { printf("Record Deleted Successfully.\n"); }
					else { printf("Error Rename File.\n"); }
				}
				else { printf("Error remove file.\n"); }found = 1;
				break;
			case 'N':
				printf("Cancelled Delete Action.\n"); fclose(deletePtr); fclose(writePtr); found = 1; break;
			default:
				printf("Invalid Response.\n"); found = 2;
				break;
			}
		} while (found == 2);
	}
	else if (found == 0) {
		fclose(deletePtr); fclose(writePtr); printf("No record found with the requested staff ID >> %s\n\n", sInput);
	}
	fclose(deletePtr); system("pause"); system("cls"); adminMenu();
}



void adminLogin() {
	int found = 0; char userID[6], password[30]; char yesNo, ch_store;
	int i = 0;
	//get user id and password
	system("cls"); loginHeader(1);
	do {
		rewind(stdin); printf("\t\t\t\t\t\t\t\t\t** You May Enter XXX To Exit The Program**\n\n\n\t\t\t\t\t\t\t\tEnter User ID : "); scanf("%[^\n]", &userID); rewind(stdin); userID[0] = toupper(userID[0]); if (strcmp("XXX", userID) == 0) { system("pause"); system("cls"); entryInterface(); }
		printf("\n\t\t\t\t\t\t\t\tPassword      : ");
		while ((ch_store = getch()) != 13) {
			if (i < 0)
				i = 0;
			//8 = backspace
			if (ch_store == 8) {
				putch('\b');
				putch(NULL);
				putch(' ');
				putch('\b');
				i--;
				continue;
			}
			password[i++] = ch_store;
			putch('*');
		}
		password[i] = '\0';
		rewind(stdin); i = 0; ch_store = NULL;
		//compare
		AdminInfo admin; FILE* fptr;
		fptr = fopen("admin.bin", "rb");
		if (fptr == NULL) {
			printf("ERROR.\n");
			exit(-1);
		}
		while ((fread(&admin, sizeof(admin), 1, fptr) != 0))
		{
			if (strcmp(userID, admin.staff_id) == 0)
			{
				if (strcmp(password, admin.password) == 0)
				{
					found = 1; fclose(fptr); break;
				}
				else { found = 0; break; }
			}
			else found = 2;
		}
		if (found == 1) {
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t     ! ! ! Login Successfully ! ! !\n"); doubleLine(189); printf("\n");
			fclose(fptr); system("pause"); system("cls"); adminLoginMenu(); break;
		}
		else if (found == 2) { fclose(fptr); system("cls"); loginHeader(1); printf("\t\t\t\t\t\t\t\t\t   User does not exits. Please Try Again:\n"); found = 0; }
		else { fclose(fptr); system("cls"); loginHeader(1); printf("\t\t\t\t\t\t\t\t\t   Incorrect Password !!! Please Try Again:\n"); }
	} while (found == 0);
	exit;
}

void adminReport() {
	AdminInfo admin;
	FILE* open;
	//create varaible to store the counting result 
	int pg2_3F = 0, pg3_4F = 0, pg4_5F = 0, pg2_3M = 0, pg3_4M = 0, pg4_5M = 0; //pg =penang
	int kl2_3F = 0, kl3_4F = 0, kl4_5F = 0, kl2_3M = 0, kl3_4M = 0, kl4_5M = 0; //kl = kuala lumpur
	int pr2_3F = 0, pr3_4F = 0, pr4_5F = 0, pr2_3M = 0, pr3_4M = 0, pr4_5M = 0; //pr = perak 
	int jh2_3F = 0, jh3_4F = 0, jh4_5F = 0, jh2_3M = 0, jh3_4M = 0, jh4_5M = 0; //jh =johor
	int ph2_3F = 0, ph3_4F = 0, ph4_5F = 0, ph2_3M = 0, ph3_4M = 0, ph4_5M = 0; //ph=pahang
	int sb2_3F = 0, sb3_4F = 0, sb4_5F = 0, sb2_3M = 0, sb3_4M = 0, sb4_5M = 0; //sb=sabah
	open = fopen("admin.bin", "rb");
	if (open == NULL) {
		printf("ERROR TO FILE.\n"); exit(-1);
	}
	while (fread(&admin, sizeof(admin), 1, open) != 0) {
		if (admin.age < 31 && admin.gender == 'F') {
			if (strcmp(admin.branch, "PG") == 0) pg2_3F++;
			else if (strcmp(admin.branch, "KL") == 0) kl2_3F++;
			else if (strcmp(admin.branch, "PR") == 0) pr2_3F++;
			else if (strcmp(admin.branch, "JH") == 0) jh2_3F++;
			else if (strcmp(admin.branch, "PH") == 0) ph2_3F++;
			else sb2_3F++;
		}
		else if (admin.age < 31 && admin.gender == 'M') {
			if (strcmp(admin.branch, "PG") == 0) pg2_3M++;
			else if (strcmp(admin.branch, "KL") == 0) kl2_3M++;
			else if (strcmp(admin.branch, "PR") == 0) pr2_3M++;
			else if (strcmp(admin.branch, "JH") == 0) jh2_3M++;
			else if (strcmp(admin.branch, "PH") == 0) ph2_3M++;
			else sb2_3M++;
		}
		else if (admin.age < 41 && admin.gender == 'F') {
			if (strcmp(admin.branch, "PG") == 0) pg3_4F++;
			else if (strcmp(admin.branch, "KL") == 0) kl3_4F++;
			else if (strcmp(admin.branch, "PR") == 0) pr3_4F++;
			else if (strcmp(admin.branch, "JH") == 0) jh3_4F++;
			else if (strcmp(admin.branch, "PH") == 0) ph3_4F++;
			else sb3_4F++;
		}
		else if (admin.age < 41 && admin.gender == 'M') {
			if (strcmp(admin.branch, "PG") == 0) pg3_4M++;
			else if (strcmp(admin.branch, "KL") == 0) kl3_4M++;
			else if (strcmp(admin.branch, "PR") == 0) pr3_4M++;
			else if (strcmp(admin.branch, "JH") == 0) jh3_4M++;
			else if (strcmp(admin.branch, "PH") == 0) ph3_4M++;
			else sb3_4M++;
		}
		else if (admin.age < 70 && admin.gender == 'F') {
			if (strcmp(admin.branch, "PG") == 0) pg4_5F++;
			else if (strcmp(admin.branch, "KL") == 0) kl4_5F++;
			else if (strcmp(admin.branch, "PR") == 0) pr4_5F++;
			else if (strcmp(admin.branch, "JH") == 0) jh4_5F++;
			else if (strcmp(admin.branch, "PH") == 0) ph4_5F++;
			else sb4_5F++;
		}
		else {
			if (strcmp(admin.branch, "PG") == 0) pg4_5M++;
			else if (strcmp(admin.branch, "KL") == 0) kl4_5M++;
			else if (strcmp(admin.branch, "PR") == 0) pr4_5M++;
			else if (strcmp(admin.branch, "JH") == 0) jh4_5M++;
			else if (strcmp(admin.branch, "PH") == 0) ph4_5M++;
			else sb4_5M++;
		}
	}
	int total2_3 = 0, total3_4 = 0, total4_5 = 0, totalF = 0, totalM = 0, totalKL = 0, totalPG = 0, totalPR = 0, totalJH = 0, totalPH = 0, totalSB = 0;
	totalKL = (kl2_3M + kl2_3F + kl3_4M + kl3_4F + kl4_5M + kl4_5F); totalPG = (pg2_3M + pg2_3F + pg3_4M + pg3_4F + pg4_5M + pg4_5F);
	totalPR = (pr2_3M + pr2_3F + pr3_4M + pr3_4F + pr4_5M + pr4_5F); totalJH = (jh2_3M + jh2_3F + jh3_4M + jh3_4F + jh4_5M + jh4_5F);
	totalPH = (ph2_3M + ph2_3F + ph3_4M + ph3_4F + ph4_5M + ph4_5F); totalSB = (sb2_3M + sb2_3F + sb3_4M + sb3_4F + sb4_5M + sb4_5F);
	total2_3 = (kl2_3M + pg2_3M + pr2_3M + jh2_3M + ph2_3M + sb2_3M) + (kl2_3F + pg2_3F + pr2_3F + jh2_3F + ph2_3F + sb2_3F);
	total3_4 = (kl3_4M + pg3_4M + pr3_4M + jh3_4M + ph3_4M + sb3_4M) + (kl3_4F + pg3_4F + pr3_4F + jh3_4F + ph3_4F + sb3_4F);
	total4_5 = (kl4_5M + pg4_5M + pr4_5M + jh4_5M + ph4_5M + sb4_5M) + (kl4_5F + pg4_5F + pr4_5F + jh4_5F + ph4_5F + sb4_5F);
	totalM = (kl2_3M + pg2_3M + pr2_3M + jh2_3M + ph2_3M + sb2_3M) + (kl3_4M + pg3_4M + pr3_4M + jh3_4M + ph3_4M + sb3_4M) + (kl4_5M + pg4_5M + pr4_5M + jh4_5M + ph4_5M + sb4_5M);
	totalF = (kl2_3F + pg2_3F + pr2_3F + jh2_3F + ph2_3F + sb2_3F) + (kl3_4F + pg3_4F + pr3_4F + jh3_4F + ph3_4F + sb3_4F) + (kl4_5F + pg4_5F + pr4_5F + jh4_5F + ph4_5F + sb4_5F);
	system("cls"); singleLine(189); printf("\n"); loginHeader(2); printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__);
	printf("\n\t\t\t\t\t\t S U M M A R Y    R E P O R T    O F    A D M I N    D E T A I L S    :\n");
	printf("\t\t"); doubleLine(130);
	printf("\t\t| \t B r a n c h e s \t| \t  A g e 20-30   \t| \t  A g e 30-40   \t| \t  A g e 40-50   \t||\n");
	printf("\t\t"); doubleLine(160);
	printf("\t\t| \t\t\t\t|     Male\t|    Female     |     Male\t|    Female     |     Male\t|    Female     ||   T o t a l (By Branches)   |\n"); printf("\t\t"); doubleLine(160);
	printf("\t\t|  Kuala Lumpur Main Campus     |     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", kl2_3M, kl2_3F, kl3_4M, kl3_4F, kl4_5M, kl4_5F, totalKL);	printf("\t\t"); singleLine(160);
	printf("\t\t|  Penang Branch Campus   \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", pg2_3M, pg2_3F, pg3_4M, pg3_4F, pg4_5M, pg4_5F, totalPG);	printf("\t\t"); singleLine(160);
	printf("\t\t|  Perak Branch Campus    \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", pr2_3M, pr2_3F, pr3_4M, pr3_4F, pr4_5M, pr4_5F, totalPR);	printf("\t\t"); singleLine(160);
	printf("\t\t|  Johor Branch Campus    \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", jh2_3M, jh2_3F, jh3_4M, jh3_4F, jh4_5M, jh4_5F, totalJH);	printf("\t\t"); singleLine(160);
	printf("\t\t|  Pahang Branch\t\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", ph2_3M, ph2_3F, ph3_4M, ph3_4F, ph4_5M, ph4_5F, totalPH);	printf("\t\t"); singleLine(160);
	printf("\t\t|  Sabah Branch \t\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", sb2_3M, sb2_3F, sb3_4M, sb3_4F, sb4_5M, sb4_5F, totalSB);	printf("\t\t"); singleLine(160);
	printf("\t\t"); doubleLine(130);
	printf("\t\t|    T O T A L (By Gender)\t|     %4d \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\n", (kl2_3M + pg2_3M + pr2_3M + jh2_3M + ph2_3M + sb2_3M), (kl2_3F + pg2_3F + pr2_3F + jh2_3F + ph2_3F + sb2_3F), (kl3_4M + pg3_4M + pr3_4M + jh3_4M + ph3_4M + sb3_4M), (kl3_4F + pg3_4F + pr3_4F + jh3_4F + ph3_4F + sb3_4F), (kl4_5M + pg4_5M + pr4_5M + jh4_5M + ph4_5M + sb4_5M), (kl4_5F + pg4_5F + pr4_5F + jh4_5F + ph4_5F + sb4_5F));	printf("\t\t"); doubleLine(130);
	printf("\t\t|    T O T A L (By Age)   \t|\t     %4d\t\t|\t     %4d\t\t|\t     %4d\t\t||\n", total2_3, total3_4, total4_5);	printf("\t\t"); doubleLine(130);
	printf("\n\n"); printf("\n\t\tT o t a l   Male   : %4d \n\t\tT o t a l   Female : %4d \n", totalM, totalF); printf("\t\t\t\t    "); singleLine(6); printf("\t\tT o t a l   ADMIN  : % 4d\n", (totalF + totalM));
	//show explanation 
	totalM > totalF ? printf("\n\t\tFrom the table above, we can know that MALE is more than female about % d. Beside, ", (totalM - totalF)) : printf("\n\t\tFrom the table above, we can know that FEMALE is more than male about % d.  Beside, ", (totalF - totalM));
	if (total2_3 > total3_4 && total2_3 > total4_5) //2_3 more than 3_4 ? if yes proceed
		printf("most of the admin are aged between 20 -  30.\n");
	else if (total3_4 > total2_3 && total3_4 > total4_5)
		printf("most of the admin are aged between 30 -  40.\n");
	else
		printf("most of the admin are aged between 40 -  50.\n");
	int found = 0;
	if (totalKL == 0) { printf("\n\t\tKuala Lumpur Main Campus Having NO Admin Now ! \n"); found = 1; }
	if (totalPG == 0) { printf("\n\t\tPenang Branch Campus Having NO Admin Now ! \n"); found = 1; }
	if (totalPR == 0) { printf("\n\t\tPerak Branch Campus Having NO Admin Now ! \n"); found = 1; }
	if (totalJH == 0) { printf("\n\t\tJohor Branch Campus Having NO Admin Now ! \n"); found = 1; }
	if (totalPH == 0) { printf("\n\t\tPahang Branch Having NO Admin Now ! \n"); found = 1; }
	if (totalSB == 0) { printf("\n\t\tSabah Branch Having NO Admin Now ! \n"); found = 1; }
	if (found == 1) printf("\n\n\t\tKindly Arrange Now.\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   <<<<<<<< END OF REPORT >>>>>>>>\n"); singleLine(189);
	fclose(open);
	char yesNo;
	do {
		printf("Do You Want To Download (Report) as Text File ? (Y - Yes / N - No ) >> "); scanf("%c", &yesNo); rewind(stdin); yesNo = toupper(yesNo);
		if (yesNo == 'Y') {
			FILE* report;
			report = fopen("report.txt", "w");
			fprintf(report, "\n\t\t\t\t\t     TTTTTTTTTTTTTTTTTTT                  \n");
			fprintf(report, "\t\t\t\t\t  TTTTTTTTTTTTTTTTTTTTTTTTT                  \n");
			fprintf(report, "\t\t\t\t\t TTTTTTTTTTTTTTTTTTTTTTTTTTTT                  \n");
			fprintf(report, "\t\t\t\t\tTTTTTT                  TTTTTT      A     $$$$   &    &   C$$$$C\n");
			fprintf(report, "\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT     $ $    $   $  &    &  C           \n");
			fprintf(report, "\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT    $$A$$   $$R$$  &    &  C         \n");
			fprintf(report, "\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT   $     $  $    $  &&&&    C$$$$CC        \n");
			fprintf(report, "\t\t\t\t\tTTTTTTTTTTTTT    TTTTTTTTTTTTT              \n");
			fprintf(report, "\t\t\t\t\t TTTTTTTTTTTT    TTTTTTTTTTTT    T A R U C    S E J A H T E R A    C O N T A C T - T R A C I N G    S Y S T E M\n");
			fprintf(report, "\t\t\t\t\t  TTTTTTTTTTT    TTTTTTTTTTT                   A D M I N    S U M M A R Y    R E P O R T \n");
			fprintf(report, "\t\t\t\t\t   TTTTTTTTTTTTTTTTTTTTTTT                              T E L : 03-4145 0278\n");
			fprintf(report, "\t\t\t\t\t      TTTTTTTTTTTTTTTTT         \n\n\n\n");
			fprintf(report, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s  %s\n", __DATE__, __TIME__);
			fprintf(report, "\n\t\t\t\t\t\t S U M M A R Y    R E P O R T    O F    A D M I N    D E T A I L S    :\n");
			fprintf(report, "\t\t_______________________________________________________________________________________________________________________________________________________________\n");
			fprintf(report, "\t\t| \t B r a n c h e s \t| \t  A g e 20-30   \t| \t  A g e 30-40   \t| \t  A g e 40-50   \t||\n");
			fprintf(report, "\t\t| \t\t\t\t|     Male\t|    Female     |     Male\t|    Female     |     Male\t|    Female     ||   T o t a l (By Branches)   |\n");
			fprintf(report, "\t\t_______________________________________________________________________________________________________________________________________________________________\n");
			fprintf(report, "\t\t|  Kuala Lumpur Main Campus     |     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", kl2_3M, kl2_3F, kl3_4M, kl3_4F, kl4_5M, kl4_5F, (kl2_3M + kl2_3F + kl3_4M + kl3_4F + kl4_5M + kl4_5F));
			fprintf(report, "\t\t|  Penang Branch Campus   \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", pg2_3M, pg2_3F, pg3_4M, pg3_4F, pg4_5M, pg4_5F, (pg2_3M + pg2_3F + pg3_4M + pg3_4F + pg4_5M + pg4_5F));
			fprintf(report, "\t\t|  Perak Branch Campus    \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", pr2_3M, pr2_3F, pr3_4M, pr3_4F, pr4_5M, pr4_5F, (pr2_3M + pr2_3F + pr3_4M + pr3_4F + pr4_5M + pr4_5F));
			fprintf(report, "\t\t|  Johor Branch Campus    \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", jh2_3M, jh2_3F, jh3_4M, jh3_4F, jh4_5M, jh4_5F, (jh2_3M + jh2_3F + jh3_4M + jh3_4F + jh4_5M + jh4_5F));
			fprintf(report, "\t\t|  Pahang Branch\t\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", ph2_3M, ph2_3F, ph3_4M, ph3_4F, ph4_5M, ph4_5F, (ph2_3M + ph2_3F + ph3_4M + ph3_4F + ph4_5M + ph4_5F));
			fprintf(report, "\t\t|  Sabah Branch \t\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\t      %4d\t       |\n", sb2_3M, sb2_3F, sb3_4M, sb3_4F, sb4_5M, sb4_5F, (sb2_3M + sb2_3F + sb3_4M + sb3_4F + sb4_5M + sb4_5F));
			fprintf(report, "\t\t_______________________________________________________________________________________________________________________________________________________________\n");
			fprintf(report, "\t\t|    T O T A L (By Gender)\t|     %4d \t|     %4d\t|     %4d\t|     %4d\t|     %4d\t|     %4d\t||\n", (kl2_3M + pg2_3M + pr2_3M + jh2_3M + ph2_3M + sb2_3M), (kl2_3F + pg2_3F + pr2_3F + jh2_3F + ph2_3F + sb2_3F), (kl3_4M + pg3_4M + pr3_4M + jh3_4M + ph3_4M + sb3_4M), (kl3_4F + pg3_4F + pr3_4F + jh3_4F + ph3_4F + sb3_4F), (kl4_5M + pg4_5M + pr4_5M + jh4_5M + ph4_5M + sb4_5M), (kl4_5F + pg4_5F + pr4_5F + jh4_5F + ph4_5F + sb4_5F));
			fprintf(report, "\t\t==================================================================================================================================\n");
			fprintf(report, "\t\t|    T O T A L (By Age)   \t|\t     %4d\t\t|\t     %4d\t\t|\t     %4d\t\t||\n", total2_3, total3_4, total4_5);
			fprintf(report, "\t\t==================================================================================================================================\n");
			fprintf(report, "\n\n"); fprintf(report, "\n\t\tT o t a l   Male   : %4d \n\t\tT o t a l   Female : %4d \n", totalM, totalF); fprintf(report, "\t\tT o t a l   ADMIN  : % 4d\n", (totalF + totalM));
			totalM > totalF ? fprintf(report, "\n\t\tFrom the table above, we can know that MALE is more than female about % d. Beside, ", (totalM - totalF)) : fprintf(report, "\n\t\tFrom the table above, we can know that FEMALE is more than male about % d.  Beside, ", (totalF - totalM));
			if (total2_3 > total3_4 && total2_3 > total4_5) //2_3 more than 3_4 ? if yes proceed
				fprintf(report, "most of the admin are aged between 20 -  30.\n");
			else if (total3_4 > total2_3 && total3_4 > total4_5)
				fprintf(report, "most of the admin are aged between 30 -  40.\n");
			else
				fprintf(report, "most of the admin are aged between 40 -  50.\n");
			int found = 0;
			if (totalKL == 0) { fprintf(report, "\n\t\tKuala Lumpur Main Campus Having NO Admin Now ! \n"); found = 1; }
			if (totalPG == 0) { fprintf(report, "\n\t\tPenang Branch Campus Having NO Admin Now ! \n"); found = 1; }
			if (totalPR == 0) { fprintf(report, "\n\t\tPerak Branch Campus Having NO Admin Now ! \n"); found = 1; }
			if (totalJH == 0) { fprintf(report, "\n\t\tJohor Branch Campus Having NO Admin Now ! \n"); found = 1; }
			if (totalPH == 0) { fprintf(report, "\n\t\tPahang Branch Having NO Admin Now ! \n"); found = 1; }
			if (totalSB == 0) { fprintf(report, "\n\t\tSabah Branch Having NO Admin Now ! \n"); found = 1; }
			if (found == 1) fprintf(report, "\n\n\t\tKindly Arrange Now.\n");
			fprintf(report, "\n\n\n\t\t\t\t\t\t\t\t\t   <<<<<<<< END OF REPORT >>>>>>>>\n");
			fclose(report); printf("\nFile Downloaded Successfully.\n");
		}
		else if (yesNo == 'N')  printf("\n\nCancelled Download.\n");
		else printf("\nInvalid Choice ! Please re-enter again :\n");
	} while (yesNo != 'Y' && yesNo != 'N');
	system("pause"); system("cls"); adminMenu();
}
