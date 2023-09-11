int list_cost_sum(node *head, float *total) {
	if (head == NULL) {
		fprintf(stderr, "empty list");
		return EXIT_FAILURE;
	}
	node *current = head->next;
	float sum = 0.0;
	while (current != NULL) {
		sum += current->price * current->quantity;
		current = current->next;
	}
	*total = sum;
	return EXIT_SUCCESS;
}