#Binary Tree

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 1000

int c,nodecount, flag=0;

struct node {
int data;
struct node *lchild;
struct node *rchild;
};

struct list
{
	int val;
	int levl;
	struct list *next;
};

void treetraversal(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void levelorder(struct node *root);
void boundarytraversal(struct node *root);
void leftboundarytraversal(struct node *root);
void leaftraversal(struct node *root);
void rightboundarytraversal(struct node *root);
void MorrisInorderTraversal(struct node *root);
//only appropriate algorithms are provided for the functions as comment
//such as stacks and queues are not implemented for these functions and
//user is expected to implement their own stack and queue data structures
//void levelorder(struct node* root);
//void printGivenLevel(struct node* root, int level);
//void iterativeinorder(struct node *root);
//void iterativepreorder(struct node *root););
//void iterativepostorder(struct node *root););
//void levelbylevelorderedprinting(struct node *root);
//void reverselevelbylevelreverseorderprinting(struct node *root);
//void spiralorderprinting(struct node *root);
int sametreecheck(struct node *root1, struct node *root2);
struct node *addbeforeroot(struct node *root,int n);
void addatleftend(struct node *root,int n);
void addatrightend(struct node *root,int n);
struct node *search(struct node *root,int n);
struct node *addafterasleftchild(struct node *root,int data,int n);
struct node *addafterasrightchild(struct node *root,int data,int n);
int countnode(struct node *root);
void topview(struct node *root);
int height(struct node *root);
int maxdata(struct node *root);
struct node *deletegivennode(struct node *start,int data);
int roottoleafsumcheck(struct node *root, int sum);
int isBST(struct node *root, int minm, int maxm);
struct node *leastcommonancestor(struct node *root, int node1, int node2);
int isMirrorImage(struct node *root1, struct node *root2);
int diameter(struct node *root);
int Max(int x, int y);
struct node *Tree_clone(struct node* root);
void View_Tree(struct node *root);
struct list *findMinMaxTopView(struct node *node, struct list *head, int *min, int *maxm, int hd, int lv);
struct list *findMinMaxBottomView(struct node *node, struct list *head, int *min, int *maxm, int hd, int lv);
void printViews(struct list *head);

int main()
{
    struct node *root[10],*temp;
    int choice,data,nodedata,item,sum,res,i,r,r1,r2,data1,data2;
    for(i=0;i<10;i++)
        root[i]=NULL;
    while(1)
    {
        printf("\nENTER\n0 to print root\n1 for tree traversal\n2 to add before root\n3 to add at left end\n4 to add at right end\n");
        printf("5 to search an item\n6 to add after a given node as left child\n7 to add after a given node as right child\n");
        printf("8 to count no. of nodes\n9 to print tree top view data\n10 to find the height of a node\n11 to find the maximum data in tree");
        printf("\n12 to delete a given node \n13 to check root to leaf sum is present or not\n14 to check if tree is BST or not");
        printf("\n15 for Morris Inorder Traversal\n16 to check if two binary tree is same or not\n17 to find least common ancestor\n");
        printf("18 to check for mirror image trees\n19 to find diameter of a tree\n20 to clone a BST\n21 to print Views of tree\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            if(root[r-1]!=NULL)
                printf("\n%d\n",root[r-1]->data);
            else
                printf("\nroot is empty\n");
                printf("\n");
            break;
        case 1:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            treetraversal(root[r-1]);
            printf("\n");
            break;
        case 2:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter new data\n");
            scanf("%d",&data);
            root[r-1]=addbeforeroot(root[r-1],data);
            printf("\n");
            break;
        case 3:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter new data\n");
            scanf("%d",&data);
            addatleftend(root[r-1],data);
            printf("\n");
            break;
        case 4:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter new data\n");
            scanf("%d",&data);
            addatrightend(root[r-1],data);
            printf("\n");
            break;
        case 5:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter data to be searched\n");
            scanf("%d",&item);
            temp=search(root[r-1],item);
            if(temp==NULL)
                printf("\ndata % d is not found in tree\n",item);
            else
                printf("\ndata %d is found in tree\n",temp->data);
                printf("\n");
            break;
        case 6:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter node data\n");
            scanf("%d",&nodedata);
            printf("\nenter new data\n");
            scanf("%d",&data);
            root[r-1]=addafterasleftchild(root[r-1],nodedata,data);
            printf("\n");
            break;
        case 7:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nenter node data\n");
            scanf("%d",&nodedata);
            printf("\nenter new data\n");
            scanf("%d",&data);
            addafterasrightchild(root[r-1],nodedata,data);
            printf("\n");
            break;
        case 8:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            //nodecount=0;
            //countnode(root[r-1]);
            //printf("\nno of nodes in the tree is : %d\n",nodecount);
            printf("\nno of nodes in the tree is : %d\n",countnode(root[r-1]));
            printf("\n");
            break;
        case 9:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\n tree top view is :\n");
            topview(root[r-1]);
            if(flag==0)
                printf("\empty tree\n");
            flag=0;
            printf("\n");
            break;
        case 10:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nheight of tree = %d\n",height(root[r-1]));
            break;
        case 11:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("maximum data in tree is = %d\n",maxdata(root[r-1]));
            break;
        case 12:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            if(root[r-1]==NULL)
                printf("no node is present in tree");
            else
            {
                printf("\nenter the value of node to be deleted\n");
                scanf("%d",&data);
                if(search(root[r-1],data))
                    root[r-1]=deletegivennode(root[r-1],data);
                else
                    printf("\ndata : %d is not present in tree\n");
            }
            printf("\n");
            break;
        case 13:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("enter value of root to leaf sum\n");
            scanf("%d",&sum);
            res=roottoleafsumcheck(root[r-1],sum);
            if(res)
                printf("\nroot to leaf sum path is present\n");
            else
                printf("\nroot to leaf sum path is not present\n");
            break;
        case 14:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            if(isBST(root[r-1],INT_MIN,INT_MAX))
                printf("Tree is a Binary Search Tree\n");
            else
                printf("Tree is not a Binary Search Tree\n");
            break;
        case 15:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            MorrisInorderTraversal(root[r-1]);
            printf("\n");
            break;
        case 16:
            printf("\nEnter 2 root no from 1 to 10\n");
            scanf("%d%d",&r1,&r2);
            if(sametreecheck(root[r1-1],root[r2-1]))
                printf("\nboth are same tree\n");
            else
                printf("\nnot same tree\n");
            break;
        case 17:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nEnter two node data\n");
            scanf("%d%d",&data1,&data2);
            temp=leastcommonancestor(root[r-1],data1,data2);
            if(temp)
                printf("\nleast common ancestor is %d\n",temp->data);
            else
                printf("\nleast common ancestor doesn't exist\n");
            break;
        case 18:
            printf("\nEnter 2 root no from 1 to 10\n");
            scanf("%d%d",&r1,&r2);
            if(isMirrorImage(root[r1-1],root[r2-1]))
                printf("\nMirror Image of each other\n");
            else
                printf("\nnot Mirror Image of each other\n");
            break;
        case 19:
            printf("\nEnter root no from 1 to 10\n");
            scanf("%d",&r);
            printf("\nDiameter of tree = %d\n",diameter(root[r-1]));
            break;
        case 20:
            printf("\nEnter tree root no. to be cloned\n");
            scanf("%d",&r);
            root[9]=Tree_clone(root[r-1]);
            levelorder(root[9]);
            break;
        case 21:
            c=0;
            printf("\nEnter tree root no. for viewing\n");
            scanf("%d",&r);
            View_Tree(root[r-1]);
            printf("\n");
            break;
        default:
            printf("\nyou entered wrong a choice\n\n");
        }
    }

    return 0;
}

void treetraversal(struct node *root)
{
    int choice;
    printf("\nENTER\n1 for inorder traversal\n2 for preorder traversal\n3 for postorder traversal\n4 levelorder traversal\n5 boundary traversal\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nyour inorder tree traversed data are :\n");
        inorder(root);
        printf("\n");
        break;
    case 2:
        printf("\nyour preorder tree traversed data are :\n");
        preorder(root);
        printf("\n");
        break;
    case 3:
        printf("\nyour postorder tree traversed data are :\n");
        postorder(root);
        printf("\n");
        break;
    case 4:
        printf("\nyour levelorder tree traversed data are :\n");
        levelorder(root);
        printf("\n");
        break;
    case 5:
        boundarytraversal(root);
        printf("\n");
        break;
    }
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("%d\n",root->data);
    inorder(root->rchild);
}

