int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  node *new_node = malloc(sizeof(node));
  new_node->item_name = item_name;
  new_node->price = price;
  new_node->quantity = quantity;

  int i;
  node *curr = *head;
  node *prev = NULL;
  for (i = 0; i < pos; i++) {
    if (curr == NULL) {
      return EXIT_FAILURE;
    }
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL) {
    new_node->next = *head;
    *head = new_node;
  } else {
    new_node->next = curr;
    prev->next = new_node;
  }
  return EXIT_SUCCESS;
}