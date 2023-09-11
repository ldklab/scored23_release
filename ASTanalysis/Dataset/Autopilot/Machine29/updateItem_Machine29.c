int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (pos < 1) {
		return EXIT_FAILURE;
	}
	if (item_name == NULL) {
		return EXIT_FAILURE;
	}
	if (price < 0) {
		return EXIT_FAILURE;
	}
	if (quantity < 0) {
		return EXIT_FAILURE;
	}

	if (*head == NULL) {
		return EXIT_FAILURE;
	}
	unsigned int current_pos = 1;
	node *current = *head;
	while (current->next != NULL && current_pos < pos) {
		current = current->next;
		current_pos += 1;
	}
	if (current_pos != pos) {
		return EXIT_FAILURE;
	}
	free(current->item_name);
	current->item_name = malloc((strlen(item_name) + 1) * sizeof(char));
	strcpy(current->item_name, item_name);
	current->price = price;
	current->quantity = quantity;
	return EXIT_SUCCESS;
}