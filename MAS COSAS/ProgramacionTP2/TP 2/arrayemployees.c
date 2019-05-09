#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayemployees.h"
#include "functions.h"
#define ELEMENTS 2000
#define IS_EMPTY_TRUE 1


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initEmployees(Employee* list, int len)
{
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            list[i].isEmpty=IS_EMPTY_TRUE;
        }
        return 0;
    }
    return -1;
}

