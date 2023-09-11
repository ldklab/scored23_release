int list_swap_item_positions(node **head, int pos1, int pos2) {
	node *node1 = *head;
	node *node2 = *head;
	unsigned int i = 1;
	while (node1 != NULL) {
		if (i == pos1) {
			break;
		}
		node1 = node1->next;
		i++;
	}
	i = 1;
	while (node2 != NULL) {
		if (i == pos2) {
			break;
		}
		node2 = node2->next;
		i++;
	}
	if (node1 == NULL || node2 == NULL) {
		return EXIT_FAILURE;
	}
	char *temp_item_name = node1->item_name;
	float temp_price = node1->price;
	int temp_quantity = node1->quantity;
	node1->item_name = node2->item_name;
	node1->price = node2->price;
	node1->quantity = node2->quantity;
	node2->item_name = temp_item_name;
	node2->price = temp_price;
	node2->quantity = temp_quantity;
	return EXIT_SUCCESS;
}