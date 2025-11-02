# SwapWithoutTemp

**Swap Without Temp** – Kullanıcının girdiği iki sayının değerlerini herhangi bir geçici değişken (temp) kullanmadan yer değiştiren basit bir C programı.

## Kullanım

1. Dosyayı derleyin.
```bash
gcc swapWithoutTemp.c -o swapWithoutTemp // Kullandığınız derleyiciye göre
```
2. Uygulamayı çalıştırın.
3. İki farklı sayı girin.
4. Program sayıların yer değiştirmiş halini ekrana yazdıracaktır.

Dikkat: Bu yöntem, özellikle sayılar çok büyükse taşma (overflow) riski taşıyabilir. Mantıksal olarak doğrudur ama büyük sayılarla dikkatli kullanılmalıdır.