int list_deduplicate(node **head) {
	if (*head == NULL) {
		fprintf(stderr, "Empty list!");
		return EXIT_FAILURE;
	}
	node *current = *head;
	node *next = current->next;
	node *toFree = current;
	while (next!= NULL) {
		node *current2 = next->next;
		while (current2!= NULL) {
			if (!strcmp(current->item_name, current2->item_name)) {
				current->quantity += current2->quantity;
				current->price += current2->price;
				current2 = current2->next;
				toFree = toFree->next;
				free(toFree);
			} else {
				current = current->next;
			}
		}
		next = next->next;
	}
	*head = current;
	return EXIT_SUCCESS;
}
