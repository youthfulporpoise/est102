#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define C_SIZE 128

int main() {

    enum addr_type {WORK, HOME, TEMP};
    union addr {
        char work_addr[C_SIZE];
        char home_addr[C_SIZE];
        char temp_addr[C_SIZE];
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
    scanf("%u-%u-%u",
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
            scanf("\n%[^\n]", details.addr.work_addr);
            address = details.addr.work_addr;
            strcpy(address_type, "Work");
            break;
        case (HOME):
            scanf("\n%[^\n]", details.addr.home_addr);
            address = details.addr.home_addr;
            strcpy(address_type, "Permament");
            break;
        case (TEMP):
            scanf("\n%[^\n]", details.addr.temp_addr);
            address = details.addr.temp_addr;
            strcpy(address_type, "Temporary");
            break;
    }

    printf("State (code): ");
    scanf("%2s", details.state);

    printf("Pincode: ");
    scanf("%6d", &details.pincode);

    /* Display details. */
    puts("");
    printf("%s (b. %u-%u-%u)\n"
           "%s, %2s (%06d) (%s)\n",
           details.name,
           details.dob[0], details.dob[1], details.dob[2],
           address, details.state, details.pincode, address_type);

    return 0;
}
