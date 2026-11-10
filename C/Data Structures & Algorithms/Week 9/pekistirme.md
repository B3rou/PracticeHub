# 9. Hafta: Pekiştirme Soruları ve Yanıtları

## Ek Çalışma – AVL İki Yönlü Dolaşım (Inorder Invariant)
**Soru:** AVL ağacının inorder dolaşımının neden artan sırada sonuç verdiğini açıklayınız.  
**Yanıt:** AVL ağacı, temelinde bir **İkili Arama Ağacı (BST)** yapısıdır. BST kuralı gereği herhangi bir düğümün sol alt ağacındaki tüm değerler kökten küçük, sağ alt ağacındaki tüm değerler ise kökten büyüktür. Inorder (İç Düzen) dolaşımı **Sol -> Kök -> Sağ** sırasını takip ettiği için, rekürsif olarak her zaman en küçük elemandan en büyük elemana doğru ziyaret gerçekleştirir. Yapılan rotasyonlar sadece düğüm yüksekliklerini dengeler, BST'nin büyüklük sıralaması mantığını değiştirmez.

---

## Bölüm 3 – Kısa Pekiştirme Soruları

### Çalışma 1 – 2-3 Tree
**Soru:** Boş bir 2-3 ağacına 10, 20, 30 sayıları eklenirse düğüm bölünmesinden sonra nasıl bir ağaç oluşur?  
**Yanıt:** Dolu düğüm `[10, 20, 30]` taşma yapar ve bölünür. Ortanca anahtar `20` kök düğüme yükselir. Sol çocuk `[10]`, sağ çocuk `[30]` olur:
```text
     [20]
    /    \
  [10]   [30]

```

### Çalışma 2 – Red-Black Tree

**Soru:** AVL Tree ile Red-Black Tree arasındaki temel dengeleme farkı nedir?

**Yanıt:**

* **AVL Tree:** Her düğümde sol ve sağ alt ağaç yükseklik farkını (Balance Factor) katı bir şekilde en fazla 1 tutar. Bu nedenle daha fazla rotasyon yapar fakat arama işlemleri daha hızlıdır.
* **Red-Black Tree:** Düğümlere siyah/kırmızı renk etiketleri atayarak ve renk kurallarına uyarak daha esnek bir denge sağlar (en uzun yol en kısa yolun en fazla 2 katı olabilir). Ekleme ve silme işlemlerinde daha az rotasyon gerektirir.
* Her iki ağacın da arama, ekleme ve silme için en kötü durum zaman karmaşıklığı $ O(\log n) $'dir.