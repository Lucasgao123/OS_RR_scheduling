#include<stdio.h>
 
int main()
{
      int i, schedule_number, cumulative_time = 0, x, counter = 0, quantum_total, quantum;
      int wtime = 0; //wait time
      int ttime = 0; //turnaround time
      int btime[10]; //burst time
      int temp[10]; //temp set    
      float AWT, ATT;// average waiting time, average turnaround time
      printf("=================================================\n");
      printf("Enter the number of processes to schedule:\t");
      scanf("%d", &schedule_number);//number of schedule processes
 
      for(i = 0; i < schedule_number; i++){
            printf("Enter the burst time of process %d: ", i + 1);
            scanf("%d", &btime[i]);//get burst time
            //temp[i] = btime[i];
      }
      printf("Enter the maximum length of the time quantum q:\t");
      scanf("%d", &quantum_total);//get quantum number
      quantum = 1;
      while(quantum <= quantum_total){

	//initialization after a loop	
	AWT = 0;
      	ATT = 0;
	wtime = 0;
	ttime = 0;
	for(i = 0; i < schedule_number; i++){
            temp[i] = btime[i];	   
      	}	
      	x = schedule_number;




	
	printf("\nq = %d: \nSchedule:\t",quantum);

	for (cumulative_time = 0, i = 0; x != 0;){

	   	 if(temp[i] <= quantum && temp[i] > 0){ // case 1: if 0 < burst time <= quantum                
			 cumulative_time = cumulative_time + temp[i];
         	         temp[i] = 0;
        	         flag = 1;
			 printf("%d ",i + 1);
			
       		     }
            	 else if(temp[i] > 0){// case 2: if 0 < burst time but burst time > quantum
                  	temp[i] = temp[i] - quantum;
                  	cumulative_time = cumulative_time + quantum;
		  	printf("%d ",i + 1);
		  	
            	     }
            	 if(temp[i] == 0 && flag == 1){
                  	x--;
		  	//calculate waiting time and turnaround time
                  	wtime = wtime + cumulative_time - btime[i];
                  	ttime = ttime + cumulative_time;
                  	flag = 0;
            	     }
            	 if(i == schedule_number - 1){				  
                    	i = 0;// when it comes to the limit, initialize it
            	     }
            	 else if(cumulative_time >= 0){			  	  
                  	i++; //keep loopping
            	    }	
            	 else{	  
                  	i = 0;
            	    }
		
      	}
	AWT = wtime * 1.0 / schedule_number;
      	ATT = ttime * 1.0 / schedule_number;
	printf("\nq = %d: \t",quantum);
      	printf("AWT:\t%f\t", AWT);
      	printf("ATT:\t%f\n", ATT);
	quantum = quantum + 1;
      }

      printf("=================================================\n");
      return 0;
}
