using System;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = new int[] {10, 11, 12, 13, 14, 15, 16,};
            unsafe
            {
                fixed (int* bas = &numbers[0], son = &numbers[numbers.Length - 1])
                {
                    Console.Write("Current Array: ");
                    for (int i = 0; i < numbers.Length; i++)
                    {
                        Console.Write(numbers[i] + " ");
                    }
                    Reverse(bas, son, numbers.Length / 2);
                    Console.Write("\nNew Reversed Array: ");
                    for (int i = 0; i < numbers.Length; i++)
                    {
                        Console.Write(numbers[i] + " ");
                    }
                }
            }
        }
        static unsafe void Reverse(int* bas, int* son, int times)
        {
            int temp;
            for (int i = 0; i < times; i++)
            {
                temp = *bas;
                *bas = *son;
                *son = temp;
                bas++;
                son--;
            }
        }
    }
}
