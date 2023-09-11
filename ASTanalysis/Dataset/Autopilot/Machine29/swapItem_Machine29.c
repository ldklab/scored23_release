int list_swap_item_positions(node **head, int pos1, int pos2) {
	if (pos1 < 1 || pos2 < 1) {
		return EXIT_FAILURE;
	}

	if (*head == NULL) {
		return EXIT_FAILURE;
	}
	if (pos1 == 1 && pos2 == 2) {
		node *temp = (*head)->next;
		(*head)->next = temp->next;
		temp->next = *head;
		*head = temp;
		return EXIT_SUCCESS;
	}
	unsigned int current_pos = 1;
	node *current = *head;
	while (current->next != NULL && current_pos < pos1 - 1) {
		current = current->next;
		current_pos += 1;
	}
	if (current_pos != pos1 - 1) {
		return EXIT_FAILURE;
	}
	node *node1 = current->next;
	node *node2 = node1->next;
	while (node2 != NULL && current_pos < pos2 - 1) {
		node2 = node2->next;
		current_pos += 1;
	}
	if (current_pos != pos2 - 1) {
		return EXIT_FAILURE;
	}
	if (pos1 == 1) {
		current->next = node2->next;
		node2->next = node1;
		node1->next = current->next;
		*head = node2;
		return EXIT_SUCCESS;
	}
	if (pos2 == 1) {
		current->next = node2->next;
		node2->next = node1;
		node1->next = current->next;
		*head = node1;
		return EXIT_SUCCESS;
	}
	current->next = node2;
	node *temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
	return EXIT_SUCCESS;
}