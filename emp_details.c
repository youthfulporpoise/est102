#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main() {
    size_t C_SIZE;
    printf("Address size: "); scanf("\n%zu", &C_SIZE);
    puts("");

    enum addr_type {WORK, HOME, TEMP};
    union addr {
        char *work_addr;
        char *home_addr;
        char *temp_addr;
    };

    struct details {
        char name[64];
        unsigned dob[3];
        enum addr_type addr_type;
        union addr addr;
        char state[2];
        unsigned pincode;
    } details;

    printf("Name: ");
    scanf("\n%63[^\n]", details.name);

    printf("DOB: ");
    scanf("\n%u-%u-%u",
        details.dob + 0, details.dob + 1, details.dob + 2);

    while (true) {
        printf("\t(0) Work\n"
               "\t(1) Home\n"
               "\t(2) Temporary\n"
               "Address type (0-2): ");
        scanf("%u", &details.addr_type);
        if (details.addr_type >= 0 && details.addr_type <= 2)
            break;
        else continue;
    }

    printf("Address: ");
    char address_type[10], *address;
    switch (details.addr_type) {
        case (WORK): 
            address = details.addr.work_addr;
            strcpy(address_type, "Work");
            break;
        case (HOME):
            address = details.addr.home_addr;
            strcpy(address_type, "Permament");
            break;
        case (TEMP):
            address = details.addr.temp_addr;
            strcpy(address_type, "Temporary");
            break;
    } 
    address = calloc(sizeof(char), C_SIZE);
    scanf("\n%[^\n]", address);

    printf("State (code): ");
    scanf("\n%2s", details.state);

    printf("Pincode: ");
    scanf("\n%6d", &details.pincode);

    /* Display details. */
    puts("");
    printf("%s (b. %02u-%02u-%04u)\n"
           "%s, %2s (%06d) (%s)\n",
           details.name,
           details.dob[0], details.dob[1], details.dob[2],
           address, details.state, details.pincode, address_type);

    free(address);
    return 0;
}
