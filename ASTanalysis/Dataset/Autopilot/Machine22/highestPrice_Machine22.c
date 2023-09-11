int list_find_highest_price_item_position(node *head, int *pos) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = head;
	float highest_price = current->price;
	int highest_price_pos = 1;
	int count = 1;
	while (current != NULL) {
		if (current->price > highest_price) {
			highest_price = current->price;
			highest_price_pos = count;
		}
		count++;
		current = current->next;
	}
	*pos = highest_price_pos;
	return EXIT_SUCCESS;
}