/*
//iterative inorder traversal algorithm
void iterativeinorder(struct node *root)
{
    if(root==NULL)
        return;
    Stack s1; //let Stack s1 is created and implemented using linked list
    while(1)
    {
        if(root!=NULL)
        {
            push(s1,root);
            root=root->lchild;
        }
        else
        {
            if(isEmpty(s1))
                break;
            else
            {
                root=pop(s1);
                printf("%d\n",root->data);
                root=root->rchild;
            }
        }
    }
}
*/


void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

/*
//iterative preorder traversal algorithm
void iterativepreorder(struct node *root)
{
    if(root==NULL)
        return;
    Stack s1; // let Stack s1 is created and implemented using linked list
    push(s1,root);
    while(!isEmpty(s1))
    {
        root=pop(s1);
        prinf("%d\n",root->data);
        if(root->rchild)
            push(s1,root->rchild);
        if(root->lchild)
            push(s1,root->lchild);
    }
}
*/

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\n",root->data);
}

/*
//iterative postorder traversal algorithm
void iterativepostorder(struct node *root)
{
    if(root==NULL)
        return root;
    Stack s1,s2; // let two stacks s1 and s2 is created and implemented using linked list
    push(s1,root);
    while(!isEmpty(s1))
    {
        root=pop(s1);
        push(s2,root);
        if(root->lchild)
            push(s1,root->lchild);
        if(root->rchild)
            push(s1,root->rchild);
    }
    while(!isEmpty(s2))
        printf("%d\n",(pop(s2))->data);
}
*/

