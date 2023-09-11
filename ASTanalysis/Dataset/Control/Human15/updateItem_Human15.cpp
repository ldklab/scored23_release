int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    int count = 0;
    while (head != NULL && count != pos) {
        head = *head->next;
        count++;
    }
    *head->item_name = item_name;
    *head->price = item_price;
    *head->quantity = quantity;
    return EXIT_SUCCESS;
}