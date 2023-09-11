int list_find_highest_price_item_position(node *head, int *pos) 
{
    int max_price = - 1;
    int max_price_pos = 0;
    int count = 0;
    while (head != NULL) {
        count++;
        if (head->price > max_price) {
            max_price = head->price;
            max_price_pos = count;
        }
    }
    pos = max_price_pos;
    return EXIT_SUCCESS;
}