///*
void levelorder(struct node *root)
{
    if(root==NULL)
    {
        printf("\n tree is empty\n");
        return;
    }
    struct queue
    {
        struct node *qdata;
        struct queue *next;
    };
    struct queue *front=NULL;
    struct queue *qnode=(struct queue *)malloc(sizeof(struct queue));
    qnode->qdata=root;
    qnode->next=NULL;
    front=qnode;
    while(front!=NULL)
    {
        qnode=front;
        printf("%d\n",qnode->qdata->data);
        if(qnode->qdata->lchild!=NULL)
        {
            struct queue *curr=front;
            while(curr->next!=NULL)
                curr=curr->next;
            struct queue *qlast=(struct queue *)malloc(sizeof(struct queue));
            qlast->qdata=qnode->qdata->lchild;
            qlast->next=NULL;
            curr->next=qlast;
        }
        if(qnode->qdata->rchild!=NULL)
        {
            struct queue *curr=front;
            while(curr->next!=NULL)
                curr=curr->next;
            struct queue *qlast=(struct queue *)malloc(sizeof(struct queue));
            qlast->qdata=qnode->qdata->rchild;
            qlast->next=NULL;
            curr->next=qlast;
        }
        front=front->next;
    }
}
//*/


void boundarytraversal(struct node *root)
{
    if(!root)
        return;
    printf("\nboundary traversal of tree is :\n");
    printf("%d\n",root->data);
    leftboundarytraversal(root->lchild);
    leaftraversal(root);
    rightboundarytraversal(root->rchild);
}
void leftboundarytraversal(struct node *root)
{
    if(!root)
        return;
    while(root->lchild!=NULL)
    {
        printf("%d\n",root->data);
        root=root->lchild;
    }
}
void leaftraversal(struct node *root)
{
    if(!root)
        return;
    if(root->lchild==NULL && root->rchild==NULL)
        printf("%d\n",root->data);
    leaftraversal(root->lchild);
    leaftraversal(root->rchild);
}
void rightboundarytraversal(struct node *root)
{
    if(root)
    {
        struct list
        {
            int value;
            struct list *next;
        };
        struct list *start=NULL,*temp;
        while(root->rchild!=NULL)
        {
            temp=(struct list*)malloc(sizeof(struct list));
            temp->value=root->data;
            temp->next=start;
            start=temp;
            root=root->rchild;
        }
        while(start!=NULL)
        {
            printf("%d\n",start->value);
            start=start->next;
        }
    }
    return;
}

