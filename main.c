//���|(���i��X) - �ϥ��쵲(Link)��@�]C �y���ʺA�O����ŧi�^
//http://openhome.cc/Gossip/AlgorithmGossip/StackByLink.htm
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node* creates(void);         // �إ߰��|
int isEmpty(Node*);           // ���|�w��
int stacktop(Node*);   // �Ǧ^���ݤ���
Node* add(Node*, int);   // �s�W����
Node* delete(Node*);     // �R������
void list(Node*);      // ��ܩҦ����e

int main(void) {
    Node* sTop;
    int input, select;

    sTop = creates();

    while(1) {
        printf("\n\n�п�J�ﶵ(-1����)�G");
        printf("\n(1)���J�Ȧܰ��|");
        printf("\n(2)��ܰ��|����");
        printf("\n(3)�R�����ݭ�");
        printf("\n(4)��ܩҦ����e");
        printf("\n\$c>");
        scanf("%d", &select);

        if(select == -1)
            break;

        switch(select) {
            case 1:
                printf("\n��J�ȡG");
                scanf("%d", &input);
                sTop = add(sTop, input);
                break;
            case 2:
                printf("\n���ݭȡG%d", stacktop(sTop));
                break;
            case 3:
                sTop = delete(sTop);
                break;
            case 4:
                list(sTop);
                break;
            default:
                printf("\n�ﶵ���~�I");
        }
    }

    printf("\n");

    return 0;
}

Node* creates() {
    return NULL;
}

int isEmpty(Node* top) {
    return (top == NULL);
}

int stacktop(Node* top) {
    return top->data;
}

Node* add(Node* top, int item) {
    Node* newnode;

    newnode = (Node*) malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("\n�O����t�m���ѡI");
        exit(1);
    }

    newnode->data = item;
    newnode->next = top;
    top = newnode;

    return top;
}

Node* delete(Node* top) {
    Node* tmpnode;

    tmpnode = top;
    if(tmpnode == NULL) {
        printf("\n���|�w�šI");
        return NULL;
    }

    top = top->next;
    free(tmpnode);

    return top;
}

void list(Node* top) {
    Node* tmpnode;
    tmpnode = top;

    printf("\n���|���e�G");
    while(tmpnode != NULL) {
        printf("%d ", tmpnode->data);
        tmpnode = tmpnode->next;
    }
}
