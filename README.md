# Phonebook Application in C

## Overview

This repository contains a **Phonebook Application** implemented in C, leveraging binary search trees to store, search, and manage contact information efficiently. The application allows users to perform actions such as adding contacts, retrieving contact details by name or phone number, and deleting contacts from the phonebook.

## Features

1. **Add Contact**:
   - Stores contact details including name, phone number, and address.
   - Uses binary search trees for efficient organization and retrieval.

2. **Search by Name**:
   - Retrieves a contact's phone number using their name.

3. **Search by Phone Number**:
   - Retrieves a contact's name and address using their phone number.

4. **Delete Contact**:
   - Removes contacts from the phonebook based on either name or phone number.

5. **Binary Search Tree Implementation**:
   - Two separate binary search trees are used: one for names and one for phone numbers.

## Project Structure

- **NameNode**: Handles contact details indexed by name.
- **NumberNode**: Handles contact details indexed by phone number.
- **Main Functionality**:
  - Adding, searching, and deleting contacts.

## Prerequisites

- C Compiler (e.g., GCC)
- Basic understanding of binary search trees

## Compilation and Execution

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/kevincogan/Phonebook-C.git
   cd Phonebook-C
   ```

2. **Compile the Program**:
   ```bash
   gcc -o phonebook phonebook.c
   ```

3. **Run the Application**:
   ```bash
   ./phonebook
   ```

## Code Highlights

### Binary Search Tree for Names
- **Structure**: Each node contains:
  - `name` (pointer to a string)
  - `phone` (integer)
  - `address` (pointer to a string)
  - Pointers to left and right child nodes
- **Key Functions**:
  - `new_name_node`: Creates a new node.
  - `add_contact_name`: Adds a contact by name.
  - `name_search`: Searches for a contact by name.
  - `delete_name`: Deletes a contact by name.

### Binary Search Tree for Numbers
- **Structure**: Each node contains:
  - `phone` (integer)
  - `name` (pointer to a string)
  - `address` (pointer to a string)
  - Pointers to left and right child nodes
- **Key Functions**:
  - `new_numbernode`: Creates a new node.
  - `add_contact_number`: Adds a contact by phone number.
  - `number_search`: Searches for a contact by phone number.
  - `delete_number`: Deletes a contact by phone number.

### Sample Usage

#### Adding Contacts
The following code snippet adds contacts to the phonebook:
```c
add_contact_name(root, "Kevin", 432, "Street");
add_contact_number(numberroot, 432, "Kevin", "Street");
```

#### Searching Contacts
- **By Name**:
  ```c
  name_search(root, "Kevin");
  ```
- **By Phone Number**:
  ```c
  number_search(numberroot, 432);
  ```

#### Deleting Contacts
- **By Name**:
  ```c
  root = delete_name(root, "Kevin");
  ```
- **By Phone Number**:
  ```c
  numberroot = delete_number(numberroot, 432);
  ```

## Example Output

### Input
1. Add contacts:
   - Name: Kevin, Phone: 432, Address: Street
   - Name: John, Phone: 1234567, Address: Street
2. Search for Kevin's number:
   ```c
   name_search(root, "Kevin");
   ```
3. Search for contact details using phone number `432`:
   ```c
   number_search(numberroot, 432);
   ```
4. Delete Kevin from the phonebook:
   ```c
   root = delete_name(root, "Kevin");
   ```

### Output
```
Kevin's number is 432
Name    Address
Kevin - Street
Kevin has been removed from the phonebook.
```

## Notes

- The binary search tree ensures efficient storage and retrieval operations.
- The program includes robust error handling for cases where the contact does not exist.
- Memory allocation and deallocation are managed to prevent leaks.

## Contribution

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes and push them to your fork.
4. Open a pull request describing your changes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Experience efficient contact management with this C-based Phonebook Application!

