int list_find_highest_price_item_position(node *head, int *pos) {
	int status = EXIT_FAILURE;
	if (head!= NULL && pos!= NULL) {
		node *current = head;
		float max = 0.0;
		int max_pos = 0;
		int i = 1;
		while (current->next!= NULL) {
			if (current->price > max) {
				max = current->price;
				max_pos = i;
			}
			current = current->next;
			i++;
		}
		*pos = max_pos;
		status = EXIT_SUCCESS;
	}
	return status;
}