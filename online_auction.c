#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Auction Item
struct Item {
    int id;
    char name[50];
    float price;
    struct Item* next;
};

struct Item* head = NULL;

// 🔹 Create (Add Item)
void addItem() {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));

    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);

    printf("Enter Item Name: ");
    scanf("%s", newItem->name);

    printf("Enter Starting Price: ");
    scanf("%f", &newItem->price);

    newItem->next = head;
    head = newItem;

    printf("Item added successfully!\n");
}

// 🔹 Display Items (Read)
void displayItems() {
    struct Item* temp = head;

    if (temp == NULL) {
        printf("No items available!\n");
        return;
    }

    printf("\nAuction Items:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f\n",
               temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

// 🔹 Search Item
void searchItem() {
    int id;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    struct Item* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Item Found!\n");
            printf("ID: %d | Name: %s | Price: %.2f\n",
                   temp->id, temp->name, temp->price);
            return;
        }
        temp = temp->next;
    }

    printf("Item not found!\n");
}

// 🔹 Update Item
void updateItem() {
    int id;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    struct Item* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf("%s", temp->name);

            printf("Enter New Price: ");
            scanf("%f", &temp->price);

            printf("Item updated successfully!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Item not found!\n");
}

// 🔹 Delete Item
void deleteItem() {
    int id;
    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    struct Item *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Item deleted successfully!\n");
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

    printf("Item deleted successfully!\n");
}

// 🔹 Main Menu
int main() {
    int choice;

    do {
        printf("\n===== Online Auction Platform =====\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Update Item\n");
        printf("4. Search Item\n");
        printf("5. Display Items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: deleteItem(); break;
            case 3: updateItem(); break;
            case 4: searchItem(); break;
            case 5: displayItems(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}