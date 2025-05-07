#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;


// Tree
struct Node {
    string data;
    Node* left;
    Node* right;

    // Konstruktor node tree
    Node (string value) {
       data = value;
       left = nullptr;
       right = nullptr;
    }
};
void postorder(Node* root);


// Stack dengan Linked List
struct STACK {
	string data;
    STACK* prev;
	STACK* next;
};
    STACK* head = nullptr;
    STACK* tail = nullptr;
// Fungsi
    void PUSH ( string value );
    void POP ();
    void CALCULATE (Node* root);
    void EVALUATE (Node* root);


// Stack dengan Array
const int SIZE = 20;
string stack1[SIZE];
   int top = -1;
// Fungsi 
   void push ( string value );
   void pop ();
   void calculate (Node* root);
   void evaluate (Node* root);


// Stack dari Library
void traversePostOrder(Node* node, string &postfix);
void evaluatePostfix(Node* node);


int main ()
{
	
	cout << "\nTree Image 1 " << endl;
	cout << "https://images.app.goo.gl/stnP5ymXf5PH9gKh8";
	cout << endl;
	
    Node* root = new Node ("+");
	root -> left = new Node ("*");
	root -> left -> left = new Node ("-");
	root -> left -> left -> left = new Node ("*");
	root -> left -> left -> left -> left = new Node ("5");
	root -> left -> right = new Node ("+");
	root -> left -> right -> left = new Node ("2");
	root -> left -> right -> right = new Node ("7");
	root -> left -> left -> right = new Node ("7");
	root -> left -> left -> left -> right = new Node ("+");
	root -> left -> left -> left -> right -> left = new Node ("2");
	root -> left -> left -> left -> right -> right = new Node ("2");
	root -> right = new Node ("-");
	root -> right -> right = new Node ("*");
	root -> right -> left = new Node ("10");
	root -> right -> right -> left = new Node ("+");
	root -> right -> right -> left -> left = new Node ("6");
	root -> right -> right -> left -> right = new Node ("8");
	root -> right -> right -> right = new Node ("-1");
	
	cout << endl << endl;
	EVALUATE(root);
	evaluatePostfix(root);
	
	cout << endl;
	evaluate(root);
	
    cout << "\nTree Image 2" << endl;
	cout << "https://images.app.goo.gl/xc21np1UXhYWehde7";
	cout << endl;
	
	Node* root2 = new Node ("+");
	root2 -> left = new Node ("3");
	root2 -> right = new Node ("*");
	root2-> right -> left = new Node ("+");
	root2 -> right -> left -> left = new Node ("5");
	root2 -> right -> left -> right = new Node ("9");
	root2 -> right -> right = new Node ("2");
	
	cout << endl << endl;
	EVALUATE(root2);
	
	evaluatePostfix(root2);

	cout << endl;
	evaluate(root2);
	
	
    // Level 1 (Root)
    Node* root4 = new Node("+");

   // Level 2
   root4->left = new Node("/");
   root4->right = new Node("*");

   // Level 3
   root4->left->left = new Node("*");
   root4->left->right = new Node("-");

   root4->right->left = new Node("5");
   root4->right->right = new Node("-");

   // Level 4
   root4->left->left->left = new Node("2");
   root4->left->left->right = new Node("3");

   root4->left->right->left = new Node("2");
   root4->left->right->right = new Node("1");

   // root4->right->left->left = new Node(" ");
   // root4->right->left->right = new Node(" ");

   root4->right->right->left = new Node("4");
   root4->right->right->right = new Node("1");

    // Panggil fungsi evaluate
    cout << endl;
    cout << "Stack dengan Linked List" << endl;
	EVALUATE (root4);
	cout << "Stack dengan Array" << endl;
	evaluate (root4);
	cout << "Stack dengan STL" << endl;
    evaluatePostfix (root4);
    
  // Level 1 (Root)
  Node* root5 = new Node("+");

  // Level 2
  root5->left = new Node("*");
  root5->right = new Node("-");

  // Level 3
  root5->left->left = new Node("-");
  root5->left->right = new Node("+");

  root5->right->left = new Node("10");
  root5->right->right = new Node("*");

  // Level 4
  root5->left->left->left = new Node("*");
  root5->left->left->right = new Node("7");

  root5->left->right->left = new Node("2");
  root5->left->right->right = new Node("7");

  // root5->right->left->left = new Node(" ");
  // root5->right->left->right = new Node(" ");

  root5->right->right->left = new Node("+");
  root5->right->right->right = new Node("-1");

  // Level 5
  root5->left->left->left->left = new Node("5");
  root5->left->left->left->right = new Node("+");

  root5->right->right->left->left = new Node("6");
  root5->right->right->left->right = new Node("8");

  // Level 6
  root5->left->left->left->right->left = new Node("2");
  root5->left->left->left->right->right = new Node("2");

    // Panggil fungsi evaluate
    cout << endl;
    cout << "Stack dengan Linked List" << endl;
	EVALUATE (root5);
	cout << "Stack dengan Array" << endl;
	evaluate (root5);
	cout << "Stack dengan STL" << endl;
    evaluatePostfix (root5);


	return 0;
}


