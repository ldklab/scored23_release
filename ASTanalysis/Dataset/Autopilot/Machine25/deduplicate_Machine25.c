int list_deduplicate(node **head) {
  node *current_node = *head;
  while (current_node != NULL) {
    node *node_to_check = current_node->next;
    while (node_to_check != NULL) {
      if (strcmp(current_node->item_name, node_to_check->item_name) == 0) {
        current_node->quantity += node_to_check->quantity;
        node *node_to_remove = node_to_check;
        node_to_check = node_to_check->next;
        list_remove_item_at_pos(head, node_to_remove->quantity);
      } else {
        node_to_check = node_to_check->next;
      }
    }
    current_node = current_node->next;
  }
  return EXIT_SUCCESS;
}