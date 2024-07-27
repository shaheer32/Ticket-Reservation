#include<stdio.h>
#include<stdlib.h>

//function declearation
void reg();  //function for registration
int confrim(int num);
int movie_details();
int movie1();
int movie2();
int movie3();
int movie4();
//seats 
int array[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
int i=0;
int seat=0;
int j=0;
int temp[30];
//seatlist 

 int seatlist(int num);  
//login
	int name;
	int login;
//reception portal
int reception();

// see reservation by admin
int seeReservations();
     
int main()
{		

printf("\n\t********** Ticket Reservation System ***********\n"); 
    
     printf("\n Press 1. to run Admin Portal \n");
     printf("\n Press 2. to run as Reception Portal \n");
     printf("\n Enter input: \n");
     scanf("%d", &login);
     if(login==2)
     {
       int temp = reception();
	 }
     
     else if(login==1)
     {
     	seeReservations();
	 }

return 0;
}

int reception()
{
printf("\n\t**********WELCOME TO RECEPTION PORTAL***********\n");
printf("\n\t**********LIST OF MOVIES***********\n");

		printf("1. Hobbs and shaw \tTiming:11:30-1:30\n");
		printf("2. Rush Hour \tTiming:11:30-1:30 \n");
		printf("3. Captain Marvel \tTiming:6:30-9:30 \n");
		printf("4. Iron Man \tTiming:8:00-11:00 \n");
		
printf("\n\t**********SELECT YOUR MOVIE***********\n");
movie_details();	
	
}
int movie_details()
{
		int num;
	printf ("Enter movie no:");		//input of movie
	scanf("%d", &num); 
    switch(num)
	{
	    case 01:
	    confrim(num);
	    movie1();
		break;
		
	   case 02:
	   	confrim(num);
	   	movie2();
	   break;
	   
	   case 03:
	    confrim(num);
	    movie3();
	   break;
	   
	   case 04:
	   	confrim(num);
	   	movie4();
	   break;
	   
	 default:
	    printf("Invalid:");
	    break;
	} 

}

int movie1()
{
	FILE *frecipt;
	printf(" \tShow name : Hobbs and shaw\n");
  	printf(" \tDate : 20- January- 2021 \n");
    printf("\tTime :8:00-11:00:\n");
    printf("\tPrice : 500Rs\n");
    
    printf("\t\t================================");
    
    	frecipt=fopen("receipt.txt","a+");
		fprintf(frecipt,"\tShow name : Hobbs and shaw\n");
  		fprintf(frecipt," \tDate : 20- January- 2021 \n");
    	fprintf(frecipt,"\tTime :8:00-11:00:\n");
    	fprintf(frecipt,"\tPrice : 500Rs\n");
    	fprintf(frecipt,"\t\t================================");
    
	fclose(frecipt);
    
}

int movie2()
{
	FILE *frecipt;
	printf("\tShow name :Rush Hour\n");
    printf("\tDay: Sunday\n");
    printf("\tTiming:11:30-1:30\n");
    printf("\tPrice: 500Rs\n");
      printf("\t\t================================");
      
      frecipt=fopen("receipt.txt","a+");
		fprintf(frecipt,"\tShow name : Rush Hour\n");
  		fprintf(frecipt," \tDate : 20- January- 2021 \n");
    	fprintf(frecipt,"\tTime :11:30-1:30\n");
    	fprintf(frecipt,"\tPrice : 500Rs\n");
    	fprintf(frecipt,"\t\t================================");
    
	fclose(frecipt);
      
}

int movie3()
{
		FILE *frecipt;
	printf("\tShow name :Captain Marvel\n");
    printf("\tDay: Sunday\n");
    printf("\tTiming:6:30-9:30\n");
    printf("\tPrice: 500Rs\n");
     printf("\t\t================================");
     
     frecipt=fopen("receipt.txt","a+");
		fprintf(frecipt,"\tShow name : Captain Marvel\n");
  		fprintf(frecipt," \tDate : 20- January- 2021 \n");
    	fprintf(frecipt,"\tTime :6:30-9:30\n");
    	fprintf(frecipt,"\tPrice : 500Rs\n");
    	fprintf(frecipt,"\t\t================================");
}
int movie4()
{
		FILE *frecipt;
	printf("\tShow name : Iron Man\n");
    printf("\tDay: Monday\n");
    printf("\tTiming:8:00-11:00\n");
    printf("\tPrice: 500Rs\n");
     printf("\t\t================================");
     
     
     frecipt=fopen("receipt.txt","a+");
		fprintf(frecipt,"\tShow name : Iron Man\n");
  		fprintf(frecipt," \tDate : 20- January- 2021 \n");
    	fprintf(frecipt,"\tTime :8:00-11:00\n");
    	fprintf(frecipt,"\tPrice : 500Rs\n");
    	fprintf(frecipt,"\t\t================================");
}

void reg()
{
	char FirstName[20];
	char LastName[20];
	char phoneNo[20];
	char email[20];
	int bookingId= 10001;
	FILE *frecipt; 		//file pointer of recipt
	
	printf("\nEnter your Details:: \n");
    printf("First name: ");
    scanf("%s", FirstName);
    printf("Last name: ");
    scanf("%s", LastName);
    printf("Phone number: ");
    scanf("%s", phoneNo);
    printf("email: ");
    scanf("%s", email);
	bookingId++;
	
	printf("\n\t\t================================\n");      // printing recipt on console
        printf("\tPLEASE COLLECT YOUR RECIPT\n");
        	printf("\t\t Booking ID : %d\n " ,bookingId);
        	printf("\tCustomer : %s\t", FirstName);
        	printf("\tContact no : %s\n", phoneNo);
        	
  	frecipt=fopen("receipt.txt","a+"); //file open in append mode  
	fprintf(frecipt,"\n\t\t================================\n");  //printing recipt on file
	fprintf(frecipt,"\t \t RECEIPT for Booking ID: %d \n",bookingId );    
    fprintf(frecipt,"\tCustomer : %s\t", FirstName);
    fprintf(frecipt,"\tContact no : %s\n", phoneNo);
	fclose(frecipt);
	
	// going to cnfrim func
}

int confrim(int num)

{
	int input;
	int userSeat;  	// returning seat number from seatlist func
	FILE *frecipt;

	userSeat=seatlist(num);	   //calling func of seatlist to book seat
		reg();  //calling of regis func
		
		
		printf("\n \tSeat No: %d\n\n" ,userSeat);   //print seat num in console
		frecipt=fopen("receipt.txt","a+");
		fprintf(frecipt,"\n \tSeat No: %d\n\n" ,userSeat); //print seat num in recipt file
		fclose(frecipt); 

		// go to switch case of movie detail func
	
}

 int seatlist(int num)
 {
 	char a[100];
	int seatNo;
 	FILE *fptr;			//file pointer to read file
 	
 	switch(num)
	{
	    case 01:
	    	fptr = fopen("movie1.txt","r");	  //open file in read mode	
		break;
		
	   case 02:
	   	fptr = fopen("movie2.txt","r");
	   break;
	   
	   case 03:
	   	fptr = fopen("movie3.txt","r");
	   break;
	   
	   case 04:
	   	fptr = fopen("movie4.txt","r");
	   break;
	   
	 default:
	    printf("Invalid:");
	    fptr = NULL;
	    break;
	} 
 	
 	if (fptr  == NULL)
	{
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   	}
   	int i = 0;
   	int increment = 0;
   	printf("\n\n");
   	while(!feof (fptr))    //loop to read file till end 
   	{
      	fscanf (fptr, "%d", &i); 
      	printf ("%d \t", i);    // print text file of movies in console.
      	temp[increment] = i;    
      	increment++;  
      	if(i==10 || i ==20)
		{
			printf("\n\n");
		}
	}
	
   fclose(fptr);
   
   FILE *fptw; // file pointer to write "0" in file 
   
   switch(num)
	{
	    case 01:
	    	fptw = fopen("movie1.txt","w+");    //in file in write mode
		break;
		
	   case 02:
	   	fptw = fopen("movie2.txt","w+");
	   break;
	   
	   case 03:
	   	fptw = fopen("movie3.txt","w+");
	   break;
	   
	   case 04:
	   	fptw = fopen("movie4.txt","w+");
	   break;
	   
	 default:
	    printf("Invalid:");
	    fptr = NULL;
	    break;
	} 
	
	do{
		printf("\n\n\t Which seat do you want? ");
		scanf("%d" ,&seat);
		if(seat == 0)
		{
			printf("Invalid");
		}
		else if(temp[seat-1] == 0)
		{
			printf("Reserved");
		}
		else{
			temp[seat-1]= 0;   
			break;
		}
		
	}while(seat == 0 || temp[seat-1] == 0);
	
	int k=0;
	
	for(k=0;k<30;k++)
	{
		fprintf(fptw,"%d \n",temp[k]);	
	}
	
	fclose(fptw);
	
	return seat; // going to  confrim func
	
}	

int seeReservations()   //admin portal
{
	int hall=0;
	FILE *fhall; 
	printf(" \tSelect Hall no to See its Reservations \n ");
	scanf("%d",&hall);
	switch(hall)
	{
	case 01:
		fhall= fopen("movie1.txt", "r");
		break;

	case 02:
		fhall= fopen("movie2.txt", "r");
		break;
		
	case 03:
	fhall= fopen("movie3.txt", "r");
		break;
		
	case 04:
	fhall= fopen("movie4.txt", "r");
		break;

	 default:
	    printf("Invalid:");
	    fhall = NULL;
	    break;
	}
	    
	    	if (fhall  == NULL)
		{
       	printf("Error! opening file");
       	// Program exits if the file pointer returns NULL.
       	exit(1);
   		}
   		printf("\n\n");
   	while(!feof (fhall))
   	{
      	fscanf (fhall, "%d", &i); 
      	printf ("%d \t", i);  //printing seats from file on console
      	if(i==10 || i ==20)
		{
			printf("\n\n");
		}
	}
	
}
