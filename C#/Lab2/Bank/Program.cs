using System;

namespace ConsoleApp4
{
    class Program
    {
        static void Main()
        {
            MusteriIslemleri kisi = new MusteriIslemleri();
            kisi.Ad = "Süllü";
            kisi.Soyad = "Güllü";

            kisi.ParaCek(1000);
            kisi.ParaYatir(1000);

            Console.WriteLine($"Bakiyeniz: {kisi.HesapBakiye}");
        }
    }
}