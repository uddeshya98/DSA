class Solution {
public:
    string doc = "";
    stack<char> undoStack;
    stack<char> redoStack;

    void append(char x) {
        doc.push_back(x);
        while (!redoStack.empty()) redoStack.pop();
        undoStack.push(x);
    }

    void undo() {
        if (!undoStack.empty()) {
            char c = undoStack.top();
            undoStack.pop();
            doc.pop_back();
            redoStack.push(c);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            char c = redoStack.top();
            redoStack.pop();
            doc.push_back(c);
            undoStack.push(c);
        }
    }

    string read() {
        return doc;
    }
};
