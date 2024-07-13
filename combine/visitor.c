#include "header.h"


// Function to check the character           EMAIL VALIDATION TILL LINE 129
// is an alphabet or not 

int isChar(char emailChar)
{
	if ((emailChar >= 'a' && emailChar <= 'z') || (emailChar >= 'A' && emailChar <= 'Z')) {
		return 1;
	}
	else return 0;
}


// Function to check email id is 
// valid or not 
int is_valid(char email[50])
{
	// Check the first character 
	// is an alphabet or not 
	if (isChar(email[0] == 0)) {

		// If it's not an alphabet 
		// email id is not valid 
		return 0;
	}


	// Variable to store position 
	// of At and Dot 
	int At = -1, Dot = -1;

	// Traverse over the email id 
	// string to find position of 
	// Dot and At 


	for (int i = 0; i < strlen(email); i++) {

		// If the character is '@' 
		if (email[i] == '@') {

			At = i;
		}

		// If character is '.' 
		else if (email[i] == '.') {

			Dot = i;
		}
	}

	// If either @ or '.'  is not present 
	if (At == -1 || Dot == -1) {
		return 0;
	}
	// If Dot is present before At 
	else if (At > Dot) {
		return 0;
	}

	// If Dot is present at the end 
	else if (Dot >= (strlen(email) - 1)) {
		return 0;
	}
	// If everything is validated, return 1
	else return 1;
}


void visitorInfoMenu() {

	int adminMenuChoice, validMenuChoice;

	do {
		printf("\n\n");
		printf("\t\t\t   =============================================\n");
		printf("\t\t\t   |          ADMIN INFORMATION MENU           |\n");
		printf("\t\t\t   |                                           |\n");
		printf("\t\t\t   |   ( 1 ) - DELETE VISITOR ACCOUNT          |\n");
		printf("\t\t\t   |   ( 2 ) - DISPLAY ALL VISITOR RECORD      |\n");
		printf("\t\t\t   |   ( 3 ) - SEARCH USER INFORMATION         |\n");
		printf("\t\t\t   =============================================\n");

		//user enter choice
		printf("\n\nYour option?                   >");
		scanf("%d", &adminMenuChoice);
		rewind(stdin);

		switch (adminMenuChoice) {
		case 1:
			deleteFunction();
			validMenuChoice = 0;
			break;
		case 2:
			displayRecordFunction();
			validMenuChoice = 0;
			break;
		case 3:
			searchFunction();
			validMenuChoice = 0;
			break;
		default:
			printf("\n\nERROR. Please choose the available options.");
			system("pause");
			system("cls");
			validMenuChoice = 0;
			break;
		}

	} while (validMenuChoice != 1);

}


Validation universalCharacterCheck(char inputCharacter[]) {

	/*int inputArray[5] = { 0 }*/
	Validation outputCharacter;
	int qCharacter = 0;
	int qAlphabet = 0, qDigit = 0, qSpecialCharacter = 0, qSpace = 0, qSpecialCharacterWithoutSpace = 0;


	/* Checks each character of string*/

	while (inputCharacter[qCharacter] != '\0')
	{
		if ((inputCharacter[qCharacter] >= 'a' && inputCharacter[qCharacter] <= 'z') ||
			(inputCharacter[qCharacter] >= 'A' && inputCharacter[qCharacter] <= 'Z'))
		{
			qAlphabet++;
		}
		else if (inputCharacter[qCharacter] >= '0' && inputCharacter[qCharacter] <= '9')
		{
			qDigit++;
		}
		else if (inputCharacter[qCharacter] == ' ')
		{
			qSpace++;
			qSpecialCharacter++;
		}
		else
		{
			qSpecialCharacter++;
			qSpecialCharacterWithoutSpace++;
		}
		qCharacter++;
	}

	outputCharacter.noCharacter = qCharacter;
	outputCharacter.noAlphabet = qAlphabet;
	outputCharacter.noDigit = qDigit;
	outputCharacter.noSpecialCharacter = qSpecialCharacter;
	outputCharacter.noSpace = qSpace;
	outputCharacter.noSpecialCharacterWithoutSpace = qSpecialCharacterWithoutSpace;

	return outputCharacter;
}


int h2HorizontalRule() {
	printf("--------------------------------------------------\n");
}

int h1HorizontalRule() {
	printf("==================================================\n");
}

int h3HorizontalRule() {
	printf("-----------------------\n");
}

void visitorMenu() {
	//Validation mainTempStruct;
	int tfLoop = 0;    // for text file scanning
	int mainMenuChoice = 0;
	int totalNumberOfAccount = 0;
	system("cls"); loginHeader(4);
	printf("\t\t\t\t\t\t\t\t    "); h1HorizontalRule();//==================================================
	printf("\t\t\t\t\t\t\t\t\t     The Vistitor Information Module\n");
	printf("\t\t\t\t\t\t\t\t    "); h1HorizontalRule();//==================================================

	printf("\t\t\t\t\t\t\t\t\t                  WELCOME                        \n");
	printf("\t\t\t\t\t\t\t\t\t                  -------                       \n\n\n");

	time_t t;
	time(&t);
	printf("\t\t\t\t\t\t\t\tThe current date and time is: %s\n", ctime(&t));
	//printf("\t\t\t\t\t\t\t\tThe current date and time is: %s\n", "TIME");


	printf("\n\n\t\t\t\t\t\t\t\tMain Menu.\n");
	printf("\t\t\t\t\t\t\t\t----------\n\n");
	printf("\t\t\t\t\t\t\t\t\t1. Login.\n");
	printf("\t\t\t\t\t\t\t\t\t2. Register.\n");
	printf("\t\t\t\t\t\t\t\t\t3. Back.\n");
	printf("\t\t\t\t\t\t\t\t\t4. Exit.\n");
	printf("\n\n\t\t\t\t\t\t\t\tWhat would you like to do now?    >");

	do {

		rewind(stdin);
		scanf("%d", &mainMenuChoice);
		switch (mainMenuChoice) {
		case 1:
			printf("\t\t\tYou will now be directed to the Login page. Please press [ENTER] to proceed.\n");

			system("cls"); loginHeader(4);
			visitorLogin();
			break;
		case 2:printf("\t\t\tYou will now be directed to the Register page. Please press [ENTER] to proceed.\n");

			system("cls"); loginHeader(4);
			visitorRegisterAccount();

			break;
		case 3:
			entryInterface();
			break;
		case 4:printf("\t\t\tThank you for using our programme.\n\n");

			exit(0);
		default:
			printf("\n\t\t\tERROR. Please enter the available options.      >");



		}


	} while (mainMenuChoice != 1 && mainMenuChoice != 2 && mainMenuChoice != 3);

}

