int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{   node *temp = *head;
    node *newnode;
    newnode->item_name = item_name;
    newnode->price = price;
    newnode->quantity = quantity;
    // for(int i  = 1; i < pos ; i++){
    //     if(temp->next != NULL){
    //         temp = temp->next;
    //     }
    // }
    // if(pos == 1){
    //     temp->next = newnode;
    // }
    // else
    // {
    // newnode->next = temp->next;
    // temp->next = newnode;
    // }
    return EXIT_SUCCESS;
}