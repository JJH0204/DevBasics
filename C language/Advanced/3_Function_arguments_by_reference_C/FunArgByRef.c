//Function arguments by reference.c
#include <stdio.h>

/*EX1
void addone(int n) {
    // n is local variable which only exists within the function scope
    n++; // therefore incrementing it has no effect
}

int n;
printf("Before: %d\n", n);
addone(n);
printf("After: %d\n", n);
*/

/*EX2
void addone(int *n) {
    // n is a pointer here which point to a memory-adress outside the function scope
    (*n)++; // this will effectively increment the value of n
}

int n;
printf("Before: %d\n", n);
addone(&n);
printf("After: %d\n", n);
*/

/*EX3
void move(point * p) {
    (*p).x++;   // p->x++;
    (*p).y++;   // p->y++;
}
*/

/*Exercis*/
typedef struct {
  char * name;
  int age;
} person;

/* function declaration */
void birthday(person * p);

/* write your function here */
void birthday(person * p)
{
    p -> age++;
}

int main() {
  person john;
  john.name = "John";
  john.age = 27;

  printf("%s is %d years old.\n", john.name, john.age);
  birthday(&john);
  printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

  return 0;
}