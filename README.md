# Online-Auction-Platform-
🛒 Online Auction Platform (C Project)

##📌 Project Title

Online Auction Platform using C (Linked List Implementation)

##👨‍💻 Team Members

Member 1: T.upendera

Member 2: J.Hema Harshith

##❓ Problem Statement

The Online Auction Platform is a console-based application developed in C that allows users to manage auction items. Users can add products, update details, delete items, search for products, and display all available auction items.

The system simulates a basic auction environment using data structures and provides a menu-driven interface for easy interaction.


##🧠 Data Structure Used
Singly Linked List
Each node represents a product in the auction.
Dynamic memory allocation is used (malloc, free).
Efficient insertion and deletion operations.

##📦 Structure Example:

     
  
    struct Product {
    
       int id;
    
       char name[50];

       float price;

       struct Product* next;

    };



##⚙️ Algorithm Explanation

1. Add Product (Create)

Allocate memory using malloc

Input product details (ID, name, price)

Insert node at the end of the list


2. Display Products (Read)

Traverse the linked list from head

Print each product’s details


3. Update Product (Update)

Search product by ID

Modify its name or price


4. Delete Product (Delete)

Locate the node using ID

Adjust pointers to remove node

Free memory using free


5. Search Product

  Traverse list

  Compare IDs

  Display if found


##🛠️ Compilation Instructions
🔹 Using GCC Compiler:
       
        gcc auction.c -o auction
        ./auction

🔹 Requirements:

C Compiler (GCC recommended)

Any OS (Windows/Linux/Mac)



##📋 Sample Output
1.main menu

<img width="318" height="152" alt="21" src="https://github.com/user-attachments/assets/561e55ca-7177-4acc-9b2f-cf52c5007a3e" />

<img width="238" height="146" alt="21 1" src="https://github.com/user-attachments/assets/eba44588-a2e1-4e97-98aa-9b9ed1d9f115" />


2.add product

<img width="263" height="111" alt="22" src="https://github.com/user-attachments/assets/f4e3d0b6-c99c-4ced-9071-6ca4d311639e" />


3.delete product

<img width="256" height="68" alt="23" src="https://github.com/user-attachments/assets/656476e8-a211-4ea5-af47-dd4827b24d8f" />


4.update product

<img width="268" height="122" alt="24" src="https://github.com/user-attachments/assets/4d8bb196-4661-442c-91da-03d0d8cdb0c1" />


5.search product

<img width="338" height="97" alt="25" src="https://github.com/user-attachments/assets/2e9546d4-94e6-472f-8c7b-df526d1ea476" />


6.dispay product

<img width="365" height="93" alt="26" src="https://github.com/user-attachments/assets/bfb8986d-2ef4-4aae-a870-bded3da09967" />


7.exit

<img width="192" height="41" alt="27" src="https://github.com/user-attachments/assets/0d7998ce-c00b-4b40-a955-4e8e32ec46a7" />


🎥 Demo Video Link


🚀 Features
Menu-driven program
Dynamic memory management
Efficient CRUD operations
Easy to understand structure
