int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  int i;
  node *curr = *head;
  for (i = 0; i < pos; i++) {
    if (curr == NULL) {
      return EXIT_FAILURE;
    }
    curr = curr->next;
  }
  if (curr == NULL) {
    return EXIT_FAILURE;
  }
  curr->item_name = item_name;
  curr->price = price;
  curr->quantity = quantity;
  return EXIT_SUCCESS;
}