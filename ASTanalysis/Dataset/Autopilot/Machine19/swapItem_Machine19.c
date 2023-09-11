int list_swap_item_positions(node **head, int pos1, int pos2) {
	if(head == NULL) {
		return EXIT_FAILURE;
	}

	if(pos1 == 0 || pos2 == 0) {
		return EXIT_FAILURE;
	}
	
	node *temp = *head;
	if(pos1 == pos2) {
		return EXIT_SUCCESS;
	}

	int index = 1;
	while(temp->next!= NULL && index < pos1 - 1) {
		temp = temp->next;
		index++;
	}

	if(index == pos1 - 1) {
		if(temp->next == NULL) {
			return EXIT_FAILURE;
		}
		else {
			node *temp1 = temp->next;
			node *temp2 = temp1->next;
			temp->next = temp2;
			temp1->next = temp2->next;
			temp2->next = temp1;
			return EXIT_SUCCESS;
		}
	}
	else {
		return EXIT_FAILURE;
	}
}