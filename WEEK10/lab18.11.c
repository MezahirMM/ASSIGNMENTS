struct Node{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value){
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int maxSum(struct Node* temp){
	if (temp == NULL)
		return 0;
	int left1 = maxSum(temp->left);
	int right1 = maxSum(temp->right);
	if(left1 < right1)
		return right1 + temp->value;
	else
		return left1 + temp->value;

}

int main(){
	struct Node* root = newNode(1);
	root->left = newNode(5);
	root->right = newNode(10);
	root->left->left = newNode(20);
	root->left->left->left = newNode(999);
	root->left->right = newNode(4);
	root->right->right = newNode(20);
	root->right->right->right = newNode(15);
	root->right->left = newNode(21);
	root->right->left->left = newNode(13);

	printf("maximum sum of tree nodes: %d\n", maxSum(root));

	return 0;
}
