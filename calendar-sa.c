
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define LEAP_YEAR ((Year%4==0 && Year%100 != 0)||Year%400==0)


int MonthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
char *MonthName[]={"January","February","March","April","May","June","July",
	"August","September","October","November","Decembeer"};
char *MonthName1[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP",
	"OCT","NOV","DEC"};
	
int getZeller(int Month,int Year)
{
	int Day = 1, ZMonth, ZYear, Zeller;
	if(Month < 3)
		ZMonth = Month+10;
	else
		ZMonth = Month-2;
	if(ZMonth > 10)
		ZYear = Year-1;
	else
		ZYear = Year;
	Zeller = ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
			(int)((ZYear%100)/4)-2*(int)(ZYear/100)+
			(int)(ZYear/400)+77)%7;
	return Zeller;
}

void main(void)
{
	int Month, Year, Zeller, date ;
	int i, j,m,D,M,Y,flag=0;


	printf("\n\t CALENDER \n");
	if(flag==0)
	{
	    time_t now;
	    time(&now);
	    struct tm *local = localtime(&now);
	    D=local->tm_mday; 
	    Month=local->tm_mon + 1; 
	    Year=local->tm_year + 1900;
	    flag=1;
	    
	}
	else
	{
    	while(TRUE)
    	{
    		
    		printf("\n\n\tEnter mm-yyyy: ");
    		scanf("%d-%d", &Month, &Year);
    		printf("\n");
    		break;
    	}	
    }
    
    sap:
    	Zeller = getZeller(Month,Year);
    	printf("\n\n\t\t\t");
    
    	/* month name */
    	printf("%s %d\n",MonthName[Month-1],Year);
    
    	/* adjusting February in case of Leap Year */
    	MonthDay[1] = LEAP_YEAR ? 29 : 28;
    
    	/* giving output */
    	
    
    	printf("\t");
    	printf("SUN     MON     TUE     WED     THU     FRI    SAT");
    
    	
        printf("\n");
    	/* setting starting position */
    	for(i = 1; i <= Zeller; i++)
    		printf("\t  ");
    	j = Zeller;
    	
    	/* printing dates */
    	for(i = 1; i <= MonthDay[Month-1]; i++)
    	{
    		if(j++ % 7 == 0)
    		{
    			printf("\n\t");
    			if(i==D)
    			{
    			    printf("\033[1;31m");  /*code red activated*/
    			    printf("%2d",i);
    			    printf("\033[0m");     /*code red deactivated*/
    			    
    			}
    			else
    			{
    			printf("%2d",i);
    			}
    			
    		}
    		else
    		{
    		    if(i==D)
    			{
    			    printf("\033[1;31m");    /*code red activated*/
    			    printf("      %2d",i);
    			    printf("\033[0m");       /*code red deactivated*/
    			    
    			}
    			else
    			{
    			printf("      %2d",i);
    			}
    		}
    	}
    	do{
        	printf(" \t\n\n\t\t press 1 for Previous Month \t\n\n\t\t Press 2 for Next Month \t\n\n\t\t Press 3 for Jump To a Date \t\n\n\t\t Press 0 for exit \n\n Enter : ");
        	scanf("%d",&m);
        	
        	switch(m)
        	{
        	    case 1:
        	        Month--;
        			if(Month < 1)
        			{
        				Month = 12;
        				Year--;
        			}
        			goto sap;
        			break;
        		case 2:
        		    Month++;
        			if(Month > 12)
        			{
        				Month = 1;
        				Year++;
        			}
        			goto sap;
        			break;
    			case 3:
			        printf("\t\n\t\tEnter the date :");
			        scanf("%d",&D);
			        printf("\t\n\t\tEnter the month :");
			        scanf("%d",&M);
			        Month=M;
			        printf("\t\n\t\tEnter the Year :");
			        scanf("%d",&Y);
			        Year=Y;
			        goto sap;
			        break;
		        case 0:
		            printf("\t\n\t\tThank You ");
		            break;
		        default:
		            printf("\t\n\t\tEnter a valid Number !\n\n");
		            break;
        	}
        }while(m!=0);
}
	









