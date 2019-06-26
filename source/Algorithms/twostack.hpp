#include "../Linear/Stack.cpp"
#include "../String/String.cpp"
#include "../Linear/SLL.cpp"
#include "../Functions/functions.cpp"

/** Djikstra's Two Stack Algorithm
 * <Place your notes and analysis here>
 * O(n)
 */
double twostack(char* expression) {
    Stack* opers = new Stack();
	Stack* values = new Stack();

    String s = String(expression);

    for (int i = 0; i < s.size(); i++){
        if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/' || s.at(i) == '^'){
            opers->push(s.at(i));
        }
        else if (s.at(i) >= '0' && s.at(i) <= '9'){
            values->push((int)s.at(i) - 48);
        }
        else if (s.at(i) == ')' && values->size() > 1){
            char op = opers->pop();
            double result = 0;
            int right = values->pop();
            int left = values->pop();

            switch (op){
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                case '^':
                    result = pow(left,right);
                    break;
                default:
                    break;
            }
            values->push(result);
        }
    }

    return values->pop();
}