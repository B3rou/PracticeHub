using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp2
{
    internal class Urun
    {
        public string UrunAdi;
        private int _stokAdedi;
        private double _fiyat;
        public int StokAdedi
        {
            get
            {
                return _stokAdedi;
            }

            set
            {
                if (value < 0)
                    value = 0;
                _stokAdedi = value;
            }
        }
        public double Fiyat
        {
            get
            {
                return _fiyat;
            }

            set
            {
                if (value < 0)
                    value = 0;
                _fiyat = value;
            }
        }

        public double KdvliFiyat
        {
            get
            {
                return _fiyat * 1.2;
            }
        }
    }
}
