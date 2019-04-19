#include<stdio.h>
#include<conio.h>
 
int main()
{
    int at[20],bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("\t**************************************************Welcome***************************************************");
    printf("\n \t************************************Operating System Project Work*************************************");
    printf("\n Topic:Priority Scheduling");
    printf("\n Please Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time,Arrival Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Arrival Time:");
        scanf("%d",&at[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //it contains process number\
    }
 
   
    for(i=0;i<n;i++)  //used selection sort for sorting burst time, priority and process number in ascending order 
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
 
    
    for(i=1;i<n;i++) //calculating waiting time
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //calculating average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculating  turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //calculating average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    return 0;
}

