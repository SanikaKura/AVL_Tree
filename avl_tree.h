#pragma once
#include <vector>
using namespace std;

struct Node{
    string name;
    string ufid;
    Node* left;
    Node* right;
    Node() : name(""), ufid("0"), left(nullptr), right(nullptr) {}

};

class AVLTree {
private:

public:
    Node* root = nullptr;
    Node* Insert(string name, string ufid);
    Node* InsertHelper(Node* node, string name, string ufid);
    Node* find_imbalanced(Node* root_node, Node* node_input);
    //bool idExistHelper(string id_);
    AVLTree() : root() {}
};

struct Node* newnode(string name1, string ufid1){
    struct Node* temp = new struct Node;
    temp->name = name1;
    temp->ufid = ufid1;
    temp->left = temp->right = nullptr;
    return temp;
};

int count_val = 0;
int nameExists(Node* node, string name_){
    if(node == nullptr){
    }
    else {
        if (node->name == name_){
            count_val += 1;
        }
        else {
            nameExists(node->left, name_);
            nameExists(node->right, name_);
        }
    }
    return count_val;
}

bool nameExistsHelper(Node* root, string name_){  //bool for if node exists based on name
    count_val = 0;
    if (nameExists(root, name_) > 0){
        return true;
    }
    else {return false;}
}


void isName(Node* node, string nameKey){ // searches every node until finds given name
    if(node == nullptr){
        // returningNumber +=0;
    }
    else {
        if (node->name == nameKey) { cout << stoi(node->ufid) << endl ; }  // cout << stoi(node->ufid) << endl; }
        else {
            isName(node->left, nameKey);
            isName(node->right, nameKey);
        }
    }
}

string in = "";
void traversal(Node* node){

    if(node == nullptr){
        //cout << "";
    }
    else {
        traversal(node->left);
        in.append(node->name);
        in.append(", ");
        traversal(node->right);
    }
}

string inorderHelper(Node* root){ /// produces a comma seperated string of inorder traversal
    in = "";
    traversal(root);
    return in ;
};


string IDin = "";
void traversalID(Node* node){ /// helper for remove inorder function -> makes inorder list of ids

    if(node == nullptr){
        //cout << "";
    }
    else {
        traversalID(node->left);
        IDin.append(node->ufid);
        IDin.append(", ");
        traversalID(node->right);
    }
}

string inorderHelperID(Node* root){ /// helper for helper
    IDin = "";
    traversalID(root);
    return IDin ;
};




string pre = "";
void preorder(Node* node){

    if(node == nullptr){
        //cout << "";
    }
    else {
        pre.append(node->name);
        pre.append(", ");
        //cout << node->ufid<< ", ";
        preorder(node->left);
        preorder(node->right);
    }
}

string preorderHelper(Node* root){
    pre = "";
    preorder(root);
    return pre ;
};


string p = "" ;
void postorder(Node* node){

    if(node == nullptr){
    }
    else {
        postorder(node->left);
        postorder(node->right);
        p.append(node->name);
        p.append(", ");
    }
}

string postorderHelper(Node* root){
    p = "";
    postorder(root);
    return p ;
};


Node* find_parent(Node* parent, Node* search){
    int parentLeft = stoi(parent ->left ->ufid);
    int parentRight = stoi(parent ->right ->ufid);
    int parentId = stoi(parent->ufid);
    int searchId = stoi(search->ufid); //converts ufid values to ints for proper comparison

    if (parentLeft == searchId || parentRight ==searchId){ //if one of the parent's child nodes == given id return parent
        return parent;
    }
    else {
        if (searchId > parentId){
            Node* newparent = parent ->right;
            find_parent(newparent, search);
        }
        if (searchId < parentId){
            Node* newparent = parent ->left;
            find_parent(newparent, search);
        }
    }
}


    Node* deleteNode(Node* node, string ufid_)
    {
        int uf = stoi (ufid_);
        if (node == nullptr)
        {return node;}

        if (stoi(node->ufid) > uf) {
            node->left = deleteNode(node->left, ufid_);
            return node;
        }
        else if (stoi(node->ufid)< uf) {
            node->right = deleteNode(node->right, ufid_);
            return node;
        }

        if (node->left == nullptr) {
            Node* rightchild = node->right;
            delete node;
            return rightchild;
        }
        else if (node->right == nullptr) {
            Node* leftchild = node->left;
            delete node;
            return leftchild;
        }

        else {
            Node* parent = node; Node* child = node->right;
            while (child->left != NULL) {
                parent = child;
                child = child->left;
            }
            if (parent != node)
                parent->left = child->right;
            else
                parent->right = child->right;

            node->ufid = child->ufid;
            node->name = child->name;
            delete child;
            return node;
        }
    }


