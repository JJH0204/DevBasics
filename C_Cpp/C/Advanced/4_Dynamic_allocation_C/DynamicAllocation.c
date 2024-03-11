//DynamicAllocation.c
#include <stdio.h>
#include <stdlib.h> // must include

/*structures*/
typedef struct {
    char * name;
    int age;
} person;

void printDynamicAlloc(person * p);

/*EX1*/
void Ex_Fun(void)
{
    /*How to Use Dynamic Allocation*/
    person * person_1 = (person *)malloc(sizeof(person));
    /*
    malloc() returns a "void pointer". So, Set the data type "person *"
    sizeof is not an actual function, because the compiler interprets it and translates it to the actual memory size of the person struct.
    */
   printDynamicAlloc(person_1);


   /*To access the person's members, we can use the "->"*/
   person_1->name = "Jaeho";
   person_1->age = 27;

   printDynamicAlloc(person_1);

   /*After we are done using the dynamically allocated struct, we can release it using "free"*/
   free(person_1);

   printDynamicAlloc(person_1);
}

/*check fun*/
void printDynamicAlloc(person * p)
{
    if (p == NULL)
    {
        printf("Memory is Clean~\n");
        return;
    }

    printf("person name: %s, age: %d\n",p->name,p->age);
}

/*Exercise*/
typedef struct {
  int x;
  int y;
} point;

int main(void)
{
    // Ex_Fun();

    point * mypoint = NULL;

    /* Dynamically allocate a new point
    struct which mypoint points to here */
    mypoint = (point*)malloc(sizeof(point));

    mypoint->x = 10;
    mypoint->y =5 ;
    printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);

    free(mypoint);

    return 0;
}