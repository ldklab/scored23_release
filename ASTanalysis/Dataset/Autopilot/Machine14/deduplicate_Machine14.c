int list_deduplicate(node **head) {
	node *cur_node = *head;
	while (cur_node != NULL) {
		node *cur_node2 = cur_node->next;
		node *prev_node2 = cur_node;
		while (cur_node2 != NULL) {
			if (strcmp(cur_node->item_name, cur_node2->item_name) == 0) {
				cur_node->quantity += cur_node2->quantity;
				prev_node2->next = cur_node2->next;
				free(cur_node2);
				cur_node2 = prev_node2;
			}
			prev_node2 = cur_node2;
			cur_node2 = cur_node2->next;
		}
		cur_node = cur_node->next;
	}
	return EXIT_SUCCESS;
}