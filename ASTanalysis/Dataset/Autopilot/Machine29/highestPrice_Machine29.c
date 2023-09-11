int list_find_highest_price_item_position(node *head, int *pos) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = head;
	float highest_price = head->price;
	int highest_price_pos = 1;
	int current_pos = 1;
	while (current->next != NULL) {
		current = current->next;
		current_pos += 1;
		if (current->price > highest_price) {
			highest_price = current->price;
			highest_price_pos = current_pos;
		}
	}
	*pos = highest_price_pos;
	return EXIT_SUCCESS;
}