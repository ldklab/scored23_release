int list_remove_item_at_pos(node **head, int pos) {
  node *current_node = *head;
  if (pos < 1) {
    return EXIT_FAILURE;
  }
  if (pos == 1) {
    *head = current_node->next;
    free(current_node->item_name);
    free(current_node);
    return EXIT_SUCCESS;
  }
  for (int i = 1; i < pos - 1; i++) {
    if (current_node == NULL) {
      return EXIT_FAILURE;
    }
    current_node = current_node->next;
  }
  node *node_to_remove = current_node->next;
  current_node->next = current_node->next->next;
  free(node_to_remove->item_name);
  free(node_to_remove);
  return EXIT_SUCCESS;
}