void visitorLogin() {//==========================================

	system("cls"); loginHeader(4);
	// variables
	VisitorInfo login[1000];

	Validation loginTempStruct;
	char currentUserId[10];

	int validationUserId;
	int registerAccountResult = 0;

	char visitorPassword[50];
	int passwordValidation = 0;

	int endLoginOption;

	printf("\t\t\t\t\t\t\t\t    "); h2HorizontalRule();
	printf("\t\t\t\t\t\t\t\t                        LOGIN          \n");
	printf("\t\t\t\t\t\t\t\t                        -----          \n");
	printf("\t\t\t\t\t\t\t\t    "); h2HorizontalRule();
	//LIST OF MODULE
	//--------------

	//1. characterCheck();    //Check number of character (12)/ no special character / no alphabets 
	do {
		// Validation to exclude (> or < 12 char/alphabnets/special characters)
		printf("\n\n\t\t\t\t\t\t\tPlease enter your User ID No. [4 Characters]         > ");
		rewind(stdin);
		scanf("%[^\n]", &currentUserId);
		strupr(currentUserId);
		printf("\n\n");

		/*universalCharacterCheck(newAcc.visitorIcNo,registerTempStruct);*/
		loginTempStruct = universalCharacterCheck(currentUserId);


		if (loginTempStruct.noCharacter < 4 || loginTempStruct.noCharacter > 4) {
			/*system("cls");*/
			printf("\t\t\t\t\t\t\tERROR. You have entered %d character(s). Please try again\n\n", loginTempStruct.noCharacter);
			validationUserId = 0;
		}
		else if (loginTempStruct.noSpecialCharacter > 0) {
			printf("\t\t\t\t\t\t\tERROR. You have entered %d special character(s). Please try again\n\n", loginTempStruct.noSpecialCharacter);
			validationUserId = 0;
		}
		else if (loginTempStruct.noAlphabet > 1 || loginTempStruct.noAlphabet < 1) {
			printf("\t\t\t\t\t\t\tERROR. You have entered %d alphabet(s). Please try again\n\n", loginTempStruct.noAlphabet);
			validationUserId = 0;
		}
		else if (loginTempStruct.noDigit > 4 && loginTempStruct.noDigit <= 4)
		{
			printf("\t\t\t\t\t\t\tERROR. You have entered %d digits(s). Please try again.\n\n", loginTempStruct.noDigit);
			validationUserId = 0;
		}
		else {
			validationUserId = 1;
		}

	} while (validationUserId != 1);



	//2. Check the existence of the visitor account/ if not, proceed to registry modul

	int existenceCheckLp = 0;
	int existenceCheckIcNoResult = 0;


	//OPEN TEXT FILE AND FOR READING (strcmp current userID with existing userID)
	FILE* loginFptr;
	loginFptr = fopen("visitor-info-database2.txt", "r");

	while (loginFptr == NULL) {
		printf("\t\t\t\t\t\t\tERROR. File cannot be open due to not found.");
		exit(-1);
	}

	int i = 0;
	int num = 0;
	int compareUserId = 0;

	while (fscanf(loginFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &login[i].visitorUserId, &login[i].visitorIcNo, &login[i].visitorPassportNo, &login[i].visitorName, &login[i].visitorGender, &login[i].visitorBd.day, &login[i].visitorBd.month, &login[i].visitorBd.year, &login[i].visitorEmail, &login[i].visitorContactNo, &login[i].visitorAccStatus, &login[i].visitorAccStatus) != EOF)
	{

		i++;
	}

	fclose(loginFptr);

	for (int num = 0; num < i; num++) {

		if (strcmp(currentUserId, login[num].visitorUserId) == 0 && login[num].visitorAccStatus == 1) {
			existenceCheckIcNoResult = 1;
		}
		else if (strcmp(currentUserId, login[num].visitorUserId) == 0 && login[num].visitorAccStatus == 0) {
			printf("\n\t\t\t\t\t\t\tYour account was terminated. You are required to Register for a new account.\n");
			existenceCheckIcNoResult = 0;
		}
	}
	char currentPassword[100];
	if (existenceCheckIcNoResult != 1) {

		//prompt to ask user if they want to register a new account
		printf("\n\t\t\t\t\t\t\tThere is no matching account found.          \n");
		printf("\t\t\t\t\t\t\t1 - Register\n\t\t\t\t\t\t\t2 - Retry\n\t\t\t\t\t\t\t3 - Exit\n");

		printf("\t\t\t\t\t\t\tWould you like to do now?                            >");

		do {
			rewind(stdin);
			scanf("%d", &endLoginOption);

			switch (endLoginOption) {
			case 1:
				printf("\n\t\t\t\t\t\t\tYou will now be directed to the Register page. Please press [ENTER] to continue.\n\n");

				system("cls"); loginHeader(4);
				visitorRegisterAccount();
				break;

			case 2:
				passwordValidation = 0;
				system("cls"); loginHeader(4);
				visitorLogin();
				endLoginOption = 0;
				break;
			case 3:
				printf("\n\t\t\t\t\t\t\t\tThank you.\n");
				exit(0);
				break;


			default:
				printf("\t\t\t\t\t\t\tERROR. Please select the options. (1/2/3)     > ");
				break;
			}
		} while (endLoginOption != 1 && endLoginOption != 2 && endLoginOption != 3);
	}
	// prompt user to input their password
	char ch_store;
	do {
		i = 0; ch_store = NULL;
		printf("\n\t\t\t\t\t\t\tPlease input password  (Type 'XXX' to MENU )         > ");
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
			currentPassword[i++] = ch_store;
			putch('*');
		}
		currentPassword[i] = '\0'; i = 0; ch_store = NULL;
		if (strcmp(currentPassword, "xxx") == 0 || strcmp(currentPassword, "XXX") == 0) {
			printf("\n\n\t\t\t\t\t\t\t\tThank you for using our application.\n");
			system("cls"); loginHeader(4);
			visitorMenu();
		}

		FILE* pwFptr;
		pwFptr = fopen("password.txt", "r");

		while (pwFptr == NULL) {
			printf("\n\t\t\t\t\t\t\tERROR. File cannot be open due to not found.");
			exit(-1);
		}

		while (fscanf(pwFptr, "%[^\n]\n", &visitorPassword) != EOF) {

			if (strcmp(currentPassword, visitorPassword) == 0) {
				passwordValidation = 1;
				break;
			}
			i++;
		}
		if (passwordValidation == 1) {
			printf("\n\t\t\t\t\t\t\t\t\tLogin successful.\n");
			system("pause");
			system("cls"); loginHeader(4);
			profileMenu(currentUserId);
		}
		else {
			printf("\n\t\t\t\t\t\t\tPassword does not match. Please try again. ( Press XXX to exit )\n\n");
		}
	} while (passwordValidation != 1);
}

