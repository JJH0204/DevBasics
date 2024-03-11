#include <stdio.h>
/*must include*/
#include <string.h>

void concept(void)
{
    /*Defining*/
    char *name = "Jung Jaeho";
    /*
    same as
    char name[] = "Jung Jaeho";
    char name[11] = "Jung Jaeho";
    */

    /*string formatting with printf*/
    int age = 27;
    printf("%s is %d years old.\n", name, age);

    /*string Length*/
    printf("%lu\n", strlen(name));

    /*string comparison*/
    if (strncmp(name, "Jung Jaeho", 10) == 0)
    {
        printf("Helle, Jaeho!\n");
    }
    else
    {
        printf("You are not Jaeho.\n");
    }

    /*String Concatenation*/
    char First_name[20] = "Jung";
    char Last_name[20] = "Jaeho";

    strncat(First_name, Last_name, 5);
    printf("%s\n", First_name);
    strncat(First_name, Last_name, 20);
    printf("%s\n", First_name);
}

void exercise(void)
{
    // Define the string first_name with the value John using the pointer notation, and define the string last_name with the value Doe using the local array notation.
    /* define first_name */
    char *first_name = "John";
    /* define last_name */
    char last_name[] = "Doe";
    char name[100];

    last_name[0] = 'B';
    sprintf(name, "%s %s", first_name, last_name);
    // printf("test: %s\n",name);
    if (strncmp(name, "John Boe", 100) == 0)
    {
        printf("Done!\n");
    }
    name[0] = '\0';
    strncat(name, first_name, 4);
    strncat(name, last_name, 20);
    printf("%s\n", name);
}

int main(void)
{
    concept();
    exercise();
    return 0;
}