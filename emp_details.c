#include <stdio.h>
#include <stdbool.h>
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
    scanf("%63[^\n]", details.name);

    puts("");
    printf("DOB: ");
    scanf("%u-%u-%u",
        details.dob + 0, details.dob + 1, details.dob + 2);

    puts("");
    while (true) {
        printf("\t(0) Work\n"
               "\t(0) Home\n"
               "\t(0) Temporary\n"
               "Address type (0-2): ");
        scanf("%u", &details.addr_type);
        if (details.addr_type >= 0 && details.addr_type <= 2)
            break;
        else continue;
    }

    puts("");
    printf("Address: ");
    switch (details.addr_type) {
        case (WORK): 
            // details.addr.work_addr; 
            scanf("%[^\n]", details.addr.work_addr);
            break;
        case (HOME):
            // details.addr.home_addr = ""; 
            scanf("%[^\n]", details.addr.home_addr);
            break;
        case (TEMP):
            // details.addr.temp_addr = ""; 
            scanf("%[^\n]", details.addr.temp_addr);
            break;
    }

    puts("");
    printf("State (code): ");
    scanf("%2s", details.state);

    puts("");
    printf("Pincode: ");
    scanf("%6d", &details.pincode);

    return 0;
}
