int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
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

	node *new_node = malloc(sizeof(node));
	new_node->item_name = item_name;
	new_node->price = price;
	new_node->quantity = quantity;
	new_node->next = current->next;
	current->next = new_node;
	return EXIT_SUCCESS;
}