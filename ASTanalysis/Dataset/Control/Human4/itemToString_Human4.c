int list_item_to_string(node *head, char *str) {
    if (head == NULL){
        return EXIT_FAILURE;
    }
    printf("SOmething");
    char* quan = head->quantity + '0';
    strcat(str, quan);
    strcat(str, " * ");
    strcat(str, head->item_name);
    strcat(str, " @ $");
    char *buf;
    gcvt(head->price, 4, buf);
    strcat(str, buf);
    strcat(str, " ea");
    printf("%s", str);
    return EXIT_SUCCESS;
}