#include <stdio.h>
#include <stdlib.h>

//This will group a the variables together so they can be easily called upon for a given name creating a binary tree structure.
struct namenode
{
    struct namenode *right_child, *left_child; // This creates a left and right child by grouping the namenode with the pointer that point us to the left_child and right_child variable.
    char *name; //This point to name variable which contains character.
    int phone; //This stores the phone number
    char *address; //This points to the address variable which contains characters.
};

struct namenode* new_name_node(char *new_name, int new_phone_number, char *new_address)
{
  struct namenode *new;
  int memory_size = sizeof(struct namenode); //This calculates the size of the struct nodename.
  new = malloc(memory_size); //This allocates a block of memory for the struct namenode variables.
  new -> name = new_name; //This allows us to access amember of the namenode structure and change the value.
  new -> phone = new_phone_number; //This allows us to access amember of the namenode structure and change the value.
  new -> address = new_address; //This allows us to access amember of the namenode structure and change the value.
  new -> left_child =  new -> right_child = NULL; //This initiates the left and right child of the new node to null.
  return new;
}

//This function add_contact_names new contacts into the phonebook, such as name, phone number, and address.
struct namenode* add_contact_name(struct namenode *root, char *new_name, int new_phone_number, char *new_address)
{
    if(root == NULL) //This checks to see if the node is empty.
    {
    //  printf("1\n");
      struct namenode *new;
      int memory_size = sizeof(struct namenode); //This calculates the size of the struct nodename.
      new = malloc(memory_size); //This allocates a block of memory for the struct namenode variables.
      new -> name = new_name; //This allows us to access amember of the namenode structure and change the value.
      new -> phone = new_phone_number; //This allows us to access amember of the namenode structure and change the value.
      new -> address = new_address; //This allows us to access amember of the namenode structure and change the value.
      new -> left_child =  new -> right_child = NULL; //This initiates the left and right child of the new node to null.
      //printf("%s has been added to your phonebook\n", new_name);//////////////////////////
      return new;

    }

    else if((*new_name - *root->name) > 0) //This checks if the new name is alphabetically greater than the root node.
    {
      root -> right_child = add_contact_name(root -> right_child, new_name, new_phone_number, new_address); //This enables us to recursively search the left child of a given node so we can find a alphabetically ordered position on the binary tree that we can place our new node.
    }
    else if((*new_name - *root->name) <= 0) //This checks if the new name is alphabetically less than the root node.
    {
      root -> left_child = add_contact_name(root -> left_child, new_name, new_phone_number, new_address); //This enables us to recursively search the left child of a given node so we can find a alphabetically ordered position on the binary tree that we can place our new node.
    }
    return root;
}

//This searches through our binary tree to retrieve the desired contact details, which are name and phone number.
struct namenode* name_search(struct namenode *root, char * contact_name)
{
    if(root == NULL) //This checks if the desired contact was not found in the phonebook.
    {
      printf("%s's number could not be found.\n", contact_name); //Output message to user.
      return NULL; //This ends the name_search.
    }

    if (root -> name == contact_name) //This checks if the name in the current node is equal to the desired contact name.
    {
      printf("%s's number is %d\n", root -> name, root -> phone); //Output message to user.
      return NULL; //This ends the name_search.
    }


    else if((*contact_name - *root -> name) > 0) // This checks if the name is alphabetically greater than the name in the current node of the binary tree.
    {
      return name_search(root -> right_child, contact_name); //This recursively name_searches the right children of a parent node.
    }

    else if((*contact_name - *root -> name) <= 0)//This checks if the name is alphabetically less than or equalto the name in the current node of the binary tree.
    {
      return name_search(root -> left_child, contact_name); ////This recursively searches the left children of a parent node.
    }

}

//This is a function to delete a node from the binary tree.
struct namenode* delete_name(struct namenode *root, char *contact_name)
{
    //This recursively searches through the binary tree untill it finds the desired node then it check if it has no children, one child, or two children attach to the node we want to remove.
    if(root == NULL)
    {
      printf("%s is not in your phonebook\n", contact_name);
      return NULL;
    }

