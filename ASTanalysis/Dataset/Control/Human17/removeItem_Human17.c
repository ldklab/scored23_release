int list_remove_item_at_pos(node **head, int pos)
{    
    int i=0;
    char* in="";
    float p=-1;
    int q=-1;
    node *current=*head;
    node *temp_node=NULL;
    if(pos==0){
        return pop(head);
    }
    for(i=0;i<pos-1;i++){
        if(current->next==NULL){
            return -1;
        }
        current=current->next;
    }
    if (current->next==NULL){
        return -1;
    }
    temp_node=current->next;
    in=temp_node->item_name;
    p=temp_node->price;
    q=temp_node->quantity;
    current->next=temp_node->next;
    free(temp_node);

    return EXIT_SUCCESS;
}