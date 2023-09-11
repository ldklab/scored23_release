int list_print(node *head) {
	if (head == NULL) {
		printf("Empty list\n");
		return EXIT_SUCCESS;
	}
	char print_str[MAX_ITEM_PRINT_LEN];
	node *current = head;
	int count = 1;
	while (current != NULL) {
		sprintf(print_str, "%d: %d * %s @ $%.2f ea\n", count, current->quantity, current->item_name, current->price);
		printf("%s", print_str);
		count++;
		current = current->next;
	}
	return EXIT_SUCCESS;
}