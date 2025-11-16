//NGETEST GIT DI UBUNTU AJA SI

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct Node{
    string data;
    Node *left, *right;
};

Node* newNode(string data);
Node* inputTree(const string& path);
void traversePostOrder(Node* node, string &postfix);
void evaluatePostfix(Node* node);

int main(){
    Node* root = inputTree("root");
    cout << endl;
    evaluatePostfix(root);

    return 0;
}

Node* newNode(string data){
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* inputTree(const string& path){
    string data;
    cout << "Masukkan data untuk " << path << " (atau kosongkan untuk NULL): ";
    getline(cin, data);
    if (data.empty()) {
        return NULL;
    }

    Node* node = newNode(data);
    node->left = inputTree(path + "->left");
    node->right = inputTree(path + "->right");
    return node;
}

void traversePostOrder(Node* node, string &postfix){
    if (node == NULL)
        return;
    traversePostOrder(node->left, postfix);
    traversePostOrder(node->right, postfix);
    postfix += node->data + " ";
}

void evaluatePostfix(Node* node){
    string postfix = "";
    traversePostOrder(node, postfix);
    cout << "Ekspresi dalam postfix: " << postfix << endl;
    
    stack<float> evaluate;
    istringstream iss(postfix);
    string token;
    
    while(iss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            if(evaluate.size() < 2) {
                cout << "Error: Tidak tersedia operand yang cukup untuk dioperasikan " << token << endl;
                return;
            }
            
            float operand2 = evaluate.top(); evaluate.pop();
            float operand1 = evaluate.top(); evaluate.pop();
            
            if(token == "+"){
                evaluate.push(operand1 + operand2);
            } else if(token == "-"){
                evaluate.push(operand1 - operand2);
            } else if(token == "*"){
                evaluate.push(operand1 * operand2);
            } else if(token == "/"){
                if(operand2 == 0) {
                    cout << "Error: Pembagian dengan nol" << endl;
                    return;
                }
                evaluate.push(operand1 / operand2);
            }
        } else {
            try {
                evaluate.push(stof(token));
            } catch(const exception& e) {
                cout << "Error: Operator tidak valid " << token << endl;
                return;
            }
        }
    }

    if(evaluate.size() != 1) {
        cout << "Error: Ekspresi tidak valid (terlalu banyak operand tersisa)" << endl;
        return;
    }
    
    cout << "Evaluation Result: " << evaluate.top() << endl;
}