int count_ = 0;
int id_exists(Node* node, string id){
    if(node == nullptr){
    }
    else {
        if (node->ufid == id){
            //cout << "true";
            count_val += 1;
            //return true;
        }
        else {
            //cout << "__________" << node->name << "__________";
            id_exists(node->left, id);
            id_exists(node->right, id);
        }
    }
    return count_;
}


bool id_existsBool(Node* root, string ufid_){

    if (root == nullptr){return false;}
    if (root->ufid == ufid_){return true;}
    if (stoi(root->ufid) > stoi(ufid_)){return id_existsBool(root->left, ufid_);}
    //return id_existsBool(root->right, ufid_);

}


void findKey(Node* node, string id_){ //recursive comparison to nodes
    if(node == nullptr){

    }
    else {
        if (node->ufid == id_) { cout << node->name << endl ; }  // cout << stoi(node->ufid) << endl; }
        else {
            findKey(node->left, id_);
            findKey(node->right, id_);
        }
    }
}



void print_left_tree(Node* node){
    if(node == nullptr){
        cout << "";
    }
    else {
        cout << node->ufid<< " ";
        print_left_tree(node->left);
    }
}

void print_right_tree(Node* node){
    if(node == nullptr){
        cout << "";
    }
    else {
        cout << node->ufid<< " ";
        print_right_tree(node->right);
    }
}


int height(Node* node){
    if (node == nullptr){
        return 0;
    }
    else {
        int l_height = height(node ->left);
        int r_height = height(node ->right);

        if (l_height > r_height){return l_height + 1;}
        else {return (r_height +1);}
    }
}

int balance(Node* node){ // function returns the balance of a node
    int left_height; int right_height;
    if (node -> left == nullptr) {
        left_height = 0;
    }
    else {left_height = height(node ->left); }
    if (node -> right == nullptr) {
        right_height = 0;
    }
    else{right_height = height(node -> right) ;}

    int result = (left_height - right_height);
    return result;
}



Node* temp = new Node();
Node* AVLTree::find_imbalanced(Node* root_node, Node* node_input){          /// this function takes a freshly inserted node and returns the parent until a ndoe is imbalanced
    int value = stoi(node_input -> ufid);
    int rootval = stoi(root_node -> ufid);
    if (stoi(root -> ufid) == value) {return root_node; }

    if (value < rootval){
        int b = balance(root_node);
        //cout << node_input->name <<node_input->name << " BALACE of b:  " << b << endl;
        root_node = root_node -> left;
        if ((b > 1) || (b < -1)){temp = root_node; return temp; }
        //root_node = root_node -> left;
        find_imbalanced(root_node, node_input);
    }

    if (value > rootval){
        int b = balance(root_node); //cout <<node_input->name << " balance of b:  " << b << endl;
        root_node = root_node -> right;
        if ((b > 1) || (b < -1)){temp = root_node; return temp;}
        //root_node = root_node -> right;
        find_imbalanced(root_node, node_input);
    }
    if (value == rootval) {
        if (stoi(temp->ufid) == 0) {
            return nullptr;
        } else {
            return temp;
        }
    }
    return nullptr;
} ///shes gonna return a nullptr if the tree is balanced

Node* rightRotation(Node* node){ //helper function for left left case
    Node* first = node -> left;
    Node* second = first -> right;

    first->right = node;
    node -> left = second;
    return first;
}

Node* leftRotation(Node* node){
    Node* rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;
    return rightChild;
}




Node* AVLTree::InsertHelper(Node* node, string name_, string ufid_){
    temp -> ufid = "0";

    if (node == nullptr)
    {
        Node* noden= new Node();///places new node !
        noden->name = name_;
        noden->ufid = ufid_;
        return noden;
    }

    if (stoi(ufid_) > stoi(node->ufid))
    {
        node -> right = InsertHelper(node->right, name_, ufid_);
    }

    else if (stoi(ufid_) < stoi(node->ufid))
    {
        node -> left = InsertHelper(node->left, name_, ufid_);
    }

    int balanceFactor = balance(node);

    if (balanceFactor > 1){
        if (stoi(ufid_) < stoi(node->left->ufid)){ //left left
            if (node == root ){root = rightRotation(node); return root;} ///reassigns root if root changes
            else return rightRotation(node);
        }
        else if (stoi(ufid_) > stoi(node->left->ufid)){ //left right
            node->left = leftRotation(node->left);
            if (node == root ){ root = rightRotation(node); return root; }
            else return rightRotation(node);
        }
    }

    if (balanceFactor < -1){
        if (stoi(ufid_) > stoi(node->right->ufid)) {//right right
            if (node == root ){ root = leftRotation(node); return root;}
            else return leftRotation(node);
        }
        else if (stoi(ufid_) < stoi(node->right->ufid)){ //right left
            node->right = rightRotation(node->right);
            if (node == root ){ root = leftRotation(node); return root;}
            else return leftRotation(node);
        }
    }

    return node;

}


