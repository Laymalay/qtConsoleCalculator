#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringList>

float calculate(const QChar oper, const float num1, const float num2){
    switch(oper.toLatin1())
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '/':
        return num1 / num2;
    case '*':
        return num1 * num2;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Calculator");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main",
    "Calculate two numbers."));
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption sumOption(QStringList() << "a" << "add",
                QCoreApplication::translate("main", "adds two numbers."));
    parser.addOption(sumOption);

    QCommandLineOption subOption(QStringList() << "s" << "sub",
                QCoreApplication::translate("main", "subtracts two numbers."));
    parser.addOption(subOption);

    QCommandLineOption divOption(QStringList() << "d" << "div",
                QCoreApplication::translate("main", "divides two numbers."));
    parser.addOption(divOption);

    QCommandLineOption mulOption(QStringList() << "m" << "mul",
                QCoreApplication::translate("main", "multiplies two numbers."));
    parser.addOption(mulOption);

    parser.addPositionalArgument("first-number", QCoreApplication::translate("main", "first-number"));
    parser.addPositionalArgument("second-number", QCoreApplication::translate("main", "second-number"));
    parser.process(a);
    const QStringList args = parser.positionalArguments();
    if (args.size() != 2) {
           qDebug() << "Error: Must specify 2 arguments.";
           parser.showHelp(1);
       }

    float res = 0;
    bool error = false;
    bool validate_num1, validate_num2;
    float num1 = args[0].toFloat(&validate_num1);
    float num2 = args[1].toFloat(&validate_num2);

    if (validate_num1 && validate_num2){
        bool add = parser.isSet(sumOption);
        bool sub = parser.isSet(subOption);
        bool div = parser.isSet(divOption);
        bool mul = parser.isSet(mulOption);
        QChar oper;
        add?oper = '+': sub? oper = '-': div? oper = '/' : mul? oper = '*' : error = true;
        qDebug() << oper;
        res = calculate(oper,num1,num2);
        qDebug() << num1 << oper.toLatin1() <<num2 << '=' << res;
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
