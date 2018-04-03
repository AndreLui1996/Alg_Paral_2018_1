#include <iostream>
#include <ctime>
#include <algorithm>    

#define MAX 100
double A[MAX][MAX], B[MAX][MAX] ,C[MAX][MAX];
using namespace std;




int main()
{
  int b = 20;
  for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       A[i][j] =i+j+2;
      // cout<< a[i][j]<<" ";
    }
  }

  for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       B[i][j] =i+j+5;
      // cout<< a[i][j]<<" ";
    }
  }

////////////////////////////////////////

  int start_s=clock();
      
  for(int i0 = 0; i0< MAX;i0+=b){
      for(int j0=0;j0< MAX;j0+=b){
         for (int x0 = 0; x0 < MAX; x0+=b){
           for (int i = i0; i < min(i0+b,MAX); ++i){
              for (int j = j0; j < min(j0+b,MAX); ++j){
                 for (int x = x0; x < min(x0+b,MAX); ++x){
                    C[i][j] = C[i][j] + A[i][x]*B[x][j];        
                 }
              }
            }
          }
      }
    }
  
  int stop_s=clock();
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

////////////////////////////////////// 6 for ///////////////////

for(int i = 0; i< MAX;i++){
    for(int j=0;j< MAX;j++){
       //cout<< C[i][j]<<" ";
    }
    //cout<<endl;
  }

    return 0;
}
