//
// Created by 72358 on 3/03/2025.
//

#ifndef DATA_ESTRUCTURE_C_QUEUEUSINGTWOSTACKS_H
#define DATA_ESTRUCTURE_C_QUEUEUSINGTWOSTACKS_H

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void enqueue(int value) {
        stack1.push(value);
    }

    void dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty()) {
            stack2.pop();
        }
    }
};

#endif //DATA_ESTRUCTURE_C_QUEUEUSINGTWOSTACKS_H
