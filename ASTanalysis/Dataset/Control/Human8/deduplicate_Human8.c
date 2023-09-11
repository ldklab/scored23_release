int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int len=0;
    node* curr = *head;

    while(curr){
        curr = curr->next;
        len += 1;
    }

    char* names[len+1];
    memset(names, 0, sizeof(names));

    int quantities[len+1];
    memset(quantities, 0, sizeof(quantities));

    float prices[len+1];
    int j=0;

    curr = *head;

    while(curr){
        // int pos =  find(curr->item_name, names);
        int pos = -1;
        for(int i=0; i<len; i++){
            if(names[i] == curr->item_name){
                pos = i;
                break;
            }
        }

        if(pos==-1){
            names[j] = curr->item_name;
            quantities[j] = curr->quantity;

            // char str[256];
            // sprintf(str, "%.2f", curr->price);
            // sscanf(str, "%f", &(prices[j]));
            // prices[j] = curr->price;

            float value = (int)(curr->price * 100 + .5);
            prices[j] =  (float)value / 100;

            // printf("%f\n", curr->price);
            // printf("%f\n", prices[j]);
            j += 1;
        }

        else{
            // names[pos] = curr->item_name;
            quantities[pos] += curr->quantity;
        }

        // printf("quantities_0: %d\n", quantities[0]);

        curr = curr->next;
    }

    *head = NULL;
    list_init(head);
    for(int i=0; i<len; i++){
        if(names[i] != 0){
            list_add_item_at_pos(head, names[i], prices[i], quantities[i], i+1);
        }
    }

    // list_print(*head);

    return EXIT_SUCCESS;
}

