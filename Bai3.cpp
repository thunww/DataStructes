#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* makeNode(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(Node*& top, int x) {
    Node* newNode = makeNode(x);
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top) {
    if (top == NULL) {
        cout << "Stack rong " << endl;
        return -1;
    }
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return x;
}

void chuyenDoi10Sang2(int n) {
    Node* binaryStack = nullptr;
    if (n == 0) {
        push(binaryStack, 0);
    }
    else {
        while (n > 0) {
            push(binaryStack, n % 2);
            n = n / 2;
        }
    }

    int size = 0;
    Node* temp = binaryStack;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    cout << "So nhi phan tuong ung la: ";

    for (int i = size; i < 4; i++) {
        cout << 0;
    }
   
    while (binaryStack != nullptr) {
        cout << pop(binaryStack);
    }
    cout << endl;
}

void chuyenDoi10Sang16(int n) {
    Node* hexStack = nullptr;
    if (n == 0) {
        push(hexStack, 0);
    }
    else {
        while (n > 0) {
            int a = n % 16;
            if (a < 10)
                push(hexStack, a + '0'); 
            else
                push(hexStack, a - 10 + 'A');
            n = n / 16;
        }
    }

    cout << "So thap luc phan tuong ung la: ";
    while (hexStack != nullptr) {
        int x = pop(hexStack);
        cout << char(x);
    }
    cout << endl;
}


int chuyenDoi2Sang10(Node* binaryStack) {
    int dec = 0;
    int p = 0;
    while (binaryStack != NULL) {
        dec = dec + binaryStack->data * pow(2, p);
        binaryStack = binaryStack->next;
        ++p;
    }
    return dec;
}

int chuyenDoi16Sang10(Node* hexStack) {
    int dec = 0;
    int p = 0;
    while (hexStack != NULL) {
        int x = hexStack->data;
        if (x >= '0' && x <= '9')
            dec = dec + (x - '0') * pow(16, p);
        else if (x >= 'A' && x <= 'F')
            dec = dec + (x - 'A' + 10) * pow(16, p);
        hexStack = hexStack->next;
        ++p;
    }
    return dec;
}


int main() {
    char c;
    int dec;
    string hex, binary;
    Node* binaryStack = NULL;
    Node* hexStack = NULL;
   

    do {
        cout << "=============MENU============= \n";
        cout << "a. Doi so thap phan sang nhi phan.\n";
        cout << "b. Doi so thap phan sang so thap luc phan.\n";
        cout << "c. Doi so nhi phan sang so thap phan.\n";
        cout << "d. Doi so thap luc phan sang so thap phan.\n";
        cout << "e. Thoat\n";
        cout << "==============END============== \n";
        cout << "Lua chon: ";
        cin >> c;

        if (c == 'a') {
            cout << "Nhap so thap phan: ";
            cin >> dec;
            chuyenDoi10Sang2(dec);
        }
        else if (c == 'b') {
            cout << "Nhap so thap phan: ";
            cin >> dec;
            chuyenDoi10Sang16(dec);
        }
        else if (c == 'c') {
            cout << "Nhap so nhi phan: ";
            cin >> binary;
            for (char ch : binary) {
                if (ch == '0' || ch == '1')
                    push(binaryStack, ch - '0');
                else {
                    cout << "Nhap khong hop le. Vui long nhap lai!\n";
                    binaryStack = NULL; // Xóa stack
                    break;
                }
            }
            if (binaryStack != NULL) {
                cout << "So thap phan tuong ung la : " << chuyenDoi2Sang10(binaryStack) << endl;
            }
        }
        else if (c == 'd') {
            cout << "Nhap so thap luc phan: ";
            cin >> hex;
            bool va = true;
            for (char ch : hex) {
                if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F')) {
                    push(hexStack, ch);
                }
                else {
                    cout << "Nhap khong hop le. Vui long nhap lai!\n";
                    hexStack = NULL; // Xóa stack
                    va = false;
                    break;
                }
            }
            if (va && hexStack != NULL) {
                cout << "So thap phan tuong ung la : " << chuyenDoi16Sang10(hexStack) << endl;
            }
        }
        else if (c == 'e') {
            cout << "Ket thuc.\n";
        }
        else {
            cout << "Chuc nang khong hop le. Vui long nhap lai!.\n";
        }


        if (binaryStack != NULL) {
            while (binaryStack != NULL) {
                pop(binaryStack);
            }
        }
        if (hexStack != NULL) {
            while (hexStack != NULL) {
                pop(hexStack);
            }
        }

    } while (c != 'e');

    return 0;
}
