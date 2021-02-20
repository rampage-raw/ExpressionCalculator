#include "calc.h"

calc::calc()
{

}

double calc::RunCalc(string cur){
    ss = cur;
    if(checkmatch(ss) == false) return -0x3f3f3f3f-1;
    ss = "(" + ss + ")";
    len = ss.length();
    int lastpos = 0;
    for(int i = 0; i < len - 1; ++i){
        if( (ss[i] == ')' && ss[i + 1] == '(') ||
                (ss[i] == ')' && (ss[i + 1] >= '0' && ss[i + 1] <= '9')) ||
                ((ss[i] >= '0' && ss[i] <= '9') && ss[i + 1] == '(') ){
            string tmp = ss.substr(lastpos, i - lastpos + 1);
            rec.push_back(tmp);
            lastpos = i + 1;
        }
    }
    string tmp = ss.substr(lastpos, len - lastpos);
    rec.push_back(tmp);
    int reclen = rec.size();
    for(int i = 0; i < reclen; ++i){
        if(i == 0) ss = rec[i];
        else ss = ss + '*' + rec[i];
    }
    len = ss.length();
    if(checkvalid(ss) == false) return -0x3f3f3f3f-2;

    string temp = "";
    for(int i = 0; i < len; ++i){
        if(ss[i] == '.'){
            if(decimal_point){
                return -0x3f3f3f3f;
            }
            else {
                decimal_point = true;
                temp += ".";
            }
        }
        else if(ss[i] >= '0' && ss[i] <= '9'){
            temp += ss[i];
        }
        else {
            if(!temp.empty()){
                num.push(transform(temp));
                temp = "";
                decimal_point = false;
            }
            if(ss[i] == '+' || ss[i] == '-'){
                while(symbol.top() != '('){//读到一次加减法，那么在'('与其之间的为一项
                    num.push(func());
                }
                symbol.push(ss[i]);
            }
            else if(ss[i] == '*' || ss[i] == '/'){
                while(symbol.top() == '*' || symbol.top() == '/'){//读到乘除法，那么优先运算将项内合并
                    num.push(func());
                }
                symbol.push(ss[i]);
            }
            else if(ss[i] == '('){
                symbol.push(ss[i]);
            }
            else if(ss[i] == ')'){//当处理到')'时，每个匹配的括号里仅有两项
                while(symbol.top() != '('){
                    num.push(func());
                }
                if(!symbol.empty()) symbol.pop();
                else return -0x3f3f3f3f-1;
            }
        }
    }
    if(symbol.empty()) return num.top();
    else return -0x3f3f3f3f-1;
}

double calc::transform(string cur){
    double cnt = 0;
    int pos = cur.length();
    int curlen = cur.length();
    for(int i = 0; i < curlen; ++i){
        if(cur[i] == '.'){
            pos = i;
            break;
        }
        cnt = cnt * 10 + (cur[i] - '0');
    }
    double k = 0.1;
    double tmp = 0;
    for(int i = pos + 1; i < curlen; ++i){
        tmp += k * (cur[i] - '0');
        k *= 0.1;
    }
    cnt += tmp;
    return cnt;
}

double calc::cal(double x, double y, char c){
    if(c == '+') return x + y;
    if(c == '-') return x - y;
    if(c == '*') return x * y;
    return x / y;
}

double calc::func(){
    double x = num.top();
    num.pop();
    double y = num.top();
    num.pop();
    char c = symbol.top();
    symbol.pop();
    double cur = cal(y, x, c);
    return cur;
}

bool calc::checkmatch(string cur){
    stack<char> tmp;
    int curlen = cur.length();
    for(int i = 0; i < curlen; ++i){
        if(cur[i] == '(') tmp.push(cur[i]);
        if(cur[i] == ')'){
            if(!tmp.empty()) tmp.pop();
            else return false;
        }
    }
    if(!tmp.empty()) return false;
    return true;
}

bool calc::checkvalid(string cur){
    int curlen = cur.length();
    for(int i = 0; i < curlen - 1; ++i){
        if(cur[i] == '('){
            if( cur[i + 1] == ')' || cur[i + 1] == '+' || cur[i + 1] == '-' || cur[i + 1] == '*' ||
                    cur[i + 1] == '/' || cur[i + 1] == '.' ) return false;
        }
        else if(cur[i] == ')'){
            if( cur[i + 1] == '.' || cur[i + 1] == '(' ||
                    (cur[i + 1] >= '0' && cur[i + 1] <= '9') ) return false;
        }
        else if(cur[i] == '+' || cur[i] == '-' || cur[i] == '*' || cur[i] == '/'){
            if(cur[i + 1] == ')' || cur[i + 1] == '+' || cur[i + 1] == '-' || cur[i + 1] == '*' ||
                    cur[i + 1] == '/' || cur[i + 1] == '.') return false;
        }
        else if(cur[i] == '.'){
            if(cur[i + 1] == ')' || cur[i + 1] == '+' || cur[i + 1] == '-' || cur[i + 1] == '*' ||
                    cur[i + 1] == '/' || cur[i + 1] == '.' || cur[i + 1] == '(') return false;
        }
        else if((cur[i] >= '0' && cur[i] <= '9')){
            if(cur[i + 1] == '(') return false;
        }
    }
    return true;
}
