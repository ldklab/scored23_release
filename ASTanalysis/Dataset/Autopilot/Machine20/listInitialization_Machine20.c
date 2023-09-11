int list_init(node **head) {
	int status = EXIT_FAILURE;
	node *new_node = (node *)malloc(sizeof(node));
	if (new_node != NULL) {
		new_node->item_name = NULL;
		new_node->price = 0.0;
		new_node->quantity = 0;
		new_node->next = NULL;
		*head = new_node;
		status = EXIT_SUCCESS;
	}
	return status;
}