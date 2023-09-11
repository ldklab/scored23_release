int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (pos == 1) {
		(*head)->item_name = item_name;
		(*head)->price = price;
		(*head)->quantity = quantity;
		return EXIT_SUCCESS;
	}
	node *cur_node = (*head)->next;
	unsigned int i = 2;
	while (cur_node != NULL) {
		if (i == pos) {
			cur_node->item_name = item_name;
			cur_node->price = price;
			cur_node->quantity = quantity;
			return EXIT_SUCCESS;
		}
		cur_node = cur_node->next;
		i++;
	}
	return EXIT_FAILURE;
}