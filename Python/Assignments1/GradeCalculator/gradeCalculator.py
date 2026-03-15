vize = float(input("Vize notunu girin: "))
final = float(input("Final notunu girin: "))

ortalama = (vize*0.4) + (final*0.6)

if vize > 100 or final > 100 or final < 0 or vize < 0:
    print("Geçersiz not girdiniz. Lütfen değerlerinizi 0 ile 100 arasında girin.")
    exit(1)

print(f"Ortalamanız: {ortalama}")

if ortalama >= 90:
    print("Harf Notu: AA") 
elif ortalama >= 85:
    print("Harf Notu: BA")
elif ortalama >= 80:
    print("Harf Notu: BB")
elif ortalama >= 75:
    print("Harf Notu: CB")
elif ortalama >= 65:
    print("Harf Notu: CC")
elif ortalama >= 60:
    print("Harf Notu: DC")
elif ortalama >= 55:
    print("Harf Notu: DD")
elif ortalama >= 50:
    print("Harf Notu: FD")
else:
    print("Harf Notu: FF") 

exit(0)