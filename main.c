#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include <assert.h>

int main() {
	int choice;
	int accept;
	Student stu[TOTAL_STUDENT];
	accept=declaration();
	assert(accept==1);

	printf("ADMISSION PROCESS");
	printf("1.TOTAL SEATS IN PROGRAMS\n");
    printf("2.STUDENT ROLL NO\n");
    printf("3.FILLED SEATS IN PROGRAMS\n");
	printf("4.STUDENT INFO\n");
	printf("5.WAITING STUDENTS DETAILS\n");
	do{
	    printf("\nCHOOSE FROM ABOVE OPTIONS:\n");
	    scanf("%d",&choice);
	    switch(choice){

	    	case 1: manage_seats();
			break;

			case 2:	student_reg(stu);
		    break;

			case 3: display_total_filled_seats();
			break;

			case 4: display(stu);
			break;

			case 5: display_waiting_students(stu);
			break;

			}


	}while(choice!=0);

	return 0;
}
