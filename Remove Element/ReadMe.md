#  Remove Element Uygulaması

Bu projede, bir tamsayı dizisinden belirli bir değeri kaldıran `removeElement` fonksiyonunun C diliyle nasıl yazılacağını adım adım açıklıyoruz. Bu fonksiyon, C++’ta kullanılan benzer bir `std::vector` algoritmasının C eşdeğeridir.

---

##  Problem Tanımı

Bir tamsayı dizisinde, belirli bir `val` değerine sahip elemanları çıkartın ve kalan elemanları dizinin başına taşıyın. Fonksiyon, yeni dizinin uzunluğunu döndürmelidir.

> ✅ Not: Ekstra dizi kullanmak **yasak**, işlem doğrudan aynı dizi üzerinde yapılmalıdır.

---

## 💡 Algoritmanın Mantığı

Bu algoritma in-place olarak çalışır. Yani yeni bir dizi oluşturmadan, mevcut dizi üzerinde değişiklik yapılır.

Adım adım algoritma açıklaması:

1. Başlangıçta ``index`` adında bir değişken sıfırlanır. Bu değişken, yeni dizide ``val`` olmayan sayıların yerleştirileceği pozisyonu tutar.

2. ``nums`` dizisinin tüm elemanları sırayla taranır:

  - Eğer bir eleman ``val``’e eşit değilse, ``nums[index]`` konumuna kopyalanır.

  - Bu işlemle dizinin baş kısmı ``val`` olmayan elemanlarla doldurulmuş olur.

3. ``index`` değişkeni, artık val olmayan kaç elemanın kaldığını yani dizinin yeni uzunluğunu gösterir.

4.  Geriye sadece bu ``index`` değerini döndürmek kalır.

---

## 🧱 C ve C++ ile Farkları 



| Özellik                 | C++ Versiyonu           | C Versiyonu                          |
|-------------------------|--------------------------|---------------------------------------|
| Veri yapısı            | `std::vector<int>`       | Dizi (`int[]`)                        |
| Fonksiyon çağrısı       | Referansla (`&nums`)     | Pointer ile (`int* nums`)             |
| Dinamik büyüklük        | `vector.size()`          | `sizeof(nums) / sizeof(nums[0])`      |
| Bellek yönetimi         | Otomatik (RAII)          | Manuel (`malloc` / `free` gerekebilir)|
| Nesne yönelimli destek | Var                      | Yok                                   |
| Dizi boyutu kontrolü    | `vector.size()` güncel   | Boyut manuel hesaplanmalı             |
| Ekstra kütüphane        | STL (`<vector>`)         | Yok (yalın C)                         |
| Performans              | Yüksek soyutlama ile esneklik | Daha düşük seviyeli, hızlı ve doğrudan |


---

## 📌 Sonuç

Bu uygulama, algoritmik düşünme ve C'de dizilerle çalışma pratiği yapmak için harika bir örnektir. Aynı zamanda C ve C++ arasındaki farkları anlamaya da yardımcı olur. Özellikle bellek kontrolü, pointer mantığı ve manuel dizilerle çalışma konularında temel oluşturur.

