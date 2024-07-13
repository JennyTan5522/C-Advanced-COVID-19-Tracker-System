#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>    //display time
#include<Windows.h> //display time & invalid choice will pop a sound
#include<stdbool.h> //boolean expression
#include<conio.h>   //clear screen
#include<math.h>
#pragma warning(disable:4996)

void loginHeader(int num);
void adminLoginMenu();
void entryInterface();

//visitor information variables
void visitorMenu();
void visitorInfoMenu();//visitor Menu
void profileMenu(char userId[]); //After successfully login ,llow them to choose whether want to dsiplay , modify or check-in
void visitorLogin();
void visitorRegisterAccount();
void displayFunction(char currentUserId[]); //Visitor display part
void displayRecordFunction();//Admin display part
void modifyFunction();
void searchFunction();

int is_valid(char email[50]);
int is_valid(char email[50]);
void deleteFunction();

//Visit & Exit variables
void typeOfEntrance(char currentUserId[]);//For user select check-in or check-out
void checkIn(char currentUserId[]);
void checkOut(char currentUserId[]);
void modifyEntry(struct Entrance entry[50]);//Update current records
void displayHistoryVisitor(char currentUserId[], struct Entrance entry[50]); //Visitor dislpay part
void displayHistoryAdmin(struct Entrance entry[50]); //Admin display part
void deleteEntry(struct Entrance entry[50]);
int deleteIndex(int i); //Delete index part from delete entry
void entranceReport(struct Entrance entry[50]);
bool checkIsNum(int input); //Digit validation
void sound(); //For invalid option 
void VisitAndExit();
void searchEntry(struct Entrance entry[50]);

//venue variables
void menuVenue();
void venueList();
void addVenue();
void modifyVenue();
void searchVenue();
void displayVenue();
void reserveVenue();
void deleteVenue();
int integerCheck();
void updateStatus();
void doubleLine();


//Visitor information variables
typedef struct {
	int noCharacter;
	int noAlphabet;
	int noDigit;
	int noSpecialCharacter;
	int noSpace;
	int noSpecialCharacterWithoutSpace;
}Validation;


// Admin Functions
void searchAdmin();
void addAdmin();
void deleteAdmin();
int adminMenu();
void modifyAdmin(int num);
void adminReport();
void adminLogin();

struct Date {
	int day, month, year;
};


typedef struct {
	char visitorUserId[10];
	char visitorIcNo[13];
	char visitorPassportNo[10];
	char visitorName[150];
	char visitorGender;
	struct Date visitorBd;
	char visitorEmail[50];
	char visitorContactNo[13];
	char visitorAddress[100];
	int visitorAccStatus;
}VisitorInfo;



//Visit & Exit variables
//tagged structure
struct Symptoms {
	int fever, cough, breath, headache, contact;
};

//typedef structure -> check in variables
typedef struct {
	char  venueId[30], id[20], purpose[60], risk[10];
	int checkInHours, checkInMinutes, checkInDay, checkInMonth, checkInYear;
	double temp;
	struct Symptoms symptoms; //nested structure
}Checkin;

// -> check-out variables
typedef struct {
	int outHour, outMins, totalMins, feedback, rating;
	char  feed[15], rate[15];
}Checkout;


struct Entrance {
	char entryId[10];
	Checkin in;
	Checkout out;
	struct Symptoms symptoms;
};

//backup structure variables  
struct {
	int checkInDay, checkInMonth, checkInYear, checkInHours, checkInMins, exitHour, exitMins, duration;
	double temp;
	char personalId[10], entryId[10], venueId[30], purpose[30], rate[10], feedback[15], risk[10];
}backup;



//Venue variables
typedef struct {
	char venueId[5];
	int reserveYear, reserveMonth, reserveDay, reserveStartHr, reserveStartMin, reserveEndHr, reserveEndMin;
	char reserveReason[100];
}reserve;

reserve reserveV[100];

struct opDay {
	char opStartDay[100], opEndDay[100];
};

struct opTime {
	int	opStartTime, opEndTime;
	struct opDay day;
};

typedef struct {
	int saniDay, saniMonth, saniYear;
}Sanitization;

struct {
	char venueID[5], venueCat[25], venueName[25], status[12];
	int maxVis, currentVisitors;
	struct opTime timeDay;
	Sanitization saniTime;
}v[1000];


//Sanitazation
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

//function declaration
void sanitizationMenu();
void search();