// xxxxxxxxx– Implementasi Fungsi Array –xxxxxxxxx 

// Postorder Traversal
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    } 
} 


// xxxxxxxxx– Implementasi Fungsi Linked List –xxxxxxxxx 

void PUSH ( string value ) {
	// Untuk memasukkan data dalam Linked List
	STACK* newstack = new STACK;
    newstack->data = value;
    newstack->prev = tail;
    newstack->next = nullptr;         
   if (tail) tail->next = newstack;
        else head = newstack;
   tail = newstack; }
      	 void ANSWER ( ) {
	// Hasil akhir akan terletak pada head
	cout << "Hasil = " << head -> data << endl; }
	
void POP () {
    // Untuk menghapus operand
        if ( tail -> prev ) tail -> prev -> next = nullptr;
        tail = tail -> prev; 
}

void CALCULATE ( Node* root ) {
    // Memanfaatkan postorder traversal dan fungsi rekursif    
  
    if ( root != nullptr ) {
    /* 1) Kunjungi sampai kiri dan kanan NULL untuk melanjutkan fungsi dan kembali ke panggilan fungsi sebelumnya / rekursif */
    CALCULATE ( root -> left );
    CALCULATE ( root -> right );
    
    // 2) Cek data dalam node dan eksekusinya
    
    //    a. Jika data bukan operator
    if ( root -> data != "+" &&
          root -> data != "-" &&
          root -> data != "*" && 
          root -> data != "/") 
          // Memasukkan data ke dalam Linked List
          PUSH ( root -> data ); 
      	
    //    b. Jika data adalah operator
    else {
           // Ambil 2 operand terakhir
          STACK* operand_1 = tail -> prev;
          STACK* operand_2 = tail;
          // Konversi data string menjadi integer
          int a = stod ( operand_1 -> data );
          int b = stoi ( operand_2 -> data );
          // Hasil operasi operand dengan operator
          int result;
          
          // Operasikan operand 1 dan 2
          if (root->data == "+") {
          	 result = a + b;
          	 cout << "\t" << a << " + " << b << " = " << result << "\n"; }
          else if (root->data == "-") {
          	 result = a - b;
          	 cout << "\t" << a << " - " << b << " = " << result << "\n"; }
          else if (root->data == "*") {
           	result = a * b;
           	cout << "\t" << a << " * " << b << " = " << result << "\n"; }
          else if (root->data == "/") {
           	if ( b == 0 ) {
                   cout << "Invalid, terdapat pembagian dengan 0 \n";
                   return; }
               result = a / b;
               cout << "\t" << a << " / " << b << " = " << result << "\n"; }
              
       
          // Menghapus kedua operand yang telah dioperasikan
          POP ();
          delete operand_1;
          POP ();
          delete operand_2;

          // Masukkan data dalam Linked List
          PUSH (to_string(result));
          
      } 
   }     
}
    
void EVALUATE (Node* root) {
	cout << "Postfix = ";
	postorder(root);
	cout <<"\nOperation" << endl;
	CALCULATE  (root);
	cout << "Result = " << tail -> data << endl << endl;
}


// xxxxxxxxx– Implementasi Fungsi Array –xxxxxxxxx 

void push ( string value ) {
    // Untuk menambahkan data dalam array
    if (top == SIZE - 1)
        cout << "Stack is Full, not enough space to calculate further\n";
    else {
        top++;
        stack1[top] = value;
    }
}

void pop () {
        top--;
}
	
