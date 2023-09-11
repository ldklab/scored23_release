int list_cost_sum(node *head, float *total) {
  node *current_node = head;
  *total = 0;
  for (int i = 1; current_node != NULL; i++) {
    *total += current_node->price * current_node->quantity;
    current_node = current_node->next;
  }
  return EXIT_SUCCESS;
}