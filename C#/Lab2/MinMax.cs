using System;

class TikkiTikkiTikki
{
    static void Main()
    {
        int[] numbers = {1, 2, 3, 4, 5, 6};
        int len = numbers.Length;
        int max = numbers[0];
        int min = numbers[0];

        for (int i = 0; i < len; i++)
        {
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
        }

        Console.WriteLine($"Max:{max}");
        Console.WriteLine($"Min:{min}");
    }
}