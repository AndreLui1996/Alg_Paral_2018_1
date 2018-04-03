#include <iostream>
#include <ctime>
#include <algorithm>    

#define MAX 100
double A[MAX][MAX], B[MAX][MAX] ,C[MAX][MAX];
using namespace std;

int main()
{

  for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       A[i][j] =i+j+2;
    }
  }

  for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       B[i][j] =i+j+5;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////
    //// IMPLICA :  2n°3 operaciones aritmeticas y PRODUCE : 3n°2 de datos 
    //// DESVENTAJA : Una gran matriz no cabe en la pequeña memoria local
    int start_s=clock();
    for(int i=0; i<MAX; i++){ 
        for(int j=0; j<MAX; j++){ 
            for (int x = 0; x < MAX; ++x)
            {
                C[i][j] = C[i][j] + A[i][x]*B[x][j];        
            }
        }
    }
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

/////////////////////////////////////////////////////////////////////////////////////

for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       //cout<< C[i][j]<<" ";
    }
    //cout<<endl;
  }

    return 0;
}
