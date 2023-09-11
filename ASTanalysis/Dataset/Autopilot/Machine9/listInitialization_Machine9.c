int list_init(node **head) {
  *head = malloc(sizeof(node));
  if (!*head) {
    return EXIT_FAILURE;
  }
  (*head)->item_name = NULL;
  (*head)->price = 0;
  (*head)->quantity = 0;
  (*head)->next = NULL;
  return EXIT_SUCCESS;
}