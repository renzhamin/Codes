/*Tasnim Ferdous IUT-CSE19(+_-)
		please do inform me if you find bugs */

#include <stdio.h>

struct city{
	char flat[20];
	char street[20];
	char City[20];
	char division[20];
	char postcode[8];
};

struct village{
	char district[20];
	char Village[20];
	char Union[20];
	char division[20];
	char postcode[8]; //taken as ch because of input problems with %d
};

union addr{
	struct city c;
	struct village v;
};

struct date{
	unsigned int day;
	unsigned int year;
	unsigned int month;
};

struct work_info{
	char occupation[20];
	char designation[20];
	char institution[20];
	struct date dateofjoining;
	struct date yearsofservice;
};

struct people{
	struct rel{
		char name[20];
		char relationtype[10];
		struct people *related;
	}relation[5];

	char name[20];
	struct date dateofbirth;
	union addr address;
	struct work_info occupation_info;
	int personal_number;
	int iscity;
	int numberOfrelations;

} citizen[1000];



