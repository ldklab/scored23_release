int list_find_highest_price_item_position(node *head, int *pos) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *cur_node = head;
	unsigned int i = 1;
	unsigned int max_pos = 1;
	float max_price = cur_node->price;
	while (cur_node != NULL) {
		if (cur_node->price > max_price) {
			max_price = cur_node->price;
			max_pos = i;
		}
		cur_node = cur_node->next;
		i++;
	}
	*pos = max_pos;
	return EXIT_SUCCESS;
}