/*
//iterative level by level printing algorithm
void levelbylevelorderedprinting(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    EnQueue(root);
    EnQueue(NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue();
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(curr);
            printf("\n");
        }
        else
        {
            printf("%d",curr->data);
            if(curr->lchild)
                EnQueue(curr->lchild);
            if(curr->rchild)
                EnQueue(root->rchild);
        }
        prev=curr;
    }
}
*/

/*
//right view algorithm
void rightview(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    EnQueue(root);
    EnQueue(NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue();
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(curr);
            printf("\n");
        }
        else
        {
            if(front(q)==NULL)//front(q) returns front item from the queue
                printf("%d",curr->data);
            if(curr->lchild)
                EnQueue(curr->lchild);
            if(curr->rchild)
                EnQueue(root->rchild);
        }
        prev=curr;
    }
}
*/


/*
//left view algorithm
void rightview(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    EnQueue(root);
    EnQueue(NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue();
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(curr);
            printf("\n");
        }
        else
        {
            if(prev==NULL)
                printf("%d",curr->data);
            if(curr->lchild)
                EnQueue(curr->lchild);
            if(curr->rchild)
                EnQueue(root->rchild);
        }
        prev=curr;
    }
}
*/



/*
//reverse level reverse order printing algorithm
void reverselevelbylevelreverseorderprinting(struct node *root)
{
    if(root==NULL)
        return;
    Queue q; // let a queue be created and implemented using linked list
    Stack s; // let a stack s be created and implemented using linked list
    EnQueue(q,root);
    EnQueue(q,NULL);
    struct node *curr,*prev;
    prev=NULL;
    while(!isEmpty(q))
    {
        curr=DeQueue(q);
        if(prev==curr)
            break;
        else if(curr==NULL)
        {
            Enqueue(q,curr);
            push(s,curr);
        }
        else
        {
            push(s,curr);
            if(curr->lchild)
                EnQueue(q,curr->lchild);
            if(curr->rchild)
                EnQueue(q,root->rchild);
        }
        prev=curr;
    }
    pop(s);
    while(!isEmpty(s))
    {
        curr=pop(s);
        if(curr==NULL)
            printf("\n");
        else
            printf("%d ",curr->data);
    }
}
*/

/*
//spiral order printing algorithm
void spiralorderprinting(struct node *root)
{
    if(root==NULL)
        return;
    Stack s1,s2; // let 2 stacks be created
    push(s1,root);
    struct node *curr;
    while( !isEmpty(s1) || !isEmpty(s2) )
    {
        while(!isEmpty(s1))
        {
            curr=pop(s1);
            printf("%d",curr->data);
            if(curr->lchild)
                push(s2,curr->lchild);
            if(curr->rchild)
                push(s2,curr->rchild);
        }
        printf("\n");
        while(!isEmpty(s2))
        {
            curr=pop(s2);
            printf("%d",curr->data);
            if(curr->rchild)
                push(s1,curr->rchild);
            if(curr->lchild)
                push(s1,curr->lchild);
        }
        printf("\n");
    }
}
*/