void visitorRegisterAccount() {
	{
		system("cls"); loginHeader(4);
		h2HorizontalRule();//----------------------------------
		printf("                 Account Registration\n");
		h2HorizontalRule();//----------------------------------
		printf("Please enter your credentials accordingly.\n\n\n");

		/*int registerValidationArray[6] = { 0,0,0,0,0 };*/

		Validation registerTempStruct = { 0,0,0,0,0 };
		VisitorInfo newAcc;
		int registerUserId = 0, registerIcNo = 0, registerPassportNo = 0, registerName = 0, registerGender = 0, registerBdDay = 0, registerBdMonth = 0, registerBdYear = 0, registerEmail = 0, registerContactNo = 0, registerAddress = 0, registerPassword = 0;
		char citizenship = 0;
		int citizenshipStatus = 0; // 1 = local, 0= foreigner

		// ASK IF VISITOR IS LOCAL OR FOREIGNER
		do {
			printf("\nAre you a Malaysia? (Y/N)      >");
			rewind(stdin);
			scanf("%c", &citizenship);
			citizenship = toupper(citizenship);

			if (citizenship == 'Y') {
				citizenshipStatus = 1;
			}
			else  if (citizenshipStatus == 'N') {
				citizenshipStatus = 0;
			}
		} while (citizenship != 'Y' && citizenship != 'N');

		if (citizenshipStatus == 1) { // citizenshipStatus 1 = local 

				// if its local user, passportNo default '---', visitorCountry = MALAYSIA

			strcpy(newAcc.visitorPassportNo, "---");

			//----REGISTER: Input new visitor ic number FOR LOCALS!!!!!!!!!
			do {
				printf("\n");
				printf("Identity Card number (according to the Identity Card)               >");
				rewind(stdin);
				scanf("%[^\n]", &newAcc.visitorIcNo);

				//send new icNo for characterCheck
				registerTempStruct = universalCharacterCheck(newAcc.visitorIcNo);

				if (registerTempStruct.noCharacter != 12) {
					//if the number of character of the IC is not accurately 12
					printf("ERROR. You have entered %d character(s). Please try again\n\n", registerTempStruct.noCharacter);
					registerIcNo = 0;
				}
				else if (registerTempStruct.noSpecialCharacter > 0) {
					//if there is more than one special character including space
					printf("ERROR. You have entered %d special character(s). Please try again\n\n", registerTempStruct.noSpecialCharacter);
					registerIcNo = 0;
				}
				else if (registerTempStruct.noAlphabet > 0) {
					//if there is more than one alphabat character 
					printf("ERROR. You have entered %d alphabet(s). Please try again\n\n", registerTempStruct.noAlphabet);
					registerIcNo = 0;
				}
				else {
					//if all character validation is correct 
					registerIcNo = 1;
				}

			} while (registerIcNo == 0);

		}
		else { // citizenStatus 0 = foreigner
				// if user is foreigner, icNo default to '---'
			strcpy(newAcc.visitorIcNo, "---");

			//----REGISTER: Input new visitor passport  number FOR FOREIGNER!@!!!!!!
			do {
				printf("\nPassport number (according to the Passport)                       >");
				rewind(stdin);
				scanf("%[^\n]", &newAcc.visitorPassportNo);

				// Enter 
				registerTempStruct = universalCharacterCheck(newAcc.visitorPassportNo);

				if (registerTempStruct.noCharacter < 6 || registerTempStruct.noCharacter > 6) {
					/*system("cls");*/
					printf("ERROR. You have entered %d character(s). Please try again\n\n\n", registerTempStruct.noCharacter);
					registerPassportNo = 0;
				}
				else if (registerTempStruct.noSpecialCharacter > 0) {
					/*system("cls");*/
					printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", registerTempStruct.noSpecialCharacter);
					registerPassportNo = 0;
				}
				else if (registerTempStruct.noAlphabet > 1 || registerTempStruct.noAlphabet < 1) {
					/*system("cls");*/
					printf("ERROR. You have entered %d alphabet(s). Please try again\n\n\n", registerTempStruct.noAlphabet);
					registerPassportNo = 0;
				}
				else if (registerTempStruct.noDigit > 5 && registerTempStruct.noDigit < 5)
				{
					printf("ERROR. You have entered %d digits(s). Please try again\n\n\n", registerTempStruct.noDigit);
					registerPassportNo = 0;
				}
				else {
					registerPassportNo = 1;
				}

			} while (registerPassportNo == 0);
		}
		//----REGISTER: Input new visitor name
		do {

			printf("\n\n");
			printf("Full Name (FULL CAPS according to the Identity Card)                >");
			rewind(stdin);
			scanf("%[^\n]", newAcc.visitorName);
			strupr(newAcc.visitorName);
			//	char name2[200] = "  ";
			///	name2 = strupr(newAcc.visitorName);

			registerTempStruct = universalCharacterCheck(newAcc.visitorName);

			if (registerTempStruct.noCharacter < 0 || registerTempStruct.noCharacter > 150) {
				/*system("cls");*/
				printf("ERROR. You have entered %d character(s). Please try again\n\n\n", registerTempStruct.noCharacter);
				registerName = 0;
			}

			else if (registerTempStruct.noSpecialCharacterWithoutSpace > 0) {

				printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", registerTempStruct.noSpecialCharacterWithoutSpace);
				registerName = 0;
			}
			else if (registerTempStruct.noDigit > 0)
			{
				printf("ERROR. You have entered %d digits(s). Please try again\n\n\n", registerTempStruct.noDigit);
				registerName = 0;
			}

			else {
				/*printf("Character check register name success. Proceed.\n");*/
				registerName = 1;
			}

		} while (registerName != 1);


		//REGISTER: Input new visitor gender
		do {
			printf("\n\n");
			rewind(stdin);
			printf("Gender  (M = MALE / F = FEMALE)                                     >");
			scanf("%c", &newAcc.visitorGender);
			newAcc.visitorGender = toupper(newAcc.visitorGender);
			//gender = newAcc.visitorGender;

			switch (newAcc.visitorGender) {
			case 'M':
				registerGender = 1; break;
			case 'F':
				registerGender = 1; break;
			default:
				printf("ERROR. Please choose the available options.");
				registerGender = 0; break;
			}

		} while (registerGender != 1);

		////REGISTER: Input new visitor birthdate
		do {// validate date of birth (day)

			char tempDay[10] = " ";
			printf("\n\n");
			printf("Date of Birth [day]    (1-31)                                       >");
			rewind(stdin);
			scanf("%s", &tempDay);

			int dayLength = 0;
			dayLength = strlen(tempDay);

			for (int i = 0; i < dayLength; i++)
			{
				if (isdigit(tempDay[i]) != 0) {
					//if user input digits
					registerBdDay = 1;
				}

				else {
					// if user input other than digits
					registerBdDay = 0;
					break;
				}
			}

			newAcc.visitorBd.day = atoi(tempDay);

			if (registerBdDay == 1 && newAcc.visitorBd.day < 32 && newAcc.visitorBd.day >0) {
				registerBdDay = 1;
			}
			else {
				printf("\nERROR. Your input in invalid. Please try again.");
				registerBdDay = 0;
			}

		} while (registerBdDay != 1);


		do {// validate date of birth (month)

			char tempMonth[10] = " ";
			printf("\n\n");
			printf("Date of Birth [month]    (1-12)                                     >");
			rewind(stdin);
			scanf("%s", &tempMonth);

			int monthLength = 0;
			monthLength = strlen(tempMonth);

			for (int i = 0; i < monthLength; i++)
			{
				if (isdigit(tempMonth[i]) != 0) {
					//if user input digits
					registerBdMonth = 1;
				}

				else {
					// if user input other than digits
					registerBdMonth = 0;
					break;
				}
			}

			newAcc.visitorBd.month = atoi(tempMonth);

			if (registerBdMonth == 1 && newAcc.visitorBd.month < 13 && newAcc.visitorBd.month >0) {
				registerBdMonth = 1;
			}
			else {
				printf("\nERROR. Your input in invalid. Please try again.");
				registerBdMonth = 0;
			}

		} while (registerBdMonth != 1);
		do {// validate date of birth (year)

			char tempYear[10] = " ";
			printf("\n\n");
			printf("Date of Birth [year]                                                >");
			rewind(stdin);
			scanf("%s", &tempYear);

			int yearLength = 0;
			yearLength = strlen(tempYear);

			for (int i = 0; i < yearLength; i++)
			{
				if (isdigit(tempYear[i]) != 0) {
					//if user input digits
					registerBdYear = 1;
				}

				else {
					// if user input other than digits
					registerBdYear = 0;
					break;
				}
			}

			newAcc.visitorBd.year = atoi(tempYear);

			if (registerBdYear == 1 && newAcc.visitorBd.year > 1900 && newAcc.visitorBd.year < 2021) {
				registerBdYear = 1;
			}
			else {
				printf("\nERROR. Your input in invalid. Please try again.");
				registerBdYear = 0;
			}

		} while (registerBdYear != 1);

		//REGISTER: Input new visitor email // different type of validation !!!
		do {
			printf("\n\n");
			printf("Email Address ( e.g. jsmith@example.com)                            >");
			rewind(stdin);
			scanf("%[^\n]", &newAcc.visitorEmail);
			//newAcc.visitorEmail[49] = strupr(newAcc.visitorEmail);

			registerEmail = is_valid(newAcc.visitorEmail);

			if (registerEmail != 1) {
				// email is fail
				printf("\nERROR. Please try again.\n");
			}

		} while (registerEmail != 1);

		//REGISTER: Input new contact number
		do {

			printf("\n\n");
			printf("Contact Number    (e.g. 012 3456789)                                >");
			rewind(stdin);
			scanf("%[^\n]", &newAcc.visitorContactNo);

			registerTempStruct = universalCharacterCheck(newAcc.visitorContactNo);

			if (registerTempStruct.noCharacter < 0 || registerTempStruct.noCharacter > 13) {
				/*system("cls");*/
				printf("ERROR. You have entered %d character(s). Please try again\n\n\n", registerTempStruct.noCharacter);
				registerContactNo = 0;
			}
			else if (registerTempStruct.noSpecialCharacterWithoutSpace > 0) {
				printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", registerTempStruct.noSpecialCharacterWithoutSpace);
				registerContactNo = 0;
			}
			else if (registerTempStruct.noSpace != 1) {
				printf("ERROR. You have entered %d space(s). Please try again\n\n\n", registerTempStruct.noSpace);
				registerContactNo = 0;
			}
			else {

				registerContactNo = 1;
			}
		} while (registerContactNo != 1);

		//REGISTER: Input new address
		 //(citizenshipStatus != 1) {// citizenship status 1= local, 2= foreigner
		do {
			printf("\n\n");
			printf("Home Address  (FULL CAPS according to the Identity Card)            >");
			rewind(stdin);
			scanf("%[^\n]", &newAcc.visitorAddress);
			strupr(newAcc.visitorAddress);
			if (newAcc.visitorAddress == " ") {
				registerAddress = 0;
			}
			else {
				registerAddress = 1;
			}

		} while (registerAddress != 1);

		//REGISTER: Input new user password for new user 
		char newPassword[15] = " ";
		do {
			printf("\n\n");
			printf("Please enter your new password (at least 15 characters)             >");
			rewind(stdin);
			scanf("%[^\n]", &newPassword);
			registerPassword = 1;
		} while (registerPassword != 1);

		//conformation
		FILE* registerFptr;
		char registerConfirmation;
		int createUserId = 0;

		do {
			printf("\n\n");
			printf("Comfirmation to register for a new account (Y/N)                    >");
			rewind(stdin);
			scanf("%c", &registerConfirmation);
			registerConfirmation = toupper(registerConfirmation);

			switch (registerConfirmation) {
			case 'Y':
				//if yes,  ..... need to assign the new visitor a new USER ID (e.g V001)
				createUserId = 1;
				break;
			case 'N':
				//if no, straight exit or go back menu
				printf("\n\nRegistration is CANCELLED. You are now directed to the main menu.\n\n");
				system("cls"); loginHeader(4);
				/*main();*/
				break;
			default:
				printf("ERROR. Please choose the available options.\n");
				break;
			}
		} while (registerConfirmation != 'Y' && registerConfirmation != 'N' && registerConfirmation != 'n' && registerConfirmation != 'y');


		//CREATING USER ID
		if (createUserId == 1) {
			VisitorInfo user[1000];

			// opening text file and checking if file can open or not
			registerFptr = fopen("visitor-info-database2.txt", "r");
			while (registerFptr == NULL) {
				printf("ERROR. File cannot be open due to not found.");
				exit(-1);
			}

			int i = 0;
			int totalNumberOfAccounts = 0, fourDigits = 0;
			char firstChar[10] = " ";
			firstChar[0] = 'V';


			// scanning existing accounts
			while (fscanf(registerFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &user[i].visitorUserId, &user[i].visitorIcNo, &user[i].visitorPassportNo, &user[i].visitorName, &user[i].visitorGender, &user[i].visitorBd.day, &user[i].visitorBd.month, &user[i].visitorBd.year, &user[i].visitorEmail, &user[i].visitorContactNo, &user[i].visitorAddress, &user[i].visitorAccStatus) != EOF)
			{
				i++;
			}
			totalNumberOfAccounts = i;
			fourDigits = i;

			fclose(registerFptr);

			//ASSIGNING USER ID
			//decide the role in User ID (V= regular, F= foreigner, A=admin)

			if (citizenshipStatus == 0) {
				firstChar[0] = 'F';
			}
			char  tempAccNo[10];

			//increase the previous AccNo by 1
			fourDigits++;

			//COMBINING both firstChar and AccountNo

			//converting accountNo to string
			sprintf(tempAccNo, "%03d", fourDigits);

			//concatenate firstChar and AccNo
			strcat(firstChar, tempAccNo);
			/*printf("\n%s\n", newAcc.visitorUserId);*/
			strcpy(newAcc.visitorUserId, firstChar);


			//FPRINF INTO 2 FILES (visitor-info-database.txt & password.txt)
			// fprintf into the file 

			FILE* pwFptr;

			registerFptr = fopen("visitor-info-database2.txt", "a");
			pwFptr = fopen("password.txt", "a");

			if (registerFptr == NULL) {
				printf("ERROR. File cannot be open due to not found.");
				exit(-1);
			}

			while (pwFptr == NULL) {
				printf("ERROR. File cannot be open due to not found.");
				exit(-1);
			}


			//fprint into text file (visitor-info-database.txt)
			fprintf(registerFptr, "\n%s|%s|%s|%s|%c|%02d/%02d/%04d|%s|%s|%s|1|", newAcc.visitorUserId, newAcc.visitorIcNo, newAcc.visitorPassportNo, newAcc.visitorName, newAcc.visitorGender, newAcc.visitorBd.day, newAcc.visitorBd.month, newAcc.visitorBd.year, newAcc.visitorEmail, newAcc.visitorContactNo, newAcc.visitorAddress);

			//fprint into text file (password.txt)
			fprintf(pwFptr, "\n%s", newPassword);


			fclose(registerFptr);
			fclose(pwFptr);

			printf("\nYour information successfully saved. directed to main menu\n");
			printf("\nYour PERSONAL USER ID is  : %s \n", newAcc.visitorUserId);
			system("pause");

			system("cls"); loginHeader(4);
			visitorMenu();

			return 0;
		}
		return 0;
	}
}

