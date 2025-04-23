#  Remove Duplicates from Sorted Array 

Bu proje, sıralı bir tamsayı dizisindeki tekrar eden elemanları kaldırarak her değerden yalnızca birini bırakan `removeDuplicates` fonksiyonunun C diliyle nasıl uygulanacağını gösterir. C++’ta yaygın olarak kullanılan `std::vector` ile yapılan uygulamanın C eşdeğeridir.

---

##  Problem Tanımı

Verilen sıralı (artan) bir tamsayı dizisinden tekrar eden elemanları çıkartın. Sonuç olarak oluşan benzersiz değerlerin yer aldığı dizinin yeni uzunluğunu döndürün.

- Girdi: `nums = [1,1,2,2,3,3,4]`
- Çıktı: `nums = [1,2,3,4,_]`, yeni uzunluk: `4`

> Not: Ekstra dizi kullanımı yasaktır. İşlem doğrudan mevcut dizi üzerinde yapılmalıdır.

---

## Algoritmanın Mantığı

1. Dizi sıralı olduğu için aynı elemanlar art arda gelir.
2. `j` adında yeni bir indeks değişkeni tutulur. Bu, benzersiz elemanları yazmak için kullanılır.
3. Dizi dolaşılır ve eğer bir eleman bir öncekiyle aynı değilse, bu eleman `j` indeksine kopyalanır.
4. `j` artırılır, böylece yalnızca benzersiz değerler dizinin başında kalır.
5. `j`, aynı zamanda yeni dizinin uzunluğudur.

---

##  C Kodu Satır Satır Açıklama
``int removeDuplicates(int* nums, int numsSize)``
- Bu fonksiyon, sıralı dizideki tekrar eden elemanları kaldırır.

- ``nums`` diziyi, ``numsSize`` ise dizinin orijinal boyutunu temsil eder.

``if (numsSize == 0) return 0;``
- Eğer dizi boşsa, işlem yapmaya gerek yoktur.

- Direkt olarak 0 döndürülür.

``int j = 1;``
- ``j``, benzersiz elemanları nereye yerleştireceğimizi tutar.

- İlk eleman zaten benzersiz olduğundan, ``j`` başlangıçta 1 olur.

``for (int i = 1; i < numsSize; i++)``
- Dizinin 1. indeksinden başlayarak tüm elemanlar dolaşılır.

- Neden 0 değil? Çünkü ilk eleman zaten benzersizdir, onu kıyaslayacak bir şey yoktur.

``if (nums[i] != nums[i - 1])``
- Eğer şu anki eleman bir öncekiyle aynı değilse, bu eleman benzersizdir.

``nums[j] = nums[i];``
- Benzersiz eleman bulunduğunda, bu eleman j konumuna yazılır.

- Böylece dizinin başında sadece benzersiz elemanlar birikmiş olur.

``j++;``
- Benzersiz eleman yazıldıktan sonra bir sonraki boş pozisyona geçilir.

``return j;``
- ``j``, dizideki benzersiz elemanların sayısını gösterir.

- Bu aynı zamanda dizinin yeni boyutudur.


## ⚙️ C++ ile Farkları

| Özellik                | C++ Versiyonu               | C Versiyonu                                |
|------------------------|-----------------------------|---------------------------------------------|
| Veri yapısı            | `std::vector<int>`          | Dizi (`int[]`)                              |
| Fonksiyon çağrısı      | Referansla (`&nums`)        | Pointer ile (`int* nums`)                   |
| Dinamik büyüklük       | `vector.size()`             | `sizeof(nums) / sizeof(nums[0])`            |
| Bellek yönetimi        | Otomatik (RAII)             | Manuel (`malloc`/`free` gerekebilir)        |
| Nesne yönelimli destek | ✅ Var                      | ❌ Yok                                      |
| Dizi boyutu kontrolü   | `vector.size()` güncel kalır| Boyut manuel hesaplanmalı                   |
| Ekstra kütüphane       | STL (`<vector>`)            | Yalın C, ek kütüphane kullanılmaz           |
| Performans             | Yüksek soyutlama ile esneklik| Daha düşük seviyeli, hızlı ve doğrudan     |
 ---
#  Notlar
- Bu algoritma yalnızca sıralı diziler için geçerlidir. Eğer sıralı değilse, önce sıralama işlemi yapılmalıdır.

- Bu tip algoritmalar gömülü sistemlerde ve bellek kısıtlı ortamlarda oldukça önemlidir.

- C dilinde, vector gibi yapıların olmaması nedeniyle işlemler pointer manipülasyonlarıyla yapılır.