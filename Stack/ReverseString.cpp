//
// Created by 72358 on 17/02/2025.
//
#include "ReverseString.h"


string reverseString(const string& str) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function reverses the input string 'str'.    |
    //   | - Uses a stack to hold the characters.              |
    //   | - Pops from stack and appends to 'reversedString'.  |
    //   | - Return type: string                               |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold each character of the string. |
    //   | - Push each character of 'str' onto the stack.      |
    //   | - Pop from the stack and append to 'reversedString' |
    //   |   until the stack is empty.                         |
    //   | - Return the reversed string.                       |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    Stack stack;
    string reversedString;
    for (char c : str) {
        stack.push(c);
    }
    while (!stack.isEmpty()) {
        reversedString += stack.pop();
    }
    return reversedString;
}

string reverseString(const string& str) {
    stack<char> charStack;
    string reversedString;

    for (char c : str) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    return reversedString;
}

bool isBalancedParentheses(const string& parentheses) {
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if the input string          |
    //   |   'parentheses' has balanced parentheses.           |
    //   | - Uses a stack to hold the open parentheses.        |
    //   | - Return type: bool                                 |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Use a stack to hold open parentheses.             |
    //   | - Push '(' onto the stack.                          |
    //   | - When encountering ')', check if stack is empty    |
    //   |   or top of stack is not '('. If so, return false.  |
    //   | - Otherwise, pop from the stack.                    |
    //   | - At the end, if stack is empty, return true.       |
    //   | - Otherwise, return false.                          |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    stack<char> charStack;

}

bool isBalancedParentheses(const string& parentheses) {
    // Stack to store the opening parentheses
    stack<char> charStack;

    // Iterate through the input string
    for (char p : parentheses) {
        // If the current character is an opening parenthesis, push it onto the stack
        if (p == '(') {
            charStack.push(p);
        } else if (p == ')') { // If the current character is a closing parenthesis
            // Check if the stack is empty or the top of the stack
            // is not an opening parenthesis
            if (charStack.empty() || charStack.top() != '(') {
                return false;
            }
            // Pop the matching opening parenthesis from the stack
            charStack.pop();
        }
    }

    // Return true if the stack is empty, indicating balanced parentheses
    return charStack.empty();
}