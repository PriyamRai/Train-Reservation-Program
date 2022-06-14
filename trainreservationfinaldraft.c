#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#define  true 1;
#define false 0;
typedef struct traindetails {

        char trainname[20] ;
        char traintime[20];
        char journeyduration[20];
        int fare ;
        int trainnumber;
}  ;

/*typedef struct passengerinfo{
    char name[15] ,gender[10] ;
    int age ;
    struct passengerinfo *next;
};*/
typedef struct mynode {
	char name[20];
	char gen[6];
	int age;
	struct mynode* link;
} Node;

Node * head=NULL;
Node * tail=NULL ;
_Bool authenticateuser(int uid){
    int a[]={2345,3447,5330,9866,8162};
    for(int i=0;i<5;i++){
        if(a[i]==uid){
            return true ;
        }
    }
    return false;


}

_Bool check(char source[],char destination[]){
   // char places[][20]={"Kashi","Ayodhya","Manali","Shimla","Jalandhar","Amritsar","Pune","Mumbai"} ;
   if(strcmp(source,"Kashi")==0&&strcmp(destination,"Ayodhya")==0||strcmp(source,"Manali")==0&&strcmp(destination,"Shimla")==0||strcmp(source,"Jalandhar")==0&&strcmp(destination,"Amritsar")==0||strcmp(source,"Pune")==0&&strcmp(destination,"Mumbai")==0){
        return true;
    }
    return false ;





}

int main() {
    int uid;
    printf("Enter the uid to authenticate : ");
    scanf("%d",&uid);
    _Bool checkers=authenticateuser(uid);
    while(!checkers){
            int i=0;
        for(;i<3;i++){
            printf("Invalid User");
            scanf("%d",&uid);
            checkers=authenticateuser(uid);
        }
        if(i==3){
           printf("Maximum login attempts reached .Please trhy another session");
            return 0 ;
        }
    }
    printf("\nAuthenticating user \nChecking database\n");
    printf("User Authentication Successful : Please continue to book your ticket :\n");
    char source[20] ;
    char destination[20];
    printf("We offer the following touring destinations -\n(1) KASHI TO AYODHYA\n(2) PUNE TO MUMBAI\n(3)JALANDHAR TO AMRITSAR \n(4) MANALI TO SHIMLA\nPLEASE SELECT ANYONE FROM THESE :)");
    printf("Source:");

    scanf("%s",&source);
    printf("\n Destination:");
    scanf("%s",&destination);
    _Bool checking=check(source,destination) ;
    while(!checking){
        printf("Enter a valid source and destination\n Source:");

        scanf("%s",&source);
        printf("\nDestination : ");
        scanf("%s",&destination);
        checking=check(source,destination);
    }
    struct traindetails t1 ;
    if(strcmp(source,"Kashi")==0){
        strcpy(t1.trainname,"SHIVGANGAEXPRESS");
        strcpy(t1.traintime,"15:30-19:35");
        strcpy(t1.journeyduration,"3Hours5Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;

    } else if(strcmp(source,"Pune")==0){
        strcpy(t1.trainname,"JANSHATABDIEXPRESS");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    } else if(strcmp(source,"Jalandhar")==0){
        strcpy(t1.trainname,"GareebrathExpress");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    } else if(strcmp(source,"Manali")==0){
        strcpy(t1.trainname,"ABC");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    }


    int numpassengers;
    //Node * head=NULL ;
    //Node * tail=NULL ;
    printf("Enter the number of tickets you want to book : ");
    scanf("%d",&numpassengers);
    char name[10],gender[10];
    int age ;

      //  Node * newptr=NULL;
    while(numpassengers>0){
        printf("name : ");
        scanf("%s",&name);
        printf("gender:");
        scanf("%s",&gender);
        printf("age : ");
        scanf("%d",&age);
        Node *newptr = (Node*)malloc(sizeof(Node));
        strcpy(newptr->name, name);
        strcpy(newptr->gen, gender);
        newptr->age = age;
        if (head == NULL){
            head=newptr;
            tail=newptr;
         }else{
            tail->link=newptr;
            tail=newptr;
        }
        numpassengers-- ;
    }

        //function to print the ticket :-
    printf("\n            YOUR BOOKING HAS BEEN DONE SUCCESSFULLY !!! \n            PLEASE DOWNLOAD AND SAVE YOUR TICKET \n\n");
    printf("             Train Details and Duration\n");
    printf("%s (%d%) \n",t1.trainname,t1.trainnumber);
    printf("%s            %s\n",t1.traintime,t1.journeyduration);
    printf("%s                 %s",source,destination);
    printf("\n____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("\n            PASSENGER INFORMATION\n");


    Node * temp=head ;
	while(temp!=NULL) {
		printf("%s",temp->name);
		printf("\n");
		printf("%d",temp->age);
		printf("|");
		printf("%s",temp->gen);
		temp=temp->link;
		printf("\n***********\n");
	}
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("PAYMENT DETAILS \n");
    printf("Base Fare       %d\n",t1.fare);
    int i=84;
    printf("Convenience Fee and GST       %d\n",i);
    printf("Total Fare       %d",i+t1.fare);
}




