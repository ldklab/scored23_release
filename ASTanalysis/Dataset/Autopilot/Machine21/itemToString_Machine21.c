int list_item_to_string(node *head, char *str) {
    node *current = head;
    int i=0, j=0;
    char *p = str;
    while (current!=NULL) {
        int len=0;
        float f = current->price;
        char *item_name = current->item_name;
        len = sprintf(p, "%d * %s @ $%.2f ea", current->quantity, item_name, f);
        p += len;
        i++;
        current = current->next;
        j++;
    }
 