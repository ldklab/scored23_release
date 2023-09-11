int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	// If pos is 0, return EXIT_FAILURE
	if (pos == 0) {
		return EXIT_FAILURE;
	}

	// If pos is 1, add to the head
	if (pos == 1) {
		node *new_node = malloc(sizeof(node));
		new_node->item_name = malloc(sizeof(item_name));
		strcpy(new_node->item_name, item_name);
		new_node->price = price;
		new_node->quantity = quantity;
		new_node->next = *head;
		*head = new_node;
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

	// Create new node with item information
	node *new_node = malloc(sizeof(node));
	new_node->item_name = malloc(sizeof(item_name));
	strcpy(new_node->item_name, item_name);
	new_node->price = price;
	new_node->quantity = quantity;

	// Insert new node into the list
	new_node->next = current->next;
	current->next = new_node;

	return EXIT_SUCCESS;
}