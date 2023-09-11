int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    node *curr = *head;
    while(curr != NULL){
        node *c2 = curr;
        while(c2->next != NULL){
            if(c2->next->item_name == curr->item_name && c2->next->price == curr->price){
                curr->quantity += c2->next->quantity;
                node *t = c2->next;
                c2->next = c2->next->next;
            }
            c2 = c2->next;
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}