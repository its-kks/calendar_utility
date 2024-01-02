//Calendar generator
#include <stdio.h>
int datetoday(int mon,int yr)
{
    int month[]={13,14,3,4,5,6,7,8,9,10,11,12};
    int d=1,m=mon,y=yr,num1=0,odd_day,ylst2,yfrst2;
    if(m==1 || m==2)
        y=y-1;
    num1=y;
    int year[4]={};
    for(int i=0;i<=3;i++)
    {
        year[i]=num1%10;
        num1=num1/10;
    }
    ylst2=year[1]*10+year[0];
    yfrst2=year[3]*10+year[2];
    odd_day=(d+((13*(month[m-1]+1))/5)+ylst2+(ylst2/4)+(yfrst2/4)-(2*yfrst2))%7;
    if(odd_day<0)
        odd_day+=7;
    return odd_day;
}
int leap(int year)
{
    int ans=0;
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
                ans=1;
        }
        else
            ans=1;
        
    }
    return ans;
}
int no_of_days(int month,int year)
{
    int nodm[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap(year))
        nodm[1]=29;
return nodm[month-1];

}
void calendar(int month,int year)
{
    int odd_day=datetoday(month, year);
    
    if(odd_day==0){
        // make saturday seven
        odd_day=7;
    }

    int count=1,date=1;
    char *ar[]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG",\
    "SEP","OCT","NOV","DEC"};
    printf("\t\t\t%d %s\n\n",year,ar[month-1]);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n\n");
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(count>=odd_day && date<=no_of_days(month,year))
            {
                printf("%02d\t",date);
                date++;
            }
            else {
                printf("  \t");
                count++;
            }
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    while(1){
        int year,month;
        printf("Enter year:");
        scanf("%d",&year);
        while(year<1)
        {
            printf("Enter valid year:");
            scanf("%d",&year);
        }
        printf("Enter month:");
        scanf("%d",&month);
        while(month<1 || month>12)
        {
            printf("Enter valid month:");
            scanf("%d",&month);
        }
        calendar(month, year);
    }
return 0;
}


    