/*
void levelorder(struct node* root)//recursively
{
    if(root==NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
	int h = height(root);
	int i;
	for (i=1; i<=h; i++)
		printGivenLevel(root, i);
}
*/

///* Print nodes at a given level */
/*
void printGivenLevel(struct node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->lchild, level-1);
		printGivenLevel(root->rchild, level-1);
	}
}
*/

struct node *addbeforeroot(struct node *root, int n)
{
    struct node *temp;
    int choice;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=n;
    printf("\nENTER\n1 to make previous root as left child\n2 to make previous root as right child\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        temp->lchild=root;
        temp->rchild=NULL;
        break;
    case 2:
        temp->lchild=NULL;
        temp->rchild=root;
        break;
    default:
        printf("\nyou entered a wrong choice\n");
    }
    return temp;
}

void addatleftend(struct node *root,int n)//root!=NULL
{
    if(root->lchild==NULL)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=n;
        temp->lchild=NULL;
        temp->rchild=NULL;
        root->lchild=temp;
        return;
    }
    addatleftend(root->lchild,n);//recursive
}

void addatrightend(struct node *root,int n)//root!=NULL
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->lchild=NULL;
    temp->rchild=NULL;
    while(root->rchild!=NULL)//iterative
    {
        root=root->rchild;
    }
    root->rchild=temp;
}

struct node *search(struct node *root,int n)
{
    struct node *temp1,*temp2;
    if(root==NULL || root->data==n)
        return root;
    temp1=search(root->lchild,n);
        if(temp1!=NULL)
            return temp1;
    temp2=search(root->rchild,n);
        if(temp2!=NULL)
            return temp2;
    return NULL;
}

struct node *addafterasleftchild(struct node *root,int data,int n)
{
    struct node *temp1=NULL;
    temp1=search(root,data);
    //printf("%d",temp1->data);
    if(temp1==NULL)
    {
        printf("\ndata %d is not found in tree\n",data);
        return root;
    }
    else
    {
        struct node *temp;
        int choice;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=n;

        printf("\nENTER\n1 to make left child of given node as left child of new node\n2 to make left child of given node as right child of new node\n");
        scanf("%d",&choice);
        struct node *h;
        switch(choice)
        {
        case 1:
            temp->lchild=temp1->lchild;
            temp1->lchild=temp;
            temp->rchild=NULL;
            break;
        case 2:
            temp->rchild=temp1->lchild;
            temp1->lchild=temp;
            temp->lchild=NULL;
            break;
        default:
            printf("\nyou entered a wrong choice\n");
        }
    }
    return root;
}

struct node *addafterasrightchild(struct node *root,int data,int n)
{
struct node *temp1=NULL;
    temp1=search(root,data);
    if(temp1==NULL)
    {
        printf("\ndata %d is not found in tree\n",data);
        return;
    }
    else
    {
        struct node *temp;
        int choice;
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=n;
        printf("\nENTER\n1 to make right child of given node as left child of new node\n2 to make right child of given node as right child of new node\n");
        scanf("%d",&choice);
        struct node *h;
        switch(choice)
        {
        case 1:
            temp->lchild=temp1->rchild;
            temp1->rchild=temp;
            temp->rchild=NULL;
            break;
        case 2:
            temp->rchild=temp1->rchild;
            temp1->rchild=temp;
            temp->lchild=NULL;
            break;
        default:
            printf("\nyou entered a wrong choice\n");
        }
    }
    return root;
}

/*size of a tree
void countnode(struct node *root)
{
    if(root==NULL)
        return;
    nodecount++;
    countnode(root->lchild);
    countnode(root->rchild);
}
*/

///*size of a tree
int countnode(struct node *root)
{
    if(root==NULL)
        return 0;
    return 1+countnode(root->lchild)+countnode(root->rchild);
}
//*/

