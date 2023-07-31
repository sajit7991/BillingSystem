#include "addEmployee.h"

	char name[64];
	uint8_t dob[16];
	uint8_t gender;
	char address[128];
	salary_t salary;
	char client_allocated[32];
	uint32_t client_billing_per_month; 

	float basic;
	float hra;
	float sa;
	float bonus;
	float ctc;


salary_t getSalary()
{
	salary_t salary;
	
	printf(" basic: ");
	scanf("%f",&salary.basic);
	printf(" hra: ");
	scanf("%f",&salary.hra);
	printf(" sa: ");
	scanf("%f",&salary.sa);
	printf(" bonus: ");
	scanf("%f",&salary.bonus);
	
	salary.ctc = salary.basic + salary.hra + salary.sa + salary.bonus;
	
	return salary;
}

employeeInfo_t getEmployeeDetails()
{
	employeeInfo_t empInfo;
	Employee_t emp;
	char M_F;
	
	printf("Enter name of employee: ");
	scanf(" %[^\n]",emp.name);	
	
	printf("Enter DOB of employee(YYYY-MM-DD): ");
	scanf(" %[^\n]",emp.dob);
	
	printf("Enter Gender of employee(M/F): ");
	scanf(" %c",&M_F);
	
	printf("Enter addess of employee: ");
	scanf(" %[^\n]",emp.address);
	
	printf("enter salary details: \n");
	emp.salary = getSalary();
	
	printf("Enter client Allocated of employee: ");
	scanf(" %[^\n]",emp.client_allocated);
	
	printf("Enter client billing per month of employee: ");
	scanf("%f",&emp.client_billing_per_month);
	
	printf("enter type of Employee{Permanent(1) Contractual(2) ShortTerm(3)}: ");
	scanf("%d",&empInfo.typeEmp);
	
	if(M_F == 'M' || M_F == 'm')
		emp.gender = MALE;
	else if(M_F == 'F' || M_F == 'f')
		emp.gender = FEMALE;
	else
		emp.gender = ORTHER;
	
	if(empInfo.typeEmp == ShortTerm)
	{
		printf("Enter end date of assignment of employee(YYYY-MM-DD): ");
		scanf(" %[^\n]",empInfo.employeeType.shortTermEmployee.end_date_of_assignment);
		
		empInfo.employeeType.shortTermEmployee.employee = emp;
	}
	else if(empInfo.typeEmp == Contractual)
	{
		empInfo.employeeType.contractualEmployee.employee = emp;
	}
	else
	{
		empInfo.employeeType.permanentEmployee.employee = emp;
	}
	
	return empInfo;
} 




