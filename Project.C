#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <windows.h>

// Declaring all the functions
void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);
void quiz();



// Creating a global structure to store
// data of the user
struct pass 
{
	char username[50];
	int date, month, year;
	//(no need) char pnumber[15];
	char fname[20];
	char lname[20];
	
};

// Structure to keep track
// of amount transfer
struct money 
{
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
	float balance;
};

// Structure to make up a password that you can log in with//
struct userpass 
{
	char password[50];
};


// Function to create accounts
// of users
void account(void)
{
	char password[20]; //
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu; //fp is for opening the file// //fu is for closing file//
	struct pass u1; //making a structure from the pass structure named u1//
	struct userpass p1; //making a structure from the userpass structure named p1//

	struct userpass u2;

	// Opening file to
	// write data of a user
	fp = fopen("username.txt", "w"); //opening a file in writing mode//

	// Inputs
	system("cls");
	printf("\n\nCreate Account: ");

	printf("\n\nFirst Name: ");
	scanf("%s", &u1.fname);

	printf("\n\n\nLast Name: ");
	scanf("%s", &u1.lname);
	
	printf("\n\nUsername: ");
	scanf("%s", &u1.username);

	printf("\n\nPassword: ");

	//Password 
		for (i = 0; i < 50; i++) 
	{
		ch = getche();
		if (ch != 13)
		 {
			password[i] = ch;
			ch = '*';	
			printf("%c", ch);
		 }
		else if (ch == 13)
		{
			break;
		}
	}
	password[i]='\0';

	// Writing to the file
	fwrite(&u1, sizeof(u1), 1, fp); //arguments =(where we write, how much memory we give to the file, how much we write, variable that will function as our output)//

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountcreated();
}

// Successful account creation
void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf("Please wait....\n\nYour data is processing....");
	for (i = 0; i < 200000000; i++) 
	{
		i++;
		i--;
	}

	

	printf("Account has been created successfully....\n");
	

	printf("Press Enter to login: ");

	getche();
	login();//calling function
}

// Login function to check
// the username of the user
void login(void)
{
	system("cls");
	int value;
	char username[50];
	char password[50];

	int i, j, k, count=0, value2;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	// Opening file of
	// user data
	fp = fopen("username.txt", "r"); //opening a file in the read mode//

	if (fp == NULL) 
	{
		printf("Error in opening the file. ");
	}
	
	printf(" Account Login: \n");
	
	printf("**************************************************************\n");

	
	printf("---- Log In ----\n");

	// Take input
	
	printf("Username: \n");
	scanf("%s", &username);

	// Checking if username
	// exists in the file or not
	while (fread(&u1, sizeof(u1), 1, fp)) //arguments = ()
	{
		do
		{
			value2= (strcmp(username, u1.username)); //if the predefined username and the username entered are identical//
			if (value2 == 0)
			{
				loginsu();
				display(username);
			}

			else 
			{
				printf("Username entered wrong! \n");
				break;
			}
			count=count +1;
		} while (value2!=0 || count<3);
		
		
	printf("Password: \n");

	// Input the password
	for (i = 0; i < 50; i++) 
	{
		ch = getch();
		if (ch != 13)
		{
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
		{
			break;
		}
			
	}

	
		do
		{
			// Input the password
			for (i = 0; i < 50; i++) 
				{
				count=0;
				ch = getch();
				if (ch != 13)
				{
					password[i] = ch;
					ch = '*';
					printf("%c", ch);
				}

				else
				{
					break;
				}
					
				}
				 value =(strcmp(password, u2.password));//if the predefined username and the username entered are identical//
			if (value == 0)
			{
				loginsu();
				
			}

			else 
			{
				printf("Password entered wrong! \n");
				break;
			}
		}while (value!=0 || count<3);
		} 
		
		

	// Closing the file
	fclose(fp);
}

// Redirect after
// successful login
void loginsu(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details: \n");
	for (i = 0; i < 20000; i++) 
	{
		i++;
		i--;
	}

	
	printf("Login Successful: \n");
	
	printf("Press Enter to continue: \n");

	getche();
}

// Display function to show the
// data of the user on screen
void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "r");
	struct pass u1;

	if (fp == NULL) 
	{
		printf("Error in opening the file. ");
	}

	while (fread(&u1, sizeof(u1), 1, fp)) 
	{
		if (strcmp(username1, u1.username) == 0) //if predefined username and username entered are equal//
		 {
			
			printf("Welcome ! %s %s", u1.fname, u1.lname);
			
			printf("..........................\n");
			
			printf("---- Your Account Info----\n");
			
			printf("***************************\n");
			
			printf("Name: ..%s %s", u1.fname, u1.lname);

		}
	}

	fclose(fp); //closed (read) file//

	

	// Menu to perform different
	// actions by user
	printf(" HOME ");
	
	printf("******");
	
	printf(" 1....Check Balance: \n");
	
	printf(" 2....Transfer Money: \n");
	
	printf(" 3....Log Out: \n\n");
	
	printf(" 4....Exit: \n\n");

	printf(" Exit your choices..\n");
	scanf("%d", &choice);

	switch (choice) 
	{
		case 1:
			checkbalance(username1);
			break;
	
		case 2:
			transfermoney();
			break;
	
		case 3:
			logout();
			login();
			break;
	
		case 4:
			exit(0);
			break;
		}
	}

