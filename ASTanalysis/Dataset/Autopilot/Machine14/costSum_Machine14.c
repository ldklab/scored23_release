int list_cost_sum(node *head, float *total) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *cur_node = head;
	float sum = 0;
	while (cur_node != NULL) {
		sum += cur_node->price * cur_node->quantity;
		cur_node = cur_node->next;
	}
	*total = sum;
	return EXIT_SUCCESS;
}