void displayRecordFunction() {


	h2HorizontalRule();
	printf("  DISPLAY VISITOR INFORMATION RECORDS MODULE\n");
	h2HorizontalRule();
	printf("\n\n");

	//variables
	VisitorInfo displayR[1000];

	int totalNumberOfAccount = 0;
	/*Validation displayRTempStruct;*/


	//OPEN TEXT FILE AND FOR REAING (strcmp current userID with existing userID)
	FILE* displayRecordFptr;
	displayRecordFptr = fopen("visitor-info-database2.txt", "r");

	while (displayRecordFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}

	int a = 0;
	int num = 0;
	/*int compareUserId = 0;*/

	while (fscanf(displayRecordFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &displayR[a].visitorUserId, &displayR[a].visitorIcNo, &displayR[a].visitorPassportNo, &displayR[a].visitorName, &displayR[a].visitorGender, &displayR[a].visitorBd.day, &displayR[a].visitorBd.month, &displayR[a].visitorBd.year, &displayR[a].visitorEmail, &displayR[a].visitorContactNo, &displayR[a].visitorAddress, &displayR[a].visitorAccStatus) != EOF)
	{
		a++;
	}

	fclose(displayRecordFptr);
	totalNumberOfAccount = a;
	printf("==================================================================================================================================================================\n");
	printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
	printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


	//lop to print all record
	for (int i = 0; i < a; i++) {

		printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", displayR[i].visitorUserId, displayR[i].visitorIcNo, displayR[i].visitorPassportNo, displayR[i].visitorName, displayR[i].visitorGender, displayR[i].visitorBd.year, displayR[i].visitorBd.month, displayR[i].visitorBd.day, displayR[i].visitorEmail, displayR[i].visitorContactNo, displayR[i].visitorAddress, displayR[i].visitorAccStatus);
		printf("|-------+------------+------+-----------------------+------------+----------------------------+------------+---------------------------------------------------+-|\n");


	}

	printf("\n\n\n");
	system("\n\npause");

	char endDisplayRecord;

	do {

		printf("Would you like to return to the Profile Menu? (Y/N)      >");
		rewind(stdin);
		scanf("%c", &endDisplayRecord);
		endDisplayRecord = toupper(endDisplayRecord);

		switch (endDisplayRecord) {
		case 'Y':
			printf("\nYou will now be directed to the Profile Menu.\n");
			system("pause");
			system("cls"); loginHeader(4);
			return 0;
			break;
		case 'N':
			printf("\n");
			system("pause");
			endDisplayRecord = 'O';
			break;
		default:
			printf("ERROR. Please choose the available options.\n\n\n");
			break;
		}

	} while (endDisplayRecord != 'Y' && endDisplayRecord != 'N');
}

