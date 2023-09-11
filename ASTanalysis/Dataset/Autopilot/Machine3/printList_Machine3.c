int list_print(node *head) {
	node *current = head;
	int position = 1;
	if(current->next == NULL) {
		printf("%d: %d * %s @ $%.2f ea\n", position, current->quantity, current->item_name, current->price);
		return EXIT_SUCCESS;
	}
	while (current->next != NULL) {
		current = current->next;
		printf("%d: %d * %s @ $%.2f ea\n", position, current->quantity, current->item_name, current->price);
		position++;
	}
	return EXIT_SUCCESS;
}