    if ((*contact_name - *root -> name) > 0)
    {
      root -> right_child = delete_name(root->right_child, contact_name);
    }

    else if((*contact_name - *root->name) < 0)
    {
      root->left_child = delete_name(root -> left_child, contact_name);
    }

    else
    {
        //If the there is no right or left child then the node has no children.
        if(root -> left_child==NULL && root -> right_child == NULL)
        {
            free(root);
            return NULL;
        }

        //If the node has a child then we execute the code here.
        else if(root -> left_child == NULL || root -> right_child == NULL)
        {
            struct namenode *reconnect_node;
            if(root -> left_child == NULL) //If the left is null then the child is on the right.
            {
                reconnect_node = root -> right_child; //connects the child node to the current tree to remove the desired node.
            }

            else if(root -> right_child == NULL) // If the right is null then the child is on the right.
            {
                reconnect_node = root -> left_child; //connects the child node to the current tree to remove the desired node.
            }
            free(root); //Frees the node
            return reconnect_node;
        }

        //If the child has two nodes attached execute this code.
        else if(root -> left_child != NULL && root -> right_child != NULL)
        {
            struct namenode *minimum_node = root -> right_child;
            while(minimum_node && minimum_node -> left_child != NULL) // This finds the most left node in the binary tree
            {
              minimum_node = minimum_node -> left_child;
            }

            root -> name = minimum_node -> name; //connects the child node to the current tree to remove the desired node.
            root -> right_child = delete_name(root -> right_child, minimum_node -> name);
        }
    }
    return root;
}

/////////////////////////////   Number Node Implementation ////////////////////////////

//This will group a the variables together so they can be easily called upon for a given name creating a binary tree structure.
struct numbernode
{
    struct numbernode *right_child, *left_child;
    int phone;
    char * name;
    char * address;
};


struct numbernode* new_numbernode(int new_phone_number, char * new_name, char * new_address)
{
    struct numbernode *new;
    int memory_size = sizeof(struct numbernode);//This calculates the size of the struct nodename.
    new = malloc(memory_size); //This allocates a block of memory.

    //This allows us to access a member of the namenode structure and change or call the value.
    new -> phone = new_phone_number;
    new -> name = new_name;
    new -> address = new_address;
    new -> left_child = new -> right_child = NULL;

    return new;
}

struct numbernode* add_contact_number(struct numbernode *numberroot, int new_phone_number, char * new_name, char * new_address)
{

    if(numberroot==NULL)
    {
      struct numbernode *new;
      int memory_size = sizeof(struct numbernode); //This calculates the size of the struct nodename.
      new = malloc(memory_size); //This allocates a block of memory.

      //This allows us to access a member of the namenode structure and change or call the value.
      new -> phone = new_phone_number;
      new -> name = new_name;
      new -> address = new_address;
      new -> left_child = new -> right_child = NULL;

      return new;

    }

    else if((new_phone_number > numberroot -> phone)) // new_phone_number is greater
    {
      numberroot -> right_child = add_contact_number(numberroot -> right_child, new_phone_number, new_name, new_address); //recursively searching right through the bnary tree.
    }

    else if(new_phone_number <= numberroot -> phone)// new_phone_number is smaller
    {
      numberroot -> left_child = add_contact_number(numberroot -> left_child, new_phone_number, new_name, new_address); //recursively searching left through the bnary tree.
    }
    return numberroot;
}


struct numbernode* number_search(struct numbernode *numberroot, int contact_number)
{
    if(numberroot == NULL)
    {
      printf("%d's number could not be found.\n", contact_number); //Output message to user.
      return NULL; //This ends the name_search.
    }

    if(numberroot -> phone == contact_number) //if numberroot->phone is contact_number then the element is found
    {
      printf("Name    Address\n");
      printf("%s - %s\n\n", numberroot->name, numberroot->address);
      return NULL;
    }

    else if(contact_number > numberroot -> phone) //if greater move to the righ child.
    {
      return number_search(numberroot -> right_child, contact_number); //recursively seach right.
    }

