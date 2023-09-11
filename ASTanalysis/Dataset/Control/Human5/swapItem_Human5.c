int list_swap_item_positions(node **head, int pos1, int pos2) {
    if(pos1==pos2)
        return EXIT_SUCCESS;

    node *prev1 = NULL, *curr1 = *head;
    int i = 1;
    while(curr1 && i!=pos1) {
        prev1 = curr1;
        curr1 = curr1->next;
        i++;
    }
    node *prev2 = NULL, *curr2 = *head;
    i = 1;
    while(curr2 && i!=pos2) {
        prev2 = curr2;
        curr2 = curr2->next;
        i++;
    }
    if(curr1 == NULL || curr2 ==NULL) {
        return EXIT_SUCCESS;
    }
    if(prev1 != NULL) {
        prev1->next = curr2;
    }
    else{
        *head = curr2;}
    if(prev2 != NULL) {
        prev2->next = curr1;
    }
    else{
        *head = curr1;}
    node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
    

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}