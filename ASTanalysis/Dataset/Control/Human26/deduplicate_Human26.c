int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    node* ptr = *head;
    int ptr_counter = 1;

    // loops through each item in list
    while (ptr != NULL) {
        node* dup_ptr = ptr->next; // checks for duplicates
        int dup_counter = ptr_counter + 1;

        // loops through rest of list starting with the node after ptr
        while(dup_ptr != NULL) {
            // update quantity if the two pointers have same item name
            if(strcmp(ptr->item_name, dup_ptr->item_name) == 0) {
                node* rem_ptr = dup_ptr;
                ptr->quantity += rem_ptr->quantity; // update quantity
                dup_ptr = dup_ptr->next; // move dup_ptr to next pointer

                // remove duplicate and check for error
                int status = list_remove_item_at_pos(head, dup_counter);
                if (status == EXIT_FAILURE) {
                    return EXIT_FAILURE;
                }
                continue;
            }

            dup_ptr = dup_ptr->next;
            dup_counter++;
        }

        ptr = ptr->next;
        ptr_counter++;
    }