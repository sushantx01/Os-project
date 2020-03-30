#include<stdio.h>
#include<conio.h>
int main()
 {
   int x,n,p[10],pp[10],bt[10],wt[10],tat[10],awt,atat,i,at[10],tq;
 
   /* n:- number of process
      p:- process
   	  pp:- process priority
      bt:- process burst time
      wt:- wait time
      tat:- turnaround time
      awt:- average waiting time
      atat:- average turnaround time
      at:- arrival time
      tq:- time qunatum
 	*/
 
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("Enter time quantum : ");
   scanf("%d",&tq);
   printf("\n\t  Time Priorities  : Burst time : Arrival Time  \n");
 
   for(i=0;i<n;i++)
    {
      //printing process number
      printf("\n Process %d ",i+1);
      // taking values of process priority, burst time, arrival time respectively.
      scanf("%d %d %d",&pp[i],&bt[i] ,&at[i]);
      p[i]=i+1;
    }
 
//sorting on the basis of priority
//using bubble sort
int j;
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
     x=pp[i];
     pp[i]=pp[j];
     pp[j]=x;
     x=bt[i];
     bt[i]=bt[j];
     bt[j]=x;
     x=p[i];
     p[i]=p[j];
     p[j]=x;
      }
      //gc[i]=p[j];
   }
}
wt[0]=0;
awt=0;
tat[0]=bt[0];
atat=tat[0];
for(i=1;i<n;i++)
 {
    if(tq<n || tq>n) {
     
   wt[i]=tat[i-1];
   awt+=wt[i];
   tat[i]=wt[i]+bt[i];
   atat+=tat[i];
     }
 }
 printf("***************************************************************************");
 //Gantt chart
 printf("\n");
 printf("Gantt chart\n");
 for(i=0;i<n;i++)
 {
    printf("P %d ",p[i]);
 }
//Displaying the process in tabular form
 
printf("\n\nProcess \t Arrival time \t Burst Time \t Wait Time   \t Turn Around Time \t Priority \n");
for(i=0;i<n;i++){
printf("\n  %d",p[i]); //printing of process
printf("\t\t %d",at[i]); //printing of arrival time
printf("\t\t %d",bt[i]); //printing of burst time
printf("\t\t %d",wt[i]);//printing of wait time
 printf("\t\t %d",tat[i]); //printing of turn around time
 printf("\t\t %d",pp[i]);//printing of process priorities
 
}
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d ",awt);
printf("\n Average Turn Around Time : %d",atat);
getch();
}
