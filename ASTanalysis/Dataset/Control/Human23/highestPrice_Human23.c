int list_find_highest_price_item_position(node *head, int *pos) 
{
    node* current = head;
    float max_price = head->price;
    int current_pos = 1;
    *pos = 1;
    while(current != NULL){
        if(current->price > max_price){
            *pos = current_pos;
        }
        current_pos ++;
        current = current->next;
    }
    return EXIT_SUCCESS;
}