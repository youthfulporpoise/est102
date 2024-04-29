/*
 *  EMPLOYEE DATABASE
 *
 *  A program to read and print data of n employees (name, employee ID, and
 *  salary) using structures.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Number of employees: ");
    scanf("%d", &n);

    struct Employee {
        char name[64];
        int id;
        float salary;
    } empdb[n];

    for (int i = 0; i < n; ++i) {
        puts("");
        printf("Employee #%d\n", i + 1);
        printf("Name: "); scanf("%s", empdb[i].name);
        printf("ID: "); scanf("%d", &empdb[i].id);
        printf("Salary: "); scanf("%f", &empdb[i].salary);
    }

    puts("");
    for (int i = 0; i < n; ++i) {
        printf("%d: %s (₹%.2f)\n", empdb[i].id, empdb[i].name,
                                  empdb[i].salary);
    } puts("");

    return 0;
}
