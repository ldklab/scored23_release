int list_find_highest_price_item_position(node *head, int *pos) 
{
    int counter = 0;
    int max = -1;

    while (head != NULL) {
        counter++;

        if (head->price > max) max = head->price;
        head = head->next;
    }

    *pos = counter;

    return EXIT_SUCCESS;
}