#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[50];
    int age;
    float basicSalary;
    float bonus;
};

// bonus function for employee
float emp_bonus(int age, float basicSalary) {
	float bonusAmount; 
	
	if(age > 50){
		bonusAmount = basicSalary * 0.4;
	}
	else{
		bonusAmount = basicSalary * 0.25;
	}
	
	return bonusAmount;
}

// search function to find out the age
// of an Employee
void search_age(struct Employee e[]) {
	printf("\nsearch_age() function for searching age in file\n");
	
	//  Enter a name to search in file
	
	
	FILE *infile; 
    struct Employee employee; 
      
    // Open person.dat for reading 
    infile = fopen ("Employee_Data.txt", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    // read file contents till end of file 
    int i = 0;
    while(fread(&employee, sizeof(struct Employee), 1, infile)) {
        printf ("name = %s age = %d basic salary = %f bonus = %f\n", employee.name, 
        employee.age, employee.basicSalary, employee.bonus); 
        
        //printf ("name = %s age = %d basic salary = %f bonus = %f\n", e[i]->name, 
        //e[i]->age, e[i]->basicSalary, e[i]->bonus);
        
        i++;
  	}
  	
    // close file 
    fclose (infile);
}

// Main Function
// Program Starts here
int main()
{
	printf("\nSolution of Problem no 1\n");
	
	// Employee Number define and 
	// create structure for them
	int numberOfEmployee = 2;
    struct Employee emp[numberOfEmployee];
    
    printf("\n%d\n", numberOfEmployee);
    
    // Take all emplyee data input from user
    for(int i = 0; i < numberOfEmployee; i++)
    {
    	printf("\nEmployee no %d: \n", (i + 1));
    	printf("Enter Name: ");
    	scanf("%s", emp[i].name);
    	
    	printf("Enter Age: ");
    	scanf("%d", &emp[i].age);
    	
    	printf("Enter Basic Salary: ");
    	scanf("%f", &emp[i].basicSalary);
    	
    	// apply bonus function for employee
    	emp[i].bonus = emp_bonus(emp[i].age, emp[i].basicSalary);
    }
    
    // Print name and salary of
    // all emplyees
    for(int i = 0; i < numberOfEmployee; i++)
    {
    	printf("\nEmployee no %d: \t", (i + 1));
    	printf("Name: %s", emp[i].name);    	
    	
    	// calculate the total salary
    	float totalSalary;
    	totalSalary = emp[i].basicSalary + emp[i].bonus;
    	printf("\tTotal Salary: %f", totalSalary);   
    	    	
    }
    
    
   // create Employee_Data.txt file and 
   // store employee details(name and age)
   FILE *outfile;

   // create a file for writing 
   outfile = fopen("Employee_Data.txt","w"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
  
  	for(int i = 0; i < numberOfEmployee; i++)
    {
    	struct Employee employee = {*emp[i].name, emp[i].age, emp[i].basicSalary, emp[i].bonus};

/*
      	char* empName = emp[i].name;
      	char* empAge = emp[i].age;
      	char* empBasicSalary = emp[i].basicSalary;
      	char* empBonus = emp[i].bonus;
      	
      	struct Employee employee = {empName, empAge, empBasicSalary, empBonus};
*/
      	
		// write struct to file 
		fwrite (&employee, sizeof(struct Employee), 1, outfile); 
		  
		if(fwrite != 0)  
			printf("\nEmployee %d contents to file written successfully !\n", (i + 1)); 
		else 
			printf("\nerror writing file !\n");					
    }
  
    // close file 
    fclose (outfile); 
    
    // applying search_age function
    // on Employee_Data.txt file
    search_age(emp);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
