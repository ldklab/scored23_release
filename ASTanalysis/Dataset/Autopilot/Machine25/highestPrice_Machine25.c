int list_find_highest_price_item_position(node *head, int *pos) {
  int highest_price = -1;
  node *current_node = head;
  for (int i = 1; current_node != NULL; i++) {
    if (current_node->price > highest_price) {
      highest_price = current_node->price;
      *pos = i;
    }
    current_node = current_node->next;
  }
  return EXIT_SUCCESS;
}