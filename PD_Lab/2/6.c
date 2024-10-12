#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
    char name[100];
    char mobile_number[20];
    char arrival_time[10];
    struct data* next;
};
typedef struct data* Reservation;

Reservation CreateReservation(char name[], char mobile_number[], char arrival_time[]) {
    Reservation newReservation = (Reservation)malloc(sizeof(struct data));
    if (newReservation != NULL) {
        strcpy(newReservation->name, name);
        strcpy(newReservation->mobile_number, mobile_number);
        strcpy(newReservation->arrival_time, arrival_time);
        newReservation->next = NULL;
    }
    return newReservation;
}


void AddReservation(Reservation* head, char name[], char mobile_number[], char arrival_time[]) {
    Reservation newReservation = CreateReservation(name, mobile_number, arrival_time);
    if (newReservation == NULL) {
        printf("Error:Memory Allocation.\n");
        exit(1);
    }

    if (*head == NULL) {
        *head = newReservation;
    } else {
        Reservation temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newReservation;
    }
    printf("Reservation added successfully for %s\n", name);
}


void ViewNextBooking(Reservation head) {
    if (head == NULL) {
        printf("Reservation queue is empty.\n");
        return;
    }
    printf("Next Booking Request: %s (%s)\n",head->name, head->arrival_time);

}


void viewReservationQueue(Reservation head) {
    if (head == NULL) {
        printf("Reservations queue is empty.\n");
        return;
    }
    Reservation temp = head;

    while (temp != NULL){
        printf("%s (%s)\n", temp->name, temp->arrival_time);
        temp = temp->next;
    }
}


int CancelReservation(Reservation *head) {
    if (*head == NULL) {
        printf("Reservstion queue is empty.\n");
        return 1;
    }
    printf("Reservation to Cancel: ");
    char name[50];
    getchar();
    fgets(name, 50, stdin);
    Reservation temp = *head, prev;
    
    prev = temp;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Reservation not found.\n");
        
    }

    if(temp==prev){
        Reservation ptr;
        ptr = temp->next;
        *head = ptr;
    }
    if(temp->next == NULL){
        prev->next = NULL;
    }
    if(temp!=prev){
        Reservation ptr;
        ptr = temp->next;
        prev->next = ptr;
    }

    
    printf("Reservation for %s cancelled successfully.\n",name);
    
    free(temp);
    
    return 0;

}

int main() {
    Reservation head = NULL;
    int choice;
    char name[100];
    char mobile_number[20];
    char arrival_time[10];

    do {
        printf("Menu:\n"
               "1.Add Reservation\n"
               "2.View Next Booking Request\n"
               "3.Cancel Reservation\n"
               "4.Display Reservation Queue\n"
               "5.Exit\n");

        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                printf("Customer name: ");
                getchar();
                fgets(name, 100, stdin);
                printf("Mobile number: ");
                scanf("%s", mobile_number);
                printf("Arrival time: ");
                scanf("%s", arrival_time);
                AddReservation(&head, name, mobile_number, arrival_time);
                break;
            case 2:
                ViewNextBooking(head);
                break;
            case 3:
                CancelReservation(&head);
                break;
            case 4:
                viewReservationQueue(head);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    while (head != NULL) {
        Reservation temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}