void topview(struct node *root)
{
    if(root)
    {
        flag=1;
        if(root->lchild)
        {
            root->lchild->rchild=NULL;
            topview(root->lchild);
        }
        printf("%d ",root->data);
        if(root->rchild)
        {
            root->rchild->lchild=NULL;
            topview(root->rchild);
        }
    }
}
//side views can be implemented using level order traversal technique
//top view, bottom view, vertical sum cal be implemented using vertical order
//traversal using the concept of  extreme left and extreme right width of tree


int height(struct node *root)
{
    if(root==NULL)
        return 0;
    return (height(root->lchild)+1 > height(root->rchild)+1) ? height(root->lchild)+1 : height(root->rchild)+1;
}

int maxdata(struct node *root)
{
    if(root==NULL)
        return INT_MIN;
    return (root->data>maxdata(root->lchild))?((root->data>maxdata(root->rchild))?root->data:maxdata(root->rchild)):((maxdata(root->lchild)>maxdata(root->rchild))?maxdata(root->lchild):maxdata(root->rchild));
    //return maximum of root->lchild, root->rchild and root
}

int sametreecheck(struct node *root1, struct node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    return (((root1->data==root2->data)
            && sametreecheck(root1->lchild, root2->lchild))
            && sametreecheck(root1->rchild, root2->rchild));
}


struct node *deletegivennode(struct node *root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root->lchild;
        //return root->rchild; //user's choice
        //one half subtree is deleted
    else if(root->lchild && root->lchild->data==key)
    {
        root->lchild=root->lchild->lchild;
        return root;
        //root->lchild=root->lchild->rchild; //user's choice
        //one half subtree is deleted
    }
    else if(root->rchild && root->rchild->data==key)
    {
        root->rchild=root->rchild->rchild;
        return root;
        //root->rchild=root->rchild->lchild; //user's choice
        //one half subtree is deleted
    }
    deletegivennode(root->lchild,key);
    deletegivennode(root->rchild,key);

    return root;
}

int roottoleafsumcheck(struct node *root, int sum)
{
    int left,right;
    if(root==NULL)
        return 0;
    if(root->lchild==NULL && root->rchild==NULL)
    {
        if(sum-root->data==0)
        {
            printf("%d<-",root->data);
            return 1;
        }
        else
            return 0;
    }
    left=roottoleafsumcheck(root->lchild,sum-root->data);
    right=roottoleafsumcheck(root->rchild,sum-root->data);
    if(left || right)
    {
        printf("%d<-",root->data);
        return 1;
    }
    else
        return 0;
}

int isBST(struct node *root, int minm, int maxm)
{
    if(root==NULL)
        return 1;
    if(root->data<=minm || root->data>=maxm)
        return 0;
    return isBST(root->lchild,minm,root->data) && isBST(root->rchild,root->data,maxm) ;
}