void calculate ( Node* root ) {
    // Memanfaatkan postorder traversal dam fungsi rekursif    
 
    if (root != nullptr) {
    /* 1) Kunjungi sampai kiri dan kanan NULL untuk melanjutkan fungsi dan kembali ke panggilan fungsi sebelumnya / relursif */
        calculate ( root -> left );
        calculate ( root -> right );
      
    // 2) Cek data dalam node dan eksekusinya
    
    //    a. Jika data bukan operator
    if ( root -> data != "+" &&
          root -> data != "-" &&
          root -> data != "*" && 
          root -> data != "/") 
          // Memasukkan data ke dalam Array
          push ( root -> data );
          
    //    b. Jika data adalah operator
        else {
      	  // Ambil 2 operand terakhir
        	string operand_1 = stack1[top-1];
        	string operand_2 = stack1[top];
        	// Konversi data string menjadi integer
        	int a = stoi ( stack1[top-1] );
        	int b = stoi ( stack1[top] );
      	  // Hasil operasi operand dengan operator
        	int result;
        	
            // Operasikan operand 1 dan 2
            if (root->data == "+") {
           	 result = a + b;
           	 cout << "\t" << a << " + " << b << " = " << result << "\n"; }
            else if (root->data == "-") {
           	 result = a - b;
           	 cout << "\t" << a << " - " << b << " = " << result << "\n"; }
            else if (root->data == "*") {
            	result = a * b;
           	 cout << "\t" << a << " * " << b << " = " << result << "\n"; }
            else if (root->data == "/") {
            	if ( b == 0 ) {
                    cout << "Invalid, terdapat pembagian dengan 0 \n";
                    return; }
                result = a / b;
                cout << "\t" << a << " / " << b << " = " << result << "\n"; }
                
          // Hapus operand 1 dan 2        
          pop();
          pop();
          
         // Masukkan data dalam Linked List
         push(to_string(result));
      } 
   }
}

void evaluate (Node* root) {
	cout << "Postfix = ";
	postorder(root);
	cout <<"\nOperation" << endl;
	calculate  (root);
	cout << "Result = " << stack1[top] << endl << endl;
}


// xxxxxxxxx– Implementasi Fungsi Stack Library –xxxxxxxxx 



void traversePostOrder(Node* node, string &postfix){
    if (node == NULL)
        return;
    traversePostOrder(node->left, postfix);
    traversePostOrder(node->right, postfix);
    postfix += node->data + " "; // Add space as separator
}

void evaluatePostfix(Node* node){
    string postfix = "";
    traversePostOrder(node, postfix);
    cout << "Postfix = " << postfix << endl;
    cout << "Operation" << endl;
    
    stack<float> evaluate;
    istringstream iss(postfix);
    string token;
    
    while(iss >> token){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            // Make sure we have at least two operands
            if(evaluate.size() < 2) {
                cout << "Error: Not enough operands for operator " << token << endl;
                return;
            }
            
            float operand2 = evaluate.top(); evaluate.pop();
            float operand1 = evaluate.top(); evaluate.pop();
            
            if(token == "+"){
                evaluate.push(operand1 + operand2);
                cout <<"\t"<< operand1 <<" + "<< operand2 
                <<" = "<< evaluate.top() << "\n";
            } else if(token == "-"){
                evaluate.push(operand1 - operand2);
                cout <<"\t"<< operand1 <<" - "<< operand2 
                <<" = "<< evaluate.top() << "\n";
            } else if(token == "*"){
                evaluate.push(operand1 * operand2);
                cout <<"\t"<< operand1 <<" * "<< operand2 
                <<" = "<< evaluate.top() << "\n";
            } else if(token == "/"){
                if(operand2 == 0) {
                    cout << "Error: Division by zero" << endl;
                    return;
                }
                evaluate.push(operand1 / operand2);
                cout <<"\t"<< operand1 <<" / "<< operand2 
                <<" = "<< evaluate.top() << "\n";
            }
        } else {
            try {
                evaluate.push(stof(token));
            } catch(const exception& e) {
                cout << "Error: Invalid token " << token << endl;
                return;
            }
        }
    }

    if(evaluate.size() != 1) {
        cout << "Error: Invalid expression (too many operands)" << endl;
        return;
    }
    
    cout << "Result: " << evaluate.top() << endl << endl;
}


