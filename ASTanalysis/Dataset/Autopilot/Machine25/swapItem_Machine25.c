int list_swap_item_positions(node **head, int pos1, int pos2) {
  node *current_node = *head;
  node *node1 = NULL;
  node *node2 = NULL;
  node *previous_node1 = NULL;
  node *previous_node2 = NULL;
  if (pos1 < 1 || pos2 < 1) {
    return EXIT_FAILURE;
  }
  for (int i = 1; i < pos1; i++) {
    if (current_node == NULL) {
      return EXIT_FAILURE;
    }
    previous_node1 = current_node;
    current_node = current_node->next;
  }
  node1 = current_node;
  current_node = *head;
  for (int i = 1; i < pos2; i++) {
    if (current_node == NULL) {
      return EXIT_FAILURE;
    }
    previous_node2 = current_node;
    current_node = current_node->next;
  }
  node2 = current_node;
  if (pos1 == 1) {
    previous_node2->next = node1;
    node1->next = node2->next;
    node2->next = node1;
    *head = node2;
  } else if (pos2 == 1) {
    previous_node1->next = node2;
    node2->next = node1->next;
    node1->next = node2;
    *head = node1;
  } else {
    previous_node1->next = node2;
    previous_node2->next = node1;
    node1->next = node2->next;
    node2->next = node1->next;
  }
  return EXIT_SUCCESS;
}