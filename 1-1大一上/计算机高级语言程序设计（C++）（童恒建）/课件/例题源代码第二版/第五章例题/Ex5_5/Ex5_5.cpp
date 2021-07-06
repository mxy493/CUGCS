//¡¾Àı5.5¡¿¾ØÕóÔËËã£º¾ØÕó×ªÖÃÓë¾ØÕóÏà³Ë¡£
#include <iostream>
#include <iomanip>
using namespace std;

void inverse(int [3][6], int [6][3]);
void multi(int [6][3], int [3][4], int [6][4]);
void output(int [6][4]);

int main(){
    int middle[6][3], result[6][4];
    int matrix1[3][6]={8,10,12,23,1,3,5,7,9,2,4,6,34,45,56,2,4,6};   
    int matrix2[3][4]={3,2,1,0,-1,-2,9,8,7,6,5,4};
	inverse(matrix1,middle);
  	multi(middle,matrix2,result);
    output(result);
	return 0;
}

void inverse(int matrix1[3][6],int middle[6][3]){            
    int i,j;
    for (i=0;i<3;i++)
      for (j=0;j<6;j++)
        middle[j][i]=matrix1[i][j];                           
    return;                                                      
}
void multi(int middle[6][3],int matrix2[3][4],int result[6][4]){                                                                    
    int i,j,k;
    for (i=0;i<6;i++){
      for (j=0;j<4;j++){
        result[i][j] = 0;
        for (k=0;k<3;k++)
          result[i][j]+=middle[i][k]*matrix2[k][j];
      }
    }
    return;
}
void output(int result[6][4]){
    int i,j;
	cout <<"result"<<'\n';
    for (i=0;i<6;i++){
      for (j=0;j<4;j++)
        cout <<setw(6)<<result[i][j];
      cout<<'\n';
    }
    return;                                                       
}
