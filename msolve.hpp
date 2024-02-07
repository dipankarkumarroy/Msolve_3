/********************************************************
 *This code orginally Written By
 *Author: Dipankar Kumar Roy
 *If you want to use this code, please mention Authors name.
 *********************************************************/
#ifndef MSOLVE_HPP
#define MSOLVE_HPP
#include <cmath>

class _Dip_
{
public:
    char data;
    _Dip_ *next;
};

class _Dip__s
{
public:
    double data;
    _Dip__s *next;
};

class _Dip_Node
{
public:
    std::string data;
    _Dip_Node *next;

    _Dip_Node(const std::string &value) : data(value), next(nullptr) {}
};

class _Dip_ll
{
private:
    _Dip_Node *head;

public:
    _Dip_ll() : head(nullptr) {}

    void insert(const std::string &value)
    {
        _Dip_Node *newNode = new _Dip_Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            _Dip_Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    std::string search(const std::string &key)
    {
        _Dip_Node *current = head;
        while (current)
        {
            size_t pos = current->data.find(key + ":");
            if (pos == 0)
            {
                size_t colonPos = current->data.find(':');
                if (colonPos != std::string::npos)
                {
                    return current->data.substr(colonPos + 1);
                }
            }
            current = current->next;
        }
        return "";
    }

    ~_Dip_ll()
    {
        while (head)
        {
            _Dip_Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

_Dip_ *char_top = __null;
_Dip__s *start = __null;

_Dip_ *create__Dip_(_Dip_ *ptr, char data)
{
    _Dip_ *new__Dip_;
    new__Dip_ = (_Dip_ *)malloc(sizeof(_Dip_));
    new__Dip_->data = data;
    new__Dip_->next = ptr;
    return new__Dip_;
}

void _Dip_push_(char data)
{
    char_top = create__Dip_(char_top, data);
}

char _Dip_pop_()
{
    char val = char_top->data;
    _Dip_ *ptr = char_top;
    if (char_top->next)
    {
        char_top = char_top->next;
    }
    else
    {
        char_top = __null;
    }
    free(ptr);
    return val;
}

_Dip__s *create__Dip_2(_Dip__s *ptr, double data)
{
    _Dip__s *new__Dip_;
    new__Dip_ = (_Dip__s *)malloc(sizeof(_Dip__s));
    new__Dip_->data = data;
    new__Dip_->next = ptr;
    return new__Dip_;
}
void _Dip_push_2(double data)
{
    start = create__Dip_2(start, data);
}
double _Dip_pop_2()
{
    double val = start->data;
    _Dip__s *ptr = start;
    if (start->next)
    {
        start = start->next;
    }
    else
    {
        start = __null;
    }
    free(ptr);
    return val;
}

class _Dip_queue_
{
public:
    double data;
    _Dip_queue_ *next;

    _Dip_queue_(double val) : data(val), next(nullptr) {}
};

class _queue_
{
private:
    _Dip_queue_ *front;
    _Dip_queue_ *rear;

public:
    _queue_() : front(nullptr), rear(nullptr) {}

    void _Dip_push_(double value)
    {
        _Dip_queue_ *new_Dip_queue_ = new _Dip_queue_(value);
        if (isEmpty())
        {
            front = rear = new_Dip_queue_;
        }
        else
        {
            rear->next = new_Dip_queue_;
            rear = new_Dip_queue_;
        }
    }

    double _Dip_pop_()
    {
        if (isEmpty())
        {
            std::cerr << "Missing value." << std::endl;
            return -1;
        }
        else
        {
            double _Dip_pop_pedValue = front->data;
            _Dip_queue_ *temp = front;
            front = front->next;
            delete temp;
            return _Dip_pop_pedValue;
        }
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }
};

int _Dip_pri_(char s)
{
    if (s == '+' || s == '-')
    {
        return 0;
    }
    if (s == '*' || s == '/' || s == '%')
    {
        return 1;
    }
    if (s == '^')
    {
        return 2;
    }

    return -1;
}

std::string _Dip_InfTPo_(std::string s)
{
    std::string stack, postfix;
    char c;
    s = '(' + s + ')';

    for (int i = 0; i < s.size(); i++)
    {
    label1:
        if (s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '%' && s[i] != '^' && s[i] != 'f')
        {
            postfix = postfix + s[i];
            if (s[i + 1] == '(' || s[i + 1] == ')' || s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '%' || s[i + 1] == '^' || s[i + 1] == 'f')
            {
                postfix = postfix + " ";
            }
        }
        else
        {
            if (s[i] == '(')
            {
                if (s[i + 1] == '+' || s[i + 1] == '-')
                {
                    postfix = postfix + "0 ";
                }
                _Dip_push_(s[i]);
            }
            else if (s[i] == ')')
            {
                do
                {
                    c = _Dip_pop_();
                    if (c != '(')
                    {
                        postfix = postfix + c + " ";
                    }
                } while (c != '(');
            }
            else
            {
                if (s[i] == 'f')
                {
                    int k = i;
                    int countB = 0;
                    std::string tempstr, tempstr2, tempstr3;
                    while (s[i] != '(')
                    {
                        tempstr = tempstr + s[i];
                        i++;
                    }

                    do
                    {

                        if (s[i] == '(')
                        {
                            countB = countB + 1;
                            i++;
                            continue;
                        }
                        else if (s[i] == ')')
                        {
                            countB = countB - 1;
                            i++;
                            continue;
                        }
                        else if (s[i] == ',')
                        {
                            tempstr2 = tempstr2 + tempstr3;
                            tempstr3 = ' ';
                        }
                        else
                        {
                            tempstr3 = tempstr3 + s[i];
                        }

                        i++;
                    } while (countB != 0);

                    
                    postfix = postfix + tempstr2 +tempstr3 + ' ' + tempstr + ' ';
                    goto label1;
                }

                if (_Dip_pri_(char_top->data) == _Dip_pri_(s[i]))
                {
                    if (s[i] == '^')
                    {
                        _Dip_push_(s[i]);
                    }
                    else
                    {
                        c = _Dip_pop_();
                        while (_Dip_pri_(c) == _Dip_pri_(s[i]))
                        {
                            if (c != '(')
                            {
                                postfix = postfix + c + " ";
                            }
                            c = _Dip_pop_();
                        }
                        _Dip_push_(c);
                        _Dip_push_(s[i]);
                    }
                }
                else if (_Dip_pri_(char_top->data) < _Dip_pri_(s[i]))
                {
                    _Dip_push_(s[i]);
                }
                else if (_Dip_pri_(char_top->data) >= _Dip_pri_(s[i]))
                {

                    do
                    {
                        c = _Dip_pop_();
                        if (c != '(')
                        {
                            postfix = postfix + c + " ";
                        }
                    } while (c != '(');
                    _Dip_push_('(');
                    _Dip_push_(s[i]);
                }
            }
        }
    }
    return (" " + postfix);
}

double _Dip_cal_(std::string s)
{
    int i = 0;
    double val;
    std::string temp = "";
    s = s + 'E';
    while (s[i] == ' ' && s[i] != 'E')
    {
        if (s[i + 1] == 'f')
        {
            std::string tempi;
            while (s[i + 1] != ' ')
            {
                tempi = tempi + s[i + 1];
                i++;
            }
            /*
            Trigonometric Functions:
            fsin(x): Sine of x.
            fcos(x): Cosine of x.
            ftan(x): Tangent of x.
            fasin(x): Arcsine of x.
            facos(x): Arccosine of x.
            fatan(x): Arctangent of x.

            Hyperbolic Functions:
            fsinh(x): Hyperbolic sine of x.
            fcosh(x): Hyperbolic cosine of x.
            ftanh(x): Hyperbolic tangent of x.
            fasinh(x): Inverse hyperbolic sine of x.
            facosh(x): Inverse hyperbolic cosine of x.
            fatanh(x): Inverse hyperbolic tangent of x.

            Exponential and Logarithmic Functions:
            fexp(x): Exponential function e^x.
            flog(x): Natural logarithm of x.
            flog10(x): Base-10 logarithm of x.
            flog2(x): Base-2 logarithm of x.
            fexp2(x): 2 raised to the power x.

            fsqrt(x): Square root of x.
            fcbrt(x): Cube root of x.

            Rounding and Remainder Functions:
            fceil(x): Round up to the nearest integer.
            floor(x): Round down to the nearest integer.
            fround(x): Round to the nearest integer.
            ftrunc(x): Truncate towards zero.

            fabs(x): Absolute value of x.
            fabs(x): Same as fabs(x).
            */

            if (tempi == "fsin")
            {
                double x, y;
                x = _Dip_pop_2();
                y = sin(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fcos")
            {
                double x, y;
                x = _Dip_pop_2();
                y = cos(x);
                _Dip_push_2(y);
            }
            else if (tempi == "ftan")
            {
                double x, y;
                x = _Dip_pop_2();
                y = tan(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fasin")
            {
                double x, y;
                x = _Dip_pop_2();
                y = asin(x);
                _Dip_push_2(y);
            }
            else if (tempi == "facos")
            {
                double x, y;
                x = _Dip_pop_2();
                y = acos(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fatan")
            {
                double x, y;
                x = _Dip_pop_2();
                y = atan(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fatan2")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = atan2(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fsinh")
            {
                double x, y;
                x = _Dip_pop_2();
                y = sinh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fcosh")
            {
                double x, y;
                x = _Dip_pop_2();
                y = cosh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "ftan")
            {
                double x, y;
                x = _Dip_pop_2();
                y = tanh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fasinh")
            {
                double x, y;
                x = _Dip_pop_2();
                y = asinh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "facosh")
            {
                double x, y;
                x = _Dip_pop_2();
                y = acosh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fatanh")
            {
                double x, y;
                x = _Dip_pop_2();
                y = atanh(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fexp")
            {
                double x, y;
                x = _Dip_pop_2();
                y = exp(x);
                _Dip_push_2(y);
            }
            else if (tempi == "flog")
            {
                double x, y;
                x = _Dip_pop_2();
                y = log(x);
                _Dip_push_2(y);
            }
            else if (tempi == "flog10")
            {
                double x, y;
                x = _Dip_pop_2();
                y = log10(x);
                _Dip_push_2(y);
            }
            else if (tempi == "flog2")
            {
                double x, y;
                x = _Dip_pop_2();
                y = log2(x);
                _Dip_push_2(y);
            }
            else if (tempi == "exp2")
            {
                double x, y;
                x = _Dip_pop_2();
                y = exp(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fpow")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = pow(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fsqrt")
            {
                double x, y;
                x = _Dip_pop_2();
                y = sqrt(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fcbrt")
            {
                double x, y;
                x = _Dip_pop_2();
                y = cbrt(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fceil")
            {
                double x, y;
                x = _Dip_pop_2();
                y = ceil(x);
                _Dip_push_2(y);
            }
            else if (tempi == "ffloor")
            {
                double x, y;
                x = _Dip_pop_2();
                y = floor(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fround")
            {
                double x, y;
                x = _Dip_pop_2();
                y = round(x);
                _Dip_push_2(y);
            }
            else if (tempi == "ftrunc")
            {
                double x, y;
                x = _Dip_pop_2();
                y = trunc(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fmod")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = fmod(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fabs")
            {
                double x, y;
                x = _Dip_pop_2();
                y = fabs(x);
                _Dip_push_2(y);
            }
            else if (tempi == "fcopysign")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = copysign(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fmin")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = __min(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fmax")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = __max(y, x);
                _Dip_push_2(z);
            }
            else if (tempi == "fhypot")
            {
                double x, y, z;
                x = _Dip_pop_2();
                y = _Dip_pop_2();
                z = hypot(y, x);
                _Dip_push_2(z);
            }
        }
        else if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' || s[i + 1] == '%' || s[i + 1] == '^')
        {
            double x, y, z;
            y = _Dip_pop_2();
            x = _Dip_pop_2();
            switch (s[i + 1])
            {
            case '^':
                z = 1;
                if (y == 0)
                {
                    z = 1;
                }
                else if (y < 0)
                {
                    y = y * (-1);
                    for (int i = 0; i < y; i++)
                    {
                        z = z * x;
                    }
                    z = 1 / z;
                }
                else
                {
                    for (int i = 0; i < y; i++)
                    {
                        z = z * x;
                    }
                }
                break;
            case '*':
                z = x * y;
                break;
            case '/':
                z = x / y;
                break;
            case '%':
                z = (int)x % (int)y;
                break;
            case '+':
                z = x + y;
                break;
            case '-':
                z = x - y;
                break;
            default:
                break;
            }
            _Dip_push_2(z);
            i++;
        }
        else if (s[i + 1] != 'E')
        {
            while (s[i + 1] != ' ')
            {
                temp = temp + s[i + 1];
                i++;
            }
            val = stod(temp);
            _Dip_push_2(val);
            temp = "";
        }
        i++;
    }
    return _Dip_pop_2();
}

template <typename... Args>
std::string _Dip_conv_(const std::string &s, Args... args)
{
    _Dip_ll list;
    int k = 0, id = 0;
    std::string ts;
    _queue_ my_queue_;
    (my_queue_._Dip_push_(args), ...);
    while (s[k] != '\0')
    {
        while (s[k] == ' ')
        {
            k++;
        }

        if (s[k] == 'f')
        {
            int tempo = k;
            std::string temstr = "";
            while (isalpha(s[k]) || s[k] == '_' || isdigit(s[k]))
            {
                temstr = temstr + s[k];
                k++;
            }
            if (s[k] == '(')
            {
                ts = ts + temstr;
            }
            else
            {
                k = tempo;
            }
        }

        if (isalpha(s[k]) || s[k] == '_')
        {
            std::string temp = "";
            std::string temp1 = "";
            while (isalpha(s[k]) || s[k] == '_' || s[k] == ' ' || isdigit(s[k]))
            {
                if (s[k] != ' ')
                {
                    temp = temp + s[k];
                }

                k++;
            }
            temp1 = list.search(temp);
            if (temp1 == "")
            {
                double x = my_queue_._Dip_pop_();
                if (x < 0)
                {
                    ts = ts + "(0" + std::to_string(x) + ")";
                    list.insert(temp + ':' + "(0" + std::to_string(x) + ")");
                }
                else
                {
                    ts = ts + std::to_string(x);
                    list.insert(temp + ':' + std::to_string(x));
                }
            }
            else
            {
                ts = ts + temp1;
            }
        }
        else if (!isalnum(s[k]) || isdigit(s[k]))
        {
            ts = ts + s[k];
            k++;
        }
        else
        {
            k++;
        }
    }

    return ts;
}

double Msolve(std::string s)
{
    int k = 0;
    std::string ts;
    while (s[k] != '\0')
    {
        if (s[k] != ' ')
        {
            ts = ts + s[k];
        }

        k++;
    }
    return _Dip_cal_(_Dip_InfTPo_(ts));
}

template <typename... Args>
double Msolve(std::string s, Args... args)
{
    s = _Dip_conv_(s, args...);
    return _Dip_cal_(_Dip_InfTPo_(s));
}

#endif
