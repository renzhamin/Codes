/*Tasnim Ferdous IUT-CSE19(+_-)
		please do inform me if you find bugs */

#include "structures.c"
#include "functions.c"
#include "butterfly.c"

int main() {
	
// 	freopen("sample_input.txt","r",stdin);
	butterfly(7,'.',' ');
	printf("Citizen Information Database (maximum 1000 entries) \n");
	
	while(1){
		menu();

		switch(choice){
			case 1 : { 
				add(); 
				break;
			}
			case 2 : { 
				showAll(); 
				break; 
			}
			case 3 : { 
				find();
				break; 
			}
			case 4 : { 
				butterfly(10,'+','.');
				printf("Program is being terminated\n");				 
				return 0;
			}
			default : { 
				printf("Invalid Input ! \n"); 
				break; 
			}
		}
	}

}
