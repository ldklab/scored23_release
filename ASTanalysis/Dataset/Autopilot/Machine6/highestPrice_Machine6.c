int list_find_highest_price_item_position(node *head, int *pos) {
	if (head == NULL) {
		fprintf(stderr, "empty list");
		return EXIT_FAILURE;
	}
	node *current = head->next;
	node *max = current;
	int i = 0;
	while (current != NULL) {
		if (current->price > max->price) {
			max = current;
		}
		current = current->next;
		i++;
	}
	*pos = i;
	return EXIT_SUCCESS;
}