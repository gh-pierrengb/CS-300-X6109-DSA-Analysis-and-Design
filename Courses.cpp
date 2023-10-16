//============================================================================
// Name        : Courses.cpp
// Author      : Pierrot NGIMBIDI
// Version     : 1.0
// Copyright   : Copyright © 2023 Pierrot NGIMBIDI
// Description : A program to manage course schedule
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

/**
 * Transform a string into lowercase using a lambda function.
 * @param input
 * @return a lowercase string.
 */
string toLower(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c) { return tolower(c); });
    return result;
}

// Course class structure
class Course {
public:
    string courseNumber;
    string name;
    vector<string> prerequisites;  // List of course prerequisites
};

// Internal node structure
class TreeNode {
public:
    Course data;
    TreeNode* left;
    TreeNode* right;

    // Default constructor
    TreeNode() : left(nullptr), right(nullptr) {}

    // Constructor with a course
    TreeNode(Course c) : data(c){}
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    TreeNode* root;

    void addNode(TreeNode* node, Course course);
    void inOrder(TreeNode* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Course courseNumber);
    Course Search(string courseNumber);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    //root is equal to nullptr
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // call inOrder fuction and pass root
    inOrder(root);
}

/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
    // if root equarl to null ptr
    TreeNode *node  =  new TreeNode(course);
    if(root == nullptr) {
        // root is equal to new node course
        root = node;
    }
        // else
    else {
        // add Node root and course
        addNode(root, course);
    }
}

/**
 * Add a Course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(TreeNode* node, Course course) {
    // if node is larger then add to left
    if(node->data.courseNumber > course.courseNumber) {
        // if no left node
        if(node->left == nullptr) {
            // this node becomes left
            node->left = new TreeNode(course);
        }
            // else recurse down the left node
        else {
            addNode(node->left, course);
        }
    }
        // else
    else {
        // if no right node
        if(node->right == nullptr) {
            // this node becomes right
            node->right = new TreeNode(course);
        }
            //else
        else {
            // recurse down the left node
            addNode(node->right, course);
        }
    }
}
/**
 * Traverse the binary tree in order
 * @param node the node to traverse. Starts with root node.
 */
void BinarySearchTree::inOrder(TreeNode* node) {
    //if node is not equal to null ptr
    if (node == nullptr) {
        return;
    }
    //InOrder not left
    inOrder(node->left);
    //output courseNumber and courseName
    cout << node->data.courseNumber << ", " << node->data.name << endl;
    //InOder right
    inOrder(node->right);
}

/**
 * Search for a course and return it.
 * @param course The course number to search for
 */
Course BinarySearchTree::Search(string courseNumber) {
    // Set the current node to the root
    TreeNode* current = root;

    // keep looping downwards until bottom reached or matching course Number found
    while (current != nullptr) {
        // if match found, return current course
        if (toLower(current->data.courseNumber) == courseNumber) {
            // Matching courseNumber found, return the course
            return current->data;
        } else if (courseNumber < toLower(current->data.courseNumber)) {
            // If courseNumber is smaller than the current node's courseNumber, go left
            current = current->left;
        } else {
            // If courseNumber is greater than the current node's courseNumber, go right
            current = current->right;
        }
        // Traverse the tree until the bottom is reached or the matching courseNumber is found
    }

    // If no matching courseNumber is found, return an empty courseNumber
    Course course;
    return course;
}

/**
 * Load a CSV file containing courses into a container
 * @param filename the csv file name to load
 * @param bst By reference Binary Search Tree.
 * @returns A Binary Search Tree holding courses.
 */
void readCourseData(const string& filename, BinarySearchTree* bst) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File not found." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 2) {
            cout << "Invalid file format." << endl;
            file.close();
            return;
        }

        Course course;
        course.courseNumber = tokens[0];
        course.name = tokens[1];

        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        bst->Insert(course);
    }
    file.close();
}

/**
 * Print course info and prerequisites
 * @param course the course to print
 */
void PrintCourseInfo(Course course) {

    cout << course.courseNumber << ", " << course.name << endl;

        if (!course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for(int i = 0; i < course.prerequisites.size(); i++){
                cout << course.prerequisites.at(i);
                if(i != course.prerequisites.size() - 1){
                    cout << ", ";
                }
            }
        }
        cout << endl;
}



int main() {
    string fileName;
    int choice = 0;
    // Binary tree to hold courses
    BinarySearchTree* bst;
    bst = new BinarySearchTree();
    string courseKey;
    Course course;

    cout << "Welcome to the course planner." << endl;
    while (choice != 9) {
        cout << "  1. Load DataStructure" << endl;
        cout << "  2. Print course list" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {

            case 1:
                fileName = "courses.csv";
                readCourseData(fileName, bst);
                break;
            case 2:
                cout << "Here is a sample schedule:" << endl;
                cout << endl;
                bst->InOrder();
                break;
            case 3:
                cout << "What course do you want to know about? ";
                cin >> courseKey;
                course = bst->Search(courseKey);
                PrintCourseInfo(course);
                break;
            case 9:
                cout << "Thank you for using the course planner!" << endl;
                ::exit(0);
            default:
                cout << choice << " is not a valid option." << endl;
                break;
        }
    }

    return 0;
}