void searchFunction() {
	int loop = 0;
	do {
		h2HorizontalRule();
		printf("           SEARCH VISITOR INFORMATION RECORD MODULE\n");
		h2HorizontalRule();

		printf("Search Menu.\n");
		h3HorizontalRule();
		printf("\n");

		// search function options
		printf("\t1.Visitor User ID.\n");
		printf("\t2.Visitor Ic Number.\n");
		printf("\t3.Visitor Passport Number.\n");
		printf("\t4.Visitor Name.\n");
		printf("\t5.Visitor Gender.\n");
		printf("\t6.Visitor Birth Date. [month]\n");// by month
		printf("\t7.Visitor Birth Date. [year]\n");// by year
		printf("\t8.Visitor Email Address.\n");
		printf("\t9.Visitor Contact Number.\n");
		printf("\t10.Visitor Home Address.\n");
		printf("\t11.Account Status.\n");
		printf("\t12.Exit.\n\n");// exit module

		//////variable
		VisitorInfo search[1000], searchCmp;
		Validation searchTempStruct;
		int searchChoice = 0;

		int searchUserId = 0, searchIcNo = 0, searchPassportNo = 0, searchName = 0, searchGender = 0, searchBdDay = 0, searchBdMonth = 0, searchBdYear = 0, searchEmail = 0, searchContactNo = 0, searchAddress = 0, searchPassword = 0, searchAccountStatus = 0;;
		int i, totalNumberOfAccount = 0;

		char statusLabel[9] = " ";
		char tempMonth[3] = " ", tempYear[5] = " ";

		//promp user to input the required category
		do {
			printf("\nWhich category would you like to serch for?                    >");
			rewind(stdin);
			scanf("%d", &searchChoice);

			switch (searchChoice) {
			case 1:// case 1: search with visitor user ID

				do {
					printf("\n");
					printf("Please enter your Visitor User ID                              >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorUserId);
					strupr(searchCmp.visitorUserId);

					searchTempStruct = universalCharacterCheck(searchCmp.visitorUserId);

					if (searchTempStruct.noCharacter != 4) {
						//if the number of character of the UserID is not accurately 6
						printf("ERROR. You have entered %d character(s). Please try again\n\n", searchTempStruct.noCharacter);
						searchIcNo = 0;
					}
					else if (searchTempStruct.noSpecialCharacter > 0) {
						//if there is more than one special character including space
						printf("ERROR. You have entered %d special character(s). Please try again\n\n", searchTempStruct.noSpecialCharacter);
						searchIcNo = 0;
					}
					else if (searchTempStruct.noAlphabet > 1) {
						//if there is more than one alphabat character 
						printf("ERROR. You have entered %d alphabet(s). Please try again\n\n", searchTempStruct.noAlphabet);
						searchIcNo = 0;
					}
					else if (searchTempStruct.noDigit != 3)
					{
						printf("ERROR. You have entered %d digits(s). Please try again\n\n\n", searchTempStruct.noDigit);
						searchPassportNo = 0;
					}
					else {
						//if all character validation is correct 
						searchIcNo = 1;
					}

				} while (searchIcNo != 1);



				// scanning existing accounts
				i = 0;
				FILE* searchFptr;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor User ID >>> %s\n", searchCmp.visitorUserId);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorUserId, search[a].visitorUserId) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");



					}
				}
				break;

			case 2:// case 2: search with visitor ic number

				do {
					printf("\nPlease enter the Visitor User I.C. Number                      >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorIcNo);

					searchTempStruct = universalCharacterCheck(searchCmp.visitorIcNo);

					if (searchTempStruct.noCharacter != 12) {
						//if the number of character of the IC is not accurately 12
						printf("ERROR. You have entered %d character(s). Please try again\n\n", searchTempStruct.noCharacter);
						searchIcNo = 0;
					}
					else if (searchTempStruct.noSpecialCharacter > 0) {
						//if there is more than one special character including space
						printf("ERROR. You have entered %d special character(s). Please try again\n\n", searchTempStruct.noSpecialCharacter);
						searchIcNo = 0;
					}
					else if (searchTempStruct.noAlphabet > 0) {
						//if there is more than one alphabat character 
						printf("ERROR. You have entered %d alphabet(s). Please try again\n\n", searchTempStruct.noAlphabet);
						searchIcNo = 0;
					}
					else {
						//if all character validation is correct 
						searchIcNo = 1;
					}
				} while (searchIcNo != 1);

				// scanning existing accounts
				i = 0;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}
				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor User IC No. >>> %s\n", searchCmp.visitorIcNo);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");

				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorIcNo, search[a].visitorIcNo) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");



					}
				}
				break;

			case 3:// search visitor passport number  
				do {
					printf("\nPlease enter the Visitor Passport Number                       >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorPassportNo);
					strupr(searchCmp.visitorPassportNo);

					// Enter 
					searchTempStruct = universalCharacterCheck(searchCmp.visitorPassportNo);

					if (searchTempStruct.noCharacter != 6) {
						/*system("cls");*/
						printf("ERROR. You have entered %d character(s). Please try again\n\n\n", searchTempStruct.noCharacter);
						searchPassportNo = 0;
					}
					else if (searchTempStruct.noSpecialCharacter > 0) {
						/*system("cls");*/
						printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", searchTempStruct.noSpecialCharacter);
						searchPassportNo = 0;
					}
					else if (searchTempStruct.noAlphabet != 1) {
						/*system("cls");*/
						printf("ERROR. You have entered %d alphabet(s). Please try again\n\n\n", searchTempStruct.noAlphabet);
						searchPassportNo = 0;
					}
					else if (searchTempStruct.noDigit != 5)
					{
						printf("ERROR. You have entered %d digits(s). Please try again\n\n\n", searchTempStruct.noDigit);
						searchPassportNo = 0;
					}
					else {
						searchPassportNo = 1;
					}

				} while (searchPassportNo == 0);

				i = 0;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}
				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}
				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Passport No. >>> %s\n", searchCmp.visitorPassportNo);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorPassportNo, search[a].visitorPassportNo) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;

			case 4:// search visitor name 
				do {
					printf("\n");
					printf("Please enter the Visitor Full Name                             >");
					rewind(stdin);
					scanf("%[^\n]", searchCmp.visitorName);
					strupr(searchCmp.visitorName);

					searchTempStruct = universalCharacterCheck(searchCmp.visitorName);

					if (searchTempStruct.noCharacter < 0 || searchTempStruct.noCharacter > 150) {
						/*system("cls");*/
						printf("ERROR. You have entered %d character(s). Please try again\n\n\n", searchTempStruct.noCharacter);
						searchName = 0;
					}

					else if (searchTempStruct.noSpecialCharacterWithoutSpace > 0) {

						printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", searchTempStruct.noSpecialCharacterWithoutSpace);
						searchName = 0;
					}
					else if (searchTempStruct.noDigit > 0)
					{
						printf("ERROR. You have entered %d digits(s). Please try again\n\n\n", searchTempStruct.noDigit);
						searchName = 0;
					}
					else {
						searchName = 1;
					}
				} while (searchName != 1);

				i = 0;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}
				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Passport No. >>> %s\n", searchCmp.visitorName);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");

				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorName, search[a].visitorName) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;


			case 5:// search visitor gender

				do {
					printf("\n");
					rewind(stdin);
					printf("Please enter the Visitor Gender (M = MALE / F = FEMALE)        >");
					scanf("%c", &searchCmp.visitorGender);
					searchCmp.visitorGender = toupper(searchCmp.visitorGender);


					switch (searchCmp.visitorGender) {
					case 'M':
						searchGender = 1; break;
					case 'F':
						searchGender = 1; break;
					default:
						printf("ERROR. Please choose the available options.");
						searchGender = 0; break;
					}
				} while (searchGender != 1);

				i = 0;
				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Gender       >>> %c\n", searchCmp.visitorGender);
				/*printf("\n\nSearch By : Visitor Passport No. >>> %s\n", searchCmp.visitorName);*/
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (searchCmp.visitorGender == search[a].visitorGender) {
						/*(strcmp(searchCmp.visitorGender, search[a].visitorGender) == 0)*/

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;



			case 6:// search visitor bd month
				do {
					printf("\n\n");
					printf("Please enter the Visitor Date of Birth [month : 01-12]         >");
					rewind(stdin);
					scanf("%s", &tempMonth);

					int monthLength = 0;
					monthLength = strlen(tempMonth);

					for (int i = 0; i < monthLength; i++)
					{
						if (isdigit(tempMonth[i]) != 0) {
							//if user input digits
							searchBdMonth = 1;
						}

						else {
							// if user input other than digits
							searchBdMonth = 0;
							break;
						}
					}
					searchCmp.visitorBd.month = atoi(tempMonth);

					if (searchBdMonth == 1 && searchCmp.visitorBd.month < 13 && searchCmp.visitorBd.month >0) {
						searchBdMonth = 1;
					}
					else {
						printf("\nERROR. Your input in invalid. Please try again.");
						searchBdMonth = 0;
					}
				} while (searchBdMonth != 1);


				//OPEN AND CHECK FOR THE TEXT FILE
				i = 0;
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				/*printf("\n\nSearch By : Visitor Gender       >>> %c\n", searchCmp.visitorGender);*/
				printf("\n\nSearch By : Visitor BirthDate [month] >>> %d\n", searchCmp.visitorBd.month);
				/*printf("\n\nSearch By : Visitor Passport No. >>> %s\n", searchCmp.visitorName);*/
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (searchCmp.visitorBd.month == search[a].visitorBd.month) {
						/*(strcmp(searchCmp.visitorGender, search[a].visitorGender) == 0)*/

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}


				break;
			case 7:// search visitor bd year

				do {// validate date of birth (year)
					printf("\n\n");
					printf("Please enter the Visitor Date of Birth [year]                  >");
					rewind(stdin);
					scanf("%s", &tempYear);

					int yearLength = 0;
					yearLength = strlen(tempYear);

					for (int i = 0; i < yearLength; i++)
					{
						if (isdigit(tempYear[i]) != 0) {
							//if user input digits
							searchBdYear = 1;
						}

						else {
							// if user input other than digits
							searchBdYear = 0;
							break;
						}
					}

					searchCmp.visitorBd.year = atoi(tempYear);

					if (searchBdYear == 1 && searchCmp.visitorBd.year > 1900 && searchCmp.visitorBd.year < 2021) {
						searchBdYear = 1;
					}
					else {
						printf("\nERROR. Your input in invalid. Please try again.");
						searchBdYear = 0;
					}

				} while (searchBdYear != 1);


				//OPEN AND CHECK FOR THE TEXT FILE
				i = 0;
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor BirthDate [year] >>> %d\n", searchCmp.visitorBd.year);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (searchCmp.visitorBd.year == search[a].visitorBd.year) {
						/*(strcmp(searchCmp.visitorGender, search[a].visitorGender) == 0)*/

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;

			case 8:// search email

				//REGISTER: Input new visitor email // different type of validation !!!
				do {
					printf("\n\n");
					printf("Please enter the Visitor Email Address  (e.g. john@gmail.com)  >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorEmail);

					searchEmail = is_valid(searchCmp.visitorEmail);

					if (searchEmail != 1) {
						// email is fail
						printf("\nERROR. Please try again.\n");
					}
				} while (searchEmail != 1);

				//OPEN AND CHECK FOR THE TEXT FILE
				i = 0;
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Email Address    >>> %s\n", searchCmp.visitorEmail);
				/*printf("\n\nSearch By : Visitor BirthDate [year] >>> %d\n", searchCmp.visitorBd.year);*/
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorEmail, search[a].visitorEmail) == 0) {
						/*(strcmp(searchCmp.visitorGender, search[a].visitorGender) == 0)*/

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;
			case 9:// search contact no  
				do {
					printf("\n");
					printf("Please enter the Visitor Contact Number                        >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorContactNo);

					searchTempStruct = universalCharacterCheck(searchCmp.visitorContactNo);

					if (searchTempStruct.noCharacter < 0 || searchTempStruct.noCharacter > 13) {
						printf("ERROR. You have entered %d character(s). Please try again\n\n\n", searchTempStruct.noCharacter);
						searchContactNo = 0;
					}

					else if (searchTempStruct.noSpecialCharacterWithoutSpace > 0) {
						printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", searchTempStruct.noSpecialCharacterWithoutSpace);
						searchContactNo = 0;
					}
					else if (searchTempStruct.noSpace != 1) {

						printf("ERROR. You have entered %d space(s). Please try again\n\n\n", searchTempStruct.noSpace);
						searchContactNo = 0;
					}
					else {

						searchContactNo = 1;
					}

				} while (searchContactNo != 1);

				// scanning existing accounts
				i = 0;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor User IC No. >>> %s\n", searchCmp.visitorContactNo);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorContactNo, search[a].visitorContactNo) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;

			case 10:// search address m  
				do {
					printf("\n");
					printf("Please enter the Visitor Home Address                          >");
					rewind(stdin);
					scanf("%[^\n]", &searchCmp.visitorAddress);
					strupr(searchCmp.visitorAddress);


					if (searchCmp.visitorAddress == " ") {
						searchAddress = 0;
					}
					else {
						searchAddress = 1;
					}

				} while (searchAddress != 1);

				// scanning existing accounts
				i = 0;

				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}
				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}
				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Home Address >>> %s\n", searchCmp.visitorAddress);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");

				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (strcmp(searchCmp.visitorAddress, search[a].visitorAddress) == 0) {

						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						/*printf("|                                                                                                                                                                |\n");*/
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;
			case 11:// search account status
				do {
					printf("\n\n");
					rewind(stdin);
					printf("Please enter Visitor Account Status (1 = ACTIVE|0 = DELETED)   >");
					scanf("%d", &searchCmp.visitorAccStatus);

					switch (searchCmp.visitorAccStatus) {
					case 0:
						strcpy(statusLabel, "DELETED");
						searchAccountStatus = 1;
						break;
					case 1:
						strcpy(statusLabel, "ACTIVE");
						searchAccountStatus = 1;
						break;
					default:
						printf("ERROR. Please choose the available options.");
						searchAccountStatus = 0; break;
					}

				} while (searchAccountStatus != 1);

				i = 0;
				//open and check for the text file
				searchFptr = fopen("visitor-info-database2.txt", "r");
				while (searchFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				while (fscanf(searchFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &search[i].visitorUserId, &search[i].visitorIcNo, &search[i].visitorPassportNo, &search[i].visitorName, &search[i].visitorGender, &search[i].visitorBd.day, &search[i].visitorBd.month, &search[i].visitorBd.year, &search[i].visitorEmail, &search[i].visitorContactNo, &search[i].visitorAddress, &search[i].visitorAccStatus) != EOF)
				{
					i++;
				}

				fclose(searchFptr);
				totalNumberOfAccount = i;

				//header
				printf("\n\nSearch By : Visitor Account Status >>> %s\n", statusLabel);
				printf("==================================================================================================================================================================\n");
				printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
				printf("|=======+============+======+=======================+===+========+============================+============+===================================================+=|\n");


				for (int a = 0; a < totalNumberOfAccount; a++) {
					if (searchCmp.visitorAccStatus == search[a].visitorAccStatus) {


						printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", search[a].visitorUserId, search[a].visitorIcNo, search[a].visitorPassportNo, search[a].visitorName, search[a].visitorGender, search[a].visitorBd.year, search[a].visitorBd.month, search[a].visitorBd.day, search[a].visitorEmail, search[a].visitorContactNo, search[a].visitorAddress, search[a].visitorAccStatus);
						printf("|-------+------------+------+-----------------------+---+----------+--------------------+------------+---------------------------------------------------------+-|\n");
					}
				}
				break;

			case 12:// to exit search module
				printf("\nYou will now be directed back to the Profile Menu\n");
				system("pause");
				system("cls");
				return 0;
				break;

			default:


				break;
			}

		} while (searchChoice < 1 && searchChoice > 12);


		//End of search function options ( continue of exit)
		char endDisplayRecord;
		do {

			printf("\n\nWould you like to continue or return to the Profile Menu? [ C - continue , E - Exit ]     >");
			rewind(stdin);
			scanf("%c", &endDisplayRecord);
			endDisplayRecord = toupper(endDisplayRecord);

			switch (endDisplayRecord) {
			case 'E':
				printf("\nYou will now be directed to the Profile Menu.\n");
				system("pause");
				system("cls");
				return 0;
				break;
			case 'C':
				printf("\n");
				/*system("pause");*/
				system("cls");
				/*endDisplayRecord = 'O';*/
				break;
			default:
				printf("ERROR. Please choose the available options.\n\n\n");
				break;
			}

		} while (endDisplayRecord != 'C' && endDisplayRecord != 'E');
	} while (loop != 1);
}


