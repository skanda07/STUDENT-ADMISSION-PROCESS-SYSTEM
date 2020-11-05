#include <stdint.h>
#include "appconstant.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

	static int8_t bda_seats=0;
	static int8_t ml_seats=0;
	static int8_t es_seats=0;
	static int8_t total_seats=0;

struct _student_{
	char name[STUDENT_NAME_LEN];
	int32_t regnumber;
	char program[PROGRAM_NAME_LEN];
	char email[STUDENT_EMAIL_LEN];
	int32_t marks;
	char status[STATUS_LEN];
};
typedef struct _student_ Student;

struct _program_{
	int8_t big_data_seats;
	int8_t machine_learning_seats;
	int8_t embedded_system_seats;

};
typedef struct _program_ Program;


Program program_seats();
Student student_new(char name[],int32_t reg, char prg[], char email[]);
int8_t check_status(int32_t marks);
void update_seats(char *program);
void student_reg(Student *st);
void display(Student *st);
void fill_seats(Program pg);
void display_seats(Program pg);
void display_total_filled_seats();
void manage_seats();
void waiting_student(Student *st);

#endif
