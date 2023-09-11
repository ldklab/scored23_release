int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	// If pos is 0, return EXIT_FAILURE
	if (pos == 0) {
		return EXIT_FAILURE;
	}

	// If pos is 1, update the head
	if (pos == 1) {
		(*head)->item_name = item_name;
		(*head)->price = price;
		(*head)->quantity = quantity;
		return EXIT_SUCCESS;
	}

	// If pos is greater than 1, find the node at pos - 1
	int i;
	node *current = *head;
	for (i = 1; i < pos - 1; i++) {
		current = current->next;
		if (current == NULL) {
			return EXIT_FAILURE;
		}
	}

	// Update the node
	current->item_name = item_name;
	current->price = price;
	current->quantity = quantity;
	return EXIT_SUCCESS;
}