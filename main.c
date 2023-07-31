#ifndef _SHAREDMAIN_
#define _SHAREDMAIN_

#include <stdio.h>
#include <stdlib.h>	
#include "shared_struct.h"

typedef enum options
{
	AddEmployee = 1,
	ClientBilling,
	employeeSalary,
	Consolidated,
	Individual,
	SalaryAlert,
	Exit,
	MAX_OPtions
}options_e;



Employee_t* returnEmployeeType(employeeInfo_t* employeeInfoPtr ,int employeeType)
{
	Employee_t* emp = NULL;
	switch(employeeType)
	{
		case Permanent: 
			emp = &employeeInfoPtr->employeeType.permanentEmployee.employee;
			break;
		case Contractual: 
			emp = &employeeInfoPtr->employeeType.contractualEmployee.employee;
			break;
		case ShortTerm: 
			emp = &employeeInfoPtr->employeeType.shortTermEmployee.employee;
			break;
	}
	return emp;
}




int main(int argc ,char** argv)
{
	int allTure =1;
	options_e opt;
	
	printf("Welcome to mirafra employee system \n");
	printf("kindly select the opt(1-7): \n");
	printf("%. Add Employee.\n",AddEmployee);
	printf("%. Calculate the billing to Client.\n",ClientBilling);
	printf("%. Calculate the salary of the employee.\n",employeeSalary);
	printf("%. Consolidated Report.\n",Consolidated);
	printf("%. Individual Report.\n",Individual);
	printf("%. check_salary_alert.\n",SalaryAlert);
	printf("%. Exit\n",Exit);
	
	do{
		scanf(" %d",&opt);
		if(!(opt>=AddEmployee && opt<MAX_OPtions))
		{
			printf("kindly select the valid opt(1-7): \n");
			continue;
		}
		
		switch(opt)
		{
			case AddEmployee:
					addEmployee(&mirafraEmployeeVar);
					break;
			case ClientBilling:
					break;
			case employeeSalary:
					break;
			case Consolidated:
					break;
			case Individual:
					break;
			case SalaryAlert:
					break;
			case Exit:
					printf("Bye, Have a nice day!!!");
					allTure = 0;
					break;
		}
		
	}while(allTure);
	
	
	freeAllObject(&mirafraEmployeeVar.mirafraEmployee);
	
	return 0 ; 
}

#endif