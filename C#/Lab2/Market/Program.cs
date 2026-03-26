using ConsoleApp2;
using System;

namespace Market
{
    class Program
    {
        static void Main()
        {
            Urun u1 = new Urun();

            u1.UrunAdi = "Laptop";
            u1.StokAdedi = -5;
            u1.Fiyat = 500.3;

            UndertaleYazdir($"Name: {u1.UrunAdi}\nStock: {u1.StokAdedi}\nPrice: {u1.Fiyat}\nFenum Tax: {u1.KdvliFiyat}");
        }
        static void UndertaleYazdir(string mesaj, int hiz = 1)
        {
            foreach (char harf in mesaj)
            {
                Console.Write(harf);

                // Boşluk ve alt satırda ses çıkmasın
                if (harf != ' ' && harf != '\n')
                {
                    // 150 frekans Sans için idealdir, Papyrus için 400-500 deneyebilirsin.
                    Console.Beep(150, 40);
                }

                Thread.Sleep(hiz);
            }

            // Cümle bittikten sonra bir alt satıra geçmesi için
            Console.WriteLine();
        }
    }
}