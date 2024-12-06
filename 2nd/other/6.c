struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *tmp = head;
    int num = 0;
    for (; tmp->next != NULL; num++)
    {
        tmp = tmp->next;
    }
    num++;

    tmp = head;
    // 找到操作节点，他的next是要移除的节点
    // 从头开始找到要移动的次数 num - n -1;
    int moveTimes = num - n - 1;

    for (int i = 0; i < moveTimes; i++)
    {
        tmp = tmp->next;
    }

    if (moveTimes < 0)
    {
        head = head->next;
        free(tmp);
        return head;
    }

    struct ListNode *willRemove = NULL;
    willRemove = tmp->next; // 找到目标节点，这个节点可能是最后一个节点
    if (willRemove != NULL)
    {
        tmp->next = tmp->next->next;
    }

    free(willRemove);

    return head;
}

// 创建链表的函数
struct ListNode *createList(int *arr, int size)
{
    if (size == 0)
    {
        return NULL; // 如果数组为空，返回 NULL
    }

    // 创建头节点
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    // 使用临时指针构建链表
    struct ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    return head; // 返回链表头节点
}

int main()
{
    int arr[] = {1, 2}; //  2,3, 4, 5
    int size = sizeof(arr) / sizeof(arr[0]);

    // 创建链表
    struct ListNode *head = createList(arr, size);

    // 打印链表
    printf("Created list: ");
    printList(head);

    head = removeNthFromEnd(head, 1);//2
    // 打印链表
    if (head != NULL)
    {
        printf("list: ");
        printList(head);
    }

    // 释放链表（防止内存泄漏）
    struct ListNode *current = head;
    while (current != NULL)
    {
        struct ListNode *temp = current;
        current = current->next;
        free(temp);
    }
}