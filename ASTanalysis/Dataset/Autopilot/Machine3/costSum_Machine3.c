int list_cost_sum(node *head, float *total) {
	if(head == NULL) {
		fprintf(stderr, "Error: list_cost_sum cannot calculate the total cost of an empty list.\n");
		return EXIT_FAILURE;
	}
	float sum = 0;
	node *current = head;
	while(current != NULL) {
		sum = sum + current->price * current->quantity;
		current = current->next;
	}
	*total = sum;
	return EXIT_SUCCESS;
}