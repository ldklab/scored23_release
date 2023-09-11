int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node* current = *head;
    int current_pos = 1;
    while(current_pos < pos){
        current = current->next;
        if(current == NULL)
            return EXIT_FAILURE;
        current_pos++;
    }

    current->item_name = item_name;
    current->price = price;
    current->quantity = quantity;
    return EXIT_SUCCESS;
}
