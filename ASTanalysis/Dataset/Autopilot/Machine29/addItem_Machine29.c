int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (item_name == NULL) {
		return EXIT_FAILURE;
	}
	if (price < 0) {
		return EXIT_FAILURE;
	}
	if (quantity < 0) {
		return EXIT_FAILURE;
	}
	if (pos < 1) {
		return EXIT_FAILURE;
	}

	if (*head == NULL) {
		if (pos != 1) {
			return EXIT_FAILURE;
		}
		node *new_node = malloc(sizeof(node));
		new_node->item_name = malloc((strlen(item_name) + 1) * sizeof(char));
		strcpy(new_node->item_name, item_name);
		new_node->price = price;
		new_node->quantity = quantity;
		new_node->next = NULL;
		*head = new_node;
		return EXIT_SUCCESS;
	}
	unsigned int current_pos = 1;
	node *current = *head;
	while (current->next != NULL && current_pos < pos - 1) {
		current = current->next;
		current_pos += 1;
	}
	if (current_pos != pos - 1) {
		return EXIT_FAILURE;
	}
	node *new_node = malloc(sizeof(node));
	new_node->item_name = malloc((strlen(item_name) + 1) * sizeof(char));
	strcpy(new_node->item_name, item_name);
	new_node->price = price;
	new_node->quantity = quantity;
	new_node->next = current->next;
	current->next = new_node;
	return EXIT_SUCCESS;
}