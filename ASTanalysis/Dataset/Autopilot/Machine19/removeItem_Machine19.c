int list_remove_item_at_pos(node **head, int pos) {
	if(head == NULL) {
		return EXIT_FAILURE;
	}

	if(pos == 0) {
		return EXIT_FAILURE;
	}

	node *temp = *head;
	if(pos == 1) {
		if(*head == NULL) {
			return EXIT_FAILURE;
		}
		else {
			*head = temp->next;
			free(temp->item_name);
			free(temp);
			return EXIT_SUCCESS;
		}
	}

	int index = 1;
	while(temp->next!= NULL && index < pos - 1) {
		temp = temp->next;
		index++;
	}

	if(index == pos - 1) {
		if(temp->next == NULL) {
			return EXIT_FAILURE;
		}
		else {
			node *temp2 = temp->next;
			temp->next = temp->next->next;
			free(temp2->item_name);
			free(temp2);
			return EXIT_SUCCESS;
		}
	}
	else {
		return EXIT_FAILURE;
	}
}