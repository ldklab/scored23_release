int list_cost_sum(node *head, float *total) {
	if(head == NULL || total == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = head;
	float sum = 0;
	while(temp!= NULL) {
		sum += temp->price * temp->quantity;
		temp = temp->next;
	}

	*total = sum;
	return EXIT_SUCCESS;
}