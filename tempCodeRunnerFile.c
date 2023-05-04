#include <stdio.h> 
#include<stdlib.h>

int main ()
{
  int n, i, j, k, temp, sum = 0;
  float avg;
  printf ("Sacchit Wathe\t60019210066\nEnter the number of processes: ");
  scanf ("%d", &n);
  int *burst_time = (int *) malloc (n * sizeof (int));
  int *waiting_time 
 = (int *) malloc (n * sizeof (int));
  int *turnaround_time = (int *) malloc (n * sizeof (int));
  int *process_id = (int *) malloc (n * sizeof (int));
  printf ("Enter the burst time for each process:");
  
for (i = 0; i < n; i++)
    
    {
      scanf ("%d", &burst_time[i]);
    
}
  int *arrival_time = (int *) malloc (n * sizeof (int));
  printf ("Enter the
arrival time for each process:");
  for (i = 0; i < n; i++)
    
    {
      scanf ("%d", &arrival_time[i]);
    
}
  
process_id[0] = 1;
  for (i = 1; i < n; i++)
    
    {
      
process_id[i] = i + 1;
    
}
  
//Sorting the processes according to their arrival time for (i = 0; i
    <n;
  i++) 
  {
    
for (j = i + 1; j < n; j++)
      
      {
	if (arrival_time[i] > arrival_time[j])
	  
	  {
	    
temp = arrival_time[i];
	    arrival_time[i] = arrival_time[j];
	    arrival_time[j] = temp;
	    temp = burst_time[i];
	    burst_time[i] = burst_time[j];
	    burst_time[j] 
 = temp;
	    
temp = process_id[i];
	    process_id[i] = process_id[j];
	    process_id[j] = temp;
	  
}
      
}
  
}
  
//Calculating the waiting time for each process for (i = 0; i < n; i++)
  {
    waiting_time[i] = 0;
    for (j = 0; j < i; j++)
      
      {
	waiting_time[i] += burst_time[j];
      
}
    sum += waiting_time[i];
  
}
  
avg = (float) sum / n;
  sum = 0;
  
printf (" Process\tBurst Time\tArrival Time\tWaiting
Time\tTurnaround Time");
  for (i = 0; i < n; i++)
    
    {
      
turnaround_time[i] = burst_time[i] + waiting_time[i];
      sum += turnaround_time[i];
      printf ("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", process_id[i], burst_time[i],
	      arrival_time[i], waiting_time[i], turnaround_time[i]);
    
}
  
//Display a Gantt Chart for the scheduling printf("\nGantt
Chart:\n | ");
for (i = 0; i < n; i++)
{ printf(" \ tP % d \ t | ", process_id[i]);
} printf(" \ n "); printf(" 0 \ t ");
for (i = 0; i < n; i++)
{ printf(" \ t % d \ t ", turnaround_time[i]);
} return 0;
}

