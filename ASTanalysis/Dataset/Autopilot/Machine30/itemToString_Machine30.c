int list_item_to_string(node *head, char *str) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    float price_rounded = (float) (int) (head->price * 100) / 100.0;
    sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, 
        price_rounded);

    return EXIT_SUCCESS;
}