// Function to transfer
// money from one user to
// another
void transfermoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	// Opening file in read mode to
	// read user's username
	fp = fopen("username.txt", "a");

	// Creating a another file
	// to write amount along with
	// username to which amount
	// is going to be transferred
	fm = fopen("mon.txt", "a");

	
	printf("---- Transfer Money ----/n");
	
	printf("========================/n");

	
	printf("From (your username).. ");
	scanf("%s", &usernamet);

	
	printf(" To (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username if it
	// is present in file or not
	while (fread(&u1, sizeof(u1), 1, fp))
	{
		if (strcmp(usernamep, u1.username) == 0)
		{
				strcpy(m1.usernameto, u1.username);
				strcpy(m1.userpersonfrom, usernamet);
		}
	}
	
	// Taking amount input
	printf("Enter the amount to be transferred:" );
	scanf("%d", &m1.money1);
//	if (&m1.money1 > balance)
//	{
//		printf("Transfer amount is greater than User Balance. \nTry giving the quiz to obtain reward money!\n");
//		quiz();
//	}
//	else
	{
		// Writing to the file
		fwrite(&m1, sizeof(m1), 1, fm);

		printf("------------------------------------------------\n");

		printf("--------------------------------------------------\n");
			

		printf("Transfering amount, Please wait..\n");

		
		for (i = 0; i < 70; i++) 
		{
			for (j = 0; j < 1200000; j++)
			{
				j++;
				j--;
			}
			printf("*");
		}


		printf("Amount successfully transferred! ");
		getche();

		// Close the files
		fclose(fp);
		fclose(fm);

		// Function to return
		// to the home screen
		display(usernamet);
	}
	
}

// Function to check balance
// in users account
void checkbalance(char username2[])
{
	system("cls");
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;

	// Opening amount file record
	fm = fopen("mon.txt", "");

	printf("---- BALANCE DASHBOARD ----\n");
	
	printf("***************************\n");
	
	// Reading username to
	// fetch the correct record
	while (fread(&m1, sizeof(m1), 1, fm)) 
	{
		if (strcmp(username2, m1.usernameto) == 0) //if the username that we are sending the money to, exists//
		 {	
			printf("%d", i);
			i++;
			
			printf("%s", m1.userpersonfrom);
	
			printf("%d", m1.money1);
			// Adding and
			// finding total money
			summoney = summoney + m1.money1;
		}
	}

	
	printf("Total Amount: ");

	printf("%d", summoney);

	getche();

	// Closing file after
	// reading it
	fclose(fm);
	display(username2);
}

// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	system("cls");
	printf("Please wait, logging out");

	for (i = 0; i < 10; i++) 
	{
		for (j = 0; j < 25000000; j++)
		{
			i++;
			i--;
		}
		printf(".");
	}

	
	printf("Sign out successfully..\n");

	
	printf("Press any key to continue..\n");

	getche();
}

	void quiz()
	{
		char quest [5][100];
		char optionl [3][20],option2 [3][20], 
		option3 [3][20],option4 [3][20], 
		option5 [3][20]; 
		int response[5], correct_ans[5], option,i, marks;  
		system("cls");
		strcpy(quest[0], "Name the capital of India");  
		strcpy (optionl [0],"1. Mumbai");  
		strcpy(optionl[1] ,"2. New Delhi");  
		strcpy(optionl[2] ,"3. Chennai");  
		correct_ans[0] = 1;  
		strcpy(quest[1], "Name the national bird of India");  
		strcpy(option2 [0],"1. Peacock");  
		strcpy(option2[1], "2. Sparrow");  
		strcpy(option2[2],"3. Parrot");  
		correct_ans[1]=0;  
		strcpy(quest[2], "Name the First Prime minister of India");  
		strcpy(option3 [0],"1. M D Gandi");  
		strcpy(option3[1] ,"2. S D Sharma");  
		strcpy(option3 [2],"3. J L Nehru");  
		correct_ans[2]=2;  
		strcpy(quest[3], "Name the first female president of India");  
		strcpy(option4 [0],"l. Pratibha Patil");  
		strcpy(option4[1] ,"2. Sonia Gandhi");  
		strcpy(option4[2] ,"3. Indira Gandhi");  
		correct_ans[3] = 0;  
		strcpy(quest[4], "Name the youngest prime minister of India");  
		strcpy(option5[0],"l. Rajiv Gandhi");  
		strcpy(option5[1], "2. Sanjay Gandhi");  
		strcpy(option5[2],"3. Rahul Gandhi");  
		correct_ans[4] = 0; 
		do {  
			printf("\n\n\n\n QUIZ PROGRAM"); 
			printf("\n*******************");  
			printf("\n 1. Display Questions");  
			printf("\n 2. Display Correct Answers");  
			printf("\n 3. Display Result");  
			printf("\n 4. EXIT");  
			printf ("\n *************************");  
			printf("\n\n\n Enter your option: ");  
			scanf("%d", &option);  
			switch(option)  {  
			case 1:    
				printf ("\n %s \n", quest [0]);   
				for(i=0;i<3;i++)   {   
					printf("\n %s", optionl[i]);   
				}   
				printf ("\n\n Enter your answer number: ");   
				scanf("%d", &response[0]);   
				printf ("\n %s \n", quest [1]);   
				for (i=0;i<3;i++)   {   
					printf("\n %s", option2[i]);   
				}   
				printf("\n\n Enter your answer number: ");   
				scanf("%d", &response[1]);   
				printf("\n %s \n", quest[2]);  
				for(i=0;i<3;i++)  {   
					printf("\n %s", option3[i]);  
				}   
				printf("\n\n Enter your answer number: ");   
				scanf ("%d", &response [2]);   
				printf("\n %s \n", quest[3]);  
				for (i=0;i<3;i++)  {   
					printf("\n %s", option4[i]);  
				}   
				printf("\n\n Enter your answer number: ");   
				scanf ("%d", &response [3]);   
				printf("\n %s \n", quest[4]);  
				for (i=0;i<3;i++)  {   
					printf("\n %s", option5[i]);  
				}   
				printf("\n\n Enter your answer number: ");   
				scanf ("%d", &response [4] );   
				break;  
			case 2:   
				printf("\n\n CHECK THE CORRECT ANSWERS");   
				printf("\n ************************");   
				printf("\n %s \n %s",quest[0] ,optionl[correct_ans[0]]);   
				printf("\n\n %s \n%s",quest[1] ,option2[correct_ans[1]]);   
				printf("\n\n %s \n%s",quest[2] ,option3[correct_ans[2]]);   
				printf("\n\n %s \n%s",quest[3] ,option4[correct_ans[3]]);   
				printf("\n\n %s \n%s",quest[4] ,option5[correct_ans[4]]);   
				break;  
			case 3:   
				marks = 0;  
				for(i = 0;i <= 4;i++)  {   
					if(correct_ans[i]+1==response[i])   {   
						marks++;   
					}  
				}   
				printf ("\n Out of 5 you score %d",marks);   
				break;  
			}  
		}  
			while(option!=4);  
			getch();  
			

}

int main()
{
	int i, a, b, choice;
	int passwordlength;
	system("color 06");

	// Creating a Main
	// menu for the user
	printf("Hello and welcome!\n\n");
	

	printf("**********************************\n");
	

	
	printf("1.... Create a Bank Account: \n");

	
	printf("2.... Already a user? Sign in!: \n");
	
	printf("3.... Exit\n");
	
	printf("**********************************\n");

	printf("\n\nEnter your choice: ");

	scanf("%d", &choice);

	switch (choice) 
	{
		case 1:
			system("cls");
			printf("\n Username 50 characters max. ");
			printf("\n Password should be 50 characters max. ");
			account();
			break;
	
		case 2:
			login();
			break;
	
		case 3:
			exit(0);
			break;
	
			getch();	
	}
}

  















