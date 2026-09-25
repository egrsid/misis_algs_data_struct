#include <iostream>

struct Node {
    int data_;
    Node* next_ = nullptr;
};

Node* fill_recursive() {
    int n;
    std::cin >> n;
    if (n == 0) return nullptr;

    Node* newNode = new Node{};
    newNode->data_ = n;
    newNode->next_ = fill_recursive();

    return newNode;
}

Node* fill_iterative() {
    int n;
    std::cin >> n;
    if (n == 0) return nullptr;

    Node* cur = new Node{};
    Node* head = cur;
    while (n > 0) {
        Node* newNode = new Node{};
        cur->next_ = newNode;
        newNode->data_ = n;
        cur = newNode;

        std::cin >> n;
    }

    return head;
}

void print_list_recursive(const Node* begin) {
    if (begin == nullptr) return;
    std::cout << begin->data_ << std::endl;
    print_list_recursive(begin->next_);
}

void print_list_iterative(const Node* begin) {
    while (begin != nullptr) {
        std::cout << begin->data_ << std::endl;
        begin = begin->next_;
    }
}

int main() {
    Node* begin = fill_recursive();
    print_list_recursive(begin);
}