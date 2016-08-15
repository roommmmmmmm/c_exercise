#include <iostream>
#include <iomanip>
using namespace std;
int main(){
		  int i,j;
		 /*打印表头*/
 		  cout << "Nine-by-nine Multiplication Table " << endl;
		  cout << "------------------------------------------" << endl;
		  cout << "  ";//l两个空格跳过最左列的竖排
	  	  for (i = 1; i <= 9; ++i) {
			   cout << setw(4) << i ;
		  }
		  cout <<"\n";
		  cout << "------------------------------------------" << endl;
		 /*逐行打印*/
		 for (i = 1; i <= 9; ++i) {
			  cout << setw(2) << i; /* 最左列的竖排标志 */	
			  /* 共打印 9 列，j 为列号，只打印上三角，下三角使用空格填充 */
			 for( j = 1; j <= 9; ++j )																 			 	{																				            if( j < i )
		        cout << "    ";			
			  else		 
				  cout << setw(4) << i * j;			
				   cout << endl; /* 结束一行打印，换行 */									
				   }
 cout << "------------------------------------------" << endl;							
 			return 0;
}
