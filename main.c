#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//struct datatype to store the details of the student
struct student
{
    int id;
    char name[30];
    char course[30];
    long long int mobile;
    char email[30];
    char address[30];
}add;
//For delay
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//Function to add the details of the new student
void new_registration()
{
    system("cls");
    int id;
    FILE *ptr =NULL;
    ptr=fopen("student.dat","a+");
    printf("Enter the student unique ID: ");
    scanf("%d", &id);
    while(fscanf(ptr,"%d %s %s %lli %s %s",&add.id,add.name,add.course,&add.mobile,add.email,add.address) !=EOF)
    {
        if(add.id == id)
        {
            printf("Student with this ID already exist \n");
            printf("Take another ID Number\n");
            printf("Press enter to go to menu");
            getch();
            menu();
        }
    }
    add.id = id;
    printf("Enter the name of the student: ");
    scanf("%s",add.name);
    printf("Enter the course name: ");
    scanf("%s",add.course);
    printf("Enter the mobile: ");
    scanf("%lli",&add.mobile);
    printf("Enter the Email address: ");
    scanf("%s",add.email);
    printf("Enter the address: ");
    scanf("%s",add.address);
    fprintf(ptr,"%d %s %s %lli %s %s\n",add.id,add.name,add.course,add.mobile,add.email,add.address);
    fclose(ptr);
    printf("Press enter to go to menu");
    getch();
    menu();

}
//Update or edit the information of the student
void update()
{
    system("cls");
    int id;
    printf("Enter the ID of the student whose details you want to change: ");
    scanf("%d",&id);
    FILE *newrec;
    FILE *old;
    old = fopen("student.dat","r");
    newrec = fopen("new.dat","w");

    while(fscanf(old,"%d %s %s %lli %s %s",&add.id,add.name,add.course,&add.mobile,add.email,add.address) !=EOF)
    {
        if(add.id == id)
        {
            int choice;
            printf("What do you want to change\n");
            printf("1. Name\n");
            printf("2. Course\n");
            printf("3. Mobile\n");
            printf("4. Email\n");
            printf("5. Address\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                printf("Enter the new Name: ");
                scanf("%s", add.name);
                break;
            case 2:
                printf("Enter the changed course: ");
                scanf("%s", add.course);
                break;
            case 3:
                printf("Enter the new mobile number: ");
                scanf("%lli", &add.mobile);
                break;
            case 4:
                printf("Enter the new Email address: ");
                scanf("%s", add.email);
                break;
            case 5:
                printf("Enter the new address: ");
                scanf("%s", add.address);
                break;
            default:
                printf("Enter the correct choice");
                update();
            }
            fprintf(newrec,"%d %s %s %lli %s %s\n",add.id,add.name,add.course,add.mobile,add.email,add.address);
        }
        else
        {
            fprintf(newrec,"%d %s %s %lli %s %s\n",add.id,add.name,add.course,add.mobile,add.email,add.address);
        }
    }
    fclose(newrec);
    fclose(old);
    remove("student.dat");
    rename("new.dat","student.dat");
    printf("Press enter to go to menu");
    getch();
    menu();
}
//Check the details of a particular student
void check()
{
    system("cls");
    int id;
    FILE *ptr =NULL;
    ptr=fopen("student.dat","a+");
    printf("Enter the student unique ID: ");
    scanf("%d", &id);
    while(fscanf(ptr,"%d %s %s %lli %s %s",&add.id,add.name,add.course,&add.mobile,add.email,add.address) !=EOF)
    {
        if(add.id == id)
        {

            printf("\n\nDetail of the student with ID: %d \n", add.id);
            printf("Name : %s \n", add.name);
            printf("Course : %s \n", add.course);
            printf("Mobile : %lli \n", add.mobile);
            printf("Email : %s \n", add.email);
            printf("Address : %s \n\n", add.address);
            printf("Press enter to go to menu");
            getch();
            menu();
        }
    }
    fclose(ptr);
}
// See the list of all the student
void view_list()
{
    system("cls");
    FILE *ptr =NULL;
    ptr=fopen("student.dat","r");
    printf("ID \t Name \t\t Course \t Mobile\n ");
    while(fscanf(ptr,"%d %s %s %lli %s %s",&add.id,add.name,add.course,&add.mobile,add.email,add.address) !=EOF)
    {
        printf("%d \t %s \t %s \t\t %lli\n",add.id,add.name,add.course,add.mobile);
    }
    printf("Press enter to go to menu");
    fclose(ptr);
    getch();
    menu();
}
//Remove the details of the student from database
void erase()
{
    system("cls");
    int id;
    printf("Enter the ID of the student whose details you want to remove: ");
    scanf("%d",&id);
    FILE *newrec,*old;
    old = fopen("student.dat","r");
    newrec = fopen("new.dat","w");

    while(fscanf(old,"%d %s %s %lli %s %s",&add.id,add.name,add.course,&add.mobile,add.email,add.address) !=EOF)
    {
        if(add.id == id)
        {
            printf("Removed successfully ");
        }
        else
        {
            fprintf(newrec,"%d %s %s %lli %s %s\n",add.id,add.name,add.course,add.mobile,add.email,add.address);
        }
    }
    fclose(newrec);
    fclose(old);
    remove("student.dat");
    rename("new.dat","student.dat");
    printf("Press enter to go to menu");
    getch();
    menu();
}
//Menu function to choose the operation
void menu()
{

    int choice;
    system("cls");
    system("Color 3F");
    printf("UNIVERSITY STUDENT MANAGEMENT SYSTEM \n\n\n");
    printf("1. New Registration \n");
    printf("2. Update information \n");
    printf("3. Check the detail of existing student \n");
    printf("4. View student list \n");
    printf("5. Remove the student \n");
    printf("6. close \n");
    do
    {
        printf("Enter you choice:");
        scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        // Add the details of the new student
        new_registration();
        break;

    case 2:
        // Update or edit any information of the student
        update();
        break;
    case 3:
        // Check the detail of existing student
        check();
        break;
    case 4:
        // See the list of all the student
        view_list();
        break;
    case 5:
        //Remove the student from database
        erase();
        break;
    case 6:
        printf("End");
        exit(0);
        break;
    default:
        printf("Enter the right option");

    }

    }while(choice <= 6);

}
int main()
{
    char password[] = "code";
    char pass[30];
    while(1)
    {
        printf("Enter the password to login:");
        scanf("%s", pass);
        if(strcmpi(password, pass) == 0)
        {
            printf("\n\nPassword Match!\nLOADING");
            /*for(int i=0;i<=6;i++)
            {
                fordelay(100000000);
                printf(".");
            }*/
        menu();
        }
        else
        {
            printf("Enter the correct password\n");
            printf("Press enter to retry");
            getch();
            system("cls");
        }
    }
    return 0;
}
