using System;

class Factorial
{
    static void Main(string[] args)
    {
        if (args.Length != 1)
        {
            Console.WriteLine("Usage: ./Program.cs <number>");
            return;
        }

        int number = Convert.ToInt32(args[0]);
        Console.WriteLine("{0}! is {1}", args[0], RecursiveFactorial(number));
    }

    static int RecursiveFactorial(int input)
    {
        if (input == 1)
            return input;
        return input * RecursiveFactorial(input - 1);
    }
}