void deleteFunction() {

	//variables
	VisitorInfo delete[1000];
	Validation deleteTempStruct;

	char deleteChoice = ' ';
	int validDeleteChoice;

	h2HorizontalRule();
	printf("                   DELETE FUNCTION\n");
	h2HorizontalRule();
	printf("\n\n");

	char deleteUserId[10];
	int validationUserId = 0;

	int totalNumberOfAccount = 0;
	int existenceCheckIcNoResult = 0;
	int existence = 0;
	int order = 0;
	do {

		//fopen text file and necessary commands
		do {
			// Validation to exclude (> or < 12 char/alphabnets/special characters)
			printf("\n\nPlease enter your Visitor ID No. to be deleted [4 Characters]         >");
			rewind(stdin);
			scanf("%[^\n]", &deleteUserId);
			strupr(deleteUserId);
			printf("\n\n");

			/*universalCharacterCheck(newAcc.visitorIcNo,registerTempStruct);*/
			deleteTempStruct = universalCharacterCheck(deleteUserId);


			if (deleteTempStruct.noCharacter < 4 || deleteTempStruct.noCharacter> 4) {
				printf("ERROR. You have entered %d character(s). Please try again\n\n", deleteTempStruct.noCharacter);
				validationUserId = 0;
			}

			else if (deleteTempStruct.noSpecialCharacter > 0) {
				printf("ERROR. You have entered %d special character(s). Please try again\n\n", deleteTempStruct.noSpecialCharacter);
				validationUserId = 0;
			}
			else if (deleteTempStruct.noAlphabet > 1 || deleteTempStruct.noAlphabet < 1) {
				printf("ERROR. You have entered %d alphabet(s). Please try again\n\n", deleteTempStruct.noAlphabet);
				validationUserId = 0;
			}
			else if (deleteTempStruct.noDigit > 3 && deleteTempStruct.noDigit < 3)
			{
				printf("ERROR. You have entered %d digits(s). Please try again.\n\n", deleteTempStruct.noDigit);
				validationUserId = 0;
			}
			else {
				validationUserId = 1;
			}

		} while (validationUserId != 1);

		//2. Check the existence of the visitor account/ if not, proceed to registry modul

		//OPEN TEXT FILE AND FOR REAING (strcmp current userID with existing userID)
		FILE* deleteFptr;
		deleteFptr = fopen("visitor-info-database2.txt", "r");

		while (deleteFptr == NULL) {
			printf("ERROR. File cannot be open due to not found.");
			exit(-1);
		}

		int i = 0;
		int num = 0;
		int compareUserId = 0;


		while (fscanf(deleteFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &delete[i].visitorUserId, &delete[i].visitorIcNo, &delete[i].visitorPassportNo, &delete[i].visitorName, &delete[i].visitorGender, &delete[i].visitorBd.day, &delete[i].visitorBd.month, &delete[i].visitorBd.year, &delete[i].visitorEmail, &delete[i].visitorContactNo, &delete[i].visitorAddress, &delete[i].visitorAccStatus) != EOF)
		{
			i++;
		}

		fclose(deleteFptr);
		totalNumberOfAccount = i;

		for (int num = 0; num < totalNumberOfAccount; num++) {
			if (strcmp(deleteUserId, delete[num].visitorUserId) == 0 && delete[num].visitorAccStatus == 1) {
				existenceCheckIcNoResult = 1;
				existence = 1;
				order = num;
				break;
			}
			else if (strcmp(deleteUserId, delete[num].visitorUserId) == 0 && delete[num].visitorAccStatus == 0) {
				printf("\nThe account was terminated. Pleas enteer another Visitor ID.\n");
				existence = 0;
				existenceCheckIcNoResult = 0;
				/*break;*/
			}
			else {
				existenceCheckIcNoResult = 0;
			}
		}
	} while (existenceCheckIcNoResult != 1);


	//DELETE PROCESSING 
	if (existence = 1) {
		//displaying the full word for gender
		char displayGender[10];

		switch (delete[order].visitorGender) {
		case 'F':
			strcpy(displayGender, "FEMALE");
			break;
		case 'M':
			strcpy(displayGender, "MALE");
			break;
		default:
			//printf("ERROR.\n");
			strcpy(displayGender, "OTHERS");
			break;
		}


		printf("The Profile Details of User %s\n", delete[order].visitorUserId);
		h3HorizontalRule();
		printf("User ID                        :%s\n", delete[order].visitorUserId);
		printf("Identity Card No.              :%s\n", delete[order].visitorIcNo);
		printf("Passport No.                   :%s\n", delete[order].visitorPassportNo);
		printf("User Full Name                 :%s\n", delete[order].visitorName);
		printf("Gender                         :%s\n", displayGender);  // need to display full word
		printf("Date of Birth                  :%04d/%02d/%02d\n", delete[order].visitorBd.year, delete[order].visitorBd.month, delete[order].visitorBd.day);// date displayed in japan date format
		printf("Email Address                  :%s\n", delete[order].visitorEmail);
		printf("Contact Number                 :%s\n", delete[order].visitorContactNo);
		printf("Home Address                   :%s\n\n\n", delete[order].visitorAddress);

		// menu display of funciton options
		printf("\n\nDelete Function Options\n");
		printf("-----------------------\n\n");
		printf("\tY = Yes.\n");
		printf("\tN = No.\n\n");


		//confirmation to delete the existing user account
		do {

			printf("Confirmation to delete your existing account.       >");
			rewind(stdin);
			scanf("%c", &deleteChoice);
			/*deleteChoice = toupper(deleteChoice);*/


			switch (deleteChoice) {
			case 'Y':
			case 'y':

				delete[order].visitorAccStatus = 0;
				//appending into the file
				FILE* deleteFptr;
				deleteFptr = fopen("visitor-info-database2.txt", "w");

				if (deleteFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}
				for (int a = 0; a < totalNumberOfAccount; a++) {

					fprintf(deleteFptr, "%s|%s|%s|%s|%c|%02d/%02d/%04d|%s|%s|%s|%d|", delete[a].visitorUserId, delete[a].visitorIcNo, delete[a].visitorPassportNo, delete[a].visitorName, delete[a].visitorGender, delete[a].visitorBd.day, delete[a].visitorBd.month, delete[a].visitorBd.year, delete[a].visitorEmail, delete[a].visitorContactNo, delete[a].visitorAddress, delete[a].visitorAccStatus);

					if (a != (totalNumberOfAccount - 1)) {
						fprintf(deleteFptr, "\n");
					}
				}

				fclose(deleteFptr);

				//closure
				printf("The termination the account of Visitor ID: %s has been processed. You will now be directed to the Main Menu.\n", delete[order].visitorUserId);
				system("pause");
				system("cls"); loginHeader(4);
				return 0;
				break;

			case 'N':
			case 'n':
				printf("The termination of your account has been cancelled. You will now be directed to the Profile Menu.\n");
				system("pause");
				system("cls"); loginHeader(4);
				return 0;

				validDeleteChoice = 1;

				break;
			default:
				printf("ERROR. Please enter the available options.");
				validDeleteChoice = 0;
				system("pause\n");
				system("cls"); loginHeader(4);
				/*deleteFunction();*/

			}


		} while (validDeleteChoice != 1);
	}
}


