int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  node *new_node = malloc(sizeof(node));
  node *current_node = *head;
  new_node->price = price;
  new_node->quantity = quantity;
  new_node->item_name = malloc(sizeof(char) * (strlen(item_name) + 1));
  strcpy(new_node->item_name, item_name);
  new_node->next = NULL;
  if (pos == 1) {
    new_node->next = *head;
    *head = new_node;
    return EXIT_SUCCESS;
  }
  for (int i = 1; i < pos - 1; i++) {
    if (current_node == NULL) {
      return EXIT_FAILURE;
    }
    current_node = current_node->next;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
  return EXIT_SUCCESS;
}