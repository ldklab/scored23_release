int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if(*head == NULL) {
		fprintf(stderr, "Error: list_add_item_at_pos cannot add an item to an empty list.\n");
		return EXIT_FAILURE;
	}
	// if pos is 0, remove the head
	if(pos == 0) {
		node *head_next = (*head)->next;
		free(*head);
		*head = head_next;
		return EXIT_SUCCESS;
	}
	// if pos is 1, add item to the beginning
	if(pos == 1) {
		node *new_node = malloc(sizeof(node));
		if(!new_node) {
			fprintf(stderr, "Error: list_add_item_at_pos cannot allocate memory for new_node.\n");
			return EXIT_FAILURE;
		}
		new_node->item_name = item_name;
		new_node->price = price;
		new_node->quantity = quantity;
		new_node->next = *head;
		*head = new_node;
		return EXIT_SUCCESS;
	}
	node *current = *head;
	for(int i = 1; i < pos - 1; i++) {
		current = current->next;
	}
	node *new_node = malloc(sizeof(node));
	if(!new_node) {
		fprintf(stderr, "Error: list_add_item_at_pos cannot allocate memory for new_node.\n");
		return EXIT_FAILURE;
	}
	new_node->item_name = item_name;
	new_node->price = price;
	new_node->quantity = quantity;
	new_node->next = current->next;
	current->next = new_node;
	return EXIT_SUCCESS;
}