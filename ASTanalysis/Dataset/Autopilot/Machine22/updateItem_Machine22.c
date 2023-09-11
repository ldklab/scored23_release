int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = *head;
	int count = 1;
	while (current != NULL && count != pos) {
		count++;
		current = current->next;
	}

	if (current == NULL) {
		return EXIT_FAILURE;
	}

	current->quantity = quantity;
	current->price = price;
	current->item_name = item_name;
	return EXIT_SUCCESS;
}