void modifyFunction() {
	//variables
	VisitorInfo modify[1000];
	Validation modifyTempStruct = { 0,0,0,0,0 };

	//validaiton for each datafield
	int modifyUserId = 0, modifyIcNo = 0, modifyPassportNo = 0, modifyName = 0, modifyGender = 0, modifyBdDay = 0, modifyBdMonth = 0, modifyBdYear = 0/*modifyRace = 0*/, modifyEmail = 0, modifyContactNo = 0, modifyAddress = 0;

	char modifyEnd;
	int continueModify = 0;

	do {
		//header
		h2HorizontalRule();
		printf("                  MODIFY FUNCTION\n");
		h2HorizontalRule();
		printf("\n\n");

		//fopen text file and necessary commands
		FILE* modifyFptr;
		modifyFptr = fopen("visitor-info-database2.txt", "r");

		if (modifyFptr == NULL) {
			printf("ERROR. File cannot be open due to not found.");
			exit(-1);
		}

		//read the whole text file into an array 
		int i = 0;
		int selected = 0;
		int order = 0;
		int totalAccounts = 0;

		while (fscanf(modifyFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%[^\|]|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &modify[i].visitorUserId, &modify[i].visitorIcNo, &modify[i].visitorPassportNo, &modify[i].visitorName, &modify[i].visitorGender, &modify[i].visitorBd.day, &modify[i].visitorBd.month, &modify[i].visitorBd.year, &modify[i].visitorEmail, &modify[i].visitorContactNo, &modify[i].visitorAddress, &modify[i].visitorAccStatus) != EOF)
		{
			i++;
		}

		fclose(modifyFptr);

		////////DISPLAYING PROFILE DETAIL AS REFERENCE IN MODIFY FUNCTION
		//displaying the full word for gender
		char displayGender[10];


		switch (modify[order].visitorGender) {
		case 'F':
			strcpy(displayGender, "FEMALE");
			break;
		case 'M':
			strcpy(displayGender, "MALE");
			break;
		default:
			strcpy(displayGender, "OTHERS");
			break;
		}


		printf("User ID                        :%s\n", modify[order].visitorUserId);
		printf("Identity Card No.              :%s\n", modify[order].visitorIcNo);
		printf("Passport No.                   :%s\n", modify[order].visitorPassportNo);
		printf("User Full Name                 :%s\n", modify[order].visitorName);
		printf("Gender                         :%s\n", displayGender);  // need to display full word
		printf("Date of Birth                  :%04d/%02d/%02d\n", modify[order].visitorBd.year, modify[order].visitorBd.month, modify[order].visitorBd.day);// date displayed in japan date format
		printf("Email Address                  :%s\n", modify[order].visitorEmail);
		printf("Contact Number                 :%s\n", modify[order].visitorContactNo);
		printf("Home Address                   :%s\n\n\n", modify[order].visitorAddress);

		printf("Modify Menu.\n");
		h3HorizontalRule();
		printf("\n");

		printf("\t1.Email Address.\n");
		printf("\t2.Contact Number.\n");
		printf("\t3.Home Address.\n");
		printf("\t4.Exit.\n\n");

		int modifyChoice = 0;
		do {
			printf("\n\nWhich information would you like to modify?    >");
			rewind(stdin);
			scanf("%d", &modifyChoice);

			switch (modifyChoice) {

			case 1:// CASE 1: MODIFY EMAIL ADDRESS   ***stopped at email to edit fscanf

				do {
					printf("\n\n");
					printf("Please enter your new Email Address (e.g. jsmith@example.com)                >");
					rewind(stdin);
					scanf("%[^\n]", &modify[order].visitorEmail);

					//validatate email address 
					modifyEmail = is_valid(modify[order].visitorEmail);

					if (modifyEmail != 1) {
						// email is fail
						printf("\nERROR. Please try again.\n");
					}
				} while (modifyEmail != 1);

				//fprint into text file
				modifyFptr = fopen("visitor-info-database2.txt", "w");

				if (modifyFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}

				for (int a = 0; a < i; a++) {

					fprintf(modifyFptr, "%s|%s|%s|%s|%c|%02d/%02d/%02d|%s|%s|%s|%d|", modify[a].visitorUserId, modify[a].visitorIcNo, modify[a].visitorPassportNo, modify[a].visitorName, modify[a].visitorGender, modify[a].visitorBd.day, modify[a].visitorBd.month, modify[a].visitorBd.year, modify[a].visitorEmail, modify[a].visitorContactNo, modify[a].visitorAddress, modify[a].visitorAccStatus);

					if (a != (i - 1)) {
						fprintf(modifyFptr, "\n");
					}
				}

				fclose(modifyFptr);
				break;

			case 2:// CASE 2: MODIFY contact no

				do {

					printf("\n\n");
					printf("Please enter your new CoContact Number (e.g. 012 3456789)                >");
					rewind(stdin);
					scanf("%[^\n]", &modify[order].visitorContactNo);


					modifyTempStruct = universalCharacterCheck(modify[order].visitorContactNo);

					if (modifyTempStruct.noCharacter < 0 || modifyTempStruct.noCharacter > 13) {
						printf("ERROR. You have entered %d character(s). Please try again\n\n\n", modifyTempStruct.noCharacter);
						modifyContactNo = 0;
					}
					else if (modifyTempStruct.noSpecialCharacterWithoutSpace > 0) {
						printf("ERROR. You have entered %d special character(s). Please try again\n\n\n", modifyTempStruct.noSpecialCharacterWithoutSpace);
						modifyContactNo = 0;
					}
					else if (modifyTempStruct.noAlphabet > 1) {
						printf("ERROR. You have entered %d alphabet(s). Please try again\n\n", modifyTempStruct.noAlphabet);
						modifyContactNo = 0;
					}
					else if (modifyTempStruct.noSpace != 1) {

						printf("ERROR. You have entered %d space(s). Please try again\n\n\n", modifyTempStruct.noSpace);
						modifyContactNo = 0;
					}
					else {
						modifyContactNo = 1;
					}

				} while (modifyContactNo != 1);

				//fprint into text file
				modifyFptr = fopen("visitor-info-database2.txt", "w");

				if (modifyFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}


				for (int a = 0; a < i; a++) {

					fprintf(modifyFptr, "%s|%s|%s|%s|%02d/%02d/%04d|%c|%s|%s|%s|%d|", modify[a].visitorUserId, modify[a].visitorIcNo, modify[a].visitorPassportNo, modify[a].visitorName, modify[a].visitorGender, modify[a].visitorBd.day, modify[a].visitorBd.month, modify[a].visitorBd.year, modify[a].visitorEmail, modify[a].visitorContactNo, modify[a].visitorAddress, modify[a].visitorAccStatus);

					if (a != (i - 1)) {
						fprintf(modifyFptr, "\n");
					}
				}

				fclose(modifyFptr);
				break;

			case 3:// CASE 8: MODIFY ADDRESS	

				do {
					printf("\n\n");
					printf("Please enter your new Home Address (FULL CAPS according to the Identity Card)                >");
					rewind(stdin);
					scanf("%[^\n]", modify[order].visitorAddress);
					strupr(modify[order].visitorAddress);

					if (modifyAddress == " ") {
						modifyAddress = 0;
					}
					else {
						modifyAddress = 1;
					}

				} while (modifyAddress != 1);


				//fprint into text file
				modifyFptr = fopen("visitor-info-database2.txt", "w");

				if (modifyFptr == NULL) {
					printf("ERROR. File cannot be open due to not found.");
					exit(-1);
				}


				for (int a = 0; a < i; a++) {

					fprintf(modifyFptr, "%s|%s|%s|%s|%c|%02d/%02d/%02d|%s|%s|%s|%d|", modify[a].visitorUserId, modify[a].visitorIcNo, modify[a].visitorPassportNo, modify[a].visitorName, modify[a].visitorGender, modify[a].visitorBd.day, modify[a].visitorBd.month, modify[a].visitorBd.year, modify[a].visitorEmail, modify[a].visitorContactNo, modify[a].visitorAddress, modify[a].visitorAccStatus);

					if (a != (i - 1)) {
						fprintf(modifyFptr, "\n");
					}
				}
				fclose(modifyFptr);
				break;

			case 4:
				printf("\nYou will now be directed back to the profile menu.\n");
				system("pause");
				system("cls"); loginHeader(4);
				return 0;

			default:
				printf("ERROR. Please choose the available options.\n");
				modifyChoice = 0;
				break;
			}




		} while (modifyChoice < 1 && modifyChoice >3);



		do {

			printf("What would you like to do now? [C - Continue Modify / E - Exit]             >");
			rewind(stdin);
			scanf("%c", &modifyEnd);
			modifyEnd = toupper(modifyEnd);

			switch (modifyEnd) {
			case 'C':
				printf("\n");
				continueModify = 1;
				system("pause");
				system("cls"); loginHeader(4);
				/*modifyFunction();*/

				break;

			case 'E':

				//show the details for final time (?)

				printf("\nYou will now be directed to the Profile Menu.\n");
				system("pause");
				system("cls"); loginHeader(4);
				return 0;
				/*continueModify = 0;*/

				break;

			default:
				printf("ERROR. Please choose the available options.\n\n");
				break;
			}


		} while (modifyEnd != 'C' && modifyEnd != 'E');



	} while (continueModify == 1);
}



