int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(pos<0){
        return EXIT_FAILURE;
    }

    node* curr = *head;

    if(pos==1){
        // node* newnode = malloc(sizeof(node));
        // newnode->item_name = item_name;
        // newnode->price = price;
        // newnode->quantity = quantity;
        
        // newnode->next= *head;
        // *head = newnode;
        *head = curr->next;
    }

    else{
        int n = 1;
        while(curr){
            if(n==pos-1){
                // node* newnode = malloc(sizeof(node));
                // newnode->item_name = item_name;
                // newnode->price = price;
                // newnode->quantity = quantity;
                // newnode->next= curr->next;

                // curr->next = newnode;
                curr->next = curr->next->next;
                break;
            }

            else{
                // *head = (*head)->next;
                curr = curr->next;
                n += 1;
            }
        }
    }

    return EXIT_SUCCESS;
}