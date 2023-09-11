int list_load(node **head, char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}
	node *cur_node = *head;
	while (cur_node->next != NULL) {
		cur_node = cur_node->next;
	}
	char *item_name = NULL;
	float price;
	int quantity;
	while (fscanf(fp, "%m[^,],%f,%d\n", &item_name, &price, &quantity) != EOF) {
		cur_node->next = malloc(sizeof(node));
		cur_node->next->item_name = item_name;
		cur_node->next->price = price;
		cur_node->next->quantity = quantity;
		cur_node->next->next = NULL;
		cur_node = cur_node->next;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}