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

Node* lst_from_array(const int* arr, size_t size) {
    if (size == 0) return nullptr;

    Node* begin = new Node{};
    Node* cur = begin;

    for (int i = 0; i < size; ++i) {
        cur->data_ = arr[i];
        if (i != size - 1) {
            cur->next_ = new Node{};
            cur = cur->next_;
        } else cur->next_ = nullptr;
    }

    return begin;
}

void print_reverse(Node* begin) {
    if (begin == nullptr) return;

    print_reverse(begin->next_);
    std::cout << begin->data_ << std::endl;
}

void delete_lst(Node*& begin) {
    if (begin == nullptr) return;

    while (begin != nullptr) {
        Node* cur = begin->next_;
        delete begin;
        begin = cur;
    }

    begin = nullptr;
}

Node* delete_el_from_lst_iterative(Node*& begin, size_t idx) {
    if (begin == nullptr) return nullptr;

    if (idx == 0) {
        Node* to_delete = begin;
        begin = begin->next_;
        delete to_delete;
        return begin;
    }

    Node* cur = begin;
    for (int i = 0; i < idx-1 && cur->next_ != nullptr; ++i) cur = cur->next_;

    if (cur->next_ == nullptr) return begin;

    Node* to_delete = cur->next_;
    cur->next_ = cur->next_->next_;
    delete to_delete;

    return begin;
}

Node* delete_el_from_lst_recursive(Node* begin, size_t idx) {
    if (begin == nullptr) return nullptr;

    if (idx == 0) {
        Node* to_delete = begin;
        begin = begin->next_;
        delete to_delete;
        return begin;
    }

    begin->next_ = delete_el_from_lst_recursive(begin->next_, idx-1);
    return begin;
}

Node* push_front(Node* begin, int val) {
    return new Node{val, begin};
}

void push_front_inplace(Node*& begin, int val) {
    begin = new Node{val, begin};
}

void push_front_ptr(Node** begin, int val) {
    Node* new_node = new Node{val, *begin};
    *begin = new_node;
}

Node* pop_front(Node* begin) {
    if (begin == nullptr) return nullptr;

    Node* new_begin = begin->next_;
    delete begin;

    return new_begin;
}

void pop_front_inplace(Node*& begin) {
    if (begin == nullptr) return;

    Node* old_begin = begin;
    begin = begin->next_;
    delete old_begin;
}

void pop_front_ptr(Node** begin) {
    if (begin == nullptr) return;

    Node* old_begin = *begin;
    *begin = (*begin)->next_;
    delete old_begin;
}

Node* insert(Node* begin, int idx, int val) {
    if (idx == 0) return push_front(begin, val);

    Node* head = begin;
    
    for (size_t i = 0; i < idx-1 && begin->next_ != nullptr; ++i) begin = begin->next_;

    begin->next_ = new Node{val, begin->next_};

    return head;
}



int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* begin = lst_from_array(arr, 10);
    begin = insert(begin, 2, 100);
    print_list_iterative(begin);
}