int list_swap_item_positions(node **head, int pos1, int pos2) {
	if (*head == NULL) {
		fprintf(stderr, "Empty list!");
		return EXIT_FAILURE;
	}
	node *current = *head;
	node *pos1_node = NULL;
	node *pos2_node = NULL;
	unsigned int i = 0;
	while (current != NULL) {
		if (i == pos1 - 1) {
			pos1_node = current;
		}
		if (i == pos2 - 1) {
			pos2_node = current;
		}
		current = current->next;
		i++;
	}
	if (pos1_node == NULL || pos2_node == NULL) {
		fprintf(stderr, "No such positions!");
		return EXIT_FAILURE;
	}
	node *temp = pos1_node->next;
	pos1_node->next = pos2_node->next;
	pos2_node->next = temp;
	if (pos1 == 1) {
		*head = pos2_node;
	} else if (pos2 == 1) {
		*head = pos1_node;
	}
	return EXIT_SUCCESS;
}