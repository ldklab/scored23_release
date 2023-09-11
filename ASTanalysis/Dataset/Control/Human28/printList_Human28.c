int list_print(node *head) {
    int i =0;
    node* n = head;
    while (n != NULL){
        printf("%d : %d * %c @%f ea",i,head->quantity,head ->item_name,head ->price);
        n = n ->next;
        i = i+1; 
    }
    return EXIT_SUCCESS;
}