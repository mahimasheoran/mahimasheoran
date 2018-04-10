#include<stdio.h>
struct process
{
    char pro_name[10];
    int at,bt,ct,wt,tt,pri,bt1;
}pro[10],pro1[10];
void main()
{
	struct process temp;
    int i,time=0,t1,t2,bu_t=0,largest,limit,count=0,k,pf2=0,limit2,n,pos,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d",&limit);
    n=limit;
    for(i=0;i<limit;i++)
    {
    	printf("\nEnter Process name:-");
    	fflush(stdin);
        scanf("%s",&pro[i].pro_name);
        printf("\nEnter Details For processor %c:\n",pro[i].pro_name);
        printf("Enter arrival time :-");
        scanf("%d",&pro[i].at);
        printf("Enter Burst Time:-");
        scanf("%d",&pro[i].bt);
        pro[i].bt1=pro[i].bt;
        printf("Enter Priority:\t");
        scanf("%d",&pro[i].pri);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); //
