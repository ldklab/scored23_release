int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		return EXIT_FAILURE;
	}
	new_node->item_name = item_name;
	new_node->price = price;
	new_node->quantity = quantity;
	if (pos == 1) {
		new_node->next = *head;
		*head = new_node;
		return EXIT_SUCCESS;
	}
	node *prev_node = *head;
	node *cur_node = (*head)->next;
	unsigned int i = 2;
	while (cur_node != NULL) {
		if (i == pos) {
			new_node->next = cur_node;
			prev_node->next = new_node;
			return EXIT_SUCCESS;
		}
		prev_node = cur_node;
		cur_node = cur_node->next;
		i++;
	}
	if (i == pos) {
		prev_node->next = new_node;
		new_node->next = NULL;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}