void MorrisInorderTraversal(struct node *root)
{
    struct node *curr,*predecessor;
    if(root==NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    printf("\nyour Morris Inorder Traversal are :\n");
    curr=root;
    while(curr!=NULL)
    {
        if(curr->lchild==NULL)
        {
            printf("%d\n",curr->data);
            curr=curr->rchild;
        }
        else
        {
            predecessor=curr->lchild;
            while(predecessor->rchild!=NULL && predecessor->rchild!=curr)
                predecessor=predecessor->rchild;
            if(predecessor->rchild==NULL)
            {
                predecessor->rchild=curr;
                curr=curr->lchild;
            }
            else
            {
                predecessor->rchild=NULL;
                printf("%d\n",curr->data);
                curr=curr->rchild;
            }
        }
    }
}

//struct node *leastcommonancestor(struct node *root, struct node *node1, struct node *node2)
struct node *leastcommonancestor(struct node *root, int node1, int node2)
{
    struct node *lt,*rt;
    if(root==NULL)
        return NULL;
    if(root->data==node1 || root->data==node2)
        return root;
    lt=leastcommonancestor(root->lchild,node1,node2);
    rt=leastcommonancestor(root->rchild,node1,node2);
    if(lt && rt)
        return root;
    else if(!lt && !rt)
        return NULL;
    else
        return (lt)?lt:rt;
}


int isMirrorImage(struct node *root1, struct node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    return root1->data==root2->data && (isMirrorImage(root1->lchild,root2->rchild) && isMirrorImage(root1->rchild,root2->lchild));
}


int diameter(struct node *root)
{
    int lt,rt,ld,rd;
    if(root==NULL)
        return 0;
    lt=height(root->lchild);
    rt=height(root->rchild);
    ld=diameter(root->lchild);
    rd=diameter(root->rchild);
    return Max(lt+rt+1,Max(ld,rd));
}

int Max(int x, int y)
{
    return (x>y)?x:y;
}


struct node *Tree_clone(struct node* root)
{
    if(!root)
        return NULL;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=root->data;
    temp->lchild=Tree_clone(root->lchild);
    temp->rchild=Tree_clone(root->rchild);
    return temp;
}

void View_Tree(struct node *root)
{
	int min = 0, maxm = 0, choice;
	struct list *head;
	printf("\nEnter \n1 for top View\n2 for bottom view\n");
	scanf("%d",&choice);
	switch(choice)
	{
    case 1:
        head=NULL;
        printf("\ntop view is : ");
        head=findMinMaxTopView(root, head, &min, &maxm, 0, 0);
        printViews(head);
        printf("\n");
        break;
    case 2:
        head=NULL;
        printf("\nbottom view is : ");
        head=findMinMaxBottomView(root, head, &min, &maxm, 0, 0);
        printViews(head);
        printf("\n");
        break;
    default:
        printf("\nyou entered a wrong choice\n");
	}
}
struct list *findMinMaxTopView(struct node *root, struct list *head, int *min, int *maxm, int hd, int lv)
{
    struct list* curr;
	if (root == NULL) return head;
	if(c==0)
	{
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    temp->next=head;
	    head=temp;
	    c++;
	}
	if (hd < *min)
	{
	    *min = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    temp->next=head;
	    head=temp;
	}
	else if (hd > *maxm)
	{
	    *maxm = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    curr=head;
	    while(curr->next!=NULL)
	        curr=curr->next;
	    curr->next=temp;
	    temp->next=NULL;
	}
	else
    {
        curr=head;
	    int z=*min;
	    while(z!=hd)
	    {
	        z++;
	        curr=curr->next;
	    }
	    if(lv<curr->levl)
        {
            curr->val=root->data;
            curr->levl=lv;
        }
    }
	head=findMinMaxTopView(root->lchild, head, min, maxm, hd-1, lv+1);
	head=findMinMaxTopView(root->rchild, head, min, maxm, hd+1, lv+1);
	return head;
}

struct list *findMinMaxBottomView(struct node *root, struct list *head, int *min, int *maxm, int hd, int lv)
{
    struct list* curr;
	if (root == NULL) return head;
	if(c==0)
	{
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    temp->next=head;
	    head=temp;
	    c++;
	}
	if (hd < *min)
	{
	    *min = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    temp->next=head;
	    head=temp;
	}
	else if (hd > *maxm)
	{
	    *maxm = hd;
	    struct list *temp=(struct list*)malloc(sizeof(struct list));
	    temp->val=root->data;
	    temp->levl=lv;
	    curr=head;
	    while(curr->next!=NULL)
	        curr=curr->next;
	    curr->next=temp;
	    temp->next=NULL;
	}
	else
    {
        curr=head;
	    int z=*min;
	    while(z!=hd)
	    {
	        z++;
	        curr=curr->next;
	    }
	    if(lv>curr->levl)
        {
            curr->val=root->data;
            curr->levl=lv;
        }
    }
	head=findMinMaxBottomView(root->lchild, head, min, maxm, hd-1, lv+1);
	head=findMinMaxBottomView(root->rchild, head, min, maxm, hd+1, lv+1);
	return head;
}

void printViews(struct list *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}
