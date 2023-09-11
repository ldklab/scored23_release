int list_find_highest_price_item_position(node *head, int *pos) {
  if (head == NULL || pos == NULL) {
    return EXIT_FAILURE;
  }
  float highest_price = head->price;
  int highest_i = 1;
  int i = 1;
  node *curr = head;
  while (curr != NULL) {
    if (curr->price > highest_price) {
      highest_price = curr->price;
      highest_i = i;
    }
    curr = curr->next;
    i++;
  }
  *pos = highest_i;
  return EXIT_SUCCESS;
}