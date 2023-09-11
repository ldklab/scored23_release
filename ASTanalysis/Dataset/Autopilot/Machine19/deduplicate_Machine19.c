int list_deduplicate(node **head) {
	if(head == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = *head;
	node *head2 = NULL;
	node *temp2 = NULL;

	while(temp!= NULL) {
		temp2 = head2;
		head2 = malloc(sizeof(node));
		if(head2 == NULL) {
			return EXIT_FAILURE;
		}
		head2->item_name = malloc(sizeof(char) * (strlen(temp->item_name) + 1));
		strcpy(head2->item_name, temp->item_name);
		head2->price = temp->price;
		head2->quantity = temp->quantity;
		head2->next = NULL;
		if(temp2 != NULL) {
			temp2->next = head2;
		}

		temp = temp->next;
	}

	free(temp);
	*head = head2;
	return EXIT_SUCCESS;
}