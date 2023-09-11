int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // pos must be an integer >= 1
    if (pos < 1) {
        return EXIT_FAILURE;
    }

    node* prev_ptr = NULL;
    node* next_ptr = *head; // node that will be pushed down 1 index (curr node at pos)

    int counter = 1;
    while(counter < pos && next_ptr != NULL) {
        prev_ptr = next_ptr;
        next_ptr = next_ptr->next;
        counter++;
    }

    // counter should be equal to pos by end of while loop
    // otherwise this means we've looped until end of list and 
    // pos exceeds list length
    if (counter != pos) {
        return EXIT_FAILURE;
    }
    

    // make new node
    node* new_item_ptr = malloc(sizeof(node));
    new_item_ptr->item_name = malloc(strlen(item_name) + 1);
    strcpy(new_item_ptr->item_name, item_name);
    new_item_ptr->price = price;
    new_item_ptr->quantity = quantity;
    new_item_ptr->next = next_ptr;

    // case: pos is not 1, hence prev_str != NULL
    if (pos != 1) {
        prev_ptr->next = new_item_ptr;
    } else {
        *head = new_item_ptr; // update head ptr if pos == 1
    }

    return EXIT_SUCCESS;
}