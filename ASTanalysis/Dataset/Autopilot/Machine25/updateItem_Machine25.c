int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  node *current_node = *head;
  if (pos < 1) {
    return EXIT_FAILURE;
  }
  for (int i = 1; i < pos; i++) {
    if (current_node == NULL) {
      return EXIT_FAILURE;
    }
    current_node = current_node->next;
  }
  current_node->price = price;
  current_node->quantity = quantity;
  free(current_node->item_name);
  current_node->item_name = malloc(sizeof(char) * (strlen(item_name) + 1));
  strcpy(current_node->item_name, item_name);
  return EXIT_SUCCESS;
}