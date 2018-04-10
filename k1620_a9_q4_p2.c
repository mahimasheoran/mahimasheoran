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
    for(i=0;i<limit;i++)
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(pro[j].at<pro[pos].at)
                pos=j;
        }
        temp=pro[i];
        pro[i]=pro[pos];
        pro[pos]=temp;
    }
    time=pro[0].at;
    for(i=0;limit!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(pro[i].at<=time)
    		{
    			for(j=i+1;j<limit;j++)
    			{
    				if(pro[j].at==time&&pro[j].pri<pro[i].pri)
    				{
    					pro1[pf2]=pro[i];
						pf2++;
    					for(k=i;k<limit-1;k++)
    						pro[k]=pro[k+1];
    					limit--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			pro[i].bt--;
			if(pro[i].bt==0)
			{
				pro[i].tt=time-pro[i].at;
				pro[i].wt=pro[i].tt-pro[i].bt1;
				printf("%s\t|\t%d\t|\t%d\n",pro[i].pro_name,pro[i].tt,pro[i].wt);
				wait_time+=time-pro[i].at-pro[i].bt1; 
    			turnaround_time+=time-pro[i].at;
    			for(k=i;k<limit-1;k++)
    				pro[k]=pro[k+1];i--;
    			limit--;
				count=t1;break;
			}
		}
		count=0;
		if(pro[i].bt!=0)
		{
			pro1[pf2]=pro[i];
			pf2++;
			for(k=i;k<limit-1;k++)
    			pro[k]=pro[k+1];
    		limit--;
		}
			if(i==limit-1)
				i=-1;
	} //
