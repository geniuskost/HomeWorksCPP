#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Violation {
    std::string description;
    Violation(const std::string& desc) : description(desc) {}
};

struct Node {
    std::string carNumber;
    std::vector<Violation> violations;
    Node* left;
    Node* right;
    Node(const std::string& num, const std::string& desc)
        : carNumber(num), left(nullptr), right(nullptr) {
        violations.push_back(Violation(desc));
    }
};

class DAIBase {
    Node* root;
    void printAll(Node* node) const {
        if (!node) return;
        printAll(node->left);
        std::cout << "Car: " << node->carNumber << "\n";
        for (const auto& v : node->violations)
            std::cout << "  - " << v.description << "\n";
        printAll(node->right);
    }
    void printByNumber(Node* node, const std::string& num) const {
        if (!node) return;
        if (num < node->carNumber) printByNumber(node->left, num);
        else if (num > node->carNumber) printByNumber(node->right, num);
        else {
            std::cout << "Car: " << node->carNumber << "\n";
            for (const auto& v : node->violations)
                std::cout << "  - " << v.description << "\n";
        }
    }
    void printByRange(Node* node, const std::string& from, const std::string& to) const {
        if (!node) return;
        if (from < node->carNumber) printByRange(node->left, from, to);
        if (from <= node->carNumber && node->carNumber <= to) {
            std::cout << "Car: " << node->carNumber << "\n";
            for (const auto& v : node->violations)
                std::cout << "  - " << v.description << "\n";
        }
        if (to > node->carNumber) printByRange(node->right, from, to);
    }
    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
public:
    DAIBase() : root(nullptr) {}
    ~DAIBase() { clear(root); }

    void addViolation(const std::string& carNum, const std::string& desc) {
        Node** cur = &root;
        while (*cur) {
            if (carNum < (*cur)->carNumber) cur = &((*cur)->left);
            else if (carNum > (*cur)->carNumber) cur = &((*cur)->right);
            else {
                (*cur)->violations.push_back(Violation(desc));
                return;
            }
        }
        *cur = new Node(carNum, desc);
    }

    void printAll() const { printAll(root); }
    void printByNumber(const std::string& num) const { printByNumber(root, num); }
    void printByRange(const std::string& from, const std::string& to) const { printByRange(root, from, to); }
};