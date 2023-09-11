int list_print(node *head) {
    int counter = 1;
    while (head != NULL){
        printf("%d: %d * %s @ %f", counter, head->quantity, head->item_name, head->price);
        counter++;
    }
    return EXIT_SUCCESS;
}