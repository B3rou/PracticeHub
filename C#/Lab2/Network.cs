using System;

namespace ConsoleApp
{
    class Network
    {
        private static int AktifBaglantiSayisi;
        static Network()
        {
            AktifBaglantiSayisi = 0;
            Console.WriteLine("Sunucu ayarları yapıldı.");
        }

        public Network()
        {
            AktifBaglantiSayisi++;
            Console.WriteLine($"Yeni Bağlantı Algılandı. Aktif Bağlantı Sayısı: {AktifBaglantiSayisi}");
        }
    }

    class Program
    {
        static void Main()
        {
            Network n1 = new Network();
            Network n2 = new Network();
            Network n3 = new Network();
        }
    }
}