#include "free.h"

void freeAllObject(EmployeeSystem_t** mirafraEmployee)
{
	EmployeeSystem_t* temp;
	EmployeeSystem_t* onode = *mirafraEmployee;
	while(*mirafraEmployee)
	{
		temp = *mirafraEmployee;
		(*mirafraEmployee) = (*mirafraEmployee)->next;
		free(temp);
	}
	onode = NULL;
}







