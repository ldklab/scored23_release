int list_swap_item_positions(node **head, int pos1, int pos2) {
    node* current = *head;
    int current_pos = 1;
    while(current_pos < pos1){
        current = current->next;
        current_pos++;
    }

    char* temp_item_name = current->item_name;
    float temp_price = current->price;
    int temp_quantity = current->quantity;

    current_pos = 1;
    current = *head;
    while(current_pos < pos2){
        current= current->next;
        current_pos++;
    }

    node* node2 = current;

    int res = list_update_item_at_pos(head, node2->item_name, node2->price, node2->quantity, pos1);
    if(res == EXIT_FAILURE)
        return EXIT_FAILURE;
    res = list_update_item_at_pos(head, temp_item_name, temp_price, temp_quantity, pos2);
    if(res == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}