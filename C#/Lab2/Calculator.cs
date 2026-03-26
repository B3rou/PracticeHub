using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Please enter 2 numbers");
        Console.Write("1: ");
        double x = Convert.ToDouble(Console.ReadLine());
        Console.Write("2: ");
        double y = Convert.ToDouble(Console.ReadLine());
        Console.WriteLine("What's The Next Step Of The Operation? (+,-,*,/)");
        char op = Console.ReadLine()[0];
        switch (op)
        {
            case '+':
                Console.WriteLine($"Answer is: {Sum(x, y)}");
                break;
            case '-':
                Console.WriteLine($"Answer is: {Sub(x, y)}");
                break;
            case '*':
                Console.WriteLine($"Answer is: {Multi(x, y)}");
                break;
            case '/':
                Console.WriteLine($"Answer is: {Div(x, y)}");
                break;
            default:
                Console.WriteLine($"Invalid Operator!");
                break;
        }
    }

    static double Sum(double x, double y)
    {
        return x + y;
    }
    static double Sub(double x, double y)
    {
        return x - y;
    }
    static double Multi(double x, double y)
    {
        return x + y;
    }
    static double Div(double x, double y)
    {
        return x / y;
    }

}