#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Auction Item
struct Item {
    int id;
    char name[50];
    float basePrice;
    float highestBid;
    char highestBidder[50];
    struct Item *next;
};

struct Item *head = NULL;

// Add Item
void addItem() {
    struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));

    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);

    printf("Enter Item Name: ");
    scanf("%s", newItem->name);

    printf("Enter Base Price: ");
    scanf("%f", &newItem->basePrice);

    newItem->highestBid = newItem->basePrice;
    strcpy(newItem->highestBidder, "No Bid");

    newItem->next = head;
    head = newItem;

    printf("Item added successfully!\n");
}

// Display Items
void displayItems() {
    struct Item *temp = head;

    if (temp == NULL) {
        printf("No auction items available!\n");
        return;
    }

    printf("\n===== Auction Items =====\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Base Price: %.2f | Highest Bid: %.2f | Bidder: %s\n",
               temp->id, temp->name, temp->basePrice,
               temp->highestBid, temp->highestBidder);
        temp = temp->next;
    }
}

// Search Item
void searchItem() {
    int id;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    struct Item *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Item Found!\n");
            printf("ID: %d | Name: %s | Highest Bid: %.2f | Bidder: %s\n",
                   temp->id, temp->name,
                   temp->highestBid, temp->highestBidder);
            return;
        }
        temp = temp->next;
    }

    printf("Item not found!\n");
}

// Place Bid
void placeBid() {
    int id;
    float bid;
    char bidder[50];

    printf("Enter Item ID: ");
    scanf("%d", &id);

    struct Item *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Current Highest Bid: %.2f\n", temp->highestBid);
            printf("Enter Your Name: ");
            scanf("%s", bidder);

            printf("Enter Bid Amount: ");
            scanf("%f", &bid);

            if (bid > temp->highestBid) {
                temp->highestBid = bid;
                strcpy(temp->highestBidder, bidder);
                printf("Bid placed successfully!\n");
            } else {
                printf("Bid must be higher than current highest bid!\n");
            }
            return;
        }
        temp = temp->next;
    }

    printf("Item not found!\n");
}

// Delete Item
void deleteItem() {
    int id;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);

    struct Item *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Item removed successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Item removed successfully!\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n===== Offline Auction System =====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Place Bid\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: placeBid(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
