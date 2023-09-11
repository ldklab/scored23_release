int list_remove_item_at_pos(node **head, int pos) {
	if (pos == 1) {
		node *cur_node = *head;
		*head = (*head)->next;
		free(cur_node);
		return EXIT_SUCCESS;
	}
	node *prev_node = *head;
	node *cur_node = (*head)->next;
	unsigned int i = 2;
	while (cur_node != NULL) {
		if (i == pos) {
			prev_node->next = cur_node->next;
			free(cur_node);
			return EXIT_SUCCESS;
		}
		prev_node = cur_node;
		cur_node = cur_node->next;
		i++;
	}
	return EXIT_FAILURE;
}