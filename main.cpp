#include <iostream>
#include "avl_tree.h"
using namespace std;

int main() {
    AVLTree tree;

    int isTree = 0;
    cout << "How many commands would you like to run?" << endl;
    int numCommands;
    cin >> numCommands;
    cin.ignore();

    for (int i = 0; i < numCommands+1 ; i ++){
        cout << "Insert command:" << endl;
        string input;
        getline(cin, input, '\n');

        if(input.substr(0, 7) == "insert "){
            if (input[7] == '"'){ //checks that name is in parenthesis
                string inserting ;
                inserting = input.substr(8, -1);
                size_t found = inserting.find('"');
                if (input[found+8] == '"'){
                    string nameInput = input.substr(8, found);
                    if (nameInput.find_first_not_of("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm ") != std::string::npos){ // checks name is alphabetical
                        cout << "unsuccessful" << endl;
                    }
                    else {
                      string idInput = input.substr(10+found, -1);
                      int counter = 0;
                        for( int i = 0; i < idInput.length(); i++ ) {
                            if( !isdigit( idInput[i] )) {
                                counter += 1;
                            }
                        }
                        if ((counter > 0 )|| idInput.length() !=8){ cout << "unsuccessful" << endl;} // breaks if id is not numerical or not 8 digits long
                        else {
                            if (isTree == 0){
                                cout << "successful" << endl;
                                tree.root = newnode(nameInput, idInput); //places first node
                                isTree += 1;
                            }
                            else {
                                if (id_existsBool(tree.root, idInput)){ //checks node dne
                                    cout << "unsuccessful" << endl;
                                }
                                else {
                                    cout << "successful" << endl;
                                    tree.InsertHelper(tree.root,nameInput, idInput); } // places new node
                            }
                        }
                }}
            }
        }

        else if (input.substr(0, 7) == "remove "){
            if (isTree == 0){cout << "unsuccessful" << endl;}
            else {
            if (input.size() != 15){cout << "unsuccessful" << endl;}
            else {
            string idInput = input.substr(7, 14);
            int counter = 0;
            for( int i = 0; i < idInput.length(); i++ ) {
                if( !isdigit( idInput[i] )) {
                    counter += 1;
                }
            }
            if ((counter > 0 )){ cout << "unsuccessful"<<  endl;}
            else {
                cout << "successful"<<  endl;
                deleteNode(tree.root, (idInput));
            }
        }}}

        else if((input.substr(0, 7) == "search ") && input[7]=='"') { //checks that search is followed by a name
            if (isTree == 0){cout << "unsuccessful" << endl;}
            else {
            if (input[7] == '"') {
                string inserting;
                inserting = input.substr(8, -1);
                size_t found = inserting.find('"');
                if (input[found + 8] == '"') {
                    string nameInput = input.substr(8, found);
                    if (!nameExistsHelper(tree.root, nameInput)){
                        cout << "unsuccessful"<<  endl;
                    }
                    else {
                        isName(tree.root, nameInput);
                    }
                }
            }
        }}

        else if((input.substr(0, 7) == "search ") && input[7]!='"'){ //checks search is followed by id
            if (isTree == 0){cout << "unsuccessful" << endl; }
            else {
            if (input.size() != 15){cout << "unsuccessful" << endl;}
            else {
                string idInput = input.substr(7, 14);
                int counter = 0;
                for( int i = 0; i < idInput.length(); i++ ) {
                    if( !isdigit( idInput[i] )) {
                        counter += 1;
                    }
                }
                if ((counter > 0 )){ cout << "unsuccessful"<<  endl;}
                else {
                    if (!id_existsBool(tree.root, idInput)){
                        cout << "unsuccessful"<<  endl;
                    }
                    else {
                        findKey(tree.root, idInput);
                    }
                }
            }
        }}

        else if(input.substr(0, 12) == "printInorder"){
            string w = inorderHelper(tree.root);
            int size = w.size();
            string ww = w.substr(0, size-2);
            cout << ww << endl;
        }

        else if(input.substr(0, 13) == "printPreorder"){
            string pre = preorderHelper(tree.root);
            int size = pre.size();
            string preSub = pre.substr(0, size-2);
            cout << preSub<< endl;

        }
        else if(input.substr(0, 14) == "printPostorder"){
            string p = postorderHelper(tree.root);
            int size = p.size();
            string pSub = p.substr(0, size-2);
            cout << pSub << endl;
        }

        else if(input.substr(0, 15) == "printLevelCount"){            ///HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!
            if (isTree == 0 ){ cout << "0" <<endl; }
            else {cout << height(tree.root) << endl;
        }}

        else if(input.substr(0, 14) == "removeInorder ") {
            string n = input.substr(14, input.size());
            int counter = 0;
            for (int i = 0; i < n.length(); i++) { //checks n is an integer
                if (!isdigit(n[i])) {
                    counter += 1;
                }
            }
            if ((counter > 0)) { cout << "unsuccessful" << endl; }
            else {
                string s = inorderHelperID(tree.root);
                int number = s.size()/10;
                if (stoi(n) > number-1){
                    cout << "unsuccessful" << endl;
                }
                else {
                    int index = stoi(n)*10;
                    string deleting = s.substr(index, 8);
                    cout << "successful"<<  endl;
                    deleteNode(tree.root, (deleting));

                }

            }
        }


    }



    return 0;
};
