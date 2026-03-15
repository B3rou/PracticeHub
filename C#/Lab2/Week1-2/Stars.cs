using System;

class Stars
{
    static void Main()
    {
        Random place = new Random();
        Console.SetWindowSize(150, 50);
        for (int i= 0; i < 100; i++)
        {
            int row = place.Next(0, Console.WindowWidth);
            int col = place.Next(0, Console.WindowHeight);
            Console.SetCursorPosition(row, col);
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("*");
            // System.Threading.Thread.Sleep();
        }
    }
}