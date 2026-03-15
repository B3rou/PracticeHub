using System;

class Student
{
    public string Name { get; set; }
    public int Exam { get; set; }
}

class Program
{
    static void Main()
    {
        List<Student> students = new List<Student>();
        for (int i = 0; i < 10; i++)
            {
            try
            {
                Student student = new Student();
                student.Name = Console.ReadLine();
                student.Exam = Convert.ToInt32(Console.ReadLine());
                if (student.Exam < 0 || student.Exam > 100)
                {
                    i--;
                    Console.WriteLine("Note has to be between 0-100!");
                    continue;
                }
                students.Add(student);
            }
            catch (FormatException)
            {
                Console.WriteLine("Invalid Input!");
                i--;
            }
        }
        Console.WriteLine("\nAll Students:");
        foreach (var student in students)
        {
            Console.WriteLine($"Name: {student.Name}, Exam: {student.Exam}");
        }
    }
}