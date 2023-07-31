#include "Billing.h"

void ClientBillingFun(mirafraEmployeeSystem_t mirafraEmployeeVar)
{
	char clientName[128] = {0};
	
	if(mirafraEmployeeVar.employeeCnt == 0 || mirafraEmployeeVar.mirafraEmployee == NULL)
	{
		printf("employee database not found!!!!\n");
		return ;		
	}
	
	printf("enter the Client name: ");
	scanf(" %[^\n]",clientName);
	
	if(*clientName == '\0')
	{
		printf("invalid clientName!!!\n");
		return;
	}
	
	Employee_t* emp = NULL;
	EmployeeSystem_t* tNode = mirafraEmployeeVar.mirafraEmployee;
	uint64_t sum = 0;
	
	while(tNode)
	{
		emp = returnEmployeeType(&tNode->employeeInfo);
		
		if(!strcmp(emp->client_allocated,clientName))
		{
			sum += emp->client_billing_per_month;
		}
		
		tNode = tNode->next;
	}
	printf("%s Total billing is %llu", clientName,sum );
}


void employeeBillingFun(mirafraEmployeeSystem_t mirafraEmployeeVar)
{
	
	char employeeName[128] = {0};
	
	if(mirafraEmployeeVar.employeeCnt == 0 || mirafraEmployeeVar.mirafraEmployee == NULL)
	{
		printf("employee database not found!!!!\n");
		return ;		
	}
	
	printf("enter the Client name: ");
	scanf(" %[^\n]",employeeName);
	
	if(*employeeName == '\0')
	{
		printf("invalid clientName!!!\n");
		return;
	}
	
	Employee_t* emp = NULL;
	EmployeeSystem_t* tNode = mirafraEmployeeVar.mirafraEmployee;
	
	
	while(tNode)
	{
		emp = returnEmployeeType(&tNode->employeeInfo);
		
		if(!strcmp(emp->name,employeeName))
		{
			break;
		}
		
		tNode = tNode->next;
	}
	printf("%s Total CTC is %f", employeeName,emp->salary.ctc );
}


void employeeSalaryFun(mirafraEmployeeSystem_t mirafraEmployeeVar)
{
	if(mirafraEmployeeVar.employeeCnt == 0 || mirafraEmployeeVar.mirafraEmployee == NULL)
	{
		printf("employee database not found!!!!\n");
		return ;		
	}
	
	Employee_t* emp = NULL;
	EmployeeSystem_t* tNode = mirafraEmployeeVar.mirafraEmployee;
	float sum = 0;
	
	while(tNode)
	{
		emp = returnEmployeeType(&tNode->employeeInfo);
		sum += emp->salary.ctc;
		tNode = tNode->next;
	}
	printf("ALL Employee CTC is %f",sum );
}


void salaryAlertFun(mirafraEmployeeSystem_t mirafraEmployeeVar)
{
	
	if(mirafraEmployeeVar.employeeCnt == 0 || mirafraEmployeeVar.mirafraEmployee == NULL)
	{
		printf("employee database not found!!!!\n");
		return ;		
	}
	
	Employee_t* emp = NULL;
	EmployeeSystem_t* tNode = mirafraEmployeeVar.mirafraEmployee;
	uint8_t  check = 0;
	
	while(tNode)
	{
		emp = returnEmployeeType(&tNode->employeeInfo);

		if((emp->client_billing_per_month * 0.80f) <= emp->salary.ctc)
		{
			if(!check)
				printf("ALERT!!!\n");
			printf("Employee name (%s) has ctc %f while his client Billing is %d\n",emp->name,emp->salary.ctc,emp->client_billing_per_month);
			printf("-------------------------------------------------------------------------\n");
		
			check = 1;
		}
		
		tNode = tNode->next;
	}
	
	if(!check)
	{
		printf("No ALERT!!! \n");
	}
	return;
}


void consolidateReportFun(mirafraEmployeeSystem_t mirafraEmployeeVar)
{
	char clientName[128] = {0};
	
	if(mirafraEmployeeVar.employeeCnt == 0 || mirafraEmployeeVar.mirafraEmployee == NULL)
	{
		printf("employee database not found!!!!\n");
		return ;		
	}
	
	printf("enter the Client name: ");
	scanf(" %[^\n]",clientName);
	
	if(*clientName == '\0')
	{
		printf("invalid clientName!!!\n");
		return;
	}
	
	Employee_t* emp = NULL;
	EmployeeSystem_t* tNode = mirafraEmployeeVar.mirafraEmployee;
	uint64_t clientSum = 0;
	float empSum = 0;
	uint8_t check = 0;
	
	while(tNode)
	{
		emp = returnEmployeeType(&tNode->employeeInfo);
		
		if(!strcmp(emp->client_allocated,clientName))
		{
			if(!check)
				printf("Consolidate Report\n");
			clientSum += emp->client_billing_per_month;
			empSum += emp->salary.ctc;
			printf("Employee name (%s) has ctc %f for  client %s and client Billing is %d\n",emp->name,emp->salary.ctc,emp->client_allocated,emp->client_billing_per_month);
			printf("-------------------------------------------------------------------------\n");
			check = 1;
		}
		
		
		tNode = tNode->next;
	}
	if(check){
		printf("Total Employee salary : %f \n", empSum);
		printf("Total client billing : %d \n", clientSum);
	}
	else{
		printf("No emp assign to %s client!!!\n",clientName);
	}
	return;
}







