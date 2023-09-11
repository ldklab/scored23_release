int list_swap_item_positions(node **head, int pos1, int pos2) {
  int i;
  node *curr1 = *head;
  node *curr2 = *head;
  node *prev1 = NULL;
  node *prev2 = NULL;
  for (i = 0; i < pos1; i++) {
    if (curr1 == NULL) {
      return EXIT_FAILURE;
    }
    prev1 = curr1;
    curr1 = curr1->next;
  }
  for (i = 0; i < pos2; i++) {
    if (curr2 == NULL) {
      return EXIT_FAILURE;
    }
    prev2 = curr2;
    curr2 = curr2->next;
  }
  if (curr1 == NULL || curr2 == NULL) {
    return EXIT_FAILURE;
  }
  if (prev1 == NULL) {
    *head = curr2;
  } else {
    prev1->next = curr2;
  }
  if (prev2 == NULL) {
    *head = curr1;
  } else {
    prev2->next = curr1;
  }
  node *temp = curr2->next;
  curr2->next = curr1->next;
  curr1->next = temp;
  return EXIT_SUCCESS;
}