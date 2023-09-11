int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // positions must be an integer >= 1
    if (pos1 < 1 || pos2 < 1) {
        return EXIT_FAILURE;
    }

    if (pos1 == pos2) {
        return EXIT_SUCCESS;
    }

    node* ptr1 = *head;
    node* ptr2 = *head;
    int counter = 1;

    // loop until both ptrs are set or reach end of list
    while(ptr1 != NULL && ptr2 != NULL && (counter < pos1 || counter < pos2)) {
        if (counter < pos1) {
            ptr1 = ptr1->next;
        }
        if (counter < pos2) {
            ptr2 = ptr2->next;
        }

        counter++;
    }

    // cannot swap with end of list (NULL)
    if (ptr1 == NULL || ptr2 == NULL) {
        return EXIT_FAILURE;
    }

    // swap attr
    char* temp_name = ptr1->item_name;
    float temp_price = ptr1->price;
    int temp_quantity = ptr1->quantity;

    ptr1->item_name = ptr2->item_name;
    ptr1->price = ptr2->price;
    ptr1->quantity = ptr2->quantity;

    ptr2->item_name = temp_name;
    ptr2->price = temp_price;
    ptr2->quantity = temp_quantity;


    return EXIT_SUCCESS;
}