void displayFunction(char currentUserId[]) {

	VisitorInfo display[1000];

	char endDelete = ' ';

	h2HorizontalRule();
	printf("                   ABOUT ME\n");
	h2HorizontalRule();

	printf("\n\nProfile details.\n");
	printf("----------------\n\n");

	//open and read text file into a structure array
	FILE* displayFptr;
	displayFptr = fopen("visitor-info-database2.txt", "r");

	if (displayFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}

	//read the whole text file into an array 
	int i = 0;
	/*int selected = 0;*/
	int order = 0;

	while (fscanf(displayFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &display[i].visitorUserId, &display[i].visitorIcNo, &display[i].visitorPassportNo, &display[i].visitorName, &display[i].visitorGender, &display[i].visitorBd.day, &display[i].visitorBd.month, &display[i].visitorBd.year, &display[i].visitorEmail, &display[i].visitorContactNo, &display[i].visitorAddress, &display[i].visitorAccStatus) != EOF)
	{
		if (strcmp(currentUserId, display[i].visitorUserId) == 0) {
			order = i;
		}
		i++;
	}

	fclose(displayFptr);


	//displaying the full word for gender
	char displayGender[10];

	switch (display[order].visitorGender) {
	case 'F':
		strcpy(displayGender, "FEMALE");
		break;
	case 'M':
		strcpy(displayGender, "MALE");
		break;
	default:
		//printf("ERROR.\n");
		strcpy(displayGender, "OTHERS");
		break;
	}




	printf("User ID                        :%s\n", display[order].visitorUserId);
	printf("Identity Card No.              :%s\n", display[order].visitorIcNo);
	printf("Passport No.                   :%s\n", display[order].visitorPassportNo);
	printf("User Full Name                 :%s\n", display[order].visitorName);
	printf("Gender                         :%s\n", displayGender);  // need to display full word
	printf("Date of Birth                  :%04d/%02d/%02d\n", display[order].visitorBd.year, display[order].visitorBd.month, display[order].visitorBd.day);// date displayed in japan date format
	printf("Email Address                  :%s\n", display[order].visitorEmail);
	printf("Contact Number                 :%s\n", display[order].visitorContactNo);
	printf("Home Address                   :%s\n\n\n", display[order].visitorAddress);


	do {

		printf("Would you like to return to the Profile Menu? (Y/N)      >");
		rewind(stdin);
		scanf("%c", &endDelete);
		endDelete = toupper(endDelete);

		switch (endDelete) {
		case 'Y':
			printf("\nYou will now be directed to the Profile Menu.\n");
			system("pause");
			system("cls"); loginHeader(4);
			profileMenu(currentUserId);
			break;
		case 'N':
			printf("\n");
			system("pause");
			endDelete = 'O';
			break;
		default:
			printf("ERROR. Please choose the available options.\n\n\n");
			break;
		}

	} while (endDelete != 'Y' && endDelete != 'N');




}

void displayAdminRecordFunction() {

	h2HorizontalRule();
	printf("  DISPLAY ADMIN INFORMATION RECORDS \n");
	h2HorizontalRule();
	printf("\n\n");

	//variables
	VisitorInfo displayR[1000];

	int totalNumberOfAccount = 0;
	//OPEN TEXT FILE AND FOR REAING (strcmp current userID with existing userID)
	FILE* displayRecordFptr;
	displayRecordFptr = fopen("visitor-info-database2.txt", "r");

	while (displayRecordFptr == NULL) {
		printf("ERROR. File cannot be open due to not found.");
		exit(-1);
	}

	int a = 0;
	int num = 0;

	while (fscanf(displayRecordFptr, "%[^\|]|%[^\|]|%[^\|]|%[^\|]|%c|%d/%d/%d|%[^\|]|%[^\|]|%[^\|]|%d|\n", &displayR[a].visitorUserId, &displayR[a].visitorIcNo, &displayR[a].visitorPassportNo, &displayR[a].visitorName, &displayR[a].visitorGender, &displayR[a].visitorBd.day, &displayR[a].visitorBd.month, &displayR[a].visitorBd.year, &displayR[a].visitorEmail, &displayR[a].visitorContactNo, &displayR[a].visitorAddress, &displayR[a].visitorAccStatus) != EOF)
	{
		a++;
	}

	fclose(displayRecordFptr);
	totalNumberOfAccount = a;
	printf("==================================================================================================================================================================\n");
	printf("|User ID|   User IC  | Pp.No|       Full Name       |Sex|  B.Date  |        Email       | Contact No |                         Home Address                    |S|\n");
	printf("|=======+============+======+=======================+===+========+============================+======+========================================================+=|\n");

	//lop to print all record
	for (int i = 0; i < a; i++) {
		if (displayR[i].visitorUserId[0] == 'A') {
			printf("|%7s|%12s|%6s|%23s| %c |%04d/%02d/%02d|%20s|%12s|%57s|%d|\n", displayR[i].visitorUserId, displayR[i].visitorIcNo, displayR[i].visitorPassportNo, displayR[i].visitorName, displayR[i].visitorGender, displayR[i].visitorBd.year, displayR[i].visitorBd.month, displayR[i].visitorBd.day, displayR[i].visitorEmail, displayR[i].visitorContactNo, displayR[i].visitorAddress, displayR[i].visitorAccStatus);
			//printf("|=======+============+======+=======================+===+========+============================+======+========================================================+=|\n");
		}
	}

	printf("\n\n\n");
	system("\n\npause");
	char endDisplayRecord;

	do {
		printf("Would you like to return to the Profile Menu? (Y/N)      >");
		rewind(stdin);
		scanf("%c", &endDisplayRecord);
		endDisplayRecord = toupper(endDisplayRecord);

		switch (endDisplayRecord) {
		case 'Y':
			printf("\nYou will now be directed to the Profile Menu.\n");
			system("pause");
			system("cls");
			return 0;
			break;
		case 'N':
			printf("\n");
			system("pause");
			endDisplayRecord = 'O';
			break;
		default:
			printf("ERROR. Please choose the available options.\n\n\n");
			break;
		}
	} while (endDisplayRecord != 'Y' && endDisplayRecord != 'N');
}







void profileMenu(char userId[]) {
	struct Entrance entry[50];
	int option, validMenuChoice;

	printf("\n\t\t\tVVVVVVVV           VVVVVVVV iiii                     iiii          tttt                                               \n");
	printf("\t\t\tV::::::V           V::::::Vi::::i                   i::::i      ttt:::t                                               \n");
	printf("\t\t\tV::::::V           V::::::V iiii                     iiii       t:::::t                                               \n");
	printf("\t\t\tV::::::V           V::::::V                                     t:::::t                                               \n");
	printf("\t\t\t V:::::V           V:::::Viiiiiii     ssssssssss   iiiiiiittttttt:::::ttttttt       ooooooooooo   rrrrr   rrrrrrrrr   \n");
	printf("\t\t\t  V:::::V         V:::::V i:::::i   ss::::::::::s  i:::::it:::::::::::::::::t     oo:::::::::::oo r::::rrr:::::::::r  \n");
	printf("\t\t\t   V:::::V       V:::::V   i::::i ss:::::::::::::s  i::::it:::::::::::::::::t    o:::::::::::::::or:::::::::::::::::r \n");
	printf("\t\t\t    V:::::V     V:::::V    i::::i s::::::ssss:::::s i::::itttttt:::::::tttttt    o:::::ooooo:::::orr::::::rrrrr::::::r\n");
	printf("\t\t\t     V:::::V   V:::::V     i::::i  s:::::s  ssssss  i::::i      t:::::t          o::::o     o::::o r:::::r     r:::::r\n");
	printf("\t\t\t      V:::::V V:::::V      i::::i    s::::::s       i::::i      t:::::t          o::::o     o::::o r:::::r     rrrrrrr\n");
	printf("\t\t\t       V:::::V:::::V       i::::i       s::::::s    i::::i      t:::::t          o::::o     o::::o r:::::r            \n");
	printf("\t\t\t        V:::::::::V        i::::i ssssss   s:::::s  i::::i      t:::::t    tttttto::::o     o::::o r:::::r            \n");
	printf("\t\t\t         V:::::::V        i::::::is:::::ssss::::::si::::::i     t::::::tttt:::::to:::::ooooo:::::o r:::::r            \n");
	printf("\t\t\t          V:::::V         i::::::is::::::::::::::s i::::::i     tt::::::::::::::to:::::::::::::::o r:::::r            \n");
	printf("\t\t\t           V:::V          i::::::i s:::::::::::ss  i::::::i       tt:::::::::::tt oo:::::::::::oo  r:::::r            \n");
	printf("\t\t\t            VVV           iiiiiiii  sssssssssss    iiiiiiii         ttttttttttt     ooooooooooo    rrrrrrr            \n\n");
	do {
		printf("\n\n\t\t\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t\t\t       |       Dear User, what would you wish to perform  ?    |\n");
		printf("\t\t\t\t\t\t       |                                                       |\n");
		printf("\t\t\t\t\t\t       |             (1) -   ABOUT ME                          |\n");//show visitor information
		printf("\t\t\t\t\t\t       |             (2) -   CHANGE THE CURRENT RECORDS        |\n");//modify visitor information
		printf("\t\t\t\t\t\t       |             (3) -   CHECK IN & CHECK OUT              |\n");//visit & exit
		printf("\t\t\t\t\t\t       |             (4) -   DISPLAY ENTRY HISTORY             |\n");//display visitor entrance records (Visit & Exit )
		printf("\t\t\t\t\t\t       |             (5) -   EXIT                              |\n");
		printf("\t\t\t\t\t\t       ---------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t               Please enter your option -> ");
		rewind(stdin);
		scanf("%d", &option);
		switch (option) {
		case 1:
			system("cls"); loginHeader(4);
			displayFunction(userId);
			validMenuChoice = 0;
			break;
		case 2:
			//modify function

			system("cls"); loginHeader(4);
			modifyFunction(userId);
			validMenuChoice = 0;
			break;
		case 3:
			//delete function
			typeOfEntrance(userId);
			validMenuChoice = 0;
			break;
		case 4:
			displayHistoryVisitor(userId, entry);
			validMenuChoice = 0;
			break;
		case 5:
			exit(0);
		default:sound();
		}
	} while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5);
}
