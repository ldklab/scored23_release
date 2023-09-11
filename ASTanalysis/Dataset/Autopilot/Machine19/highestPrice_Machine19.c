int list_find_highest_price_item_position(node *head, int *pos) {
	if(head == NULL || pos == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = head;
	float highest_price = 0;
	int index = 0;
	while(temp != NULL) {
		if(highest_price < temp->price) {
			highest_price = temp->price;
			index = temp->quantity;
		}
		temp = temp->next;
	}

	*pos = index;
	return EXIT_SUCCESS;
}