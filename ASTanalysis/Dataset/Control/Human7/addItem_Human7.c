int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    node *temp = *head;
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->item_name=item_name;
    new_node->price=price;
    new_node->quantity=quantity;
    if(pos ==1){
        new_node->next = temp;
        *head = new_node;
    } else {
        for(int i =1; i< pos-1; i++){
            if(temp->next==NULL){
                break;
            }
            temp= temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}