    else if(contact_number <= numberroot -> phone)//if smaller move to the left chiild
    {
      return number_search(numberroot->left_child,contact_number); //recursively search left.
    }
}


// Thsi deletes the phone numbers from the binary tree.
struct numbernode* delete_number(struct numbernode *numberroot, int contact_number)
{

    //Searches for the desired number then checks for the number of children the node has, if it has any.
    if(numberroot==NULL) //if there is nothing in the tree return statement.
    {
      printf("%d is not in your phonebook\n", contact_number);
      return NULL;
    }

    if (contact_number > numberroot -> phone) //if the phone greater.
    {
      numberroot -> right_child = delete_number(numberroot -> right_child, contact_number); //Recursively search right.
    }

    else if(contact_number < numberroot -> phone) //if the phone is less.
    {
      numberroot -> left_child = delete_number(numberroot -> left_child, contact_number); // Recursively search left.
    }

    else
    {

        //If there are no left and right child.
        if(numberroot -> left_child == NULL && numberroot -> right_child == NULL)
        {
            free(numberroot); //Free node from memory.
            return NULL;
        }

        //=If there is only one child node to the parent node.
        else if(numberroot -> left_child == NULL || numberroot -> right_child == NULL)
        {
            struct numbernode *reconnect_node;
            if(numberroot->left_child==NULL) //Child is right.
            {
              reconnect_node = numberroot->right_child; //Attaches the node to the current tree.
            }

            else if(numberroot -> right_child == NULL) //Child is left.
            {
              reconnect_node = numberroot->left_child; //Attaches the node to the current tree.
            }

            free(numberroot); //Frees the node from memory.
            return reconnect_node;
        }

        //If there are two children attached to the parent node.
        else if(numberroot -> left_child != NULL && numberroot -> right_child != NULL)
        {
            struct numbernode *minimum_node = numberroot -> right_child;
            while(minimum_node && minimum_node -> left_child != NULL) // This finds the most left node.
            {
              minimum_node = minimum_node -> left_child;
            }

            numberroot->phone = minimum_node->phone; //connects the child node to the current tree to remove the desired node.
            numberroot->right_child = delete_number(numberroot->right_child, minimum_node->phone);
        }
    }
    return numberroot;
}



////////////////////////////////////////////////////////////////////////////////

int main()
{

  struct numbernode *numberroot;
  struct namenode *root;
  numberroot = new_numbernode(555, "M---", "---"); //Ensure equal distribution
  root = new_name_node("M---", 555, "---"); //Ensures equal distribution

  //Person 1 - Added to contacts
  add_contact_number(numberroot, 432, "Kevin", "Street");
  add_contact_name(root, "Kevin", 432, "Street");

  //Person 2 - Added to contacts
  add_contact_number(numberroot, 4, "Zoe", "Street");
  add_contact_name(root, "Zoe", 4, "Street");

  //Person 3 - Added to contacts
  add_contact_number(numberroot, 1234567, "John", "Street");
  add_contact_name(root, "John", 1234567, "Street");

  //Person 4 - Added to contacts
  add_contact_number(numberroot, 9087, "Charles", "Street");
  add_contact_name(root, "Charles", 9087, "Street");

  //Person 5 - Added to contacts
  add_contact_number(numberroot, 352345, "Sean", "Street");
  add_contact_name(root, "Sean", 352345, "Street");

  //Searches for contact name and address by number.
  number_search(numberroot, 432);
  number_search(numberroot, 4);
  number_search(numberroot, 352345);
  number_search(numberroot, 1234567);



  //Searches for the contacts phone number by name.
  name_search(root, "Kevin");
  name_search(root, "John");
  name_search(root,"Sean");

  //Deletes name from phonebook.
  root = delete_name(root, "Jonny");
  root = delete_name(root, "Charles");
  root = delete_name(root, "Kevin");

  //Deletes phone number from phonebook.
  numberroot = delete_number(numberroot,9087);
  numberroot = delete_number(numberroot,352345);
  numberroot = delete_number(numberroot,1234567);



  printf("\n");

  return 0;
}
