int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    node new = {
        .item_name = item_name,
        .price = price,
        .quantity = quantity
    };

    int count = 0;
    node* prev = head;
    head = *head->next;
    while (head != NULL && count != pos) {
        head = *head->next;
        prev = prev->next;
        count++;
    }
    prev->next = new;
    new->next = head;
    return EXIT_SUCCESS;
}