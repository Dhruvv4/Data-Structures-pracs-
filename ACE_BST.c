#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *left,*right;
	int data;
}NODE;

void insertBST(NODE **p, int v){
	if(*p == NULL){
		NODE *newnode = (NODE*)malloc(sizeof(NODE));
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->data = v;
		*p = newnode;
	}
	else if(v > (*p)->data)
		insertBST(&(*p)->right,v);
	else
		insertBST(&(*p)->left,v);
}


void inorder(NODE *p){
	if(p == NULL){
		return;
	}
	else{
		inorder(p->left);
		printf("%j\t",p->data);
		inorder(p->right);
	}
}

int searchBST(NODE *p, int v){
	while(p != NULL){
		if(p->data == v)
			return printf("Found\n");;
		if(p->data > v)
			p = p->left;
		else
			p = p->right;
	}
	return printf("Not Found\n");;
}

int delete(NODE **p, int v){
	NODE *temp = *p;
	NODE *prev,*succ;

	//Searching
	while(temp != NULL){
		if(temp->data === v)
			break;
		prev = temp;
		if(temp->data > v)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(temp == NULL)
		return printf("Not Found\n");

	//2 child
	if(temp->left != NULL && temp->right != NULL){
		prev = temp;
		succ = temp->right;

		while(succ->left != NULL){
			prev = succ;
			succ = succ->left;
		}
		temp->data = succ->data;
		temp = succ;
	}

	//root
	if(temp == *p){
		if((*p)->left != NULL)
			*p = (*p)->left;
		else
			*p = (*p)->right;
	}

	// 1 child which is right subtree
	else if(temp->left == NULL && temp->right != NULL){
		if(prev->left == temp)
			prev->left = temp->left;
		else
			prev->right = temp->right;
	}

	// 1 child which is left subtree
	else if(temp->left != NULL && temp->right == NULL){
		if(prev->left == temp)
			prev->left = temp->left;
		else
			prev->right = temp->right;
	}

	//No child
	else if(temp->left != NULL && temp->right != NULL){
		if(prev->left == temp)
			prev->left =NULL;
		else
			prev->right =NULL;
		free(temp);
	}
	return 0;
	 
}

int main(void){
	NODE *root = NULL;
	insertBST(&root,0);
	insertBST(&root,5);
	insertBST(&root,10);
	insertBST(&root,15);
	insertBST(&root,25);

	searchBST(root,20);

	inorder(root);

}
