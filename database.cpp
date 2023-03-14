#include <iostream>
#include <cstring> //I included this library because I am going to use strstr and strcmp later on

//created the struct. I used arrays of characters because I find it easier to check if a string is there (using strstr)
struct employee{
    char name[50];
    char depart[30];
    float salary;
}employees[100];

int n = 0;

void add();
void display();
void search();
void department();

int main() {
    int option;

    std::cout <<"Welcome to this mini data-base!\n";

    for(;;){
        std::cout<<"\n\tPress 1 to add an employee.\n";
        std::cout << "\tPress 2 to display the employees.\n";
        std::cout<<"\tPress 3 to search for a specific employee.\n";
        std::cout<<"\tPress 4 to display the employees that work on a specific department.\n";
        std::cout <<"\tPress 5 to exit the program.\n";
        std::cout<<"\toption: ";
        std::cin>>option;

        switch (option) {
            case 1: add();
                break;
            case 2: display();
                break;
            case 3: search();
                break;
            case 4: department();
                break;
            case 5: exit(0);
                break;
            default: std::cout << "Invalid option! Please enter on of the valid option!";
        }
    }

    return 0;
}

//function to add an element in the "data-base"
void add(){
    std::cin.ignore(256, '\n');
    std::cout << "\nPlease enter the employee's name: ";
    std::cin.getline(employees[n].name, 50);
    std::cout << "Please enter the department where the employee is working: ";
    std::cin.getline(employees[n].depart, 30);
    std::cout<<"Please enter the employee's salary: ";
    std::cin>>employees[n].salary;
    n++;
}

//function to display the elements from the "data-base"
void display(){
    std::cout << "\nThe employees: ";

    for (int i=0; i<n; i++)
        std::cout <<"\n\t"<<employees[i].name<<" "<<employees[i].depart<< " "<<employees[i].salary<<"\n";

}

/*function to search for an element in the "data-base". I created another array of chars to get the info from the user; 
I created a variable "found" in order to have a signal if the string was found or not;*/
void search(){
    char searched[50];
    int found = 0;

    std::cin.ignore(256, '\n');
    std::cout<<"\nEnter the name of the employee that you are looking for: ";
    std::cin.getline(searched, 50);
    std::cout<<"The employee: \n";

    for (int i=0; i<n; i++){
        if(strstr(employees[i].name, searched)){
            std::cout << "\t"<<employees[i].name<< " "<<employees[i].depart<<" "<<employees[i].salary<<"\n";
            found=1;
        }
    }
    if (found == 0)
        std::cout<<"The employee was not found!\n";
}

//function to display the the elements that have a specific component. same as in the search function;
void department(){
    char dprt[30];
    int result=0;

    std::cin.ignore(256, '\n');
    std::cout<<"\nDepartment: ";
    std::cin.getline(dprt, 30);
    std::cout<<"Employees working on this department: ";

    for (int i=0; i<n; i++){
        if (!strcmp(employees[i].depart, dprt)){
            std::cout << "\n\t"<<employees[i].name<<"\n";
            result=1;
        }
    }
    if (result == 0)
        std::cout<< "There are no employees working on this department!";

}