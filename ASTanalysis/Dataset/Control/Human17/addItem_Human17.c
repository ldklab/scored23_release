int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    struct node *temp,*ptr;
    temp=(struct node*) malloc(sizeof(struct node));
    &temp->item_name=item_name;
    &temp->price=price;
    &temp->quantity=quantity;
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        for(i=0;ptr=head;i<pos-1;i++){
            ptr=ptr->next;
            if(ptr==NULL)
            {
                return EXIT_FAILURE;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return EXIT_SUCCESS;
}