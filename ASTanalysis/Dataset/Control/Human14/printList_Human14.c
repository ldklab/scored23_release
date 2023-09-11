int list_print(node *head)
{
    // TODO: Implement this function,
    if (head == NULL)
    {
        return EXIT_FAILURE;
    }
    unsigned int pos = 1;
    node *curr = head;
    while (curr != NULL)
    {
        printf("%d: %d * %s @ $%.2f ea\n", pos, curr->quantity, curr->item_name, curr->price);
        curr = curr->next;
        pos++;
    }
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}