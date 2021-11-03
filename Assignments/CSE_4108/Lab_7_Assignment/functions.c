/*Tasnim Ferdous IUT-CSE19(+_-)
		please do inform me if you find bugs */

#define YEAR 2020
int i=0,choice=0;

void add(){
	printf("Enter information of citizen %d\n",i);
	printf("Enter name: ");
	scanf("%s",citizen[i].name);

	printf("Enter date of birth in dd/mm/yy format : ");
	scanf("%d/%d/%d",&citizen[i].dateofbirth.day,&citizen[i].dateofbirth.month,&citizen[i].dateofbirth.year);

	printf("Enter your Personal Number : ");
	scanf("%d",&citizen[i].personal_number);
	int c;
	printf("If from city enter 1 else 2 : "); scanf("%d",&c);

	if(c==1){
		citizen[i].iscity=1;
		printf("Enter division : "); scanf("%s",citizen[i].address.c.division);
		printf("Enter city : "); scanf("%s",citizen[i].address.c.City);
		printf("Enter postcode : "); scanf("%s",citizen[i].address.c.postcode);
		printf("Enter Street No: "); scanf("%s",citizen[i].address.c.street);
		printf("Enter Flat No: "); scanf("%s",citizen[i].address.c.flat);
	} else {
		citizen[i].iscity=0;
		printf("Enter division : "); scanf("%s",citizen[i].address.v.division);
		printf("Enter village : "); scanf("%s",citizen[i].address.v.Village);
		printf("Enter postcode : "); scanf("%s",citizen[i].address.v.postcode);
		printf("Enter district : "); scanf("%s",citizen[i].address.v.district);
		printf("Enter Union : "); scanf("%s",citizen[i].address.v.Union);
	}

	printf("Enter Occupation : "); scanf("%s",citizen[i].occupation_info.occupation);
	printf("Enter Designation : "); scanf("%s",citizen[i].occupation_info.designation);
	printf("Enter Institution : "); scanf("%s",citizen[i].occupation_info.institution);
	printf("Enter Date of Joining in dd/mm/yy format: "); 
	scanf("%d/%d/%d",&citizen[i].occupation_info.dateofjoining.day,&citizen[i].occupation_info.dateofjoining.month,&citizen[i].occupation_info.dateofjoining.year);
	citizen[i].occupation_info.yearsofservice.year=YEAR - citizen[i].occupation_info.dateofjoining.year;
	printf("Enter number of Relations (maximum 5) : "); scanf("%d",&citizen[i].numberOfrelations);
	int l=0;
	for(int j=0;j<citizen[i].numberOfrelations;j++){
		printf("Enter the index of the citizen related with : "); scanf("%d",&l);
		citizen[i].relation[j].related=&(citizen[l]);
		printf("Enter relation type : "); scanf("%s",citizen[i].relation[j].relationtype);
		printf("\n");
	}
	printf("\n");
	i++;
}

void show(int k){
	printf("---------------------------------------------\n");
	printf("Information of citizen no %d\n",k);
	printf("Name : %s\n",citizen[k].name);
	printf("Date of birth : %d/%d/%d\n",citizen[k].dateofbirth.day,citizen[k].dateofbirth.month,citizen[k].dateofbirth.year);

	for(int j=0;j<citizen[k].numberOfrelations;j++){
		printf("%s of %s ",citizen[k].relation[j].relationtype,citizen[k].relation[j].related->name);
		printf("\n");
	}

	printf("Personal Number : %d\n",citizen[k].personal_number);

	if(citizen[k].iscity){
		printf("Division : %s\n",citizen[k].address.c.division);
		printf("City : %s\n",citizen[k].address.c.City);
		printf("PostCode : %s\n",citizen[k].address.c.postcode);
		printf("Street No : %s\n",citizen[k].address.c.street);
		printf("Flat No : %s\n",citizen[k].address.c.flat);
	} else {
		printf("Division : %s\n",citizen[k].address.v.division);
		printf("Village : %s\n",citizen[k].address.v.Village);
		printf("PostCode : %s\n",citizen[k].address.v.postcode);
		printf("District : %s\n",citizen[k].address.v.district);
		printf("Union : %s\n",citizen[k].address.v.Union);

	}
	printf("Occupation : %s",citizen[k].occupation_info.occupation);
	printf("\nDesignation : %s",citizen[k].occupation_info.designation);
	printf("\nInstitution : %s",citizen[k].occupation_info.institution);
	printf("\nDate of Joining : %d/%d/%d",citizen[k].occupation_info.dateofjoining.day,citizen[k].occupation_info.dateofjoining.month,citizen[k].occupation_info.dateofjoining.year); 
	printf("\nYears of Service : %d years",citizen[k].occupation_info.yearsofservice.year);
	
	printf("\n---------------------------------------------\n\n");
}

void showAll(){
	printf("\n");
	for(int k=0;k<i;k++){
		show(k);
	}
}


void find(){
	int num;
	printf("Enter Personal Number : "); 
	scanf("%d",&num); 
	int j=0;
	for(j=0;j<i;j++){
		if(num==citizen[j].personal_number) break;
	}
	if(j<i) show(j);
	else printf("Person not found ! \n");
}

void menu(){
	printf("\n************************\n");
	printf("1.Add Entry\n2.Show Entries\n3.Find Entry\n4.Exit Program\nEnter Choice : ");
	scanf("%d",&choice);
	printf("\n************************\n\n");
}