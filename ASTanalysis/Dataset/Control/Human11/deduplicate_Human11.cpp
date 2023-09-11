int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    char *s[CURR_LEN];
    node *curr = *head;
    if(curr==NULL || curr->next==NULL) return EXIT_FAILURE;
    node *curr2 = *head;
    // curr = curr->next;
    int pointer =2;
    while(curr->next){
        int i=1;
        for(i=1;i<pointer;i++){
            if(strcmp(curr->next->c,curr2->c)==0){
                float updated_price=curr->next->price+curr2->price;
                int updated_q = curr->next->quantity+curr2->quantity;
                list_update_item_at_pos(head,curr2->c,updated_price,updated_q,i);
                list_remove_item_at_pos(head,pointer);
                break;
            }
            else {
                curr2=curr2->next;
            }
        }
        if(i==pointer){
            curr = curr->next;
        }
    }
    return EXIT_SUCCESS;

}