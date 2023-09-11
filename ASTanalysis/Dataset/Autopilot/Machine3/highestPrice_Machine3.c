int list_find_highest_price_item_position(node *head, int *pos) {
	if(head == NULL) {
		fprintf(stderr, "Error: list_find_highest_price_item_position cannot find the highest price for an empty list.\n");
		return EXIT_FAILURE;
	}
	if(head->next == NULL) {
		*pos = 0;
		return EXIT_SUCCESS;
	}
	float highest_price = head->price;
	*pos = 1;
	node *current = head->next;
	while(current != NULL) {
		if(current->price > highest_price) {
			highest_price = current->price;
			*pos = *pos + 1;
		}
		current = current->next;
	}
	return EXIT_SUCCESS;
}