using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace ConsoleApp4
{
    internal partial class MusteriIslemleri
    {
        string _ad;
        string _soyad;
        double _hesapBakiye;

        public MusteriIslemleri()
        {
            _hesapBakiye = 0;
        }
    }

    internal partial class MusteriIslemleri
    {
        public string Ad
        {
            get
            {
                return _ad;
            }
            set
            {
                _ad = value;
            }
        }
        public string Soyad
        {
            get
            {
                return _soyad;
            }
            set
            {
                _soyad = value;
            }
        }
        public double HesapBakiye
        {
            get
            {
                return _hesapBakiye;
            }
            set
            {
                _hesapBakiye = value;
            }
        }
        public void ParaYatir(double miktar)
        {
            HesapBakiye += miktar;
        }
        public void ParaCek(double miktar)
        {
            if (HesapBakiye > 0)
                HesapBakiye -= miktar;
            else
                Console.WriteLine("Ur Broke Gng");
        }
    }
}
