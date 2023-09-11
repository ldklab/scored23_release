int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* prev = *head; // dereference pointer to get the value of head
    node new = {.item_name = item_name, .price = price, .quantity=quantity };
    int cur = 1;
    if (*head == NULL) {*head = &new; return EXIT_SUCCESS;}
    while (prev != NULL && cur < pos){
        prev = prev->next;
        cur++;
    }
    
    if (prev != NULL && cur == pos) {
        prev->next = &new;
        new.next = prev;
        return EXIT_SUCCESS;
    }
    // pos > length or other
    return EXIT_FAILURE;
}