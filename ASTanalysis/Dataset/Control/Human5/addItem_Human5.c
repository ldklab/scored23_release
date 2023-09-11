int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if(pos<1)
        return EXIT_FAILURE;
    else{
        while(pos--) {
            if(pos==0){
                node * temp = (node*) malloc(sizeof(node));
                temp ->  item_name = item_name;
                temp->price = price;
                temp->quantity = quantity;
                temp->next = *head;
                *head = temp;
                return EXIT_SUCCESS;
            }
            else {
                head=&(*head)->next;
            }
        }
    }
    return EXIT_FAILURE;
}