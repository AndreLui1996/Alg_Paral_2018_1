#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
/////////unfion leer con Scatter //////////////////////////////
void Odd_Even_Sort(double local_a[], int local_n, int n, char vec_name[], int my_rank, MPI_Comm comm){
  int a[]
  int n;
  int phase, i , temp;
  for(phase=0;phase < n;phase++){
      if(phase %2==0){
        for (i = 1; i < n; i+=2)
            if(a[i-1] > a[i]){
                temp = a[i];
                a[i] = a[i-1];
                a[i-1]= temp;
            }
      }else{
        for (i = 1; i < n-1 ; i+=2)
            if(a[i] > a[i+1]){
                temp = a[i];
                a[i] = a[i+1];
                a[i+1]= temp;  
            }
      }

  } 

}

int main()
{
  int comm_sz = 16;
  int my_rank;
  double start,finish;
  int local_n,local_m;
  MPI_Init(NULL,NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  return 0;
} 