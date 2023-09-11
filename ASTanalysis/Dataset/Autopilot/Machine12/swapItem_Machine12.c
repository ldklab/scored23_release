int list_swap_item_positions(node **head, int pos1, int pos2) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  node *curr1 = *head;
  node *curr2 = *head;
  int i = 1;
  for (i = 1; i < pos1; i++) {
    if (curr1->next == NULL) {
      return EXIT_FAILURE;
    }
    curr1 = curr1->next;
  }
  for (i = 1; i < pos2; i++) {
    if (curr2->next == NULL) {
      return EXIT_FAILURE;
    }
    curr2 = curr2->next;
  }
  char *temp_item_name = (char *)malloc(sizeof(char) * (strlen(curr1->item_name) + 1));
  strcpy(temp_item_name, curr1->item_name);
  float temp_price = curr1->price;
  int temp_quantity = curr1->quantity;
  free(curr1->item_name);
  curr1->item_name = (char *)malloc(sizeof(char) * (strlen(curr2->item_name) + 1));
  strcpy(curr1->item_name, curr2->item_name);
  curr1->price = curr2->price;
  curr1->quantity = curr2->quantity;
  free(curr2->item_name);
  curr2->item_name = (char *)malloc(sizeof(char) * (strlen(temp_item_name) + 1));
  strcpy(curr2->item_name, temp_item_name);
  curr2->price = temp_price;
  curr2->quantity = temp_quantity;
  free(temp_item_name);
  return EXIT_SUCCESS;
}