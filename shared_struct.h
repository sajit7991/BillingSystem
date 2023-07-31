#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _SHAREDMAIN_
	#define Var 
#else
	#define Var extern
#endif


typedef enum employeeType
{
	Permanent = 1,
	Contractual,
	ShortTerm,
	MAX_TYPE
}options_e;

typedef enum gender
{
	FEMALE = 0,
	MALE = 1,
	ORTHER = 2
}gender_e;

typedef struct salary
{
	float basic;
	float hra;
	float sa;
	float bonus;
	float ctc;
}salary_t;

typedef struct employee
{
	char name[64];
	uint8_t dob[16];
	uint8_t gender;
	char address[128];
	salary_t salary;
	char client_allocated[32];
	uint32_t client_billing_per_month;
}Employee_t;

typedef struct PermanentEmployee
{
	Employee_t employee;
}permanentEmployee_t;

typedef struct ContractualEmployee
{
	Employee_t employee;
}contractualEmployee_t;

typedef struct ShortTermEmployee
{
	Employee_t employee;
	uint8_t end_date_of_assignment[16];
}shortTermEmployee_t;

typedef struct {
	
	typedef union {
		permanentEmployee_t		permanentEmployee;
		contractualEmployee_t 	contractualEmployee;
		shortTermEmployee_t		shortTermEmployee;
	}employeeType
	int employeeType;

}employeeInfo_t;

typedef struct EmployeeSystem
{
	struct EmployeeSystem *next;
	struct EmployeeSystem *prev;
	employeeInfo_t employeeInfo;
	
}EmployeeSystem_t;

typedef struct mirafraEmployeeSystem
{
	EmployeeSystem_t* mirafraEmployee;
	int employeeCnt;
}mirafraEmployeeSystem_t;

Var mirafraEmployeeSystem_t mirafraEmployeeVar
#ifdef _SHAREDMAIN_
	= {NULL,0}
#endif
;


Employee_t* returnEmployeeType(employeeInfo_t* employeeInfoPtr ,int employeeType);




