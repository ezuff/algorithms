#include "../Linear/Stack.hpp"
#include "../String/String.hpp"
#include "../Functions/functions.hpp"
#include "../Linear/LinkedList.hpp"

/** Djikstra's Two Stack Algorithm
 * <Place your notes and analysis here>
 * O(n)
 */
 double twostack(char* expression){
    Stack* opers = new Stack();
	Stack* values = new Stack();

    String s = String(expression);
    int len = s.size();

    for (int i = 0; i < len; i++){
        if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/' || s.at(i) == '^'){
            opers->push(s.at(i));
            std::cout << opers->top() << std::endl;
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
        }else if (s.find(')') == s.size()){
            throw i;
        }
    }

    return values->pop();
}