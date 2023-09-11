int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  node *temp = *head;
  unsigned int i = 0;
  // check if there is no head
  if (!head) {
    return EXIT_FAILURE;
  }
  // check if there is no item_name
  if (!temp) {
    return EXIT_SUCCESS;
  }
  while (i < pos) {
    // check if there is no next node
    if (!temp->next) {
      return EXIT_SUCCESS;
    }
    temp = temp->next;
    i++;
  }
  // check if there is no next node
  if (!temp->next) {
    return EXIT_SUCCESS;
  }
  // check if there is no item_name
  if (!item_name) {
    return EXIT_SUCCESS;
  }
  node *new_node = malloc(sizeof(node));
  new_node->item_name = malloc(strlen(item_name) + 1);
  strcpy(new_node->item_name, item_name);
  new_node->price = price;
  new_node->quantity = quantity;
  new_node->next = temp->next;
  temp->next = new_node;
  return EXIT_SUCCESS;
}