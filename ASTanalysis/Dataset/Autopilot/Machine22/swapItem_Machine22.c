int list_swap_item_positions(node **head, int pos1, int pos2) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = *head;
	int count = 1;
	while (current != NULL && count != pos1) {
		count++;
		current = current->next;
	}

	if (current == NULL) {
		return EXIT_FAILURE;
	}

	node *target = current->next;
	node *prev = current->next;
	int count2 = 1;
	while (target != NULL && count2 != pos2) {
		count2++;
		prev = target;
		target = target->next;
	}

	if (target == NULL) {
		return EXIT_FAILURE;
	}

	prev->next = target->next;
	target->next = current->next;
	current->next = target;
	return EXIT_SUCCESS;
}