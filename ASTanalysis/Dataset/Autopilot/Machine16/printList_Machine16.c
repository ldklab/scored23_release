int list_print(node *head) {
	// If head is empty, return an empty string
	if (head == NULL) {
		printf("\n");
		return EXIT_SUCCESS;
	}

	// If head has only one node
	if (head->next == NULL) {
		printf("%d: %d * %s @ $%.2f ea\n", 1, head->quantity, head->item_name, head->price);
		return EXIT_SUCCESS;
	}

	// If head has multiple nodes
	node *current = head;
	int pos = 1;
	while (current != NULL) {
		printf("%d: %d * %s @ $%.2f ea\n", pos, current->quantity, current->item_name, current->price);
		current = current->next;
		pos++;
	}

	return EXIT_SUCCESS;
}