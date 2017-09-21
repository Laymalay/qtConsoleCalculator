#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringList>

float calculate(const char oper, const float num1, const float num2){
    switch(oper)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '/':
        return num1 / num2;
    case '*':
        return num1 * num2;
    default :
        throw std::logic_error("invalid operation");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Calculator");
    QCoreApplication::setApplicationVersion("1.0");


    float res = 0;

    QString oper_str = argv[1];
    char oper;

    if (oper_str == "-s" || oper_str == "--sub")
        oper = '-';
    else if (oper_str == "-a" || oper_str == "--add")
        oper = '+';
    else if (oper_str == "-d" || oper_str == "--div")
        oper = '/';
    else if (oper_str == "-m" || oper_str == "--mul")
        oper = '*';
    else{
        qDebug() << "Invalid operation";
        return 1;
    }



    bool validate_num1, validate_num2;
    float num1 = ((QString)argv[2]).toFloat(&validate_num1);
    float num2 = ((QString)argv[3]).toFloat(&validate_num2);

    if (validate_num1 && validate_num2){
        res = calculate(oper,num1,num2);
        qDebug() << num1 << oper <<num2 << '=' << res;
        return 1;
    }
    else {
       qDebug() << "incorrect numbers" << "\n";
       return 0;
    }


}















//bool check_is_number(const QString str){
//    bool pos = true;
//    byte dot = 0;
//    for (int i =0;i<str.size();i++)
//    {
//       if(i==0 && !str[i].isDigit()){
//           if (str[i] == '-' || str[i] == '+')
//               continue;
//           else return false;
//       }
//       if(str[i].isDigit())
//           continue;

//       if(str[i] == '.' && dot == 0) dot ++;
//       else return false;

//    }
//}
