int list_print(node *head) {
    int i = 0;
    if (head == NULL){
        return EXIT_FAILURE;
    }
    while (head[i].next != NULL){
        printf("%d: %d * %s @ $%.2f ea\n", i, head[i].quantity, 
        head[i].item_name, head[i].price);
        i++;
    }
    return EXIT_SUCCESS;
}