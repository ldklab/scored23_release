int list_deduplicate(node **head) 
{
    node* current = *head;
    node* next;
    int pos1 = 1, pos2= 2;
    while(current != NULL && current->next != NULL){
        node* second_ptr = current->next;
        while(second_ptr != NULL ){
            if(current->item_name == second_ptr->item_name){
                int total_quantity = current->quantity + second_ptr->quantity;
                
            }
            pos2++;
        }
        pos1++;
    }
    return EXIT_FAILURE;
}