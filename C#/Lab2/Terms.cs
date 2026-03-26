using System;
class Terms
{
    static void Main()
    {
        Console.WriteLine("Mid Terms: ");
        double x = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine("Finals: ");
        double y = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine($"Average is: {x * 0.4 + y * 0.6}");
    }
}