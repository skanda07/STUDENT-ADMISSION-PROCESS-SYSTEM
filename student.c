#include <string.h>
#include "student.h"
#include <assert.h>
#include <stdio.h>


void manage_seats(){
	Program prog=program_seats();
	display_seats(prog);
}

Program program_seats(){
	Program pg;
	printf("\nENTER BDA SEATS:\n");
	scanf("%d",&pg.big_data_seats);
	assert(pg.big_data_seats<=40);
	printf("\nENTER ML SEATS:\n");
	scanf("%d",&pg.machine_learning_seats);
	assert(pg.machine_learning_seats<=40);
	printf("\nENTER ES SEATS:\n");
	scanf("%d",&pg.embedded_system_seats);
	assert(pg.embedded_system_seats<=40);
	return pg;
}


void display_seats(Program pg){
	printf("\nTOTAL SEATS IN PROGRAM:\n");
	printf("\nBDA SEATS = %d\n",pg.big_data_seats);

	printf("\nML SEATS = %d\n",pg.machine_learning_seats);

	printf("\nES SEATS = %d\n",pg.embedded_system_seats);
}

void display_total_filled_seats(){
	printf("\nTOTAL FILLED SEATS IN RESPECTIVE DEPARTMENTS:\n");
	printf("\nBDA = %d\n",bda_seats);
	printf("\nML = %d\n",ml_seats);
	printf("\nES = %d\n",es_seats);
	printf("\nTOTAL = %d\n",total_seats);
}

 void student_reg(Student *st){
 	int32_t appnum;
 	int8_t get;
 	printf("\nENTER APPLICATION NUMBER:");
 	scanf("%d",&appnum);
 	printf("\nENTER STUDENT MARKS");
 	scanf("%d",&st[appnum].marks);
 	get=check_status(st[appnum].marks);
 	if(!get){
 		strcpy(st[appnum].status,"ADMITTED");
	 }
	 else{
	 	strcpy(st[appnum].status,"WAITING");;
	 }
 	printf("\nENTER STUDENT NAME:");
 	scanf("%s",&st[appnum].name);
 	printf("\nENTER REGISTRATION NUMBER:");
 	scanf("%d",&st[appnum].regnumber);
 	printf("\nENTER PROGRAM NAME:");
 	scanf("%s",&st[appnum].program);
 	update_seats(st[appnum].program);
 	printf("\nENTER EMAIL ID:");
 	scanf("%s",&st[appnum].email);

 }

 int8_t check_status(int32_t marks){
 	if(marks>5){
 		assert(marks<10);
 		return 0;
	 }
	 else{
	 	return 1;
	 }
 }

 void update_seats(char program[]){
 	assert(strcmp(program,"\0")!=0);
 	if(!strcmp(program,"BDA")){
 		bda_seats+=1;
 		total_seats=bda_seats+ml_seats+es_seats;
	 }
	 else if(!strcmp(program,"ML")){
	 	ml_seats+=1;
	 	total_seats=bda_seats+ml_seats+es_seats;
	 }
	 else if(!strcmp(program,"ES")){
	 	es_seats+=1;
	 	total_seats=bda_seats+ml_seats+es_seats;
	 }
	 else{
	 	printf("PLEASE ENTER CORRECT PROGRAM NAME");
	 }

 }


 void display(Student *st){
 	int i;

 	for(i=1;i<=total_seats;i++){
 		printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n",st[i].name,st[i].regnumber,st[i].program,st[i].email,st[i].marks,st[i].status);
	 }
 }


 void waiting_students(Student *st){
 	int i;
 	for(i=1;i<=total_seats;i++){
 		if(!strcmp(st[i].status,"WAITING")){
 			if(!strcmp(st[i].program,"BDA") && bda_seats!=50){
 				strcpy(st[i].status,"ACCEPTED");}
 			else if(!strcmp(st[i].program,"ML") && ml_seats!=50){
 				strcpy(st[i].status,"ACCEPTED");
			 }
			else if(!strcmp(st[i].program,"ES") && es_seats!=50){
 				strcpy(st[i].status,"ACCEPTED");
 			}
 			else{
 				strcpy(st[i].status,"REJECTED");
			 }
	 }

 	}
}
