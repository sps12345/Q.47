#include<stdio.h>
void main()
{
    int arr_time[10],burst_time[10],pr[20],wait_time[10],ta_time[10],n,total=0,pos,temp,c;
    float avg_wt=0,avg_tat=0;
    double wait_t = 0,turnaround_time=0;
    int  tmp[10] ,end;
    int  smallest, count = 0, time;
    int i,j;
    float average_waiting_time, average_turnaround_time;
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        pr[i]=i+1;          
    }
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&arr_time[i]);
        pr[i]=i+1;         
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for( j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=arr_time[i];
        arr_time[i]=arr_time[pos];
        arr_time[pos]=temp;
    }

    wait_time[0]=0;
    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];

        total+=wait_time[i];
    }
    avg_wt=(float)total/n;   
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time \t Arrival Time ");
    for(i=0;i<n;i++)
    {
        ta_time[i]=burst_time[i]+wait_time[i];
        total+=ta_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d\t\t \t  %d",pr[i],burst_time[i],wait_time[i],ta_time[i],arr_time[i]);
    }
printf("\n 1- Preemptive  2-  Non-preemptive \n ");
printf("\n enter the value: ");
scanf("%d",&c);
if(c==1)
{
      burst_time[9] = 9999;
      for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(arr_time[i] <= time && burst_time[i] <burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  printf("%d ",end);
                  for(i=1;i<n;i++);
                  {
                      wait_t= wait_t + wait_time[smallest];
                      turnaround_time= turnaround_time + end - arr_time[smallest];
                  }

            }
    }
      avg_wt = wait_t / n;
      avg_tat = turnaround_time / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", avg_wt);
      printf("Average Turnaround Time:\t%lf\n", avg_tat);
}
else if(c==2)
{
printf("\n \n non preemptive");





    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
else
{
printf("  wrong input");
}
}

