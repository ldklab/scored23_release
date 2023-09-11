int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    
    node *temp = *head;
    if(pos == 1){
        *head = temp->next;
    } else{
        for(int i=0; i<pos-1;i++){
            temp = temp->next;
        }
        node *del =temp->next;       
        temp->next=temp->next->next;
        del->next=NULL;
    }
    return EXIT_SUCCESS;
}